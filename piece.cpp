#include "piece.h"

Piece::Piece()
{
}

void Piece::SetAsBlack()
{
    color = PieceColor::Black;
}

void Piece::SetAsWhite()
{
    color = PieceColor::White;
}
