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
        for (int i = 0; i<NUM_BARS+1; i++){
            mean = 0;
            for (int c = 0; c<CUT_SIZE/NUM_BARS; c++){
                mean += OutBuf[c + i*CUT_SIZE/NUM_BARS + index_lc];
            }
            barvec.append(mean/(CUT_SIZE/NUM_BARS));
            if (mean/(CUT_SIZE/NUM_BARS)>LocalMaxVolume){
                LocalMaxVolume = mean/(CUT_SIZE/NUM_BARS);
                newLocalMax(LocalMaxVolume);
            }
        }
        emit stop_fft(&barvec);
        emit stop_fft();

        if (LocalMaxVolume>GlobalMaxVolume){
            GlobalMaxVolume = LocalMaxVolume;
            emit newGlobalMax(GlobalMaxVolume);
            emit newMaxGraph(&barvec);
        }

    }
    else{
        stop_fft(&OutBuf);
        stop_fft();
    }
}

FFTStream::reset_max()
{
    LocalMaxVolume = 0;
}
