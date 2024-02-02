#include "Ball.h"

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
    speedX *= x;
}

void Ball::SetSpeedY(int y) {
    speedY *= y;
}

Ball::Ball(Coords coords_val) :
    //coords.x(coords.x), coords.y(coords.y), coords.radius(coords.radius), speedX(7), speedY(7){
    coords(coords_val), speedX(7), speedY(7){
    //DrawCircle(coords.x, posY, rad, WHITE);
}

void Ball::Update() {

        //if (Getcoords.x() + radius >= GetScreenWidth() || Getcoords.x() - radius <= 0) {
        //    speedX *= -1;
        //}
        //if (GetPosY() + radius >= GetScreenHeight() || GetPosY() - radius <= 0) {
        //    speedY *= -1;
        //}
        
        SetPosX(speedX);
        SetPosY(speedY);
 
}

void Ball::Draw() const {
    DrawCircle(this->GetPosX(), this->GetPosY(), this->coords.radius, WHITE);
}
