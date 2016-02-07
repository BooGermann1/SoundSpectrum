#ifndef GLOBALS
#define GLOBALS

const int SIZE = 512;
const int SAMPLE_RATE = 8000;
const float RES_BW = float(SAMPLE_RATE)/SIZE;
const int SAMPLE_TIME_MS = 1000/RES_BW;
const bool BARS = true;
const int NUM_BARS = 63;

const int LOW_CUT = 300;
const int HIGH_CUT = 3400;
const int index_lc = LOW_CUT/RES_BW;
const int index_hc = HIGH_CUT/RES_BW;
const int CUT_SIZE = index_hc - index_lc;

#endif // GLOBALS

