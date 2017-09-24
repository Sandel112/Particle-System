//
// Created by abox on 9/23/17.
//

#include "Particle.h"
Particle::Particle(){
}

Particle::Particle(float xPos= 400,float yPos= 400,float xVel= 0,float yVel= 0) {
    float xPosition = xPos;
    float yPosition = yPos;
    float xVelocity = xVel;
    float yVelocity = yVel;
    bool dead = false;
}

void Particle::Advance(){
    xPosition += xVelocity;
    yPosition += yVelocity;
    if ((xPosition < 0) or (xPosition > 900)){
        dead = true;
    }

    if ((yPosition < 0) or (yPosition > 900)){
        dead = true;
    }
}

void Particle::addVelocity(float xAccl, float yAccl){
    xVelocity += xAccl;
    yVelocity += yAccl;
}

bool Particle::isDead(){
    return dead;
}

float Particle::getXPos(){
    return xPosition;
}

float Particle::getYPos(){
    return yPosition;
}