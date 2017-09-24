#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "SFML-2.4.2/Particle.h"


using namespace sf;


void spawnLoop( std::vector<Particle*> &particleVector ){
    for (int i=0; i < 5; i++) {
        float xVar = (rand() % 4) +1;
        float yVar = (rand() % 4) +1;
        particleVector.push_back( new Particle(400,400,xVar,yVar) );
    }
}



void advanceLoop( std::vector<Particle*> &particleVector ){
    for (auto i = particleVector.rbegin();
            i != particleVector.rend(); i++){
        (*i)->addVelocity(1,5);
        (*i)->Advance();

        if ((*i)->isDead()){
            delete(*i);
            std::advance(i, 1);
            particleVector.erase( i.base() );

        }
    }
}

int main() {
    RenderWindow window(VideoMode(900,900),"Hello SFML");
    window.setFramerateLimit(30);

    std::vector<Particle*> vec; // Are pointeri catre obiecte


    while(window.isOpen()){
        Event event;
        while(window.pollEvent(event)) {
            if (event.type == Event::Closed) {
                window.close();
            }
            window.clear(Color::White);

            spawnLoop(vec);
            advanceLoop(vec);
            for (auto i = vec.begin(); i != vec.end(); i++){
                CircleShape shape;
                shape.setPosition((*i)->getXPos(),(*i)->getYPos());
                shape.setRadius(1);
                shape.setFillColor(Color::Black);
                window.draw(shape);
                window.display();
            }



            window.display();
        }

        }

    return 0;
}