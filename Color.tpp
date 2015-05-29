// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Color.tpp                                          :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/05/29 13:44:39 by ngoguey           #+#    #+#             //
//   Updated: 2015/05/29 14:56:16 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#define SPEC Color<T>
#define SPEC2 Color<unsigned char>
#define SPECT2 Color<T2>
#define TEMPLATE_ARGS typename T

// * STATICS **************************************************************** //
template <TEMPLATE_ARGS>
constexpr typename SPEC::AttributePointer	SPEC::attributes[];

template <TEMPLATE_ARGS>
constexpr T									SPEC::defValue;

// * CONSTRUCTORS *********************************************************** //
template <TEMPLATE_ARGS>
CONSTEXPR SPEC::Color() noexcept
	: r()
	, g()
	, b()
{	return ;}
// {	std::cout << "Ctor[def]\n";}

template <TEMPLATE_ARGS>
CONSTEXPR SPEC::Color(SPEC const &rhs) noexcept
	: r(rhs.r)
	, g(rhs.g)
	, b(rhs.b)
{	return ;}
// {	std::cout << "Ctor[cpy]\n";}

template <TEMPLATE_ARGS>
CONSTEXPR SPEC::Color(std::initializer_list<T> l) noexcept
	: r(l.size() > 0 ? *(l.begin()    ) : SPEC::defValue)
	, g(l.size() > 1 ? *(l.begin() + 1) : SPEC::defValue)
	, b(l.size() > 2 ? *(l.begin() + 2) : SPEC::defValue)
{	return ;}
// {	std::cout << "Ctor[ilist]\n";}

template <TEMPLATE_ARGS>
CONSTEXPR SPEC::Color(SPEC::AssortedTuple3 const &t) noexcept
	: r(std::get<0>(t))
	, g(std::get<1>(t))
	, b(std::get<2>(t))
{	return ;}
// {	std::cout << "Ctor[tuple3]\n";}s

template <TEMPLATE_ARGS>
CONSTEXPR SPEC::Color(T r, T g, T b) noexcept
	: r(r)
	, g(g)
	, b(b)
{	return ;}
// {	std::cout << "Ctor[3T]\n";}

// * MEMBER FUNCTIONS / METHODS ********************************************* //
template <TEMPLATE_ARGS>
CONSTEXPR SPEC		&SPEC::set(T r, T g, T b) noexcept
{
	this->r = r;
	this->g = g;
	this->b = b;
	return *this;
}

// * OPERATORS ************************************************************** //
template <TEMPLATE_ARGS>
CONSTEXPR SPEC		&SPEC::operator=(SPEC const &rhs) noexcept
{
	this->r = rhs.r;
	this->g = rhs.g;
	this->b = rhs.b;
	return *this;
}

template <TEMPLATE_ARGS>
CONSTEXPR SPEC		&SPEC::operator=(SPEC::AssortedTuple3 const &rhs) noexcept
{
	this->r = std::get<0>(rhs);
	this->g = std::get<1>(rhs);
	this->b = std::get<2>(rhs);
	return *this;
}

// * [] OPERATORS ******************* //
#define DEFINE_OPERATOR(ATTRIB)											\
template <TEMPLATE_ARGS>												\
CONSTEXPR T ATTRIB	&SPEC::operator[](size_t i) ATTRIB noexcept			\
{																		\
	return this->*SPEC::attributes[i];									\
}
DEFINE_OPERATOR()
DEFINE_OPERATOR(const)
#undef DEFINE_OPERATOR

// * . and .= OPERATORS ************* //
#define DEFINE_OPERATOR(OP)													\
template <TEMPLATE_ARGS>													\
template <typename T2>														\
CONSTEXPR SPEC		&SPEC::operator CAT_EQ_OP(OP)(SPECT2 const &rhs)		\
{																			\
	r = this->r OP rhs.r;													\
	g = this->g OP rhs.g;													\
	b = this->b OP rhs.b;													\
	return *this;															\
}																			\
																			\
template <TEMPLATE_ARGS>													\
template <typename T2>														\
CONSTEXPR SPEC		&SPEC::operator CAT_EQ_OP(OP)(T2 v)						\
{																			\
	r = this->r OP v;														\
	g = this->g OP v;														\
	b = this->b OP v;														\
	return *this;															\
}																			\
																			\
template <TEMPLATE_ARGS>													\
template <typename T2>														\
CONSTEXPR SPEC		SPEC::operator OP(SPECT2 const &rhs) const				\
{																			\
	return SPEC(this->r OP rhs.r, this->g OP rhs.g, this->b OP rhs.b);		\
}																			\
																			\
template <TEMPLATE_ARGS>													\
template <typename T2>														\
CONSTEXPR SPEC		SPEC::operator OP(T2 v) const							\
{																			\
	return SPEC(this->r OP v, this->g OP v,	this->b OP v);					\
}

DEFINE_OPERATOR(/)
DEFINE_OPERATOR(+)
DEFINE_OPERATOR(*)
DEFINE_OPERATOR(-)
#undef DEFINE_OPERATOR

template <TEMPLATE_ARGS>
CONSTEXPR SPEC::operator SPEC::AssortedTuple3() const noexcept
{
	return std::make_tuple(r, g, b);
}

template <unsigned int MAXVAL>
std::ostream		&operator<<(std::ostream &o, SPEC2 const &rhs)
{
	return (o << "(" << static_cast<int>(rhs.r)
		<< "/" << static_cast<int>(rhs.g)
		<< "/" << static_cast<int>(rhs.b) << ")");
}
template <TEMPLATE_ARGS>
std::ostream		&operator<<(std::ostream &o, SPEC const &rhs)
{
	return (o << "(" << rhs.r << "/" << rhs.g << "/" << rhs.b << ")");
}

#undef SPEC
#undef TEMPLATE_ARGS
