#include "Collision.h"

//IsHitRect‚Ì’è‹`
bool Collsion::IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh) {
	if (Bx < Ax + Aw &&
		Bx + Bw > Ax &&
		By + Bh > Ay &&
		By < Ay + Ah)
	{
		// “–‚½‚Á‚Ä‚¢‚é‚Æ‚«‚Ìˆ—
		return true;
	}
	return false;
}

//IsHitCircle‚Ì’è‹`
bool Collsion::IsHitCircle(int CircleAx, int CircleAy, int CircleAr, int CircleBx, int CircleBy, int CircleBr) {
	if ((CircleAr + CircleBr) * (CircleAr + CircleBr) >
		(CircleAx - CircleBx) * (CircleAx - CircleBx) + (CircleAy - CircleBy) * (CircleAy - CircleBy))
	{
		// “–‚½‚Á‚Ä‚¢‚é‚Æ‚«‚Ìˆ—
		return true;
	}
	return false;
}

