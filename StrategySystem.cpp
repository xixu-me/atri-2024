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

void CStrategySystem::Penalty() {
	if (home1.position.y < ball.position.y) {
		Position(HOME1, CPoint(ball.position.x - 234, ball.position.y + 100));
	}
	else if (home1.position.y == ball.position.y) {
		Position(HOME1, CPoint(ball.position.x - 234, ball.position.y));
	}
	else {
		Position(HOME1, CPoint(ball.position.x - 234, ball.position.y - 100));
	}
	// Direction(HOME2, ball.position);
	// Direction(HOME3, ball.position);
	// Direction(HOME4, ball.position);
	// Direction(HOME5, ball.position);
	// Direction(HOME6, ball.position);
	// Direction(HOME7, ball.position);
	// Direction(HOME8, ball.position);
	// Direction(HOME9, ball.position);
	// Direction(HOME10, ball.position);
}

// 争球
void CStrategySystem::Freeball() {
	int d = 21;
	static bool faceR;
	if (Status() == 2) { // 左上
		if (Distance(home3.position, ball.position) > d && flag) {
			Direction(HOME3, ball.position);
			faceR = fabs(home3.angle) > 90;
		}
		else {
			flag = false;
			double r = Distance(home3.position, ball.position) / (2 * (sin(atwo(home3.pos.x, home3.pos.y, ball.position.x, ball.position.y, ball.position.x, ball.position.y, 28, 505)))); // 求曲线行驶时轨迹的半径
			int lw = (r - 8) / (r + 5) * 127;
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
			double r = Distance(home1.position, ball.position) / (2 * (sin(atwo(home1.pos.x, home1.pos.y, ball.position.x, ball.position.y, ball.position.x, ball.position.y, 28, 313))));
			int rw = (r - 5) / (r + 5) * 127;
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
	}
	else if (Status() == 4) { // 右上
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
	}
	else if (Status() == 5) { // 右下
		if (Distance(home7.position, ball.position) > d && flag) {
			Direction(HOME7, ball.position);
			faceR = fabs(home7.angle) > 90;
		}
		else {
			flag = false;
			double r = Distance(home7.position, ball.position) / (2 * (sin(atwo(home7.pos.x, home7.pos.y, ball.position.x, ball.position.y, ball.position.x, ball.position.y, 515, 723))));
			int lw = (r - 5) / (r + 5) * 127;
			if (faceR)
				Velocity(10, -127, -lw);
			else
				Velocity(10, lw, 127);
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
	}
}

double CStrategySystem::atwo(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4) // 两直线间夹角
{
	double j = 0;
	double k1 = (y1 - y2) / (x1 - x2);
	double k2 = (y3 - y4) / (x3 - x4);
	j = atan(fabs((k2 - k1) / (1 + k1 * k2)));
	return j;
}

void CStrategySystem::spin(int which, bool isClockwise) { // 自旋
	if (isClockwise)
		Velocity(which, 127, -127);
	else
		Velocity(which, -127, 127);
}

// 射门
void CStrategySystem::Shot(int which, bool de) // 0向下门框射
{
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
		t4.x = 17.0;
		t4.y = 505.0;
		O = atan(fabs(ball.position.y - t4.y) / fabs(ball.position.x - t4.x)); // fabs(Angle(,t4));
		O1 = 180 - O;
		t3.x = t1.x + cos(O) * 34;
		t3.y = t1.y - sin(O) * 34;
	}
	else if (de == 1) {
		t4.x = 17.0;
		t4.y = 313.0;
		O = atan(fabs(ball.position.y - t4.y) / fabs(ball.position.x - t4.x)); // fabs(Angle(ball.position,t4));
		O1 = 180 + O;
		t3.x = t1.x + cos(O) * 34;
		t3.y = t1.y + sin(O) * 34;
	}
	if (Distance(robot->position, ball.position) <= 35 && (fabs(Angle(ball.position, t3) - Angle(robot->position, t3))) <= 3) {
		if (de == 1) {
			t3.x = t1.x - cos(O) * 34;
			t3.y = t1.y - sin(O) * 34;
			DirectionSE(which, t3);
		}
		else if (de == 0) {
			t3.x = t1.x - cos(O) * 34;
			t3.y = t1.y + sin(O) * 34;
			DirectionSE(which, t3);
		}
	}
	else
		PositionSE(which, t3); // 机器人到足够近的点t3
}

bool CStrategySystem::Canshot() // 射？
{
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
	if (ball.position.y >= 265 && ball.position.y <= 481) // 敌方框上半场
	{
		D1.x = 170;
		D1.y = 265;
		D2.x = 170;
		D2.y = 409;
		if (Distance(ball.position, home9.position) <= 116 && ball.position.y >= 409 && ball.position.y <= 481) //9可射
		{
			Shot(HOME9, 0);
			Position(HOME10, D1);
		}
		else if (Distance(ball.position, home10.position) <= 168 && ball.position.y < 409 && ball.position.y >= 265) //10可射
		{
			Position(HOME9, D2);
			Shot(HOME10, 0);
		}
		else {//9，10到预定位置
			Position(HOME10, D1);
			Position(HOME9, D2);
		}
		return 1;
	}
	else if (ball.position.y >= 337 && ball.position.y <= 556) // 敌方框下半场
	{ 
		D1.x = 170;
		D1.y = 556;
		D2.x = 170;
		D2.y = 409;
		if (Distance(ball.position, home9.position) <= 116 && ball.position.y <= 409 && ball.position.y >= 337) //9可射
		{
			Shot(HOME9, 1);
			Position(HOME10, D1);
		}
		else if (Distance(ball.position, home10.position) <= 164 && ball.position.y > 409 && ball.position.y <= 556) //10可射
		{
			Position(HOME9, D2);
			Shot(HOME10, 1);
		}
		else { // 9，10到预定位置
			Position(HOME10, D1);
			Position(HOME9, D2);
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

void CStrategySystem::shot1(int which, double o, CPoint t) { // 直射
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

int CStrategySystem::search() { // 查找在禁区里的机器人
	return 0;
}

void CStrategySystem::Navigate() // 给人要去的位置坐标导航（预判）
{
	/*double d[11];
	d[1] = Distance(ball.position, home1.position);
	d[2] = Distance(ball.position, home2.position);
	d[3] = Distance(ball.position, home3.position);
	d[4] = Distance(ball.position, home4.position);
	d[5] = Distance(ball.position, home5.position);
	d[6] = Distance(ball.position, home6.position);
	d[7] = Distance(ball.position, home7.position);
	d[8] = Distance(ball.position, home8.position);
	d[9] = Distance(ball.position, home9.position);
	d[10] = Distance(ball.position, home10.position);*/
	if (65 < ball.position.x <= 590) {

		// 对方罚球区内,包围门框
		if (ball.position.x <= 160 && ball.position.y <= 600 && ball.position.y >= 210) {

			Navigation[1] = CPoint(175, ball.position.y);
			Navigation[2] = CPoint(175, ball.position.y + 20);
			Navigation[3] = CPoint(175, ball.position.y - 20);
			Navigation[4] = CPoint(190, ball.position.y);
			Navigation[5] = CPoint(175, ball.position.y + 10);
			Navigation[6] = CPoint(190, ball.position.y - 10);
			Navigation[7] = CPoint(ball.position.x, 610);
			Navigation[8] = CPoint(ball.position.x, 210);
			Navigation[9] = CPoint(200, ball.position.y + 30);
			Navigation[10] = CPoint(200, ball.position.y - 30);
		}
		// 对方下半场
		else if (ball.position.y >= 607) {
			if (home1.position.x > ball.position.x) {	  // 球员在右
				if (home1.position.y > ball.position.y) { // 球员在右下
					Navigation[1] = ball.position;
				}
				else { // 球员在右下
					Navigation[1] = CPoint(ball.position.x + 10, ball.position.y + 10);
				}
			}
			else {										  // 球员在左
				if (home1.position.y > ball.position.y) { // 左下
					Navigation[1] = ball.position;
				}
				else { // 左上
					Navigation[1] = CPoint(ball.position.x - 10, ball.position.y + 10);
				}
			}
			if (home2.position.x > ball.position.x) {
				if (home2.position.y > ball.position.y) {
					Navigation[2] = ball.position;
				}
				else {
					Navigation[2] = CPoint(ball.position.x + 10, ball.position.y + 20);
				}
			}
			else {
				if (home2.position.y > ball.position.y) {
					Navigation[2] = ball.position;
				}
				else {
					Navigation[2] = CPoint(ball.position.x - 10, ball.position.y - 20);
				}
			}
			if (home3.position.x > ball.position.x) {
				if (home3.position.y > ball.position.y) {
					Navigation[3] = ball.position;
				}
				else {
					Navigation[3] = CPoint(ball.position.x + 20, ball.position.y + 10);
				}
			}
			else {
				if (home3.position.y > ball.position.y) {
					Navigation[3] = ball.position;
				}
				else {
					Navigation[3] = CPoint(ball.position.x - 20, ball.position.y - 10);
				}
			}
			Navigation[4] = CPoint(ball.position.x + 10, ball.position.y + 10);
			Navigation[5] = CPoint(ball.position.x + 10, ball.position.y);
			Navigation[6] = CPoint(ball.position.x + 10, ball.position.y - 10);
			Navigation[7] = CPoint(ball.position.x, ball.position.y + 10);
			Navigation[8] = CPoint(ball.position.x - 10, ball.position.y + 10);
			Navigation[9] = CPoint(ball.position.x + 20, ball.position.y);
			Navigation[10] = CPoint(ball.position.x + 20, ball.position.y + 10);
			//// Navigate(ball.position);
			////  机器人在球右下
			// if (robot->position.y <= ball.position.y && robot->position.x >= ball.position.x) {
			//	Direction(which, ball.position);
			//	// Velocity(which, 127, 127);
			// }
			//// 机器人在球右上
			// else if (robot->position.y > ball.position.y && robot->position.x > ball.position.x) {
			//	Direction(which, CPoint(ball.position.x + 10, ball.position.y));
			//	// Velocity(which, vL, vR);
			// }
			//// 机器人在球左上
			// else if (robot->position.y < ball.position.y && robot->position.x < ball.position.x) {
			//	// Position(which, CPoint(ball.));
			// }
			//// 机器人在球左下
			// else {
			//	Direction(which, CPoint(ball.position.x - 20, ball.position.y));
			// }
		}
		// 对方中场
		else if (ball.position.y >= 217 && ball.position.y < 607) {
			if (home1.position.x > ball.position.x) {
				if (home1.position.y < ball.position.y) {
					Navigation[1] = ball.position;
				}
				else {
					Navigation[1] = CPoint(ball.position.x + 10, ball.position.y - 10);
				}
			}
			else {
				if (home1.position.y < ball.position.y) {
					Navigation[1] = CPoint(ball.position.x, ball.position.y - 10);
				}
				else {
					Navigation[1] = CPoint(ball.position.x - 10, ball.position.y - 10);
				}
			}
			if (home2.position.x > ball.position.x) {
				if (home2.position.y < ball.position.y) {
					Navigation[2] = ball.position;
				}
				else {
					Navigation[2] = CPoint(ball.position.x + 20, ball.position.y + 10);
				}
			}
			else {
				if (home2.position.y < ball.position.y) {
					Navigation[1] = CPoint(ball.position.x, ball.position.y - 15);
				}
				else {
					Navigation[1] = CPoint(ball.position.x - 10, ball.position.y - 15);
				}
			}
			if (home3.position.x > ball.position.x) {
				if (home3.position.y < ball.position.y) {
					Navigation[3] = ball.position;
				}
				else {
					Navigation[3] = CPoint(ball.position.x + 10, ball.position.y + 20);
				}
			}
			else {
				if (home3.position.y < ball.position.y) {
					Navigation[1] = CPoint(ball.position.x + 10, ball.position.y - 15);
				}
				else {
					Navigation[1] = CPoint(ball.position.x - 15, ball.position.y - 10);
				}
			}
			Navigation[4] = CPoint(ball.position.x, ball.position.y - 20);
			Navigation[5] = CPoint(ball.position.x + 10, ball.position.y - 20);
			Navigation[6] = CPoint(ball.position.x + 20, ball.position.y - 10);
			Navigation[7] = CPoint(ball.position.x + 20, ball.position.y + 10);
			Navigation[8] = CPoint(ball.position.x + 20, ball.position.y + 15);
			Navigation[9] = CPoint(ball.position.x + 40, ball.position.y - 20);
			Navigation[10] = CPoint(ball.position.x + 30, ball.position.y - 10);
			//// 机器人在球的右下
			// if (robot->position.x >= ball.position.x && robot->position.y <= ball.position.y) {
			//	Direction(which, ball.position);
			// }
			//// 机器人在球右上
			// else if (robot->position.x > ball.position.x && robot->position.y > ball.position.y) {
			//	// 右上且距离较远
			//	if (robot->position.y >= ball.position.y + 100) {
			//		Direction(which, CPoint(ball.position.x + 20, ball.position.y + 20));
			//	}
			//	// 距离较近
			//	else {
			//		Direction(which, CPoint(ball.position.x + 10, ball.position.y));
			//	}
			// }
			//// 机器人在球左下
			// else if (robot->position.x <= ball.position.x && robot->position.y >= ball.position.y) {
			//	Direction(which, CPoint(ball.position.x - 20, ball.position.y + 20));
			// }
			//// 机器人在球左上
			// else {
			//	Direction(which, CPoint(ball.position.x - 20, ball.position.y - 20));
			// }
		}
		// 上场
		else {
			if (home1.position.x > ball.position.x) {
				if (home1.position.y < ball.position.y) {
					Navigation[1] = ball.position;
				}
				else {
					Navigation[1] = CPoint(ball.position.x + 10, ball.position.y - 10);
				}
			}
			else {
				if (home1.position.y < ball.position.y) {
					Navigation[1] = CPoint(ball.position.x, ball.position.y - 10);
				}
				else {
					Navigation[1] = CPoint(ball.position.x - 10, ball.position.y - 10);
				}
			}
			if (home2.position.x > ball.position.x) {
				if (home2.position.y < ball.position.y) {
					Navigation[2] = ball.position;
				}
				else {
					Navigation[2] = CPoint(ball.position.x + 10, ball.position.y);
				}
			}
			else {
				if (home2.position.y < ball.position.y) {
					Navigation[2] = CPoint(ball.position.x - 5, ball.position.y - 10);
				}
				else {
					Navigation[2] = CPoint(ball.position.x - 10, ball.position.y - 10);
				}
			}
			if (home3.position.x > ball.position.x) {
				if (home3.position.y < ball.position.y) {
					Navigation[3] = ball.position;
				}
				else {
					Navigation[3] = CPoint(ball.position.x + 10, ball.position.y - 15);
				}
			}
			else {
				if (home2.position.y < ball.position.y) {
					Navigation[3] = CPoint(ball.position.x - 5, ball.position.y - 10);
				}
				else {
					Navigation[3] = CPoint(ball.position.x - 10, ball.position.y - 10);
				}
			}
			Navigation[4] = CPoint(ball.position.x - 10, ball.position.y - 10);
			Navigation[5] = CPoint(ball.position.x, ball.position.y - 10);
			Navigation[6] = CPoint(ball.position.x + 10, ball.position.y - 10);
			Navigation[7] = CPoint(ball.position.x + 10, ball.position.y);
			Navigation[8] = CPoint(ball.position.x + 20, ball.position.y + 10);
			Navigation[9] = CPoint(ball.position.x + 30, ball.position.y + 20);
			Navigation[10] = CPoint(ball.position.x + 30, ball.position.y + 25);
			// 机器人在球右上
			// if (robot->position.x >= ball.position.x && robot->position.y <= ball.position.y) {
			//	Direction(which, ball.position);
			//}
			//// 机器人在球右下
			// else if (robot->position.x >= ball.position.x && robot->position.y > ball.position.y) {
			//	Direction(which, CPoint(ball.position.x + 20, ball.position.y));
			// }
			//// 机器人在球左上
			// else if (robot->position.x < ball.position.x && robot->position.y >= ball.position.y) {
			//	Direction(which, CPoint(ball.position.x - 20, ball.position.y));
			// }
			//// 机器人在左下
			// else {
			// }
		}
	}
	// 防守区域(在己方罚球区外)
	else if (ball.position.x > 590 && ball.position.x < 965) {
		CPoint goal;
		double l;

		// 己方上半场
		goal.x = ball.position.x;
		goal.y = 95;
		l = Distance(ball.position, goal);
		if (ball.position.y < 217 && ball.position.y >= 95) {
			Navigation[1].x = ball.position.x;
			Navigation[1].y = 95 + (int)l + 5;
			Navigation[2].x = ball.position.x - (int)sin(15.0 * PI / 180.0) * ((int)l + 5);
			Navigation[2].y = 95 + (int)cos(15.0 * PI / 180.0) * ((int)l + 5);
			Navigation[3].x = ball.position.x + (int)sin(15.0 * PI / 180.0) * ((int)l + 5);
			Navigation[3].y = 95 + (int)cos(15.0 * PI / 180.0) * ((int)l + 5);
			Navigation[4].x = ball.position.x;
			Navigation[4].y = 95 + (int)l + 15;
			Navigation[5].x = ball.position.x - (int)sin(25.0 * PI / 180.0) * ((int)l + 15);
			Navigation[5].y = 95 + (int)cos(25.0 * PI / 180.0) * ((int)l + 15);
			Navigation[6].x = ball.position.x + (int)sin(25.0 * PI / 180.0) * ((int)l + 15);
			Navigation[6].y = 95 + (int)cos(25.0 * PI / 180.0) * ((int)l + 15);
			Navigation[7].x = ball.position.x - (int)sin(45.0 * PI / 180.0) * ((int)l + 15);
			Navigation[7].y = 95 + (int)cos(45.0 * PI / 180.0) * ((int)l + 15);
			Navigation[8].x = ball.position.x + (int)sin(45.0 * PI / 180.0) * ((int)l + 15);
			Navigation[8].y = 95 + (int)cos(45.0 * PI / 180.0) * ((int)l + 15);
			Navigation[9].x = ball.position.x - (int)sin(30.0 * PI / 180.0) * ((int)l + 25);
			Navigation[9].y = 95 + (int)cos(30.0 * PI / 180.0) * ((int)l + 25);
			Navigation[10].x = ball.position.x + (int)sin(30.0 * PI / 180.0) * ((int)l + 25);
			Navigation[10].y = 95 + (int)cos(30.0 * PI / 180.0) * ((int)l + 25);
		}
		// 己方中场
		else if (ball.position.y > 217 && ball.position.y <= 607) {
			// 球在中场上侧，要把球往上压
			if (ball.position.y < 409) {
				Navigation[1].x = ball.position.x;
				Navigation[1].y = 95 + (int)l + 5;
				Navigation[2].x = ball.position.x - (int)sin(15.0 * PI / 180.0) * ((int)l + 5);
				Navigation[2].y = 95 + (int)cos(15.0 * PI / 180.0) * ((int)l + 5);
				Navigation[3].x = ball.position.x + (int)sin(15.0 * PI / 180.0) * ((int)l + 5);
				Navigation[3].y = 95 + (int)cos(15.0 * PI / 180.0) * ((int)l + 5);
				Navigation[4].x = ball.position.x;
				Navigation[4].y = 95 + (int)l + 15;
				Navigation[5].x = ball.position.x - (int)sin(25.0 * PI / 180.0) * ((int)l + 15);
				Navigation[5].y = 95 + (int)cos(25.0 * PI / 180.0) * ((int)l + 15);
				Navigation[6].x = ball.position.x + (int)sin(25.0 * PI / 180.0) * ((int)l + 15);
				Navigation[6].y = 95 + (int)cos(25.0 * PI / 180.0) * ((int)l + 15);
				Navigation[7].x = ball.position.x - (int)sin(45.0 * PI / 180.0) * ((int)l + 15);
				Navigation[7].y = 95 + (int)cos(45.0 * PI / 180.0) * ((int)l + 15);
				Navigation[8].x = ball.position.x + (int)sin(45.0 * PI / 180.0) * ((int)l + 15);
				Navigation[8].y = 95 + (int)cos(45.0 * PI / 180.0) * ((int)l + 15);
				Navigation[9].x = ball.position.x - (int)sin(30.0 * PI / 180.0) * ((int)l + 25);
				Navigation[9].y = 95 + (int)cos(30.0 * PI / 180.0) * ((int)l + 25);
				Navigation[10].x = ball.position.x + (int)sin(30.0 * PI / 180.0) * ((int)l + 25);
				Navigation[10].y = 95 + (int)cos(30.0 * PI / 180.0) * ((int)l + 25);
			}
			// 球在中场下侧，要把球往下压

			else {
				goal.x = ball.position.x;
				goal.y = 723;
				l = Distance(ball.position, goal);
				Navigation[1].x = ball.position.x;
				Navigation[1].y = 723 - (int)l - 5;
				Navigation[2].x = ball.position.x - (int)sin(15.0 * PI / 180.0) * ((int)l + 5);
				Navigation[2].y = 723 - (int)cos(15.0 * PI / 180.0) * ((int)l + 5);
				Navigation[3].x = ball.position.x + (int)sin(15.0 * PI / 180.0) * ((int)l + 5);
				Navigation[3].y = 723 - (int)cos(15.0 * PI / 180.0) * ((int)l + 5);
				Navigation[4].x = ball.position.x;
				Navigation[4].y = 723 - (int)l - 15;
				Navigation[5].x = ball.position.x - (int)sin(25.0 * PI / 180.0) * ((int)l + 15);
				Navigation[5].y = 723 - (int)cos(25.0 * PI / 180.0) * ((int)l + 15);
				Navigation[6].x = ball.position.x + (int)sin(25.0 * PI / 180.0) * ((int)l + 15);
				Navigation[6].y = 723 - (int)cos(25.0 * PI / 180.0) * ((int)l + 15);
				Navigation[7].x = ball.position.x - (int)sin(45.0 * PI / 180.0) * ((int)l + 15);
				Navigation[7].y = 723 - (int)cos(45.0 * PI / 180.0) * ((int)l + 15);
				Navigation[8].x = ball.position.x + (int)sin(45.0 * PI / 180.0) * ((int)l + 15);
				Navigation[8].y = 723 - (int)cos(45.0 * PI / 180.0) * ((int)l + 15);
				Navigation[9].x = ball.position.x - (int)sin(30.0 * PI / 180.0) * ((int)l + 25);
				Navigation[9].y = 723 - (int)cos(30.0 * PI / 180.0) * ((int)l + 25);
				Navigation[10].x = ball.position.x + (int)sin(30.0 * PI / 180.0) * ((int)l + 25);
				Navigation[10].y = 723 - (int)cos(30.0 * PI / 180.0) * ((int)l + 25);
			}
		}
		// 己方下半场

		else if (ball.position.y > 607) {
			goal.x = ball.position.x;
			goal.y = 723;
			l = Distance(ball.position, goal);
			Navigation[1].x = ball.position.x;
			Navigation[1].y = 723 - (int)l - 5;
			Navigation[2].x = ball.position.x - (int)sin(15.0 * PI / 180.0) * ((int)l + 5);
			Navigation[2].y = 723 - (int)cos(15.0 * PI / 180.0) * ((int)l + 5);
			Navigation[3].x = ball.position.x + (int)sin(15.0 * PI / 180.0) * ((int)l + 5);
			Navigation[3].y = 723 - (int)cos(15.0 * PI / 180.0) * ((int)l + 5);
			Navigation[4].x = ball.position.x;
			Navigation[4].y = 723 - (int)l - 15;
			Navigation[5].x = ball.position.x - (int)sin(25.0 * PI / 180.0) * ((int)l + 15);
			Navigation[5].y = 723 - (int)cos(25.0 * PI / 180.0) * ((int)l + 15);
			Navigation[6].x = ball.position.x + (int)sin(25.0 * PI / 180.0) * ((int)l + 15);
			Navigation[6].y = 723 - (int)cos(25.0 * PI / 180.0) * ((int)l + 15);
			Navigation[7].x = ball.position.x - (int)sin(45.0 * PI / 180.0) * ((int)l + 15);
			Navigation[7].y = 723 - (int)cos(45.0 * PI / 180.0) * ((int)l + 15);
			Navigation[8].x = ball.position.x + (int)sin(45.0 * PI / 180.0) * ((int)l + 15);
			Navigation[8].y = 723 - (int)cos(45.0 * PI / 180.0) * ((int)l + 15);
			Navigation[9].x = ball.position.x - (int)sin(30.0 * PI / 180.0) * ((int)l + 25);
			Navigation[9].y = 723 - (int)cos(30.0 * PI / 180.0) * ((int)l + 25);
			Navigation[10].x = ball.position.x + (int)sin(30.0 * PI / 180.0) * ((int)l + 25);
			Navigation[10].y = 723 - (int)cos(30.0 * PI / 180.0) * ((int)l + 25);
		}
	}
}

void CStrategySystem::control(int which) {
	Robot2 *robot;
	// switch (which) {
	// case HOME1:
	//	robot = &home1;
	//	break;
	// case HOME2:
	//	robot = &home2;
	//	break;
	// case HOME3:
	//	robot = &home3;
	//	break;
	// case HOME4:
	//	robot = &home4;
	//	break;
	// case HOME5:
	//	robot = &home5;
	//	break;
	// case HOME6:
	//	robot = &home6;
	//	break;
	// case HOME7:
	//	robot = &home7;
	//	break;
	// case HOME8:
	//	robot = &home8;
	//	break;
	// case HOME9:
	//	robot = &home9;
	//	break;
	// case HOME10:
	//	robot = &home10;
	//	break;
	// case HGOALIE:
	//	robot = &hgoalie;
	//	break;
	// }
	DirectionSE(which, Navigation[which]);
}

void CStrategySystem::Possession() {
	Navigate();
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
	if (ball.position.y>=337&& ball.position.x < 290) // 球在敌方下半
	{
		if (Distance(ball.position, home2.position) <= 75)//2可射
		{
			Shot(HOME2, 1);//2
			control(1);//1
			for (int i = 3; i < 9; i++) // 3-8
				control(i);
			if (!Canshot()) // 9，10
			{
				control(9);
				control(10);
			}
		}	
		else if (Distance(ball.position, home3.position) <= 75 && ball.position.y <= 481&&ball.position.y>=505)//3可射
		{
			Shot(HOME3, 0);//3
			control(1);//1
			control(2);	   // 2
			for (int i = 3; i < 9; i++) // 4-8
				control(i);
			if (!Canshot()) // 9，10
			{
				control(9);
				control(10);
			}
		}
		else							 // 其它情况
			for (int i = 1; i < 11; i++) // 1-10
				control(i);
	}
	else if (ball.position.y < 481 && ball.position.x < 290) // 球在敌方上半
	{
		if (Distance(ball.position, home3.position) <= 75)//3可射
		{
			Shot(HOME3, 0);//3
			control(1);						// 1
			control(2);	   // 2
			for (int i = 3; i < 9; i++) // 4-8
				control(i);
			if (!Canshot()) // 9，10
			{
				control(9);
				control(10);
			}
		}	
		else if (Distance(ball.position, home2.position) <= 75 && ball.position.y >= 337&&ball.position.y<=313)//2可射
		{
			Shot(HOME2, 1);//2
			control(1);	   // 1
			for (int i = 3; i < 9; i++) // 3-8
				control(i);
			if(!Canshot()) // 9，10
			{
				control(9);
				control(10);
			}
		}
		else							 // 其它情况
			for (int i = 1; i < 11; i++) // 1-10
				control(i);
	}
	else//其它情况
		for (int i = 1; i < 11; i++)//1-10
			control(i);
}
// 守门
void CStrategySystem::Goalie() {
	static bool flag;
	static double dy;
	int gx = ball.position.x < 950 ? 950 : 965;
	// if (ball.position.x <= 873 && ball.position.y >= 217 && ball.position.y <= 607 && hgoalie.position.y > ball.position.y) {
	// 	Position(HGOALIE, ball.position);
	// }
	// TODO: 防点球
	// if (CheckBallPosF1() == 1 || isPenalty) {
	// 	isPenalty = true;
	// 	if (ball.position.y < 409) {
	// 		Position(which, CPoint(gx, 217));
	// 	}
	// 	else {
	// 		Position(which, CPoint(gx, 607));
	// 	}
	// 	if (ball.position.x < 900) {
	// 		PositionPro(which, CPoint(ball.position));
	// 	}
	// 	if (ball.oldPosition.x > ball.position.x || ball.position.x >= 965) {
	// 		isPenalty = false;
	// 	}
	// }
	// else {

	// 球在我方半场且在预测区域远离球门
	if (ball.position.x > 515 && ball.position.x < 873 || ball.position.x > 873 && ball.position.x < ball.oldPosition.x) {
		flag = true;
		if (ball.position.y < 313)
			Direction(HGOALIE, CPoint(gx, 313));
		else if (ball.position.y > 505)
			Direction(HGOALIE, CPoint(gx, 505));
		else
			Direction(HGOALIE, CPoint(gx, ball.position.y));
	}
	// 球在中预测区域靠近球门
	else if (ball.position.x > 515 && ball.position.y > 217 && ball.position.y < 607) {
		if (ball.position.x > 900) {
			double dyy = (hgoalie.position.x - 873) * ABS(ball.position.y - hgoalie.position.y) * 1.0 / (hgoalie.position.x - ball.position.x);
			if (ball.position.y > hgoalie.position.y)
				Direction(HGOALIE, CPoint(873, hgoalie.position.y + dyy));
			else
				Direction(HGOALIE, CPoint(873, hgoalie.position.y - dyy));
		}
		else {
			if (flag) {
				dy = (gx - ball.position.x) * ABS(ball.position.y - ball.oldPosition.y) * 1.0 / (ball.position.x - ball.oldPosition.x);
				flag = false;
			}
			if (ball.position.y > ball.oldPosition.y)
				Direction(HGOALIE, CPoint(gx, ball.position.y + dy));
			else
				Direction(HGOALIE, CPoint(gx, ball.position.y - dy));
		}
	}
	// 球在上预测区域靠近球门
	else if (ball.position.x > 515 && ball.position.y < 217 && ball.position.y >= ball.oldPosition.y) {
		flag = true;
		if (hgoalie.position.y > 217) {
			Direction(HGOALIE, ball.position);
		}
		else
			Direction(HGOALIE, CPoint(gx, 265));
	}
	// 球在下预测区域靠近球门
	else if (ball.position.x > 515 && ball.position.y <= ball.oldPosition.y) {
		flag = true;
		if (hgoalie.position.y < 607) {
			Direction(HGOALIE, ball.position);
		}
		else
			Direction(HGOALIE, CPoint(gx, 556));
	}
	// 球在对方半场
	else {
		flag = true;
		Direction(HGOALIE, CPoint(gx, 409));
	}
	// }
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

void CStrategySystem::DirectionSE(int which, CPoint point) {
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
	switch (Status()) {
	case 1:
		Penalty();
		flag = true;
		break;
	case 2:
	case 3:
	case 4:
	case 5:
		Freeball();
		break;
	default:
		Possession();
		flag = true;
		break;
	}
	Goalie();
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
		ball.oldPosition = bal.oldPosition;
		ball.angle = bal.angle;

		home1.position = ho1.position;
		home1.oldPosition = ho1.oldPosition;
		home1.angle = ho1.angle;

		home2.position = ho2.position;
		home2.oldPosition = ho2.oldPosition;
		home2.angle = ho2.angle;

		home3.position = ho3.position;
		home3.oldPosition = ho3.oldPosition;
		home3.angle = ho3.angle;

		home4.position = ho4.position;
		home4.oldPosition = ho4.oldPosition;
		home4.angle = ho4.angle;

		home5.position = ho5.position;
		home5.oldPosition = ho5.oldPosition;
		home5.angle = ho5.angle;

		home6.position = ho6.position;
		home6.oldPosition = ho6.oldPosition;
		home6.angle = ho6.angle;

		home7.position = ho7.position;
		home7.oldPosition = ho7.oldPosition;
		home7.angle = ho7.angle;

		home8.position = ho8.position;
		home8.oldPosition = ho8.oldPosition;
		home8.angle = ho8.angle;

		home9.position = ho9.position;
		home9.oldPosition = ho9.oldPosition;
		home9.angle = ho9.angle;

		home10.position = ho10.position;
		home10.oldPosition = ho10.oldPosition;
		home10.angle = ho10.angle;

		hgoalie.position = hgo.position;
		hgoalie.oldPosition = hgo.oldPosition;
		hgoalie.angle = hgo.angle;

		opponent.position1 = opp.position1;
		opponent.oldPosition1 = opp.oldPosition1;
		opponent.position2 = opp.position2;
		opponent.oldPosition2 = opp.oldPosition2;
		opponent.position3 = opp.position3;
		opponent.oldPosition3 = opp.oldPosition3;
		opponent.position4 = opp.position4;
		opponent.oldPosition4 = opp.oldPosition4;
		opponent.position5 = opp.position5;
		opponent.oldPosition5 = opp.oldPosition5;
		opponent.position6 = opp.position6;
		opponent.oldPosition6 = opp.oldPosition6;
		opponent.position7 = opp.position7;
		opponent.oldPosition7 = opp.oldPosition7;
		opponent.position8 = opp.position8;
		opponent.oldPosition8 = opp.oldPosition8;
		opponent.position9 = opp.position9;
		opponent.oldPosition9 = opp.oldPosition9;
		opponent.position10 = opp.position10;
		opponent.oldPosition10 = opp.oldPosition10;
		opponent.position11 = opp.position11;
		opponent.oldPosition11 = opp.oldPosition11;
	}
	else {
		ball.position.x = 1030 - bal.position.x;
		ball.oldPosition.x = 1030 - bal.oldPosition.x;
		ball.position.y = 818 - bal.position.y;
		ball.oldPosition.y = 818 - bal.oldPosition.y;
		if (ball.angle > 0)
			ball.angle = bal.angle - 180;
		else
			ball.angle = 180 + bal.angle;

		home1.position.x = 1030 - ho1.position.x;
		home1.oldPosition.x = 1030 - ho1.oldPosition.x;
		home1.position.y = 818 - ho1.position.y;
		home1.oldPosition.y = 818 - ho1.oldPosition.y;
		if (home1.angle > 0)
			home1.angle = ho1.angle - 180;
		else
			home1.angle = 180 + ho1.angle;
		home2.position.x = 1030 - ho2.position.x;
		home2.oldPosition.x = 1030 - ho2.oldPosition.x;
		home2.position.y = 818 - ho2.position.y;
		home2.oldPosition.y = 818 - ho2.oldPosition.y;
		if (home2.angle > 0)
			home2.angle = ho2.angle - 180;
		else
			home2.angle = 180 + ho2.angle;
		home3.position.x = 1030 - ho3.position.x;
		home3.oldPosition.x = 1030 - ho3.oldPosition.x;
		home3.position.y = 818 - ho3.position.y;
		home3.oldPosition.y = 818 - ho3.oldPosition.y;
		if (home3.angle > 0)
			home3.angle = ho3.angle - 180;
		else
			home3.angle = 180 + ho3.angle;
		home4.position.x = 1030 - ho4.position.x;
		home4.oldPosition.x = 1030 - ho4.oldPosition.x;
		home4.position.y = 818 - ho4.position.y;
		home4.oldPosition.y = 818 - ho4.oldPosition.y;
		if (home4.angle > 0)
			home4.angle = ho4.angle - 180;
		else
			home4.angle = 180 + ho4.angle;
		home5.position.x = 1030 - ho5.position.x;
		home5.oldPosition.x = 1030 - ho5.oldPosition.x;
		home5.position.y = 818 - ho5.position.y;
		home5.oldPosition.y = 818 - ho5.oldPosition.y;
		if (home5.angle > 0)
			home5.angle = ho5.angle - 180;
		else
			home5.angle = 180 + ho5.angle;
		//*/
		home6.position.x = 1030 - ho6.position.x;
		home6.oldPosition.x = 1030 - ho6.oldPosition.x;
		home6.position.y = 818 - ho6.position.y;
		home6.oldPosition.y = 818 - ho6.oldPosition.y;
		///*
		if (home6.angle > 0)
			home6.angle = ho6.angle - 180;
		else
			home6.angle = 180 + ho6.angle;
		//*/
		home7.position.x = 1030 - ho7.position.x;
		home7.oldPosition.x = 1030 - ho7.oldPosition.x;
		home7.position.y = 818 - ho7.position.y;
		home7.oldPosition.y = 818 - ho7.oldPosition.y;
		///*
		if (home7.angle > 0)
			home7.angle = ho7.angle - 180;
		else
			home7.angle = 180 + ho7.angle;
		//*/
		home8.position.x = 1030 - ho8.position.x;
		home8.oldPosition.x = 1030 - ho8.oldPosition.x;
		home8.position.y = 818 - ho8.position.y;
		home8.oldPosition.y = 818 - ho8.oldPosition.y;
		///*
		if (home8.angle > 0)
			home8.angle = ho8.angle - 180;
		else
			home8.angle = 180 + ho8.angle;
		//*/
		home9.position.x = 1030 - ho9.position.x;
		home9.oldPosition.x = 1030 - ho9.oldPosition.x;
		home9.position.y = 818 - ho9.position.y;
		home9.oldPosition.y = 818 - ho9.oldPosition.y;
		///*
		if (home9.angle > 0)
			home9.angle = ho9.angle - 180;
		else
			home9.angle = 180 + ho9.angle;
		//*/
		home10.position.x = 1030 - ho10.position.x;
		home10.oldPosition.x = 1030 - ho10.oldPosition.x;
		home10.position.y = 818 - ho10.position.y;
		home10.oldPosition.y = 818 - ho10.oldPosition.y;
		///*
		if (home10.angle > 0)
			home10.angle = ho10.angle - 180;
		else
			home10.angle = 180 + ho10.angle;
		//*/
		hgoalie.position.x = 1030 - hgo.position.x;
		hgoalie.oldPosition.x = 1030 - hgo.oldPosition.x;
		hgoalie.position.y = 818 - hgo.position.y;
		hgoalie.oldPosition.y = 818 - hgo.oldPosition.y;
		///*
		if (hgoalie.angle > 0)
			hgoalie.angle = hgo.angle - 180;
		else
			hgoalie.angle = 180 + hgo.angle;
		//*/
		opponent.position1.x = 1030 - opp.position1.x;
		opponent.oldPosition1.x = 1030 - opp.oldPosition1.x;
		opponent.position2.x = 1030 - opp.position2.x;
		opponent.oldPosition2.x = 1030 - opp.oldPosition2.x;
		opponent.position3.x = 1030 - opp.position3.x;
		opponent.oldPosition3.x = 1030 - opp.oldPosition3.x;
		opponent.position4.x = 1030 - opp.position4.x;
		opponent.oldPosition4.x = 1030 - opp.oldPosition4.x;
		opponent.position5.x = 1030 - opp.position5.x;
		opponent.oldPosition5.x = 1030 - opp.oldPosition5.x;
		opponent.position6.x = 1030 - opp.position6.x;
		opponent.oldPosition6.x = 1030 - opp.oldPosition6.x;
		opponent.position7.x = 1030 - opp.position7.x;
		opponent.oldPosition7.x = 1030 - opp.oldPosition7.x;
		opponent.position8.x = 1030 - opp.position8.x;
		opponent.oldPosition8.x = 1030 - opp.oldPosition8.x;
		opponent.position9.x = 1030 - opp.position9.x;
		opponent.oldPosition9.x = 1030 - opp.oldPosition9.x;
		opponent.position10.x = 1030 - opp.position10.x;
		opponent.oldPosition10.x = 1030 - opp.oldPosition10.x;
		opponent.position11.x = 1030 - opp.position11.x;
		opponent.oldPosition11.x = 1030 - opp.oldPosition11.x;

		opponent.position1.y = 818 - opp.position1.y;
		opponent.oldPosition1.y = 818 - opp.oldPosition1.y;
		opponent.position2.y = 818 - opp.position2.y;
		opponent.oldPosition2.y = 818 - opp.oldPosition2.y;
		opponent.position3.y = 818 - opp.position3.y;
		opponent.oldPosition3.y = 818 - opp.oldPosition3.y;
		opponent.position4.y = 818 - opp.position4.y;
		opponent.oldPosition4.y = 818 - opp.oldPosition4.y;
		opponent.position5.y = 818 - opp.position5.y;
		opponent.oldPosition5.y = 818 - opp.oldPosition5.y;
		opponent.position6.y = 818 - opp.position6.y;
		opponent.oldPosition6.y = 818 - opp.oldPosition6.y;
		opponent.position7.y = 818 - opp.position7.y;
		opponent.oldPosition7.y = 818 - opp.oldPosition7.y;
		opponent.position8.y = 818 - opp.position8.y;
		opponent.oldPosition8.y = 818 - opp.oldPosition8.y;
		opponent.position9.y = 818 - opp.position9.y;
		opponent.oldPosition9.y = 818 - opp.oldPosition9.y;
		opponent.position10.y = 818 - opp.position10.y;
		opponent.oldPosition10.y = 818 - opp.oldPosition10.y;
		opponent.position11.y = 818 - opp.position11.y;
		opponent.oldPosition11.y = 818 - opp.oldPosition11.y;
	}
}

CStrategySystem::CStrategySystem(int id) {
	int t = 11;
	while (t--) {
		Navigation.push_back(ball.position);
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