#pragma once
#include "../Input/Input.h"
class SceneResult
{
private:
	//�w�i�摜
	int BackGround;

public:

	SceneResult();
	~SceneResult();

	//������
	void Init();

	//�ʏ폈��
	void Step();

	//�`��
	void Draw();

	//�I������
	void Fin();
};