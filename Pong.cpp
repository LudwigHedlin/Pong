// Pong.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "PongBox.h"
#include "Vec2.h"
#include "Timer.h"

void handleKeys(PongBox& box)
{
    if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
    {
        box.rectLeft.moveUp();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
    {
        box.rectLeft.moveDown();
    }
    else
    {
        box.rectLeft.noMove();
    }

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
    {
        box.rectRight.moveUp();
    }
    else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
    {
        box.rectRight.moveDown();
    }
    else
    {
        box.rectRight.noMove();
    }
}

int main()
{
    sf::RenderWindow window(sf::VideoMode(1000, 800), "Pong");
    
    PongBox box = PongBox(Vec2(100, 100), 800, 600);
    sf::Event event;
    Timer timer;
    while (window.isOpen())
    {
        timer.deltatime();
        box.collision();
        box.update(timer.dt);


        window.clear();
        box.draw(window);
        window.display();
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();

        }

        
        handleKeys(box);


    }
}



// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
