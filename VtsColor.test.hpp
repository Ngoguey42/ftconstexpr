// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   VtsColor.test.hpp                                  :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/01 15:57:51 by ngoguey           #+#    #+#             //
//   Updated: 2015/06/01 15:57:51 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FTCONSTEXPR_VTSCOLOR_TEST_HPP
# define FTCONSTEXPR_VTSCOLOR_TEST_HPP

# include "VtsColor.hpp"
# include <assert.h>
# include <iomanip>
# define DO_CONSTEXPR constexpr

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
#  define P(VAL) std::cout << std::setw(30); std::cout << VAL
// #  define P(VAL) std::cout << VAL
# endif

# define VALUE_TYPE 
# define TYPE VtsColor<2>

KEYWORD int	testcVtsColor(void)
{
	{
		P("default CTOR: ");
		TYPE const		v0;
		P("OK\n");
		P("values CTOR: ");
		TYPE const		v1(10, 20, 30);
		assert(v1.c[0] == 10 && v1.c[1] == 20 && v1.c[2] == 30);
		P("OK\n");
		P("ilist CTOR test1: ");
		TYPE const 		v2{40, 50, 60};
		assert(v2.c[0] == 40 && v2.c[1] == 50 && v2.c[2] == 60);
		P("OK\n");
		P("ilist CTOR test2: ");
		TYPE const 		v3{{40, 50, 60}};
		assert(v3.c[0] == 40 && v3.c[1] == 50 && v3.c[2] == 60);
		P("OK\n");
		P("ilist CTOR test3: ");
		TYPE const 		v4({40, 50, 60});
		assert(v4.c[0] == 40 && v4.c[1] == 50 && v4.c[2] == 60);
		P("OK\n");
		P("color CTOR test1: ");
		TYPE const 		v5(TYPE::Color(40, 50, 60));
		assert(v5.c[0] == 40 && v5.c[1] == 50 && v5.c[2] == 60);
		P("OK\n");
		P("color CTOR test2: ");
		TYPE const 		v6{TYPE::Color(40, 50, 60)};
		assert(v6.c[0] == 40 && v6.c[1] == 50 && v6.c[2] == 60);
		P("OK\n");
	}
	{
		P("Vertex variadic CTOR1 test1: ");
		TYPE const 		v0(TYPE::Color(5u, 6u, 7u), TYPE::Vertex(1.f, 2.f, 3.f), TYPE::Vertex(10.f, 20.f, 30.f));
		assert(v0.c[0] == 5u && v0.c[1] == 6u && v0.c[2] == 7u &&
			   v0.v[0].x == 1.f && v0.v[0].y == 2.f && v0.v[0].z == 3.f &&
			   v0.v[1].x == 10.f && v0.v[1].y == 20.f && v0.v[1].z == 30.f);
		P("OK\n");
		P("Vertex variadic CTOR1 test2: ");
		TYPE const 		v1({5u, 6u, 7u}, TYPE::Vertex(1.42f, 2.42f, 3.42f), TYPE::Vertex(10.42f, 20.42f, 30.42f));
		assert(v1.c[0] == 5u && v1.c[1] == 6u && v1.c[2] == 7u &&
			   v1.v[0].x == 1.42f && v1.v[0].y == 2.42f && v1.v[0].z == 3.42f &&
			   v1.v[1].x == 10.42f && v1.v[1].y == 20.42f && v1.v[1].z == 30.42f);
		P("OK\n");
		P("Vertex variadic CTOR2: ");
		TYPE const 		v3(50u, 60u, 70u, TYPE::Vertex(1.12f, 2.12f, 3.12f), TYPE::Vertex(10.12f, 20.12f, 30.12f));
		assert(v3.c[0] == 50u && v3.c[1] == 60u && v3.c[2] == 70u &&
			   v3.v[0].x == 1.12f && v3.v[0].y == 2.12f && v3.v[0].z == 3.12f &&
			   v3.v[1].x == 10.12f && v3.v[1].y == 20.12f && v3.v[1].z == 30.12f);
		P("OK\n");
/*		P("copy CTOR: ");
		TYPE const		v7(v0);
		assert(v7.c[0] == 5u && v7.c[1] == 6u && v7.c[2] == 7u &&
			   v7.v[0].x == 1.f && v7.v[0].y == 2.f && v7.v[0].z == 3.f &&
			   v7.v[1].x == 10.f && v7.v[1].y == 20.f && v7.v[1].z == 30.f);
			   P("OK\n");*/
		TYPE			v4;
		P("operator=(VtsColor): ");
		v4 = v1;
		assert(v4.c[0] == 5u && v4.c[1] == 6u && v4.c[2] == 7u &&
			   v4.v[0].x == 1.42f && v4.v[0].y == 2.42f && v4.v[0].z == 3.42f &&
			   v4.v[1].x == 10.42f && v4.v[1].y == 20.42f && v4.v[1].z == 30.42f);
		P("OK\n");
		P("operator[]: ");
		assert(v4[0].x == 1.42f && v4[1].y == 20.42f);
		P("OK\n");
		P("operator[] const: ");
		assert(v0[0].x == 1.f && v0[1].y == 20.f);
		P("OK\n");
	}
	return (0);
}

void		testVtsColor(void)
{
	std::cout << "sizeof type: " << sizeof(TYPE) << "bytes\n";
	std::cout << "sizeof type::Vertex: " << sizeof(TYPE::Vertex) << "bytes\n";
	std::cout << "sizeof type::Color: " << sizeof(TYPE::Color) << "bytes\n";
	KEYWORD int ti = testcVtsColor();
	(void)ti;
	std::cout << "OK\n";
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
