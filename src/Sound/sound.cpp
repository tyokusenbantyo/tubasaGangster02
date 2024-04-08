#include "DxLib.h"
#include "sound.h"



void Sound::InitPlay()
{
	//��
	for (int i = 0; i < ALL_SOUND; i++) {
		se[i] = { 0 };
	}

	//SE
	se[SE_DAMEGE] = LoadSoundMem("data/Sound/SEdamage.mp3");		//�_���[�W���󂯂��Ƃ�
	se[SE_HIT_COIN] = LoadSoundMem("data/Sound/coin03.mp3");		//�R�C���ɂ������Ƃ�
	//se[SE_HIT_HAMMER] = LoadSoundMem("data/Sound/SE_enter.mp3");	//�R�C���ɂ������Ƃ�
	//se[SE_OPEN_PARASOL] = LoadSoundMem("data/Sound/SE_enter.mp3");	//�R�C���ɂ������Ƃ�
	//se[SE_CLOSE_PARASOL] = LoadSoundMem("data/Sound/SE_enter.mp3");	//�R�C���ɂ������Ƃ�
}

void Sound::PlayMusic()
{
	//���ʒ���
	//ChangeVolumeSoundMem(255 * 50 / 100, bgm[B_SPRING]);
	//ChangeVolumeSoundMem(255 * 50 / 100, bgm[B_SUMMER]);
	//ChangeVolumeSoundMem(255 * 50 / 100, bgm[B_FALL]);
	//ChangeVolumeSoundMem(255 * 50 / 100, bgm[B_WINTER]);

}


void Sound::Fin()
{
	//SE�̍폜
	for (int i = 0; i < ALL_SOUND; i++) {
		StopSoundMem(se[i]);
		DeleteSoundMem(se[i]);
	}

	//BGM�̍폜
	for (int i = 0; i < BGM_ALL; i++) {
		StopSoundMem(bgm[i]);
		DeleteSoundMem(bgm[i]);
	}

}

