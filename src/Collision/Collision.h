#pragma once
class Collsion{

public:
	//I矩形のあたり判定
	static bool IsHitRect(int Ax, int Ay, int Aw, int Ah, int Bx, int By, int Bw, int Bh);

	//円のあたり判定
	static bool IsHitCircle(int CircleAx, int CircleAy, int CircleAr, int CircleBx, int CircleBy, int CircleBr);
};