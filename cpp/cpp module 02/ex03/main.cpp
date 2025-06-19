#include "Point.hpp"

bool	bsp(Point const a, Point const b, Point const c, Point const point);

void	test(Point const a, Point const b, Point const c, Point const point, bool expectedResult)
{
	bool	result;

	result = bsp(a, b, c, point);
	std::cout << "Point (" << point.getX() << ", " << point.getY() << ") is ";
	if (result)
		std::cout << "inside the triangle" << std::endl;
	else
		std::cout << "not inside the triangle" << std::endl;
	
	if (result == expectedResult)
		std::cout << "Test passed" << std::endl << std::endl;
	else
		std::cout << "Test failed" << std::endl << std::endl;
}

int	main()
{
	Point	a(1, 2);
	Point	b(4, 6);
	Point	c(7, 1);

	Point	p1(3, 3);
	Point	p2(7, 2);
	Point	p3(1, 2);
	Point	p4(4, 1.5);

	std::cout << "Point A of a triangle: (" << a.getX() << ", " << a.getY() << ")" << std::endl;
	std::cout << "Point B of a triangle: (" << b.getX() << ", " << b.getY() << ")" << std::endl;
	std::cout << "Point C of a triangle: (" << c.getX() << ", " << c.getY() << ")" << std::endl;

	std::cout << std::endl;
	test(a, b, c, p1, true);
	test(a, b, c, p2, false);
	test(a, b, c, p3, false);
	test(a, b, c, p4, false);
}
