#pragma once
enum SCENE_ID
{
	//�^�C�g���֘A
	SCENE_ID_INIT_TITLE,
	SCENE_ID_LOOP_TITLE,
	SCENE_ID_FIN_TITLE,

	//�v���C�֘A
	SCENE_ID_INIT_PLAY,
	SCENE_ID_LOOP_PLAY,

	SCENE_ID_FIN_PLAY,

	//�N���A�֘A	
	SCENE_ID_INIT_RESULT,
	SCENE_ID_LOOP_RESULT,
	SCENE_ID_FIN_RESULT,
};

enum PLAY_SCENE_ID
{
	ID_PLAY_REDITION,		//�n�܂�O�̉��o
	ID_PLAY_NOW,			//�v���C��
	ID_PLAY_FINSH,			//�I���̉��o
};
//���݂̃V�[��ID
extern int g_CurrentSceneID;
extern int g_CurrentScenePlayID;
