#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include "board.h"

#define HEIGHT 800
#define WEIGHT 800

using std::cout;
using std::endl;

int main()
{
    sf::RenderWindow window(sf::VideoMode(HEIGHT, WEIGHT), "SFML works!");

    Board b;

    std::vector<std::vector<sf::Text>> text(8, std::vector<sf::Text>(8));

    sf::Font font;
    if (!font.loadFromFile("arial.ttf"))
    {
        std::cerr << ".Error while loading font" << std::endl;
        return -1;
    }

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            sf::Text &cellText = text[i][j];
            cellText.setFont(font);
            cellText.setString("P");
            cellText.setCharacterSize(50);
            cellText.setPosition(
                    j*(HEIGHT/8) - cellText.getLocalBounds().width/2 + (HEIGHT/8)/2,
                    i*(WEIGHT/8) - cellText.getLocalBounds().height/2 + (WEIGHT/8)/2
            );

            if((i+j)%2==0 || (i==0&&j==0)){
                cellText.setFillColor(sf::Color::Black);
            }else{
                cellText.setFillColor(sf::Color::White);
            }
        }
    }


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
        // for(auto i:text){
        //     for(sf::Text t:i){
        //         window.draw(t);
        //     }
        // }
        window.display();
    }

    return 0;
}
