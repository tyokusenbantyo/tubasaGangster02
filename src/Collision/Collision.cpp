
#include"Collision.h"
//IsHitRect�̒�`��
bool IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh)
{
	if (Bx < Ax + Aw &&
		Bx + Bw > Ax &&
		By + Bh > Ay &&
		By < Ay + Ah)
	{
		return true;
	}
	return false;
}



//IsHitCircle�̒�`�~

bool IsHitCircle(int Ax, int Ay, int Ar, int Bx, int By, int Br)
{
	if ((Ar + Br) * (Ar + Br) >
		(Ax - Bx) * (Ax - Bx) + (Ay - By) * (Ay - By))
	{
		// �������Ă���Ƃ��̏���
		return true;
	}
	return false;
}

// ��`�̓����蔻��
// xy���W�͍���̍��W
//bool IsHitRect(float x1, float y1, float w1, float h1, float x2, float y2, float w2, float h2)
//{
//	if (x1 < x2 + w2 && x1 + w1 > x2 &&
//		y1 + h1 > y2 && y1 < y2 + h2)
//	{
//		return true;
//	}
//
//	return false;
//}

