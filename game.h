#ifndef GAME_H
#define GAME_H

#include "square.h"

class Game
{
private:
    Square board[8][8];
    Piece whitePieces[12];
    Piece blackPieces[12];
    int whitePiecesNumber = 12;
    int blackPiecesNumber = 12;
    bool playAsWhite = true;
    bool whiteTurn = true;
    Piece* pickedPiece = NULL;
    bool finish = false;
public:
    Game();
    bool GetFinish(){return finish;}
    Piece* GetPickedPiece(){return pickedPiece;}
    Square* GetSquare(int column, int line){return &(board[column][line]);}
    Piece* GetSquarePiece(int column, int line){return board[column][line].GetPiece();}
    QPushButton* GetSquareButton(int column, int line){return board[column][line].GetButton();}
    bool IsSquarePieceQueen(int column, int line){return board[column][line].IsPieceQueen();}
    bool IsWhiteTurn(){return whiteTurn;}
    bool IsThatPieceTurn(Piece* p);
    //QLabel* GetSquarePieceLabel(int column, int line){return board[column][line].GetPieceLabel();}
    //bool IsSquarePieceLabelNull(int column, int line){return board[column][line].IsPieceLabelNull();}
    void MovePiece( Square* s, Piece* p);
    void MovePiece( int column, int line, Piece* p);
    void NextTurn(){whiteTurn = whiteTurn ? false : true;}
    void SetPickedPiece(Piece* p){pickedPiece = p;}
    void RemoveSquarePiece(int column, int line)
    {
        if(board[column][line].GetPiece() != NULL)
        {
            if(board[column][line].GetPiece()->GetCcolor() == PieceColor::White)
            {
                whitePiecesNumber--;
                if(whitePiecesNumber == 0)
                    Win();
            }
            else
            {
                blackPiecesNumber--;
                if(whitePiecesNumber == 0)
                    Win();
            }
        }
        board[column][line].RemovePiece();
    }
    void SetSquareColor(int column, int line, SquareColor sc);
    void SetSquareButton(int column, int line, QPushButton *b);
    //void SetSquarePieceImage(int column, int line, QLabel *l);
    void SetSquarePiece(int column, int line, Piece* p){board[column][line].SetPiece(p);}
    void SetSquarePieceAsBlack(int column, int line){board[column][line].SetPieceAsBlack();}
    void SetSquarePieceAsWhite(int column, int line){board[column][line].SetPieceAsWhite();}
    void SpredPieces();
    void Win(){finish =true;}
};

#endif // GAME_H
