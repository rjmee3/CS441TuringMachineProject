#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include "tape.h"

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

void moveTape(Tape* tape, int move) {
    tape->index += move;
}

void writeTape(Tape* tape, char symbol) {
    if (tape->index >= 0) {
        tape->pos_tape[tape->index].symbol = symbol;
        tape->pos_tape[tape->index].blank = false;
    } else {
        tape->neg_tape[abs(tape->index)-1].symbol = symbol;
        tape->neg_tape[abs(tape->index)-1].blank = false;
    }
}

char readTape(Tape* tape) {
    if (tape->index >= 0) {
        return tape->pos_tape[tape->index].symbol;
    } else {
        return tape->neg_tape[abs(tape->index)-1].symbol;
    }
}

void setBlank (Tape* tape) {
    if (tape->index >= 0) {
        tape->pos_tape[tape->index].blank = true;
        tape->pos_tape[tape->index].symbol = ' ';
    } else {
        tape->neg_tape[abs(tape->index)-1].blank = true;
        tape->neg_tape[tape->index].symbol = ' ';
    }
}

bool isBlank(Tape* tape) {
    if (tape->index >= 0) {
        return tape->pos_tape[tape->index].blank;
    } else {
        return tape->neg_tape[abs(tape->index)-1].blank;
    }
}

void printTape(Tape* tape) {

    char full_tape[TAPE_LENGTH*2+1];
    char full_head[TAPE_LENGTH*2+1];

    // tape->index = 0;

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
    char *end_tape = full_tape + strlen(full_tape) - 1;
    char *end_head = full_head + strlen(full_head) - 1;
    while ((end_tape > start_tape && isspace(*end_tape)) && (end_head > start_head && isspace(*end_head))) {
        end_tape--;
        end_head--;
    }

    *(end_tape+1) = '\0';
    *(end_head+1) = '\0';

    memmove(full_tape, start_tape, strlen(start_tape) + 1);
    memmove(full_head, start_head, strlen(start_head) + 1);

    fprintf(stderr, "\n%s\n", full_tape);
    fprintf(stderr, "%s\n", full_head);
}