#pragma once
#define COIN_MAX	(8)
struct Coin
{
	int x, y, h, w,handlePath,GravitySpeed,DrawFrameCount,
		bulletFrameCount;		//発射感覚を知っていする;
	bool IsUse;
	bool BulletIinterval;
	bool oneJunp;				
};
void InitCoin();	//コインの初期化
void DrawCoin();	//コインの描画
void CoinGravity();	//コインの重力
void coinMove();	//コインの移動処理
void CoinBullet();	//コインの発射処理
void Coininterval();//コインの発射感覚
extern Coin coin[COIN_MAX];
