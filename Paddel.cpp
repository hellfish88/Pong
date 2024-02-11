#include "Paddel.h"

float Paddle::GetNorm(float impactY) const {
	float neutral = GetMidY();
	float max = neutral + (stats.height / 2);

	float distanceFromCenter = impactY - neutral;
	float norm = distanceFromCenter / (stats.height / 2);
	return std::clamp(norm, -1.0f, 1.0f);

}

void Paddle::SetY(float y) {

	if (!((stats.y + y) >= GetScreenHeight() - (stats.height) || (stats.y + y) <= 0)) {
		stats.y += y * GetFrameTime() * 60;
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
