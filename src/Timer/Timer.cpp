#include "DxLib.h"
#include "Timer.h"


Timer::Timer()
{
	//�^�C�}�[�̍��W
	timePosX = 635; 
	timePosY = 10;

	flameCount = 0;		//�t���[���̃J�E���g
	tensPlace = 0;		//�\�̈�
	tensPlaceC = 0;		//�\�̈ʗp�̃J�E���g�ϐ�
	oncePlace = 0;		//��̈�
	oncePlaceC = 0;		//��̈ʗp�̃J�E���g�ϐ�
}

void Timer::Init()
{
	flameCount = 0;		//�t���[���̃J�E���g
	tensPlace = 0;		//�\�̈�
	tensPlaceC = 0;		//�\�̈ʗp�̃J�E���g�ϐ�
	oncePlace = 0;		//��̈�
	oncePlaceC = 0;		//��̈ʗp�̃J�E���g�ϐ�

	tensPlaceC = 7900;	//�c��100�t���[���������\�̈ʂ�3��2�ɂȂ�//�����ŕb����ύX������

	back = 0;			//���n
}

//�ǂݍ���
void Timer::Load()
{
	//LoadDivGraph(COUNT_NUMBER01, 10,10, 1, 100, 100, img100);//�S�̈ʒS��
	LoadDivGraph(COUNT_NUMBER01, 10,10, 1, 90, 90, img10);//�\�̈ʒS��
	LoadDivGraph(COUNT_NUMBER01, 10,10, 1, 90, 90, img01);//��̈ʒS��

	back = LoadGraph("data/02_Playimage/time.png");
}

//����
void Timer::CountDown()
{
	flameCount++;

	//�\�̈�
	tensPlaceC++;
	tensPlace = (tensPlaceC / 1000) % 1000;
	if (tensPlace > 9) {
		tensPlaceC = 0;
	}
	
	//��̈�
	oncePlaceC++;
	oncePlace = (oncePlaceC / 100) % 1000;
	if (oncePlace > 9) {
		oncePlaceC = 0;
	}
}

void Timer::Draw()
{	
	//���n
	DrawGraph(577, 8, back, true);

	//�\�̈�
	DrawGraph(timePosX, timePosY, img10[tensPlace], true);

	//��̈�
	DrawGraph(timePosX + 68 , timePosY, img01[oncePlace], true);

	//�f�o�b�O
	//DrawFormatString(0, 60, GetColor(255, 0, 0), "�W���m���炢%d", tensPlace);
	//DrawFormatString(0, 80, GetColor(255, 0, 0), "��̈�%d", oncePlace);
	//DrawFormatString(0, 100, GetColor(255, 0, 0), "??�̈�%d", tensPlaceC);
	//DrawFormatString(0, 120, GetColor(255, 0, 0), "?�̈�%d", oncePlaceC);

}

