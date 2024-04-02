#pragma once

//�ݒ�t���[�����[�g�i60FPS�j
#define FRAME_RATE (60)

//1�t���[���̎��ԁi�~���b�j
#define FRAME_TIME (1000/FRAME_RATE)

void CalcFPS();
void DrawFPS();
void TimeFPS();

//�t���[�����[�g���
struct FrameRateInfo
{
	int currentTime;		//���݂̎���
	int lastFrameTime;		//�O��̃t���[�����s���̎���
	int count;				//�t���[���J�E���g�p
	int calcFpsTime;		//FPS���v�Z������
	float fps;				//�v������FPS�i�\���p�j
};

extern FrameRateInfo frameRateInfo;