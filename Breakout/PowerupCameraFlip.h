#pragma once
#include "PowerupBase.h"
class PowerupCameraFlip : public PowerupBase
{
public:
	PowerupCameraFlip(sf::RenderWindow* window, Paddle* paddle, Ball* ball);
	~PowerupCameraFlip();
	std::pair<POWERUPS, float> applyEffect() override;
};

