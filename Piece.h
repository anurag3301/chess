#pragma once
#include "utils.h"

class Piece{
public:
    Pos pos;
    std::wstring name;
    sf::Text symbol;
    Piece_color color;
    Piece_type type;

    Piece(){}

    Piece(std::wstring n, int px, int py, sf::Font &font, Piece_type t, Piece_color col){
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
