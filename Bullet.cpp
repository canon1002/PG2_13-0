#include "Bullet.h"
#include <Novice.h>

/// �R���X�g���N�^
Bullet::Bullet() {

	// �������ˉ񐔂�ݒ�
	reflectionIndex_ = 4;

	// �������������s��
	this->Initialize();

}


/// �f�X�g���N�^
Bullet::~Bullet() {

}


/// ����������
void Bullet::Initialize() {

	/// ����������

	// �������W
	transform_.pos.x = -1200;
	transform_.pos.y = -1200;

	// �������a
	transform_.rad.x = 16;
	transform_.rad.y = 16;

	// �����ړ���
	velX_ = 6;
	velY_ = 4;

	// ���ˉ񐔂�ݒ�
	reflection_ = reflectionIndex_;

	// ���˂���Ă��Ȃ���Ԃɂ���
	isShot_ = false;

}

/// ����������(���ˎ�)
void Bullet::Initialize(Transform player) {

	/// ����������

	// �������W
	transform_.pos.x = player.pos.x;
	transform_.pos.y = player.pos.y;

	// �������a
	transform_.rad.x = 16;
	transform_.rad.y = 16;

	// �����ړ���
	velX_ = 6;
	velY_ = 4;

	// ���ˉ񐔂�ݒ�
	reflection_ = reflectionIndex_;

	// ���˂���Ă����Ԃɂ���
	isShot_ = true;

}


/// �X�V����
void Bullet::Update(bool isReflection) {

	//���˂��Ȃ��p�^�[��
	if (!isReflection) {

		// ���˂���Ă��Ȃ���Γ������~
		if (isShot_ == false) {
		}

		// ���˂���Ă���Ƃ��̏���
		if (isShot_ == true) {

			// �e�̈ړ�
			transform_.pos.y += velY_;



			// ��ʊO�ɏo�����~
			if (transform_.pos.y >= 800) {
				isShot_ = false;
			}
		}
	}

}


/// �`�揈��
void Bullet::Draw() {

	// �e�̕`��
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


/// ���ˏ󋵂̎擾
bool Bullet::GetIsShot() {
	return this->isShot_;
}



/// �������炨�܂�


/// ���ˉ񐔂̐ݒ�
void Bullet::SetReflection(int num) {
	
	// ���ˉ񐔂�num�̒l�ɕύX
	reflectionIndex_ = num;

}


/// ���ˉ\�񐔂̎擾
int Bullet::GetReflection() {
	
	// ���ˉ\�񐔂�Ԃ�
	return reflectionIndex_;

}
