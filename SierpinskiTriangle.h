#pragma once
#include <SFML/Graphics.hpp>

/*
FIX: If you're using Visual studio, right click on the project and then on Properties, 
Under Configuration Properties click on C\C++ and then add the directory 
to your header files under the Additional Include Directories section.
*/
//TO DO: still need to inlude one type of text
#ifndef SIERPINSKI_TRIANGLE_H
#define SIERPINSKI_TRIANGLE_H


#include <iostream>
#include <vector>
#include <random>

using namespace std;

class SierpinskiTriangle
{
public:
    SierpinskiTriangle();

    void run();

private:
    
    
    /*FIX:In Component::GetListeners you are returning the address of a function local variable, 
    one that immediately goes out of scope and is destructed. 
    You would either need to make it not function local or not return the pointer.*/
     vector<sf::Vector2f> vertices;
    vector<sf::Vector2f> points;
    sf::RenderWindow window;
   
    sf::Font font;
    sf::Text instructionText;
     
    void handle_events();
    void generate_points();
    void draw();
};

#endif 
