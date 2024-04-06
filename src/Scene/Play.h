#pragma once
#include "../Timer/Timer.h"
class ScenePlay
{
private:
	//背景画像
	int BackGround[2];
	int Tuta[2];
	int BG_PosY[2];//背景画像の移動用変数
	int Tuta_PosY[2];//つた画像の移動用変数
	Timer timer;

public:

	ScenePlay();
	~ScenePlay();

	//初期化
	void Init();

	//通常処理
	void Step();

	//描画
	void Draw();

	//終了処理
	void Fin();
};
void Character_Hit_Coin();