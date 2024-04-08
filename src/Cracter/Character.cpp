#include "DxLib.h"
#include"Character.h"
#include"../Input_struct/input.h"
#include"../Item/hammer/hammer.h"
#include "../Sound/sound.h"
#define CHARACTER_SPEED	(5)				//キャラクターのスピード
#define CHARACTERGRAVITY	(1)			//キャラクターの重力
#define CHARACTERLIMITGRAVITYDOWN	(8)	//パラソルがない時の重力リミット
#define CHARACTERLIMITGRAVITYUP	(5)		//パラソルがある時の重力リミット
int Character_Path[4];
int Character_cheng=LoadGraph("data/02_Playimage/PPT4.png");

Sound sound;
Character character[1];
void InitCharacter()	//キャラクターの初期化
{
	for (int i = 0; i < CHARACTER_PARASOL_MAX; i++)
	{
		character[i].x = 640;
		character[i].y = 50;
		character[i].h = 128;
		character[i].w = 100;
		character[i].Gravity = 0;
		character[i].handleUP = LoadGraph("data/02_Playimage/player_1.png");
		character[i].Chararazian = 0.0f;
		character[i].parasolOpenFramecount - 0;
		character[i].parasolCloseFramecount = 0;
		Character_Path[0] = LoadGraph("data/02_Playimage/PPT1.png");
		Character_Path[1] = LoadGraph("data/02_Playimage/PPT2.png");
		Character_Path[2] = LoadGraph("data/02_Playimage/PPT3.png");
		Character_Path[3] = LoadGraph("data/02_Playimage/PPT4.png");

	}
}
void StepCharacter()		//キャラクターの移動処理
{
	for (int i = 0; i < CHARACTER_PARASOL_MAX; i++)
	{		
		if (hummer[0].otosu == false)
		{
			if (hummer[1].otosu == false)
			{
				if (hummer[2].otosu == false)
				{
					if (hummer[3].otosu == false)
					{
						if (IsKeykeep(KEY_INPUT_A) == 1)
						{
							character[i].x -= CHARACTER_SPEED;
							if (character[i].x <= 280)
							{
								character[i].x += CHARACTER_SPEED;
							}
							if (character[i].Chararazian > -0.8)
							{
								character[i].Chararazian -= 0.05;
							}
						}
						if (IsKeykeep(KEY_INPUT_D) == 1)
						{
							character[i].x += CHARACTER_SPEED;
							if (character[i].x >= 920)
							{
								character[i].x -= CHARACTER_SPEED;
							}
							if (character[i].Chararazian < 0.5)
							{
								character[i].Chararazian += 0.05;
							}
						}
						if (IsKyePush(KEY_INPUT_SPACE) == 1)
						{
							if (character[i].parasol == false)
							{
								character[i].parasol = true;
								//se
								PlaySoundMem(sound.se[SE_OPEN_PARASOL], DX_PLAYTYPE_LOOP, true);
							}
							else if (character[i].parasol == true)
							{
								character[i].parasol = false;
							}

							
						}
						
					}
				}
			}		
		}
		if (hummer[0].otosu == true)
		{
			character[i].parasol = false;
		}
		if (hummer[1].otosu == true)
		{
			character[i].parasol = false;
		}
		if (hummer[2].otosu == true)
		{
			character[i].parasol = false;
		}
		if (hummer[3].otosu == true)
		{
			character[i].parasol = false;
		}
		
	}
}
void StepCharacterDraw()		//キャラクターの描画
{
	for (int i = 0; i < CHARACTER_PARASOL_MAX; i++)
	{
		//DrawBox(character[i].x, character[i].y, character[i].x + character[i].w, character[i].y + character[i].h, GetColor(255, 255, 255), false);
		if (character[i].parasol == true)	//パラソルが開いてるか確認
		{
			//フレームカウントで画像を切り替える
			if (character[i].parasolOpenFramecount == 0)
			{
				Character_cheng = Character_Path[3];
			}
			if (character[i].parasolOpenFramecount == 1)
			{
				Character_cheng = Character_Path[2];
			}
			if (character[i].parasolOpenFramecount == 2)
			{
				Character_cheng = Character_Path[1];
			}
			if (character[i].parasolOpenFramecount == 3)
			{
				Character_cheng = Character_Path[0];
			}
			if (character[i].parasolOpenFramecount < 3)
			{
				character[i].parasolOpenFramecount++;
			}
			character[i].parasolCloseFramecount = 0;
			DrawRotaGraph(character[i].x + 33, character[i].y + 37, 1.0f, character[i].Chararazian, Character_cheng, true);
		}
		if (character[i].parasol == false)	//パラソルが開いてるか確認
		{
			//フレームカウントで画像を切り替える
			if (character[i].parasolCloseFramecount == 0)
			{
				Character_cheng = Character_Path[0];
			}
			if (character[i].parasolCloseFramecount == 1)
			{
				Character_cheng = Character_Path[1];
			}
			if (character[i].parasolCloseFramecount == 2)
			{
				Character_cheng = Character_Path[2];
			}
			if (character[i].parasolCloseFramecount == 3)
			{
				Character_cheng = Character_Path[3];
			}
			if (character[i].parasolCloseFramecount < 3)
			{
				character[i].parasolCloseFramecount++;
			}
			character[i].parasolOpenFramecount = 0;
			DrawRotaGraph(character[i].x + 33, character[i].y + 37, 1.0f, character[i].Chararazian, Character_cheng, true);
		}
		
	}
}
void StepCharacterGravity()		//キャラクターの重力処理
{
	for (int i = 0; i < CHARACTER_PARASOL_MAX; i++)
	{
		//	下がってるとき
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
		//上がってるとき
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