#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
#define HEIGHT 800
#define WIDTH 800


class Board{
public:
    std::vector<std::vector<sf::RectangleShape>> board;

    Board(){
        this -> board = std::vector<std::vector<sf::RectangleShape>>(8, std::vector<sf::RectangleShape>(8));
        for(int i=0; i<8; i++){
            for(int j=0; j<8; j++){
                sf::RectangleShape &cell = this->board[i][j];
                cell.setSize({HEIGHT/8, WIDTH/8});
                cell.setPosition(j*(HEIGHT/8), i*(WIDTH/8));
                if((i+j)%2==0 || (i==0&&j==0)){
                    cell.setFillColor(sf::Color::White);
                }else{
                    cell.setFillColor(sf::Color::Black);
                }
            }
        }
    }

    void display(sf::RenderWindow &window){
        for(auto i:board){
            for(sf::RectangleShape r:i){
                window.draw(r);
            }
        }
    }

};

class Piece{
public:
    int pos_x, pos_y; 
    std::wstring name;
    sf::Text symbol;

    Piece(){}

    Piece(std::wstring name, int px, int py, sf::Font &font):
        name(name), pos_x(px), pos_y(py)
    {
        symbol.setFont(font); 
        symbol.setString(name);
        symbol.setCharacterSize(50);

        symbol.setPosition(
                pos.x*(HEIGHT/8) - symbol.getLocalBounds().width/2 + (HEIGHT/8)/2,
                pos.y*(WIDTH/8) - symbol.getLocalBounds().height/2 + (WIDTH/8)/2
        );

        if((pos_x+pos_y)%2==0 || (pos_y==0&&pos_x==0)){
            symbol.setFillColor(sf::Color::Black);
        }else{
            symbol.setFillColor(sf::Color::White);
        }
    }

    void display(sf::RenderWindow &window){
        window.draw(symbol);
    }
};


class Chess{
public:
    Board b;
    sf::RenderWindow window;
    sf::Font font;
    std::vector<Piece> white_peieces;
    std::vector<Piece> black_peieces;
    Piece p1;

    Chess():window(sf::VideoMode(HEIGHT, WIDTH), "Chess"){
        if (!font.loadFromFile("arial.ttf")){
            std::cerr << ".Error while loading font" << std::endl;
            exit(1);
        }

        white_peieces = std::vector<Piece>(16);
        black_peieces = std::vector<Piece>(16);
        this->init_peiece();
    }

    void init_peiece(){
        std::vector<std::wstring> temp = {L"R", L"K", L"B"};

        for(int i=0; i<8; i++){
            white_peieces[i] = Piece(L"P", i, 1, font);
            black_peieces[i] = Piece(L"P", i, 6, font);
        }

        for(int i=0; i<3; i++){
            white_peieces[8+i] = Piece(temp[i], i, 0, font);
            white_peieces[15-i] = Piece(temp[i], 7-i, 0, font);

            black_peieces[8+i] = Piece(temp[i], i, 7, font);
            black_peieces[15-i] = Piece(temp[i], 7-i, 7, font);
        }
        white_peieces[11] = Piece(L"Q", 3, 0, font);
        white_peieces[12] = Piece(L"Ḱ", 4, 0, font);

        black_peieces[11] = Piece(L"Ḱ", 3, 7, font);
        black_peieces[12] = Piece(L"Q", 4, 7, font);

    }

    void display(){
        while (window.isOpen())
        {
            sf::Event event;
            window.waitEvent(event);
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
            }

            window.clear();
            b.display(window);
            for(int i=0; i<16; i++){
                white_peieces[i].display(window);
                black_peieces[i].display(window);
            }
            window.display();
        }
    }
};
