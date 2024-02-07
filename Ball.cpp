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
        coords.x += pos;
    } else {
        coords.x = pos;
    }
}

void Ball::SetPosY(int pos, bool reset) {
    if (!reset) {
        coords.y += pos;
    } else {
        coords.y = pos;
    }

}

void Ball::SetSpeedX(int x) {
    if (GetTime() - timeUpdated > 0.3) {
        speedX *= x;
        coords.x += (coords.x > GetScreenWidth()/2)? -5 : 5; /// Fix ball stuck in paddle bug
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
        SetSpeedX(2);
        SetSpeedY(2);
        has_been_doubled = true;
    }
}

void Ball::ResetSpeed() {
    speedX = (speedX <= 0) ? original_speedX * -1 : original_speedX;
    speedY = (speedY <= 0) ? original_speedY * -1 : original_speedY;
}

void Ball::SetCollisionCounter() {
    //timeUpdated = GetTime();
}

Ball::Ball(Circle coords_val) :

    coords(coords_val), speedX(7), speedY(7){
    original_speedX = speedX;
    original_speedY = speedY;
}

void Ball::Update(Paddle* paddle) {
        SetPosX(speedX);
        SetPosY(speedY);


}

void Ball::Draw() const {
    DrawCircle(this->GetPosX(), this->GetPosY(), this->coords.radius, WHITE);
}
