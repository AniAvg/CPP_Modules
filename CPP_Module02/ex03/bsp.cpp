#include "Point.hpp"

static float sign(Point const p1, Point const p2, Point const p3)
{
	return ((p3.get_x() - p2.get_x()).toFloat() * (p1.get_y() - p2.get_y()).toFloat()
			- (p1.get_x() - p2.get_x()).toFloat() * (p3.get_y() - p2.get_y()).toFloat());
}

bool bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	d1 = sign(a, b, point);
	float	d2 = sign(a, c, point);
	float	d3 = sign(b, c, point);

	if (d1 == 0 || d2 == 0 || d3 == 0)
		return false;

	bool	has_neg = (d1 < 0) || (d2 < 0) || (d3 < 0);
	bool	has_pos = (d1 > 0) || (d2 > 0) || (d3 > 0);

	return !(has_neg && has_pos);
}
