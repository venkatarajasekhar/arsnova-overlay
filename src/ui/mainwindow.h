#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtGui>

#include "version.h"
#include "ui_mainwindow.h"
#include "ui/splashscreen.h"
#include "qplugin/loginwidget.h"
#include "ui/qrcodewidget.h"
#include "ui/sessionwidget.h"

class MainWindow : public QMainWindow, Ui::MainWindow {
    Q_OBJECT

public:
    explicit MainWindow ( QWidget * parent = 0, Qt::WindowFlags f = 0 );
    virtual ~MainWindow();
    const Ui::MainWindow * const getUi();
    void addWidget ( QString title, QWidget * widget );

private:
    Ui::MainWindow * ui;
    QSignalMapper * menuSignalMapper;
    QMap<QString, QWidget *> * widgetList;

    void checkLeftMenuButton(QString title);

private slots:
    void activateWidget ( QString widgetTitle );
};

#endif // MAINWINDOW_H