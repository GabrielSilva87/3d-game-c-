#include "Bullet.h"

Bullet::Bullet() : speed(5.0f) {
    shape.setRadius(5);
    shape.setFillColor(sf::Color::Yellow);
}

void Bullet::update() {
    shape.move(0, -speed);
}

void Bullet::setPosition(float x, float y) {
    shape.setPosition(x, y);
}

bool Bullet::isOffScreen() const {
    return shape.getPosition().y < 0;
}

sf::CircleShape Bullet::getShape() const {
    return shape;
}