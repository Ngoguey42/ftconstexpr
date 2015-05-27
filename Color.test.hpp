
#ifndef FTCONSTEXPR_COLOR_TEST_HPP
# define FTCONSTEXPR_COLOR_TEST_HPP

# include "Color.hpp"

// # define DO_CONSTEXPR constexpr

# ifdef DO_CONSTEXPR //don't touch
#  define DO_AND_PRINT(ARG) ARG
#  define SHOW(V)	
#  define ENDL
#  define KEYWORD constexpr

# else
	
#  define DO_AND_PRINT(ARG)												\
	std::cout << "\033[35m" << #ARG << "\033[0m" << std::endl;			\
	ARG																	
#  define SHOW(V)	std::cout << #V << ": " << V << "\n";
#  define ENDL	std::cout << "\n";
#  define KEYWORD 
# endif

# define VALUE_TYPE float
# define TYPE Color<VALUE_TYPE, 1>

static KEYWORD int	testcColor(void)
{
	{
		TYPE	v;
	}
	{
		TYPE		v{1, 2, 3};
		TYPE const	v2{4, 5, 6};
		
		SHOW(v) SHOW(v2)
		DO_AND_PRINT(v[0] = v[1];)
		SHOW(v) SHOW(v2)
		DO_AND_PRINT(v[0] = v[1] * v2[2];)
		SHOW(v) SHOW(v2)
	}
	ENDL
	{
		TYPE	v{10, 20, 42};
		
		SHOW(v) 
		DO_AND_PRINT(v.set(100, 200, 250);)
		SHOW(v) 
		DO_AND_PRINT(v.set(250, 250, 100);)
		SHOW(v) 
	}
	ENDL
	{
		TYPE	v1{0.5, 40, 20};
		TYPE	v2(v1);
		
		DO_AND_PRINT(v1.set(0.1, 250, 100);)
		SHOW(v1) SHOW(v2)
		DO_AND_PRINT(v1 = v2;)
		SHOW(v1) SHOW(v2)
		DO_AND_PRINT(v1 *= v2;)
		SHOW(v1) SHOW(v2)
		DO_AND_PRINT(v2 = ((((v1 + 1) - 2) * 3) / 4);)
		SHOW(v1) SHOW(v2)
	}
	ENDL
	{
		TYPE	v1{0.2, 40, 20};
		std::tuple<VALUE_TYPE, VALUE_TYPE, VALUE_TYPE>	t0(v1);
		std::tuple<VALUE_TYPE, VALUE_TYPE, VALUE_TYPE>	t1 = static_cast<decltype(t1)>(v1);
		
		TYPE	v2(t1);
		TYPE	v3{t1};
		TYPE	v4 = t1;
		(void)v4;
		
		DO_AND_PRINT(v2.set(0.5f, 50, 50);)
		SHOW(v2)
		DO_AND_PRINT(v2 = t0;)
		SHOW(v2)
	}
	ENDL
	return (0);
}


void		testColor(void)
{
	// Color<float>		c1;
	// Color<float, 1>		c2;
	// Color<unsigned char>		c3;
	// Color<unsigned char, 255>		c4;
// {
	std::cout << "sizeof type: " << sizeof(TYPE) << "bytes\n";
	KEYWORD int ti = testcColor();
	(void)ti;
	std::cout << "OK\n";
	return ;
	return ;
}

# undef DO_CONSTEXPR
# undef DO_AND_PRINT
# undef SHOW
# undef ENDL
# undef KEYWORD
# undef VALUE_TYPE
# undef TYPE

#endif