#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spectrumwidget.h"
#include "audiostream.h"
#include "fftstream.h"
#include "settings.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    SpectrumWidget* Spectrum = new SpectrumWidget(this);
    setCentralWidget(Spectrum);
    AudioStream* Stream = new AudioStream();
    FFTStream* FFT = new FFTStream();
    Settings mod;
    connect(Stream, SIGNAL(Complete(QBuffer*)), FFT, SLOT(start_fft(QBuffer*)));
    connect(FFT, SIGNAL(stop_fft(QVector<double>*)), Spectrum, SLOT(Redraw(QVector<double>*)));
    connect(FFT, SIGNAL(stop_fft()), Stream, SLOT(StartRecord()));
    Stream->StartRecord();
}

MainWindow::~MainWindow()
{
    delete ui;
}
