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
public: // �����o�֐�

	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Player();
	
	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Player();
	
	void Update();

	/// <summary>
	/// �ړ�����
	/// </summary>
	/// <param name="keys">�L�[���͏�</param>
	/// <param name="preKeys">1�t���[���O�̃L�[���͏�</param>
	void Move(char* keys,char* preKeys);

	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

public: // �����o�ϐ�

	// Bullet�N���X�̃|�C���^�ϐ�
	Bullet bullet_[60];

private: // �����o�ϐ�

	// ���W�Ɣ��a
	Transform transform_;

	// �ړ���
	int speed_;

	// �e�̐���ݒ� 
	const int kBulletMax_ = 60;

	// ���˂���e�̎�ނ�ۑ�
	int shotMode_;

};

