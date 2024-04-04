#pragma once
#include "DxLib.h"
#include "../Input/Input.h"
#define CHARACTER_MAX	(1)				//プレイヤーの人数を決める
struct  Character
{
	int x,				//横
		y,				//縦
		h,	
		w,
		handle,			//画像ハンドル
		Gravity;		//重力
	bool parasol;
	
};
void InitCharacter();		//キャラクターの初期化
void StepCharacter();		//キャラクターの移動処理
void StepCharacterDraw();	//キャラクターの描画処理
void StepCharacterGravity();//キャラクターの重力処理
extern Character character[CHARACTER_MAX];