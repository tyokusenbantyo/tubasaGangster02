#pragma once
#define COUNT_NUMBER01	"data/Timer/01.png"
#define COUNT_NUMBER10	"data/Timer/01.png"

class Timer
{
public:
	int flameCount;		//�t���[���̃J�E���g
	int print;			//�\���p�ϐ�

	int img01[10];		//�摜�̕ϐ��@�z��̒��g�͑��搔
	int img10[10];
	int img100[10];

	int hundredsPlace;	//�S�̈�
	int hundredsPlaceC;	//�S�̈ʗp�̃J�E���g�ϐ�
	int tensPlace;		//�\�̈�
	int tensPlaceC;		//�\�̈ʗp�̃J�E���g�ϐ�
	int oncePlace;		//��̈�
	int oncePlaceC;		//��̈ʗp�̃J�E���g�ϐ�

	int _x,_y;			//���W

	bool time120;		//���Ԑݒ肪120�b�ɂȂ���/�S�̈ʂ�\������
public:
	Timer();

	//void startCt();	//�n�܂�O�̃J�E���g�_�E��
	//void LoadSTCD();
	//void finSTCD();

	void Init();
	void Load();
	void CountDown();
	void Draw();


	////�����̊֐�
	//void Tamesi(int minute);
};