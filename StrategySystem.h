#include "general.h"

#ifndef _INSIDE_VISUAL_CPP_STRATEGYSYSTEM
#define _INSIDE_VISUAL_CPP_STRATEGYSYSTEM

// 阵型球员相对中央球员的位置结构体
struct RelPos {
	int id;
	double dis;
	double ang;
};

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
	void Penalty();	   // 罚球
	void Freeball();   // 争球
	void Possession(); // 控球
	void Goalie();	   // 守门

	CPoint *pos; // 球员位置
	RelPos *rp;	 // 阵型球员相对中央球员的位置

	int cp_id();									// 中央球员 ID
	void fp_sort(RelPos *rp, int h = 0, int t = 0); // 阵型球员排序，h 为该层前的球员数量，t 为包含该层后的球员数量
	int fm_id();									// 阵型 ID
	CPoint coor(int which);							// 返回机器人的位置

	// void spin(int which, bool isClockwise);	   // 自旋
	void shot1(int which, double o, CPoint t); // 直射
	bool canshot();							   // 射？
	int search1();							   // 查找在大区里的机器人
	int search2();							   // 查找在小区里的机器人
	//CPoint searchNear(int which);			   // 查找最近的机器人
	// void control(int which);
	// void ccd(int which, double d, double j);									 // 曲线行驶
	double atwo(int x1, int y1, int x2, int y2, int x3, int y3, int x4, int y4); // 两直线间夹角
	// void navigate();
	void shot(int which, bool de);			 // 射门;
	void shot(int which, bool de, CPoint t); // 把球向 t 点射,de 向上还是向下射,de = 0从上向下射
	CPoint shooter_pos();					 // 对方射门者位置

	double Distance(CPoint point1, CPoint point2); // 计算两点之间的距离
	double Angle(CPoint point1, CPoint point2);	   // 计算两点之间的角度
	void Direction(int which, CPoint point);
	// void DirectionSE(int which, CPoint point); // 不进禁区版 Direction
	void PositionSE(int which, CPoint point); // 不进禁区版 Position
	void Rush(int which, CPoint point);		  // 冲向某点

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

	bool start; // 是否刚开始
	int t;		// 时间，即周期数
	struct infor {
		int num;	// 球员编号
		double dis; // 球员到球的距离
	};
	bool flag;

	// std::vector<CPoint> Navigation;

	// void Think();

public:
	int command[35];
};

#endif // _INSIDE_VISUAL_CPP_STRATEGYSYSTEM
