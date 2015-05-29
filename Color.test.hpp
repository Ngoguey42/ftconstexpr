
#ifndef FTCONSTEXPR_COLOR_TEST_HPP
# define FTCONSTEXPR_COLOR_TEST_HPP

# include "Color.hpp"
# include <assert.h>
// # define DO_CONSTEXPR constexpr

namespace ftce
{

# ifdef DO_CONSTEXPR //don't touch
#  define DO_AND_PRINT(ARG) ARG
#  define SHOW(V)	
#  define ENDL
#  define KEYWORD constexpr
#  define P(VAL)
# else
	
#  define DO_AND_PRINT(ARG)												\
	std::cout << "\033[35m" << #ARG << "\033[0m" << std::endl;			\
	ARG																	
#  define SHOW(V)	std::cout << #V << ": " << V << "\n";
#  define ENDL	std::cout << "\n";
#  define KEYWORD 
#  define P(VAL) std::cout << VAL
# endif

# define VALUE_TYPE unsigned char
# define TYPE Color<unsigned char, 255>
# define TUPLET std::tuple<VALUE_TYPE, VALUE_TYPE, VALUE_TYPE>

static KEYWORD int	testcColor(void)
{
	{
		P("default CTOR: ");
		TYPE const		v0;
		P("OK\n");
		P("values CTOR: ");
		TYPE const		v1(10, 20, 30);
		assert(v1[0] == 10 && v1[1] == 20 && v1[2] == 30);
		P("OK\n");
		P("ilist CTOR: ");
		TYPE const 		v2{40, 50, 60};
		assert(v2[0] == 40 && v2[1] == 50 && v2[2] == 60);
		P("OK\n");
		P("copy CTOR: ");
		TYPE const		v3(v1);
		assert(v3[0] == 10 && v3[1] == 20 && v3[2] == 30);
		P("OK\n");
		P("tuple CTOR: ");
		TYPE const		v4(std::make_tuple(70, 80, 90));
		assert(v4[0] == 70 && v4[1] == 80 && v4[2] == 90);
		P("OK\n");
	}
	{
		P("setter: ");
		TYPE	v{10, 20, 42};
		v.set(100, 200, 250);
		assert(v[0] == 100 && v[1] == 200 && v[2] == 250);
		P("OK\n");
	}
	{
		TYPE			v1{100, 200, 250};
		TYPE const		v2(10, 20, 30);
		TUPLET			t1(10, 20, 30);
		P("operator =(color): ");
		v1 = v2;
		assert(v1[0] == 10 && v1[1] == 20 && v1[2] == 30);
		P("OK\n");
		v1.set(0, 0, 0);
		P("operator =(tuple): ");
		v1 = t1;
		assert(v1[0] == 10 && v1[1] == 20 && v1[2] == 30);
		P("OK\n");
		P("operator []: ");
		assert(v1[0] == 10 && v1[1] == 20 && v1[2] == 30);
		P("OK\n");
		P("operator []const: ");
		assert(v2[0] == 10 && v2[1] == 20 && v2[2] == 30);
		P("OK\n");
		v1.set(100, 200, 250);
		P("operator typecast(tuple): ");
		t1 = static_cast<TUPLET>(v1);
		assert(std::get<0>(t1) == 100 && std::get<1>(t1) == 200 && std::get<2>(t1) == 250);
		P("OK\n");
	}
	{
		VALUE_TYPE	v1 = 1;
		TYPE	v2{2, 2, 2};

		P("operator +=(color): ");
		v2 += v2;
		assert(v2[0] == 4 && v2[1] == 4 && v2[2] == 4);
		P("OK\n");
		P("operator -=(color): ");
		v2 -= v1;
		assert(v2[0] == 3 && v2[1] == 3 && v2[2] == 3);
		P("OK\n");
		P("operator *=(color): ");
		v2 *= v2;
		assert(v2[0] == 9 && v2[1] == 9 && v2[2] == 9);
		P("OK\n");
		v1 = 2;
		P("operator /=(color): ");
		v2 /= v1;
		assert(v2[0] == 4 && v2[1] == 4 && v2[2] == 4);
		P("OK\n");
	}
	{
		TYPE	v1{1, 1, 1};
		TYPE	v2{2, 2, 2};

		P("operator +=(val): ");
		v2 += v2;
		assert(v2[0] == 4 && v2[1] == 4 && v2[2] == 4);
		P("OK\n");
		P("operator -=(val): ");
		v2 -= v1;
		assert(v2[0] == 3 && v2[1] == 3 && v2[2] == 3);
		P("OK\n");
		P("operator *=(val): ");
		v2 *= v2;
		assert(v2[0] == 9 && v2[1] == 9 && v2[2] == 9);
		P("OK\n");
		v1.set(2, 2, 2);
		P("operator /=(val): ");
		v2 /= v1;
		assert(v2[0] == 4 && v2[1] == 4 && v2[2] == 4);
		P("OK\n");
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
# undef P

};	// ftce (ftconstexpr)

#endif