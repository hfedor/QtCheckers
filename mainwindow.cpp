#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    blackPieceIconPath = "C:/Users/lenovo/Documents/Moje Programy/Qt/Warcaby/black.png";
    whitePieceIconPath = "C:/Users/lenovo/Documents/Moje Programy/Qt/Warcaby/white.png";
    blackQueenIconPath = "C:/Users/lenovo/Documents/Moje Programy/Qt/Warcaby/black_queen.png";;
    whiteQueenIconPath = "C:/Users/lenovo/Documents/Moje Programy/Qt/Warcaby/white_queen.png";;

    squares[0][0] = ui->s11;
    squares[0][1] = ui->s12;
    squares[0][2] = ui->s13;
    squares[0][3] = ui->s14;
    squares[0][4] = ui->s15;
    squares[0][5] = ui->s16;
    squares[0][6] = ui->s17;
    squares[0][7] = ui->s18;
    squares[1][0] = ui->s21;
    squares[1][1] = ui->s22;
    squares[1][2] = ui->s23;
    squares[1][3] = ui->s24;
    squares[1][4] = ui->s25;
    squares[1][5] = ui->s26;
    squares[1][6] = ui->s27;
    squares[1][7] = ui->s28;
    squares[2][0] = ui->s31;
    squares[2][1] = ui->s32;
    squares[2][2] = ui->s33;
    squares[2][3] = ui->s34;
    squares[2][4] = ui->s35;
    squares[2][5] = ui->s36;
    squares[2][6] = ui->s37;
    squares[2][7] = ui->s38;
    squares[3][0] = ui->s41;
    squares[3][1] = ui->s42;
    squares[3][2] = ui->s43;
    squares[3][3] = ui->s44;
    squares[3][4] = ui->s45;
    squares[3][5] = ui->s46;
    squares[3][6] = ui->s47;
    squares[3][7] = ui->s48;
    squares[4][0] = ui->s51;
    squares[4][1] = ui->s52;
    squares[4][2] = ui->s53;
    squares[4][3] = ui->s54;
    squares[4][4] = ui->s55;
    squares[4][5] = ui->s56;
    squares[4][6] = ui->s57;
    squares[4][7] = ui->s58;
    squares[5][0] = ui->s61;
    squares[5][1] = ui->s62;
    squares[5][2] = ui->s63;
    squares[5][3] = ui->s64;
    squares[5][4] = ui->s65;
    squares[5][5] = ui->s66;
    squares[5][6] = ui->s67;
    squares[5][7] = ui->s68;
    squares[6][0] = ui->s71;
    squares[6][1] = ui->s72;
    squares[6][2] = ui->s73;
    squares[6][3] = ui->s74;
    squares[6][4] = ui->s75;
    squares[6][5] = ui->s76;
    squares[6][6] = ui->s77;
    squares[6][7] = ui->s78;
    squares[7][0] = ui->s81;
    squares[7][1] = ui->s82;
    squares[7][2] = ui->s83;
    squares[7][3] = ui->s84;
    squares[7][4] = ui->s85;
    squares[7][5] = ui->s86;
    squares[7][6] = ui->s87;
    squares[7][7] = ui->s88;

    RenderBoard();

    for(int c = 0 ; c < 8 ; c++)
        for(int l = 0 ; l < 8 ; l++)
            connect(squares[c][l],
                    &QAbstractButton::clicked,
                    this,
                    [=](){ ClickSquare(c,l); });
}

void MainWindow::EndGame()
{
    ui->endLabel->setText("Koniec");
}

void MainWindow::ClickSquare(int column,int line)
{
    Piece* newPickedPiece = game.GetSquarePiece(column, line);
    if(newPickedPiece != NULL)
    {
        if(game.IsThatPieceTurn(newPickedPiece))
            game.SetPickedPiece(newPickedPiece);
    }
    else
    {
        Piece* pickedPiece = game.GetPickedPiece();

        if(pickedPiece != NULL)
        {
            int pickedColumn = pickedPiece->GetColumn();
            int pickedLine = pickedPiece->GetLine();

            if(pickedPiece->IsQueen())
            {
                bool move = true;
                int cdelta = column - pickedColumn;
                int ldelta = line - pickedLine;

                if( cdelta == ldelta || cdelta == -ldelta )
                {
                    if( column >  pickedColumn )
                    {
                        if( line > pickedLine )
                        {
                             for(int i = 1 ; (pickedColumn+i < column && pickedLine+i < line) ; i++)
                             {
                                 Piece* beaten = game.GetSquarePiece(pickedColumn+i,pickedLine+i);
                                 if(beaten != NULL)
                                 {
                                     if(pickedColumn+i < column - 1)
                                     {
                                         move = false;
                                         break;
                                     }
                                     else
                                         game.RemoveSquarePiece(column-1,line-1);
                                 }
                             }
                        }
                        else
                        {
                            for(int i = 1 ; (pickedColumn+i < column && pickedLine-i > line) ; i++)
                            {
                                Piece* beaten = game.GetSquarePiece(pickedColumn+i,pickedLine-i);
                                if(beaten != NULL)
                                {
                                    std::cout << beaten->GetColumn() << beaten->GetLine() << std::endl;
                                    if(pickedColumn+i < column - 1)
                                    {
                                        move = false;
                                        break;
                                    }
                                    else
                                        game.RemoveSquarePiece(column-1,line+1);
                                }
                            }
                        }
                    }
                    else
                    {
                        if( line > pickedLine )
                        {
                             for(int i = 1 ; (pickedColumn-i > column && pickedLine+i < line) ; i++)
                             {
                                 Piece* beaten = game.GetSquarePiece(pickedColumn-i,pickedLine+i);
                                 if(beaten != NULL)
                                 {
                                     std::cout << beaten->GetColumn() << beaten->GetLine() << std::endl;
                                     if(pickedColumn-i > column + 1)
                                     {
                                         move = false;
                                         break;
                                     }
                                     else
                                         game.RemoveSquarePiece(column+1,line-1);
                                 }
                             }
                        }
                        else
                        {
                            for(int i = 1 ; (pickedColumn-i > column && pickedLine-i > line) ; i++)
                            {
                                Piece* beaten = game.GetSquarePiece(pickedColumn-i,pickedLine-i);
                                if(beaten != NULL)
                                {
                                    std::cout << beaten->GetColumn() << beaten->GetLine() << std::endl;
                                    if(pickedColumn-i > column + 1)
                                    {
                                        move = false;
                                        break;
                                    }
                                    else
                                        game.RemoveSquarePiece(column+1,line+1);
                                }
                            }
                        }
                    }
                    if(move)
                    {
                        game.MovePiece(column, line, pickedPiece);
                        game.SetPickedPiece(NULL);
                        game.NextTurn();
                    }
                }
            }
            else
            {
                if(game.IsWhiteTurn())
                {
                    if((column == pickedColumn+1 || column == pickedColumn-1) && line == pickedLine+1)
                    {
                        game.MovePiece(column, line, pickedPiece);
                        if(line == 7)
                            pickedPiece->MakeQueen();
                        game.SetPickedPiece(NULL);
                        game.NextTurn();
                    }
                }
                else
                {
                    if((column == pickedColumn+1 || column == pickedColumn-1) && line == pickedLine-1)
                    {
                        game.MovePiece(column, line, pickedPiece);
                        if(line == 0)
                            pickedPiece->MakeQueen();
                        game.SetPickedPiece(NULL);
                        game.NextTurn();
                    }
                }

                if(column == pickedColumn+2 && column >= 2 && line == pickedLine+2 && line >= 2)
                {
                    Piece* beaten = game.GetSquarePiece(column-1,line-1);
                    if(beaten != NULL && !game.IsThatPieceTurn(beaten))
                    {
                        game.MovePiece(column, line, pickedPiece);
                        if(line == 7)
                            pickedPiece->MakeQueen();
                        game.RemoveSquarePiece(pickedColumn+1,pickedLine+1);
                        game.SetPickedPiece(NULL);
                        game.NextTurn();
                    }
                }
                else if(column == pickedColumn-2 && column <= 6  && line == pickedLine-2 && line <= 6)
                {
                    Piece* beaten = game.GetSquarePiece(column+1,line+1);
                    if(beaten != NULL && !game.IsThatPieceTurn(beaten))
                    {
                        game.MovePiece(column, line, pickedPiece);
                        if(line == 0)
                            pickedPiece->MakeQueen();
                        game.RemoveSquarePiece(pickedColumn-1,pickedLine-1);
                        game.SetPickedPiece(NULL);
                        game.NextTurn();
                    }
                }
                else if(column == pickedColumn+2 && column >= 2 && line == pickedLine-2 && line <= 6)
                {
                    Piece* beaten = game.GetSquarePiece(column-1,line+1);
                    if(beaten != NULL && !game.IsThatPieceTurn(beaten))
                    {
                        game.MovePiece(column, line, pickedPiece);
                        if(line == 0)
                            pickedPiece->MakeQueen();
                        game.RemoveSquarePiece(pickedColumn+1,pickedLine-1);
                        game.SetPickedPiece(NULL);
                        game.NextTurn();
                    }
                }
                else if(column == pickedColumn-2 && column <= 6 && line == pickedLine+2 && line >= 2)
                {
                    Piece* beaten = game.GetSquarePiece(column+1,line-1);
                    if(beaten != NULL && !game.IsThatPieceTurn(beaten))
                    {
                        game.MovePiece(column, line, pickedPiece);
                        if(line == 7)
                            pickedPiece->MakeQueen();
                        game.RemoveSquarePiece(pickedColumn-1,pickedLine+1);
                        game.SetPickedPiece(NULL);
                        game.NextTurn();
                    }
                }
            }
        }
    }

    RenderBoard();

    if(game.GetFinish())
        EndGame();
}

void MainWindow::RemoveSquarePiece(int column, int line)
{
    game.RemoveSquarePiece(column,line);
    squares[column][line]->setIcon(QIcon(""));
}

void MainWindow::RenderBoard()
{
    if(game.IsWhiteTurn())
        ui->turnLabel->setPixmap(QPixmap("C:/Users/lenovo/Documents/Moje Programy/Qt/Warcaby/white.png").scaled(30,30));
    else
        ui->turnLabel->setPixmap(QPixmap("C:/Users/lenovo/Documents/Moje Programy/Qt/Warcaby/black.png").scaled(30,30));

    for(int c = 0; c < 8; c++)
        for(int l = 0; l < 8; l++)
        {
            if((c+l)%2 == 0)
                squares[c][l]->setStyleSheet("background-color: white");
            else
                squares[c][l]->setStyleSheet("background-color: brown");
        }

    Piece* pickedPiece = game.GetPickedPiece();
    if(pickedPiece != NULL)
    {
        squares[pickedPiece->GetColumn()][pickedPiece->GetLine()]->setStyleSheet("background-color: blue");
    }

    for(int c = 0; c < 8; c++)
        for(int l = 0; l < 8; l++)
        {
            squares[c][l]->setIconSize(QSize(37,37));
            Piece* piece = game.GetSquarePiece(c,l);
            if(piece != NULL)
            {
                if(piece->GetCcolor() == PieceColor::White)
                    SetSquarePieceAsWhite(c,l);
                else
                    SetSquarePieceAsBlack(c,l);
            }
            else
                RemoveSquarePiece(c,l);

        }
}

void MainWindow::SetSquarePieceAsBlack(int column, int line)
{
    game.SetSquarePieceAsBlack(column,line);
    if(game.IsSquarePieceQueen(column, line))
        squares[column][line]->setIcon(QIcon(blackQueenIconPath));
    else
        squares[column][line]->setIcon(QIcon(blackPieceIconPath));
}

void MainWindow::SetSquarePieceAsWhite(int column, int line)
{
    game.SetSquarePieceAsWhite(column,line);
    if(game.IsSquarePieceQueen(column, line))
        squares[column][line]->setIcon(QIcon(whiteQueenIconPath));
    else
        squares[column][line]->setIcon(QIcon(whitePieceIconPath));
}

/*void MainWindow::on_a8_clicked()
{

}*/

void MainWindow::test(int c, int l)
{
    squares[c][l]->setStyleSheet("background-color: white;");
}

MainWindow::~MainWindow()
{
    delete ui;
}


