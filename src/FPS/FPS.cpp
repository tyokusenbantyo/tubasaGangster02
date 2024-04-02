#include "DxLib.h"
#include "FPS.h"

//�t���[�����[�g���ϐ�
FrameRateInfo frameRateInfo = { 0 };


//FPS�v�Z
void CalcFPS()
{
	//�O���FPS���v�Z�������Ԃ���o�ߎ��Ԃ����߂�
	int difTime = frameRateInfo.currentTime - frameRateInfo.calcFpsTime;

	//�O���FPS���v�Z�����Ԃ���
	//�P�b�ȏ�o�߂��Ă�����FPS���v�Z����
	if (difTime > 1000)
	{
		//�t���[���񐔂��~���b�ɍ��킹��
		//�����܂ŏo�������̂�float�ɃL���X�g
		float frameCount = (float)(frameRateInfo.count * 1000.0f);

		//FPS�����߂�
		//���z�̐��l��60000/1000��60�@�ƂȂ�
		frameRateInfo.fps = frameCount / difTime;

		//�t���[�����[�g�J�E���g���N���A
		frameRateInfo.count = 0;

		//FPS���v�Z�������Ԃ��X�V
		frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
	}
}

//FPS�\���i�f�o�b�O�p�j
void DrawFPS()
{
	unsigned int color = GetColor(255, 30, 30);
	DrawFormatString(1180, 700, color, "FPS[%.2f]", frameRateInfo.fps);
}

void TimeFPS()
{
	Sleep(1);  //�V�X�e���񏈗���Ԃ�	

	//���݂̎��Ԃ��擾
	frameRateInfo.currentTime = GetNowCount();

	//�ŏ��̃��[�v�Ȃ�
	//���݂̎��Ԃ��AFPS�̌v�Z���������Ԃɐݒ�
	if (frameRateInfo.calcFpsTime == 0.0f)
	{
		frameRateInfo.calcFpsTime = frameRateInfo.currentTime;
		frameRateInfo.fps = (float)FRAME_RATE;
	}

	
}