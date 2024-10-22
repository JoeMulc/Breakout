#include "PowerupCameraFlip.h"

PowerupCameraFlip::PowerupCameraFlip(sf::RenderWindow* window, Paddle* paddle, Ball* ball)
	: PowerupBase(window, paddle, ball)
{
	_sprite.setFillColor(sf::Color::White);
}

PowerupCameraFlip::~PowerupCameraFlip()
{

}

std::pair<POWERUPS, float> PowerupCameraFlip::applyEffect() 
{

	return { flipCam, 5.0f };
}