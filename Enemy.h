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
public: //メンバ関数

	Enemy();
	~Enemy();

	void Initialize();
	void Update();
	void Draw();
	void HitBox(Bullet bullet);

public: // メンバ変数

	static int id;
	static bool isAlive;
	Ball ball;

};

