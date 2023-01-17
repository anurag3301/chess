#pragma once
#include "utils.h"
#include "Piece.h"
#include "Board.h"

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


    Piece* piece_on(Pos cell){
        for(int i=0; i<white_peieces.size(); i++){
            if(white_peieces[i].getPos() == cell){
                return &white_peieces[i];
            }
            if(black_peieces[i].getPos() == cell){
                return &black_peieces[i];
            }
        }
        return nullptr;
    }

    void clicked(sf::Event &event){
        if(event.mouseButton.button == sf::Mouse::Left){
            Pos clicked_pos;
            clicked_pos.x = event.mouseButton.x/(HEIGHT/8);
            clicked_pos.y = event.mouseButton.y/(WIDTH/8);

            b.cell_select(clicked_pos);

            Piece* peice_oncell = piece_on(clicked_pos);

            if(peice_oncell != nullptr){
                std::vector<Pos> moves = peice_oncell->get_moves();
                for(auto i:moves){
                    Pos final_move = i+clicked_pos;
                    if((final_move.x>=0 && final_move.x<=7) &&
                        (final_move.y>=0 && final_move.y<=7)){
                        b.add_moves_indicator(final_move);
                    }
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
            b.display_move_indicator(window);
            for(int i=0; i<16; i++){
                white_peieces[i].display(window);
                black_peieces[i].display(window);
            }
            window.display();
        }
    }
};
