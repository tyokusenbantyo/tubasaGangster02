#pragma once
enum SE
{
	SE_ENTER,
	SE_DAMEGE,
	SE_HIT_COIN,
	SE_HIT_HAMMER,
	SE_OPEN_PARASOL,
	SE_CLOSE_PARASOL,
	SE_BIRD,
	SE_BIRD1,
	SE_WIND,
	SE_WIND1,

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

	 void InitPlay();	//playシーン専用の初期化
	 void PlayMusic();	//playシーン専用の再生関数
	 void Fin();
};


