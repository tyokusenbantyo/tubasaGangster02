#pragma once
#define COUNT_NUMBER01	"data/Timer/drak.png"
#define COUNT_NUMBER10	"data/Timer/drak.png"

class Timer
{
public:
	int flameCount;		//�t���[���̃J�E���g
	int print;			//�\���p�ϐ�

	int img01[10];		//�摜�̕ϐ��@�z��̒��g�͑��搔
	int img10[10];

	int tensPlace;		//�\�̈�
	int tensPlaceC;		//�\�̈ʗp�̃J�E���g�ϐ�
	int oncePlace;		//��̈�
	int oncePlaceC;		//��̈ʗp�̃J�E���g�ϐ�
	int timePosX,timePosY;			//���W

	int back;			//���n

	Timer();

	void Init();
	void Load();
	void CountDown();
	void Draw();

};