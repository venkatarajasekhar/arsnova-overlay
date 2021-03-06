/***************************************************************************
 *   Copyright (C) 2014  Paul-Christian Volkmer
 *   <paul-christian.volkmer@mni.thm.de>
 *
 *   This file is part of ARSnova Overlay.
 *
 *   ARSnova Overlay is free software: you can redistribute it and/or modify
 *   it under the terms of the GNU General Public License as published by
 *   the Free Software Foundation, either version 3 of the License, or
 *   (at your option) any later version.
 *
 *   ARSnova Overlay is distributed in the hope that it will be useful,
 *   but WITHOUT ANY WARRANTY; without even the implied warranty of
 *   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *   GNU General Public License for more details.
 *
 *   You should have received a copy of the GNU General Public License
 *   along with ARSnova Overlay.  If not, see <http://www.gnu.org/licenses/>.
 ***************************************************************************/

#include "settings.h"

std::shared_ptr<Settings> Settings::_instance = std::shared_ptr<Settings> ();

Settings::Settings() {
    qsettings = new QSettings ( "THM", "ARSnova Overlay" );
    qsettings->setDefaultFormat ( QSettings::NativeFormat );
}

Settings::~Settings() {
    delete qsettings;
}

std::shared_ptr< Settings > Settings::instance() {
    if ( ! _instance ) {
        _instance = std::shared_ptr<Settings> ( new Settings() );
    }

    return _instance;
}

Settings::WidgetPosition Settings::widgetPosition() {
    return ( Settings::WidgetPosition ) qsettings->value ( "widgetPosition" ).toInt();
}

void Settings::setWidgetPosition ( Settings::WidgetPosition widgetPosition ) {
    qsettings->setValue ( "widgetPosition", widgetPosition );
    emit this->settingsChanged();
}

QUrl Settings::serverUrl() {
    if ( qsettings->value ( "serverUrl" ).isNull() ) {
        return QUrl ( "https://arsnova.eu" );
    }
    QString result = qsettings->value ( "serverUrl" ).toString();
    return result.endsWith ( "/" ) ? QUrl ( result.remove( QRegExp( "/$" ) ) ) : QUrl ( result );
}

void Settings::setServerUrl ( QUrl serverUrl ) {
    if ( serverUrl.isValid() ) {
        qsettings->setValue ( "serverUrl", serverUrl );
    }
    emit this->settingsChanged();
}

int Settings::screen() {
    return qsettings->value ( "screen" ).toInt();
}

void Settings::setScreen ( int screen ) {
    qsettings->setValue ( "screen", screen );
    emit this->settingsChanged();
}
