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

	 void InitTitle();		//�S�̂̏�����
	 void InitPlay();	//play�V�[����p�̏�����
	 void InitResult();	//play�V�[����p�̏�����
	 void PlayMusic();	//play�V�[����p�̍Đ��֐�
	 void PlaySE();		//play�V�[����p�̃A�C�e��SE
	 void Fin();
};


/*
�E�R�C���ɂ�������
�E�n���}�[�ɂ�������
�E�X�y�[�X�L�[���������i��ʑJ�ځj
�E�p���\�����J�������@�ӂ�ӂ�
�E�p���\��������@�@�Ђ�[�[
�E���Ԑ؂�@�@�@�@�@�@�҂ҁ[�I

�E�^�C�g�����BGM
�E���ʉ��BGM
�E�V�ђ�BGM


	se[SE_ENTER] = LoadSoundMem("data/Sound/SE_enter.mp3");		//����{�^��
	se[SE_DAMEGE] = LoadSoundMem("data/Sound/SE_enter.mp3");	//�_���[�W���󂯂��Ƃ�
	se[SE_HIT_COIN] = LoadSoundMem("data/Sound/SE_enter.mp3");	//�R�C���ɂ������Ƃ�
	se[SE_HIT_HAMMER] = LoadSoundMem("data/Sound/SE_enter.mp3");	//�R�C���ɂ������Ƃ�
	se[SE_OPEN_PARASOL] = LoadSoundMem("data/Sound/SE_enter.mp3");	//�R�C���ɂ������Ƃ�
	se[SE_CLOSE_PARASOL] = LoadSoundMem("data/Sound/SE_enter.mp3");	//�R�C���ɂ������Ƃ�

	bgm[BGM_OP] = LoadSoundMem("data/Sound/BGM_Winter.mp3");//�~
	bgm[BGM_PLAY] = LoadSoundMem("data/Sound/BGM_Winter.mp3");//�~
	bgm[BGM_ED] = LoadSoundMem("data/Sound/BGM_Winter.mp3");//�~



*/