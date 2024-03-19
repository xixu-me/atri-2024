#include "StdAfx.h"
#include "StrategySystem.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CStrategySystem, CObject)

extern int nKick;
#define BALL_WIDTH 78
#define BALL_LENGTH 156
#define BALL_DIS 26
#define CORNER 115

#define ANGLE_BOUND 60
#define BOUND_BOUND 12
#define G_OFFSET 20
#define G_ANGLE_BOUND 60
#define G_BOUND_BOUND 10

// 罚球
// void CStrategySystem::Penalty() {
// 	srand(time(nullptr));
// 	int x = rand() % 2;
// 	// 简单直线函数点球，向上射终点为（60，313），向下射终点为（60，505）；
// 	int k, b;
// 	// 1往上射
// 	if (x) {
// 		k = (ball.position.y - 313) / (ball.position.x - 60);
// 		b = 313 - 60 * k;
// 		if (home1.position.x <= (ball.position.x + 16) && home1.position.x >= (ball.position.x + 16 - 1) && home1.position.y >= ((ball.position.x + 16) * k + b) - 1 && home1.position.y <= (ball.position.x + 16) * k + b)
// 			Direction(HOME1, ball.position); // 跟踪球射门
// 		else
// 			Position(HOME1, CPoint(ball.position.x + 16 /*球每次更新位置，则将机器人放到函数直线上与球不同位置上，下一周期在踢球*/, (ball.position.x + 16) * k + b)); // 机器人最开始不在范围，则移动到指定位置
// 	}
// 	// 往下射
// 	else {
// 		k = (ball.position.y - 505) / (ball.position.x - 60);
// 		b = 505 - 60 * k;
// 		if (home1.position.x <= (ball.position.x + 16) && home1.position.x >= (ball.position.x + 16) - 1 && home1.position.y >= ((ball.position.x + 16) * k + b) - 1 && home1.position.y <= (ball.position.x + 16) * k + b)
// 			Direction(HOME1, ball.position); // 跟踪球射门
// 		else
// 			Position(HOME1, CPoint(ball.position.x + 16, /*球每次更新位置，则将机器人放到函数直线上与球不同位置上，下一周期在踢球*/ (ball.position.x + 16) * k + b)); // 机器人最开始不在范围，则移动到指定位置
// 	}
// }

/*
void CStrategySystem::Penalty() {
	srand(time(nullptr));
	int x = rand() % 2;
	if (ball.position.y < 410) {
		if (Distance(home1.position, ball.position) > 15) {
			Position(HOME1, CPoint(28, 313));
		}
		else {
			Position(HOME1, CPoint(60, 313));
		}
	}
	else if (ball.position.y > 410) {
		if (Distance(home1.position, ball.position)>15) {
			Position(HOME1, CPoint(28, 505));
		}
		else {
			Position(HOME1, CPoint(60, 505));
		}
	}else if (ball.position.y == 410) {
		if (x) {
				Position(HOME1, CPoint(60, 313));
		}
		else {
				Position(HOME1, CPoint(60, 313));
		}
	}
}*/

/* void CStrategySystem::Penalty() {
	srand(time(nullptr));
	int x = rand() % 2;
	if (x) {
		if (Distance(home1.position, ball.position) > 15) {
			Position(HOME1, CPoint(28, 313));
		}
		else {
			Position(HOME1, CPoint(60, 313));
		}
	}
	else {
		if (Distance(home1.position, ball.position) > 15) {
			Position(HOME1, CPoint(28, 505));
		}
		else {
			Position(HOME1, CPoint(60, 505));
		}
	}
}*/

// void CStrategySystem::Penalty() {
// 	srand(time(nullptr));
// 	int x = rand() % 2;
// 	if (x) {
// 		Position(HOME1, CPoint(60, 313));
// 	}
// 	else {
// 		Position(HOME1, CPoint(60, 505));
// 	}
// }

// void CStrategySystem::Penalty() {
// 	if (home1.position.y < ball.position.y) {
// 		if (-home1.position.y != (-ball.position.y + 505) / (ball.position.x - 60) * (ball.position.x + 10) + (-505 - ((-ball.position.y + 505) / (ball.position.x - 60) * (ball.position.x + 10)))) {
// 			Position(HOME1, CPoint(ball.position.x + 10, -((-ball.position.y + 505) / (ball.position.x - 60) * (ball.position.x + 10) + (-505 - (-ball.position.y + 505) / (ball.position.x - 60) * (ball.position.x + 10)))));
// 		}
// 		Position(HOME1, CPoint(ball.position.x - 234, ball.position.y + 100));
// 	}
// 	else if (home1.position.y == ball.position.y) {
// 		Position(HOME1, CPoint(ball.position.x - 234, ball.position.y));
// 	}
// 	else {
// 		if (-home1.position.y != (-ball.position.y + 303) / (ball.position.x - 60) * (ball.position.x + 10) + (-303 - ((-ball.position.y + 303) / (ball.position.x - 60) * (ball.position.x + 10)))) {
// 			Position(HOME1, CPoint(ball.position.x - 234, -(-ball.position.y + 303) / (ball.position.x - 60) * (ball.position.x + 10) + (-303 - ((-ball.position.y + 303) / (ball.position.x - 60) * (ball.position.x + 10)))));
// 		}
// 		Position(HOME1, CPoint(ball.position.x - 234, ball.position.y + 100));
// 	}
// }

// void CStrategySystem::Penalty() {
// 	srand(time(nullptr));
// 	int x = rand() % 2;
// 	if (x) {
// 		if ((home1.position.x > ball.position.x + 24 + 1) || (home1.position.x < ball.position.x + 24 - 1) || (home1.position.y > ball.position.y + 10 + 1) || (home1.position.y > ball.position.y + 10 - 1)) {
// 			Position(HOME1, CPoint(ball.position.x + 24, ball.position.y + 10));
// 		}
// 		Position(HOME1, CPoint(ball.position.x - 233, ball.position.y - 97));
// 		// else {
// 		//	//Position(HOME1, CPoint(36.5, 313));
// 		//
// 		// }
// 	}
// 	else {
// 		if ((home1.position.x > ball.position.x + 24 + 1) || (home1.position.x < ball.position.x + 24 - 1) || (home1.position.y > ball.position.y - 10 + 1) || (home1.position.y > ball.position.y - 10 - 1)) {
// 			Position(HOME1, CPoint(ball.position.x + 24, ball.position.y - 10));
// 		}
// 		Position(HOME1, CPoint(ball.position.x - 228, ball.position.y + 95));
// 		// else {
// 		//	//Position(HOME1, CPoint(41.5, 505));
// 		// }
// 	}
// }

// void CStrategySystem::Penalty() {
// 	if (home1.position.y < ball.position.y) {
// 		Position(HOME1, CPoint(ball.position.x - 234, ball.position.y + 100));
// 	}
// 	else if (home1.position.y == ball.position.y) {
// 		Position(HOME1, CPoint(ball.position.x - 234, ball.position.y));
// 	}
// 	else {
// 		Position(HOME1, CPoint(ball.position.x - 234, ball.position.y - 100));
// 	}
// }

void CStrategySystem::Penalty() {
	srand(time(nullptr));
	int x = rand() % 2;
	int d = 21;
	static bool faceR;
	// Direction(HOME1, CPoint(ball.position.x + 104, ball.position.y));
	if (x) {
		if (Distance(home1.position, ball.position) > d) {
			Direction(HOME1, ball.position);
			faceR = fabs(home1.angle) > 90;
		}
		else {
			// flag = false;
			double r = Distance(home1.position, ball.position) / (2 * (sin(atwo(home1.pos.x, home1.pos.y, ball.position.x, ball.position.y, ball.position.x, ball.position.y, 28, 505)))); // 求曲线行驶时轨迹的半径
			int lw = (r - 3) / (r + 5) * 127;
			if (faceR)
				Velocity(1, lw, 127);
			else
				Velocity(1, -127, -lw);
		}
	}
	else {
		if (Distance(home1.position, ball.position) > d) {
			Direction(HOME1, ball.position);
			faceR = fabs(home1.angle) > 90;
		}
		else {
			// flag = false;
			double r = Distance(home1.position, ball.position) / (2 * (sin(atwo(home1.pos.x, home1.pos.y, ball.position.x, ball.position.y, ball.position.x, ball.position.y, 28, 313))));
			int rw = r / (r + 3) * 127;
			if (!faceR)
				Velocity(1, -rw, -127);
			else
				Velocity(1, 127, rw);
		}
	}
	Direction(HOME2, ball.position);
	Direction(HOME3, ball.position);
	Direction(HOME4, ball.position);
	Direction(HOME5, ball.position);
	Direction(HOME6, ball.position);
	Direction(HOME7, ball.position);
	Direction(HOME8, ball.position);
	Direction(HOME9, ball.position);
	Direction(HOME10, ball.position);
}

// 争球
void CStrategySystem::Freeball() {
	// 要实现先直冲，在曲线的话，就要加一个标识符标识此时的状态，当距离不足时标识符为1，距离够时标识符变为0，并且在争球结束后变为1
	// 感觉防御的话就直冲判断比较简单粗暴，毕竟目标是拦截，而不是射门，
	static bool faceR;
	int d = 25;
	if (Status() == 2) { // 左上
		Direction(HOME3, ball.position);
	}
	else if (Status() == 3) { // 左下
		Direction(HOME1, ball.position);
	}
	/* if (Status() == 2) { // 左上
	   if (Distance(home3.position, ball.position) > d && flag) {
		   Direction(HOME3, CPoint(ball.position.x,ball.position.y-6));
		   faceR = fabs(home3.angle) > 90;
	   }
	   else {
		   flag = false;
		   double r = Distance(home3.position, ball.position) / (2 * (sin(atwo(home3.pos.x, home3.pos.y, ball.position.x, ball.position.y, ball.position.x, ball.position.y, 28, 605)))); // 求曲线行驶时轨迹的半径
		   int lw = (r-5) / (r +8) * 127;
			if (faceR)
			   Velocity(3, lw, 127);
		   else
			   Velocity(3, -127, -lw);
	   }
	   Direction(HOME1, ball.position);
	   Direction(HOME2, ball.position);
	   Direction(HOME4, ball.position);
	   Direction(HOME5, ball.position);
	   Direction(HOME6, ball.position);
	   Direction(HOME7, ball.position);
	   Direction(HOME8, ball.position);
	   Direction(HOME9, ball.position);
	   Direction(HOME10, ball.position);
	}

	else if (Status() == 3) { // 左下
	   if (Distance(home1.position, ball.position) > d && flag) {
		   Direction(HOME1, ball.position);
		   faceR = fabs(home1.angle) > 90;
	   }
	   else {
		   flag = false;
		   double r = Distance(home1.position, ball.position) / (2 * (sin(atwo(home1.pos.x, home1.pos.y, ball.position.x, ball.position.y, ball.position.x, ball.position.y, 28, 213))));
		   int rw = (r - 5) / (r + 8) * 127;
		   if (!faceR)
			   Velocity(1, -rw, -127);
		   else
			   Velocity(1, 127, rw);
	   }
	   Direction(HOME2, ball.position);
	   Direction(HOME3, ball.position);
	   Direction(HOME4, ball.position);
	   Direction(HOME5, ball.position);
	   Direction(HOME6, ball.position);
	   Direction(HOME7, ball.position);
	   Direction(HOME8, ball.position);
	   Direction(HOME9, ball.position);
	   Direction(HOME10, ball.position);
   }*/
	else if (Status() == 4) { // 右上
		Direction(HOME10, ball.position);
	}
	/*else if (Status() == 4) { // 右上
		if (Distance(home10.position, ball.position) > d && flag) {
			Direction(HOME10, ball.position);
			faceR = fabs(home10.angle) > 90;
		}
		else {
			flag = false;
			double r = Distance(home10.position, ball.position) / (2 * (sin(atwo(home10.pos.x, home10.pos.y, ball.position.x, ball.position.y, ball.position.x, ball.position.y, 515, 95))));
			int rw = (r - 5) / (r + 5) * 127;
			if (faceR)
				Velocity(10, -rw, -127);
			else
				Velocity(10, 127, rw);
		}
		Direction(HOME1, ball.position);
		Direction(HOME2, ball.position);
		Direction(HOME3, ball.position);
		Direction(HOME4, ball.position);
		Direction(HOME5, ball.position);
		Direction(HOME6, ball.position);
		Direction(HOME7, ball.position);
		Direction(HOME8, ball.position);
		Direction(HOME9, ball.position);
	} */
	/* else if (Status() == 5) { // 右下
	   if (Distance(home7.position, ball.position) > d && flag) {
		   Direction(HOME7, ball.position);
		   faceR = fabs(home7.angle) > 90;
	   }
	   else {
		   flag = false;
		   double r = Distance(home7.position, ball.position) / (2 * (sin(atwo(home7.pos.x, home7.pos.y, ball.position.x, ball.position.y, ball.position.x, ball.position.y, 515, 723))));
		   int lw = (r - 8) / (r + 5) * 127;
		   if (faceR)
			   Velocity(7, -127, -lw);
		   else
			   Velocity(7, lw, 127);
	   }
	   Direction(HOME1, ball.position);
	   Direction(HOME2, ball.position);
	   Direction(HOME3, ball.position);
	   Direction(HOME4, ball.position);
	   Direction(HOME5, ball.position);
	   Direction(HOME6, ball.position);
	   Direction(HOME8, ball.position);
	   Direction(HOME9, ball.position);
	   Direction(HOME10, ball.position);
   }*/
	else if (Status() == 5) { // 右下//也许还有其它改进的思路，但实在南蚌
		Direction(HOME7, ball.position);
	}
	else // 这个标识符判断的问题到底咋搞，放在这的话应该是要在action函数里把freeball函数一直调用，如果要把还原放在action函数的话就要再不是争球的情况下都还原
		flag = 1;
	Direction(HOME1, ball.position);
	Direction(HOME2, ball.position);
	Direction(HOME4, ball.position);
	Direction(HOME5, ball.position);
	Direction(HOME6, ball.position);
	Direction(HOME7, ball.position);
	Direction(HOME8, ball.position);
	Direction(HOME9, ball.position);
	Direction(HOME10, ball.position);
}

// 两直线间夹角
double CStrategySystem::atwo(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) {
	double j = 0;
	double k1 = (y1 - y2) / (x1 - x2);
	double k2 = (y3 - y4) / (x3 - x4);
	j = atan(fabs((k2 - k1) / (1 + k1 * k2)));
	return j;
}

// void CStrategySystem::spin(int which, bool isClockwise) { // 自旋
// 	if (isClockwise)
// 		Velocity(which, 127, -127);
// 	else
// 		Velocity(which, -127, 127);
// }

// 控球
// void CStrategySystem::Possession() {
// navigate();
/*for(int i=1;i<11;i++)
{
	Navigation[i]=ball.position;
}*/

// if (ball.position.x < 290) {
// 	Canshot();
// 	for (int i = 1; i < 9; i++) {
// 	control(i);
// }
// }
// else
// 	for (int i = 1; i < 11; i++) {
// 		control(i);
// 	}

// bool a, b;
// if (ball.position.y >= 337 && ball.position.x < 290) // 球在敌方下半
// {
// 	if ((ball.position.y >= 481 && ball.position.y <= 607) || (ball.position.x - ball.oldPosition.x <= 5 && ball.position.y - ball.oldPosition.y <= 5) && search1() < 4) // 7可射
// 		shot(7, 1);																																						 // 7射
// 	else
// 		control(7);

// 	if (Distance(ball.position, home2.position) <= 75) // 2可射
// 	{
// 		control(1); // 1
// 		if (search1() < 4)
// 			shot(HOME2, 1); // 2射
// 		else
// 			control(2);
// 		for (int i = 3; i < 7; i++) // 3-6
// 			control(i);
// 		control(1);		// 8
// 		if (!canshot()) // 9，10
// 		{
// 			control(9);
// 			control(10);
// 		}
// 	}
// 	else if (Distance(ball.position, home3.position) <= 75 && ball.position.y <= 481 && ball.position.y >= 505) // 3可射
// 	{
// 		control(1); // 1
// 		control(2); // 2
// 		if (search1() < 4)
// 			shot(HOME3, 0); // 3射
// 		else
// 			control(3);
// 		for (int i = 4; i < 7; i++) // 4-6
// 			control(i);
// 		control(8);		// 8
// 		if (!canshot()) // 9，10
// 		{
// 			control(9);
// 			control(10);
// 		}
// 	}
// 	else							 // 其它情况
// 		for (int i = 1; i < 11; i++) // 1-10
// 			control(i);
// }
// else if (ball.position.y < 481 && ball.position.x < 290) // 球在敌方上半
// {
// 	if ((ball.position.y >= 217 && ball.position.y <= 337) || (ball.position.x - ball.oldPosition.x <= 5 && ball.position.y - ball.oldPosition.y <= 5) && search1() < 4) // 8可射
// 		shot(8, 0);
// 	else
// 		control(8);
// 	if (Distance(ball.position, home3.position) <= 75) // 3可射
// 	{
// 		control(1); // 1
// 		control(2); // 2
// 		if (search1() < 4)
// 			shot(HOME3, 0); // 3射
// 		else
// 			control(3);
// 		for (int i = 4; i < 7; i++) // 4-6
// 			control(i);
// 		control(HOME7); // 7
// 		if (!canshot()) // 9，10
// 		{
// 			control(9);
// 			control(10);
// 		}
// 	}
// 	else if (Distance(ball.position, home2.position) <= 75 && ball.position.y >= 313 && ball.position.y <= 337) // 2可射
// 	{

// 		control(1); // 1
// 		if (search1() < 4)
// 			shot(2, 0); // 2射
// 		else
// 			control(2);
// 		control(HOME3);				// 3
// 		for (int i = 4; i < 7; i++) // 4-6
// 			control(i);
// 		control(HOME7); // 7
// 		if (!canshot()) // 9，10
// 		{
// 			control(9);
// 			control(10);
// 		}
// 	}
// 	else							 // 其它情况
// 		for (int i = 1; i < 11; i++) // 1-10
// 			control(i);
// }
// else							 // 其它情况
// 	for (int i = 1; i < 11; i++) // 1-10
// 		control(i);
//}

// 控球具体实现
void CStrategySystem::Possession() {
	CPoint pos[10];
	RelPos rp[10];
	CPoint cur_pos[10]{ home1.position, home2.position, home3.position, home4.position, home5.position, home6.position, home7.position, home8.position, home9.position, home10.position };

	if (cp_id()) {
		pos[0] = cur_pos[cp_id() - 1];

		for (int i = 0; i < 10; i++) {
			if (rp[i].id == fm_id() - 1) {
				rp[i].ang = 0;
				rp[i].dis = 0;
			}
			else {
				rp[i].ang = atan2(cur_pos[i].y - pos[0].y, cur_pos[i].x - pos[0].x);
				rp[i].dis = Distance(cur_pos[i], pos[0]);
			}
		}

		// 孙徐
		if (fm_id() == 1) {
			Direction(cp_id(), ball.position);

			pos[1] = CPoint(pos[0].x, pos[0].y - 10);
			pos[2] = CPoint(pos[0].x + 10, pos[0].y - 10);
			pos[3] = CPoint(pos[0].x + 10, pos[0].y);
			pos[6] = CPoint(pos[0].x + 20, pos[0].y);
			pos[4] = CPoint(pos[0].x + 10, pos[0].y + 10);
			pos[7] = CPoint(pos[0].x + 20, pos[0].y + 10);
			pos[5] = CPoint(pos[0].x + 10, pos[0].y + 20);
			pos[8] = CPoint(170, 409);
			pos[9] = CPoint(170, 556);

			fp_sort(rp);
			fp_sort(rp, 0, 5);
			Direction(rp[0].id, pos[1]);
			Direction(rp[1].id, pos[2]);
			Direction(rp[2].id, pos[3]);
			Direction(rp[3].id, pos[4]);
			Direction(rp[4].id, pos[5]);
			fp_sort(rp, 5, 7);
			Direction(rp[5].id, pos[6]);
			Direction(rp[6].id, pos[7]);
			Direction(rp[7].id, pos[8]);
			Direction(rp[8].id, pos[9]);
		}
		else if (fm_id() == 2) {
			Direction(cp_id(), ball.position);

			pos[1] = CPoint(pos[0].x, pos[0].y + 10);
			pos[2] = CPoint(pos[0].x + 10, pos[0].y + 10);
			pos[3] = CPoint(pos[0].x + 10, pos[0].y);
			pos[6] = CPoint(pos[0].x + 20, pos[0].y);
			pos[4] = CPoint(pos[0].x + 10, pos[0].y - 10);
			pos[7] = CPoint(pos[0].x + 20, pos[0].y - 10);
			pos[5] = CPoint(pos[0].x + 10, pos[0].y - 20);
			pos[8] = CPoint(170, 409);
			pos[9] = CPoint(170, 265);

			fp_sort(rp);
			fp_sort(rp, 0, 5);
			Direction(rp[5].id, pos[1]);
			Direction(rp[4].id, pos[2]);
			Direction(rp[3].id, pos[3]);
			Direction(rp[2].id, pos[4]);
			Direction(rp[1].id, pos[5]);
			fp_sort(rp, 5, 7);
			Direction(rp[7].id, pos[6]);
			Direction(rp[6].id, pos[7]);
			Direction(rp[7].id, pos[8]);
			Direction(rp[8].id, pos[9]);
		}
		else if (fm_id() == 3) {
			// if (ball.position.x >= 157 && ball.position.x <= 290 && ball.position.y <= 409)
			// 	shot(cp_id(), 0, CPoint(45, 457));
			// else if (ball.position.x >= 157 && ball.position.x <= 290 && ball.position.y > 409)
			// 	shot(cp_id(), 0, CPoint(45, 361));
			// else
			// 	Direction(cp_id(), CPoint(170, ball.position.y));

			if (ball.position.x >= 157 && ball.position.x <= 290 && ball.position.y <= 409) {
				// 内圈
				pos[1] = CPoint(pos[0].x - 15, pos[0].y - 40);
				pos[2] = CPoint(pos[0].x + 15, pos[0].y - 40);
				pos[3] = CPoint(pos[0].x + 40 * cos(30), pos[0].y - 40 * sin(30));
				pos[4] = CPoint(pos[0].x + 40 * cos(30), pos[0].y + 40 * sin(40));
				pos[5] = CPoint(pos[0].x + 15, pos[0].y + 40);
				pos[6] = CPoint(pos[0].x - 15, pos[0].y + 40);
				// 内圈
				pos[7] = CPoint(pos[0].x + 120 * cos(67.5), pos[0].y - 120 * sin(67.5));
				pos[8] = CPoint(pos[0].x + 120 * cos(45), pos[0].y - 120 * sin(45));
				pos[9] = CPoint(pos[0].x + 120 * cos(22.5), pos[0].y - 120 * sin(22.5));
				shot(cp_id(), 0, CPoint(45, 361));
			}
			else if (ball.position.x >= 157 && ball.position.x <= 290 && ball.position.y > 409) {
				// 内圈
				pos[1] = CPoint(pos[0].x - 15, pos[0].y - 40);
				pos[2] = CPoint(pos[0].x + 15, pos[0].y - 40);
				pos[3] = CPoint(pos[0].x + 40 * cos(30), pos[0].y - 40 * sin(30));
				pos[4] = CPoint(pos[0].x + 40 * cos(30), pos[0].y + 40 * sin(40));
				pos[5] = CPoint(pos[0].x + 15, pos[0].y + 40);
				pos[6] = CPoint(pos[0].x - 15, pos[0].y + 40);
				// 内圈
				pos[7] = CPoint(pos[0].x + 120 * cos(67.5), pos[0].y + 120 * sin(67.5));
				pos[8] = CPoint(pos[0].x + 120 * cos(45), pos[0].y + 120 * sin(45));
				pos[9] = CPoint(pos[0].x + 120 * cos(22.5), pos[0].y + 120 * sin(22.5));
				shot(cp_id(), 0, CPoint(45, 457));
			}
			else if (ball.position.x < 157 && ball.position.y >= 217 && ball.position.y <= 409) // 球在上半
			{
				pos[1] = CPoint(142, pos[0].y - 20);
				pos[2] = CPoint(142, pos[0].y + 20);

				pos[3] = CPoint(170, pos[0].y - 20);
				pos[4] = CPoint(170, pos[0].y + 20);
				pos[5] = CPoint(185, pos[0].y - 12);
				if (pos[0].y - 50 < 157)
					pos[6] = CPoint(ball.position.x + 12, 225);
				else
					pos[6] = CPoint(170, pos[0].y - 50);
				pos[7] = CPoint(ball.position.x, 225);
				pos[8] = CPoint(170, pos[0].y + 45);
				pos[9] = CPoint(170, pos[0].y + 405);
				shot(cp_id(), 0);
			}
			else if (ball.position.x < 157 && ball.position.y >= 217 && ball.position.y > 409) // 球在下半
			{
				pos[1] = CPoint(142, pos[0].y - 20);
				pos[2] = CPoint(142, pos[0].y + 20);

				pos[3] = CPoint(170, pos[0].y - 20);
				pos[4] = CPoint(170, pos[0].y + 20);
				pos[5] = CPoint(185, pos[0].y + 12);
				if (pos[0].y + 50 > 607)
					pos[6] = CPoint(ball.position.x + 12, 615);
				else
					pos[6] = CPoint(170, pos[0].y + 50);
				pos[7] = CPoint(ball.position.x, 615);
				pos[8] = CPoint(170, pos[0].y - 45);
				pos[9] = CPoint(170, pos[0].y - 405);
				shot(cp_id(), 1);
			}
			struct infor a[11];
			for (int i = 1; i <= 10; i++) {
				a[i].num = i;
				Robot2 *robot;
				switch (i) {
				case HOME1:
					robot = &home1;
					break;
				case HOME2:
					robot = &home2;
					break;
				case HOME3:
					robot = &home3;
					break;
				case HOME4:
					robot = &home4;
					break;
				case HOME5:
					robot = &home5;
					break;
				case HOME6:
					robot = &home6;
					break;
				case HOME7:
					robot = &home7;
					break;
				case HOME8:
					robot = &home8;
					break;
				case HOME9:
					robot = &home9;
					break;
				case HOME10:
					robot = &home10;
					break;
				case HGOALIE:
					robot = &hgoalie;
					break;
				}
				a[i].dis = Distance(ball.position, robot->position);
			}
			for (int i = 1; i <= 10; i++) {
				for (int j = i + 1; j <= 10; j++) {
					if (a[i].dis > a[j].dis) {
						struct infor t;
						t = a[i];
						a[i] = a[j];
						a[j] = t;
					}
				}
			}
			for (int i = 1; i <= 10; i++)
				if (a[i].num != cp_id())
					Direction(a[i].num, pos[i - 1]);
		}

		// 王徐
		else if (fm_id() == 4) {
			Direction(cp_id(), ball.position);

			pos[1] = CPoint(ball.position.x + (int)cos(45.0 * PI / 180.0) * 20, ball.position.y + (int)sin(45.0 * PI / 180.0) * 20);
			pos[2] = CPoint(ball.position.x + (int)cos(90.0 * PI / 180.0) * 20, ball.position.y + (int)sin(90.0 * PI / 180.0) * 20);
			pos[3] = CPoint(pos[0].x + (int)cos(0.0 * PI / 180.0) * 40, pos[0].y + (int)sin(0.0 * PI / 180.0) * 40);
			pos[4] = CPoint(pos[0].x + (int)cos(15.0 * PI / 180.0) * 40, pos[0].y + (int)sin(15.0 * PI / 180.0) * 40);
			pos[5] = CPoint(pos[0].x + (int)cos(30.0 * PI / 180.0) * 40, pos[0].y + (int)sin(30.0 * PI / 180.0) * 40);
			pos[6] = CPoint(pos[0].x + (int)cos(45.0 * PI / 180.0) * 40, pos[0].y + (int)sin(45.0 * PI / 180.0) * 40);
			pos[7] = CPoint(pos[0].x + (int)cos(50.0 * PI / 180.0) * 60, pos[0].y + (int)sin(50.0 * PI / 180.0) * 60);
			pos[8] = CPoint(pos[0].x + (int)cos(60.0 * PI / 180.0) * 60, pos[0].y + (int)sin(60.0 * PI / 180.0) * 60);
			pos[9] = CPoint(pos[0].x + (int)cos(75.0 * PI / 180.0) * 60, pos[0].y + (int)sin(75.0 * PI / 180.0) * 60);

			double d[10], dy[10];
			CPoint cur_pos[10]{ home1.position, home2.position, home3.position, home4.position, home5.position, home6.position, home7.position, home8.position, home9.position, home10.position };
			for (int i = 0; i <= 9; i++) {
				if (i == cp_id() - 1) {
					d[i] = 1e5;
				}
				else {
					d[i] = Distance(cur_pos[i], cur_pos[cp_id() - 1]);
				}
			}
			int p1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			for (int i = 1; i <= 10; i++) {
				for (int j = 0; j < 10 - i; j++) {
					if (d[j] > d[j + 1]) {
						int tmp = d[j];
						d[j] = d[j + 1];
						d[j + 1] = tmp;
						tmp = p1[j];
						p1[j] = p1[j + 1];
						p1[j + 1] = tmp;
					}
				}
			}
			Direction(p1[0], pos[0]);
			Direction(p1[1], pos[1]);
			for (int i = 0; i <= 9; i++) {
				if (i == cp_id() - 1) {
					dy[i] = 1e5;
				}
				else {
					dy[p1[i]] = 217 - cur_pos[i].y;
				}
			}
			dy[p1[0]] = 1e5;
			dy[p1[1]] = 1e5;
			int p2[10] = { p1[0], p1[1], p1[2], p1[3], p1[4], p1[5], p1[6], p1[7], p1[8], p1[9] };
			for (int i = 1; i <= 10; i++) {
				for (int j = 0; j < 10 - i; j++) {
					if (dy[j] > dy[j + 1]) {
						int tmp = d[j];
						dy[j] = dy[j + 1];
						dy[j + 1] = tmp;
						tmp = p2[j];
						p2[j] = p2[j + 1];
						p2[j + 1] = tmp;
					}
				}
			}
			Direction(p2[0], pos[9]);
			Direction(p2[1], pos[8]);
			Direction(p2[2], pos[7]);
			Direction(p2[3], pos[6]);
			Direction(p2[4], pos[5]);
			Direction(p2[5], pos[4]);
			Direction(p2[6], pos[3]);
		}
		else if (fm_id() == 5) {
			Direction(cp_id(), ball.position);

			pos[1] = CPoint(ball.position.x + (int)cos(0.0 * PI / 180.0) * 20, ball.position.y + (int)sin(0.0 * PI / 180.0) * 20);
			pos[2] = CPoint(ball.position.x + (int)cos(-90.0 * PI / 180.0) * 20, ball.position.y + (int)sin(-90.0 * PI / 180.0) * 20);
			pos[3] = CPoint(pos[0].x + (int)cos(0.0 * PI / 180.0) * 40, pos[0].y + (int)sin(0.0 * PI / 180.0) * 40);
			pos[4] = CPoint(pos[0].x + (int)cos(-15.0 * PI / 180.0) * 40, pos[0].y + (int)sin(-15.0 * PI / 180.0) * 40);
			pos[5] = CPoint(pos[0].x + (int)cos(-30.0 * PI / 180.0) * 40, pos[0].y + (int)sin(-30.0 * PI / 180.0) * 40);
			pos[6] = CPoint(pos[0].x + (int)cos(-45.0 * PI / 180.0) * 40, pos[0].y + (int)sin(6 - 45.0 * PI / 180.0) * 40);
			pos[7] = CPoint(pos[0].x + (int)cos(-50.0 * PI / 180.0) * 60, pos[0].y + (int)sin(-50.0 * PI / 180.0) * 60);
			pos[8] = CPoint(pos[0].x + (int)cos(-60.0 * PI / 180.0) * 60, pos[0].y + (int)sin(-60.0 * PI / 180.0) * 60);
			pos[9] = CPoint(pos[0].x + (int)cos(-75.0 * PI / 180.0) * 60, pos[0].y + (int)sin(-75.0 * PI / 180.0) * 60);

			double d[10], dy[10]; // dy是球员新的
			CPoint cur_pos[10]{ home1.position, home2.position, home3.position, home4.position, home5.position, home6.position, home7.position, home8.position, home9.position, home10.position };
			for (int i = 0; i <= 9; i++) {
				if (i == cp_id() - 1) {
					d[i] = 1e5;
				}
				else {
					d[i] = Distance(cur_pos[i], cur_pos[cp_id() - 1]);
				}
			}
			int p1[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 }; // p1是球员新下标
			for (int i = 1; i <= 10; i++) {
				for (int j = 0; j < 10 - i; j++) {
					if (d[j] > d[j + 1]) {
						// 根据球员与中心球员距离，按从小到大排列距离
						int tmp = d[j];
						d[j] = d[j + 1];
						d[j + 1] = tmp;

						// 距离交换后，下标同时交换
						tmp = p1[j];
						p1[j] = p1[j + 1];
						p1[j + 1] = tmp;
					}
				}
			}
			Direction(p1[0], pos[0]);
			Direction(p1[1], pos[1]);
			for (int i = 0; i <= 9; i++) {
				if (i == cp_id() - 1) {
					dy[i] = 1e5;
				}
				else {
					dy[p1[i]] = cur_pos[i].y - 607;
				}
			}
			dy[p1[0]] = 1e5;
			dy[p1[1]] = 1e5;
			// p2
			int p2[10] = { p1[0], p1[1], p1[2], p1[3], p1[4], p1[5], p1[6], p1[7], p1[8], p1[9] };
			for (int i = 1; i <= 10; i++) {
				for (int j = 0; j < 10 - i; j++) {
					if (dy[j] > dy[j + 1]) {
						int tmp = d[j];
						dy[j] = dy[j + 1];
						dy[j + 1] = tmp;

						// 距离交换后，下标同时交换
						tmp = p2[j];
						p2[j] = p2[j + 1];
						p2[j + 1] = tmp;
					}
				}
			}
			Direction(p2[0], pos[9]);
			Direction(p2[1], pos[8]);
			Direction(p2[2], pos[7]);
			Direction(p2[3], pos[6]);
			Direction(p2[4], pos[5]);
			Direction(p2[5], pos[4]);
			Direction(p2[6], pos[3]);
		}
		else if (fm_id() == 6) {
			Direction(cp_id(), ball.position);

			pos[1] = CPoint(ball.position.x + (int)cos(-90.0 * PI / 180.0) * 20, ball.position.y + (int)sin(-90.0 * PI / 180.0) * 20);
			pos[2] = CPoint(ball.position.x + (int)cos(90.0 * PI / 180.0) * 20, ball.position.y + (int)sin(90.0 * PI / 180.0) * 20);
			pos[5] = CPoint(pos[0].x + (int)cos(45.0 * PI / 180.0) * 40, pos[0].y + (int)sin(45.0 * PI / 180.0) * 40);
			pos[3] = CPoint(pos[0].x + (int)cos(-45.0 * PI / 180.0) * 40, pos[0].y + (int)sin(-45.0 * PI / 180.0) * 40);
			pos[4] = CPoint(pos[0].x + (int)cos(0.0 * PI / 180.0) * 40, pos[0].y + (int)sin(0.0 * PI / 180.0) * 40);
			pos[9] = CPoint(pos[0].x + (int)cos(60.0 * PI / 180.0) * 60, pos[0].y + (int)sin(60.0 * PI / 180.0) * 60);
			pos[6] = CPoint(pos[0].x + (int)cos(-60.0 * PI / 180.0) * 60, pos[0].y + (int)sin(-60.0 * PI / 180.0) * 60);
			pos[8] = CPoint(pos[0].x + (int)cos(30.0 * PI / 180.0) * 60, pos[0].y + (int)sin(30.0 * PI / 180.0) * 60);
			pos[7] = CPoint(pos[0].x + (int)cos(-30.0 * PI / 180.0) * 60, pos[0].y + (int)sin(-30.0 * PI / 180.0) * 60);

			/*fp_sort(rp);
			fp_sort(rp, 0, 2);
			Direction(rp[0].id, pos[1]);
			Direction(rp[1].id, pos[2]);
			fp_sort(rp, 2, 5);
			Direction(rp[2].id, pos[3]);
			Direction(rp[3].id, pos[4]);
			Direction(rp[4].id, pos[5]);
			fp_sort(rp, 5, 9);
			Direction(rp[5].id, pos[6]);
			Direction(rp[6].id, pos[7]);
			Direction(rp[7].id, pos[8]);
			Direction(rp[8].id, pos[9]);*/

			int d[10];
			CPoint cur_pos[10]{ home1.position, home2.position, home3.position, home4.position, home5.position, home6.position, home7.position, home8.position, home9.position, home10.position };
			for (int i = 0; i <= 9; i++) {
				if (i == cp_id() - 1) {
					d[i] = 1e5;
				}
				d[i] = cur_pos[i].x - cur_pos[cp_id() - 1].x;
			}
			int p[10] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9 };
			for (int i = 1; i <= 10; i++) {
				int j;
				for (j = 0; j < 10 - i; j++) {
					if (d[j] > d[j + 1]) {
						int tmp = d[j];
						d[j] = d[j + 1];
						d[j + 1] = tmp;
						tmp = p[j];
						p[j] = p[j + 1];
						p[j + 1] = tmp;
					}
				}
			}
			for (int i = 0; i <= 9; i++) {
				if (p[i] = cp_id() - 1)
					continue;
				Direction(p[i], pos[i + 1]);
			}
		}

		// 景缪
		else if (fm_id() == 7) {
			Direction(cp_id(), ball.position);

			if (ball.position.x > 873) {
				pos[1] = CPoint(pos[0].x + 3, pos[0].y - 3);
				pos[2] = CPoint(pos[0].x + 1, pos[0].y + 5);
				pos[3] = CPoint(pos[0].x + 5, pos[0].y + 20);
				pos[4] = CPoint(pos[0].x, pos[0].y + 20);
				pos[5] = CPoint(pos[0].x - 10, pos[0].y + 20);
				pos[6] = CPoint(pos[0].x - 20, pos[0].y + 20);
				pos[7] = CPoint(896, 217);
				pos[8] = CPoint(919, 217);
				pos[9] = CPoint(942, 217);
			}
			else {
				pos[1] = CPoint(pos[0].x + 3, pos[0].y - 5);
				pos[2] = CPoint(pos[0].x + 3, pos[0].y + 5);
				pos[6] = CPoint(pos[0].x - 15, pos[0].y + 10);
				pos[5] = CPoint(pos[0].x - 10, pos[0].y + 5);
				pos[4] = CPoint(pos[0].x - 5, pos[0].y + 10);
				pos[3] = CPoint(pos[0].x, pos[0].y + 10);
				int n1 = 643 > ball.position.x ? 623 : ball.position.x;
				int n2 = 733 > ball.position.x ? 733 : ball.position.x;
				pos[7] = CPoint(n1, 217);
				pos[8] = CPoint(n2, 217);
				pos[9] = CPoint(939, 217);
			}

			fp_sort(rp);
			fp_sort(rp, 0, 2);
			Direction(rp[0].id, pos[1]);
			Direction(rp[1].id, pos[2]);
			fp_sort(rp, 2, 6);
			Direction(rp[2].id, pos[3]);
			Direction(rp[3].id, pos[4]);
			Direction(rp[4].id, pos[5]);
			Direction(rp[5].id, pos[6]);
			fp_sort(rp, 6, 9);
			Direction(rp[6].id, pos[7]);
			Direction(rp[7].id, pos[8]);
			Direction(rp[8].id, pos[9]);

			// double adou[15];
			// int xz[15];
			// int n = 1;
			// xz[n] = cp_id();
			// int pp[15];
			// for (int i = 1; i <= 9; i++) // 按角度从小到大排序，然后最小的占据点位，并且后续将已分配的记名，不参与接下来的分配
			// {
			// 	for (int u = 1; u <= 10; u++) {
			// 		Robot2 *robot;
			// 		switch (u) {
			// 		case HOME1:
			// 			robot = &home1;
			// 			break;
			// 		case HOME2:
			// 			robot = &home2;
			// 			break;
			// 		case HOME3:
			// 			robot = &home3;
			// 			break;
			// 		case HOME4:
			// 			robot = &home4;
			// 			break;
			// 		case HOME5:
			// 			robot = &home5;
			// 			break;
			// 		case HOME6:
			// 			robot = &home6;
			// 			break;
			// 		case HOME7:
			// 			robot = &home7;
			// 			break;
			// 		case HOME8:
			// 			robot = &home8;
			// 			break;
			// 		case HOME9:
			// 			robot = &home9;
			// 			break;
			// 		case HOME10:
			// 			robot = &home10;
			// 			break;
			// 		}
			// 		adou[u] = atwo(robot->position.x, robot->position.y, ball.position.x, ball.position.y, pos[i].x, pos[i].y, ball.position.x, ball.position.y); // 先将值赋给adou
			// 		pp[u] = u;
			// 	}

			// 	// 然后求adou里最小的，给pos[1]的坐标，并将球员号计入xz中
			// 	for (int u = 1; u <= 10; u++)
			// 		for (int j = u + 1; j <= 10; j++)
			// 			if (adou[u] > adou[j]) {
			// 				double t;
			// 				int m;
			// 				m = pp[u];
			// 				pp[u] = pp[j];
			// 				pp[j] = m;
			// 				t = adou[u];
			// 				adou[u] = adou[j];
			// 				adou[j] = t;
			// 			}
			// 	for (int u = 1; u <= 10; u++) {
			// 		int o = 0;
			// 		for (int j = 1; j <= n; j++) {
			// 			if (pp[u] == xz[j]) // 是记录人员
			// 			{
			// 				break;
			// 			}
			// 			if (j == n) // 不是记录人员
			// 			{
			// 				Direction(pp[u], pos[i]);
			// 				n++;
			// 				xz[n] = pp[u];
			// 				o = 1;
			// 			}
			// 		}
			// 		if (o == 1)
			// 			break;
			// 	}
			// }
			// // if (Distance(pos[i], ball.position)<5)
			// //	PositionSE(pos[i], ball.position); // 在这个阵型这个点位处的球员就击球
			// // 否则就保持一定速度在点位待机
		}
		else if (fm_id() == 8) {
			Direction(cp_id(), ball.position);

			if (ball.position.x > 873) {
				pos[1] = CPoint(pos[0].x + 3, pos[0].y + 3);
				pos[2] = CPoint(pos[0].x + 1, pos[0].y - 5);
				pos[3] = CPoint(pos[0].x + 5, pos[0].y - 20);
				pos[4] = CPoint(pos[0].x, pos[0].y - 20);
				pos[5] = CPoint(pos[0].x - 10, pos[0].y - 20);
				pos[6] = CPoint(pos[0].x - 20, pos[0].y - 20);
				pos[7] = CPoint(896, 608);
				pos[8] = CPoint(919, 608);
				pos[9] = CPoint(942, 608);
			}
			else {
				pos[1] = CPoint(pos[0].x + 3, pos[0].y + 5);
				pos[2] = CPoint(pos[0].x + 3, pos[0].y - 5);
				pos[6] = CPoint(pos[0].x - 15, pos[0].y - 10);
				pos[5] = CPoint(pos[0].x - 10, pos[0].y - 5);
				pos[4] = CPoint(pos[0].x - 5, pos[0].y - 10);
				pos[3] = CPoint(pos[0].x, pos[0].y - 10);
				int n1 = 643 > ball.position.x ? 643 : ball.position.x;
				int n2 = 733 > ball.position.x ? 733 : ball.position.x;
				pos[7] = CPoint(n1, 608);
				pos[8] = CPoint(n2, 608);
				pos[9] = CPoint(939, 608);
			}

			fp_sort(rp);
			fp_sort(rp, 0, 2);
			Direction(rp[0].id, pos[1]);
			Direction(rp[1].id, pos[2]);
			fp_sort(rp, 2, 6);
			Direction(rp[2].id, pos[3]);
			Direction(rp[3].id, pos[4]);
			Direction(rp[4].id, pos[5]);
			Direction(rp[5].id, pos[6]);
			fp_sort(rp, 6, 9);
			Direction(rp[6].id, pos[7]);
			Direction(rp[7].id, pos[8]);
			Direction(rp[8].id, pos[9]);
			// double adou[15];
			// int xz[15];
			// int n = 1;
			// xz[n] = cp_id();
			// int pp[15];
			// for (int i = 1; i <= 9; i++) // 按角度从小到大排序，然后最小的占据点位，并且后续将已分配的记名，不参与接下来的分配
			// {

			// 	for (int u = 1; u <= 10; u++) {
			// 		Robot2 *robot;
			// 		switch (u) {
			// 		case HOME1:
			// 			robot = &home1;
			// 			break;
			// 		case HOME2:
			// 			robot = &home2;
			// 			break;
			// 		case HOME3:
			// 			robot = &home3;
			// 			break;
			// 		case HOME4:
			// 			robot = &home4;
			// 			break;
			// 		case HOME5:
			// 			robot = &home5;
			// 			break;
			// 		case HOME6:
			// 			robot = &home6;
			// 			break;
			// 		case HOME7:
			// 			robot = &home7;
			// 			break;
			// 		case HOME8:
			// 			robot = &home8;
			// 			break;
			// 		case HOME9:
			// 			robot = &home9;
			// 			break;
			// 		case HOME10:
			// 			robot = &home10;
			// 			break;
			// 		}
			// 		adou[u] = atwo(robot->position.x, robot->position.y, ball.position.x, ball.position.y, pos[i].x, pos[i].y, ball.position.x, ball.position.y); // 先将值赋给adou
			// 		pp[u] = u;
			// 	}
			// 	// 然后求adou里最小的，给pos[1]的坐标，并将球员号计入xz中
			// 	for (int u = 1; u <= 10; u++)
			// 		for (int j = u + 1; j <= 10; j++)
			// 			if (adou[u] > adou[j]) {
			// 				double t;
			// 				int m;
			// 				m = pp[u];
			// 				pp[u] = pp[j];
			// 				pp[j] = m;
			// 				t = adou[u];
			// 				adou[u] = adou[j];
			// 				adou[j] = t;
			// 			}
			// 	for (int u = 1; u <= 10; u++) {
			// 		int o = 0;
			// 		for (int j = 1; j <= n; j++) {
			// 			if (pp[u] == xz[j]) // 是记录人员
			// 			{
			// 				break;
			// 			}
			// 			if (j == n) // 不是记录人员
			// 			{
			// 				Direction(pp[u], pos[i]);
			// 				n++;
			// 				xz[n] = pp[u];
			// 				o = 1;
			// 			}
			// 		}
			// 		if (o == 1)
			// 			break;
			// 	}
			// }
			// // if (Distance(pos[i], ball.position)<5)
			// //	PositionSE(pos[i], ball.position);//在这个阵型这个点位处的球员就击球
			// //  否则就保持一定速度在点位待机
		}
		else if (fm_id() == 9) {
			Direction(cp_id(), ball.position);

			pos[1].y = ball.position.y;
			pos[1].x = 900;
			pos[2].x = pos[1].x;
			if (ball.position.y > 409) // 球在下面
			{
				pos[2].y = pos[1].y - 40;
			}
			else if (ball.position.y <= 409) // 球在上面
			{
				pos[2].y = pos[1].y + 40;
			}
			if (ball.position.x < 873) // 球在禁区外
			{
				pos[3].x = ball.position.x;
				pos[3].y = ball.position.y + 55; // 球下面
				pos[4].x = ball.position.x;
				pos[4].y = ball.position.y - 55; // 球上面
				if (ball.position.x < 850) {
					pos[5].x = ball.position.x + 20;
					pos[5].y = ball.position.y; // 正对球
				}
				else {
					pos[5].x = 870;
					pos[5].y = ball.position.y; // 正对球
				}
				pos[6].x = 870;
				pos[6].y = ball.position.y + 50;
				pos[7].x = 870;
				pos[7].y = ball.position.y - 50;
				pos[8].x = 870;
				pos[8].y = ball.position.y + 65;
				pos[9].x = 870;
				pos[9].y = ball.position.y - 65;
			}
			else if (ball.position.x > 873) // 球在禁区里,球员不进禁区
			{
				pos[3].x = 870;
				pos[3].y = ball.position.y + 50; // 球下面
				pos[4].x = 870;
				pos[4].y = ball.position.y - 50; // 球上面
				pos[5].x = pos[1].x - 80;
				pos[5].y = ball.position.y; // 正对球
				if (ball.position.y > 409)	// 球在下面
				{
					pos[6].x = 900;
					pos[6].y = 610;
					pos[7].x = pos[5].x;
					pos[7].y = pos[5].y - 70;
					pos[8].x = pos[5].x;
					pos[8].y = pos[5].y + 70;
					pos[9].x = 870;
					pos[9].y = ball.position.y - 100;
				}
				if (ball.position.y <= 409) // 球在下面
				{
					pos[6].x = 900;
					pos[6].y = 210;
					pos[7].x = pos[5].x;
					pos[7].y = pos[5].y - 70;
					pos[8].x = pos[5].x;
					pos[8].y = pos[5].y + 70;
					pos[9].x = 870;
					pos[9].y = ball.position.y + 100;
				}

				struct infor a[10];
				Robot2 *robot;
				for (int j = 1; j <= 9; j++) {
					for (int i = 1; i <= 9; i++) {
						a[i].num = i;
						a[i].dis = -1;
						switch (i) {
						case HOME1:
							robot = &home1;
							break;
						case HOME2:
							robot = &home2;
							break;
						case HOME3:
							robot = &home3;
							break;
						case HOME4:
							robot = &home4;
							break;
						case HOME5:
							robot = &home5;
							break;
						case HOME6:
							robot = &home6;
							break;
						case HOME7:
							robot = &home7;
							break;
						case HOME8:
							robot = &home8;
							break;
						case HOME9:
							robot = &home9;
							break;
						case HOME10:
							robot = &home10;
							break;
						}
						if (a[i].dis == -1)
							a[i].dis = Distance(pos[j], robot->position); // 机器人到点位的距离
					}
					int min = a[1].dis;
					int p = 1;					 // 最近的球员编号
					for (int l = 2; l <= 9; l++) // 选出最近的机器人
					{
						if (min <= a[l].dis) {
							a[l].dis = -1;
						}
						else {
							min = a[l].dis;
							a[p].dis = -1;
							p = l;
						}
					}
					if (a[p].num != cp_id())		  // 不是中心球员
						PositionSE(a[p].num, pos[j]); // 移动到最近的点位
				}
			}
		}
	}
	else { // TODO 无中央球员
		if (fm_id() == 4 || fm_id() == 6) {
			pos[0] = CPoint(ball.position.x + (int)cos(0 * PI / 180) * 40, ball.position.y + (int)sin(20 * PI / 180) * 40);
			pos[1] = CPoint(ball.position.x + (int)cos(45.0 * PI / 180.0) * 20, ball.position.y + (int)sin(45.0 * PI / 180.0) * 20);
			pos[2] = CPoint(ball.position.x + (int)cos(90.0 * PI / 180.0) * 20, ball.position.y + (int)sin(90.0 * PI / 180.0) * 20);
			pos[3] = CPoint(pos[0].x + (int)cos(0.0 * PI / 180.0) * 40, pos[0].y + (int)sin(0.0 * PI / 180.0) * 40);
			pos[4] = CPoint(pos[0].x + (int)cos(15.0 * PI / 180.0) * 40, pos[0].y + (int)sin(15.0 * PI / 180.0) * 40);
			pos[5] = CPoint(pos[0].x + (int)cos(30.0 * PI / 180.0) * 40, pos[0].y + (int)sin(30.0 * PI / 180.0) * 40);
			pos[6] = CPoint(pos[0].x + (int)cos(45.0 * PI / 180.0) * 40, pos[0].y + (int)sin(45.0 * PI / 180.0) * 40);
			pos[7] = CPoint(pos[0].x + (int)cos(50.0 * PI / 180.0) * 60, pos[0].y + (int)sin(50.0 * PI / 180.0) * 60);
			pos[8] = CPoint(pos[0].x + (int)cos(60.0 * PI / 180.0) * 60, pos[0].y + (int)sin(60.0 * PI / 180.0) * 60);
			pos[9] = CPoint(pos[0].x + (int)cos(75.0 * PI / 180.0) * 60, pos[0].y + (int)sin(75.0 * PI / 180.0) * 60);

			fp_sort(rp);
			fp_sort(rp, 0, 3);
			Direction(rp[0].id, pos[0]);
			Direction(rp[1].id, pos[1]);
			Direction(rp[2].id, pos[2]);
			fp_sort(rp, 3, 6);
			Direction(rp[3].id, pos[3]);
			Direction(rp[4].id, pos[4]);
			Direction(rp[5].id, pos[5]);
			fp_sort(rp, 6, 10);
			Direction(rp[6].id, pos[6]);
			Direction(rp[7].id, pos[7]);
			Direction(rp[8].id, pos[8]);
			Direction(rp[9].id, pos[9]);
		}
		else if (fm_id() == 5) {
			pos[0] = CPoint(ball.position.x + (int)cos(0 * PI / 180) * 40, ball.position.y - (int)sin(20 * PI / 180) * 40);
			pos[1] = CPoint(ball.position.x + (int)cos(0.0 * PI / 180.0) * 20, ball.position.y + (int)sin(0.0 * PI / 180.0) * 20);
			pos[2] = CPoint(ball.position.x + (int)cos(-90.0 * PI / 180.0) * 20, ball.position.y + (int)sin(-90.0 * PI / 180.0) * 20);
			pos[3] = CPoint(pos[0].x + (int)cos(0.0 * PI / 180.0) * 40, pos[0].y + (int)sin(0.0 * PI / 180.0) * 40);
			pos[4] = CPoint(pos[0].x + (int)cos(-15.0 * PI / 180.0) * 40, pos[0].y + (int)sin(-15.0 * PI / 180.0) * 40);
			pos[5] = CPoint(pos[0].x + (int)cos(-30.0 * PI / 180.0) * 40, pos[0].y + (int)sin(-30.0 * PI / 180.0) * 40);
			pos[6] = CPoint(pos[0].x + (int)cos(-45.0 * PI / 180.0) * 40, pos[0].y + (int)sin(-45.0 * PI / 180.0) * 40);
			pos[7] = CPoint(pos[0].x + (int)cos(-50.0 * PI / 180.0) * 60, pos[0].y + (int)sin(-50.0 * PI / 180.0) * 60);
			pos[8] = CPoint(pos[0].x + (int)cos(-60.0 * PI / 180.0) * 60, pos[0].y + (int)sin(-60.0 * PI / 180.0) * 60);
			pos[9] = CPoint(pos[0].x + (int)cos(-75.0 * PI / 180.0) * 60, pos[0].y + (int)sin(-75.0 * PI / 180.0) * 60);

			fp_sort(rp);
			fp_sort(rp, 0, 3);
			Direction(rp[0].id, pos[0]);
			Direction(rp[1].id, pos[1]);
			Direction(rp[2].id, pos[2]);
			fp_sort(rp, 3, 6);
			Direction(rp[3].id, pos[3]);
			Direction(rp[4].id, pos[4]);
			Direction(rp[5].id, pos[5]);
			fp_sort(rp, 6, 10);
			Direction(rp[6].id, pos[6]);
			Direction(rp[7].id, pos[7]);
			Direction(rp[8].id, pos[8]);
			Direction(rp[9].id, pos[9]);
		}
	}
}

// 搜索最近球员位置
// CPoint CStrategySystem::searchNear(int which) {
//	CPoint cur_pos[10]{ home1.position, home2.position, home3.position, home4.position, home5.position, home6.position, home7.position, home8.position, home9.position, home10.position };
//	double ddd = 10000;
//	CPoint near;
//	for (int i = 0; i < 10; i++) {
//		if (Distance(cur_pos[i], ball.position) < ddd) {
//			ddd = Distance(cur_pos[i], ball.position);
//			near = cur_pos[i];
//		}
//	}
//	return near;
// }

// 中央球员 ID
int CStrategySystem::cp_id() {
	int id = 0;
	CPoint cur_pos[10]{ home1.position, home2.position, home3.position, home4.position, home5.position, home6.position, home7.position, home8.position, home9.position, home10.position };
	if (fm_id() == 1) {
		for (int i = 0; i < 10; i++) {
			if (cur_pos[i].y >= ball.position.y)
				cur_pos[i] = CPoint(-965, -723);
		}
		double min = 10000;
		for (int i = 0; i < 10; i++) {
			if (Distance(cur_pos[i], ball.position) < min) {
				min = Distance(cur_pos[i], ball.position);
				id = i + 1;
			}
		}
	}
	else if (fm_id() == 2) {
		for (int i = 0; i < 10; i++) {
			if (cur_pos[i].y <= ball.position.y)
				cur_pos[i] = CPoint(-965, -723);
		}
		double min = 10000;
		for (int i = 0; i < 10; i++) {
			if (Distance(cur_pos[i], ball.position) < min) {
				min = Distance(cur_pos[i], ball.position);
				id = i + 1;
			}
		}
	}
	else if (fm_id() == 7) {
		for (int i = 0; i < 10; i++) {
			if (cur_pos[i].y <= ball.position.y)
				cur_pos[i] = CPoint(-965, -723);
		}
		double min = 10000;
		for (int i = 0; i < 10; i++) {
			if (Distance(cur_pos[i], ball.position) < min) {
				min = Distance(cur_pos[i], ball.position);
				id = i + 1;
			}
		}
	}
	else if (fm_id() == 8) {
		for (int i = 0; i < 10; i++) {
			if (cur_pos[i].y >= ball.position.y)
				cur_pos[i] = CPoint(-965, -723);
		}
		double min = 10000;
		for (int i = 0; i < 10; i++) {
			if (Distance(cur_pos[i], ball.position) < min) {
				min = Distance(cur_pos[i], ball.position);
				id = i + 1;
			}
		}
	}
	else if (fm_id() == 3) {
		if (ball.position.x >= 157 && ball.position.x <= 290) {
			for (int i = 0; i < 10; i++) {
				if (cur_pos[i].x < ball.position.x)
					cur_pos[i] = CPoint(-965, -723);
			}
			double min = 10000;
			for (int i = 0; i < 10; i++) {
				if (Distance(cur_pos[i], ball.position) < min) {
					min = Distance(cur_pos[i], ball.position);
					id = i + 1;
				}
			}
		}
		else if (ball.position.x >= 65 && ball.position.x < 157) // 球在禁区用y轴最近
		{
			double min = 10000;
			for (int i = 0; i < 10; i++) {
				if (cur_pos[i].x < ball.position.x)
					cur_pos[i] = CPoint(-965, -723);
			}
			for (int i = 0; i < 10; i++) {
				if (fabs(ball.position.y - cur_pos[i].y) < min) {
					min = fabs(ball.position.y - cur_pos[i].y);
					id = i + 1;
				}
			}
		}
	}
	else {
		for (int i = 0; i < 10; i++) {
			if (cur_pos[i].x <= ball.position.x)
				cur_pos[i] = CPoint(-965, -723);
		}
		double min = 10000;
		for (int i = 0; i < 10; i++) {
			if (Distance(cur_pos[i], ball.position) < min) {
				min = Distance(cur_pos[i], ball.position);
				id = i + 1;
			}
		}
	}
	return id;
}

// 阵型 ID
int CStrategySystem::fm_id() {
	if (ball.position.x < 290) {
		if (ball.position.y < 217)
			return 1;
		else if (ball.position.y <= 607)
			return 3;
		else
			return 2;
	}
	else if (ball.position.x < 740) {
		if (ball.position.y < 217)
			return 4;
		else if (ball.position.y <= 607)
			return 6;
		else
			return 5;
	}
	else {
		if (ball.position.y < 217)
			return 7;
		else if (ball.position.y <= 607)
			return 9;
		else
			return 8;
	}
}

// 阵型球员相对中央球员的位置结构体
// struct RelPos {
// 	int id;
// 	double dis;
// 	double ang;  // (-π, π]
// };

// 阵型球员排序，h 为该层前的球员数量，t 为包含该层后的球员数量
void CStrategySystem::fp_sort(RelPos *rp, int h, int t) {
	RelPos r;
	if (!h && !t) {
		for (int i = 1; i < 10; i++) {
			for (int j = 0; j < 10 - i; j++) {
				if (rp[j].dis > rp[j + 1].dis) {
					r = rp[j], rp[j] = rp[j + 1], rp[j + 1] = r;
				}
			}
		}
	}
	else {
		for (int i = h + 1; i < t; i++) {
			for (int j = h; j < t - i; j++) {
				if (rp[j].ang > rp[j + 1].ang) {
					r = rp[j], rp[j] = rp[j + 1], rp[j + 1] = r;
				}
			}
		}
	}
}

// 返回机器人的位置
CPoint CStrategySystem::coor(int which) {
	Robot2 *robot;
	switch (which) {
	case HOME1:
		robot = &home1;
		break;
	case HOME2:
		robot = &home2;
		break;
	case HOME3:
		robot = &home3;
		break;
	case HOME4:
		robot = &home4;
		break;
	case HOME5:
		robot = &home5;
		break;
	case HOME6:
		robot = &home6;
		break;
	case HOME7:
		robot = &home7;
		break;
	case HOME8:
		robot = &home8;
		break;
	case HOME9:
		robot = &home9;
		break;
	case HOME10:
		robot = &home10;
		break;
	case HGOALIE:
		robot = &hgoalie;
		break;
	}
	return robot->position;
}

// 0向下门框射
void CStrategySystem::shot(int which, bool de) {
	Robot2 *robot;
	switch (which) {
	case HOME1:
		robot = &home1;
		break;
	case HOME2:
		robot = &home2;
		break;
	case HOME3:
		robot = &home3;
		break;
	case HOME4:
		robot = &home4;
		break;
	case HOME5:
		robot = &home5;
		break;
	case HOME6:
		robot = &home6;
		break;
	case HOME7:
		robot = &home7;
		break;
	case HOME8:
		robot = &home8;
		break;
	case HOME9:
		robot = &home9;
		break;
	case HOME10:
		robot = &home10;
		break;
	case HGOALIE:
		robot = &hgoalie;
		break;
	}
	double O, O1;
	CPoint t1, t2, t3, t4; // t1球，t2机器人,t3机器人要移动到的点，t4门
	t1.x = ball.position.x;
	t1.y = ball.position.y;
	if (de == 0) {
		t4.x = 33.0;
		t4.y = 505.0;
		O = atan(fabs(ball.position.y - t4.y) / fabs(ball.position.x - t4.x)); // fabs(Angle(,t4));
		O1 = 180 - O;
		t3.x = t1.x + cos(O) * 34;
		t3.y = t1.y - sin(O) * 34;
	}
	else if (de == 1) {
		t4.x = 33.0;
		t4.y = 313.0;
		O = atan(fabs(ball.position.y - t4.y) / fabs(ball.position.x - t4.x)); // fabs(Angle(ball.position,t4));
		O1 = 180 + O;
		t3.x = t1.x + cos(O) * 34;
		t3.y = t1.y + sin(O) * 34;
	}
	if (Distance(robot->position, ball.position) <= 35 && (fabs(Angle(ball.position, t3) - Angle(robot->position, t3))) <= 2) {
		if (de == 1) {
			t3.x = t1.x - cos(O) * 34;
			t3.y = t1.y - sin(O) * 34;
			Direction(which, t3);
		}
		else if (de == 0) {
			t3.x = t1.x - cos(O) * 34;
			t3.y = t1.y + sin(O) * 34;
			Direction(which, t3);
		}
	}
	else
		Position(which, t3); // 机器人到足够近的点t3
}

// 射？
bool CStrategySystem::canshot() {
	bool t; // 判断球在敌方上半还是下半；0为下半
	CPoint D1, D2, t4;
	Robot2 *robot9, *robot10;
	robot9 = &home9;
	robot10 = &home10;
	// if (ball.position.y >= 409 && ball.position.x <= 290&&ball.position.y<=607) // 球在敌方下半
	// {
	// 	t = 0;
	// 	D1.x = 170;
	// 	D1.y = 265;
	// 	Position(HOME10, D1);
	// 	D2.x = 170;
	// 	D2.y = 409;
	// 	Position(HOME9, D2);
	// }
	// else if (ball.position.y < 409 && ball.position.x < 290 && ball.position.y >= 217 && Distance(ball.position, home10.position) > 168) // 球在敌方上半
	// {
	// 	t = 1;
	// 	D1.x = 170;
	// 	D1.y = 556;
	// 	Position(HOME10, D1);
	// 	D2.x = 170;
	// 	D2.y = 409;
	// 	Position(HOME9, D2);
	// 	if (ball.position.x >= 104 && ball.position.x <= 170 && ball.position.y >= 313 && ball.position.y <= 449 && (ball.oldPosition.y - ball.oldPosition.y) <= 0)
	// 		Shot(HOME9, 1);
	// 	if (ball.position.x >= 104 && ball.position.x <= 170 && ball.position.y > 449 && ball.position.y <= 607 && (ball.oldPosition.y - ball.oldPosition.y) <= 0)
	// 		Shot(HOME10, 1);
	// }
	if (ball.position.y <= 481) // 敌方框上半场
	{
		D1.x = 170;
		D1.y = 265;
		D2.x = 170;
		D2.y = 409;
		if (Distance(ball.position, home9.position) <= 116 && ball.position.y >= 409 && ball.position.y <= 481) // 9可射
		{
			shot(HOME9, 0);
			Direction(HOME10, D1);
		}
		else if (Distance(ball.position, home10.position) <= 168 && ball.position.y < 409 && ball.position.y >= 265) // 10可射
		{
			Direction(HOME9, D2);
			shot(HOME10, 0);
		}
		else { // 9，10到预定位置
			Direction(HOME10, D1);
			Direction(HOME9, D2);
		}
		return 1;
	}
	else if (ball.position.y >= 337) // 敌方框下半场
	{
		D1.x = 170;
		D1.y = 556;
		D2.x = 170;
		D2.y = 409;
		if (Distance(ball.position, home9.position) <= 116 && ball.position.y <= 409 && ball.position.y >= 337) // 9可射
		{
			shot(HOME9, 1);
			Direction(HOME10, D1);
		}
		else if (Distance(ball.position, home10.position) <= 164 && ball.position.y > 409 && ball.position.y <= 556) // 10可射
		{
			Direction(HOME9, D2);
			shot(HOME10, 1);
		}
		else { // 9，10到预定位置
			Direction(HOME10, D1);
			Direction(HOME9, D2);
		}
		return 1;
	}
	return 0;
	// if ()
	// {
	// 	if (ball.position.y <= 170) {
	// 		Position(HOME10, D1);
	// 		Shot(HOME9, 0);
	// 	}
	// 	else if (ball.position.y >= 170) {
	// 		Position(HOME9, D2);
	// 		Shot(HOME10, 0);
	// 	}
	// }
	// else {
	// 	Position(HOME10, D1);
	// 	Position(HOME9, D2);
	// }
}

// 把球向t点射,de向上还是向下射
void CStrategySystem::shot(int which, bool de, CPoint t) {
	Robot2 *robot;
	switch (which) {
	case HOME1:
		robot = &home1;
		break;
	case HOME2:
		robot = &home2;
		break;
	case HOME3:
		robot = &home3;
		break;
	case HOME4:
		robot = &home4;
		break;
	case HOME5:
		robot = &home5;
		break;
	case HOME6:
		robot = &home6;
		break;
	case HOME7:
		robot = &home7;
		break;
	case HOME8:
		robot = &home8;
		break;
	case HOME9:
		robot = &home9;
		break;
	case HOME10:
		robot = &home10;
		break;
	case HGOALIE:
		robot = &hgoalie;
		break;
	}
	double O;
	CPoint t1, t2, t3; // t1球，t2机器人,t3机器人要移动到的点
	t1.x = ball.position.x;
	t1.y = ball.position.y;
	if (de == 0) {
		O = atan(fabs(ball.position.y - t.y) / fabs(ball.position.x - t.x));
		if (ball.position.x <= 515) {
			t3.x = t1.x + cos(O) * 34;
			t3.y = t1.y - sin(O) * 34;
		}
		else {
			t3.x = t1.x - cos(O) * 34;
			t3.y = t1.y - sin(O) * 34;
		}
	}
	else if (de == 1) {
		O = atan(fabs(ball.position.y - t.y) / fabs(ball.position.x - t.x)); // fabs(Angle(ball.position,t4));
		if (ball.position.x <= 515) {
			t3.x = t1.x + cos(O) * 34;
			t3.y = t1.y + sin(O) * 34;
		}
		else {
			t3.x = t1.x - cos(O) * 34;
			t3.y = t1.y + sin(O) * 34;
		}
	}
	if (Distance(robot->position, ball.position) <= 35 && (fabs(Angle(ball.position, t3) - Angle(robot->position, t3))) <= 2) {
		if (de == 1) {
			t3.x = t1.x - cos(O) * 34;
			t3.y = t1.y - sin(O) * 34;
			Direction(which, t3);
		}
		else if (de == 0) {
			t3.x = t1.x - cos(O) * 34;
			t3.y = t1.y + sin(O) * 34;
			Direction(which, t3);
		}
	}
	else
		Position(which, t3); // 机器人到足够近的点t3
}

// 直射
void CStrategySystem::shot1(int which, double o, CPoint t) {
	Robot2 *robot;
	switch (which) {
	case HOME9:
		robot = &home9;
		break;
	case HOME1:
		robot = &home1;
		break;
	}
	bool a = 0;
	/*if((fabs(Angle(ball.position, t) - Angle(robot->position, t))) > 5)*/
	Angle(which, o);
	Velocity(which, 127, 127); // which全速前进
}

/*void banarea(int which)  //让9，10不进禁区
{
	Robot2 *robot;
	switch (which) {
	case HOME9:
		robot = &home9;
		break;
	case HOME10:
		robot = &home10;
		break;
	}
	CPoint t1, t2;//t1球
	t1.x = ball.position.x;
	t1.y = ball.position.y;
	t2.x = robot->position.x;
	t2.y = robot->position.y;
	if((t1.x>=65&&1.x<=103&&t1.y>=247&&t1.y<=577)||(t2.x+1==))
}*/

// void CStrategySystem::navigate() // 给人要去的位置坐标导航（预判）
// {
// 	CPoint robot[11];
// 	robot[1] = home1.position;
// 	robot[2] = home2.position;
// 	robot[3] = home3.position;
// 	robot[4] = home4.position;
// 	robot[5] = home5.position;
// 	robot[6] = home6.position;
// 	robot[7] = home7.position;
// 	robot[8] = home8.position;
// 	robot[9] = home9.position;
// 	robot[10] = home10.position;
// 	/*double d[11];
// 	d[1] = Distance(ball.position, home1.position);
// 	d[2] = Distance(ball.position, home2.position);
// 	d[3] = Distance(ball.position, home3.position);
// 	d[4] = Distance(ball.position, home4.position);
// 	d[5] = Distance(ball.position, home5.position);
// 	d[6] = Distance(ball.position, home6.position);
// 	d[7] = Distance(ball.position, home7.position);
// 	d[8] = Distance(ball.position, home8.position);
// 	d[9] = Distance(ball.position, home9.position);
// 	d[10] = Distance(ball.position, home10.position);*/
// 	if (65 < ball.position.x && ball.position.x <= 515) {

// 		// 对方罚球区内,包围门框
// 		if (ball.position.x <= 160 && ball.position.y <= 600 && ball.position.y >= 210) {

// 			Navigation[1] = CPoint(175, ball.position.y);
// 			Navigation[2] = CPoint(175, ball.position.y + 20);
// 			Navigation[3] = CPoint(175, ball.position.y - 20);
// 			Navigation[4] = CPoint(200, ball.position.y);
// 			Navigation[5] = CPoint(175, ball.position.y + 30);
// 			Navigation[6] = CPoint(200, ball.position.y - 30);
// 			Navigation[7] = CPoint(ball.position.x, 610);
// 			Navigation[8] = CPoint(ball.position.x, 210);
// 			Navigation[9] = CPoint(220, ball.position.y + 50);
// 			Navigation[10] = CPoint(220, ball.position.y - 50);
// 		}
// 		// 对方下半场
// 		else if (ball.position.y >= 607) {
// 			if (home1.position.x > ball.position.x) {	  // 球员在右
// 				if (home1.position.y > ball.position.y) { // 球员在右下
// 					Navigation[1] = ball.position;
// 				}
// 				else { // 球员在右下
// 					Navigation[1] = CPoint(ball.position.x + 10, ball.position.y + 10);
// 				}
// 			}
// 			else {										  // 球员在左
// 				if (home1.position.y > ball.position.y) { // 左下
// 					Navigation[1] = ball.position;
// 				}
// 				else { // 左上
// 					Navigation[1] = CPoint(ball.position.x - 10, ball.position.y + 10);
// 				}
// 			}
// 			if (home2.position.x > ball.position.x) {
// 				if (home2.position.y > ball.position.y) {
// 					Navigation[2] = ball.position;
// 				}
// 				else {
// 					Navigation[2] = CPoint(ball.position.x + 10, ball.position.y + 20);
// 				}
// 			}
// 			else {
// 				if (home2.position.y > ball.position.y) {
// 					Navigation[2] = ball.position;
// 				}
// 				else {
// 					Navigation[2] = CPoint(ball.position.x - 10, ball.position.y - 20);
// 				}
// 			}
// 			if (home3.position.x > ball.position.x) {
// 				if (home3.position.y > ball.position.y) {
// 					Navigation[3] = ball.position;
// 				}
// 				else {
// 					Navigation[3] = CPoint(ball.position.x + 20, ball.position.y + 10);
// 				}
// 			}
// 			else {
// 				if (home3.position.y > ball.position.y) {
// 					Navigation[3] = ball.position;
// 				}
// 				else {
// 					Navigation[3] = CPoint(ball.position.x - 20, ball.position.y - 10);
// 				}
// 			}
// 			Navigation[4] = CPoint(ball.position.x + 50, ball.position.y + 50);
// 			Navigation[5] = CPoint(ball.position.x + 50, ball.position.y);
// 			Navigation[6] = CPoint(ball.position.x + 50, ball.position.y - 50);
// 			Navigation[7] = CPoint(ball.position.x, ball.position.y + 50);
// 			Navigation[8] = CPoint(ball.position.x - 50, ball.position.y + 50);
// 			Navigation[9] = CPoint(ball.position.x + 80, ball.position.y);
// 			Navigation[10] = CPoint(ball.position.x + 80, ball.position.y + 50);
// 			//// Navigate(ball.position);
// 			////  机器人在球右下
// 			// if (robot->position.y <= ball.position.y && robot->position.x >= ball.position.x) {
// 			//	Direction(which, ball.position);
// 			//	// Velocity(which, 127, 127);
// 			// }
// 			//// 机器人在球右上
// 			// else if (robot->position.y > ball.position.y && robot->position.x > ball.position.x) {
// 			//	Direction(which, CPoint(ball.position.x + 10, ball.position.y));
// 			//	// Velocity(which, vL, vR);
// 			// }
// 			//// 机器人在球左上
// 			// else if (robot->position.y < ball.position.y && robot->position.x < ball.position.x) {
// 			//	// Position(which, CPoint(ball.));
// 			// }
// 			//// 机器人在球左下
// 			// else {
// 			//	Direction(which, CPoint(ball.position.x - 20, ball.position.y));
// 			// }
// 		}
// 		// 对方中场
// 		else if (ball.position.y >= 217 && ball.position.y < 607) {
// 			if (home1.position.x > ball.position.x) {
// 				if (home1.position.y < ball.position.y) {
// 					Navigation[1] = ball.position;
// 				}
// 				else {
// 					Navigation[1] = CPoint(ball.position.x + 10, ball.position.y - 10);
// 				}
// 			}
// 			else {
// 				if (home1.position.y < ball.position.y) {
// 					Navigation[1] = CPoint(ball.position.x, ball.position.y - 10);
// 				}
// 				else {
// 					Navigation[1] = CPoint(ball.position.x - 10, ball.position.y - 10);
// 				}
// 			}
// 			if (home2.position.x > ball.position.x) {
// 				if (home2.position.y < ball.position.y) {
// 					Navigation[2] = ball.position;
// 				}
// 				else {
// 					Navigation[2] = CPoint(ball.position.x + 20, ball.position.y + 10);
// 				}
// 			}
// 			else {
// 				if (home2.position.y < ball.position.y) {
// 					Navigation[1] = CPoint(ball.position.x, ball.position.y - 15);
// 				}
// 				else {
// 					Navigation[1] = CPoint(ball.position.x - 10, ball.position.y - 15);
// 				}
// 			}
// 			if (home3.position.x > ball.position.x) {
// 				if (home3.position.y < ball.position.y) {
// 					Navigation[3] = ball.position;
// 				}
// 				else {
// 					Navigation[3] = CPoint(ball.position.x + 10, ball.position.y + 20);
// 				}
// 			}
// 			else {
// 				if (home3.position.y < ball.position.y) {
// 					Navigation[1] = CPoint(ball.position.x + 10, ball.position.y - 15);
// 				}
// 				else {
// 					Navigation[1] = CPoint(ball.position.x - 15, ball.position.y - 10);
// 				}
// 			}
// 			Navigation[4] = CPoint(ball.position.x, ball.position.y - 60);
// 			Navigation[5] = CPoint(ball.position.x + 50, ball.position.y - 60);
// 			Navigation[6] = CPoint(ball.position.x + 60, ball.position.y - 50);
// 			Navigation[7] = CPoint(ball.position.x + 60, ball.position.y + 50);
// 			Navigation[8] = CPoint(ball.position.x + 60, ball.position.y + 70);
// 			Navigation[9] = CPoint(ball.position.x + 70, ball.position.y - 60);
// 			Navigation[10] = CPoint(ball.position.x + 70, ball.position.y - 60);
// 			//// 机器人在球的右下
// 			// if (robot->position.x >= ball.position.x && robot->position.y <= ball.position.y) {
// 			//	Direction(which, ball.position);
// 			// }
// 			//// 机器人在球右上
// 			// else if (robot->position.x > ball.position.x && robot->position.y > ball.position.y) {
// 			//	// 右上且距离较远
// 			//	if (robot->position.y >= ball.position.y + 100) {
// 			//		Direction(which, CPoint(ball.position.x + 20, ball.position.y + 20));
// 			//	}
// 			//	// 距离较近
// 			//	else {
// 			//		Direction(which, CPoint(ball.position.x + 10, ball.position.y));
// 			//	}
// 			// }
// 			//// 机器人在球左下
// 			// else if (robot->position.x <= ball.position.x && robot->position.y >= ball.position.y) {
// 			//	Direction(which, CPoint(ball.position.x - 20, ball.position.y + 20));
// 			// }
// 			//// 机器人在球左上
// 			// else {
// 			//	Direction(which, CPoint(ball.position.x - 20, ball.position.y - 20));
// 			// }
// 		}
// 		// 上场
// 		else {
// 			if (home1.position.x > ball.position.x) {
// 				if (home1.position.y < ball.position.y) {
// 					Navigation[1] = ball.position;
// 				}
// 				else {
// 					Navigation[1] = CPoint(ball.position.x + 10, ball.position.y - 10);
// 				}
// 			}
// 			else {
// 				if (home1.position.y < ball.position.y) {
// 					Navigation[1] = CPoint(ball.position.x, ball.position.y - 10);
// 				}
// 				else {
// 					Navigation[1] = CPoint(ball.position.x - 10, ball.position.y - 10);
// 				}
// 			}
// 			if (home2.position.x > ball.position.x) {
// 				if (home2.position.y < ball.position.y) {
// 					Navigation[2] = ball.position;
// 				}
// 				else {
// 					Navigation[2] = CPoint(ball.position.x + 10, ball.position.y);
// 				}
// 			}
// 			else {
// 				if (home2.position.y < ball.position.y) {
// 					Navigation[2] = CPoint(ball.position.x - 5, ball.position.y - 10);
// 				}
// 				else {
// 					Navigation[2] = CPoint(ball.position.x - 10, ball.position.y - 10);
// 				}
// 			}
// 			if (home3.position.x > ball.position.x) {
// 				if (home3.position.y < ball.position.y) {
// 					Navigation[3] = ball.position;
// 				}
// 				else {
// 					Navigation[3] = CPoint(ball.position.x + 10, ball.position.y - 15);
// 				}
// 			}
// 			else {
// 				if (home2.position.y < ball.position.y) {
// 					Navigation[3] = CPoint(ball.position.x - 5, ball.position.y - 10);
// 				}
// 				else {
// 					Navigation[3] = CPoint(ball.position.x - 10, ball.position.y - 10);
// 				}
// 			}
// 			Navigation[4] = CPoint(ball.position.x - 50, ball.position.y - 50);
// 			Navigation[5] = CPoint(ball.position.x, ball.position.y - 50);
// 			Navigation[6] = CPoint(ball.position.x + 50, ball.position.y - 50);
// 			Navigation[7] = CPoint(ball.position.x + 50, ball.position.y);
// 			Navigation[8] = CPoint(ball.position.x + 60, ball.position.y + 50);
// 			Navigation[9] = CPoint(ball.position.x + 70, ball.position.y + 60);
// 			Navigation[10] = CPoint(ball.position.x + 70, ball.position.y + 70);
// 			// 机器人在球右上
// 			// if (robot->position.x >= ball.position.x && robot->position.y <= ball.position.y) {
// 			//	Direction(which, ball.position);
// 			//}
// 			//// 机器人在球右下
// 			// else if (robot->position.x >= ball.position.x && robot->position.y > ball.position.y) {
// 			//	Direction(which, CPoint(ball.position.x + 20, ball.position.y));
// 			// }
// 			//// 机器人在球左上
// 			// else if (robot->position.x < ball.position.x && robot->position.y >= ball.position.y) {
// 			//	Direction(which, CPoint(ball.position.x - 20, ball.position.y));
// 			// }
// 			//// 机器人在左下
// 			// else {
// 			// }
// 		}
// 	}
// 	// 防守区域(在己方罚球区外)
// 	else if (ball.position.x > 515 && ball.position.x < 965) {
// 		CPoint goal;
// 		double l;

// 		// 己方上半场
// 		goal.x = ball.position.x;
// 		goal.y = 95;
// 		l = Distance(ball.position, goal);
// 		if (ball.position.y < 217 && ball.position.y >= 95) {
// 			Navigation[1].x = ball.position.x;
// 			Navigation[1].y = 95 + (int)l + 5;
// 			Navigation[2].x = ball.position.x - (int)sin(15.0 * PI / 180.0) * ((int)l + 5);
// 			Navigation[2].y = 95 + (int)cos(15.0 * PI / 180.0) * ((int)l + 5);
// 			Navigation[3].x = ball.position.x + (int)sin(15.0 * PI / 180.0) * ((int)l + 5);
// 			Navigation[3].y = 95 + (int)cos(15.0 * PI / 180.0) * ((int)l + 5);
// 			Navigation[4].x = ball.position.x;
// 			Navigation[4].y = 95 + (int)l + 15;
// 			Navigation[5].x = ball.position.x - (int)sin(25.0 * PI / 180.0) * ((int)l + 15);
// 			Navigation[5].y = 95 + (int)cos(25.0 * PI / 180.0) * ((int)l + 15);
// 			Navigation[6].x = ball.position.x + (int)sin(25.0 * PI / 180.0) * ((int)l + 15);
// 			Navigation[6].y = 95 + (int)cos(25.0 * PI / 180.0) * ((int)l + 15);
// 			Navigation[7].x = ball.position.x - (int)sin(45.0 * PI / 180.0) * ((int)l + 15);
// 			Navigation[7].y = 95 + (int)cos(45.0 * PI / 180.0) * ((int)l + 15);
// 			Navigation[8].x = ball.position.x + (int)sin(45.0 * PI / 180.0) * ((int)l + 15);
// 			Navigation[8].y = 95 + (int)cos(45.0 * PI / 180.0) * ((int)l + 15);
// 			Navigation[9].x = ball.position.x - (int)sin(30.0 * PI / 180.0) * ((int)l + 25);
// 			Navigation[9].y = 95 + (int)cos(30.0 * PI / 180.0) * ((int)l + 25);
// 			Navigation[10].x = ball.position.x + (int)sin(30.0 * PI / 180.0) * ((int)l + 25);
// 			Navigation[10].y = 95 + (int)cos(30.0 * PI / 180.0) * ((int)l + 25);
// 		}
// 		// 己方中场
// 		else if (ball.position.y > 217 && ball.position.y <= 607) {
// 			// 球在中场上侧，要把球往上压
// 			if (ball.position.y < 409) {
// 				Navigation[1].x = ball.position.x;
// 				Navigation[1].y = 95 + (int)l + 5;
// 				Navigation[2].x = ball.position.x - (int)sin(15.0 * PI / 180.0) * ((int)l + 5);
// 				Navigation[2].y = 95 + (int)cos(15.0 * PI / 180.0) * ((int)l + 5);
// 				Navigation[3].x = ball.position.x + (int)sin(15.0 * PI / 180.0) * ((int)l + 5);
// 				Navigation[3].y = 95 + (int)cos(15.0 * PI / 180.0) * ((int)l + 5);
// 				Navigation[4].x = ball.position.x;
// 				Navigation[4].y = 95 + (int)l + 15;
// 				Navigation[5].x = ball.position.x - (int)sin(25.0 * PI / 180.0) * ((int)l + 15);
// 				Navigation[5].y = 95 + (int)cos(25.0 * PI / 180.0) * ((int)l + 15);
// 				Navigation[6].x = ball.position.x + (int)sin(25.0 * PI / 180.0) * ((int)l + 15);
// 				Navigation[6].y = 95 + (int)cos(25.0 * PI / 180.0) * ((int)l + 15);
// 				Navigation[7].x = ball.position.x - (int)sin(45.0 * PI / 180.0) * ((int)l + 15);
// 				Navigation[7].y = 95 + (int)cos(45.0 * PI / 180.0) * ((int)l + 15);
// 				Navigation[8].x = ball.position.x + (int)sin(45.0 * PI / 180.0) * ((int)l + 15);
// 				Navigation[8].y = 95 + (int)cos(45.0 * PI / 180.0) * ((int)l + 15);
// 				Navigation[9].x = ball.position.x - (int)sin(30.0 * PI / 180.0) * ((int)l + 25);
// 				Navigation[9].y = 95 + (int)cos(30.0 * PI / 180.0) * ((int)l + 25);
// 				Navigation[10].x = ball.position.x + (int)sin(30.0 * PI / 180.0) * ((int)l + 25);
// 				Navigation[10].y = 95 + (int)cos(30.0 * PI / 180.0) * ((int)l + 25);
// 			}
// 			// 球在中场下侧，要把球往下压

// 			else {
// 				goal.x = ball.position.x;
// 				goal.y = 723;
// 				l = Distance(ball.position, goal);
// 				Navigation[1].x = ball.position.x;
// 				Navigation[1].y = 723 - (int)l - 5;
// 				Navigation[2].x = ball.position.x - (int)sin(15.0 * PI / 180.0) * ((int)l + 5);
// 				Navigation[2].y = 723 - (int)cos(15.0 * PI / 180.0) * ((int)l + 5);
// 				Navigation[3].x = ball.position.x + (int)sin(15.0 * PI / 180.0) * ((int)l + 5);
// 				Navigation[3].y = 723 - (int)cos(15.0 * PI / 180.0) * ((int)l + 5);
// 				Navigation[4].x = ball.position.x;
// 				Navigation[4].y = 723 - (int)l - 15;
// 				Navigation[5].x = ball.position.x - (int)sin(25.0 * PI / 180.0) * ((int)l + 15);
// 				Navigation[5].y = 723 - (int)cos(25.0 * PI / 180.0) * ((int)l + 15);
// 				Navigation[6].x = ball.position.x + (int)sin(25.0 * PI / 180.0) * ((int)l + 15);
// 				Navigation[6].y = 723 - (int)cos(25.0 * PI / 180.0) * ((int)l + 15);
// 				Navigation[7].x = ball.position.x - (int)sin(45.0 * PI / 180.0) * ((int)l + 15);
// 				Navigation[7].y = 723 - (int)cos(45.0 * PI / 180.0) * ((int)l + 15);
// 				Navigation[8].x = ball.position.x + (int)sin(45.0 * PI / 180.0) * ((int)l + 15);
// 				Navigation[8].y = 723 - (int)cos(45.0 * PI / 180.0) * ((int)l + 15);
// 				Navigation[9].x = ball.position.x - (int)sin(30.0 * PI / 180.0) * ((int)l + 25);
// 				Navigation[9].y = 723 - (int)cos(30.0 * PI / 180.0) * ((int)l + 25);
// 				Navigation[10].x = ball.position.x + (int)sin(30.0 * PI / 180.0) * ((int)l + 25);
// 				Navigation[10].y = 723 - (int)cos(30.0 * PI / 180.0) * ((int)l + 25);
// 			}
// 		}
// 		// 己方下半场

// 		else if (ball.position.y > 607) {
// 			goal.x = ball.position.x;
// 			goal.y = 723;
// 			l = Distance(ball.position, goal);
// 			Navigation[1].x = ball.position.x;
// 			Navigation[1].y = 723 - (int)l - 5;
// 			Navigation[2].x = ball.position.x - (int)sin(15.0 * PI / 180.0) * ((int)l + 5);
// 			Navigation[2].y = 723 - (int)cos(15.0 * PI / 180.0) * ((int)l + 5);
// 			Navigation[3].x = ball.position.x + (int)sin(15.0 * PI / 180.0) * ((int)l + 5);
// 			Navigation[3].y = 723 - (int)cos(15.0 * PI / 180.0) * ((int)l + 5);
// 			Navigation[4].x = ball.position.x;
// 			Navigation[4].y = 723 - (int)l - 15;
// 			Navigation[5].x = ball.position.x - (int)sin(25.0 * PI / 180.0) * ((int)l + 15);
// 			Navigation[5].y = 723 - (int)cos(25.0 * PI / 180.0) * ((int)l + 15);
// 			Navigation[6].x = ball.position.x + (int)sin(25.0 * PI / 180.0) * ((int)l + 15);
// 			Navigation[6].y = 723 - (int)cos(25.0 * PI / 180.0) * ((int)l + 15);
// 			Navigation[7].x = ball.position.x - (int)sin(45.0 * PI / 180.0) * ((int)l + 15);
// 			Navigation[7].y = 723 - (int)cos(45.0 * PI / 180.0) * ((int)l + 15);
// 			Navigation[8].x = ball.position.x + (int)sin(45.0 * PI / 180.0) * ((int)l + 15);
// 			Navigation[8].y = 723 - (int)cos(45.0 * PI / 180.0) * ((int)l + 15);
// 			Navigation[9].x = ball.position.x - (int)sin(30.0 * PI / 180.0) * ((int)l + 25);
// 			Navigation[9].y = 723 - (int)cos(30.0 * PI / 180.0) * ((int)l + 25);
// 			Navigation[10].x = ball.position.x + (int)sin(30.0 * PI / 180.0) * ((int)l + 25);
// 			Navigation[10].y = 723 - (int)cos(30.0 * PI / 180.0) * ((int)l + 25);
// 		}
// 	}
// 	for (int i = 1; i < 11; i++) // 己方禁区处理
// 	{
// 		int kx, ky, x1, x2;
// 		if (Navigation[i].x > 873 && Navigation[i].y < 607 && Navigation[i].y > 217) // 导航定位不进禁区
// 		{
// 			if (ball.position.x > 873) {
// 				if (ball.position.y > 607)
// 					Navigation[i].y = 607;
// 				if (ball.position.y < 217)
// 					Navigation[i].y = 217;
// 			}
// 			else {
// 				Navigation[i].x = 873;
// 			}
// 		}
// 		else if (Navigation[i].x > 873 && Navigation[i].y > 607) // 行走路径不进禁区
// 		{
// 			if (robot[i].x < 873 && robot[i].y < 607 && robot[i].y > 217) {
// 				ky = abs((Navigation[i].y - robot[i].y) / (Navigation[i].x - robot[i].x));
// 				x1 = abs((873 - robot[i].x) * ky);
// 				x2 = abs(607 - robot[i].y);
// 				if (x2 > x1) {
// 					Navigation[i].y = robot[i].y + x1;
// 					Navigation[i].x = 873;
// 				}
// 			}
// 		}
// 		else if (Navigation[i].x > 873 && Navigation[i].y < 217) {
// 			if (robot[i].x < 873 && robot[i].y < 607 && robot[i].y > 217) {
// 				ky = abs((Navigation[i].y - robot[i].y) / (Navigation[i].x - robot[i].x));
// 				x1 = abs((873 - robot[i].x) * ky);
// 				x2 = abs(217 - robot[i].y);
// 				if (x2 > x1) {
// 					Navigation[i].y = robot[i].y - x1;
// 					Navigation[i].x = 873;
// 				}
// 			}
// 		}
// 		else if (Navigation[i].x < 873 && Navigation[i].y > 217) {
// 			if (robot[i].x > 873 && robot[i].y < 217) {
// 				kx = abs((Navigation[i].x - robot[i].x) / (Navigation[i].y - robot[i].y));
// 				x1 = abs((217 - robot[i].y) * kx);
// 				x2 = abs(873 - robot[i].x);
// 				if (x2 > x1) {
// 					Navigation[i].y = 217;
// 					Navigation[i].x = robot[i].x - x1;
// 				}
// 			}
// 		}
// 		else if (Navigation[i].x < 873 && Navigation[i].y < 607) {
// 			if (robot[i].x > 873 && robot[i].y > 607) {
// 				kx = abs((Navigation[i].x - robot[i].x) / (Navigation[i].y - robot[i].y));
// 				x1 = abs((607 - robot[i].y) * kx);
// 				x2 = abs(873 - robot[i].x);
// 				if (x2 > x1) {
// 					Navigation[i].y = 607;
// 					Navigation[i].x = robot[i].x - x1;
// 				}
// 			}
// 		}
// 	}
// }

// void CStrategySystem::control(int which) {
// 	Robot2 *robot;
// 	// switch (which) {
// 	// case HOME1:
// 	//	robot = &home1;
// 	//	break;
// 	// case HOME2:
// 	//	robot = &home2;
// 	//	break;
// 	// case HOME3:
// 	//	robot = &home3;
// 	//	break;
// 	// case HOME4:
// 	//	robot = &home4;
// 	//	break;
// 	// case HOME5:
// 	//	robot = &home5;
// 	//	break;
// 	// case HOME6:
// 	//	robot = &home6;
// 	//	break;
// 	// case HOME7:
// 	//	robot = &home7;
// 	//	break;
// 	// case HOME8:
// 	//	robot = &home8;
// 	//	break;
// 	// case HOME9:
// 	//	robot = &home9;
// 	//	break;
// 	// case HOME10:
// 	//	robot = &home10;
// 	//	break;
// 	// case HGOALIE:
// 	//	robot = &hgoalie;
// 	//	break;
// 	// }
// 	PositionSE(which, Navigation[which]);
// }

// 查找在大区里的机器人
int CStrategySystem::search1() {
	int sum = 0;
	if ((home1.position.x >= 105 && home1.position.x <= 157 && home1.position.y >= 247 && home1.position.y <= 577) || (home1.position.x >= 65 && home1.position.x <= 157 && home1.position.y >= 217 && home1.position.y <= 247) || (home1.position.x >= 65 && home1.position.x <= 157 && home1.position.y >= 577 && home1.position.y <= 607))
		sum++;
	if ((home2.position.x >= 105 && home2.position.x <= 157 && home2.position.y >= 247 && home2.position.y <= 577) || (home2.position.x >= 65 && home2.position.x <= 157 && home2.position.y >= 217 && home2.position.y <= 247) || (home2.position.x >= 65 && home2.position.x <= 157 && home2.position.y >= 577 && home2.position.y <= 607))
		sum++;
	if ((home3.position.x >= 105 && home3.position.x <= 157 && home3.position.y >= 247 && home3.position.y <= 577) || (home3.position.x >= 65 && home3.position.x <= 157 && home3.position.y >= 217 && home3.position.y <= 247) || (home3.position.x >= 65 && home3.position.x <= 157 && home3.position.y >= 577 && home3.position.y <= 607))
		sum++;
	if ((home4.position.x >= 105 && home4.position.x <= 157 && home4.position.y >= 247 && home4.position.y <= 577) || (home4.position.x >= 65 && home4.position.x <= 157 && home4.position.y >= 217 && home4.position.y <= 247) || (home4.position.x >= 65 && home4.position.x <= 157 && home4.position.y >= 577 && home4.position.y <= 607))
		sum++;
	if ((home5.position.x >= 105 && home5.position.x <= 157 && home5.position.y >= 247 && home5.position.y <= 577) || (home5.position.x >= 65 && home5.position.x <= 157 && home5.position.y >= 217 && home5.position.y <= 247) || (home5.position.x >= 65 && home5.position.x <= 157 && home5.position.y >= 577 && home5.position.y <= 607))
		sum++;
	if ((home6.position.x >= 105 && home6.position.x <= 157 && home6.position.y >= 247 && home6.position.y <= 577) || (home6.position.x >= 65 && home6.position.x <= 157 && home6.position.y >= 217 && home6.position.y <= 247) || (home6.position.x >= 65 && home6.position.x <= 157 && home6.position.y >= 577 && home6.position.y <= 607))
		sum++;
	if ((home7.position.x >= 105 && home7.position.x <= 157 && home7.position.y >= 247 && home7.position.y <= 577) || (home7.position.x >= 65 && home7.position.x <= 157 && home7.position.y >= 217 && home7.position.y <= 247) || (home7.position.x >= 65 && home7.position.x <= 157 && home7.position.y >= 577 && home7.position.y <= 607))
		sum++;
	if ((home8.position.x >= 105 && home8.position.x <= 157 && home8.position.y >= 247 && home8.position.y <= 577) || (home8.position.x >= 65 && home8.position.x <= 157 && home8.position.y >= 217 && home8.position.y <= 247) || (home8.position.x >= 65 && home8.position.x <= 157 && home8.position.y >= 577 && home8.position.y <= 607))
		sum++;
	if ((home9.position.x >= 105 && home9.position.x <= 157 && home9.position.y >= 247 && home9.position.y <= 577) || (home9.position.x >= 65 && home9.position.x <= 157 && home9.position.y >= 217 && home9.position.y <= 247) || (home9.position.x >= 65 && home9.position.x <= 157 && home9.position.y >= 577 && home9.position.y <= 607))
		sum++;
	if ((home10.position.x >= 105 && home10.position.x <= 157 && home10.position.y >= 247 && home10.position.y <= 577) || (home10.position.x >= 65 && home10.position.x <= 157 && home10.position.y >= 217 && home10.position.y <= 247) || (home10.position.x >= 65 && home10.position.x <= 157 && home10.position.y >= 577 && home10.position.y <= 607))
		sum++;
	return sum;
}

// 查找在小区里的机器人
int CStrategySystem::search2() {
	int sum = 0;
	if (home1.position.x >= 65 && home1.position.x < 105 && home1.position.y >= 247 && home1.position.y <= 577)
		sum++;
	if (home2.position.x >= 65 && home2.position.x < 105 && home2.position.y >= 247 && home2.position.y <= 577)
		sum++;
	if (home3.position.x >= 65 && home3.position.x < 105 && home3.position.y >= 247 && home3.position.y <= 577)
		sum++;
	if (home4.position.x >= 65 && home4.position.x < 105 && home4.position.y >= 247 && home4.position.y <= 577)
		sum++;
	if (home5.position.x >= 65 && home5.position.x < 105 && home5.position.y >= 247 && home5.position.y <= 577)
		sum++;
	if (home6.position.x >= 65 && home6.position.x < 105 && home6.position.y >= 247 && home6.position.y <= 577)
		sum++;
	if (home7.position.x >= 65 && home7.position.x < 105 && home7.position.y >= 247 && home7.position.y <= 577)
		sum++;
	if (home8.position.x >= 65 && home8.position.x < 105 && home8.position.y >= 247 && home8.position.y <= 577)
		sum++;
	if (home9.position.x >= 65 && home9.position.x < 105 && home9.position.y >= 247 && home9.position.y <= 577)
		sum++;
	if (home10.position.x >= 65 && home10.position.x < 105 && home10.position.y >= 247 && home10.position.y <= 577)
		sum++;
	return sum;
}

// 守门
void CStrategySystem::Goalie() { // TODO 两侧卡顿
	if (start)
		ball.oldPosition = ball.position;
	// static int xit;
	// if (ball.position != ball.oldPosition)
	// 	xit = 0;
	// else
	// 	xit++;
	if (ball.position.x <= hgoalie.position.x) {
		int xix = ball.position.x > 950 ? 965 : 950, xiy, xii = int((double(ball.position.y - ball.oldPosition.y) / (ball.position.x - ball.oldPosition.x)) * 965 + (ball.oldPosition.y - (double(ball.position.y - ball.oldPosition.y) / (ball.position.x - ball.oldPosition.x)) * ball.oldPosition.x) + 0.5), xid = 2;
		if (Distance(ball.position, ball.oldPosition) < 1 || ball.position.x <= ball.oldPosition.x || xii < 313 || xii > 505) {
			if (ball.position.x >= 927 && ball.position.y >= 313 && ball.position.y <= 505) {
				xiy = ball.position.y;
				if (xiy < 343 || xiy > 475)
					xix = 965;
			}
			else {
				xii = int((double(ball.position.y - shooter_pos().y) / (ball.position.x - shooter_pos().x)) * 965 + (shooter_pos().y - (double(ball.position.y - shooter_pos().y) / (ball.position.x - shooter_pos().x)) * shooter_pos().x) + 0.5);
				if (xii < 313 || xii > 505) {
					xiy = int((Distance(ball.position, CPoint(863, 313)) * 192 / (Distance(ball.position, CPoint(863, 313)) + Distance(ball.position, CPoint(863, 505)))) + 313.5);
					if (xiy < 343 || xiy > 475)
						xix = 965;
				}
				else {
					if (xii < 343 || xii > 475)
						xix = 965;
					xiy = int((double(ball.position.y - shooter_pos().y) / (ball.position.x - shooter_pos().x)) * (xix - xid) + (shooter_pos().y - (double(ball.position.y - shooter_pos().y) / (ball.position.x - shooter_pos().x)) * shooter_pos().x) + 0.5);
				}
				if (ball.position.x <= 900 || ball.position.y < 313 || ball.position.y > 505)
					if ((t / 4) % 2)
						xiy += 30;
					else
						xiy -= 30;
			}
		}
		else {
			if (xii < 343 || xii > 475)
				xix = 965;
			xiy = int((double(ball.position.y - ball.oldPosition.y) / (ball.position.x - ball.oldPosition.x)) * (xix - xid) + (ball.oldPosition.y - (double(ball.position.y - ball.oldPosition.y) / (ball.position.x - ball.oldPosition.x)) * ball.oldPosition.x) + 0.5);
		}
		// if (ball.position.x >= 900 && ball.position.y >= 313 && ball.position.y <= 505 && xit >= 10) // TODO 旋球
		// if (shooter_pos().y > ball.position.y)
		// 	Direction(HGOALIE, CPoint(ball.position.x + 1, ball.position.y + 1));
		// else
		// 	Direction(HGOALIE, CPoint(ball.position.x + 1, ball.position.y - 1));
		// else
		Direction(HGOALIE, CPoint(xix, xiy));
	}
	else
		Stop(HGOALIE);
	ball.oldPosition = ball.position;
}

// 对方射门者位置
CPoint CStrategySystem::shooter_pos() {
	CPoint cur_pos[11]{ opponent.position1, opponent.position2, opponent.position3, opponent.position4, opponent.position5, opponent.position6, opponent.position7, opponent.position8, opponent.position9, opponent.position10, opponent.position11 };
	for (int i = 0; i < 11; i++) {
		if (cur_pos[i].x >= ball.position.x)
			cur_pos[i] = CPoint(-965, -723);
	}
	int xii = 0;
	double xid = Distance(cur_pos[0], ball.position);
	for (int i = 1; i < 11; i++) {
		if (Distance(cur_pos[i], ball.position) < xid) {
			xid = Distance(cur_pos[i], ball.position);
			xii = i;
		}
	}
	return cur_pos[xii];
}

double CStrategySystem::Distance(CPoint point1, CPoint point2) {
	return sqrt(1.0 * (point1.x - point2.x) * (point1.x - point2.x) + 1.0 * (point1.y - point2.y) * (point1.y - point2.y));
}

double CStrategySystem::Angle(CPoint point1, CPoint point2) {
	return atan2(1.0 * (point1.y - point2.y), 1.0 * (point1.x - point2.x));
}

void CStrategySystem::Direction(int which, CPoint point) {
	Robot2 *robot;
	double distance_e;
	int dx, dy, desired_angle, theta_e, vL, vR;

	switch (which) {
	case HOME1:
		robot = &home1;
		break;
	case HOME2:
		robot = &home2;
		break;
	case HOME3:
		robot = &home3;
		break;
	case HOME4:
		robot = &home4;
		break;
	case HOME5:
		robot = &home5;
		break;
	case HOME6:
		robot = &home6;
		break;
	case HOME7:
		robot = &home7;
		break;
	case HOME8:
		robot = &home8;
		break;
	case HOME9:
		robot = &home9;
		break;
	case HOME10:
		robot = &home10;
		break;
	case HGOALIE:
		robot = &hgoalie;
		break;
	}

	point.x = 2 * point.x - robot->position.x;
	point.y = 2 * point.y - robot->position.y;

	point.x = point.x < boundRect.left ? boundRect.left : point.x;
	point.x = point.x > boundRect.right ? boundRect.right : point.x;
	point.y = point.y < boundRect.top ? boundRect.top : point.y;
	point.y = point.y > boundRect.bottom ? boundRect.bottom : point.y;

	dx = point.x - robot->position.x;
	dy = point.y - robot->position.y;

	distance_e = sqrt(1.0 * dx * dx + 1.0 * dy * dy);

	if (dx == 0 && dy == 0)
		desired_angle = 90;
	else
		desired_angle = (int)(180.0 / M_PI * atan2((double)(dy), (double)(dx)));

	theta_e = desired_angle - robot->angle;

	while (theta_e > 180)
		theta_e -= 360;
	while (theta_e < -180)
		theta_e += 360;

	if (theta_e < -90) {
		theta_e += 180;
		distance_e = -distance_e;
	}
	else if (theta_e > 90) {
		theta_e -= 180;
		distance_e = -distance_e;
	}

	vL = (int)(5. * (100.0 / 1000.0 * distance_e + 40.0 / 90.0 * theta_e));
	vR = (int)(5. * (100.0 / 1000.0 * distance_e - 40.0 / 90.0 * theta_e));

	Velocity(which, vL, vR);
}

void CStrategySystem::PositionSE(int which, CPoint point) {
	Robot2 *robot;
	double distance_e;
	int dx, dy, desired_angle, theta_e, vL, vR;

	switch (which) {
	case HOME1:
		robot = &home1;
		break;
	case HOME2:
		robot = &home2;
		break;
	case HOME3:
		robot = &home3;
		break;
	case HOME4:
		robot = &home4;
		break;
	case HOME5:
		robot = &home5;
		break;
	case HOME6:
		robot = &home6;
		break;
	case HOME7:
		robot = &home7;
		break;
	case HOME8:
		robot = &home8;
		break;
	case HOME9:
		robot = &home9;
		break;
	case HOME10:
		robot = &home10;
		break;
	case HGOALIE:
		robot = &hgoalie;
		break;
	}

	if (point.x >= 873 && point.y >= 217 && point.y <= 607)
		if (robot->position.x >= 873) {
			if (robot->position.y <= 217) {
				point.x = robot->position.x - (robot->position.x - point.x) * (217 - robot->position.y) / (point.y - robot->position.y);
				point.y = 217;
			}
			else if (robot->position.y >= 607) {
				point.x = robot->position.x - (robot->position.x - point.x) * (607 - robot->position.y) / (point.y - robot->position.y);
				point.y = 607;
			}
		}
		else {
			point.x = 873;
			point.y = robot->position.y - (robot->position.y - point.y) * (873 - robot->position.x) / (point.x - robot->position.x);
		}

	point.x = point.x < boundRect.left ? boundRect.left : point.x;
	point.x = point.x > boundRect.right ? boundRect.right : point.x;
	point.y = point.y < boundRect.top ? boundRect.top : point.y;
	point.y = point.y > boundRect.bottom ? boundRect.bottom : point.y;

	dx = point.x - robot->position.x;
	dy = point.y - robot->position.y;

	distance_e = sqrt(1.0 * dx * dx + 1.0 * dy * dy);

	if (dx == 0 && dy == 0)
		desired_angle = 90;
	else
		desired_angle = (int)(180.0 / M_PI * atan2((double)(dy), (double)(dx)));

	theta_e = desired_angle - robot->angle;

	while (theta_e > 180)
		theta_e -= 360;
	while (theta_e < -180)
		theta_e += 360;

	if (theta_e < -90) {
		theta_e += 180;
		distance_e = -distance_e;
	}
	else if (theta_e > 90) {
		theta_e -= 180;
		distance_e = -distance_e;
	}

	vL = (int)(5. * (100.0 / 1000.0 * distance_e + 40.0 / 90.0 * theta_e));
	vR = (int)(5. * (100.0 / 1000.0 * distance_e - 40.0 / 90.0 * theta_e));

	Velocity(which, vL, vR);
}

void CStrategySystem::Rush(int which, CPoint point) {
	Robot2 *robot;
	double distance_e;
	int dx, dy, desired_angle, theta_e, vL, vR;

	switch (which) {
	case HOME1:
		robot = &home1;
		break;
	case HOME2:
		robot = &home2;
		break;
	case HOME3:
		robot = &home3;
		break;
	case HOME4:
		robot = &home4;
		break;
	case HOME5:
		robot = &home5;
		break;
	case HOME6:
		robot = &home6;
		break;
	case HOME7:
		robot = &home7;
		break;
	case HOME8:
		robot = &home8;
		break;
	case HOME9:
		robot = &home9;
		break;
	case HOME10:
		robot = &home10;
		break;
	case HGOALIE:
		robot = &hgoalie;
		break;
	}

	CPoint p3;

	// 计算射线的斜率和截距
	double k = (double)(point.y - robot->position.y) / (point.x - robot->position.x);
	double b = robot->position.y - k * robot->position.x;
	// 判断射线的方向
	bool right = point.x > robot->position.x; // 是否向右
	bool up = point.y < robot->position.y;	  // 是否向上
	// 根据方向和斜率判断相交边
	if (right && up) { // 右上方
		if (k > 0) {   // 斜率大于 0
			// 右边或上边
			if (k * boundRect.right + b < boundRect.top) {
				// 右边
				p3.x = boundRect.right;
				p3.y = k * boundRect.right + b;
			}
			else {
				// 上边
				p3.x = (boundRect.top - b) / k;
				p3.y = boundRect.top;
			}
		}
		else { // 斜率小于等于 0
			// 上边或右边
			if ((boundRect.top - b) / k > boundRect.right) {
				// 上边
				p3.x = (boundRect.top - b) / k;
				p3.y = boundRect.top;
			}
			else {
				// 右边
				p3.x = boundRect.right;
				p3.y = k * boundRect.right + b;
			}
		}
	}
	else if (right && !up) { // 右下方
		if (k > 0) {		 // 斜率大于 0
			// 下边或右边
			if ((boundRect.bottom - b) / k < boundRect.right) {
				// 下边
				p3.x = (boundRect.bottom - b) / k;
				p3.y = boundRect.bottom;
			}
			else {
				// 右边
				p3.x = boundRect.right;
				p3.y = k * boundRect.right + b;
			}
		}
		else { // 斜率小于等于 0
			// 右边或下边
			if (k * boundRect.right + b > boundRect.bottom) {
				// 右边
				p3.x = boundRect.right;
				p3.y = k * boundRect.right + b;
			}
			else {
				// 下边
				p3.x = (boundRect.bottom - b) / k;
				p3.y = boundRect.bottom;
			}
		}
	}
	else if (!right && up) { // 左上方
		if (k > 0) {		 // 斜率大于 0
			// 上边或左边
			if ((boundRect.top - b) / k < boundRect.left) {
				// 上边
				p3.x = (boundRect.top - b) / k;
				p3.y = boundRect.top;
			}
			else {
				// 左边
				p3.x = boundRect.left;
				p3.y = k * boundRect.left + b;
			}
		}
		else { // 斜率小于等于 0
			// 左边或上边
			if (k * boundRect.left + b < boundRect.top) {
				// 左边
				p3.x = boundRect.left;
				p3.y = k * boundRect.left + b;
			}
			else {
				// 上边
				p3.x = (boundRect.top - b) / k;
				p3.y = boundRect.top;
			}
		}
	}
	else {			 // 左下方
		if (k > 0) { // 斜率大于 0
			// 左边或下边
			if (k * boundRect.left + b > boundRect.bottom) {
				// 左边
				p3.x = boundRect.left;
				p3.y = k * boundRect.left + b;
			}
			else {
				// 下边
				p3.x = (boundRect.bottom - b) / k;
				p3.y = boundRect.bottom;
			}
		}
		else { // 斜率小于等于 0
			// 下边或左边
			if ((boundRect.bottom - b) / k > boundRect.left) {
				// 下边
				p3.x = (boundRect.bottom - b) / k;
				p3.y = boundRect.bottom;
			}
			else {
				// 左边
				p3.x = boundRect.left;
				p3.y = k * boundRect.left + b;
			}
		}
	}

	point = p3;

	point.x = point.x < boundRect.left ? boundRect.left : point.x;
	point.x = point.x > boundRect.right ? boundRect.right : point.x;
	point.y = point.y < boundRect.top ? boundRect.top : point.y;
	point.y = point.y > boundRect.bottom ? boundRect.bottom : point.y;

	dx = point.x - robot->position.x;
	dy = point.y - robot->position.y;

	distance_e = sqrt(1.0 * dx * dx + 1.0 * dy * dy);

	if (dx == 0 && dy == 0)
		desired_angle = 90;
	else
		desired_angle = (int)(180.0 / M_PI * atan2((double)(dy), (double)(dx)));

	theta_e = desired_angle - robot->angle;

	while (theta_e > 180)
		theta_e -= 360;
	while (theta_e < -180)
		theta_e += 360;

	if (theta_e < -90) {
		theta_e += 180;
		distance_e = -distance_e;
	}
	else if (theta_e > 90) {
		theta_e -= 180;
		distance_e = -distance_e;
	}

	vL = (int)(5. * (100.0 / 1000.0 * distance_e + 40.0 / 90.0 * theta_e));
	vR = (int)(5. * (100.0 / 1000.0 * distance_e - 40.0 / 90.0 * theta_e));

	Velocity(which, vL, vR);
}

// 判断状态，1 为罚球，0 为正常, 其他为争球
int CStrategySystem::Status() {
	if (ball.position.x <= 309 && ball.position.x >= 279) {
		if (ball.position.y >= 394 && ball.position.y <= 424)
			return 1;
		if (ball.position.y <= 193 && ball.position.y >= 173)
			return 2; // 左上争球点
		if (ball.position.y <= 648 && ball.position.y >= 628)
			return 3; // 左下争球点
	}
	if (ball.position.x <= 753 && ball.position.x >= 733) {
		if (ball.position.y <= 193 && ball.position.y >= 173)
			return 4; // 右上争球点
		if (ball.position.y <= 648 && ball.position.y >= 628)
			return 5; // 右下争球点
	}
	return 0;
}

void CStrategySystem::Action() {
	t++;
	Goalie();
	switch (Status()) {
	case 1:
		flag = true;
		Penalty();
		break;
	case 2:
	case 3:
	case 4:
	case 5:
		Freeball();
		break;
	default:
		flag = true;
		Possession();
		break;
	}
	if (start)
		start = false;
}

void CStrategySystem::Angle(int which, int desired_angle) {
	Robot2 *robot;
	int theta_e, vL, vR;

	switch (which) {
	case HOME1:
		robot = &home1;
		break;
	case HOME2:
		robot = &home2;
		break;
	case HOME3:
		robot = &home3;
		break;
	case HOME4:
		robot = &home4;
		break;
	case HOME5:
		robot = &home5;
		break;
	case HOME6:
		robot = &home6;
		break;
	case HOME7:
		robot = &home7;
		break;
	case HOME8:
		robot = &home8;
		break;
	case HOME9:
		robot = &home9;
		break;
	case HOME10:
		robot = &home10;
		break;
	case HGOALIE:
		robot = &hgoalie;
		break;
	}

	theta_e = desired_angle - robot->angle;
	while (theta_e > 180)
		theta_e -= 360;
	while (theta_e < -180)
		theta_e += 360;
	if (theta_e < -90)
		theta_e += 180;
	else if (theta_e > 90)
		theta_e -= 180;
	vL = (int)(60.0 / 90.0 * theta_e);
	vR = (int)(-60.0 / 90.0 * theta_e);
	Velocity(which, vL, vR);
}

void CStrategySystem::Velocity(int which, int vL, int vR) {
	if (vL < -127)
		vL = -127;
	if (vL > 127)
		vL = 127;

	if (vR < -127)
		vR = -127;
	if (vR > 127)
		vR = 127;

	switch (which) {
	case HOME1:
		command[2] = vL;
		command[3] = vR;
		command[4] = C_GO;
		break;
	case HOME2:
		command[5] = vL;
		command[6] = vR;
		command[7] = C_GO;
		break;
	case HOME3:
		command[8] = vL;
		command[9] = vR;
		command[10] = C_GO;
		break;
	case HOME4:
		command[11] = vL;
		command[12] = vR;
		command[13] = C_GO;
		break;
	case HOME5:
		command[14] = vL;
		command[15] = vR;
		command[16] = C_GO;
		break;
	case HOME6:
		command[17] = vL;
		command[18] = vR;
		command[19] = C_GO;
		break;
	case HOME7:
		command[20] = vL;
		command[21] = vR;
		command[22] = C_GO;
		break;
	case HOME8:
		command[23] = vL;
		command[24] = vR;
		command[25] = C_GO;
		break;
	case HOME9:
		command[26] = vL;
		command[27] = vR;
		command[28] = C_GO;
		break;
	case HOME10:
		command[29] = vL;
		command[30] = vR;
		command[31] = C_GO;
		break;
	case HGOALIE:
		command[32] = vL;
		command[33] = vR;
		command[34] = C_GO;
		break;
	}
}

void CStrategySystem::Position(int which, CPoint point) {
	Robot2 *robot;
	double distance_e;
	int dx, dy, desired_angle, theta_e, vL, vR;

	switch (which) {
	case HOME1:
		robot = &home1;
		break;
	case HOME2:
		robot = &home2;
		break;
	case HOME3:
		robot = &home3;
		break;
	case HOME4:
		robot = &home4;
		break;
	case HOME5:
		robot = &home5;
		break;
	case HOME6:
		robot = &home6;
		break;
	case HOME7:
		robot = &home7;
		break;
	case HOME8:
		robot = &home8;
		break;
	case HOME9:
		robot = &home9;
		break;
	case HOME10:
		robot = &home10;
		break;
	case HGOALIE:
		robot = &hgoalie;
		break;
	}

	point.x = point.x < boundRect.left ? boundRect.left : point.x;
	point.x = point.x > boundRect.right ? boundRect.right : point.x;
	point.y = point.y < boundRect.top ? boundRect.top : point.y;
	point.y = point.y > boundRect.bottom ? boundRect.bottom : point.y;

	dx = point.x - robot->position.x;
	dy = point.y - robot->position.y;

	distance_e = sqrt(1.0 * dx * dx + 1.0 * dy * dy);

	if (dx == 0 && dy == 0)
		desired_angle = 90;
	else
		desired_angle = (int)(180.0 / M_PI * atan2((double)(dy), (double)(dx)));

	theta_e = desired_angle - robot->angle;

	while (theta_e > 180)
		theta_e -= 360;
	while (theta_e < -180)
		theta_e += 360;

	if (theta_e < -90) {
		theta_e += 180;
		distance_e = -distance_e;
	}
	else if (theta_e > 90) {
		theta_e -= 180;
		distance_e = -distance_e;
	}

	vL = (int)(5. * (100.0 / 1000.0 * distance_e + 40.0 / 90.0 * theta_e));
	vR = (int)(5. * (100.0 / 1000.0 * distance_e - 40.0 / 90.0 * theta_e));

	Velocity(which, vL, vR);
}

void CStrategySystem::Stop(int which) {
	int vL, vR;
	vL = vR = 0;
	Velocity(which, vL, vR);
}

void CStrategySystem::ReceiveData(Robot1 bal, Robot2 ho1, Robot2 ho2, Robot2 ho3, Robot2 ho4,
	Robot2 ho5, Robot2 ho6, Robot2 ho7, Robot2 ho8, Robot2 ho9,
	Robot2 ho10, Robot2 hgo, Robot3 opp) {
	if (m_nGameArea == GAME_RIGHT) {
		ball.position = bal.position;
		ball.angle = bal.angle;

		home1.position = ho1.position;
		home1.angle = ho1.angle;

		home2.position = ho2.position;
		home2.angle = ho2.angle;

		home3.position = ho3.position;
		home3.angle = ho3.angle;

		home4.position = ho4.position;
		home4.angle = ho4.angle;

		home5.position = ho5.position;
		home5.angle = ho5.angle;

		home6.position = ho6.position;
		home6.angle = ho6.angle;

		home7.position = ho7.position;
		home7.angle = ho7.angle;

		home8.position = ho8.position;
		home8.angle = ho8.angle;

		home9.position = ho9.position;
		home9.angle = ho9.angle;

		home10.position = ho10.position;
		home10.angle = ho10.angle;

		hgoalie.position = hgo.position;
		hgoalie.angle = hgo.angle;

		opponent.position1 = opp.position1;
		opponent.position2 = opp.position2;
		opponent.position3 = opp.position3;
		opponent.position4 = opp.position4;
		opponent.position5 = opp.position5;
		opponent.position6 = opp.position6;
		opponent.position7 = opp.position7;
		opponent.position8 = opp.position8;
		opponent.position9 = opp.position9;
		opponent.position10 = opp.position10;
		opponent.position11 = opp.position11;
	}
	else {
		ball.position.x = 1030 - bal.position.x;
		ball.position.y = 818 - bal.position.y;
		if (ball.angle > 0)
			ball.angle = bal.angle - 180;
		else
			ball.angle = 180 + bal.angle;

		home1.position.x = 1030 - ho1.position.x;
		home1.position.y = 818 - ho1.position.y;
		if (home1.angle > 0)
			home1.angle = ho1.angle - 180;
		else
			home1.angle = 180 + ho1.angle;
		home2.position.x = 1030 - ho2.position.x;
		home2.position.y = 818 - ho2.position.y;
		if (home2.angle > 0)
			home2.angle = ho2.angle - 180;
		else
			home2.angle = 180 + ho2.angle;
		home3.position.x = 1030 - ho3.position.x;
		home3.position.y = 818 - ho3.position.y;
		if (home3.angle > 0)
			home3.angle = ho3.angle - 180;
		else
			home3.angle = 180 + ho3.angle;
		home4.position.x = 1030 - ho4.position.x;
		home4.position.y = 818 - ho4.position.y;
		if (home4.angle > 0)
			home4.angle = ho4.angle - 180;
		else
			home4.angle = 180 + ho4.angle;
		home5.position.x = 1030 - ho5.position.x;
		home5.position.y = 818 - ho5.position.y;
		if (home5.angle > 0)
			home5.angle = ho5.angle - 180;
		else
			home5.angle = 180 + ho5.angle;
		//*/
		home6.position.x = 1030 - ho6.position.x;
		home6.position.y = 818 - ho6.position.y;
		///*
		if (home6.angle > 0)
			home6.angle = ho6.angle - 180;
		else
			home6.angle = 180 + ho6.angle;
		//*/
		home7.position.x = 1030 - ho7.position.x;
		home7.position.y = 818 - ho7.position.y;
		///*
		if (home7.angle > 0)
			home7.angle = ho7.angle - 180;
		else
			home7.angle = 180 + ho7.angle;
		//*/
		home8.position.x = 1030 - ho8.position.x;
		home8.position.y = 818 - ho8.position.y;
		///*
		if (home8.angle > 0)
			home8.angle = ho8.angle - 180;
		else
			home8.angle = 180 + ho8.angle;
		//*/
		home9.position.x = 1030 - ho9.position.x;
		home9.position.y = 818 - ho9.position.y;
		///*
		if (home9.angle > 0)
			home9.angle = ho9.angle - 180;
		else
			home9.angle = 180 + ho9.angle;
		//*/
		home10.position.x = 1030 - ho10.position.x;
		home10.position.y = 818 - ho10.position.y;
		///*
		if (home10.angle > 0)
			home10.angle = ho10.angle - 180;
		else
			home10.angle = 180 + ho10.angle;
		//*/
		hgoalie.position.x = 1030 - hgo.position.x;
		hgoalie.position.y = 818 - hgo.position.y;
		///*
		if (hgoalie.angle > 0)
			hgoalie.angle = hgo.angle - 180;
		else
			hgoalie.angle = 180 + hgo.angle;
		//*/
		opponent.position1.x = 1030 - opp.position1.x;
		opponent.position2.x = 1030 - opp.position2.x;
		opponent.position3.x = 1030 - opp.position3.x;
		opponent.position4.x = 1030 - opp.position4.x;
		opponent.position5.x = 1030 - opp.position5.x;
		opponent.position6.x = 1030 - opp.position6.x;
		opponent.position7.x = 1030 - opp.position7.x;
		opponent.position8.x = 1030 - opp.position8.x;
		opponent.position9.x = 1030 - opp.position9.x;
		opponent.position10.x = 1030 - opp.position10.x;
		opponent.position11.x = 1030 - opp.position11.x;

		opponent.position1.y = 818 - opp.position1.y;
		opponent.position2.y = 818 - opp.position2.y;
		opponent.position3.y = 818 - opp.position3.y;
		opponent.position4.y = 818 - opp.position4.y;
		opponent.position5.y = 818 - opp.position5.y;
		opponent.position6.y = 818 - opp.position6.y;
		opponent.position7.y = 818 - opp.position7.y;
		opponent.position8.y = 818 - opp.position8.y;
		opponent.position9.y = 818 - opp.position9.y;
		opponent.position10.y = 818 - opp.position10.y;
		opponent.position11.y = 818 - opp.position11.y;
	}
}

CStrategySystem::CStrategySystem(int id) {
	// int t = 10;
	// while (t--) {
	// 	Navigation.push_back(CPoint(515, 409));
	// }

	t = 0;

	start = true;

	pos = new CPoint[10];
	rp = new RelPos[10];

	for (int i = 0; i < 10; i++) {
		rp[i].ang = 0;
		rp[i].dis = 0;
		rp[i].id = i + 1;
	}

	flag = true;

	m_OurTeam = id;
	boundRect.SetRect(65, 95, 965, 723);
	if (id)
		m_nGameArea = GAME_LEFT;
	else
		m_nGameArea = GAME_RIGHT;
	for (int i = 0; i < 35; i++)
		command[i] = 0;
	C_Home1.Data.Lv = 0;
	C_Home1.Data.Rv = 0;
	C_Home1.Data.Command = C_STOP;
	C_Home2.Data.Lv = 0;
	C_Home2.Data.Rv = 0;
	C_Home2.Data.Command = C_STOP;
	C_Home3.Data.Lv = 0;
	C_Home3.Data.Rv = 0;
	C_Home3.Data.Command = C_STOP;
	C_Home4.Data.Lv = 0;
	C_Home4.Data.Rv = 0;
	C_Home4.Data.Command = C_STOP;
	C_Home5.Data.Lv = 0;
	C_Home5.Data.Rv = 0;
	C_Home5.Data.Command = C_STOP;
	C_Home6.Data.Lv = 0;
	C_Home6.Data.Rv = 0;
	C_Home6.Data.Command = C_STOP;
	C_Home7.Data.Lv = 0;
	C_Home7.Data.Rv = 0;
	C_Home7.Data.Command = C_STOP;
	C_Home8.Data.Lv = 0;
	C_Home8.Data.Rv = 0;
	C_Home8.Data.Command = C_STOP;
	C_Home9.Data.Lv = 0;
	C_Home9.Data.Rv = 0;
	C_Home9.Data.Command = C_STOP;
	C_Home10.Data.Lv = 0;
	C_Home10.Data.Rv = 0;
	C_Home10.Data.Command = C_STOP;
	C_Home11.Data.Lv = 0;
	C_Home11.Data.Rv = 0;
	C_Home11.Data.Command = C_STOP;

	m_nStrategy = id; // left = 0, right = 1
	nKick = 0;
	nKick2 = 0;
	nShoot = 0;
	nSweep = 0;
}

// CStrategySystem::~CStrategySystem() {
// }
