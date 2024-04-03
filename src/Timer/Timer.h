#pragma once
#define COUNT_NUMBER01	"data/Timer/01.png"
#define COUNT_NUMBER10	"data/Timer/01.png"

class Timer
{
public:
	int flameCount;		//フレームのカウント
	int print;			//表示用変数

	int img01[10];		//画像の変数　配列の中身は総画数
	int img10[10];
	int img100[10];

	int hundredsPlace;	//百の位
	int hundredsPlaceC;	//百の位用のカウント変数
	int tensPlace;		//十の位
	int tensPlaceC;		//十の位用のカウント変数
	int oncePlace;		//一の位
	int oncePlaceC;		//一の位用のカウント変数

	int _x,_y;			//座標

	bool time120;		//時間設定が120秒になった/百の位を表示する
public:
	Timer();

	//void startCt();	//始まる前のカウントダウン
	//void LoadSTCD();
	//void finSTCD();

	void Init();
	void Load();
	void CountDown();
	void Draw();


	////試しの関数
	//void Tamesi(int minute);
};