#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "encodings.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Usage: ./VM <.bin file> <.tape file>\n");
        return 1;
    }

    FILE* bin_file = fopen(argv[1], "r");
    if (bin_file == NULL) {
        fprintf(stderr, "ERROR: .bin file failed to open.");
        return 1;
    }

    FILE* tape_file = fopen(argv[2], "r");
    if (tape_file == NULL) {
        fprintf(stderr, "ERROR: .tape file failed to open.");
        return 1;
    }
}