#ifndef SESSIONWIDGET_H
#define SESSIONWIDGET_H

#include <QtGui>
#include "sessioncontext.h"
#include "ui_sessionwidget.h"

class SessionWidget : public QWidget, Ui::SessionWidget {
    Q_OBJECT

public:
    explicit SessionWidget ( SessionContext * context, QWidget* parent = 0, Qt::WindowFlags f = 0 );
    const Ui::SessionWidget * const getUi();

private:
    Ui::SessionWidget * _ui;
    AbstractConnection * connection;

public slots:
    void onUnderstandingResponse ( UnderstandingResponse response );
};

#endif // SESSIONWIDGET_H
