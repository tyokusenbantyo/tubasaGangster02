#include "DxLib.h"
#include"Character.h"
#include"../Input/input.h"

#define CHARACTER_SPEED	(5)				//キャラクターのスピード
#define CHARACTERGRAVITY	(1)			//キャラクターの重力
#define CHARACTERLIMITGRAVITYDOWN	(8)	//パラソルがない時の重力リミット
#define CHARACTERLIMITGRAVITYUP	(5)		//パラソルがある時の重力リミット
Character character[1];
void InitCharacter()	//キャラクターの初期化
{
	for (int i = 0; i < CHARACTER_MAX; i++)
	{
		character[i].x = 0;
		character[i].y = 0;
		character[i].h = 64;
		character[i].w = 64;
		character[i].Gravity = 0;
		character[i].handle = LoadGraph("data/Playimage/coin_demo.png");
	}
}
void StepCharacter()		//キャラクターの移動処理
{
	for (int i = 0; i < CHARACTER_MAX; i++)
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
void StepCharacterDraw()		//キャラクターの描画
{
	for (int i = 0; i < CHARACTER_MAX; i++)
	{
		DrawBox(character[i].x, character[i].y, character[i].x + character[i].w, character[i].y + character[i].h, GetColor(255, 255, 255), false);
		DrawRotaGraph(character[i].x+32, character[i].y+32, 1.0f, 0.0f, character[i].handle, true);
	}
}
void StepCharacterGravity()		//キャラクターの重力処理
{
	for (int i = 0; i < CHARACTER_MAX; i++)
	{
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