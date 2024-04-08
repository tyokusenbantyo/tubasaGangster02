#include "DxLib.h"
#include "Scene.h"
//#include "Play.h"
#include"Play.h"
#include"../Item/hammer/hammer.h"

#include "../Cracter/Character.h"
#include "../Item/Coin/Coin.h"
#include "../Collision/Collision.h"


#define PLAY_BACKGROUND_PATH "data/02_Playimage/Background.png"
#define PLAY_TUTA_PATH "data/02_Playimage/tuta_1.png"

int g_CurrentScenePlayID = ID_PLAY_REDITION;

ScenePlay::ScenePlay()
{
	for (int i = 0; i < 2; i++) {
		BackGround[i] = 0;		//背景画像の初期化
		Tuta[i] = 0;			//ツタ画像の初期化
		BG_PosY[i] = 0;			//画像移動用変数の初期化
		Tuta_PosY[i] = 0;			//画像移動用変数の初期化
	}
}

ScenePlay::~ScenePlay() {}

//タイトルの初期化
void ScenePlay::Init()
{
	//画像の読み込み
	//背景
	BackGround[0] = LoadGraph(PLAY_BACKGROUND_PATH);
	BackGround[1] = LoadGraph(PLAY_BACKGROUND_PATH);

	//ツタ
	Tuta[0] = LoadGraph(PLAY_TUTA_PATH);
	Tuta[1] = LoadGraph(PLAY_TUTA_PATH);

	//画像移動用変数の初期値
	BG_PosY[0] = 0;
	BG_PosY[1] = 720;
	Tuta_PosY[0] = 0;
	Tuta_PosY[1] = 720;

	//BGM
	sound.bgm[BGM_PLAY] = LoadSoundMem("data/Sound/play.mp3");
	PlaySoundMem(sound.bgm[BGM_PLAY], DX_PLAYTYPE_LOOP, true);

	//SE
	sound.InitPlay();

	//制限時間
	timer.Init();
	timer.Load();

	//スコア初期化
	score.Init();
	score.Load();

	//装飾
	decretion[0] = LoadGraph("data/02_Playimage/start.png");
	dec_posX[0] = 280;
	dec_posY[0] = 0;

	decretion[1] = LoadGraph("data/02_Playimage/finish.png");
	dec_posX[1] = 240;
	dec_posY[1] = 0;

	alphaNum = 255;

	//通常処理へ移動
	g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
	//playの中の処理移動
	g_CurrentScenePlayID = ID_PLAY_REDITION;
}

// タイトル通常処理
void ScenePlay::Step()
{
	switch (g_CurrentScenePlayID)
	{
	case ID_PLAY_REDITION:
		//降りてくる
		if (dec_posY[0] < 259) {
			dec_posY[0]+=5;
		}
		else {
			dec_posY[0] = 260;
			alphaNum -= 2;
		}

		//画面遷移
		if (alphaNum <= 0) {
			alphaNum = 0;
			g_CurrentScenePlayID = ID_PLAY_NOW;
		}
		//g_CurrentScenePlayID = ID_PLAY_NOW;
		break;

	case ID_PLAY_NOW:
		BG_PosY[0] -= 1;
		BG_PosY[1] -= 1;
		if (BG_PosY[0] <= -720) {
			BG_PosY[0] = 720;
		}
		if (BG_PosY[1] <= -720) {
			BG_PosY[1] = 720;
		}

		Tuta_PosY[0] -= 3;
		Tuta_PosY[1] -= 3;
		if (Tuta_PosY[0] <= -720) {
			Tuta_PosY[0] = 720;
		}
		if (Tuta_PosY[1] <= -720) {
			Tuta_PosY[1] = 720;
		}
		//スコア
		score.Step();

		//制限時間
		timer.CountDown();
		if (timer.tensPlace == 0 && timer.oncePlace == 0) {
			g_CurrentScenePlayID = ID_PLAY_FINSH;
			alphaNum = 255;
		}
		break;
	case ID_PLAY_FINSH:
		//降りてくる
		if (dec_posY[1] < 259) {
			dec_posY[1] += 5;
		}
		else {
			dec_posY[1] = 260;
			alphaNum -= 2;
		}

		//画面遷移
		if (alphaNum <= 0) {
			alphaNum = 0;
			g_CurrentSceneID = SCENE_ID_FIN_PLAY;

		}
		break;
	default:
		break;
	}
	
}

// タイトル描画処理
void ScenePlay::Draw()
{	
	//背景画像
	DrawGraph(0, BG_PosY[0], BackGround[0], true);
	DrawGraph(0, BG_PosY[1], BackGround[1], true);

	//ツタ	
	DrawGraph(0, Tuta_PosY[0], Tuta[0], true);
	DrawGraph(0, Tuta_PosY[1], Tuta[1], true);

	timer.Draw();
	score.Draw();

	switch (g_CurrentScenePlayID)
	{
	case ID_PLAY_REDITION:
		if (dec_posY[0] < 259) {
			DrawGraph(dec_posX[0], dec_posY[0], decretion[0], true);
		}
		else if (dec_posY[0] >= 260) {
			//薄くなる
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, alphaNum);
			DrawGraph(dec_posX[0], dec_posY[0], decretion[0], true);

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			alphaNum -= 2;
			if (alphaNum == 0) {
				alphaNum = 0;
			}
		}

		break;

	case ID_PLAY_NOW:
		
		break;

	case ID_PLAY_FINSH:
		if (dec_posY[1] < 259) {
			DrawGraph(dec_posX[1], dec_posY[1], decretion[1], true);
		}
		else if (dec_posY[1] >= 260) {
			//薄くなる
			SetDrawBlendMode(DX_BLENDMODE_ALPHA, alphaNum);
			DrawGraph(dec_posX[1], dec_posY[1], decretion[1], true);

			SetDrawBlendMode(DX_BLENDMODE_NOBLEND, 0);
			alphaNum -= 2;
			if (alphaNum == 0) {
				alphaNum = 0;
			}
		}

		break;
	default:
		break;
	}

	//デバッグ用
	//DrawFormatString(0, 0, GetColor(255, 0, 0), "上　%d", BG_PosY[0]);
	//DrawFormatString(0, 20, GetColor(255, 0, 0), "下　%d", BG_PosY[1]);

	//DrawFormatString(0, 140, GetColor(60, 60, 50), "十%d", timer.tensPlace);
	//DrawFormatString(30, 140, GetColor(60, 60, 50), "一%d", timer.oncePlace);
	//DrawFormatString(30, 140, GetColor(60, 60, 50), "%d", alphaNum);
}

// タイトル終了処理
void ScenePlay::Fin()
{
	//BGMの削除
	StopSoundMem(sound.bgm[BGM_PLAY]);
	DeleteSoundMem(sound.bgm[BGM_PLAY]);
	//SEの削除
	for (int i = 0; i < ALL_SOUND; i++) {
		StopSoundMem(sound.se[i]);
		DeleteSoundMem(sound.se[i]);
	}
	//画像の削除
	DeleteGraph(decretion[0]);

	// プレイシーンに移動
	g_CurrentSceneID = SCENE_ID_INIT_RESULT;
}

void ScenePlay::Character_Hit_Coin()
{
	for (int c = 0; c < COIN_MAX; c++)
	{
		if (coin[c].IsUse == false)
			continue;
		for (int i = 0; i < CHARACTER_PARASOL_MAX; i++)
		{
	   		if (IsHitRect(character[i].x, character[i].y, character[i].w, character[i].h, coin[c].x, coin[c].y, coin[c].w, coin[c].h))
			{
				//DrawFormatString(100, 240, GetColor(255, 0, 0), "コインヒット");
				PlaySoundMem(sound.se[SE_HIT_COIN], DX_PLAYTYPE_BACK, true);
				
				//スコア用
				score.score_count++;
				score.s_coin_hit = true;

 				coin[c].IsUse = false;
				if (coin[c].IsUse == false)
				{
					if (c == 0)
					{
						coin[c].x = 1100;
						coin[c].y = 20;
					}
					if (c == 1)
					{
						coin[c].x = 1100;
						coin[c].y = 200;
					}
					if (c == 2)
					{
						coin[c].x = 1100;
						coin[c].y = 250;
					}
					if (c == 3)
					{
						coin[c].x = 1100;
						coin[c].y = 200;
					}
					if (c == 4)
					{
						coin[c].x = 100;
						coin[c].y = 0;
					}
					if (c == 5)
					{
						coin[c].x = 100;
						coin[c].y = 200;
					}
					if (c == 6)
					{
						coin[c].x = 100;
						coin[c].y = 200;
					}
					if (c == 7)
					{
						coin[c].x = 100;
						coin[c].y = 20;
					}

				}
			}
		}
	}
}
void ScenePlay::Character_Hit_Hummer()
{
	for (int h = 0; h < HUMMER_MAX; h++)
	{
		for (int i = 0; i < CHARACTER_PARASOL_MAX; i++)
		{
			if (IsHitRect(character[i].x, character[i].y, character[i].w, character[i].h, hummer[h].x, hummer[h].y, hummer[h].w, hummer[h].h))
			{
				//DrawFormatString(100, 240, GetColor(255, 0, 0), "ハンマーヒット");
				hummer[h].IsUse = false;
				if (h == 0 || h == 1)
				{
					hummer[h].x = 1100;
				}
				if (h == 2 || h == 3)
				{
					hummer[h].x = 100;
				}

				hummer[h].IsUse = false;
				hummer[h].y = 400;
				hummer[h].GravitySpeed = 0;
				hummer[h].oneJunp = true;
				hummer[h].otosu = true;
			}
			
			if (hummer[h].otosu == true)
			{
				hummer[h].otosuFramecount++;
				if (hummer[h].otosuFramecount == 25)
				{
					hummer[h].otosuFramecount = 0;
					hummer[h].otosu = false;
				}
				
			}
		}
	}
}