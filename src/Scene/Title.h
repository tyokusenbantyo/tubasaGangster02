#pragma once
#include "../Input/Input.h"
class SceneTitle
{
private:
	//�w�i�摜
	int BackGround;

public:

	SceneTitle();
	~SceneTitle();

	//������
	void Init();

	//�ʏ폈��
	void Step();

	//�`��
	void Draw();

	//�I������
	void Fin();
};