// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include <deque>
#include <raylib.h>

#pragma once

#ifndef SNAKE_HH
#define SNAKE_HH

namespace snake {
class Snake
{
  public:
	Snake();
	~Snake();

  public:
	std::deque<Vector2> body;
	Vector2 direction = Vector2(1, 0);

  public:
	void Draw();
	void Update();
};
}

#endif
