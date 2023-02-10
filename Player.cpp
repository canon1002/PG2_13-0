#include "Player.h"
#include <Novice.h>

/// �R���X�g���N�^
Player::Player() {

	/// ����������

	// �������W
	transform_.pos.x = 400;
	transform_.pos.y = 0;

	// �������a
	transform_.rad.x = 32;
	transform_.rad.y = 32;

	// �����ړ���
	speed_ = 8;

	// ���˂���e�̎�ނ�ݒ�
	shotMode_ = 0;

	// �e�̏�����
	for (int i = 0; i < kBulletMax_; i++) {
		this->bullet_[i].Bullet::Bullet();
	}

}


/// �f�X�g���N�^
Player::~Player() {
}


/// �ړ�����
void Player::Move(char* keys, char* preKeys) {

	/// �v���C���[��WASD�L�[�œ�����

	// W�L�[�F��
	if (keys[DIK_W]) {
		transform_.pos.y += speed_;
	}

	// S�L�[�F��
	if (keys[DIK_S]) {
		transform_.pos.y -= speed_;
	}

	// A�L�[�F��
	if (keys[DIK_A]) {
		transform_.pos.x -= speed_;
	}

	// D�L�[�F�E
	if (keys[DIK_D]) {
		transform_.pos.x += speed_;
	}


	/// �e��ύX
	if (keys[DIK_0] && !preKeys[DIK_0]) {
		this->shotMode_ = 0;
	}

	/// SPACE�L�[�Œe�𔭎�
	if (keys[DIK_SPACE] && !preKeys[DIK_SPACE]) {

		for (int i = 0; i < kBulletMax_; i++) {
			// �e�����˂���Ă��Ȃ����̂𔭎�
			if (!bullet_[i].GetIsShot()) {

				// �e�𔭎�
				bullet_[i].Initialize(transform_);
			
				// ���˂����烋�[�v�𔲂���
				break;
			}

		}
	}

	// �e�̍X�V�������s��
	for (int i = 0; i < kBulletMax_; i++) {

		if (this->shotMode_ == 0) {
			bullet_[i].Update(false);
		}

		/*if (this->shotMode_ == 1) {
			bullet_[i].Update(true);
		}*/
	}

}


/// �`�揈��
void Player::Draw() {

	// �v���C���[�̕`��
	Novice::DrawEllipse(
		transform_.pos.x,
		(transform_.pos.y * (-1)) + 600,
		transform_.rad.x,
		transform_.rad.y,
		0.0f,
		0xAAAAAAFF,
		kFillModeSolid
	);

	// ���˂���Ă���ꍇ�A�e�̕`����s��
	for (int i = 0; i < kBulletMax_; i++) {
		if (bullet_[i].GetIsShot()) {
			bullet_[i].Draw();
		}
	}

	// �������
	Novice::ScreenPrintf(10, 10, "WASD:Move");
	Novice::ScreenPrintf(10, 30, "SPACE:shot");
	/*Novice::ScreenPrintf(10, 50, "0~1:ShotMode");
	Novice::ScreenPrintf(10, 70, "2~5:SetReflectMax");*/

	// �p�����[�^�̕\��
	/*Novice::ScreenPrintf(1000, 10, "shotMode:%d", this->shotMode_);
	Novice::ScreenPrintf(1000, 30, "reflectMax:%d", bullet_->GetReflection());*/


}