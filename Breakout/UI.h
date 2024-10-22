#pragma once
#include <vector>
#include <SFML/Graphics.hpp>

#include "CONSTANTS.h"
#include "PowerupManager.h"

class GameManager;

class UI
{
public:
	UI(sf::RenderWindow* window, int lives, GameManager* gameManager);
	~UI();

	void updatePowerupText(std::pair<POWERUPS, float>);
	void lifeLost(int lives);
	void screenShake(float intensity, float duration);
	void flipCamera();
	void update(float dt);
	void render();

private:
	GameManager* _gameManager;
	
	sf::RenderWindow* _window;
	sf::View _view;
	sf::View _defaultView;
	sf::Font _font;
	sf::Text _powerupText;

	std::vector<sf::CircleShape> _lives;

	static constexpr float LIFE_RADIUS = 15.0f;
	static constexpr float LIFE_PADDING = 20.0f;

	//screen shake variables
	bool bShouldShake = false;
	float _intensity;
	float _duration;
	sf::Clock _clock;
};

