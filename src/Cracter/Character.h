#pragma once
#include "DxLib.h"
#define CHARACTER_PARASOL_MAX	(1)				//�v���C���[�̐l�������߂�
struct  Character
{
	int x,				//��
		y,				//�c
		h,	
		w,
		handleUP,			//�摜�n���h��
		handleDown,			//
		Gravity;		//�d��
	bool parasol;		
	
};
void InitCharacter();		//�L�����N�^�[�̏�����
void StepCharacter();		//�L�����N�^�[�̈ړ�����
void StepCharacterDraw();	//�L�����N�^�[�̕`�揈��
void StepCharacterGravity();//�L�����N�^�[�̏d�͏���
extern Character character[CHARACTER_PARASOL_MAX];