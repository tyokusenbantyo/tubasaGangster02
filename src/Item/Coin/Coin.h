#pragma once
#define COIN_MAX	(8)
struct Coin
{
	int x, y, h, w,handlePath,GravitySpeed,DrawFrameCount,
		bulletFrameCount;		//���ˊ��o��m���Ă�����;
	bool IsUse;
	bool BulletIinterval;
	bool oneJunp;				
};
void InitCoin();	//�R�C���̏�����
void DrawCoin();	//�R�C���̕`��
void CoinGravity();	//�R�C���̏d��
void coinMove();	//�R�C���̈ړ�����
void CoinBullet();	//�R�C���̔��ˏ���
void Coininterval();//�R�C���̔��ˊ��o
extern Coin coin[COIN_MAX];
