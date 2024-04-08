#pragma once
#define SCORE_COUNT_NUMBER01	"data/02_Playimage/score2.png"
#define SCORE_COUNT_NUMBER10	"data/02_Playimage/score2.png"
#define SCORE_BACK				"data/02_Playimage/coinScore.png"

class Score
{
private:
	int s_img01[10];		//画像用変数
	int s_img10[10];

	int s_tensPlace;		//十の位
	int CountTensPlace;		//十の位用のカウント変数
	int s_oncePlace;		//一の位
	int CountOncePlace;		//一の位用のカウント変数
	int PosX, PosY;			//座標

	int s_back;				//スコアの下地

public:
	int score_count;
	bool s_coin_hit;
	void Init();
	void Load();
	void Step();
	void Draw();

};