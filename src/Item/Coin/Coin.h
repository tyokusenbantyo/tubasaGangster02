#pragma once
#define COIN_MAX	(1)
struct Coin
{
	int x, y, h, w,handlePath,GravitySpeed,DrawFrameCount;
	bool IsUse;
};
void InitCoin();	//�R�C���̏�����
void DrawCoin();	//�R�C���̕`��
void CoinGravity();	//�R�C���̏d��
void coinMove();	//�R�C���̈ړ�����
void CoinBullet();	//�R�C���̔��ˏ���
extern Coin coin[COIN_MAX];
