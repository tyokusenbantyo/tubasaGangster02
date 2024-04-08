#include "DxLib.h"
#include "Score.h"

void Score::Init()
{
	for (int i = 0; i < 10; i++) {
		s_img01[i] = 0;		//�摜�p�ϐ�
		s_img10[i] = 0;
	}
	s_tensPlace = 0;		//�\�̈�
	CountTensPlace = 0;		//�\�̈ʗp�̃J�E���g�ϐ�
	s_oncePlace = 0;		//��̈�
	CountOncePlace = 0;		//��̈ʗp�̃J�E���g�ϐ�
	PosX = 1115;
	PosY = 25;			//���W
	score_count = 0;
	s_coin_hit = false;	//���Z�𔻒f

	s_back = 0;			//�X�R�A�̉��n
}

void Score::Load()
{
	LoadDivGraph(SCORE_COUNT_NUMBER10, 10, 10, 1, 68, 68, s_img10);//�\�̈ʒS��
	LoadDivGraph(SCORE_COUNT_NUMBER01, 10, 10, 1, 68, 68, s_img01);//��̈ʒS��

	s_back = LoadGraph(SCORE_BACK);
}

void Score::Step()
{
	if (s_coin_hit == true) {
		s_oncePlace++;
		s_coin_hit = false;
	}
	
	if (s_oncePlace == 9) {
		s_tensPlace++;
	}
	//����
	if (s_oncePlace == 9) {
		s_oncePlace = 0;
	}

	if (s_tensPlace == 9) {
		s_tensPlace = 0;
	}
}

void Score::Draw()
{
	//���n
	DrawGraph(1068, 28, s_back, true);

	if (s_tensPlace >= 1) {
		//�\�̈�
		DrawGraph(PosX, PosY, s_img10[s_tensPlace], true);
	}

	//��̈�
	DrawGraph(PosX + 45, PosY, s_img01[s_oncePlace], true);

	//�f�o�b�O�p
	//DrawFormatString(0, 0, GetColor(0, 0, 0), "�\�F%d", s_tensPlace);
	//DrawFormatString(40, 0, GetColor(0, 0, 0), "��F%d", s_oncePlace);
	//DrawFormatString(720, 0, GetColor(0, 0, 0), "�X�R�A%d", score_count);

}