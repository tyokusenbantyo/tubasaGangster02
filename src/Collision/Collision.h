#pragma once
class Collsion{

public:
	//I‹éŒ`‚Ì‚ ‚½‚è”»’è
	static bool IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh);

	//‰~‚Ì‚ ‚½‚è”»’è
	static bool IsHitCircle(int CircleAx, int CircleAy, int CircleAr, int CircleBx, int CircleBy, int CircleBr);
};