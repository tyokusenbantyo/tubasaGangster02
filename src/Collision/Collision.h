#pragma once

//IsHitRect�̃v���g�^�C�v�錾
bool IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh);


//IsHitCircle�̃v���g�^�C�v�錾
bool IsHitCircle(int Ax, int Ay, int Ar, int Bx, int By, int Br);

// ��`�̓����蔻��
// xy���W�͍���̍��W
//bool IsHitRect(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2);