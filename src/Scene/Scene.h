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
	SCENE_ID_INIT_CLEAR,
	SCENE_ID_LOOP_CLEAR,
	SCENE_ID_FIN_CLEAR,
};

//現在のシーンID
extern int g_CurrentSceneID;
