//ウィンドウを表示するプログラム（ひな形）

#include "DxLib.h"	//DXライブラリのインクルード
#include"Scene/Scene.h"
#include"../src/parasol/parasol.h"
#include"../src/Cracter/Character.h"
#include"../src/Input_struct/input.h"
#include"../src/Item/Coin/Coin.h"
#include"Scene/Title.h"
#include"../src/Play/Play.h"
#include"Scene/Play.h"
#include"Scene/Result.h"
#include"../src/Item/hammer/hammer.h"
//#include"src/Character.h"
//#include"src/input.h"

int g_CurrentSceneID = SCENE_ID_INIT_TITLE;
// Win32アプリケーションは WinMain関数 から始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(true);

	// 画面サイズを変更
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT ,32);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	//描画するスクリーンを設定する
	SetDrawScreen(DX_SCREEN_BACK);
	
	//-----------------------------------------
	
	//クラスの呼び出し
	SceneTitle title;
	ScenePlay play;
	SceneResult result;

	//-----------------------------------------

	//ゲームメインループ
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			//エスケープキーが押されたら終了
			break;
		}

		//画面に表示されたものを初期化
		ClearDrawScreen();
		
		switch (g_CurrentSceneID)
		{

		case SCENE_ID_INIT_TITLE:
		{
			title.Init();
		}
		break;

		case SCENE_ID_LOOP_TITLE:
		{
			title.Step();
			title.Draw();
		}
		break;

		case SCENE_ID_FIN_TITLE:
		{
			title.Fin();
		}
		break;

		case SCENE_ID_INIT_PLAY:
		{
			InitInput();		//入力の初期化
			InitHummer();
			InitCharacter();	//キャラクターの初期化
			InitCoin();			//コインの初期化
			Initparasol();		//パラソルの初期化

			play.Init();
			g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
		}
		break;

		case SCENE_ID_LOOP_PLAY:
		{
			play.Step();
			StepInput();				//キーの記憶
			StepCharacter();			//キャラクターの移動
			StepCharacterGravity();		//キャラクターの重力
			//Stepparasol();			//キャラとパラソルの位置を固定している
			CoinBullet();				//コインの発射処理
			Coininterval();				//コインの発射感覚
			coinMove();
			CoinGravity();
			HummerGravity();	//コインの重力
			HummerMove();	//コインの移動処理
			HummerBullet();	//コインの発射処理
			Hummerinterval();//コインの発射感覚
			Character_Hit_Coin();		//キャラクターとコインの当たり判定
			Character_Hit_Hummer();
			//描画
			play.Draw();				//背景の描画
			DrawHummer();	//コインの描画
			StepCharacterDraw();		//キャラクターの描画
			DrawCoin();					//コインの描画
			//Drawparasol();				//パラソルの描画

		}
		break;

		case SCENE_ID_FIN_PLAY:
		{
			play.Fin();
		}
		break;

		case SCENE_ID_INIT_RESULT:
		{
			result.Init();
		}
		break;

		case SCENE_ID_LOOP_RESULT:
		{
			result.Step();
			result.Draw();

		}
		break;

		case SCENE_ID_FIN_RESULT:
		{
			result.Fin();
		}
		break;

		}
		//-----------------------------------------
		//フリップ関数
		ScreenFlip();
	}

	//-----------------------------------------
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}

