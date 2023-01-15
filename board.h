#pragma once

#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
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
        std::vector<Piece_type> type = {Rook, Knight, Bishop};

        for(int i=0; i<8; i++){
            white_peieces[i] = Piece(L"P", i, 1, font, Pawn, White_P);
            black_peieces[i] = Piece(L"P", i, 6, font, Pawn, Black_P);
        }

        for(int i=0; i<3; i++){
            white_peieces[8+i] = Piece(temp[i], i, 0, font, type[i], White_P);
            white_peieces[15-i] = Piece(temp[i], 7-i, 0, font, type[i], White_P);

            black_peieces[8+i] = Piece(temp[i], i, 7, font, type[i], Black_P);
            black_peieces[15-i] = Piece(temp[i], 7-i, 7, font, type[i], Black_P);
        }
        white_peieces[11] = Piece(L"Q", 3, 0, font, Queen, White_P);
        white_peieces[12] = Piece(L"Ḱ", 4, 0, font, King, White_P);

        black_peieces[11] = Piece(L"Ḱ", 3, 7, font, King, Black_P);
        black_peieces[12] = Piece(L"Q", 4, 7, font, Queen, Black_P);

    }

    void clicked(sf::Event &event){
        if(event.mouseButton.button == sf::Mouse::Left){
            Pos clicked_pos;
            clicked_pos.x = event.mouseButton.x/(HEIGHT/8);
            clicked_pos.y = event.mouseButton.y/(WIDTH/8);
            b.cell_select(clicked_pos);
            for(auto i:white_peieces){
                if (i.getPos() == clicked_pos){
                    cout << i.getColor() << " " << i.getType() << endl;
                }
            }

            for(auto i:black_peieces){
                if (i.getPos() == clicked_pos){
                    cout << i.getColor() << " " << i.getType() << endl;
                }
            }
            
        } 
    }

    void display(){
        while (window.isOpen())
        {
            sf::Event event;
            while (window.pollEvent(event))
            {
                if (event.type == sf::Event::Closed)
                    window.close();
                if (event.type == sf::Event::MouseButtonPressed){
                    clicked(event);
                }
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
