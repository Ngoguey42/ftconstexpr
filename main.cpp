

#include "Vertex.hpp"
#include "Vertex.test.hpp"

#include "Color.hpp"
#include "Color.test.hpp"

class Point
{
public:
	Vertex<float, 2u>		v;
	Color<>			c;

	constexpr Point()
		: v{0.f, 0.f}
		, c{}
		{	return;		}
	
};

constexpr Point		createPoint(void)
{
	Point		ret;
	
	ret.v.set(1.f, 2.f);
	ret.c.set(10, 20, 30);
	
	return (ret);
}

int main(void)
{
	constexpr Point		p(createPoint());
	(void)p;
	
	std::cout << p.v << p.c << "\n";
	// testVertex();
	// testColor();
	return (0);
}