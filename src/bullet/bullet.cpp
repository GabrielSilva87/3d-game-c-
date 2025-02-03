#ifndef BULLET_H
#define BULLET_H

#include <SFML/Graphics.hpp>

class Bullet {
public:
    Bullet();
    void update();
    void setPosition(float x, float y);
    bool isOffScreen() const;
    sf::CircleShape getShape() const;

private:
    sf::CircleShape shape;
    float speed;
};

#endif // BULLET_H