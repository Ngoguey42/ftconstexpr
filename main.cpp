
// #include "Vertex.size3.hpp"
#include "Vertex.hpp"

#define DO_AND_PRINT(ARG)												\
	ARG
CONSTEXPR int	testc(void)
{
	{
		Vertex<>	v;
	}
	{
		Vertex<>		v{1.f, 2.f, 3.f};
		Vertex<> const	v2{4.f, 5.f, 6.f};
		
		DO_AND_PRINT(v[0] = v[1];)
		DO_AND_PRINT(v[0] = v[1] * v2[2];)
	}
	{
		Vertex<>	v{10.f, 20.f};
		
		DO_AND_PRINT(v.set(100.f, 200.f, 300.f);)
		DO_AND_PRINT(v.set(1000.f, 2000.f);)
	}
	{
		Vertex<>	v1{60.f, 40.f, 20.f};
		Vertex<>	v2(v1);
		
		DO_AND_PRINT(v1 = v2;)
		DO_AND_PRINT(v1 *= v2;)
		DO_AND_PRINT(v2 = ((((v1 + 1.f) - 2.f) * 3.f) / 4.f);)
	}
	{
		Vertex<>	v1{60.f, 40.f, 20.f};
		std::tuple<float, float, float>	t0(v1);
		std::tuple<float, float, float>	t1 = static_cast<decltype(t1)>(v1);
		
		Vertex<>	v2(t1);
		Vertex<>	v3{t1};
		Vertex<>	v4 = t1;
		
		v2 = t0;
		(void)t0;
		(void)t1;
		(void)v4;
	}
	return (0);
}

#undef DO_AND_PRINT
#define DO_AND_PRINT(ARG)												\
	std::cout << "\033[35m" << #ARG << "\033[0m" << std::endl;			\
	ARG																	
int		main(void)
{
	{
		Vertex<>	v;
	}
	{
		Vertex<>		v{1.f, 2.f, 3.f};
		Vertex<> const	v2{4.f, 5.f, 6.f};
		
		std::cout << "v :" << v << "\nv1 :" << v2 << "\n";
		DO_AND_PRINT(v[0] = v[1];)
		std::cout << "v :" << v << "\nv1 :" << v2 << "\n";
		DO_AND_PRINT(v[0] = v[1] * v2[2];)
		std::cout << "v :" << v << "\nv1 :" << v2 << "\n";
	}
	std::cout << "\n";
	{
		Vertex<>	v{10.f, 20.f};
		
		std::cout << "v :" << v << "\n";
		DO_AND_PRINT(v.set(100.f, 200.f, 300.f);)
		std::cout << "v :" << v << "\n";
		DO_AND_PRINT(v.set(1000.f, 2000.f);)
		std::cout << "v :" << v << "\n";
	}
	std::cout << "\n";
	{
		Vertex<>	v1{60.f, 40.f, 20.f};
		Vertex<>	v2(v1);
		
		DO_AND_PRINT(v1.set(1000.f, 2000.f);)
		std::cout << "v1 :" << v1 << "\nv2 :" << v2 << "\n";
		DO_AND_PRINT(v1 = v2;)
		std::cout << "v1 :" << v1 << "\nv2 :" << v2 << "\n";
		DO_AND_PRINT(v1 *= v2;)
		std::cout << "v1 :" << v1 << "\nv2 :" << v2 << "\n";
		DO_AND_PRINT(v2 = ((((v1 + 1.f) - 2.f) * 3.f) / 4.f);)
		std::cout << "v1 :" << v1 << "\nv2 :" << v2 << "\n";
	}
	std::cout << "\n";
		Vertex<>	v1{60.f, 40.f, 20.f};
		std::tuple<float, float, float>	t0(v1);
		std::tuple<float, float, float>	t1 = static_cast<decltype(t1)>(v1);
		
		Vertex<>	v2(t1);
		Vertex<>	v3{t1};
		Vertex<>	v4 = t1;
		
		v2.set(42.f, 0.42f, 0.0042f);
		std::cout << "v2 :" << v2 << "\n";
		v2 = t0;
		std::cout << "v2 :" << v2 << "\n";
		
		
		(void)t0;
		(void)t1;
		(void)v4;
	
	// CONSTEXPR int ti = testc();
	// (void)ti;
	return (0);
}