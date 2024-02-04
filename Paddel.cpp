#include "Paddel.h"

void Paddle::SetY(int _y) {
	float y = static_cast<float>(_y);

	if (!((stats.y + y) >= GetScreenHeight() - (stats.height) || (stats.y + y) <= 0)) {
		stats.y += y;
	}
}

void Paddle::Update(float speed) {
	if (IsKeyDown(KEY_DOWN)) {
		SetY(speed);
	} else if (IsKeyDown(KEY_UP)) {
		SetY(speed * -1);
	}
}

Rectangle Paddle::GetDimensions() const {
	return stats;
}
