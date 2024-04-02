#include "DxLib.h"
#include "Input.h"


//���݂̃t���[���L�[���
char Input::currentKeyBuf[KEY_BUF_LEN] = { 0 };

//�O�t���[���̃L�[���
char Input::preKeyBuf[KEY_BUF_LEN] = { 0 };



//���͐���@������
void Input::Init()
{
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		currentKeyBuf[index] = '\0';
		preKeyBuf[index] = '\0';
	}
}


//���͐���X�e�b�v
//����step��葁���Ă�	
void Input::Step()
{
	//�O�t���[���̃L�[���ϐ��ɋL�����Ă���
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		preKeyBuf[index] = currentKeyBuf[index];
	}
	//���݂̃L�[�����擾
	GetHitKeyStateAll(currentKeyBuf);
}
//�������ꂽ
 bool Input::IsKeyPush(int key_code)
{
	// �O�t���ŉ�����ĂȂ��@   ���@���t���ŉ�����Ă���
	if (preKeyBuf[key_code] == 0 && currentKeyBuf[key_code] == 1) {
		return true;
	}

	//������Ă��Ȃ��̂Ł@false 
	return false;
}

//�����������Ă��邩
bool Input::IsKeyKeep(int key_code) {

	// �O�t���ŉ�����Ă�@   ���@���t���ŉ�����Ă���
	if (preKeyBuf[key_code] == 1 && currentKeyBuf[key_code] == 1) {
		return true;
	}
	return false;
}


//�������������ꂽ��
bool Input:: IsKeyRelease(int key_code) {
	
	// �O�t���ŉ�����Ă�@   ���@���t���ŉ�����Ă��Ȃ�
	if (preKeyBuf[key_code] == 1 && currentKeyBuf[key_code] == 0) {
		return true;
	}

	//������Ă��Ȃ��̂Ł@false 
	return false;
}

//�P���ɉ�����Ă��邩
bool Input:: IsKeyDown(int key_code) {
	//���t���ŉ�����Ă���i�O�t���̏�Ԃ͊֌W�Ȃ��j
	if (currentKeyBuf[key_code] == 1)
		return true;

	return false;
}
