// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Color.hpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/29 13:44:41 by ngoguey           #+#    #+#             //
//   Updated: 2015/05/29 14:54:31 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FTCONSTEXPR_TEST_HPP
# define FTCONSTEXPR_TEST_HPP

# include <iostream>
# include <tuple>
# include <initializer_list>
# include <type_traits>
# include <stdexcept>

namespace ftce
{
# define CONSTEXPR constexpr
// # define CONSTEXPR 
# define CAT_EQ_OP(OP) OP ## =

template <typename T = unsigned char>
class Color
{
	static_assert(std::is_arithmetic<T>::value,
				  "ftce::Color 'T' must be arithmetic"); 
private:
	// * NESTED OBJECTS ************* //
	typedef T							Color::*AttributePointer;
	typedef std::tuple<T, T, T>			AssortedTuple3;
public:
	// * ATTRIBUTES ***************** //
	T						r;
	T						g;
	T						b;
	
	// * CTORS / DTORS ************** //
	CONSTEXPR Color() noexcept;
	CONSTEXPR Color(Color const &rhs) noexcept;
	CONSTEXPR Color(std::initializer_list<T> l) noexcept;
	CONSTEXPR Color(AssortedTuple3 const &t) noexcept;
	CONSTEXPR Color(T r, T g, T b) noexcept;
	
	// * MEMBER FUNCTIONS / METHODS * //
	CONSTEXPR Color		&set(T r, T g, T b) noexcept;
	
	// * OPERATORS ****************** //
	CONSTEXPR Color		&operator=(Color const &rhs) noexcept;
	CONSTEXPR Color		&operator=(AssortedTuple3 const &rhs) noexcept;
	CONSTEXPR T			&operator[](size_t i) noexcept;
	CONSTEXPR T const	&operator[](size_t i) const noexcept;
# define DECLARE_OPERATOR(OP)												\
	template <typename T2 = T>												\
	CONSTEXPR Color		&operator CAT_EQ_OP(OP)(T2 v);						\
	template <typename T2 = T>												\
	CONSTEXPR Color		operator OP(Color<T2> const &rhs) const;			\
	template <typename T2 = T>												\
	CONSTEXPR Color		operator OP(T2 v) const;							\
	template <typename T2 = T>												\
	CONSTEXPR Color		&operator CAT_EQ_OP(OP)(Color<T2> const &rhs);
	
	DECLARE_OPERATOR(+)
	DECLARE_OPERATOR(-)
	DECLARE_OPERATOR(*)
	DECLARE_OPERATOR(/)
# undef DECLARE_OPERATOR
	CONSTEXPR explicit	operator AssortedTuple3() const noexcept;
private:
	// * STATICS ******************** //
	static constexpr T					defValue{static_cast<T>(0)};
	static constexpr AttributePointer	attributes[]{
		&Color::r,
		&Color::g,
		&Color::b
	};
};
										
template <typename T, unsigned int MAXVAL>
std::ostream				&operator<<(std::ostream &o,
										Color<T> const &rhs);

# include "Color.tpp"
# undef CAT_EQ_OP
# undef CONSTEXPR

};	// ftce (ftconstexpr)

#endif
