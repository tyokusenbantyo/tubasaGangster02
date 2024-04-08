#include"DxLib.h"
#include"parasol.h"
#include"../Cracter/Character.h"
#include"../Item/Coin/Coin.h"
Parasol parasol[CHARACTER_PARASOL_MAX];
int ParasolHandle[4];	//�摜�p�X������ϐ�
int parasolchaeng = 0;;	//�p���\����؂�ւ���
void Initparasol()	//������
{
	for (int i = 0; i < CHARACTER_PARASOL_MAX; i++)
	{
		parasol[i].x = 0;
		parasol[i].y = 0;
		parasol[i].parasolOpenFramecount = 0;
		parasol[i].parasolCloseFramecount = 0;
	}
	//ParasolHandle[0] = LoadGraph("data/02_Playimage/parasol.png");
	//ParasolHandle[1] = LoadGraph("data/02_Playimage/parasol2.png");
	//ParasolHandle[2] = LoadGraph("data/02_Playimage/parasol3.png");
	//ParasolHandle[3] = LoadGraph("data/02_Playimage/parasol4.png");
	
	ParasolHandle[0] = LoadGraph("data/02_Playimage/PPT1.png");
	ParasolHandle[1] = LoadGraph("data/02_Playimage/PPT2.png");
	ParasolHandle[2] = LoadGraph("data/02_Playimage/PPT3.png");
	ParasolHandle[3] = LoadGraph("data/02_Playimage/PPT4.png");
}
void Stepparasol()	//�L�����N�^�[�Ƀp���\����������
{
	for (int i = 0; i < CHARACTER_PARASOL_MAX; i++)
	{
		parasol[i].x = character[i].x+20;
		parasol[i].y = character[i].y;
	}
}
void Drawparasol()	//�p���\����`��
{
	for (int i = 0; i < CHARACTER_PARASOL_MAX; i++)
	{
		DrawFormatString(0, 300, GetColor(255, 0, 0), "Parasol time%d", parasol[i].parasolOpenFramecount); 

		if (character[i].parasol == true)	//�p���\�����J���Ă邩�m�F
		{
			//�t���[���J�E���g�ŉ摜��؂�ւ���
			if (parasol[i].parasolOpenFramecount == 0)
			{
				parasolchaeng = ParasolHandle[3];
			}
			if (parasol[i].parasolOpenFramecount == 1)
			{
				parasolchaeng = ParasolHandle[2];
			}
			if (parasol[i].parasolOpenFramecount == 2)
			{
				parasolchaeng = ParasolHandle[1];
			}
			if (parasol[i].parasolOpenFramecount == 3)
			{
				parasolchaeng = ParasolHandle[0];
			}
			if (parasol[i].parasolOpenFramecount <3)
			{
				parasol[i].parasolOpenFramecount++;
			}
			parasol[i].parasolCloseFramecount = 0;
			DrawRotaGraph(parasol[i].x, parasol[i].y, 1.0f, 0.0f, parasolchaeng, true);
		}
		if (character[i].parasol == false)	//�p���\�����J���Ă邩�m�F
		{
			//�t���[���J�E���g�ŉ摜��؂�ւ���
			if (parasol[i].parasolCloseFramecount == 0)
			{
				parasolchaeng = ParasolHandle[0];
			}
			if (parasol[i].parasolCloseFramecount == 1)
			{
				parasolchaeng = ParasolHandle[1];
			}
			if (parasol[i].parasolCloseFramecount == 2)
			{
				parasolchaeng = ParasolHandle[2];
			}
			if (parasol[i].parasolCloseFramecount == 3)
			{
				parasolchaeng = ParasolHandle[3];
			}
			if (parasol[i].parasolCloseFramecount < 3)
			{
				parasol[i].parasolCloseFramecount++;
			}
			parasol[i].parasolOpenFramecount = 0;
			DrawRotaGraph(parasol[i].x , parasol[i].y, 1.0f, 0.0f, parasolchaeng, true);
		}
	}
}