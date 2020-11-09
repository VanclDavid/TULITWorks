#include "FourthExercise.h"

unsigned int getMaxByteMemory() {
    unsigned int required = 0;
    char* memory = (char*)malloc(required * sizeof(char));
    while (memory != NULL) {
        memory = (char *)malloc(required * sizeof(char));
        required++;
    }
    free(memory);

    return required;
}

int canIFillItThere(int n,int m) {
    unsigned int maxSize = getMaxByteMemory();
    unsigned int sizeInBytesOfFloatArray = n * m * 4;

    if (sizeInBytesOfFloatArray <= maxSize) {
        return 1;
    }

    return 0;
}