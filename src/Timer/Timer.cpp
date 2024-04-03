#include "DxLib.h"
#include "Timer.h"


Timer::Timer()
{
	_x = 555;
	_y = 10;
	flameCount = 0;		//フレームのカウント
	print = 0;

	tensPlace = 0;		//十の位
	tensPlaceC = 0;		//十の位用のカウント変数
	oncePlace = 0;		//一の位
	oncePlaceC = 0;		//一の位用のカウント変数
}

void Timer::Init()
{
	flameCount = 0;		//フレームのカウント
	print = 0;			//表示用変数

	hundredsPlace = 0;
	hundredsPlaceC = 0;
	tensPlace = 0;		//十の位
	tensPlaceC = 0;		//十の位用のカウント変数
	oncePlace = 0;		//一の位
	oncePlaceC = 0;		//一の位用のカウント変数

	time120 = false;	//百の位を表示するか否か

	tensPlaceC = 2900;	//残り100フレーム回ったら十の位の3が2になる
}

//読み込み
void Timer::Load()
{
	LoadDivGraph(COUNT_NUMBER01, 10,10, 1, 100, 100, img100);//百の位担当
	LoadDivGraph(COUNT_NUMBER01, 10,10, 1, 100, 100, img10);//十の位担当
	LoadDivGraph(COUNT_NUMBER01, 10,10, 1, 100, 100, img01);//一の位担当
}



//処理
void Timer::CountDown()
{
	flameCount++;
	print = 30 - (flameCount / 100) % 1000; //ここで秒数を変更★★★

	//十の位
	tensPlaceC++;
	tensPlace = (tensPlaceC / 1000) % 1000;
	if (tensPlace > 9) {
		tensPlaceC = 0;
	}

	//一の位
	oncePlaceC++;
	oncePlace = (oncePlaceC / 100) % 1000;
	if (oncePlace > 9) {
		oncePlaceC = 0;
	}

	if (print == 0) {
		//g_time = SW_TIMEFIN;//SCENEID_FIN_PLAYに行く
	}
	
}

void Timer::Draw()
{	
	//(デバッグ用)
	//DrawFormatString(0, 200, GetColor(50, 0, 255), "カウント：%d", print, true);
	//DrawFormatString(400, 220, GetColor(50, 0, 255), "フレーム：%d", flameCount, true);

	//DrawFormatString(400, 200, GetColor(50, 0, 255), "oncePlace：%d", oncePlace, true);
	//DrawFormatString(400, 240, GetColor(50, 0, 255), "tensPlace：%d", tensPlace, true);



	//十の位
	DrawGraph(_x , _y, img10[tensPlace], true);

	//一の位
	DrawGraph(_x + 70 , _y, img01[oncePlace], true);

}

