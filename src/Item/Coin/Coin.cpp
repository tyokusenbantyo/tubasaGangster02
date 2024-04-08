#include"DxLib.h"
#include"Coin.h"
#include"../../Input_struct/input.h"

Coin coin[COIN_MAX];
#define COIN_GRAVITY	(1)
#define COIN_LIMITGRAVITY	(8)
#define COIN_SPEED			(6)
int CoinPath1;
int CoinPath2;
int CoinPath3;
int interval = 0;
void InitCoin()
{
	for (int i = 0; i < COIN_MAX; i++)
	{
		if (i == 0 || i == 1 || i == 2 || i == 3)
		{
			coin[i].x = 1100;
		}
		if (i == 4 || i == 5 || i == 6 || i == 7)
		{
			coin[i].x = 100;
		}
		
		coin[i].y = 400;
		coin[i].h = 64;
		coin[i].w = 64;
		coin[i].GravitySpeed = 0;
		coin[i].DrawFrameCount = 0;
		coin[i].bulletFrameCount = 0;
		coin[i].IsUse = false;
		coin[i].BulletIinterval = false;
		coin[i].oneJunp = false;
		coin[i].handlePath = LoadGraph("data/02_Playimage/coin.png");
		CoinPath1 = LoadGraph("data/02_Playimage/coin.png");
		CoinPath2 = LoadGraph("data/02_Playimage/coin2.png");
		CoinPath3 = LoadGraph("data/02_Playimage/coin3.png");
	}
}

void CoinBullet()	//コインの発射処理
{
	for (int i = 0; i < COIN_MAX; i++)
	{
		if (coin[i].BulletIinterval==true)
		{
			if (!coin[i].IsUse)
			{
				coin[i].IsUse = true;
			}
		}
	}
}
void Coininterval()//コインの発射感覚
{
	for (int i = 0; i < COIN_MAX; i++)
	{
		if (coin[i].bulletFrameCount == 50)
		{
			coin[0].IsUse = true;
			coin[0].oneJunp = true;
			coin[4].IsUse = true;
			coin[4].oneJunp = true;
		}
		if (coin[i].bulletFrameCount == 150)
		{
			coin[1].IsUse = true;
			coin[1].oneJunp = true;
			coin[5].IsUse = true;
			coin[5].oneJunp = true;
		}
		if (coin[i].bulletFrameCount == 50)
		{
			coin[2].IsUse = true;
			coin[2].oneJunp = true;
			coin[6].IsUse = true;
			coin[6].oneJunp = true;
		}

		if (coin[i].bulletFrameCount == 150)
		{
			coin[3].IsUse = true;
			coin[3].oneJunp = true;
			coin[7].IsUse = true;
			coin[7].oneJunp = true;
		}
		if (coin[i].bulletFrameCount < 151)
		{
			coin[i].bulletFrameCount++;
		}
		else
			coin[i].bulletFrameCount = 0;
	}
	
}
void coinMove()	//コインの移動処理
{
	
	for (int i = 0; i < COIN_MAX; i++)
	{
		if (!coin[i].IsUse)
			continue;
		if (coin[i].oneJunp == true)
		{
			if(i == 0)
				coin[i].GravitySpeed -= 10;
			if (i == 1)
				coin[i].GravitySpeed -= 20;
			if (i == 2)
				coin[i].GravitySpeed -= 10;
			if (i == 3)
				coin[i].GravitySpeed -= 20;
			if (i == 4)
				coin[i].GravitySpeed -= 15;
			if (i == 5)
				coin[i].GravitySpeed -= 15;
			if (i == 6)
				coin[i].GravitySpeed -= 30;
			if (i == 7)
				coin[i].GravitySpeed -= 15;
			coin[i].oneJunp = false;
		}
		if (i == 0 || i == 1 || i == 2 || i == 3)
		{
			coin[i].x -= COIN_SPEED;
		}
		
		if (i == 4 || i == 5 || i == 6 || i == 7)
		{
			coin[i].x += COIN_SPEED;
		}
		if (coin[i].y > 720)
		{
			if (i == 0 || i == 1 || i == 2 || i == 3 )
			{
				coin[i].x = 1100;
			}
			if (i == 4 || i == 5 || i == 6 || i == 7)
			{
				coin[i].x = 100;
			}

			coin[i].IsUse = false;
			coin[i].y = 400;
			coin[i].GravitySpeed = 0;
			coin[i].oneJunp = true;
			
		}
	}
}
void DrawCoin()
{
	for (int i = 0; i < COIN_MAX; i++)
	{
		//DrawBox(coin[i].x, coin[i].y, coin[i].x + coin[i].w, coin[i].y + coin[i].h, GetColor(255, 255, 255), false);
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
		//DrawFormatString(0, 400, GetColor(255, 0, 0), "coin[i].bulletinterval =%d", coin[i].bulletFrameCount);
		//DrawFormatString(0, 420, GetColor(255, 0, 0), "coin[i].x =%d", coin[0].x);
		//DrawFormatString(0, 440, GetColor(255, 0, 0), "coin[i].y =%d", coin[0].y);
		//DrawFormatString(0, 460, GetColor(255, 0, 0), "coin[i].x =%d", coin[1].x);
		//DrawFormatString(0, 480, GetColor(255, 0, 0), "coin[i].y =%d", coin[1].y);
	}
}
void CoinGravity()
{
	for (int i = 0; i < COIN_MAX; i++)
	{
		if (!coin[i].IsUse)
			continue;
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
