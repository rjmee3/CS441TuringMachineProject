#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "tape.h"

void initTape(Tape* tape, char* input) {
    for (int i = 0; i < TAPE_LENGTH; i++) {
        tape->pos_tape[i].blank = true;
        tape->neg_tape[i].blank = true;
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
        setBlank(tape, false);
    } else {
        tape->neg_tape[abs(tape->index)-1].symbol = symbol;
        setBlank(tape, false);
    }
}

char readTape(Tape* tape) {
    if (tape->index >= 0) {
        return tape->pos_tape[tape->index].symbol;
    } else {
        return tape->neg_tape[abs(tape->index)-1].symbol;
    }
}

void setBlank (Tape* tape, bool blank) {
    if (tape->index >= 0) {
        tape->pos_tape[tape->index].blank = blank;
    } else {
        tape->neg_tape[abs(tape->index)-1].blank = blank;
    }
}

bool isBlank(Tape* tape) {
    if (tape->index >= 0) {
        return tape->pos_tape[tape->index].blank;
    } else {
        return tape->neg_tape[abs(tape->index)-1].blank;
    }
}