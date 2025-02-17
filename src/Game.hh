// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "Food.hh"
#include "Snake.hh"

#pragma once

#ifndef GAME_HH
#define GAME_HH

namespace snake {

class Game
{
  public:
	Game();
	~Game();

  public:
	void Draw();
	void Update();

  private:
	Snake snake;
	Food food;
	double lastUpdateTime = 0.0;
	bool running = true;

  private:
	bool shouldUpdate();
	void handleInput();
	void checkFoodCollision();
	void checkSnakeTailCollision();
	void gameOver();
};

}

#endif
