#include <stdbool.h>

#ifndef TAPE_H
#define TAPE_H

#define TAPE_LENGTH 4000

typedef struct TapeCell {
    char symbol;
    bool blank;
} TapeCell;

typedef struct {
    TapeCell pos_tape[TAPE_LENGTH/2];
    TapeCell neg_tape[TAPE_LENGTH/2];
    int index;
} Tape;

void initTape(Tape* tape, char* input);
void moveTape(Tape* tape, int move);
void writeTape(Tape* tape, char symbol);
char readTape(Tape* tape);
void setBlank(Tape* tape, bool blank);
bool isBlank(Tape* tape);

#endif