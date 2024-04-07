#include "DxLib.h"
#include "Scene.h"
#include "Play.h"

#include "../Cracter/Character.h"
#include "../Item/Coin/Coin.h"
#include "../Collision/Collision.h"

#define PLAY_BACKGROUND_PATH "data/02_Playimage/Background.png"
#define PLAY_TUTA_PATH "data/02_Playimage/tuta_1.png"

int g_CurrentScenePlayID = ID_PLAY_REDITION;

ScenePlay::ScenePlay()
{
	for (int i = 0; i < 2; i++) {
		BackGround[i] = 0;		//�w�i�摜�̏�����
		Tuta[i] = 0;			//�c�^�摜�̏�����
		BG_PosY[i] = 0;			//�摜�ړ��p�ϐ��̏�����
		Tuta_PosY[i] = 0;			//�摜�ړ��p�ϐ��̏�����
	}
}

ScenePlay::~ScenePlay() {}

//�^�C�g���̏�����
void ScenePlay::Init()
{
	//�摜�̓ǂݍ���
	//�w�i
	BackGround[0] = LoadGraph(PLAY_BACKGROUND_PATH);
	BackGround[1] = LoadGraph(PLAY_BACKGROUND_PATH);

	//�c�^
	Tuta[0] = LoadGraph(PLAY_TUTA_PATH);
	Tuta[1] = LoadGraph(PLAY_TUTA_PATH);

	//�摜�ړ��p�ϐ��̏����l
	BG_PosY[0] = 0;
	BG_PosY[1] = 720;
	Tuta_PosY[0] = 0;
	Tuta_PosY[1] = 720;


	//��������
	timer.Init();
	timer.Load();

	//�ʏ폈���ֈړ�
	//g_CurrentSceneID = SCENE_ID_LOOP_PLAY;
	//play�̒��̏����ړ�
	g_CurrentScenePlayID = ID_PLAY_REDITION;
}

// �^�C�g���ʏ폈��
void ScenePlay::Step()
{
	//switch (g_CurrentScenePlayID)
	//{
	//case ID_PLAY_REDITION:
	//	g_CurrentScenePlayID = ID_PLAY_NOW;
	//	break;
	//case ID_PLAY_NOW:
	//	BG_PosY[0]-=2;
	//	BG_PosY[1]-=2;
	//	if (BG_PosY[0] <= -720) {
	//		BG_PosY[0] = 720;
	//	}
	//	if (BG_PosY[1] <= -720) {
	//		BG_PosY[1] = 720;
	//	}
	//	//��������
	//	timer.CountDown();
	//	if (timer.tensPlace == 0 && timer.oncePlace == 0) {
	//		g_CurrentScenePlayID = ID_PLAY_FINSH;
	//	}
	//	break;
	//case ID_PLAY_FINSH:
	//	g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	//	break;
	//default:
	//	break;
	//}
	BG_PosY[0] -= 1;
	BG_PosY[1] -=1;
	if (BG_PosY[0] <= -720) {
		BG_PosY[0] = 720;
	}
	if (BG_PosY[1] <= -720) {
		BG_PosY[1] = 720;
	}

	Tuta_PosY[0] -= 3;
	Tuta_PosY[1] -= 3;
	if (Tuta_PosY[0] <= -720) {
		Tuta_PosY[0] = 720;
	}
	if (Tuta_PosY[1] <= -720) {
		Tuta_PosY[1] = 720;
	}


	//��������
	timer.CountDown();
	if (timer.tensPlace == 0 && timer.oncePlace == 0) {
		g_CurrentSceneID = SCENE_ID_FIN_PLAY;
	}
}

// �^�C�g���`�揈��
void ScenePlay::Draw()
{	
	//�w�i�摜
	DrawGraph(0, BG_PosY[0], BackGround[0], true);
	DrawGraph(0, BG_PosY[1], BackGround[1], true);

	//�c�^	
	DrawGraph(0, Tuta_PosY[0], Tuta[0], true);
	DrawGraph(0, Tuta_PosY[1], Tuta[1], true);

	timer.Draw();

	/*switch (g_CurrentScenePlayID)
	{
	case ID_PLAY_REDITION:

		break;

	case ID_PLAY_NOW:
		
		break;

	case ID_PLAY_FINSH:
		break;
	default:
		break;
	}*/

	//�f�o�b�O�p
	//DrawFormatString(0, 0, GetColor(255, 0, 0), "��@%d", BG_PosY[0]);
	//DrawFormatString(0, 20, GetColor(255, 0, 0), "���@%d", BG_PosY[1]);

	//DrawFormatString(0, 140, GetColor(60, 60, 50), "�\%d", timer.tensPlace);
	//DrawFormatString(30, 140, GetColor(60, 60, 50), "��%d", timer.oncePlace);
}

// �^�C�g���I������
void ScenePlay::Fin()
{
	// �v���C�V�[���Ɉړ�
	g_CurrentSceneID = SCENE_ID_INIT_RESULT;
}


void Character_Hit_Coin()
{
	for (int i = 0; i < CHARACTER_PARASOL_MAX; i++)
	{
		if (coin[i].IsUse == false)
			continue;
		for (int c = 0; c < COIN_MAX; c++)
		{
			if (IsHitRect(character[i].x, character[i].y, character[i].w, character[i].h, coin[c].x, coin[c].y, coin[c].w, coin[c].h))
			{
				DrawFormatString(100, 240, GetColor(255, 0, 0), "�q�b�g");
				coin[c].IsUse = false;
				if (coin[c].IsUse == false)
				{
					coin[i].x = 1220;
					coin[i].y = 0;
				}
			}
		}
	}
}