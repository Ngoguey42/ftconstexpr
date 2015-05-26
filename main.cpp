
// #include "Vertex.size3.hpp"
#include "Vertex.hpp"

// #define DO_CONSTEXPR constexpr

#ifdef DO_CONSTEXPR //don't touch
#define DO_AND_PRINT(ARG) ARG
#define SHOW(V)	
#define ENDL
#define KEYWORD constexpr

#else
	
#define DO_AND_PRINT(ARG)												\
	std::cout << "\033[35m" << #ARG << "\033[0m" << std::endl;			\
	ARG																	
#define SHOW(V)	std::cout << #V << ": " << V << "\n";
#define ENDL	std::cout << "\n";
#define KEYWORD 
#endif
KEYWORD int	testc(void)
{
	{
		Vertex<>	v;
	}
	{
		Vertex<>		v{1.f, 2.f, 3.f};
		Vertex<> const	v2{4.f, 5.f, 6.f};
		
		SHOW(v) SHOW(v2)
		DO_AND_PRINT(v[0] = v[1];)
		SHOW(v) SHOW(v2)
		DO_AND_PRINT(v[0] = v[1] * v2[2];)
		SHOW(v) SHOW(v2)
	}
	ENDL
	{
		Vertex<>	v{10.f, 20.f};
		
		SHOW(v) 
		DO_AND_PRINT(v.set(100.f, 200.f, 300.f);)
		SHOW(v) 
		DO_AND_PRINT(v.set(1000.f, 2000.f);)
		SHOW(v) 
	}
	ENDL
	{
		Vertex<>	v1{60.f, 40.f, 20.f};
		Vertex<>	v2(v1);
		
		DO_AND_PRINT(v1.set(1000.f, 2000.f);)
		SHOW(v1) SHOW(v2)
		DO_AND_PRINT(v1 = v2;)
		SHOW(v1) SHOW(v2)
		DO_AND_PRINT(v1 *= v2;)
		SHOW(v1) SHOW(v2)
		DO_AND_PRINT(v2 = ((((v1 + 1.f) - 2.f) * 3.f) / 4.f);)
		SHOW(v1) SHOW(v2)
	}
	ENDL
	{
		Vertex<>	v1{60.f, 40.f, 20.f};
		std::tuple<float, float, float>	t0(v1);
		std::tuple<float, float, float>	t1 = static_cast<decltype(t1)>(v1);
		
		Vertex<>	v2(t1);
		Vertex<>	v3{t1};
		Vertex<>	v4 = t1;
		(void)v4;
		
		DO_AND_PRINT(v2.set(42.f, 0.42f, 0.0042f);)
		SHOW(v2)
		DO_AND_PRINT(v2 = t0;)
		SHOW(v2)
	}
	ENDL
	{
		Vertex<>	v1{60.f, 40.f};
		std::pair<float, float>	t0(v1);
		std::pair<float, float>	t1 = static_cast<decltype(t1)>(v1);
		
		Vertex<>	v2(t1);
		Vertex<>	v3{t1};
		Vertex<>	v4 = t1;
		(void)v4;
		
		DO_AND_PRINT(v2.set(42.f, 0.42f);)
		SHOW(v2)
		DO_AND_PRINT(v2 = t0;)
		SHOW(v2)
	}
	return (0);
}

int		main(void)
{
	KEYWORD int ti = testc();
	(void)ti;
	std::cout << "OK\n";
	return (0);
}