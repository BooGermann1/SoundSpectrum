#include "spectrumwidget.h"

SpectrumWidget::SpectrumWidget(QWidget *parent)
{
    s_lay = new QVBoxLayout();
    s_plot = new QwtPlot(this);
    s_grid = new QwtPlotGrid();
    s_curve = new QwtPlotCurve();
    this->setLayout(s_lay);
    s_lay->addWidget(s_plot);
    s_plot->setCanvasBackground(Qt::black);

    s_grid->attach(s_plot);
    s_grid->setPen(Qt::darkGray, 1, Qt::DotLine);
    s_plot->repaint();
    for(int i = 0; i<SIZE / 2; i++){
        s_vect.append(double(i * 23.5));
    }
    //s_curve->setStyle(QwtPlotCurve::Sticks);
    s_curve->setPen(Qt::red, 2, Qt::SolidLine);
    s_curve->setSamples(s_vect, x_vect);
    s_curve->attach(s_plot);
    s_plot->setAxisScale(0, 0, 100);
    s_plot->setAxisTitle(2, "kHz");
    s_plot->setAxisTitle(0, "dB");
}

SpectrumWidget::Redraw(QVector<double>* get_vect)
{
    s_curve->detach();
    s_curve->setSamples(s_vect, *get_vect);
    s_curve->attach(s_plot);
    s_plot->replot();
}

