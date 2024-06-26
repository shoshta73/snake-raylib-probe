// Copyright (c) 2024 Borna Šoštarić
//
// This software is released under the MIT License.
// https://opensource.org/licenses/MIT

#include "Food.hh"
#include "Snake.hh"
#include "defines.hh"

#include "raylib.h"

double lastUpdateTime = 0.0;

bool
eventTriggered(double interval)
{
	double curr = GetTime();
	if (curr - lastUpdateTime >= interval) {
		lastUpdateTime = curr;
		return true;
	}
	return false;
}

using namespace snake;

int
main(void)
{
	InitWindow(CELL_SIZE * CELLS_COUNT, CELL_SIZE * CELLS_COUNT, "Snake");
#if !DEBUG
	SetExitKey(KEY_NULL);
#endif
	SetTargetFPS(60);

	Food food = Food();
	Snake snake = Snake();
	while (!WindowShouldClose()) {
		BeginDrawing();

		if (eventTriggered(INTERVAL)) {
			snake.Update();
		}

		if ((IsKeyPressed(KEY_UP) || IsKeyPressed(KEY_W) || IsKeyPressed(KEY_KP_8)) && snake.direction.y != 1)
			snake.direction = { 0, -1 };
		if ((IsKeyPressed(KEY_DOWN) || IsKeyPressed(KEY_S) || IsKeyPressed(KEY_KP_2)) && snake.direction.y != -1)
			snake.direction = { 0, 1 };
		if ((IsKeyPressed(KEY_LEFT) || IsKeyPressed(KEY_A) || IsKeyPressed(KEY_KP_4)) && snake.direction.x != 1)
			snake.direction = { -1, 0 };
		if ((IsKeyPressed(KEY_RIGHT) || IsKeyPressed(KEY_D) || IsKeyPressed(KEY_KP_6)) && snake.direction.x != -1)
			snake.direction = { 1, 0 };

		ClearBackground(green);

		food.Draw();
		snake.Draw();

		EndDrawing();
	}
	CloseWindow();

	return 0;
}
