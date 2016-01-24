#ifndef FFTSTREAM_H
#define FFTSTREAM_H

#include <QObject>
#include <QBuffer>
#include <QVector>
#include "qfft/headers/qfouriertransformer.h"
#include "qfft/headers/qwindowfunction.h"
#include <math.h>
#include "globals.h"

class FFTStream : public QObject
{
    Q_OBJECT
public:
    explicit FFTStream(QObject *parent = 0);

signals:
    stop_fft(QVector<double>*);
    stop_fft();
public slots:
    start_fft(QBuffer*);

private:
    QVector<double> OutBuf;
    QFourierTransformer transformer;
    float in[SIZE], out[SIZE];
};

#endif // FFTSTREAM_H
