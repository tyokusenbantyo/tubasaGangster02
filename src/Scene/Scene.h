#pragma once
//�E�B���h�E�̕��E����
#define WINDOW_HEIGHT	(720)
#define WINDOW_WIDTH	(1280)

//�^�C�g���V�[��ID���
#define SCENE_ID_INIT_TITLE			(100)			//������
#define SCENE_ID_LOOP_TITLE			(101)			//�J��Ԃ�
//�N���A�V�[�����
#define SCENE_ID_INIT_CLEAR			(200)			//������
#define SCENE_ID_LOOP_CLEAR			(201)			//�J��Ԃ�
//�Q�[���I�[�o�[�V�[�����
#define SCENE_ID_INIT_GAMEOVER		(300)			//������
#define SCENE_ID_LOOP_GAMEOVER		(301)			//�J��Ԃ�
//�v���C�V�[�����
#define SCENE_ID_INIT_PLAY			(400)			//������
#define SCENE_ID_LOOP_PLAY			(401)			//�J��Ԃ�
int g_CurrentSceneID= SCENE_ID_INIT_PLAY;