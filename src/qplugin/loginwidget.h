#ifndef LOGINWIDGET_H
#define LOGINWIDGET_H

#include <QtGui>
#include "ui_loginwidget.h"

/** This class provides the ArsNova login widget as a Qt Widget
 * @author Paul-Christian Volkmer <paul-christian.volkmer@mni.thm.de>
 */
class LoginWidget : public QWidget, Ui::LoginWidget {
    Q_OBJECT

public:
    explicit LoginWidget ( QWidget* parent = 0, Qt::WindowFlags f = 0 );
    QString text();
    void setText ( QString text );
    void clear();

    const Ui::LoginWidget * const getUi();
    
private:
    Ui::LoginWidget * _ui;

private slots:
    void on_sessionIdEdit_editingFinished();
    void on_exitButton_clicked();
    void on_loginButton_clicked();

signals:
    void editingFinished();
    void exitButtonClicked();
    void loginButtonClicked();
};

#endif // LOGINWIDGET_H