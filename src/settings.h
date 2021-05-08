#ifndef SETTINGS_H
#define SETTINGS_H

#define NUM_INPUTS 10
#define NUM_OUTPUTS 4

#define INPUT_MIC1 0
#define INPUT_MIC2 1
#define INPUT_MIC3 2
#define INPUT_MIC4 3
#define INPUT_DAW1 4
#define INPUT_DAW2 5
#define INPUT_DAW3 6
#define INPUT_DAW4 7
#define INPUT_LOOPBACK1 8
#define INPUT_LOOPBACK2 9

#define OUTPUT1 0
#define OUTPUT2 1
#define OUTPUT3 2
#define OUTPUT4 3

typedef struct { uint16_t values[NUM_OUTPUTS][NUM_INPUTS]; } transfer_matrix_t;

#endif
