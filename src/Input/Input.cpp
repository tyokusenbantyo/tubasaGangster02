#include"DxLib.h"
#include"input.h"

#define KEY_BUF_LEN	(256)

//���݂̃t���[���L�[���
char currntkeyBuf[KEY_BUF_LEN] = { 0 };
//�O�̃t���[���̃L�[���
char preKeyBuf[KEY_BUF_LEN] = { 0 };
//���͐��䏉����
void InitInput()
{
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		currntkeyBuf[index] = '\0';
		preKeyBuf[index] = '\0';
	}
}

void StepInput()
{
	//�O�̃t���[���L�[���ϐ��ɋL�^���Ă���
	for (int index = 0; index < KEY_BUF_LEN; index++)
	{
		preKeyBuf[index] = currntkeyBuf[index];
	}
	//���݂̃L�[�����擾
	GetHitKeyStateAll(currntkeyBuf);
}

bool IsKyePush(int key_code)
{
	//�O�t���ŉ�����ĂȂ��@���@���U��ŉ�����Ă���
	if (preKeyBuf[key_code] == 0 && currntkeyBuf[key_code] == 1)
	{
		return true;	}

	return false;
}

bool IsKeykeep(int key_code)											//����������
{
	if (preKeyBuf[key_code] == 1 && currntkeyBuf[key_code] == 1)
	{
		return true;
	}
	return false;
}
bool IsKeyRelease(int key_code)
{
	if (preKeyBuf[key_code] == 1 && currntkeyBuf[key_code] == 0)
	{
		return true;
	}
	return false;
}
bool IsKeyDown(int key_code)
{
	if (currntkeyBuf[key_code] == 1)
	{
		return true;
	}
	return false;
}