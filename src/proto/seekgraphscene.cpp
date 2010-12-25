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

#include "proto/seekgraphscene.h"
#include "proto/ficsprotocol.h"
#include "core/renderer.h"
#include "core/item.h"

#include <KDebug>

#include <QGraphicsPixmapItem>

using namespace Knights;

SeekGraphScene::SeekGraphScene ( QObject* parent ) : QGraphicsScene ( parent )
, m_renderer(new Renderer(QLatin1String("seek.desktop")))
{

}

SeekGraphScene::~SeekGraphScene()
{
    delete m_renderer;
}

void SeekGraphScene::addGameOffer ( const FicsGameOffer& offer )
{
    QRect containerRect(0, 0, 100, 20);
    QGraphicsRectItem* container = new QGraphicsRectItem ( containerRect );
    container->setBrush(QBrush(Qt::transparent));
    container->setPen(QPen(Qt::transparent));
    container->setPos( offer.player.second / 10, offer.baseTime * 10 );
    Item* icon = new Item(m_renderer, QLatin1String("SeekIcon"), 0, Pos(), container);
    icon->setRenderSize(QSize(16, 16));
    QGraphicsTextItem* text = new QGraphicsTextItem ( offer.player.first + QLatin1String(" ()"), container );
    text->setPos(20, 0);
    addItem ( container );
}


