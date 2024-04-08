#pragma once
#include "../Timer/Timer.h"
#include "../Sound/sound.h"
#include "../Score/Score.h"
class ScenePlay
{
private:
	//�w�i�摜
	int BackGround[2];
	int Tuta[2];
	int BG_PosY[2];//�w�i�摜�̈ړ��p�ϐ�
	int Tuta_PosY[2];//���摜�̈ړ��p�ϐ�

	int score_count;
	
	//����
	int decretion[2];
	int dec_posY[2];
	int dec_posX[2];
	int alphaNum;
public:
	ScenePlay();
	~ScenePlay();
	Timer timer;
	Sound sound;
	Score score;

	//������
	void Init();

	//�ʏ폈��
	void Step();

	//�`��
	void Draw();

	//�I������
	void Fin();
	void Character_Hit_Coin();
	void Character_Hit_Hummer();
};

