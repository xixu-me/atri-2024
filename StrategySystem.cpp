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
void CStrategySystem::Penalty() {
	// srand(time(nullptr));
	// int x = rand() % 2;
	// if (x) {
	// 	if (...)
	// 		Direction(HOME1, ball.position);
	// 	else
	// 		Position(HOME1, ...);
	// }
	// else {
	// 	if (...)
	// 		...
	// }
}

// 争球
void CStrategySystem::Freeball() {
	int d = 3;
	if (Status() == 2) { // 左上

		if (Distance(home3.position, ball.position) > d)
			Direction(HOME3, ball.position);
		else
			spin(HOME3, false);
	}
	else if (Status() == 3) { // 左下
		if (Distance(home3.position, ball.position) > d)
			Direction(HOME1, ball.position);
		else
			spin(HOME1, true);
	}
	else if (Status() == 4) { // 右上
		if (Distance(home3.position, ball.position) > d)
			Direction(HOME10, ball.position);
		else
			spin(HOME10, true);
	}

	else if (Status() == 5) { // 右下

		if (Distance(home3.position, ball.position) > d)
			Direction(HOME7, ball.position);
		else
			spin(HOME10, false);
	}
}

void CStrategySystem::spin(int which, bool isClockwise) { // 自旋
	if (isClockwise)
		Velocity(which, 127, -127);
	else
		Velocity(which, -127, 127);
}

// 射门
void CStrategySystem::Shot(int which) {
	Robot2 *robot;
	switch (which) {
	case HOME9:
		robot = &home9;
		break;
	case HOME1:
		robot = &home1;
		break;
	}
	CPoint t1, t2, t3, t4; // t1球，t2机器人,t3机器人要移动到的点，t4门
	t1.x = ball.position.x;
	t1.y = ball.position.y;
	if(t1.y<=313)
	{t4.x=65;t4.y=590;}
	if(t1.y>313)
	t4.x=65;t4.y=330;
	//double O=Angle(t1,t4);
	double O = atan(t4.y - t1.y * 1.0 / t4.x - t1.x);
	t3.x=t1.x+cos(180-O)*19.0;
	t3.y=t1.y+sin(180-O)*19.0;
	if (Distance(t1, t2) <= 20 &&Distance(t1, t2) >=0)
		shot1(which);
	else 
	{ 
		Position(which, t3); // 机器人到足够近的点
		t2.x = robot->position.x;
		t2.y = robot->position.y;
	}
	/*if (Distance(t1, t2) <= 10&&Distance(t1, t2) >=0)
		shot1(which);*/
	// if ()
	// 	shot2();
}

void CStrategySystem::shot1(int which) { // 直射
	Robot2 *robot;
	switch (which) {
	case HOME9:
		robot = &home9;
		break;
	case HOME1:
		robot = &home1;
		break;
	}
	CPoint t; // t球
	t.x = ball.position.x;
	t.y = ball.position.y;
	double o = atan(robot->position.y - t.y * 1.0 / robot->position.x - t.x); // 机器人面向球的角度
	Angle(which, o);														  // 朝球转角度
	Velocity(which, 127, 127);												  // 射门
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

void CStrategySystem::shot2(int which) { // 旋射
	Robot2 *robot;
	switch (which) {
	case HOME9:
		robot = &home9;
		break;
	case HOME10:
		robot = &home10;
		break;
	}
}

int CStrategySystem::search() { // 查找在禁区里的机器人
	return 0;
}

void CStrategySystem::control(int which) {
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
	// 进攻区域
	if (ball.position.x <= 665) {
		// 对方罚球区内
		if (ball.position.x <= 160 && ball.position.y >= 607 && ball.position.y <= 217) {
			Position(which, CPoint(160, ball.position.y));
		}
		// 对方下半场
		else if (ball.position.y > 607) {
			// 机器人在球右下
			if (robot->position.y < ball.position.y && robot->position.x > ball.position.x) {
				Position(which, ball.position);
			}
			// 机器人在球右上
			else if (robot->position.y > ball.position.y && robot->position.x > ball.position.x) {
				// 绕道球下方
				// Velocity(which, vL, vR);
			}
			// 机器人在球左上
			else if (robot->position.y < ball.position.y && robot->position.x < ball.position.x) {
			}
			// 机器人在球左下
			else {
			}
		}
		// 对方中场
		else if (ball.position.y < 217 && ball.position.y >= 572) {
			// 机器人在球的右下或右中
			if (robot->position.x > ball.position.x && robot->position.y <= ball.position.y) {
				Direction(which, ball.position);
			}
			// 在机器人在球右上
			else if (robot->position.x > ball.position.x && robot->position.y > ball.position.y) {
				// 右上且距离较远
				if (robot->position.y >= ball.position.y + 100) {
					Position(which, CPoint(ball.position.x - 20, ball.position.y + 30));
				}
				// 距离较近
				else {
					Position(which, CPoint(ball.position.x - 10, ball.position.y));
				}
			}
		}
		// else
	}
	else if (robot->position.x > ball.position.x && robot->position.x >= 160)
		Direction(which, ball.position);
}
// 控球，需调用 Shot
void CStrategySystem::Possession() {
	control(1);
	control(2);
	control(3);
	control(4);
	control(5);
	control(6);
	control(7);
	control(8);
	control(9);
	control(10);

	// TODO: Possession
	// 定义五个控球的机器人
	/*Robot2 robot1 = home1, robot2 = home2, robot3 = home3, robot4 = home4, robot5 = home5;
	CPoint t0, t1, t2, t3, t4, t5;
	t0.x = ball.position.x;
	t0.y = ball.position.y;*/

	// if (ball.position.x < 515 && home2.position.x > ball.position.x && home2.position.x < ball.position.x）{
	// 	Position(HOME2, CPoint(ball.position.x, ball.position.y));
	// }
	// 个人行走细节策略：己方人不挡道，所有控球人绕球进攻方的侧后
	//  宏观占位策略：进攻时留3个人守在门框，防守时所有人压球于角
	//  宏观（控球时）占位策略：控球人要均匀围满球前进方向的侧后，不可扎堆于一点
	//  宏观踢球策略：
	// 如果球在左1/3区，离球最近的6个机器人尽力往球门踢（攻）
	// 如果球在中1/3区，离球最近的6个机器人往左方上下侧踢（攻）
	// 如果球在右1/3区，所有机器人往右方两角压球。(防)
}

// 守门
void CStrategySystem::Goalie() {
	static bool flag = true;
	int gx = ball.position.x < 950 ? 950 : 965;

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
	if (ball.position.x > 515 && ball.position.x < 900 || ball.position.x > 900 && ball.position.x < ball.oldPosition.x) {
		flag = true;
		if (ball.position.y < 313)
			Position(HGOALIE, CPoint(gx, 313));
		else if (ball.position.y > 505)
			Position(HGOALIE, CPoint(gx, 505));
		else
			Position(HGOALIE, CPoint(gx, ball.position.y));
	}
	// 球在中预测区域靠近球门
	else if (ball.position.x > 515 && ball.position.y > 217 && ball.position.y < 607) {
		double dy = 0;
		if (flag)
			dy = (gx - ball.position.x) * ABS(ball.position.y - ball.oldPosition.y) * 1.0 / (ball.position.x - ball.oldPosition.x);
		flag = false;
		if (ball.position.y > ball.oldPosition.y)
			Position(HGOALIE, CPoint(gx, ball.position.y + dy));
		else
			Position(HGOALIE, CPoint(gx, ball.position.y - dy));
		if (ball.position.x > 900) {
			double dy = (hgoalie.position.x - 873) * ABS(ball.position.y - hgoalie.position.y) * 1.0 / (hgoalie.position.x - ball.position.x);
			if (ball.position.y > hgoalie.position.y)
				Position(HGOALIE, CPoint(873, hgoalie.position.y + dy));
			else
				Position(HGOALIE, CPoint(873, hgoalie.position.y - dy));
		}
	}
	// 球在上预测区域靠近球门
	else if (ball.position.x > 515 && ball.position.y < 217 && ball.position.y >= ball.oldPosition.y) {
		flag = true;
		if (hgoalie.position.y > 217) {
			Direction(HGOALIE, CPoint(ball.position));
		}
		Position(HGOALIE, CPoint(gx, 265));
	}
	// 球在下预测区域靠近球门
	else if (ball.position.x > 515 && ball.position.y <= ball.oldPosition.y) {
		flag = true;
		if (hgoalie.position.y < 607) {
			Direction(HGOALIE, CPoint(ball.position));
		}
		Position(HGOALIE, CPoint(gx, 556));
	}
	// 球在对方半场
	else {
		flag = true;
		Position(HGOALIE, CPoint(gx, 409));
	}
	//}
}

double CStrategySystem::Distance(CPoint point1, CPoint point2) {
	return sqrt(1.0 * (point1.x - point2.x) * (point1.x - point2.x) + 1.0 * (point1.y - point2.y) * (point1.y - point2.y));
}

double CStrategySystem::Angle(CPoint point1, CPoint point2) {
	return atan2(1.0 * (point1.y - point2.y), 1.0 * (point2.x - point1.x));
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

// 判断状态，1 为罚球，0 为正常, 其他为争球
int CStrategySystem::Status() {
	if (ball.position.x <= 309 && ball.position.x >= 279) {
		if (ball.position.y >= 394 && ball.position.y <= 424)
			return 1;
		if (ball.position.y <= 190 && ball.position.y >= 180)
			return 2; // 左上争球点
		if (ball.position.y <= 638 && ball.position.y >= 628)
			return 3; // 左下争球点
	}
	if (ball.position.x <= 950 && ball.position.x >= 920) {
		if (ball.position.y <= 190 && ball.position.y >= 180)
			return 4; // 右上争球点
		if (ball.position.y <= 638 && ball.position.y >= 628)
			return 5; // 右下争球点
	}
	return 0;
}

void CStrategySystem::Action() {
	// switch (Status()) {
	// case 1:
	// 	Penalty();
	// 	break;
	// case 2:
	// case 3:
	// case 4:
	// case 5:
	// 	Freeball();
	// 	break;
	// default:
	// 	Possession();
	// 	break;
	// }
	// Goalie();
	Shot(1);
	Goalie();
	// Shot(1);
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