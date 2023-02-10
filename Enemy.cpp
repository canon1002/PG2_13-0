#include "Enemy.h"
#include<Novice.h>

Enemy::Enemy() {
	
	this->Initialize();
	
	id++;
}

Enemy::~Enemy() {

	id--;
}

void Enemy::Initialize() {
	
	if (id == 1) {
		ball.pos = { 400,100 };
	}
	else{
		ball.pos = { 100,300 };
	}

	ball.vel = { 4,0 };
	ball.acc = { 0,0 };
	ball.rad = 32;
	ball.mass = 0.0f;
	ball.color = 0xFF3333FF;

}

void Enemy::Update() {

	if (isAlive) {
		ball.pos += ball.vel;

		if (ball.pos.x + ball.rad > 1280) {
			ball.vel.x *= -1;
		}
		if (ball.pos.x - ball.rad < 0) {
			ball.vel.x *= -1;
		}

	}

}

void Enemy::HitBox(Bullet bullet) {

	if (isAlive) {

		if ((ball.rad + bullet.transform_.rad.x) * (ball.rad + bullet.transform_.rad.x) >=
			(bullet.transform_.pos.x - ball.pos.x) * (bullet.transform_.pos.x - ball.pos.x) + (bullet.transform_.pos.y - ball.pos.y) * (bullet.transform_.pos.y - ball.pos.y)
			) {
			isAlive = false;
		}

	}

}

void Enemy::Draw() {

	if (isAlive) {
		Novice::DrawEllipse(ball.pos.x, ball.pos.y * (-1) + 600,
			ball.rad, ball.rad, 0.0f, ball.color, kFillModeSolid
		);
	}

}
