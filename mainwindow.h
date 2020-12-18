#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include <QPushButton>
#include <QLabel>
#include <QPixmap>

#include "game.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    void ClickSquare(int column,int line);
    void EndGame();
    void RemoveSquarePiece(int column, int line);
    void RenderBoard();
    void SetSquarePieceAsBlack(int column, int line);
    void SetSquarePieceAsWhite(int column, int line);
    ~MainWindow();

private slots:
    //void on_a8_clicked();
    void test(int,int);

private:
    Ui::MainWindow *ui;
    Game game;
    QPushButton* squares[8][8];
    QLabel* pieces[8][8];

    QString blackPieceIconPath;
    QString whitePieceIconPath;
    QString blackQueenIconPath;
    QString whiteQueenIconPath;

    //QPixmap whitePiecePixMap;
    //QPixmap blackPiecePixMap;
};
#endif // MAINWINDOW_H
