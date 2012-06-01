#include "overlaywidgettest.h"

OverlayWidgetTest::OverlayWidgetTest ( QObject* parent ) : QObject ( parent ) {}

void OverlayWidgetTest::enterSessionId ( QLineEdit * lineEdit ) {
    QTest::keyClick ( lineEdit,  Qt::Key_0 );
    QTest::keyClick ( lineEdit,  Qt::Key_1 );
    QTest::keyClick ( lineEdit,  Qt::Key_2 );
    QTest::keyClick ( lineEdit,  Qt::Key_3 );
    QTest::keyClick ( lineEdit,  Qt::Key_4 );
    QTest::keyClick ( lineEdit,  Qt::Key_5 );
    QTest::keyClick ( lineEdit,  Qt::Key_6 );
    QTest::keyClick ( lineEdit,  Qt::Key_7 );
    QTest::keyClick ( lineEdit,  Qt::Key_Enter );
}


void OverlayWidgetTest::initTestCase() {
    this->overlayWidget = new OverlayWidget ( new StubConnection() );
}

void OverlayWidgetTest::cleanupTestCase() {
    delete this->overlayWidget;
}

void OverlayWidgetTest::testShouldExitOnExitButtonClicked() {
    delete this->overlayWidget;
    this->overlayWidget = new OverlayWidget ( new StubConnection() );
    this->overlayWidget->show();

    QVERIFY ( this->overlayWidget->getUi()->loginwidget->isVisible() );
    QTest::mouseClick ( this->overlayWidget->getUi()->loginwidget->getUi()->exitButton, Qt::LeftButton );

    QVERIFY ( this->overlayWidget->isEnabled() );
    this->overlayWidget = new OverlayWidget ( new StubConnection() );
}

void OverlayWidgetTest::testShouldShowOverlayWidget() {
    this->overlayWidget->show();
    QVERIFY ( this->overlayWidget->isVisible() );
}

void OverlayWidgetTest::testShouldNotDisplayBarDiagramWithoutSessionLogin() {
    QVERIFY ( this->overlayWidget->getUi()->loginwidget->isVisible() );

    QTest::keyClick ( this->overlayWidget->getUi()->loginwidget->getUi()->sessionIdEdit,  Qt::Key_Enter );

    QVERIFY ( this->overlayWidget->getUi()->loginwidget->isVisible() );
}

void OverlayWidgetTest::testShouldDisplayBarDiagramAfterSessionLogin() {
    QVERIFY ( this->overlayWidget->getUi()->loginwidget->isVisible() );

    this->enterSessionId ( this->overlayWidget->getUi()->loginwidget->getUi()->sessionIdEdit );

    QVERIFY ( this->overlayWidget->getUi()->bardiagramwidget->isVisible() );
}

void OverlayWidgetTest::testShouldDisplayCorrectCountString() {
    QVERIFY ( this->overlayWidget->getUi()->bardiagramwidget->isVisible() );

    // As declared in StubConnection class
    QCOMPARE ( this->overlayWidget->getUi()->onlineUsersLabel->text(), QString ( "(10/3)" ) );
}

void OverlayWidgetTest::testShouldSwitchToLogoDiagram() {
    QVERIFY ( ! this->overlayWidget->getUi()->actionSwitchView->isChecked() );
    this->overlayWidget->getUi()->actionSwitchView->trigger();
    QVERIFY ( this->overlayWidget->getUi()->actionSwitchView->isChecked() );
    QVERIFY ( ! this->overlayWidget->getUi()->bardiagramwidget->isVisible() );
    QVERIFY ( this->overlayWidget->getUi()->logodiagramwidget->isVisible() );
}

void OverlayWidgetTest::testShouldSwitchToBarDiagram() {
    QVERIFY ( this->overlayWidget->getUi()->actionSwitchView->isChecked() );
    this->overlayWidget->getUi()->actionSwitchView->trigger();
    QVERIFY ( ! this->overlayWidget->getUi()->actionSwitchView->isChecked() );
    QVERIFY ( this->overlayWidget->getUi()->bardiagramwidget->isVisible() );
    QVERIFY ( ! this->overlayWidget->getUi()->logodiagramwidget->isVisible() );
}

void OverlayWidgetTest::testShouldSwitchToLogin() {
    this->overlayWidget->getUi()->actionChangeSession->trigger();
    QVERIFY ( this->overlayWidget->getUi()->loginwidget->isVisible() );
}