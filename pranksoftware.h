#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_pranksoftware.h"

class pranksoftware : public QMainWindow
{
    Q_OBJECT

public:
    pranksoftware(QWidget *parent = nullptr);
    ~pranksoftware();

private:
    Ui::pranksoftwareClass ui;
};
