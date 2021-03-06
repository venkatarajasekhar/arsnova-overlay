#ifndef OVERLAYWIDGET_H
#define OVERLAYWIDGET_H

#include <QtGui>
#include <QtNetwork>
#include <QtScript>

#include "ui_overlaywidget.h"
#include "../updatetimer.h"
#include "sessioncontext.h"
#include "sessionresponse.h"
#include "feedbackresponse.h"
#include "svglogo.h"
#include "qrcodewidget.h"
#include "settings.h"
#include "abstractconnection.h"

class OverlayWidget : public QWidget, Ui::OverlayWidget {
    Q_OBJECT

public:
    explicit OverlayWidget ( SessionContext * context, QWidget * parent = 0, Qt::WindowFlags f = 0 );
    virtual ~OverlayWidget();
    /** Returns user interface of this widget.
     * This method is helpfull if someone needs direct access to the
     * user interface itself e.g. testing.
     * @return User interface
     */
    const Ui::OverlayWidget * const getUi();

private:
    Ui::OverlayWidget * ui;

    AbstractConnection * connection;
    QString sessionId;
    int loggedInUsers;
    int latestUnderstandingResponses;
    QRCodeWidget * qrcodewidget;
    SessionContext * context;

    static const int ySize;
    static const int xSize;
    void moveToEdge ( int screen = -1 );
    void connectSignals();
    void setVisibleViewType ( SessionContext::ViewType type );
    void paintEvent ( QPaintEvent * event );

public slots:
    virtual void show();
    bool close();
    void onSessionResponse ( SessionResponse response );
    void onFeedbackResponse ( FeedbackResponse response );
    void onLoggedInResponse ( LoggedInResponse response );
    void onAudienceQuestionCountResponse ( AudienceQuestionCountResponse response );
    void onSettingsChanged();
};

#endif // OVERLAYWIDGET_H
