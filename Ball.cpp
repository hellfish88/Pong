#include "Ball.h"
#include <iostream>

float Ball::GetPosX() const {
    return coords.x;
}

float Ball::GetPosY() const {
    return coords.y;
}

void Ball::SetPosX(int pos, bool reset) {
    if (!reset) {
        coords.x += pos * GetFrameTime() * *speed_multiplier;
    } else {
        coords.x = pos;
    }
}

void Ball::SetPosY(int pos, bool reset) {
    if (!reset) {
        coords.y += pos * GetFrameTime() * *speed_multiplier;
    } else {
        coords.y = pos;
    }
}

void Ball::SetSpeedX(int x) {
    if (GetTime() - timeUpdated < 0.3 && collisionCount > 1) {/// Fix ball stuck in paddle bug
        speedX *= x;
        coords.x += (coords.x > GetScreenWidth()/2)? -5 : 5; 
        std::cout << "Ball pos fixed! bugfix worked!!" << std::endl;
    } else {
        speedX *= x;
    }
}

void Ball::SetSpeedY(int y) {
    if (customDirection) {
        speedY = (original_speedY *y) * normRatio;
        customDirection = false;
    } else {
        speedY *= y;
    }
}

void Ball::DoubleSpeed() {
    if (!has_been_doubled) {
        //SetSpeedX(2);
        //SetSpeedY(2);
        SetColor(RED);
        SetSpeedMultiplier(GetSpeedMultiplier() + 60);
        has_been_doubled = true;
        has_been_doubledByPowerup = false;
    }
}

void Ball::DoubleSpeedFromPowerUp() {
    if (doubleUpCount < 1) {
        //SetSpeedX(2);
        //SetSpeedY(2);
        SetColor(GREEN);
        SetSpeedMultiplier(GetSpeedMultiplier() + 60);
        doubleUpCount++;
    }
}

void Ball::ResetSpeed() {
    speedX = (speedX <= 0) ? original_speedX * -1 : original_speedX;
    speedY = (speedY <= 0) ? original_speedY * -1 : original_speedY;
    doubleUpCount = 0;
}


Ball::Ball(Circle coords_val) :

    coords(coords_val), speedX(initialSpeed), speedY(initialSpeed){
    original_speedX = speedX;
    original_speedY = speedY;
}

void Ball::Update() {
        SetPosX(speedX);
        SetPosY(speedY);
        if (coords.x > (GetScreenWidth() /2) - 20 && coords.x < (GetScreenWidth() /2) + 20 && collisionCount >= 1) // Continueing of bugfix for ball stuck in paddle
            collisionCount = 0;


}

void Ball::Draw() const {
    DrawCircle(this->GetPosX(), this->GetPosY(), this->coords.radius, color);
}
