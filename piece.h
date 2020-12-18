#ifndef PIECE_H
#define PIECE_H

#include <iostream>

#include <QLabel>

enum class PieceColor
{
    Black,
    White
};

enum class PieceType
{
    Piece,
    Queen
};

class Piece
{
private:
    PieceColor color = PieceColor::White;
    PieceType type = PieceType::Piece;
    int column = -1;
    int line = -1;
    // QLabel* label = NULL;

public:
    Piece();
    PieceColor GetCcolor(){return color;}
    int GetColumn(){return column;}
    int GetLine(){return line;}
    bool IsQueen(){return type == PieceType::Queen;}
    void MakeQueen(){type = PieceType::Queen;}
    //QLabel* GetLabel(){return label;}
    //bool IsLabelNull(){return label == NULL;}
    void Place(int c, int l){column = c; line = l;}
    void RemoveFromBoard(){column = -1; line = -1;}
    void SetColor(PieceColor pc){color = pc;}
    //void SetLabel(QLabel *l){label = l;}
    void SetAsBlack();
    void SetAsWhite();
};

#endif // PIECE_H
