//
// Created by abox on 9/23/17.
//

#ifndef MODELSFML_PARTICLE_H
#define MODELSFML_PARTICLE_H


class Particle {
private:
    float xPosition;
    float yPosition;
    float xVelocity;
    float yVelocity;
    bool dead = false;
public:
    Particle();
    Particle(float xPos,float yPos,float xVel,float yVel);
    float getYPos();
    float getXPos();
    void addVelocity(float xAccl, float yAccl);
    void Advance();
    bool isDead();
};


#endif //MODELSFML_PARTICLE_H
