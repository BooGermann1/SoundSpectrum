#include "fftstream.h"

FFTStream::FFTStream(QObject *parent) : QObject(parent)
{
    transformer.setSize(SIZE);
    transformer.setWindowFunction("Hann");
}

FFTStream::start_fft(QBuffer* Buf){
    char temp;
    Buf->open(QIODevice::ReadOnly);
    Buf->seek(0);
    for(int i = 0; i<SIZE; i++){
       Buf->getChar(&temp);
       if (temp < 0){
        in[i] = temp+256;
       }
       else{
        in[i] = temp;
       }
    }
    transformer.forwardTransform(in, out);
    OutBuf.clear();
    for(int i = 0; i<SIZE / 2; i++){
        OutBuf<<20*log10(abs(out[i])+1);
    }
    if (BARS){
        barvec.clear();
        double mean;
        for (int i = 0; i<NUM_BARS; i++){
            mean = 0;
            for (int c = 0; c<SIZE/2/NUM_BARS; c++){
                mean += OutBuf[c + i*SIZE/2/NUM_BARS];
            }
            barvec.append(mean/(SIZE/2/NUM_BARS));
        }
        stop_fft(&barvec);
        stop_fft();

    }
    else{
        stop_fft(&OutBuf);
        stop_fft();
    }
}
