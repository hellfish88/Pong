#pragma once

class Ball {

private:
	float posX, posY;
	int speedX;
	int speedY;
	int radius;
	bool exists = false;
public:
	int GetPosX() const;
	int GetPosY() const;
	int GetRadius() const { return radius; }
	void SetPosX(int);
	void SetPosY(int);
	void SetSpeedX(int);
	void SetSpeedY(int);
	Ball(int posX, int posY, int rad);
	void Update();
	void Draw() const;
	bool Exists() const { return exists; }
};