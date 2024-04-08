#include"hammer.h"
#include"DxLib.h"
Hummer hummer[HUMMER_MAX];
#define HUMMER_GRAVITY	(1)
#define HUMMER_LIMITGRAVITY	(8)
#define HUMMER_SPEED			(6)
void InitHummer()
{
	for (int i = 0; i < HUMMER_MAX; i++)
	{
		if (i == 0 || i == 1 )
		{
			hummer[i].x = 1200;
		}
		if (i == 2 || i == 3)
		{
			hummer[i].x = 50;
		}
		hummer[i].otosuFramecount = 0;
		hummer[i].y = 400;
		hummer[i].h = 64;
		hummer[i].w = 64;
		hummer[i].GravitySpeed = 0;
		hummer[i].DrawFrameCount = 0;
		hummer[i].bulletFrameCount = 0;
		hummer[i].IsUse = false;
		hummer[i].BulletIinterval = false;
		hummer[i].oneJunp = false;
		hummer[i].razian = 0.0f;
		hummer[i].otosu = false;
		hummer[i].handlePath = LoadGraph("data/02_Playimage/hammer.png");
	}
}

void HummerBullet()	//コインの発射処理
{
	for (int i = 0; i < HUMMER_MAX; i++)
	{
		if (hummer[i].BulletIinterval == true)
		{
			if (!hummer[i].IsUse)
			{
				hummer[i].IsUse = true;
			}
		}
	}
}
void Hummerinterval()//コインの発射感覚
{
	for (int i = 0; i < HUMMER_MAX; i++)
	{
		if (hummer[i].bulletFrameCount == 100)
		{
			hummer[0].IsUse = true;
			hummer[0].oneJunp = true;
			/*hummer[4].IsUse = true;
			hummer[4].oneJunp = true;*/
		}
		if (hummer[i].bulletFrameCount == 200)
		{
			hummer[1].IsUse = true;
			hummer[1].oneJunp = true;
			/*hummer[5].IsUse = true;
			hummer[5].oneJunp = true;*/
		}
		if (hummer[i].bulletFrameCount == 250)
		{
			hummer[2].IsUse = true;
			hummer[2].oneJunp = true;
			/*hummer[6].IsUse = true;
			hummer[6].oneJunp = true;*/
		}

		if (hummer[i].bulletFrameCount == 251)
		{
			hummer[3].IsUse = true;
			hummer[3].oneJunp = true;
			/*hummer[7].IsUse = true;
			hummer[7].oneJunp = true;*/
		}
		if (hummer[i].bulletFrameCount < 251)
		{
			hummer[i].bulletFrameCount++;
		}
		else
			hummer[i].bulletFrameCount = 0;
	}

}
void HummerMove()	//コインの移動処理
{

	for (int i = 0; i < HUMMER_MAX; i++)
	{
		if (!hummer[i].IsUse)
			continue;
		if (hummer[i].oneJunp == true)
		{
			if (i == 0)
				hummer[i].GravitySpeed -= 20;
			if (i == 1)
				hummer[i].GravitySpeed -= 30;
			if (i == 2)
				hummer[i].GravitySpeed -= 20;
			if (i == 3)
				hummer[i].GravitySpeed -= 30;
			if (i == 4)
				hummer[i].GravitySpeed -= 25;
			if (i == 5)
				hummer[i].GravitySpeed -= 25;
			if (i == 6)
				hummer[i].GravitySpeed -= 40;
			if (i == 7)
				hummer[i].GravitySpeed -= 25;
			hummer[i].oneJunp = false;
		}
		if (i == 0 || i == 1)
		{
			hummer[i].x -= HUMMER_SPEED;
		}

		if (i == 2 || i == 3)
		{
			hummer[i].x += HUMMER_SPEED;
		}
		if (hummer[i].y > 720)
		{
			if (i == 0 || i == 1)
			{
				hummer[i].x = 1100;
			}
			if (i == 2 || i == 3)
			{
				hummer[i].x = 100;
			}

			hummer[i].IsUse = false;
			hummer[i].y = 400;
			hummer[i].GravitySpeed = 0;
			hummer[i].oneJunp = true;
		}
	}
}
void DrawHummer()
{
	for (int i = 0; i < HUMMER_MAX; i++)
	{
		DrawBox(hummer[i].x, hummer[i].y, hummer[i].x + hummer[i].w, hummer[i].y + hummer[i].h, GetColor(255, 255, 255), false);
		
		if (hummer[i].IsUse == true)
		{
			DrawRotaGraph(hummer[i].x + 32, hummer[i].y + 32, 1.0f, hummer[i].razian, hummer[i].handlePath, true);
			hummer[i].razian+=0.1;
		}
		DrawFormatString(0, 400, GetColor(255, 0, 0), "hummer[i].bulletinterval =%d", hummer[i].bulletFrameCount);
		//DrawFormatString(0, 420, GetColor(255, 0, 0), "hummer[i].x =%d", hummer[0].x);
		//DrawFormatString(0, 440, GetColor(255, 0, 0), "hummer[i].y =%d", hummer[0].y);
		//DrawFormatString(0, 460, GetColor(255, 0, 0), "hummer[i].x =%d", hummer[1].x);
		//DrawFormatString(0, 480, GetColor(255, 0, 0), "hummer[i].y =%d", hummer[1].y);
		DrawFormatString(100, 260, GetColor(255, 0, 0), "hummer[h].otosuFramecount=  %d", hummer[i].otosuFramecount);

	}
}
void HummerGravity()
{
	for (int i = 0; i < HUMMER_MAX; i++)
	{
		if (!hummer[i].IsUse)
			continue;
		hummer[i].GravitySpeed += HUMMER_GRAVITY;
		if (hummer[i].GravitySpeed > HUMMER_LIMITGRAVITY)
		{
			hummer[i].GravitySpeed = HUMMER_LIMITGRAVITY;
			hummer[i].y += hummer[i].GravitySpeed;
		}
		else
			hummer[i].y += hummer[i].GravitySpeed;
	}

}