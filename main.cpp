#include <Novice.h>
#include<Player.h>
#include<Enemy.h>

const char kWindowTitle[] = "LC1A_30_ワタナベユウタ_タイトル";

int Enemy::id = 0;
bool Enemy::isAlive = true;

// Windowsアプリでのエントリーポイント(main関数)
int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int) {

	// ライブラリの初期化
	Novice::Initialize(kWindowTitle, 1280, 720);

	// キー入力結果を受け取る箱
	char keys[256] = {0};
	char preKeys[256] = {0};

	Player* player = new Player;
	Enemy* enemy1 = new Enemy;
	Enemy* enemy2 = new Enemy;

	// ウィンドウの×ボタンが押されるまでループ
	while (Novice::ProcessMessage() == 0) {
		// フレームの開始
		Novice::BeginFrame();

		// キー入力を受け取る
		memcpy(preKeys, keys, 256);
		Novice::GetHitKeyStateAll(keys);

		///
		/// ↓更新処理ここから
		///

		if (keys[DIK_R] && !preKeys[DIK_R]) {
			Enemy::isAlive = true;
		}

		player->Move(keys, preKeys);
		enemy1->Update();
		enemy2->Update();

		for (int i = 0; i < 60; i++) {
			enemy1->HitBox(player->bullet_[i]);
			enemy2->HitBox(player->bullet_[i]);
		}

		///
		/// ↑更新処理ここまで
		///

		///
		/// ↓描画処理ここから
		///

		player->Draw();
		enemy1->Draw();
		enemy2->Draw();

		///
		/// ↑描画処理ここまで
		///

		// フレームの終了
		Novice::EndFrame();

		// ESCキーが押されたらループを抜ける
		if (preKeys[DIK_ESCAPE] == 0 && keys[DIK_ESCAPE] != 0) {
			break;
		}
	}

	delete player;
	delete enemy1;
	delete enemy2;

	// ライブラリの終了
	Novice::Finalize();
	return 0;
}
