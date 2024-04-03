#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#include "src/Scene/Scene.h"
#include "src/Scene/Title.h"
#include "src/Scene/Play.h"
#include "src/Scene/Result.h"

// define
#define	SCREEN_SIZE_X	1280	// X�����̉�ʃT�C�Y���w��
#define	SCREEN_SIZE_Y	720	// Y�����̉�ʃT�C�Y���w��

//���݂̃V�[��ID
int g_CurrentSceneID = SCENE_ID_INIT_TITLE;  //��ԏ��߂̓^�C�g���̏���������n�߂�


// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);
	// ��ʃT�C�Y��ύX
	SetGraphMode(SCREEN_SIZE_X, SCREEN_SIZE_Y, 32);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}


	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);

	//�N���X�̐錾
	SceneTitle Title;
	ScenePlay Play;
	SceneResult Result;

	//�Q�[�����C�����[�v
	while (ProcessMessage() != -1)
	{
		if (CheckHitKey(KEY_INPUT_ESCAPE) == 1)
		{
			//�G�X�P�[�v�L�[�������ꂽ��I��
			break;
		}

		//��ʂɕ\�����ꂽ���̂�������
		ClearDrawScreen();



		//�V�[��ID�ɂ���ď����̐U�蕪��
		switch (g_CurrentSceneID)
		{
		case SCENE_ID_INIT_TITLE:
		{
			//�^�C�g��������
			Title.Init();
		}
		break;

		case SCENE_ID_LOOP_TITLE:
		{
			//�^�C�g���ʏ폈��
			Title.Step();

			//�^�C�g���`�揈��
			Title.Draw();
		}
		break;

		case SCENE_ID_FIN_TITLE:
		{
			//�^�C�g���㏈��
			Title.Fin();
		}
		break;

		case SCENE_ID_INIT_PLAY:
		{
			//�v���C������
			Play.Init();
		}
		break;

		case SCENE_ID_LOOP_PLAY:
		{
			//�v���C�ʏ폈��
			Play.Step();

			//�v���C�`�揈��
			Play.Draw();
		}
		break;

		case SCENE_ID_FIN_PLAY:
		{
			//�v���C�㏈��
			Play.Fin();
		}
		break;

		case SCENE_ID_INIT_RESULT:
		{
			//�N���A������
			Result.Init();
		}
		break;

		case SCENE_ID_LOOP_RESULT:
		{
			//�N���A�ʏ폈��
			Result.Step();

			//�N���A�`�揈��
			Result.Draw();
		}
		break;

		case SCENE_ID_FIN_RESULT:
		{
			//�N���A�㏈��
			Result.Fin();
		}
		break;


		}//�V�[���U�蕪����switch��


		//-----------------------------------------
		//���[�v�̏I����
		//�t���b�v�֐�
		ScreenFlip();

	}
	//DX���C�u�����̌㏈��
	DxLib_End();
	return 0;
}

