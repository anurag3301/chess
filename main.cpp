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

    Chess c;
    c.display();
    // std::vector<std::vector<sf::Text>> text(8, std::vector<sf::Text>(8));

    // sf::Font font;
    // if (!font.loadFromFile("arial.ttf"))
    // {
    //     std::cerr << ".Error while loading font" << std::endl;
    //     return -1;
    // }

    // for(int i=0; i<8; i++){
    //     for(int j=0; j<8; j++){
    //         sf::Text &cellText = text[i][j];
    //         cellText.setFont(font);
    //         cellText.setString("P");
    //         cellText.setCharacterSize(50);
    //         cellText.setPosition(
    //                 j*(HEIGHT/8) - cellText.getLocalBounds().width/2 + (HEIGHT/8)/2,
    //                 i*(WEIGHT/8) - cellText.getLocalBounds().height/2 + (WEIGHT/8)/2
    //         );

    //         if((i+j)%2==0 || (i==0&&j==0)){
    //             cellText.setFillColor(sf::Color::Black);
    //         }else{
    //             cellText.setFillColor(sf::Color::White);
    //         }
    //     }
    // }


    return 0;
}
