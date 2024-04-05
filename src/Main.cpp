//ウィンドウを表示するプログラム（ひな形）

#include "DxLib.h"	//DXライブラリのインクルード
#include"Scene/Scene.h"

#include"../src/Cracter/Character.h"
#include"../src/Input/input.h"
#include"../src/Item/Coin/Coin.h"

#include"../src/Scene/Title.h"
#include"../src/Play/Play.h"
#include"../src/Scene/Play.h"
#include"../src/Scene/Result.h"
//#include"src/Character.h"
//#include"src/input.h"

//現在のシーンID
int g_CurrentSceneID = SCENE_ID_INIT_TITLE;  //一番初めはタイトルの初期化から始める

// Win32アプリケーションは WinMain関数 から始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(true);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1;
	}

	// 画面サイズを変更
	SetGraphMode( WINDOW_WIDTH, WINDOW_HEIGHT ,32);

	//描画するスクリーンを設定する
	SetDrawScreen(DX_SCREEN_BACK);
	
	//-----------------------------------------
	//一番最初に１回だけやる処理をここに書く
	
		//クラスの宣言
	SceneTitle title;
	//ScenePlay play;
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
				//タイトル初期化
				title.Init();
				//キー初期化
				InitInput();
			}
			break;

			case SCENE_ID_LOOP_TITLE:
			{
				
				title.Step();		//タイトル通常処理
				StepInput();		//キー処理
				
				title.Draw();		//タイトル描画処理
			}
			break;

			case SCENE_ID_FIN_TITLE:
			{
				//タイトル後処理
				title.Fin();
			}
			break;

			case SCENE_ID_INIT_PLAY:
			{
				InitInput();		//入力の初期化
				InitCharacter();	//キャラクターの初期化
				InitCoin();			//コインの初期化

				PlayInit();			//初期化
				

				g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
			}
			break;
			case SCENE_ID_LOOP_PLAY:
			{
				StepInput();			//キーの記憶
				StepCharacter();		//キャラクターの移動
				StepCharacterGravity(); //キャラクターの重力
				Character_Hit_Coin();
				StepCharacterDraw();	//キャラクターの描画
				DrawCoin();

				PlayStep();				//遊でいる処理

			}
			case SCENE_ID_FIN_PLAY:
			{
				PlayFin();				//終了処理
			}
			break;

			break;
			case SCENE_ID_INIT_RESULT:
			{
				//クリア初期化
				result.Init();
				//キー初期化
				InitInput();
			}
			break;

			case SCENE_ID_LOOP_RESULT:
			{
				//クリア通常処理
				result.Step();
				StepInput();		//キー処理

				//クリア描画処理
				result.Draw();
			}
			break;

			case SCENE_ID_FIN_RESULT:
			{
				//クリア後処理
				result.Fin();
			}
			break;

		}


		//-----------------------------------------
		//ループの終わりに
		//フリップ関数
		ScreenFlip();

	}

	//-----------------------------------------
	//最後に１回だけやる処理をここに書く


	//-----------------------------------------
	//DXライブラリの後処理
	DxLib_End();

	return 0;
}

