//�E�B���h�E��\������v���O�����i�ЂȌ`�j

#include "DxLib.h"	//DX���C�u�����̃C���N���[�h
#include"Scene/Scene.h"
#include"../src/parasol/parasol.h"
#include"../src/Cracter/Character.h"
#include"../src/Input_struct/input.h"
#include"../src/Item/Coin/Coin.h"
#include"Scene/Title.h"
#include"../src/Play/Play.h"
#include"Scene/Play.h"
#include"Scene/Result.h"
//#include"src/Character.h"
//#include"src/input.h"

int g_CurrentSceneID = SCENE_ID_INIT_TITLE;
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
	SetGraphMode(WINDOW_WIDTH, WINDOW_HEIGHT ,32);

	//�`�悷��X�N���[����ݒ肷��
	SetDrawScreen(DX_SCREEN_BACK);
	
	//-----------------------------------------
	//��ԍŏ��ɂP�񂾂���鏈���������ɏ���
	
	//�N���X�̌Ăяo��
	SceneTitle title;
	ScenePlay play;
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

		//-----------------------------------------
		//��������Q�[���̖{�̂��������ƂɂȂ�
		//-----------------------------------------
		
		switch (g_CurrentSceneID)
		{

		case SCENE_ID_INIT_TITLE:
		{
			title.Init();
		}
		break;

		case SCENE_ID_LOOP_TITLE:
		{
			title.Step();
			title.Draw();
		}
		break;

		case SCENE_ID_FIN_TITLE:
		{
			title.Fin();
		}
		break;

		case SCENE_ID_INIT_PLAY:
		{
			InitInput();		//���͂̏�����
			InitCharacter();	//�L�����N�^�[�̏�����
			InitCoin();			//�R�C���̏�����
			Initparasol();		//�p���\���̏�����

			play.Init();
			g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
		}
		break;

		case SCENE_ID_LOOP_PLAY:
		{
			play.Step();
			StepInput();				//�L�[�̋L��
			StepCharacter();			//�L�����N�^�[�̈ړ�
			StepCharacterGravity();		//�L�����N�^�[�̏d��
			Stepparasol();				//�L�����ƃp���\���̈ʒu���Œ肵�Ă���
			CoinBullet();				//�R�C���̔��ˏ���
			coinMove();
			CoinGravity();
			//Character_Hit_Coin();		//�L�����N�^�[�ƃR�C���̓����蔻��

			//�`��
			play.Draw();				//�w�i�̕`��
			StepCharacterDraw();		//�L�����N�^�[�̕`��
			DrawCoin();					//�R�C���̕`��
			Drawparasol();				//�p���\���̕`��

		}
		break;

		case SCENE_ID_FIN_PLAY:
		{
			play.Fin();
		}
		break;

		case SCENE_ID_INIT_RESULT:
		{
			result.Init();
		}
		break;

		case SCENE_ID_LOOP_RESULT:
		{
			result.Step();
			result.Draw();

		}
		break;

		case SCENE_ID_FIN_RESULT:
		{
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

