#pragma once
#define COUNT_NUMBER01	"data/Timer/drak.png"
#define COUNT_NUMBER10	"data/Timer/drak.png"

class Timer
{
public:
	int flameCount;		//フレームのカウント
	int print;			//表示用変数

	int img01[10];		//画像の変数　配列の中身は総画数
	int img10[10];

	int tensPlace;		//十の位
	int tensPlaceC;		//十の位用のカウント変数
	int oncePlace;		//一の位
	int oncePlaceC;		//一の位用のカウント変数
	int timePosX,timePosY;			//座標

	int back;			//下地

	Timer();

	void Init();
	void Load();
	void CountDown();
	void Draw();

};