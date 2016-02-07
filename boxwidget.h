#ifndef BOXWIDGET_H
#define BOXWIDGET_H

#include <QFrame>
#include <QVBoxLayout>
#include <QLabel>

class BoxWidget : public QFrame
{
    Q_OBJECT
public:
    explicit BoxWidget(QWidget *parent = 0);
    void setHeadText(QString);
signals:

public slots:
    setValue(float);

private:
    QLabel *HeadLabel, *ValueLabel;
    QVBoxLayout *Box;
};

#endif // BOXWIDGET_H
