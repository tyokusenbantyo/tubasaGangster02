#include"DxLib.h"
#include"Coin.h"
#include"../../Input_struct/input.h"

Coin coin[COIN_MAX];
#define COIN_GRAVITY	(1)
#define COIN_LIMITGRAVITY	(8)
int CoinPath1;
int CoinPath2;
int CoinPath3;
void InitCoin()
{
	for (int i = 0; i < COIN_MAX; i++)
	{
		coin[i].x = 1220;
		coin[i].y = 0;
		coin[i].h = 64;
		coin[i].w = 64;
		coin[i].GravitySpeed = 0;
		coin[i].DrawFrameCount = 0;
		coin[i].IsUse = false;
		coin[i].handlePath = LoadGraph("data/02_Playimage/coin.png");
		CoinPath1 = LoadGraph("data/02_Playimage/coin.png");
		CoinPath2 = LoadGraph("data/02_Playimage/coin2.png");
		CoinPath3 = LoadGraph("data/02_Playimage/coin3.png");
	}
}

void CoinBullet()	//コインの発射処理
{
	/*if (IsKyePush(KEY_INPUT_P) == 1)*/
	{
		for (int i = 0; i < COIN_MAX; i++)
		{
			
			if (!coin[i].IsUse)
			{
				coin[i].IsUse = true;
			}
		}
	}
	
}
void coinMove()	//コインの移動処理
{
	DrawFormatString(0, 350, GetColor(255, 0, 0), "coin[i].y =%d", coin[0].y);
	for (int i = 0; i < COIN_MAX; i++)
	{
		if (coin[i].IsUse == true)
		{
			coin[i].x -= 8;
		}
		if (coin[i].y > 500)
		{
			coin[i].IsUse = false;
			coin[i].x = 1220;
			coin[i].y = 0;
		}
	}
}
void DrawCoin()
{
	for (int i = 0; i < COIN_MAX; i++)
	{
		DrawBox(coin[i].x, coin[i].y, coin[i].x + coin[i].w, coin[i].y + coin[i].h, GetColor(255, 255, 255), false);
		if (coin[i].DrawFrameCount == 0)
		{
			coin[i].handlePath = CoinPath1;
		}
		if (coin[i].DrawFrameCount == 7)
		{
			coin[i].handlePath = CoinPath2;
		}
		if (coin[i].DrawFrameCount == 14)
		{
			coin[i].handlePath = CoinPath3;
		}
		if (coin[i].DrawFrameCount >15)
		{
			coin[i].DrawFrameCount = 0;
		}
		else
		coin[i].DrawFrameCount++;
		if (coin[i].IsUse == true)
		{
			DrawRotaGraph(coin[i].x + 32, coin[i].y + 32, 1.0f, 0.0f, coin[i].handlePath, true);
		}
	}
}
void CoinGravity()
{
	for (int i = 0; i < COIN_MAX; i++)
	{
		coin[i].GravitySpeed += COIN_GRAVITY;
		if (coin[i].GravitySpeed > COIN_LIMITGRAVITY)
		{
			coin[i].GravitySpeed = COIN_LIMITGRAVITY;
			coin[i].y += coin[i].GravitySpeed;
		}
		else
			coin[i].y += coin[i].GravitySpeed;
	}

}