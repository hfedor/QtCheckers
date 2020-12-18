#include "game.h"

Game::Game()
{
    for(int c = 0; c < 8; c++)
        for(int l = 0; l < 8; l++)
        {
            board[c][l].SetColumn(c);
            board[c][l].SetLine(l);
        }

    for(int p = 0; p < 12; p++)
        whitePieces[p].SetAsWhite();

    for(int p = 0; p < 12; p++)
        blackPieces[p].SetAsBlack();

    SpredPieces();
}

bool Game::IsThatPieceTurn(Piece* p)
{
    if(whiteTurn)
        return p->GetCcolor() == PieceColor::White;
    else
        return p->GetCcolor() == PieceColor::Black;
}

void Game::MovePiece(Square* s, Piece* p)
{
    RemoveSquarePiece(p->GetColumn(),p->GetLine());
    s->SetPiece(p);
}

void Game::MovePiece(int column, int line, Piece* p)
{
    RemoveSquarePiece(p->GetColumn(),p->GetLine());
    SetSquarePiece(column, line, p);
}

void Game::SetSquareColor(int column, int line, SquareColor sc)
{
    board[column][line].SetColor(sc);
}

void Game::SetSquareButton(int column, int line, QPushButton *b)
{
    board[column][line].SetButoon(b);

}

void Game::SpredPieces()
{
    if(playAsWhite)
    {
        board[1][0].SetPiece(&whitePieces[0]);
        board[3][0].SetPiece(&whitePieces[1]);
        board[5][0].SetPiece(&whitePieces[2]);
        board[7][0].SetPiece(&whitePieces[3]);
        board[0][1].SetPiece(&whitePieces[4]);
        board[2][1].SetPiece(&whitePieces[5]);
        board[4][1].SetPiece(&whitePieces[6]);
        board[6][1].SetPiece(&whitePieces[7]);
        board[1][2].SetPiece(&whitePieces[8]);
        board[3][2].SetPiece(&whitePieces[9]);
        board[5][2].SetPiece(&whitePieces[10]);
        board[7][2].SetPiece(&whitePieces[11]);

        board[0][7].SetPiece(&blackPieces[0]);
        board[2][7].SetPiece(&blackPieces[1]);
        board[4][7].SetPiece(&blackPieces[2]);
        board[6][7].SetPiece(&blackPieces[3]);
        board[1][6].SetPiece(&blackPieces[4]);
        board[3][6].SetPiece(&blackPieces[5]);
        board[5][6].SetPiece(&blackPieces[6]);
        board[7][6].SetPiece(&blackPieces[7]);
        board[0][5].SetPiece(&blackPieces[8]);
        board[2][5].SetPiece(&blackPieces[9]);
        board[4][5].SetPiece(&blackPieces[10]);
        board[6][5].SetPiece(&blackPieces[11]);
    }
    else
    {
        board[1][0].SetPiece(&blackPieces[0]);
        board[3][0].SetPiece(&blackPieces[1]);
        board[5][0].SetPiece(&blackPieces[2]);
        board[7][0].SetPiece(&blackPieces[3]);
        board[0][1].SetPiece(&blackPieces[4]);
        board[2][1].SetPiece(&blackPieces[5]);
        board[4][1].SetPiece(&blackPieces[6]);
        board[6][1].SetPiece(&blackPieces[7]);
        board[1][2].SetPiece(&blackPieces[8]);
        board[3][2].SetPiece(&blackPieces[9]);
        board[5][2].SetPiece(&blackPieces[10]);
        board[7][2].SetPiece(&blackPieces[11]);

        board[0][7].SetPiece(&whitePieces[0]);
        board[2][7].SetPiece(&whitePieces[1]);
        board[4][7].SetPiece(&whitePieces[2]);
        board[6][7].SetPiece(&whitePieces[3]);
        board[1][6].SetPiece(&whitePieces[4]);
        board[3][6].SetPiece(&whitePieces[5]);
        board[5][6].SetPiece(&whitePieces[6]);
        board[7][6].SetPiece(&whitePieces[7]);
        board[0][5].SetPiece(&whitePieces[8]);
        board[2][5].SetPiece(&whitePieces[9]);
        board[4][5].SetPiece(&whitePieces[10]);
        board[6][5].SetPiece(&whitePieces[11]);
    }
}

/*
void Game::SetSquarePieceImage(int column, int line, QLabel *l)
{
    board[column][line].SetPieceLabel(l);
}
*/
