#pragma once
#include "../Input/Input.h"
#include "../Sound/sound.h"
class SceneResult
{
private:
	//�w�i�摜
	int BackGround;

public:

	SceneResult();
	~SceneResult();
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