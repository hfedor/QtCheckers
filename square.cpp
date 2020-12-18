#include "square.h"

using namespace std;

Square::Square()
{
    column = -1;
    line = -1;

    color = SquareColor::White;
}

Square::Square(int c, int l)
{
    column = c;
    line = l;
}

Square::Square(int c, int l, SquareColor sc, QPushButton *b, Piece *p)
{
    column = c;
    line = l;

    color = sc;
    button = b;
    piece = p;
}

string Square::GetNotation()
{
    char columnNot = column + 49;
    char lineNot = line + 65;
    string result;
    result[0] = columnNot;
    result += ":";
    result[2] = lineNot;
    return result;
}
