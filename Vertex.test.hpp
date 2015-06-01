// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Vertex.test.hpp                                    :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/01 15:57:56 by ngoguey           #+#    #+#             //
//   Updated: 2015/06/01 15:57:59 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FTCONSTEXPR_VERTEX_TEST_HPP
# define FTCONSTEXPR_VERTEX_TEST_HPP

// #include "Vertex.size3.hpp"
#include "Vertex.hpp"

namespace ftce
{
# define DO_CONSTEXPR constexpr

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
# define TYPE Vertex<VALUE_TYPE, 2u>


static KEYWORD int	testc(void)
{
	{
		TYPE	v;
	}
	{
		TYPE		v{1.f, 2.f};
		TYPE const	v2{4.f, 5.f};
		
		SHOW(v) SHOW(v2)
		DO_AND_PRINT(v[0] = v[1];)
		SHOW(v) SHOW(v2)
		DO_AND_PRINT(v[0] = v[1] * v2[0];)
		SHOW(v) SHOW(v2)
	}
	ENDL
	{
		TYPE	v{10.f, 20.f};
		
		SHOW(v) 
		DO_AND_PRINT(v.set(100.f, 200.f);)
		SHOW(v) 
		DO_AND_PRINT(v.set(1000.f, 2000.f);)
		SHOW(v) 
	}
	ENDL
	{
		TYPE	v1{60.f, 40.f};
		TYPE	v2(v1);
		
		DO_AND_PRINT(v1.set(1000.f, 2000.f);)
		SHOW(v1) SHOW(v2)
		DO_AND_PRINT(v1 = v2;)
		SHOW(v1) SHOW(v2)
		DO_AND_PRINT(v1 *= v2;)
		SHOW(v1) SHOW(v2)
		DO_AND_PRINT(v2 = ((((v1 + 1.f) - 2.f) * 3.f) / 4.f);)
		SHOW(v1) SHOW(v2)
	}
	// ENDL
	// {
		// TYPE	v1{60.f, 40.f};
		// std::tuple<VALUE_TYPE, VALUE_TYPE, VALUE_TYPE>	t0(v1);
		// std::tuple<VALUE_TYPE, VALUE_TYPE, VALUE_TYPE>	t1 = static_cast<decltype(t1)>(v1);
		
		// TYPE	v2(t1);
		// TYPE	v3{t1};
		// TYPE	v4 = t1;
		// (void)v4;
		
		// DO_AND_PRINT(v2.set(42.f, 0.42f);)
		// SHOW(v2)
		// DO_AND_PRINT(v2 = t0;)
		// SHOW(v2)
	// }
	ENDL
	{
		TYPE	v1{60.f, 40.f};
		std::pair<VALUE_TYPE, VALUE_TYPE>	t0(v1);
		std::pair<VALUE_TYPE, VALUE_TYPE>	t1 = static_cast<decltype(t1)>(v1);
		
		TYPE	v2(t1);
		TYPE	v3{t1};
		TYPE	v4 = t1;
		(void)v4;
		
		DO_AND_PRINT(v2.set(42.f, 0.42f);)
		SHOW(v2)
		DO_AND_PRINT(v2 = t0;)
		SHOW(v2)
	}
	return (0);
}
void		testVertex(void)
{
	std::cout << "sizeof type: " << sizeof(TYPE) << "bytes\n";
	KEYWORD int ti = testc();
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

};	// ftce (ftconstexpr)

#endif
