#include "Player.h"
#include <Novice.h>

/// コンストラクタ
Player::Player() {

	/// 初期化処理

	// 初期座標
	transform_.pos.x = 400;
	transform_.pos.y = 0;

	// 初期半径
	transform_.rad.x = 32;
	transform_.rad.y = 32;

	// 初期移動量
	speed_ = 8;

	// 発射する弾の種類を設定
	shotMode_ = 0;

	// 弾の初期化
	for (int i = 0; i < kBulletMax_; i++) {
		this->bullet_[i].Bullet::Bullet();
	}

}


/// デストラクタ
Player::~Player() {
}


/// 移動処理
void Player::Move(char* keys, char* preKeys) {

	/// プレイヤーをWASDキーで動かす

	// Wキー：上
	if (keys[DIK_W]) {
		transform_.pos.y += speed_;
	}

	// Sキー：下
	if (keys[DIK_S]) {
		transform_.pos.y -= speed_;
	}

	// Aキー：左
	if (keys[DIK_A]) {
		transform_.pos.x -= speed_;
	}

	// Dキー：右
	if (keys[DIK_D]) {
		transform_.pos.x += speed_;
	}


	/// 弾を変更
	if (keys[DIK_0] && !preKeys[DIK_0]) {
		this->shotMode_ = 0;
	}

	/// SPACEキーで弾を発射
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

		for (int i = 0; i < kBulletMax_; i++) {
			// 弾が発射されていないものを発射
			if (!bullet_[i].GetIsShot()) {

				// 弾を発射
				bullet_[i].Initialize(transform_);
			
				// 発射したらループを抜ける
				break;
			}

		}
	}

	// 弾の更新処理を行う
	for (int i = 0; i < kBulletMax_; i++) {

		if (this->shotMode_ == 0) {
			bullet_[i].Update(false);
		}

		/*if (this->shotMode_ == 1) {
			bullet_[i].Update(true);
		}*/
	}

}


/// 描画処理
void Player::Draw() {

	// プレイヤーの描画
	Novice::DrawEllipse(
		transform_.pos.x,
		(transform_.pos.y * (-1)) + 600,
		transform_.rad.x,
		transform_.rad.y,
		0.0f,
		0xAAAAAAFF,
		kFillModeSolid
	);

	// 発射されている場合、弾の描画を行う
	for (int i = 0; i < kBulletMax_; i++) {
		if (bullet_[i].GetIsShot()) {
			bullet_[i].Draw();
		}
	}

	// 操作説明
	Novice::ScreenPrintf(10, 10, "WASD:Move");
	Novice::ScreenPrintf(10, 30, "SPACE:shot");
	/*Novice::ScreenPrintf(10, 50, "0~1:ShotMode");
	Novice::ScreenPrintf(10, 70, "2~5:SetReflectMax");*/

	// パラメータの表示
	/*Novice::ScreenPrintf(1000, 10, "shotMode:%d", this->shotMode_);
	Novice::ScreenPrintf(1000, 30, "reflectMax:%d", bullet_->GetReflection());*/


}