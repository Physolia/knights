/*
    <one line to give the program's name and a brief idea of what it does.>
    Copyright (C) 2011  Miha Čančula <miha.cancula@gmail.com>

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/


#include "externalcontrol.h"
#include "gamemanager.h"
#include "knightsadaptor.h"
#include <KDebug>

#define FORWARD_FUNCTION(name, action) void ExternalControl::name() { Manager::self()->sendOffer(Action##action, NoColor, qrand()); }

using namespace Knights;

ExternalControl::ExternalControl(QObject* parent) : QObject(parent)
{
    connect(Manager::self(), SIGNAL(pieceMoved(Move)), SIGNAL(moveMade(QString)));
    new KnightsAdaptor(this);
    kDebug() << QDBusConnection::sessionBus().registerObject(QLatin1String("/Knights"), this);
    kDebug() << QDBusConnection::sessionBus().registerService(QLatin1String("org.kde.Knights"));
}

ExternalControl::~ExternalControl()
{

}

FORWARD_FUNCTION(adjourn,Adjourn)
FORWARD_FUNCTION(abort,Abort)
FORWARD_FUNCTION(pauseGame,Pause)
FORWARD_FUNCTION(resumeGame,Resume)
FORWARD_FUNCTION(undo,Undo)
FORWARD_FUNCTION(offerDraw,Draw)

void ExternalControl::movePiece(const QString& move)
{
    Manager::self()->moveByExternalControl(move);
}


