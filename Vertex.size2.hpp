// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Vertex.size2.hpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/01 16:00:46 by ngoguey           #+#    #+#             //
//   Updated: 2015/06/01 16:00:59 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FTCONSTEXPR_VERTEX_SIZE2_HPP
# define FTCONSTEXPR_VERTEX_SIZE2_HPP

# include "Vertex.hpp"

# define CAT_EQ_OP(OP) OP ## =

template <typename T>
class Vertex<T, 2u>
{
private:
	// * NESTED OBJECTS ************* //
	typedef T							Vertex::*AttributePointer;
	typedef std::pair<T, T>				AssortedTuple2;
public:
	// * ATTRIBUTES ***************** //
	T						x;
	T						y;
	
	// * CTORS / DTORS ************** //
	CONSTEXPR Vertex() noexcept;
	CONSTEXPR Vertex(Vertex const &rhs) noexcept;
	CONSTEXPR Vertex(std::initializer_list<T> l) noexcept;
	CONSTEXPR Vertex(AssortedTuple2 const &t) noexcept;
	CONSTEXPR Vertex(T x, T y) noexcept;
	~Vertex() = default;
	
	// * MEMBER FUNCTIONS / METHODS * //
	CONSTEXPR Vertex		&set(T x, T y) noexcept;
	
	// * OPERATORS ****************** //
	CONSTEXPR Vertex		&operator=(Vertex const &rhs) noexcept;
	CONSTEXPR Vertex		&operator=(AssortedTuple2 const &rhs) noexcept;
	CONSTEXPR T				&operator[](size_t i) noexcept;
	CONSTEXPR T const		&operator[](size_t i) const noexcept;
# define DECLARE_OPERATOR(OP)												\
	CONSTEXPR Vertex		&operator CAT_EQ_OP(OP)(						\
												Vertex const &rhs) noexcept;\
	CONSTEXPR Vertex		operator OP(T v) const noexcept;
	DECLARE_OPERATOR(+)
	DECLARE_OPERATOR(-)
	DECLARE_OPERATOR(*)
	DECLARE_OPERATOR(/)
# undef DECLARE_OPERATOR
	CONSTEXPR explicit operator AssortedTuple2() const noexcept;
private:
	// * STATICS ******************** //
	static constexpr T					defValue{static_cast<T>(0)};
	static constexpr AttributePointer	attributes[]{
		&Vertex::x,
		&Vertex::y,
	};
};

template <typename T>
std::ostream				&operator<<(std::ostream &o,
										Vertex<T, 2u> const &rhs);

# include "Vertex.size2.tpp"
# undef CAT_EQ_OP

#endif // ************************************** FTCONSTEXPR_VERTEX_SIZE2_HPP //
