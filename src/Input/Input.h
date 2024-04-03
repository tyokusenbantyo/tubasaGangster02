#pragma once
#define KEY_BUF_LEN (256)

class Input {
private:

	//���݂̃t���[���L�[���
	static char currentKeyBuf[KEY_BUF_LEN];

	//�O�t���[���̃L�[���
	static char preKeyBuf[KEY_BUF_LEN];

public:
	//���͐���@������
	static void Init();

	//���͐���X�e�b�v
	//����step��葁���Ă�
	static void Step();

	//�������ꂽ
	static bool IsKeyPush(int key_code);

	//�����������Ă��邩
	static bool IsKeyKeep(int key_code);

	//�������������ꂽ��
	static bool IsKeyRelease(int key_code);

	//�P���ɉ�����Ă��邩
	static bool IsKeyDown(int key_code);

};
