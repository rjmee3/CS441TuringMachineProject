#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include "tape.h"

void initTape(Tape* tape, char* input) {
    tape->current = (TapeCell*)malloc(sizeof(TapeCell));
    tape->current->symbol = ' ';
    tape->current->next = NULL;
    tape->current->prev = NULL;
    
    if (input != NULL) {
        int inputLength = strlen(input);
        for (int i = 0; i < inputLength; i++) {
            tape->current->symbol = input[i];

            if (i < inputLength - 1) {
                if (tape->current->next == NULL) {
                    TapeCell* newCell = (TapeCell*)malloc(sizeof(TapeCell));
                    newCell->symbol = ' ';
                    newCell->next = NULL;
                    newCell->prev = tape->current;
                    tape->current->next = newCell;
                }

                tape->current = tape->current->next;
            }
            
        }

        while (tape->current->prev != NULL) {
            tape->current = tape->current->prev;
        }
    }
}

void moveHead(Tape* tape, signed int amt) {
    if (amt >= 0) {
        for (int i = 0; i < amt; i++) {
            if (tape->current->next == NULL) {
                TapeCell* newCell = (TapeCell*)malloc(sizeof(TapeCell));
                newCell->symbol = ' ';
                newCell->next = NULL;
                newCell->prev = tape->current;
                tape->current->next = newCell;
            }
            tape->current = tape->current->next;
        }
    } else {
        for (int i = 0; i < abs(amt); i++) {
            if (tape->current->prev == NULL) {
                TapeCell* newCell = (TapeCell*)malloc(sizeof(TapeCell));
                newCell->symbol = ' ';
                newCell->next = tape->current;
                newCell->prev = NULL;
                tape->current->prev = newCell;
            }
            tape->current = tape->current->prev;
        }
    }
}

char readHead(Tape* tape) {
    return tape->current->symbol;
}
