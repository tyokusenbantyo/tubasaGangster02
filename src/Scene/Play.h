#pragma once
#include "../Timer/Timer.h"
class ScenePlay
{
private:
	//�w�i�摜
	int BackGround[2];
	int Tuta[2];
	int BG_PosY[2];//�w�i�摜�̈ړ��p�ϐ�

	Timer timer;

public:

	ScenePlay();
	~ScenePlay();

	//������
	void Init();

	//�ʏ폈��
	void Step();

	//�`��
	void Draw();

	//�I������
	void Fin();
};
