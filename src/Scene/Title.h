#pragma once
#include "../Input/Input.h"
#include "../Sound/sound.h"
class SceneTitle
{
private:
	//�w�i�摜
	int BackGround;
	int ruru_IMG;
	int count;
public:

	SceneTitle();
	~SceneTitle();

	Sound sound;

	//������
	void Init();

	//�ʏ폈��
	void Step();

	//�`��
	void Draw();

	//�I������
	void Fin();
};