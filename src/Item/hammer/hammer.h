#pragma once
#define HUMMER_MAX		(4)
struct Hummer
{
	int x, y, h, w, handlePath, GravitySpeed, DrawFrameCount,
		bulletFrameCount,		//発射感覚を知っていする
		otosuFramecount;		//落とす処理のフレームyカウント
	float razian = 0.0f;
	bool IsUse;
	bool BulletIinterval;	//発射感覚
	bool oneJunp;	//一回だけジャンプ
	bool otosu;		//ハンマーと当たったら無理やり落とす
};
void InitHummer();	//コインの初期化
void DrawHummer();	//コインの描画
void HummerGravity();	//コインの重力
void HummerMove();	//コインの移動処理
void HummerBullet();	//コインの発射処理
void Hummerinterval();//コインの発射感覚
extern Hummer hummer[HUMMER_MAX];