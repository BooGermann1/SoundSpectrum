#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "spectrumwidget.h"
#include "audiostream.h"
#include "fftstream.h"
#include "settings.h"
#include "boxwidget.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    SpectrumWidget *Spectrum = new SpectrumWidget(this);
    SpectrumWidget *MaxSpectrum = new SpectrumWidget(this);
    QHBoxLayout *SpectrumBox = new QHBoxLayout();
    QLabel *HeaderLabel = new QLabel("<h1><b><font color='black'> <font size=24>Нажми на кнопку СБРОС и узнай силу своего крика");
    QPushButton *StartButton = new QPushButton("Сброс");
    BoxWidget *CurrVol = new BoxWidget();
    BoxWidget *MaxVol = new BoxWidget();

    QWidget *MainWidget = new QWidget();
    QVBoxLayout *MainLayout = new QVBoxLayout();
    QVBoxLayout *HeadLayout = new QVBoxLayout();
    QHBoxLayout *BoxLayout = new QHBoxLayout();

    MainWidget->setLayout(MainLayout);

    MainLayout->addLayout(HeadLayout);
    MainLayout->addLayout(SpectrumBox);
    MainLayout->addLayout(BoxLayout);

    HeadLayout->setAlignment(Qt::AlignHCenter);
    HeadLayout->addWidget(HeaderLabel);
    HeadLayout->addWidget(StartButton);

    SpectrumBox->addWidget(Spectrum);
    SpectrumBox->addWidget(MaxSpectrum);

    BoxLayout->addWidget(CurrVol);
    BoxLayout->addWidget(MaxVol);

    CurrVol->setHeadText(QString("Громкость<br>Loudness"));
    MaxVol->setHeadText(QString("Максимальная громкость<br>Maximum loudness"));

    this->setCentralWidget(MainWidget);
    AudioStream* Stream = new AudioStream();
    FFTStream* FFT = new FFTStream();
    Settings mod;
    connect(Stream, SIGNAL(Complete(QBuffer*)), FFT, SLOT(start_fft(QBuffer*)));
    connect(FFT, SIGNAL(stop_fft(QVector<double>*)), Spectrum, SLOT(Redraw(QVector<double>*)));
    connect(FFT, SIGNAL(stop_fft()), Stream, SLOT(StartRecord()));
    connect(FFT, SIGNAL(newLocalMax(float)), CurrVol, SLOT(setValue(float)));
    connect(FFT, SIGNAL(newGlobalMax(float)), MaxVol, SLOT(setValue(float)));
    connect(FFT, SIGNAL(newMaxGraph(QVector<double>*)), MaxSpectrum, SLOT(Redraw(QVector<double>*)));
    connect(StartButton, SIGNAL(clicked(bool)), FFT, SLOT(reset_max()));
    Stream->StartRecord();
}

MainWindow::~MainWindow()
{
    delete ui;
}
