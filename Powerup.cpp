#include "Powerup.h"

void Powerup::SetY(float _y) {
	position.y = _y;
}
void Powerup::SetX(float _x) {
	position.x = _x;
}

void DoubleUp::Draw() {
	if (shouldDraw)
		DrawCircle(position.x, position.y, radius, color);
}

void DoubleUp::Action() {
	//ball->SetDoublePowerUpBool(true);
	ball->DoubleSpeedFromPowerUp();
}

