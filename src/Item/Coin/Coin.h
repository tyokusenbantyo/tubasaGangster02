#pragma once
#define COIN_MAX	(1)
struct Coin
{
	int x, y, h, w,handle;
};
void InitCoin();	//�R�C���̏�����
void DrawCoin();	//�R�C���̕`��
extern Coin coin[COIN_MAX];