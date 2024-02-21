#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include "encodings.h"
#include "tape.h"

int main(int argc, char *argv[]) {
    // handling incorrect number of arguments
    if (argc != 3) {
        fprintf(stderr, "Usage: ./SUNY_VM <.bin file> <.tape file>\n");
        return 1;
    }

    // handling file opening failures
    FILE* bin_file = fopen(argv[1], "rb");
    if (bin_file == NULL) {
        fprintf(stderr, "ERROR: .bin file failed to open.\n");
        return 1;
    }

    FILE* tape_file = fopen(argv[2], "r");
    if (tape_file == NULL) {
        fprintf(stderr, "ERROR: .tape file failed to open.\n");
        return 1;
    }

    // determining size of file
    fseek(bin_file, 0, SEEK_END);
    long fileSize = ftell(bin_file);
    fseek(bin_file, 0, SEEK_SET);

    // throw error for an empty bin file
    if (fileSize == 0) {
        fprintf(stderr, "ERROR: Empty .bin file.\n");
        return 1;
    }

    // calculating number of instructions based on file size
    size_t numInstructions = fileSize / sizeof(tm_encoding);

    // dynamically allocating memory for instructions array
    tm_encoding* instructions = (tm_encoding*)malloc(numInstructions * sizeof(tm_encoding));
    if (instructions == NULL) {
        fprintf(stderr, "ERROR: Instruction memory allocation failed.\n");
        return 1;
    }

    // read in binary data
    if (fread(instructions, sizeof(tm_encoding), numInstructions, bin_file) != numInstructions) {
        fprintf(stderr, "ERROR: Instruction reading failed.\n");
        free(instructions);
        fclose(bin_file);
        return 1;
    }

    // close bin file stream
    fclose(bin_file);
    
    // create registers and flags
    int prog_counter;
    tm_encoding instr_reg;
    bool alphabet[256];
    bool eq_flag;

    // create other structures needed
    char buffer[1024];
    Tape tape;
    bool stop = false;
    bool fail = false;

    // loop through each line of the input file
    while (fgets(buffer, sizeof(buffer), tape_file) != NULL) {
        
        // initialize everything as needed
        initTape(&tape, buffer);
        prog_counter = 0;
        eq_flag = false;
        stop = false;
        fail = false;

        // continue executing instructions until halt or failure
        while (!stop) {
            /*************************
             *                       *
             *         FETCH         *
             *                       *
             *************************/

            instr_reg = instructions[prog_counter];
            prog_counter++;

            // printing binary representation
            for (int i = 15; i >= 0; i--) {
                // fprintf(stderr, "%d", (instr_reg.word>>i) & 1);
            }
            // fprintf(stderr, " ");

            /*************************
             *                       *
             *        EXECUTE        *
             *                       *
             *************************/

            // switch based on OPCODE
            switch (instr_reg.generic.opcode) {
            case TM_OPCODE_ALP:
                alphabet[instr_reg.alpha.letter] = true;
                // fprintf(stderr, "ALPHA %c\n", instr_reg.alpha.letter);
                break;

            case TM_OPCODE_CMP:
                if (instr_reg.cmp.blank) {
                    if (isBlank(&tape)) {
                        eq_flag = true;
                    } else if (!instr_reg.cmp.oring) {
                        eq_flag = false;
                    }
                } else if (!alphabet[instr_reg.cmp.letter]) {
                    stop = true;
                    fail = true;
                } else if (instr_reg.cmp.letter == readTape(&tape)) {
                    eq_flag = true;
                } else if (!instr_reg.cmp.oring) {
                    eq_flag = false;
                }
                if (instr_reg.cmp.blank) {
                    if (instr_reg.cmp.oring) {
                        // fprintf(stderr, "OR BLANK\n");
                    } else {
                        // fprintf(stderr, "CMP BLANK\n");
                    }
                } else {
                    if (instr_reg.cmp.oring) {
                        // fprintf(stderr, "OR %c\n", instr_reg.cmp.letter);
                    } else {
                        // fprintf(stderr, "CMP %c\n", instr_reg.cmp.letter);
                    }
                }
                
                break;

            case TM_OPCODE_JMP:
                if ((instr_reg.jmp.ne == instr_reg.jmp.eq) 
                 || (instr_reg.jmp.eq == eq_flag) 
                 || (instr_reg.jmp.ne == !eq_flag)) {
                    prog_counter = instr_reg.jmp.addr;
                }
                if (instr_reg.jmp.ne && instr_reg.jmp.eq) {
                    // fprintf(stderr, "JMP %d\n", instr_reg.jmp.addr);
                } else if (instr_reg.jmp.eq == 1) {
                    // fprintf(stderr, "JEQ %d\n", instr_reg.jmp.addr);
                } else if (instr_reg.jmp.ne == 1) {
                    // fprintf(stderr, "JNE %d\n", instr_reg.jmp.addr);
                } else {
                    // fprintf(stderr, "ERROR\n");
                }
                break;

            case TM_OPCODE_DRW:
                if (instr_reg.draw.blank) {
                    setBlank(&tape);
                    // fprintf(stderr, "DRAW BLANK\n");
                } else {
                    writeTape(&tape, instr_reg.draw.letter);
                    // fprintf(stderr, "DRAW %c\n", instr_reg.draw.letter);
                }
                break;

            case TM_OPCODE_MOV:
                moveTape(&tape, instr_reg.move.amount);
                // fprintf(stderr, "MOVE %d\n", instr_reg.move.amount);
                break;

            case TM_OPCODE_STP:
                if (!instr_reg.stop.halt) {
                    fail = true;
                    // fprintf(stderr, "FAIL\n");
                }
                stop = true;
                // fprintf(stderr, "HALT\n");
                break;
            
            default:
                fprintf(stderr, "ERROR: IMPOSSIBLE INSTRUCTION.");
                break;
            }
        }

        printTape(&tape);
    }
}