//�E�B���h�E��\������v���O�����i�ЂȌ`�j

#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#include"Scene/Scene.h"

#include"../src/Cracter/Character.h"
#include"../src/Input/input.h"
#include"../src/Item/Coin/Coin.h"

#include"../src/Scene/Title.h"
#include"../src/Play/Play.h"
#include"../src/Scene/Play.h"
#include"../src/Scene/Result.h"
//#include"src/Character.h"
//#include"src/input.h"

//���݂̃V�[��ID
int g_CurrentSceneID = SCENE_ID_INIT_TITLE;  //��ԏ��߂̓^�C�g���̏���������n�߂�

// Win32�A�v���P�[�V������ WinMain�֐� ����n�܂�
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	//�E�B���h�E�̏�Ԃ�ݒ肷��
	ChangeWindowMode(true);

	//DX���C�u�����̏�����
	if (DxLib_Init() == -1) {
		return -1;
	}

	// ��ʃT�C�Y��ύX
	SetGraphMode( WINDOW_WIDTH, WINDOW_HEIGHT ,32);

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);
	
	//-----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���
	
		//�N���X�̐錾
	SceneTitle title;
	//ScenePlay play;
	SceneResult result;
	//-----------------------------------------

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

		switch (g_CurrentSceneID)
		{
			case SCENE_ID_INIT_TITLE:
			{
				//�^�C�g��������
				title.Init();
			}
			break;

			case SCENE_ID_LOOP_TITLE:
			{
				//�^�C�g���ʏ폈��
				title.Step();

				//�^�C�g���`�揈��
				title.Draw();
			}
			break;

			case SCENE_ID_FIN_TITLE:
			{
				//�^�C�g���㏈��
				title.Fin();
			}
			break;

			case SCENE_ID_INIT_PLAY:
			{
				InitInput();		//���͂̏�����
				InitCharacter();	//�L�����N�^�[�̏�����
				InitCoin();			//�R�C���̏�����

				g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
			}
			break;
			case SCENE_ID_LOOP_PLAY:
			{
				StepInput();			//�L�[�̋L��
				StepCharacter();		//�L�����N�^�[�̈ړ�
				StepCharacterGravity(); //�L�����N�^�[�̏d��
				Character_Hit_Coin();
				StepCharacterDraw();	//�L�����N�^�[�̕`��
				DrawCoin();

			}
			break;
			case SCENE_ID_INIT_RESULT:
			{
				//�N���A������
				result.Init();
			}
			break;

			case SCENE_ID_LOOP_RESULT:
			{
				//�N���A�ʏ폈��
				result.Step();

				//�N���A�`�揈��
				result.Draw();
			}
			break;

			case SCENE_ID_FIN_RESULT:
			{
				//�N���A�㏈��
				result.Fin();
			}
			break;

		}


		//-----------------------------------------
		//���[�v�̏I����
		//�t���b�v�֐�
		ScreenFlip();

	}

	//-----------------------------------------
	//�Ō�ɂP�񂾂���鏈���������ɏ���


	//-----------------------------------------
	//DX���C�u�����̌㏈��
	DxLib_End();

	return 0;
}

