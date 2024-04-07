#pragma once
enum SE
{
	SE_ENTER,
	SE_DAMEGE,
	SE_HIT_COIN,
	SE_HIT_HAMMER,
	SE_OPEN_PARASOL,
	SE_CLOSE_PARASOL,
	ALL_SOUND,
};

enum BGM
{
	BGM_OP,
	BGM_PLAY,
	BGM_ED,

	BGM_ALL,
};

class Sound
{
public:
	 int se[ALL_SOUND];			//SE
	 int bgm[BGM_ALL];

	 bool istouch[2];
	 bool isSound[ALL_SOUND];

	 void InitTitle();		//全体の初期化
	 void InitPlay();	//playシーン専用の初期化
	 void InitResult();	//playシーン専用の初期化
	 void PlayMusic();	//playシーン専用の再生関数
	 void PlaySE();		//playシーン専用のアイテムSE
	 void Fin();
};


/*
・コインにあたった
・ハンマーにあ立った
・スペースキーを押した（画面遷移）
・パラソルを開いたラ　ふわふわ
・パラソルを閉じた　　ひゅーー
・時間切れ　　　　　　ぴぴー！

・タイトル画面BGM
・結果画面BGM
・遊び中BGM


	se[SE_ENTER] = LoadSoundMem("data/Sound/SE_enter.mp3");		//決定ボタン
	se[SE_DAMEGE] = LoadSoundMem("data/Sound/SE_enter.mp3");	//ダメージを受けたとき
	se[SE_HIT_COIN] = LoadSoundMem("data/Sound/SE_enter.mp3");	//コインにあったとき
	se[SE_HIT_HAMMER] = LoadSoundMem("data/Sound/SE_enter.mp3");	//コインにあったとき
	se[SE_OPEN_PARASOL] = LoadSoundMem("data/Sound/SE_enter.mp3");	//コインにあったとき
	se[SE_CLOSE_PARASOL] = LoadSoundMem("data/Sound/SE_enter.mp3");	//コインにあったとき

	bgm[BGM_OP] = LoadSoundMem("data/Sound/BGM_Winter.mp3");//冬
	bgm[BGM_PLAY] = LoadSoundMem("data/Sound/BGM_Winter.mp3");//冬
	bgm[BGM_ED] = LoadSoundMem("data/Sound/BGM_Winter.mp3");//冬



*/