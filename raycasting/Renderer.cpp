#include "Renderer.h"

Renderer::Renderer(sf::RenderWindow& window) {
	this->window = &window;
	map = new Map();
	player = new Player(map);
	enemy = new Enemy();
}

Renderer::~Renderer() {
	delete map;
	delete player;
	delete enemy;
}

void Renderer::update(float time) {
	player->update(*window, time);
}

void Renderer::render() {
	
	for (const auto rectangle : map->getGraphicPresentation()) {
		window->draw(*rectangle);
	}

	window->draw(*player->getPlayerModel());
	window->draw(*enemy->getEnemyModel()); 
     
	for (const auto sightLine : player->getSightLines()) {
		window->draw(*sightLine);
	} 

	for (const auto wall : player->getWalls()) {
		window->draw(*wall);
	}
} 