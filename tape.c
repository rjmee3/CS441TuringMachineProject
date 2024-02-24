#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "tape.h"

// initializes the tape to all blank cells, and places the 
// input string on the tape, keeping the head on the first
// character of said string
void initTape(Tape* tape, char* input) {
    for (int i = 0; i < TAPE_LENGTH; i++) {
        tape->pos_tape[i].blank = true;
        tape->neg_tape[i].blank = true;
        tape->pos_tape[i].symbol = ' ';
        tape->neg_tape[i].symbol = ' ';
    }

    tape->index = 0;

    if (input != NULL) {
        for (int i = 0; i < strlen(input); i++) {
            tape->pos_tape[i].symbol = input[i];
            tape->pos_tape[i].blank = false;
        }
    }
}

// moves head of the tape
void moveTape(Tape* tape, int move) {
    tape->index += move;
}

// writes the char passed to the tape
void writeTape(Tape* tape, char symbol) {
    if (tape->index >= 0) {
        tape->pos_tape[tape->index].symbol = symbol;
        tape->pos_tape[tape->index].blank = false;
    } else {
        tape->neg_tape[abs(tape->index)-1].symbol = symbol;
        tape->neg_tape[abs(tape->index)-1].blank = false;
    }
}

// reads the char on the tape
char readTape(Tape* tape) {
    if (tape->index >= 0) {
        return tape->pos_tape[tape->index].symbol;
    } else {
        return tape->neg_tape[abs(tape->index)-1].symbol;
    }
}

// sets tape to blank
void setBlank (Tape* tape) {
    if (tape->index >= 0) {
        tape->pos_tape[tape->index].blank = true;
        tape->pos_tape[tape->index].symbol = ' ';
    } else {
        tape->neg_tape[abs(tape->index)-1].blank = true;
        tape->neg_tape[tape->index].symbol = ' ';
    }
}

// returns if the tape is blank
bool isBlank(Tape* tape) {
    if (tape->index >= 0) {
        return tape->pos_tape[tape->index].blank;
    } else {
        return tape->neg_tape[abs(tape->index)-1].blank;
    }
}

// prints tape and head pointer
void printTape(Tape* tape) {

    char full_tape[TAPE_LENGTH*2+1];
    char full_head[TAPE_LENGTH*2+1];

    int combinedIndex = 0;
    for (int i = TAPE_LENGTH - 1; i >= 0; i--) {
        if (-i-1 == tape->index) {
            full_head[combinedIndex] = '^';
        } else {
            full_head[combinedIndex] = ' ';
        }
        full_tape[combinedIndex++] = tape->neg_tape[i].symbol;
    }

    for (int i = 0; i < TAPE_LENGTH; i++) {
        if (i == tape->index) {
            full_head[combinedIndex] = '^';
        } else {
            full_head[combinedIndex] = ' ';
        }
        full_tape[combinedIndex++] = tape->pos_tape[i].symbol;
    }

    // trim leading whitespace
    char *start_tape = full_tape;
    char *start_head = full_head;
    while ((*start_tape && isspace(*start_tape)) && (*start_head && isspace(*start_head))) {
        start_tape++;
        start_head++;
    }

    // trim trailing whitespace
    char *end_tape = full_tape + combinedIndex - 1;
    char *end_head = full_head + combinedIndex - 1;
    while ((end_tape > start_tape && isspace(*end_tape)) && (end_head > start_head && isspace(*end_head))) {
        end_tape--;
        end_head--;
    }

    *(end_tape+1) = '\0';
    *(end_head+1) = '\0';

    memmove(full_tape, start_tape, strlen(start_tape) + 1);
    memmove(full_head, start_head, strlen(start_head) + 1);

    printf("%s\n", full_tape);
    printf("%s", full_head);
}