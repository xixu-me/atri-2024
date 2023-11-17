#include "general.h"

#ifndef _INSIDE_VISUAL_CPP_STRATEGYSYSTEM
#define _INSIDE_VISUAL_CPP_STRATEGYSYSTEM
class CStrategySystem : public CObject {
	DECLARE_DYNAMIC(CStrategySystem)
public:
	void Action();
	// ~CStrategySystem();
	CStrategySystem(int id);
	void ReceiveData(Robot1 bal, Robot2 ho1, Robot2 ho2, Robot2 ho3, Robot2 ho4,
		Robot2 ho5, Robot2 ho6, Robot2 ho7, Robot2 ho8, Robot2 ho9,
		Robot2 ho10, Robot2 hgo, Robot3 opp);

#ifdef _DEBUG
#endif // _DEBUG
private:
	void Penalty();				   // 罚球
	void Freeball();			   // 争球
	void Shot(int which, bool de); // 射门
	void Possession();			   // 控球
	void Goalie();				   // 守门

	void spin(int which, bool isClockwise); // 自旋
	void shot1(int which, double o,CPoint t);		// 直射
	void Canshot();							// 射？
	int search();							// 查找在禁区里的机器人
	void control(int which);
	void ccd(int which, double d, double j);									 // 曲线行驶
	double atwo(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4); // 两直线间夹角
	double Distance(CPoint point1, CPoint point2);								 // 计算两点之间的距离
	double Angle(CPoint point1, CPoint point2);									 // 计算两点之间的角度
	void Direction(int which, CPoint point);
	void DirectionSE(int which, CPoint point); // 不进禁区版 Direction
	void PositionSE(int which, CPoint point);  // 不进禁区版 Position
	void Rush(int which, CPoint point);		   // 冲向某点

	int Status(); // 判断状态

	void Stop(int which);
	void Position(int which, CPoint point);
	void Velocity(int which, int vL, int vR);
	void Angle(int which, int desired_angle);

	CRect boundRect;
	int m_nStrategy;
	int m_OurTeam;
	int m_nGameArea;
	double ShootLen;
	int nShoot;
	int nSweep;
	int nKick2;
	CPoint ShootVar;
	CPoint KickVar;
	double KickLen;
	CCommand C_Home3;
	CCommand C_Home2;
	CCommand C_Home1;
	CCommand C_Home4;
	CCommand C_Home5;
	CCommand C_Home6;
	CCommand C_Home7;
	CCommand C_Home8;
	CCommand C_Home9;
	CCommand C_Home10;
	CCommand C_Home11;
	Robot1 ball;
	Robot2 home1, home2, home3, home4, home5, home6, home7, home8, home9, home10, hgoalie;
	Robot3 opponent;

	bool flag;

	// void Think();

public:
	int command[35];
};

#endif // _INSIDE_VISUAL_CPP_STRATEGYSYSTEM
