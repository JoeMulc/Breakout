#include "Paddle.h"
#include <iostream>
#include <SFML/Window/Mouse.hpp>

Paddle::Paddle(sf::RenderWindow* window)
    : _window(window), _width(PADDLE_WIDTH), _timeInNewSize(0.0f), _isAlive(true)
{
    _sprite.setFillColor(sf::Color::Cyan);
    _sprite.setPosition((window->getSize().x - _width) / 2.0f, window->getSize().y - 50.0f);
    _sprite.setSize(sf::Vector2f(_width, PADDLE_HEIGHT));
}

Paddle::~Paddle()
{
}


void Paddle::moveLeft(float dt)
{
    float position = _sprite.getPosition().x;

    _sprite.move(sf::Vector2f(-dt * PADDLE_SPEED, 0));
    
  
}

void Paddle::moveRight(float dt)
{
    float position = _sprite.getPosition().x;

    _sprite.move(sf::Vector2f(dt * PADDLE_SPEED, 0));
}

void Paddle::update(float dt)
{
    if (_timeInNewSize > 0)
    {
        _timeInNewSize -= dt;
    }
    else
    {
        setWidth(1.0f, 0.0f); // Reset to default width after duration
    }
}

void Paddle::handleInput(float dt)
{
    float position = _sprite.getPosition().x;

    if (sf::Mouse::getPosition(*_window).x < _sprite.getPosition().x && position > 0)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            moveLeft(dt);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            moveRight(dt);
        }
        else
        {
            moveLeft(dt);
        }
    }
    else if (sf::Mouse::getPosition(*_window).x > _sprite.getPosition().x && position > 0)
    {
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
        {
            moveRight(dt);
        }
        else if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
        {
            moveLeft(dt);
        }
        else
        {
            moveRight(dt);
        }
    }
}

void Paddle::render()
{
    _window->draw(_sprite);
}

sf::FloatRect Paddle::getBounds() const
{
    return _sprite.getGlobalBounds();
}

// update width by SF of coeff. 
// ensure centre remains consistent.
void Paddle::setWidth(float coeff, float duration)
{
    _width = coeff * PADDLE_WIDTH;
    _sprite.setSize(sf::Vector2f(_width, _sprite.getSize().y));
    _timeInNewSize = duration;
    float newX = _sprite.getPosition().x + (_width - PADDLE_WIDTH) / 2;
    _sprite.setPosition(newX, _sprite.getPosition().y);
}
