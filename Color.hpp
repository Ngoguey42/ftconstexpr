
#ifndef FTCONSTEXPR_TEST_HPP
# define FTCONSTEXPR_TEST_HPP

# include <iostream>
# include <tuple>
# include <initializer_list>
# include <type_traits>
# include <stdexcept>

# define CONSTEXPR constexpr
// # define CONSTEXPR 
# define CAT_EQ_OP(OP) OP ## =

template <typename T = unsigned char,
		  unsigned int MAXVAL = std::is_floating_point<T>::value
		  ? 1u
		  : 255u>
class Color
{
	static_assert(std::is_arithmetic<T>::value,
				  "ftce::Color type must be arithmetic");
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
	CONSTEXPR Color(T x, T y, T z) noexcept;
	
	// * MEMBER FUNCTIONS / METHODS * //
	CONSTEXPR Color			&set(T x, T y, T z) noexcept;
	
	// * OPERATORS ****************** //
	CONSTEXPR Color			&operator=(Color const &rhs) noexcept;
	CONSTEXPR Color			&operator=(AssortedTuple3 const &rhs) noexcept;
	CONSTEXPR T				&operator[](size_t i) noexcept;
	CONSTEXPR T const		&operator[](size_t i) const noexcept;
# define DECLARE_OPERATOR(OP)												\
	CONSTEXPR Color		&operator CAT_EQ_OP(OP)(Color const &rhs) noexcept;	\
	CONSTEXPR Color		&operator CAT_EQ_OP(OP)(T v) noexcept;				\
	CONSTEXPR Color		operator OP(Color const &rhs) const noexcept;		\
	CONSTEXPR Color		operator OP(T v) const noexcept;
	DECLARE_OPERATOR(+)
	DECLARE_OPERATOR(-)
	DECLARE_OPERATOR(*)
	DECLARE_OPERATOR(/)
# undef DECLARE_OPERATOR
	CONSTEXPR explicit operator AssortedTuple3() const noexcept;
private:
	// * STATICS ******************** //
	static constexpr T					defValue{static_cast<T>(0)};
	static constexpr T					minval{static_cast<T>(0)};
	static constexpr T					maxval{static_cast<T>(MAXVAL)};
	static constexpr AttributePointer	attributes[]{
		&Color::r,
		&Color::g,
		&Color::b
	};
	static constexpr T					bounds(T v);
	static constexpr T					lowerBound(T v);
	static constexpr T					upperBound(T v);
};
										
template <typename T, unsigned int MAXVAL>
std::ostream				&operator<<(std::ostream &o,
										Color<T, MAXVAL> const &rhs);
										
										
# include "Color.tpp"
# undef CAT_EQ_OP
# undef CONSTEXPR

#endif