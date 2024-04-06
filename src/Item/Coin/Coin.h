#pragma once
#define COIN_MAX	(1)
struct Coin
{
	int x, y, h, w,handlePath,GravitySpeed,DrawFrameCount;
	bool IsUse;
};
void InitCoin();	//コインの初期化
void DrawCoin();	//コインの描画
void CoinGravity();	//コインの重力
void coinMove();	//コインの移動処理
void CoinBullet();	//コインの発射処理
extern Coin coin[COIN_MAX];
