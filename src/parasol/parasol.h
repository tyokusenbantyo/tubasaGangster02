#pragma once
#define PARASOL_GAZOU	(4)		//�p���\���̖���
struct Parasol
{
	int x, y, handle,parasolFramecount;
};
void Initparasol();	//������
void Stepparasol();	//�p���\����������
void Drawparasol();	//�p���\����`��
extern int parasolchaeng;	//�p���\����؂�ւ���