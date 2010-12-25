/*
    This file is part of Knights, a chess board for KDE SC 4.
    Copyright 2009-2010  Miha Čančula <miha.cancula@gmail.com>

    This program is free software; you can redistribute it and/or
    modify it under the terms of the GNU General Public License as
    published by the Free Software Foundation; either version 2 of
    the License or (at your option) version 3 or any later version
    accepted by the membership of KDE e.V. (or its successor approved
    by the membership of KDE e.V.), which shall act as a proxy
    defined in Section 14 of version 3 of the license.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#ifndef KNIGHTS_FICSDIALOG_H
#define KNIGHTS_FICSDIALOG_H

#include "ficsprotocol.h"

#include <QtGui/QWidget>
#include <QtGui/QStringListModel>
#include <boost/concept_check.hpp>

namespace Ui
{
    class FicsDialog;
}

namespace Knights
{
    class FicsDialog : public QWidget
    {
            Q_OBJECT
        public:
            explicit FicsDialog ( QWidget* parent = 0, Qt::WindowFlags f = 0 );
            virtual ~FicsDialog();

            int acceptedGameId();
            QString userName();
            QString password();
            bool remember();
            
            void setServerName(const QString& name);

            virtual QSize sizeHint() const;

        public Q_SLOTS:
            void slotSessionStarted();
            void slotDialogAccepted();
            void addGameOffer ( const FicsGameOffer& offer );
            void addChallenge ( const FicsPlayer& challenger );
            
            void clearOffers();
            void refresh();
            void accept();
            void decline();

            void currentTabChanged ( int tab );
            void slotCreateAccount();
            void slotLogin();
    void setConsoleWidget(QWidget* widget);
    void focusOnLogin();
    void setStatus(const QString& status, bool error = false);

        Q_SIGNALS:
            void login ( QString username, QString password );
            void createAccount();
            
            void seekingChanged ( bool seek );
            void sought();
            void declineButtonNeeded ( bool needed );
            void acceptButtonNeeded ( bool needed );
            void reloadButtonNeeded ( bool needed );

            void acceptSeek ( int seekId );
            void acceptChallenge();
            void declineChallenge();

        private:
            Ui::FicsDialog* ui;
            QMap<int, int> m_gameId;
            QStringListModel m_challengeModel;
            QString serverName;
    };
}

#endif // KNIGHTS_FICSDIALOG_H
// kate: indent-mode cstyle; space-indent on; indent-width 4; replace-tabs on;  replace-tabs on;
