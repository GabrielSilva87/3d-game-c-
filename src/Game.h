#ifndef GAME_H
#define GAME_H

#include <SFML/Graphics.hpp>
#include <vector>
#include "Bullet.h"

class Game {
public:
    Game();
    void run();

private:
    void processEvents();
    void update();
    void render();
    void shoot();

    sf::RenderWindow window;
    std::vector<Bullet> bullets;
    sf::CircleShape target;
    sf::Vector2f targetPosition;
};

#endif // GAME_H