#pragma once
#include "../Input/Input.h"
class SceneTitle
{
private:
	//背景画像
	int BackGround;

public:

	SceneTitle();
	~SceneTitle();
	//キーのクラスの宣言
	Input input;

	//初期化
	void Init();

	//通常処理
	void Step();

	//描画
	void Draw();

	//終了処理
	void Fin();
};