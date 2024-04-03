#include "DxLib.h"
#include "Timer.h"


Timer::Timer()
{
	_x = 555;
	_y = 10;
	flameCount = 0;		//�t���[���̃J�E���g
	print = 0;

	tensPlace = 0;		//�\�̈�
	tensPlaceC = 0;		//�\�̈ʗp�̃J�E���g�ϐ�
	oncePlace = 0;		//��̈�
	oncePlaceC = 0;		//��̈ʗp�̃J�E���g�ϐ�
}

void Timer::Init()
{
	flameCount = 0;		//�t���[���̃J�E���g
	print = 0;			//�\���p�ϐ�

	hundredsPlace = 0;
	hundredsPlaceC = 0;
	tensPlace = 0;		//�\�̈�
	tensPlaceC = 0;		//�\�̈ʗp�̃J�E���g�ϐ�
	oncePlace = 0;		//��̈�
	oncePlaceC = 0;		//��̈ʗp�̃J�E���g�ϐ�

	time120 = false;	//�S�̈ʂ�\�����邩�ۂ�

	tensPlaceC = 2900;	//�c��100�t���[���������\�̈ʂ�3��2�ɂȂ�
}

//�ǂݍ���
void Timer::Load()
{
	LoadDivGraph(COUNT_NUMBER01, 10,10, 1, 100, 100, img100);//�S�̈ʒS��
	LoadDivGraph(COUNT_NUMBER01, 10,10, 1, 100, 100, img10);//�\�̈ʒS��
	LoadDivGraph(COUNT_NUMBER01, 10,10, 1, 100, 100, img01);//��̈ʒS��
}



//����
void Timer::CountDown()
{
	flameCount++;
	print = 30 - (flameCount / 100) % 1000; //�����ŕb����ύX������

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

	if (print == 0) {
		//g_time = SW_TIMEFIN;//SCENEID_FIN_PLAY�ɍs��
	}
	
}

void Timer::Draw()
{	
	//(�f�o�b�O�p)
	//DrawFormatString(0, 200, GetColor(50, 0, 255), "�J�E���g�F%d", print, true);
	//DrawFormatString(400, 220, GetColor(50, 0, 255), "�t���[���F%d", flameCount, true);

	//DrawFormatString(400, 200, GetColor(50, 0, 255), "oncePlace�F%d", oncePlace, true);
	//DrawFormatString(400, 240, GetColor(50, 0, 255), "tensPlace�F%d", tensPlace, true);



	//�\�̈�
	DrawGraph(_x , _y, img10[tensPlace], true);

	//��̈�
	DrawGraph(_x + 70 , _y, img01[oncePlace], true);

}

