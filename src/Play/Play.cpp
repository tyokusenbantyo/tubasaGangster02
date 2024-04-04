#include "DxLib.h"
#include"../Cracter/Character.h"
#include"../Item/Coin/Coin.h"
#include"../Collision/Collision.h"

#include"../Timer/Timer.h"

#define PLAY_BACKGROUND_PATH "data/02_Playimage/backGraund.png"
#define PLAY_TUTA_PATH "data/02_Playimage/tuta_1.png"

int g_CurrentScenePlayID = ID_PLAY_REDITION;
Timer timer;  //制限時間

void Character_Hit_Coin()
{
	for (int i = 0; i < CHARACTER_MAX;i++)
	{

		for (int i = 0; i < COIN_MAX; i++)
		{
			if (IsHitRect(character[i].x, character[i].y, character[i].w, character[i].h, coin[i].x, coin[i].y, coin[i].w, coin[i].h))
			{
				DrawFormatString(100, 240, GetColor(255, 0, 0), "ヒット");

			}
		}
	}
}

//初期化
void Init()
{
	//変数の初期化
	for (int i = 0; i < 2; i++) {
		BackGround[i] = 0;		//背景画像の初期化
		Tuta[i] = 0;		//ツタ画像の初期化
		BG_PosY[i] = 0;		//画像移動用変数の初期化
	}

	//画像の読み込み
	//背景
	BackGround[0] = LoadGraph(PLAY_BACKGROUND_PATH);
	BackGround[1] = LoadGraph(PLAY_BACKGROUND_PATH);

	//ツタ
	Tuta[0] = LoadGraph(PLAY_TUTA_PATH);
	Tuta[1] = LoadGraph(PLAY_TUTA_PATH);

	//画像移動用変数の初期値設定
	BG_PosY[0] = 0;
	BG_PosY[1] = 720;

	//制限時間
	timer.Init();
	timer.Load();

	//通常処理へ移動
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
	//playの中の処理移動
	g_CurrentScenePlayID = ID_PLAY_REDITION;
}

//通常処理
//playerが遊ぶ
//ID_PLAY_REDITIONとID_PLAY_FINSHは演出
//★★★ID_PLAY_NOWの中に主な処理を書く★★★
void Step()
{
	switch (g_CurrentScenePlayID)
	{
	case ID_PLAY_REDITION:
		g_CurrentScenePlayID = ID_PLAY_NOW;

		break;

	case ID_PLAY_NOW:
		BG_PosY[0] -= 2;
		BG_PosY[1] -= 2;
		if (BG_PosY[0] <= -720) {
			BG_PosY[0] = 720;
		}
		if (BG_PosY[1] <= -720) {
			BG_PosY[1] = 720;
		}

		//制限時間
		timer.CountDown();

		if (timer.tensPlace == 0 && timer.oncePlace == 0) {
			g_CurrentScenePlayID = ID_PLAY_FINSH;
		}
		break;

	case ID_PLAY_FINSH:
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
		break;
	default:
		break;
	}
}

//描画処理
void Draw()
{
	//背景画像
	DrawGraph(0, BG_PosY[0], BackGround[0], true);
	DrawGraph(0, BG_PosY[1], BackGround[1], true);

	//ツタ
	DrawGraph(20, 0, Tuta[0], true);
	DrawGraph(1200, 0, Tuta[1], true);

	timer.Draw();

	//
	switch (g_CurrentScenePlayID)
	{
	case ID_PLAY_REDITION:

		break;

	case ID_PLAY_NOW:

		break;

	case ID_PLAY_FINSH:
		break;
	default:
		break;
	}


	//デバッグ用
	DrawFormatString(0, 0, GetColor(255, 0, 0), "上　%d", BG_PosY[0]);
	DrawFormatString(0, 20, GetColor(255, 0, 0), "下　%d", BG_PosY[1]);
}

//終了処理
//画面遷移や破棄処理を行う
void Fin()
{
	// プレイシーンに移動
	g_CurrentSceneID = SCENE_ID_INIT_RESULT;
}