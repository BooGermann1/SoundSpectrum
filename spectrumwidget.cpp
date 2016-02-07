#include "spectrumwidget.h"

SpectrumWidget::SpectrumWidget(QWidget *parent)
{
    s_lay = new QVBoxLayout();
//    QLabel *ResolutionLabel = new QLabel(QString("Resolution: %1 Hz").arg(double(RES_BW), 0, 'g', 3));
//    QLabel *SampleTimeLabel = new QLabel(QString("SampleTime: %1 ms").arg(SAMPLE_TIME_MS));
    s_plot = new QwtPlot(this);
    s_grid = new QwtPlotGrid();
    s_curve = new QwtPlotCurve();
    this->setLayout(s_lay);
    s_lay->addWidget(s_plot);
//    s_lay->addWidget(ResolutionLabel);
//    s_lay->addWidget(SampleTimeLabel);
    s_plot->setCanvasBackground(Qt::black);

    s_grid->attach(s_plot);
    s_grid->setPen(Qt::darkGray, 1, Qt::DotLine);
    s_plot->repaint();
    if (BARS){
        for(int i = 0; i<NUM_BARS+1; i++)
            s_vect.append(double(i * RES_BW * (CUT_SIZE / NUM_BARS) + LOW_CUT));
        s_curve->setStyle(QwtPlotCurve::Sticks);
        s_curve->setPen(Qt::red, 8, Qt::SolidLine);
    }
    else{
        for(int i = 0; i<SIZE / 2; i++){
            s_vect.append(double(i * RES_BW + LOW_CUT));
        }
        s_curve->setPen(Qt::red, 2, Qt::SolidLine);
    }
    //

    s_curve->setSamples(s_vect, x_vect);
    s_curve->attach(s_plot);
    s_plot->setAxisScale(0, 0,80);
    s_plot->setAxisTitle(2, "kHz");
    s_plot->setAxisTitle(0, "dBA");
}

SpectrumWidget::Redraw(QVector<double>* get_vect)
{
    s_curve->detach();
    s_curve->setSamples(s_vect, *get_vect);
    s_curve->attach(s_plot);
    s_plot->replot();
}

