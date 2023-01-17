#pragma once
#include "utils.h"

class Board{
public:
    std::vector<std::vector<sf::RectangleShape>> board;
    Pos selected;
    std::vector<sf::CircleShape> moves_indiator;

    Board(){
        this -> board = std::vector<std::vector<sf::RectangleShape>>(8, std::vector<sf::RectangleShape>(8));
        this->selected = {0, 0};

        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                sf::RectangleShape &cell = this->board[i][j];
                cell.setSize({HEIGHT/8, WIDTH/8});
                cell.setPosition(j*(HEIGHT/8), i*(WIDTH/8));
                if((i+j)%2==0 || (i==0&&j==0)){
                    cell.setFillColor(sf::Color(125, 148, 93));
                }else{
                    cell.setFillColor(sf::Color(238, 238, 213));
                }
            }
        }



    }

    void add_moves_indicator(Pos move){
        sf::CircleShape circle;
        int rad = 15;
        circle.setRadius(rad);
        circle.setPosition(move.x*(HEIGHT/8) + (HEIGHT/8)/2 - rad, move.y*(WIDTH/8) + (WIDTH/8)/2 - rad);
        if((move.x+move.y)%2==0 || (move.x==0&&move.y==0)){
            circle.setFillColor(sf::Color(106, 135, 77));
        }else{
            circle.setFillColor(sf::Color(214, 214, 189));
        }
        moves_indiator.push_back(circle);
    }

    void display_move_indicator(sf::RenderWindow &window){
        for(auto c:moves_indiator)
            window.draw(c);
    }

    void cell_select(Pos &pos){
        if((selected.x+selected.y)%2==0 || (selected.x==0&&selected.y==0)){
            board[selected.y][selected.x].setFillColor(sf::Color(125, 148, 93));
        }else{
            board[selected.y][selected.x].setFillColor(sf::Color(238, 238, 213));
        }

        selected = pos;
        if((selected.x+selected.y)%2==0 || (selected.x==0&&selected.y==0)){
            board[selected.y][selected.x].setFillColor(sf::Color(186, 202, 43));
        }else{
            board[selected.y][selected.x].setFillColor(sf::Color(245, 236, 105));
        }

        moves_indiator.clear();
    }

    void display(sf::RenderWindow &window){
        for(auto i:board)
            for(sf::RectangleShape r:i)
                window.draw(r);
    }
};






