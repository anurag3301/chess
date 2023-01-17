#pragma once

#include <iostream>
#include <SFML/Graphics.hpp>
#include <vector>

#define HEIGHT 800
#define WIDTH 800

using std::cout;
using std::endl;

struct Pos{
    int x;
    int y;
};

bool operator==(const Pos &p1, const Pos &p2){
    return p1.x == p2.x && p1.y == p2.y;
}

Pos operator+(const Pos &p1, const Pos &p2){
    return Pos({p1.x+p2.x, p1.y+p2.y});
}

enum Piece_color{
    Black_P,
    White_P
};

enum Piece_type{
    Pawn,
    Rook,
    Knight,
    Bishop,
    Queen,
    King
};
