#pragma once
#include "../Input/Input.h"
#include "../Sound/sound.h"
class SceneTitle
{
private:
	//”wŒi‰æ‘œ
	int BackGround;
	int ruru_IMG;
	int count;
public:

	SceneTitle();
	~SceneTitle();

	Sound sound;

	//‰Šú‰»
	void Init();

	//’Êíˆ—
	void Step();

	//•`‰æ
	void Draw();

	//I—¹ˆ—
	void Fin();
};