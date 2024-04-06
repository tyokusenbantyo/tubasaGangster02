#include "DxLib.h"
#include"../Cracter/Character.h"
#include"../Item/Coin/Coin.h"
#include"../Collision/Collision.h"
void Character_Hit_Coin()
{
	for (int i = 0; i < CHARACTER_PARASOL_MAX;i++)
	{
		if (coin[i].IsUse == false)
			continue;
		for (int c = 0; c < COIN_MAX; c++)
		{
			if (IsHitRect(character[i].x, character[i].y, character[i].w, character[i].h, coin[c].x, coin[c].y, coin[c].w, coin[c].h))
			{
				DrawFormatString(100, 240, GetColor(255, 0, 0), "ƒqƒbƒg");
				coin[c].IsUse = false;
				if (coin[c].IsUse ==false)
				{
					coin[i].x = 1220;
					coin[i].y = 0;
				}
			}
		}
	}
}
