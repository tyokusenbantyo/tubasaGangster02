#include "DxLib.h"
#include "Scene.h"
#include "Title.h"

#define TITLE_BACKGROUND_PATH "data/01_TitleImage/title.png"

SceneTitle::SceneTitle()
{
	BackGround = 0;		//�摜�̏�����
}

SceneTitle::~SceneTitle() {}

//�^�C�g���̏�����
void SceneTitle::Init()
{
	//�摜�̓ǂݍ���
	BackGround = LoadGraph(TITLE_BACKGROUND_PATH);
	//�L�[�̏�����
	InitInput();
	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;

}

// �^�C�g���ʏ폈��
void SceneTitle::Step()
{
	//�L�[
	StepInput();

	//�X�y�[�X�L�[�����������ʈړ�
 	if (IsKeyPush(KEY_INPUT_SPACE))
	{
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

// �^�C�g���`�揈��
void SceneTitle::Draw()
{
	DrawGraph(0, 0, BackGround, true);
}

// �^�C�g���I������
void SceneTitle::Fin()
{
	// �v���C�V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}