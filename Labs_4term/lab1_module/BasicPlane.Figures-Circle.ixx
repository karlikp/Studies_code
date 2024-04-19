export module BasicPlane.Figures:Circle;

import :Point;

export struct Circle
{
	Point centre, border;
};

export double radius(const Circle& c);
export double area(const Circle& c);