#include "settings.h"
#include "globals.h"
Settings::Settings(QObject *parent) : QObject(parent)
{
    settings = new QSettings("./setup.ini", QSettings::IniFormat);
    SIZE = settings->value("SIZE").toInt();
}

