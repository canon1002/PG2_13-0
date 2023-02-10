#include "Bullet.h"
#include <Novice.h>

/// コンストラクタ
Bullet::Bullet() {

	// 初期反射回数を設定
	reflectionIndex_ = 4;

	// 初期化処理を行う
	this->Initialize();

}


/// デストラクタ
Bullet::~Bullet() {

}


/// 初期化処理
void Bullet::Initialize() {

	/// 初期化処理

	// 初期座標
	transform_.pos.x = -1200;
	transform_.pos.y = -1200;

	// 初期半径
	transform_.rad.x = 16;
	transform_.rad.y = 16;

	// 初期移動量
	velX_ = 6;
	velY_ = 4;

	// 反射回数を設定
	reflection_ = reflectionIndex_;

	// 発射されていない状態にする
	isShot_ = false;

}

/// 初期化処理(発射時)
void Bullet::Initialize(Transform player) {

	/// 初期化処理

	// 初期座標
	transform_.pos.x = player.pos.x;
	transform_.pos.y = player.pos.y;

	// 初期半径
	transform_.rad.x = 16;
	transform_.rad.y = 16;

	// 初期移動量
	velX_ = 6;
	velY_ = 4;

	// 反射回数を設定
	reflection_ = reflectionIndex_;

	// 発射されている状態にする
	isShot_ = true;

}


/// 更新処理
void Bullet::Update(bool isReflection) {

	//反射しないパターン
	if (!isReflection) {

		// 発射されていなければ動きを停止
		if (isShot_ == false) {
		}

		// 発射されているときの処理
		if (isShot_ == true) {

			// 弾の移動
			transform_.pos.y += velY_;



			// 画面外に出たら停止
			if (transform_.pos.y >= 800) {
				isShot_ = false;
			}
		}
	}

}


/// 描画処理
void Bullet::Draw() {

	// 弾の描画
	Novice::DrawEllipse(
		transform_.pos.x,
		(transform_.pos.y * (-1)) + 600,
		transform_.rad.x,
		transform_.rad.y,
		0.0f,
		0x33FFFFFF,
		kFillModeWireFrame
	);

}


/// 発射状況の取得
bool Bullet::GetIsShot() {
	return this->isShot_;
}



/// ここからおまけ


/// 反射回数の設定
void Bullet::SetReflection(int num) {
	
	// 反射回数をnumの値に変更
	reflectionIndex_ = num;

}


/// 反射可能回数の取得
int Bullet::GetReflection() {
	
	// 反射可能回数を返す
	return reflectionIndex_;

}
