#include "audiostream.h"
#include <QDebug>

AudioStream::AudioStream()
{
    AudioBuffer = new QBuffer;
    AudioBuffer->open(QIODevice::WriteOnly);
    Format = new QAudioFormat;
    Format->setSampleRate(SAMPLE_RATE);
    Format->setChannelCount(1);
    Format->setSampleSize(8);
    Format->setCodec("audio/pcm");
    Format->setByteOrder(QAudioFormat::LittleEndian);
    Format->setSampleType(QAudioFormat::SignedInt);

    QAudioDeviceInfo info = QAudioDeviceInfo::defaultInputDevice();
       if (!info.isFormatSupported(*Format)) {
           qDebug("Default format not supported, trying to use the nearest.");
           *Format = info.nearestFormat(*Format);
           qDebug()<<Format->sampleRate();
           qDebug()<<Format->codec();
           qDebug()<<Format->channelCount();
           qDebug()<<Format->byteOrder();
           qDebug()<<Format->sampleSize();
           qDebug()<<Format->sampleType();
       }
    Audio = new QAudioInput(*Format, this);
}

AudioStream::StartRecord()
{
    QTimer::singleShot(SAMPLE_TIME_MS, this, SLOT(StopRecord()));
    AudioBuffer->open(QIODevice::WriteOnly);
    AudioBuffer->seek(0);
    Audio->start(AudioBuffer);
}

AudioStream::StopRecord()
{
    Audio->stop();
    AudioBuffer->close();
    emit this->Complete(AudioBuffer);
}

