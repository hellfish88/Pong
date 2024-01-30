#include "Ball.h"
#include "raylib.h"
int Ball::GetPosX() const {
    return posX;
}

int Ball::GetPosY() const {
    return posY;
}

void Ball::SetPosX(int pos) {
    posX += pos;
}

void Ball::SetPosY(int pos) {
    posY += pos;
}

void Ball::SetSpeedX(int x) {
    speedX *= x;
}

void Ball::SetSpeedY(int y) {
    speedY *= y;
}

Ball::Ball(int posX, int posY, int rad) :
    posX(posX), posY(posY), radius(rad), speedX(7), speedY(7){
    //DrawCircle(posX, posY, rad, WHITE);
    exists = true;
}

void Ball::Update() {

        //if (GetPosX() + radius >= GetScreenWidth() || GetPosX() - radius <= 0) {
        //    speedX *= -1;
        //}
        //if (GetPosY() + radius >= GetScreenHeight() || GetPosY() - radius <= 0) {
        //    speedY *= -1;
        //}

        SetPosX(speedX);
        SetPosY(speedY);

}

void Ball::Draw() const {
    DrawCircle(this->GetPosX(), this->GetPosY(), radius, WHITE);
}
