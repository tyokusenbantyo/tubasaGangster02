#pragma once
//ウィンドウの幅・高さ
#define WINDOW_HEIGHT	(720)
#define WINDOW_WIDTH	(1280)

//タイトルシーンID情報
#define SCENE_ID_INIT_TITLE			(100)			//初期化
#define SCENE_ID_LOOP_TITLE			(101)			//繰り返し
//クリアシーン情報
#define SCENE_ID_INIT_CLEAR			(200)			//初期化
#define SCENE_ID_LOOP_CLEAR			(201)			//繰り返し
//ゲームオーバーシーン情報
#define SCENE_ID_INIT_GAMEOVER		(300)			//初期化
#define SCENE_ID_LOOP_GAMEOVER		(301)			//繰り返し
//プレイシーン情報
#define SCENE_ID_INIT_PLAY			(400)			//初期化
#define SCENE_ID_LOOP_PLAY			(401)			//繰り返し
int g_CurrentSceneID= SCENE_ID_INIT_PLAY;