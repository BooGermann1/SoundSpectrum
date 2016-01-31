#ifndef SPECTRUMWIDGET_H
#define SPECTRUMWIDGET_H

#include <QWidget>
#include <QVBoxLayout>
#include <QLabel>
#include <QString>
#include "qwt_plot.h"
#include "qwt_plot_grid.h"
#include "qwt_plot_curve.h"
#include "globals.h"

class SpectrumWidget : public QWidget
{
    Q_OBJECT
public:
    explicit SpectrumWidget(QWidget *parent);

signals:

public slots:
    Redraw(QVector<double>*);

private:
    QwtPlot *s_plot;
    QwtPlotGrid *s_grid;
    QVBoxLayout *s_lay;
    QwtPlotCurve *s_curve;
    QVector<double> s_vect, x_vect;
};

#endif // SPECTRUMWIDGET_H
