#include "DxLib.h"
#include "Scene.h"
#include "Title.h"
#include"../Input_struct/input.h"

#define TITLE_BACKGROUND_PATH "data/01_TitleImage/title.png"

SceneTitle::SceneTitle()
{
	BackGround = 0;		//�摜�̏�����
	ruru_IMG = 0;
	sound.bgm[BGM_OP] = 0;		//BGM�̏�����
	count = 0;
}

SceneTitle::~SceneTitle() {}

//�^�C�g���̏�����
void SceneTitle::Init()
{
	//�摜�̓ǂݍ���
	BackGround = LoadGraph(TITLE_BACKGROUND_PATH);
	ruru_IMG = LoadGraph("data/01_TitleImage/ru-ru.png");
	//�L�[�̏�����
	InitInput();

	//BGM
	sound.bgm[BGM_OP] = LoadSoundMem("data/Sound/title.mp3");//OP
	PlaySoundMem(sound.bgm[BGM_OP], DX_PLAYTYPE_LOOP, true);


	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_TITLE;

}

// �^�C�g���ʏ폈��
void SceneTitle::Step()
{
	//�L�[
	StepInput();

	//�X�y�[�X�L�[�����������ʈړ�
	if (IsKyePush(KEY_INPUT_SPACE) && (count == 0 || count == 1))
	{
		count++;
	}
 	if (IsKyePush(KEY_INPUT_SPACE) && count >= 2 )
	{
		g_CurrentSceneID = SCENE_ID_FIN_TITLE;
	}
}

// �^�C�g���`�揈��
void SceneTitle::Draw()
{
	if (count == 0) {
		DrawGraph(0, 0, BackGround, true);
	}
	if (count >= 1) {
		DrawGraph(0, 0, ruru_IMG, true);
	}
}

// �^�C�g���I������
void SceneTitle::Fin()
{
	//BGM�̍폜
	StopSoundMem(sound.bgm[BGM_OP]);
	DeleteSoundMem(sound.bgm[BGM_OP]);

	// �v���C�V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_PLAY;
}