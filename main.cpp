#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>

#define HEIGHT 800
#define WEIGHT 800

using std::cout;
using std::endl;

int main()
{
    sf::RenderWindow window(sf::VideoMode(HEIGHT, WEIGHT), "SFML works!");

    std::vector<std::vector<sf::RectangleShape>> board(8, std::vector<sf::RectangleShape>(8));

    for(int i=0; i<8; i++){
        for(int j=0; j<8; j++){
            sf::RectangleShape &cell = board[i][j];
            cell.setSize({HEIGHT/8, WEIGHT/8});
            cell.setPosition(j*(HEIGHT/8), i*(WEIGHT/8));
            if((i+j)%2==0 || (i==0&&j==0))
                cell.setFillColor(sf::Color::White);
            else
                cell.setFillColor(sf::Color::Black);
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
        for(auto i:board){
            for(sf::RectangleShape r:i){
                window.draw(r);
            }
        }
        window.display();
    }

    return 0;
}
