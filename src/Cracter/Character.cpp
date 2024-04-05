#include "DxLib.h"
#include"Character.h"
#include"../Input_struct/input.h"
#define CHARACTER_SPEED	(5)				//�L�����N�^�[�̃X�s�[�h
#define CHARACTERGRAVITY	(1)			//�L�����N�^�[�̏d��
#define CHARACTERLIMITGRAVITYDOWN	(8)	//�p���\�����Ȃ����̏d�̓��~�b�g
#define CHARACTERLIMITGRAVITYUP	(5)		//�p���\�������鎞�̏d�̓��~�b�g
Character character[1];
void InitCharacter()	//�L�����N�^�[�̏�����
{
	for (int i = 0; i < CHARACTER_PARASOL_MAX; i++)
	{
		character[i].x = 0;
		character[i].y = 50;
		character[i].h = 128;
		character[i].w = 100;
		character[i].Gravity = 0;
		character[i].handleUP = LoadGraph("data/02_Playimage/player_1.png");
	}
}
void StepCharacter()		//�L�����N�^�[�̈ړ�����
{
	for (int i = 0; i < CHARACTER_PARASOL_MAX; i++)
	{
		if (IsKeykeep(KEY_INPUT_A) == 1)
		{
			character[i].x -= CHARACTER_SPEED;
		}
		if (IsKeykeep(KEY_INPUT_D) == 1)
		{
			character[i].x += CHARACTER_SPEED;
		}
		if (IsKyePush(KEY_INPUT_SPACE) == 1)
		{
			if (character[i].parasol == false)
			{
				character[i].parasol = true;
			}
			else if (character[i].parasol == true)
			{
				character[i].parasol = false;
			}
		}
	}
	
}
void StepCharacterDraw()		//�L�����N�^�[�̕`��
{
	for (int i = 0; i < CHARACTER_PARASOL_MAX; i++)
	{
		DrawBox(character[i].x, character[i].y, character[i].x + character[i].w, character[i].y + character[i].h, GetColor(255, 255, 255), false);
		/*if (character[i].parasol == true)*/
		{
			DrawRotaGraph(character[i].x + 48, character[i].y + 64, 1.0f, 0.0f, character[i].handleUP, true);
		}
		
	}
}
void StepCharacterGravity()		//�L�����N�^�[�̏d�͏���
{
	for (int i = 0; i < CHARACTER_PARASOL_MAX; i++)
	{
		//	�������Ă�Ƃ�
		if (character[i].parasol == false)
		{
			character[i].Gravity += CHARACTERGRAVITY;
			if (character[i].Gravity > CHARACTERLIMITGRAVITYDOWN)
			{
				character[i].Gravity = CHARACTERLIMITGRAVITYDOWN;
				character[i].y += character[i].Gravity;
			}
			else
				character[i].y += character[i].Gravity;
		}
		//�オ���Ă�Ƃ�
		if (character[i].parasol == true)
		{
			character[i].Gravity += CHARACTERGRAVITY;
			if (character[i].Gravity > CHARACTERLIMITGRAVITYUP)
			{
				character[i].Gravity = CHARACTERLIMITGRAVITYUP;
				character[i].y -= character[i].Gravity;
			}
			else
				character[i].y -= character[i].Gravity;
		}
	}
}