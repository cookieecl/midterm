#include "Point.hpp"

float	area(Point const a, Point const b, Point const c)
{
	Point	ab(b.getX().toFloat() - a.getX().toFloat(), b.getY().toFloat() - a.getY().toFloat());
	Point	ac(c.getX().toFloat() - a.getX().toFloat(), c.getY().toFloat() - a.getY().toFloat());

	float	crossProduct = ab.getX().toFloat() * ac.getY().toFloat() - ab.getY().toFloat() * ac.getX().toFloat();
	if (crossProduct < 0)
		crossProduct *= -1;
	
	return (crossProduct / 2);
}



bool	bsp(Point const a, Point const b, Point const c, Point const point)
{
	float	triangleArea = area(a, b, c);
	float	totalArea = 0;
	float	areaABP, areaACP, areaBCP = 0;

	areaABP = area(a, b, point);
	areaACP = area(a, c, point);
	areaBCP = area(b, c, point);

	if (areaABP == 0 || areaACP == 0 || areaBCP == 0)
		return (false);

	totalArea += areaABP + areaACP + areaBCP;

	if (totalArea == triangleArea)
		return (true);
	else
		return (false);
}
