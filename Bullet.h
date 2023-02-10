#pragma once
#include "Transform.h"

class Bullet
{
public: // �����o�֐�


	/// <summary>
	/// �R���X�g���N�^
	/// </summary>
	Bullet();


	/// <summary>
	/// �f�X�g���N�^
	/// </summary>
	~Bullet();

	/// <summary>
	/// ����������
	/// </summary>
	void Initialize();

	/// <summary>
	/// ����������(���ˎ�)
	/// </summary>
	/// <param name="player">�v���C���[�̍��W</param>
	void Initialize(Transform player);


	/// <summary>
	/// �X�V����
	/// </summary>
	/// <param name="isReflection">���˂��邩</param>
	/// <param name="isReflection"></param>
	void Update(bool isReflection);


	/// <summary>
	/// �`�揈��
	/// </summary>
	void Draw();

	/// <summary>
	/// ���ˏ󋵂̎擾
	/// </summary>
	/// <returns>true->���˂��Ă��� // false->���˂��Ă��Ȃ�</returns>
	bool GetIsShot();


	/// �������炨�܂�


	/// <summary>
	/// ���ˉ񐔂̐ݒ�
	/// </summary>
	/// <param name="num">���˂������</param>
	void SetReflection(int num);


	/// <summary>
	/// ���ˉ񐔂̎擾
	/// </summary>
	/// <returns>���˂ł����</returns>
	int GetReflection();

public: // �����o�ϐ�
		 
	// ���W�Ɣ��a
	Transform transform_;

private:

	// �ړ���
	int velX_;
	int velY_;

	// �e�����˂���Ă��邩
	bool isShot_;


	/// �������炨�܂�


	// ���ˉ񐔂̕ۑ�
	int reflection_;
	int reflectionIndex_;

};

