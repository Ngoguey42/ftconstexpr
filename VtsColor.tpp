// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   VtsColor.tpp                                       :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/01 15:57:38 by ngoguey           #+#    #+#             //
//   Updated: 2015/06/01 15:57:40 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#define SPEC VtsColor<NVts, TVts, SVts, Tco>
#define TEMPLATE_ARGS size_t NVts, typename TVts, size_t SVts, \
	typename Tco

// * STATICS **************************************************************** //
// * CONSTRUCTORS *********************************************************** //
template<TEMPLATE_ARGS>
CONSTEXPR SPEC::VtsColor() noexcept
	: c()
	, v()
{	return ;}
// {	std::cout << "ctor 'def'" ;}

template<TEMPLATE_ARGS>
CONSTEXPR SPEC::VtsColor(SPEC const &src) noexcept
	: c(src.c)
	, v()
{
	// Won't compile with const instance in constexpr evaluation, need to wrap v into another class.
	for (size_t	i = 0; i < NVts; i++)
		v[i] = src.v[i];
	return ;
}

// * COLOR CTORS ****** //
template<TEMPLATE_ARGS>
CONSTEXPR SPEC::VtsColor(Color const &c) noexcept
	: c(c)
	, v()
{	return ;}
// {	std::cout << "ctor 'color'" ;}

template<TEMPLATE_ARGS>
CONSTEXPR SPEC::VtsColor(Tco r, Tco g, Tco b) noexcept
	: c(r, g, b)
	, v()
{	return ;}
// {	std::cout << "ctor 'values'" ;}

template<TEMPLATE_ARGS>
CONSTEXPR SPEC::VtsColor(std::initializer_list<Tco> lc) noexcept
	: c(lc)
	, v()
{	return ;}
// {	std::cout << "ctor 'ilist'" ;}

// * VERTEX CTORS ***** //
template<TEMPLATE_ARGS>
template<typename... Vertices>
CONSTEXPR SPEC::VtsColor(Color const &c, Vertices... lv) noexcept
	: c(c)
	, v{lv...}
{
	// static_assert(std::is_same<Vertex, Vertices...>::value, "Arguments must be Vertex."); //implement is all same
	return ;
}

template<TEMPLATE_ARGS>
template<typename... Vertices>
CONSTEXPR SPEC::VtsColor(Tco r, Tco g, Tco b, Vertices... lv) noexcept
	: c(r, g, b)
	, v{lv...}
{
	// static_assert(std::is_same<Vertex, Vertices...>::value, "Arguments must be Vertex."); //implement is all same
	return ;
}


// * OPERATORS ************************************************************** //
template<TEMPLATE_ARGS>
CONSTEXPR SPEC		&SPEC::operator=(SPEC const &rhs) noexcept
{
	this->c = rhs.c;
	for (size_t	i = 0; i < NVts; i++)
		v[i] = rhs.v[i];
	return *this;
}

// * [] OPERATORS ******************* //
#define DEFINE_OPERATOR(ATTRIB)											\
template<TEMPLATE_ARGS>													\
CONSTEXPR typename SPEC::Vertex ATTRIB									\
	&SPEC::operator[](size_t i) ATTRIB noexcept							\
{																		\
	if (i >= NVts)														\
		throw std::out_of_range("VtsColor[] Out of range index");		\
	return this->v[i];													\
}
DEFINE_OPERATOR()
DEFINE_OPERATOR(const)
#undef DEFINE_OPERATOR
	
