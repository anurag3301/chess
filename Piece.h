#pragma once
#include "utils.h"

std::vector<Pos> diagnoal;
std::vector<Pos> straight;
std::vector<Pos> knight_move;
std::vector<Pos> king_move;


class Piece{
public:
    Pos pos;
    std::wstring name;
    sf::Text symbol;
    Piece_color color;
    Piece_type type;
    std::vector<Pos> moves;

    Piece(){}

    void init_moves(){
        if(diagnoal.empty()){
            for(int i=-7; i<=7; i++){
                diagnoal.push_back(Pos({i, i}));
                diagnoal.push_back(Pos({i, -i}));
            }
        }
        if(straight.empty()){
            for(int i=-7; i<=7; i++){
                straight.push_back(Pos({0, i}));
                straight.push_back(Pos({i, 0}));
            }
        }
        if(knight_move.empty()){
            knight_move = std::vector<Pos>({{-2,-1}, {-1,-2}, {1,-2}, {2,-1}, {-2,1}, {-1,2}, {1,2}, {2,1}});
        }
        if(king_move.empty()){
            king_move = std::vector<Pos>({{-1,-1}, {0,-1}, {1,-1}, {-1,0}, {1,0}, {-1,1}, {0,1}, {1,1}});
        }
    }


    Piece(std::wstring n, int px, int py, sf::Font &font, Piece_type t, Piece_color col){
        init_moves();

        name = n;
        pos = {px, py};
        color = col;
        type = t;

        symbol.setFont(font); 
        symbol.setString(name);
        symbol.setCharacterSize(50);

        symbol.setPosition(
                pos.x*(HEIGHT/8) - symbol.getLocalBounds().width/2 + (HEIGHT/8)/2,
                pos.y*(WIDTH/8) - symbol.getLocalBounds().height/2 + (WIDTH/8)/2
        );

        if(pos.y >= 6){
            symbol.setFillColor(sf::Color::Black);
        }else{
            symbol.setFillColor(sf::Color::White);
        }

        if(type == Rook){
            moves = straight;
        }else if(type == Knight){
            moves = knight_move;
        }else if(type == Bishop){
            moves = diagnoal;
        }else if(type == King){
            moves = king_move;
        }else if(type == Queen){
            moves = straight;
            moves.insert(moves.end(), diagnoal.begin(), diagnoal.end());
        }


    }

    std::vector<Pos> get_moves(){
        return moves;
    }

    Pos getPos(){
        return pos;
    }

    Piece_type getType(){
        return  type;
    }

    Piece_color getColor(){
        return  color;
    }

    void display(sf::RenderWindow &window){
        window.draw(symbol);
    }
};
