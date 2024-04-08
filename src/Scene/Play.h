#pragma once
#include "../Timer/Timer.h"
#include "../Sound/sound.h"
#include "../Score/Score.h"
class ScenePlay
{
private:
	//”wŒi‰æ‘œ
	int BackGround[2];
	int Tuta[2];
	int BG_PosY[2];//”wŒi‰æ‘œ‚ÌˆÚ“®—p•Ï”
	int Tuta_PosY[2];//‚Â‚½‰æ‘œ‚ÌˆÚ“®—p•Ï”

	int score_count;
	
	//‘•ü
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

	//‰Šú‰»
	void Init();

	//’Êíˆ—
	void Step();

	//•`‰æ
	void Draw();

	//I—¹ˆ—
	void Fin();
	void Character_Hit_Coin();
	void Character_Hit_Hummer();
};

