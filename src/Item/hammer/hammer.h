#pragma once
#define HUMMER_MAX		(4)
struct Hummer
{
	int x, y, h, w, handlePath, GravitySpeed, DrawFrameCount,
		bulletFrameCount,		//���ˊ��o��m���Ă�����
		otosuFramecount;		//���Ƃ������̃t���[��y�J�E���g
	float razian = 0.0f;
	bool IsUse;
	bool BulletIinterval;	//���ˊ��o
	bool oneJunp;	//��񂾂��W�����v
	bool otosu;		//�n���}�[�Ɠ��������疳����藎�Ƃ�
};
void InitHummer();	//�R�C���̏�����
void DrawHummer();	//�R�C���̕`��
void HummerGravity();	//�R�C���̏d��
void HummerMove();	//�R�C���̈ړ�����
void HummerBullet();	//�R�C���̔��ˏ���
void Hummerinterval();//�R�C���̔��ˊ��o
extern Hummer hummer[HUMMER_MAX];