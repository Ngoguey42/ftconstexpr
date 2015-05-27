
#define SPEC Color<T, MAXVAL>
#define SPEC2 Color<unsigned char, MAXVAL>

// * STATICS **************************************************************** //
template <typename T, unsigned int MAXVAL>
constexpr typename SPEC::AttributePointer	SPEC::attributes[];

template <typename T, unsigned int MAXVAL>
constexpr T									SPEC::defValue;

template <typename T, unsigned int MAXVAL>
constexpr T									SPEC::maxval;

template <typename T, unsigned int MAXVAL>
constexpr T									SPEC::bounds(T v)
{
	if (v < SPEC::minval)
		return (SPEC::minval);
	if (v > SPEC::maxval)
		return (SPEC::maxval);
	return (v);
}

template <typename T, unsigned int MAXVAL>
constexpr T									SPEC::lowerBound(T v)
{
	if (v < SPEC::minval)
		return (SPEC::minval);
	return (v);
}

template <typename T, unsigned int MAXVAL>
constexpr T									SPEC::upperBound(T v)
{
	if (v > SPEC::maxval)
		return (SPEC::maxval);
	return (v);
}

// * CONSTRUCTORS *********************************************************** //
template <typename T, unsigned int MAXVAL>
CONSTEXPR SPEC::Color() noexcept
	: r()
	, g()
	, b()
{	return ;}
// {	std::cout << "Ctor[def]\n";}

template <typename T, unsigned int MAXVAL>
CONSTEXPR SPEC::Color(SPEC const &rhs) noexcept
	: r(rhs.r)
	, g(rhs.g)
	, b(rhs.b)
{	return ;}
// {	std::cout << "Ctor[cpy]\n";}

template <typename T, unsigned int MAXVAL>
CONSTEXPR SPEC::Color(std::initializer_list<T> l) noexcept
	: r(l.size() > 0 ? SPEC::bounds(*(l.begin()    )) : SPEC::defValue)
	, g(l.size() > 1 ? SPEC::bounds(*(l.begin() + 1)) : SPEC::defValue)
	, b(l.size() > 2 ? SPEC::bounds(*(l.begin() + 2)) : SPEC::defValue)
{	return ;}
// {	std::cout << "Ctor[ilist]\n";}

template <typename T, unsigned int MAXVAL>
CONSTEXPR SPEC::Color(SPEC::AssortedTuple3 const &t) noexcept
	: r(SPEC::bounds(std::get<0>(t)))
	, g(SPEC::bounds(std::get<1>(t)))
	, b(SPEC::bounds(std::get<2>(t)))
{	return ;}
// {	std::cout << "Ctor[tuple3]\n";}s

template <typename T, unsigned int MAXVAL>
CONSTEXPR SPEC::Color(T r, T g, T b) noexcept
	: r(SPEC::bounds(r))
	, g(SPEC::bounds(g))
	, b(SPEC::bounds(b))
{	return ;}
// {	std::cout << "Ctor[3T]\n";}

// * MEMBER FUNCTIONS / METHODS ********************************************* //
template <typename T, unsigned int MAXVAL>
CONSTEXPR SPEC		&SPEC::set(T r, T g, T b) noexcept
{
	this->r = SPEC::bounds(r);
	this->g = SPEC::bounds(g);
	this->b = SPEC::bounds(b);
	return *this;
}

// * OPERATORS ************************************************************** //
template <typename T, unsigned int MAXVAL>
CONSTEXPR SPEC		&SPEC::operator=(SPEC const &rhs) noexcept
{
	this->r = rhs.r;
	this->g = rhs.g;
	this->b = rhs.b;
	return *this;
}

template <typename T, unsigned int MAXVAL>
CONSTEXPR SPEC		&SPEC::operator=(SPEC::AssortedTuple3 const &rhs) noexcept
{
	this->r = SPEC::bounds(std::get<0>(rhs));
	this->g = SPEC::bounds(std::get<1>(rhs));
	this->b = SPEC::bounds(std::get<2>(rhs));
	return *this;
}

// * [] OPERATORS ******************* //
#define DEFINE_OPERATOR(ATTRIB)											\
template <typename T, unsigned int MAXVAL>								\
CONSTEXPR T ATTRIB	&SPEC::operator[](size_t i) ATTRIB noexcept			\
{																		\
	if (i > 2)															\
		throw std::out_of_range("Color[] Out of range index");			\
	return this->*SPEC::attributes[i];									\
}
DEFINE_OPERATOR()
DEFINE_OPERATOR(const)
#undef DEFINE_OPERATOR

// * . and .= OPERATORS ************* //
#define DEFINE_OPERATOR(OP)													\
template <typename T, unsigned int MAXVAL>									\
CONSTEXPR SPEC		&SPEC::operator CAT_EQ_OP(OP)(SPEC const &rhs) noexcept \
{																			\
	if (std::is_floating_point<T>::value)									\
	{																		\
		r = BOUND_FN(this->r OP rhs.r);										\
		g = BOUND_FN(this->g OP rhs.g);										\
		b = BOUND_FN(this->b OP rhs.b);										\
	}																		\
	else																	\
	{																		\
		r = static_cast<T>(BOUND_FN(static_cast<float>(this->r) OP			\
									static_cast<float>(rhs.r)));			\
		g = static_cast<T>(BOUND_FN(static_cast<float>(this->g) OP			\
									static_cast<float>(rhs.g)));			\
		b = static_cast<T>(BOUND_FN(static_cast<float>(this->b) OP			\
									static_cast<float>(rhs.b)));			\
	}																		\
	return *this;															\
}																			\
																			\
template <typename T, unsigned int MAXVAL>									\
CONSTEXPR SPEC		&SPEC::operator CAT_EQ_OP(OP)(T v) noexcept				\
{																			\
	if (std::is_floating_point<T>::value)									\
	{																		\
		r = BOUND_FN(this->r OP v);											\
		g = BOUND_FN(this->g OP v);											\
		b = BOUND_FN(this->b OP v);											\
	}																		\
	else																	\
	{																		\
		r = static_cast<T>(BOUND_FN(static_cast<float>(this->r) OP			\
									static_cast<float>(v)));				\
		g = static_cast<T>(BOUND_FN(static_cast<float>(this->g) OP			\
									static_cast<float>(v)));				\
		b = static_cast<T>(BOUND_FN(static_cast<float>(this->b) OP			\
									static_cast<float>(v)));				\
	}																		\
	return *this;															\
}																			\
																			\
template <typename T, unsigned int MAXVAL>									\
CONSTEXPR SPEC		SPEC::operator OP(SPEC const &rhs) const noexcept		\
{																			\
	if (std::is_floating_point<T>::value)									\
		return SPEC(BOUND_FN(this->r OP rhs.r),								\
					BOUND_FN(this->g OP rhs.g),								\
					BOUND_FN(this->b OP rhs.b));							\
	else																	\
		return SPEC(														\
			static_cast<T>(BOUND_FN(static_cast<float>(this->r) OP			\
									static_cast<float>(rhs.r))),			\
			static_cast<T>(BOUND_FN(static_cast<float>(this->g) OP			\
									static_cast<float>(rhs.g))),			\
			static_cast<T>(BOUND_FN(static_cast<float>(this->b) OP			\
									static_cast<float>(rhs.b))));			\
}																			\
																			\
template <typename T, unsigned int MAXVAL>									\
CONSTEXPR SPEC		SPEC::operator OP(T v) const noexcept					\
{																			\
	if (std::is_floating_point<T>::value)									\
		return SPEC(BOUND_FN(this->r OP v),									\
					BOUND_FN(this->g OP v),									\
					BOUND_FN(this->b OP v));								\
	else																	\
		return SPEC(														\
			static_cast<T>(BOUND_FN(static_cast<float>(this->r) OP			\
									static_cast<float>(v))),				\
			static_cast<T>(BOUND_FN(static_cast<float>(this->g) OP			\
									static_cast<float>(v))),				\
			static_cast<T>(BOUND_FN(static_cast<float>(this->b) OP			\
									static_cast<float>(v))));				\
}
#define BOUND_FN
DEFINE_OPERATOR(/)
#undef BOUND_FN
#define BOUND_FN upperBound
DEFINE_OPERATOR(+)
DEFINE_OPERATOR(*)
#undef BOUND_FN
#define BOUND_FN lowerBound
DEFINE_OPERATOR(-)
#undef BOUND_FN
#undef DEFINE_OPERATOR

template <typename T, unsigned int MAXVAL>
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
template <typename T, unsigned int MAXVAL>
std::ostream		&operator<<(std::ostream &o, SPEC const &rhs)
{
	return (o << "(" << rhs.r << "/" << rhs.g << "/" << rhs.b << ")");
}

#undef SPEC
