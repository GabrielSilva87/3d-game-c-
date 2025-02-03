#include "Game.h"
#include <iostream>

Game::Game() : window(sf::VideoMode(800, 600), "Shooting Game") {
    target.setRadius(20);
    target.setFillColor(sf::Color::Red);
    targetPosition = sf::Vector2f(400, 300);
    target.setPosition(targetPosition);
}

void Game::run() {
    while (window.isOpen()) {
        processEvents();
        update();
        render();
    }
}

void Game::processEvents() {
    sf::Event event;
    while (window.pollEvent(event)) {
        if (event.type == sf::Event::Closed)
            window.close();
        if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Space) {
            shoot();
        }
    }
}

void Game::update() {
    for (auto& bullet : bullets) {
        bullet.update();
    }
    bullets.erase(std::remove_if(bullets.begin(), bullets.end(), [](Bullet& b) { return b.isOffScreen(); }), bullets.end());
}

void Game::render() {
    window.clear();
    window.draw(target);
    for (const auto& bullet : bullets) {
        window.draw(bullet.getShape());
    }
    window.display();
}

void Game::shoot() {
    Bullet bullet;
    bullet.setPosition(400, 550); // Posição inicial da bala
    bullets.push_back(bullet);
}