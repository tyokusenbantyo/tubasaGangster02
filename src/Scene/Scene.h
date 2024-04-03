#pragma once
enum SCENE_ID
{
	//タイトル関連
	SCENE_ID_INIT_TITLE,
	SCENE_ID_LOOP_TITLE,
	SCENE_ID_FIN_TITLE,

	//プレイ関連
	SCENE_ID_INIT_PLAY,
	SCENE_ID_LOOP_PLAY,

	SCENE_ID_FIN_PLAY,

	//クリア関連	
	SCENE_ID_INIT_RESULT,
	SCENE_ID_LOOP_RESULT,
	SCENE_ID_FIN_RESULT,
};

enum PLAY_SCENE_ID
{
	ID_PLAY_REDITION,		//始まる前の演出
	ID_PLAY_NOW,			//プレイ中
	ID_PLAY_FINSH,			//終わりの演出
};
//現在のシーンID
extern int g_CurrentSceneID;
extern int g_CurrentScenePlayID;
