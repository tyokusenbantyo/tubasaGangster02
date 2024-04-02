#include "Collision.h"

//IsHitRect�̒�`
bool Collsion::IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh) {
	if (Bx < Ax + Aw &&
		Bx + Bw > Ax &&
		By + Bh > Ay &&
		By < Ay + Ah)
	{
		// �������Ă���Ƃ��̏���
		return true;
	}
	return false;
}

//IsHitCircle�̒�`
bool Collsion::IsHitCircle(int CircleAx, int CircleAy, int CircleAr, int CircleBx, int CircleBy, int CircleBr) {
	if ((CircleAr + CircleBr) * (CircleAr + CircleBr) >
		(CircleAx - CircleBx) * (CircleAx - CircleBx) + (CircleAy - CircleBy) * (CircleAy - CircleBy))
	{
		// �������Ă���Ƃ��̏���
		return true;
	}
	return false;
}

