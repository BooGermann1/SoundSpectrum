#ifndef AUDIOSTREAM_H
#define AUDIOSTREAM_H

#include <QAudioInput>
#include <QAudioFormat>
#include <QAudioDeviceInfo>
#include <QBuffer>
#include <QTimer>
#include <QObject>
#include "globals.h"

class AudioStream : public QObject
{
    Q_OBJECT
public:
    explicit AudioStream();

signals:
    Complete(QBuffer*);

public slots:
    StartRecord();
    StopRecord();

private:
    QBuffer* AudioBuffer;
    QAudioInput* Audio;
    QAudioFormat* Format;
};

#endif // AUDIOSTREAM_H
