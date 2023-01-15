#pragma once
#include "utils.h"

class Board{
public:
    std::vector<std::vector<sf::RectangleShape>> board;
    Pos selected;

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
    }

    void display(sf::RenderWindow &window){
        for(auto i:board)
            for(sf::RectangleShape r:i)
                window.draw(r);
    }
};






