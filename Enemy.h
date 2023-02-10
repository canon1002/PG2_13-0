#pragma once
#include<Vector2.h>
#include<Bullet.h>

typedef struct Ball {
	Vector2 pos;
	Vector2 vel;
	Vector2 acc;
	float mass;
	float rad;
	unsigned int color;
};

class Enemy
{
public: //ƒƒ“ƒoŠÖ”

	Enemy();
	~Enemy();

	void Initialize();
	void Update();
	void Draw();
	void HitBox(Bullet bullet);

public: // ƒƒ“ƒo•Ï”

	static int id;
	static bool isAlive;
	Ball ball;

};

