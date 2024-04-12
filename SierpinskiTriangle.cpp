
#include "SierpinskiTriangle.h"
#ifndef SIERPINSKI_TRIANGLE_H
#define SIERPINSKI_TRIANGLE_H



using namespace std; 

using namespace sf;

SierpinskiTriangle::SierpinskiTriangle() : window(VideoMode(800, 600), "Sierpinski Triangle")
{
}

void SierpinskiTriangle::run()
{
    while (window.isOpen())
    {
        handleEvents();
        generatePoints();
        draw();
    }
}
/* if event type is Event::Closed->user has attempted to close window-> call this window.close().
if event type is Event::MouseButtonPressed-> call this (Mouse::Left)
it further checks if the pressed mouse button is the left button ^^ 
then execute.*/
void SierpinskiTriangle::handle_events()
{
    Event event;
    while (window.pollEvent(event)){
        if (event.type == Event::Closed)
            window.close();
      if (event.type == Event::MouseButtonPressed) {
            if (event.mouseButton.button == Mouse::Left) {
                cout << "Mouse clicked at: (" << event.mouseButton.x << ", " << event.mouseButton.y << ")" << endl;

            if (vertices.size() < 3){
               vertices.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
               RectangleShape vertexRect(Vector2f(10, 10));
               vertexRect.setPosition(Vector2f(event.mouseButton.x - 5, event.mouseButton.y - 5));
               vertexRect.setFillColor(Color::Blue);
               window.draw(vertexRect);
                }
                else if (points.size() == 0) {
                    // Fourth click to start the algorithm
                    points.push_back(Vector2f(event.mouseButton.x, event.mouseButton.y));
               }
           }
       }
   }
}

//TO DO: look at logic again ^^

//example flow: make points -> draw those points->clear that point->plot and fill (loop that last step)

void SierpinskiTriangle::generate_points() {
    if (points.size() > 0) {
        //use random number generator 
        random_device rd;
        mt19937 gen(rd());
        uniform_int_distribution<int> distrib(0, 2);

        //make more points using calculation vertex + lastPoint / 2.f
        int vertexIndex = distrib(gen); /* selecting random coordinates here can change later test purposes*/
        Vector2f vertex = vertices[vertexIndex];
        Vector2f lastPoint = points.back();
        Vector2f newPoint = (vertex + lastPoint) / 2.f;
        points.push_back(newPoint);
    }
}

void SierpinskiTriangle::draw(){
    window.clear();//clear last point

    //before filling color, plan where to plot
  for (int i = 0; i < vertices.size(); i++) {
        RectangleShape vertexRect(Vector2f(10, 10));
        vertexRect.setPosition(Vector2f(vertices[i].x - 5, vertices[i].y - 5));
        vertexRect.setFillColor(Color::Blue);
        window.draw(vertexRect);
  }

    //plot points out in tri form array move from one->draw another point and fill
  for (int i = 0; i < points.size(); i++) {
        CircleShape newPointCircle(2.5f);
        newPointCircle.setPosition(points[i]);
        newPointCircle.setFillColor(Color::Red);
        window.draw(newPointCircle);
    }

 window.display();
}

#endif
