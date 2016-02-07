#include "boxwidget.h"

BoxWidget::BoxWidget(QWidget *parent) : QFrame(parent)
{
    Box = new QVBoxLayout();
    Box->setAlignment(Qt::AlignJustify);
    HeadLabel = new QLabel("<h1><b><font color='black'> <font size=24>dummy text");
    HeadLabel->setAlignment(Qt::AlignHCenter);
    ValueLabel = new QLabel("<h1><b><font color='black'> <font size=24> 0 dBA");
    ValueLabel->setAlignment(Qt::AlignHCenter);
    this->setLayout(Box);
    Box->addWidget(HeadLabel);
    Box->addWidget(ValueLabel);
    this->setMaximumWidth(500);
    this->setStyleSheet("BoxWidget {border-style: solid; border-width: 4px; border-color: black;}");
}

void BoxWidget::setHeadText(QString str)
{
    HeadLabel->setText(QString("<h1><b><font color='black'> <font size=24>").append(str));
}

BoxWidget::setValue(float val)
{
    ValueLabel->setText(QString("<h1><b><font color='black'> <font size=24> %1 dBA").arg(val, 0, 'g', 3));
}

