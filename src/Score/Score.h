#pragma once
#define SCORE_COUNT_NUMBER01	"data/02_Playimage/score2.png"
#define SCORE_COUNT_NUMBER10	"data/02_Playimage/score2.png"
#define SCORE_BACK				"data/02_Playimage/coinScore.png"

class Score
{
private:
	int s_img01[10];		//�摜�p�ϐ�
	int s_img10[10];

	int s_tensPlace;		//�\�̈�
	int CountTensPlace;		//�\�̈ʗp�̃J�E���g�ϐ�
	int s_oncePlace;		//��̈�
	int CountOncePlace;		//��̈ʗp�̃J�E���g�ϐ�
	int PosX, PosY;			//���W

	int s_back;				//�X�R�A�̉��n

public:
	int score_count;
	bool s_coin_hit;
	void Init();
	void Load();
	void Step();
	void Draw();

};