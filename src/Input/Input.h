
#ifndef __INPUT_H__
#define __INPUT_H__

//���͐��䏉����
void InitInput();

//���͐���X�e�b�v
//����Step��葁���Ă�
void StepInput();

//�������ꂽ
bool IsKeyPush(int key_code);

//�����Ă��邩
bool IsKeyKeep(int key_code);

//�����ꂽ
bool IsKeyRelease(int key_code);

//�P���ɉ�����Ă��邩
bool IsKeyDown(int key_code);

#endif

