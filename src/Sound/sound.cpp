#include "DxLib.h"
#include "sound.h"



void Sound::InitPlay()
{
	//音
	for (int i = 0; i < ALL_SOUND; i++) {
		se[i] = { 0 };
	}

	//SE
	se[SE_DAMEGE] = LoadSoundMem("data/Sound/SEdamage.mp3");		//ダメージを受けたとき
	se[SE_HIT_COIN] = LoadSoundMem("data/Sound/coin03.mp3");		//コインにあったとき
	se[SE_OPEN_PARASOL] = LoadSoundMem("data/Sound/prasol_open.mp3");	//コインにあったとき
	
	se[SE_BIRD] = LoadSoundMem("data/Sound/Tombi.mp3");	//鳥　装飾
	se[SE_BIRD1] = LoadSoundMem("data/Sound/Warbler.mp3");	
	se[SE_WIND] = LoadSoundMem("data/Sound/gust of wind.mp3");	
	se[SE_WIND1] = LoadSoundMem("data/Sound/wind.mp3");	
}

void Sound::PlayMusic()
{
	//音量調整
	//ChangeVolumeSoundMem(255 * 50 / 100, bgm[B_SPRING]);
	//ChangeVolumeSoundMem(255 * 50 / 100, bgm[B_SUMMER]);
	//ChangeVolumeSoundMem(255 * 50 / 100, bgm[B_FALL]);
	//ChangeVolumeSoundMem(255 * 50 / 100, bgm[B_WINTER]);

}


void Sound::Fin()
{
	//SEの削除
	for (int i = 0; i < ALL_SOUND; i++) {
		StopSoundMem(se[i]);
		DeleteSoundMem(se[i]);
	}

}

