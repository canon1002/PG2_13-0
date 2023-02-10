#pragma once
#include "Transform.h"

class Bullet
{
public: // メンバ関数


	/// <summary>
	/// コンストラクタ
	/// </summary>
	Bullet();


	/// <summary>
	/// デストラクタ
	/// </summary>
	~Bullet();

	/// <summary>
	/// 初期化処理
	/// </summary>
	void Initialize();

	/// <summary>
	/// 初期化処理(発射時)
	/// </summary>
	/// <param name="player">プレイヤーの座標</param>
	void Initialize(Transform player);


	/// <summary>
	/// 更新処理
	/// </summary>
	/// <param name="isReflection">反射するか</param>
	/// <param name="isReflection"></param>
	void Update(bool isReflection);


	/// <summary>
	/// 描画処理
	/// </summary>
	void Draw();

	/// <summary>
	/// 発射状況の取得
	/// </summary>
	/// <returns>true->発射している // false->発射していない</returns>
	bool GetIsShot();


	/// ここからおまけ


	/// <summary>
	/// 反射回数の設定
	/// </summary>
	/// <param name="num">反射させる回数</param>
	void SetReflection(int num);


	/// <summary>
	/// 反射回数の取得
	/// </summary>
	/// <returns>反射できる回数</returns>
	int GetReflection();

public: // メンバ変数
		 
	// 座標と半径
	Transform transform_;

private:

	// 移動量
	int velX_;
	int velY_;

	// 弾が発射されているか
	bool isShot_;


	/// ここからおまけ


	// 反射回数の保存
	int reflection_;
	int reflectionIndex_;

};

