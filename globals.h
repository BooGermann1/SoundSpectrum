#ifndef GLOBALS
#define GLOBALS

const int SIZE = 512;
const int SAMPLE_RATE = 8000;
const float RES_BW = float(SAMPLE_RATE)/SIZE;
const int SAMPLE_TIME_MS = 1000/RES_BW;
const bool BARS = true;
const int NUM_BARS = 61;

#endif // GLOBALS

