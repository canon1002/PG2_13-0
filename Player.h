#pragma once
#include "Transform.h"
#include "Bullet.h"

/// <summary>
/// 
/// </summary>
/// <param name=""></param>
/// <returns></returns>

class Player
{
public: // メンバ関数

	/// <summary>
	/// コンストラクタ
	/// </summary>
	Player();
	
	/// <summary>
	/// デストラクタ
	/// </summary>
	~Player();
	
	void Update();

	/// <summary>
	/// 移動処理
	/// </summary>
	/// <param name="keys">キー入力状況</param>
	/// <param name="preKeys">1フレーム前のキー入力状況</param>
	void Move(char* keys,char* preKeys);

	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

public: // メンバ変数

	// Bulletクラスのポインタ変数
	Bullet bullet_[60];

private: // メンバ変数

	// 座標と半径
	Transform transform_;

	// 移動量
	int speed_;

	// 弾の数を設定 
	const int kBulletMax_ = 60;

	// 発射する弾の種類を保存
	int shotMode_;

};

