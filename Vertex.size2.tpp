// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Vertex.size2.tpp                                   :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/01 16:01:09 by ngoguey           #+#    #+#             //
//   Updated: 2015/06/01 16:01:10 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#define SPEC Vertex<T, 2u>

// * STATICS **************************************************************** //
template <typename T>
constexpr typename SPEC::AttributePointer	SPEC::attributes[];

template <typename T>
constexpr T									SPEC::defValue;

// * CONSTRUCTORS *********************************************************** //
template <typename T>
CONSTEXPR SPEC::Vertex() noexcept
	: x()
	, y()
{	return ;}
// {	std::cout << "Ctor[def]\n";}

template <typename T>
CONSTEXPR SPEC::Vertex(SPEC const &rhs) noexcept
	: x(rhs.x)
	, y(rhs.y)
{	return ;}
// {	std::cout << "Ctor[cpy]\n";}

template <typename T>
CONSTEXPR SPEC::Vertex(std::initializer_list<T> l) noexcept
	: x(l.size() > 0 ? *(l.begin()    ) : SPEC::defValue)
	, y(l.size() > 1 ? *(l.begin() + 1) : SPEC::defValue)
{	return ;}
// {	std::cout << "Ctor[ilist]\n";}

template <typename T>
CONSTEXPR SPEC::Vertex(SPEC::AssortedTuple2 const &t) noexcept
	: x(std::get<0>(t))
	, y(std::get<1>(t))
{	return ;}
// {	std::cout << "Ctor[tuple2]\n";}

template <typename T>
CONSTEXPR SPEC::Vertex(T x, T y) noexcept
	: x(x)
	, y(y)
{	return ;}
// {	std::cout << "Ctor[2T]\n";}

// * MEMBER FUNCTIONS / METHODS ********************************************* //
template <typename T>
CONSTEXPR SPEC		&SPEC::set(T x, T y) noexcept
{
	this->x = x;
	this->y = y;
	return *this;
}

// * OPERATORS ************************************************************** //
template <typename T>
CONSTEXPR SPEC		&SPEC::operator=(SPEC const &rhs) noexcept
{
	this->x = rhs.x;
	this->y = rhs.y;
	return *this;
}

template <typename T>
CONSTEXPR SPEC		&SPEC::operator=(SPEC::AssortedTuple2 const &rhs) noexcept
{
	this->x = std::get<0>(rhs);
	this->y = std::get<1>(rhs);
	return *this;
}

// * [] OPERATORS ******************* //
#define DEFINE_OPERATOR(ATTRIB)											\
template <typename T>													\
CONSTEXPR T ATTRIB	&SPEC::operator[](size_t i) ATTRIB noexcept			\
{																		\
	if (i > 1)															\
		throw std::out_of_range("Vertex[] Out of range index");			\
	return this->*SPEC::attributes[i];									\
}
DEFINE_OPERATOR()
DEFINE_OPERATOR(const)
#undef DEFINE_OPERATOR

// * . and .= OPERATORS ************* //
#define DEFINE_OPERATOR(OP)													\
template <typename T>														\
CONSTEXPR SPEC		&SPEC::operator CAT_EQ_OP(OP)(SPEC const &rhs) noexcept \
{																			\
	x CAT_EQ_OP(OP) rhs.x;													\
	y CAT_EQ_OP(OP) rhs.y;													\
	return *this;															\
}																			\
																			\
template <typename T>														\
CONSTEXPR SPEC		SPEC::operator OP(T v) const noexcept					\
{																			\
	return SPEC(x OP v, y OP v);									\
}
DEFINE_OPERATOR(+)
DEFINE_OPERATOR(-)
DEFINE_OPERATOR(*)
DEFINE_OPERATOR(/)
#undef DEFINE_OPERATOR

template <typename T>
CONSTEXPR SPEC::operator SPEC::AssortedTuple2() const noexcept
{
	return std::make_pair(x, y);
}

template <typename T>
std::ostream		&operator<<(std::ostream &o, SPEC const &rhs)
{
	return (o << "(" << rhs.x << "/" << rhs.y << ")");
}

#undef SPEC
