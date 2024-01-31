#include "Paddel.h"

void Paddle::SetY(int y) {
	if (!((posy + y) >= GetScreenHeight() - (height) || (posy + y) <= 0)) {
		posy += y;
	}
}

void Paddle::Update(int speed) {
	if (IsKeyDown(KEY_DOWN)) {
		SetY(speed);
	} else if (IsKeyDown(KEY_UP)) {
		SetY(speed * -1);
	}
}