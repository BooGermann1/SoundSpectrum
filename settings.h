#ifndef SETTINGS_H
#define SETTINGS_H

#include <QObject>
#include <QSettings>

class Settings : public QObject
{
    Q_OBJECT
public:
    explicit Settings(QObject *parent = 0);

signals:

public slots:

private:
    QSettings *settings;
    int SIZE;
};

#endif // SETTINGS_H