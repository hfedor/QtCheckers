#ifndef SQUARE_H
#define SQUARE_H

#include <iostream>

#include <QPushButton>

#include "piece.h"

enum class SquareColor
{
    Black,
    White
};

class Square
{
private:
    int column;
    int line;
    SquareColor color;
    QPushButton* button = NULL;
    Piece* piece = NULL;

public:
    Square();
    Square(int c, int l);
    Square(int c, int l, SquareColor sc, QPushButton* b, Piece* p);
    int GetColumn(){return column;}
    int GetLine(){return line;}
    SquareColor GetColor(){return color;}
    QPushButton* GetButton(){return button;}
    Piece* GetPiece(){return piece;}
    //QLabel* GetPieceLabel(){if(piece != NULL) return piece->GetLabel(); else return NULL;}
    std::string GetNotation();
    bool IsPieceQueen(){return piece->IsQueen();}
    //bool IsPieceLabelNull(){return piece->IsLabelNull();}
    void RemovePiece(){if(piece != NULL) piece->RemoveFromBoard(); piece = NULL;}
    void SetColumn(int c){column = c;}
    void SetLine(int l){line = l;}
    void SetColor(SquareColor sc){color = sc;}
    void SetButoon(QPushButton *b){button = b;}
    void SetPiece(Piece *p){piece = p; p->Place(column,line);}
    //void SetPieceLabel(QLabel* l){if(piece == NULL) piece = new Piece(); piece->SetLabel(l);}
    void SetPieceAsBlack() { if(piece != NULL) piece->SetAsBlack(); }
    void SetPieceAsWhite() { if(piece != NULL) piece->SetAsWhite(); }
};

#endif // SQUARE_H
