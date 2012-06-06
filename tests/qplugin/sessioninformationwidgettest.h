#ifndef SESSIONINFORMATIONWIDGETTEST_H
#define SESSIONINFORMATIONWIDGETTEST_H

#include <QtTest>
#include <QtTestGui>

#include "qplugin/sessioninformationwidget.h"

class SessionInformationWidgetTest : public QObject {
    Q_OBJECT

public:
    explicit SessionInformationWidgetTest ( QObject * parent = 0 );

private:
    SessionInformationWidget * sessionInformationWidget;

private slots:
    void initTestCase();
    void cleanupTestCase();

    void testShouldDisplayCorrectSessionName();
    void testShouldDisplayCorrectProgressBar();
    void testShouldDisplayCorrectUserAndFeedbackCount();
};

#endif // SESSIONINFORMATIONWIDGETTEST_H