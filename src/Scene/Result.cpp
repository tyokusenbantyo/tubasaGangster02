#include "DxLib.h"
#include "Scene.h"
#include "Result.h"

#define TITLE_BACKGROUND_PATH "data/03_ClearImage/result_1.png"

SceneResult::SceneResult()
{
	BackGround = 0;		//�摜�̏�����
}

SceneResult::~SceneResult() {}

//������
void SceneResult::Init()
{
	//�摜�̓ǂݍ���
	BackGround = LoadGraph(TITLE_BACKGROUND_PATH);
	//�L�[�̏�����
	InitInput();
	//BGM
	sound.bgm[BGM_ED] = LoadSoundMem("data/Sound/resulr.mp3");//OP
	PlaySoundMem(sound.bgm[BGM_ED], DX_PLAYTYPE_LOOP, true);

	//�ʏ폈���ֈړ�
	g_CurrentSceneID = SCENE_ID_LOOP_RESULT;

}

// �ʏ폈��
void SceneResult::Step()
{
	//�L�[
	StepInput();
	//�X�y�[�X�L�[�𗣂������ʈړ�
	if (IsKeyRelease(KEY_INPUT_SPACE))
	{
		g_CurrentSceneID = SCENE_ID_FIN_RESULT;
	}
}

// �`�揈��
void SceneResult::Draw()
{
	DrawGraph(0, 0, BackGround, true);
}

// �I������
void SceneResult::Fin()
{
	//BGM�̍폜
	StopSoundMem(sound.bgm[BGM_ED]);
	DeleteSoundMem(sound.bgm[BGM_ED]);

	//�^�C�g���ړ�
	g_CurrentSceneID = SCENE_ID_INIT_TITLE;
}