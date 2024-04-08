#include "DxLib.h"
#include "Score.h"

void Score::Init()
{
	for (int i = 0; i < 10; i++) {
		s_img01[i] = 0;		//画像用変数
		s_img10[i] = 0;
	}
	s_tensPlace = 0;		//十の位
	CountTensPlace = 0;		//十の位用のカウント変数
	s_oncePlace = 0;		//一の位
	CountOncePlace = 0;		//一の位用のカウント変数
	PosX = 1115;
	PosY = 25;			//座標
	score_count = 0;
	s_coin_hit = false;	//加算を判断

	s_back = 0;			//スコアの下地
}

void Score::Load()
{
	LoadDivGraph(SCORE_COUNT_NUMBER10, 10, 10, 1, 68, 68, s_img10);//十の位担当
	LoadDivGraph(SCORE_COUNT_NUMBER01, 10, 10, 1, 68, 68, s_img01);//一の位担当

	s_back = LoadGraph(SCORE_BACK);
}

void Score::Step()
{
	if (s_coin_hit == true) {
		s_oncePlace++;
		s_coin_hit = false;
	}
	
	if (s_oncePlace == 9) {
		s_tensPlace++;
	}
	//制御
	if (s_oncePlace == 9) {
		s_oncePlace = 0;
	}

	if (s_tensPlace == 9) {
		s_tensPlace = 0;
	}
}

void Score::Draw()
{
	//下地
	DrawGraph(1068, 28, s_back, true);

	if (s_tensPlace >= 1) {
		//十の位
		DrawGraph(PosX, PosY, s_img10[s_tensPlace], true);
	}

	//一の位
	DrawGraph(PosX + 45, PosY, s_img01[s_oncePlace], true);

	//デバッグ用
	//DrawFormatString(0, 0, GetColor(0, 0, 0), "十：%d", s_tensPlace);
	//DrawFormatString(40, 0, GetColor(0, 0, 0), "一：%d", s_oncePlace);
	//DrawFormatString(720, 0, GetColor(0, 0, 0), "スコア%d", score_count);

}