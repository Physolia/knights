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

#ifndef KNIGHTS_PIECE_H
#define KNIGHTS_PIECE_H

#include <QtSvg/QGraphicsSvgItem>

#include "pos.h"

namespace Knights
{
enum PieceType
{
    King,
    Queen,
    Bishop,
    Knight,
    Rook,
    Pawn
};
enum Color
{
    NoColor = 0,
    White,
    Black
};
Color oppositeColor ( Color color );

class Piece : public QGraphicsSvgItem
{
    Q_OBJECT
public:
    Piece ( QGraphicsItem* parentItem = 0 );
    Piece ( PieceType type, Color color, QGraphicsItem* parent = 0 );
    virtual ~Piece();

    PieceType pieceType();
    Color color();

private:
    Color m_color;
    PieceType m_type;
};

typedef QMap<Pos, Piece*> Grid;
typedef QPair<Color,PieceType> PieceData;
typedef QMap<Pos, PieceData> BoardState;
}

Q_DECLARE_METATYPE ( Knights::Color )
Q_DECLARE_METATYPE ( Knights::PieceType )
Q_DECLARE_METATYPE ( Knights::PieceData )
Q_DECLARE_METATYPE ( Knights::BoardState )

#endif // KNIGHTS_PIECE_H
// kate: indent-mode cstyle; space-indent on; indent-width 4; replace-tabs on;