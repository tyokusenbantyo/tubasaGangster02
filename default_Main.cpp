#include "DxLib.h"	//DXライブラリのインクルード
#include "src/Scene/Scene.h"
#include "src/Scene/Title.h"
#include "src/Scene/Play.h"
#include "src/Scene/Result.h"

// define
#define	SCREEN_SIZE_X	1280	// X方向の画面サイズを指定
#define	SCREEN_SIZE_Y	720	// Y方向の画面サイズを指定

//現在のシーンID
int g_CurrentSceneID = SCENE_ID_INIT_TITLE;  //一番初めはタイトルの初期化から始める


// Win32アプリケーションは WinMain関数 から始まる
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//ウィンドウの状態を設定する
	ChangeWindowMode(true);
	// 画面サイズを変更
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//DXライブラリの初期化
	if (DxLib_Init() == -1) {
		return -1;
	}


	//描画するスクリーンを設定する
	SetDrawScreen(DX_SCREEN_BACK);

	//クラスの宣言
	SceneTitle Title;
	ScenePlay Play;
	SceneResult Result;

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



		//シーンIDによって処理の振り分け
		switch (g_CurrentSceneID)
		{
		case SCENE_ID_INIT_TITLE:
		{
			//タイトル初期化
			Title.Init();
		}
		break;

		case SCENE_ID_LOOP_TITLE:
		{
			//タイトル通常処理
			Title.Step();

			//タイトル描画処理
			Title.Draw();
		}
		break;

		case SCENE_ID_FIN_TITLE:
		{
			//タイトル後処理
			Title.Fin();
		}
		break;

		case SCENE_ID_INIT_PLAY:
		{
			//プレイ初期化
			Play.Init();
		}
		break;

		case SCENE_ID_LOOP_PLAY:
		{
			//プレイ通常処理
			Play.Step();

			//プレイ描画処理
			Play.Draw();
		}
		break;

		case SCENE_ID_FIN_PLAY:
		{
			//プレイ後処理
			Play.Fin();
		}
		break;

		case SCENE_ID_INIT_RESULT:
		{
			//クリア初期化
			Result.Init();
		}
		break;

		case SCENE_ID_LOOP_RESULT:
		{
			//クリア通常処理
			Result.Step();

			//クリア描画処理
			Result.Draw();
		}
		break;

		case SCENE_ID_FIN_RESULT:
		{
			//クリア後処理
			Result.Fin();
		}
		break;


		}//シーン振り分けのswitch文


		//-----------------------------------------
		//ループの終わりに
		//フリップ関数
		ScreenFlip();

	}
	//DXライブラリの後処理
	DxLib_End();
	return 0;
}

