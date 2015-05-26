
#ifndef VERTEX_SIZE3_HPP
# define VERTEX_SIZE3_HPP

# include "Vertex.hpp"

# define CAT_EQ_OP(OP) OP ## =

template <typename T>
class Vertex<T, 3u>
{
private:
	// * NESTED OBJECTS ************* //
	typedef T							Vertex::*AttributePointer;
	typedef std::tuple<T, T, T>			AssortedTupple;
public:
	// * ATTRIBUTES ***************** //
	float	x;
	float	y;
	float	z;
	
	~Vertex(){std::cout << "Dtor\n";}
	
	// * CTORS / DTORS ************** //
	CONSTEXPR Vertex() noexcept;
	CONSTEXPR Vertex(Vertex const &rhs) noexcept;
	CONSTEXPR Vertex(std::initializer_list<T> l) noexcept;
	CONSTEXPR Vertex(AssortedTupple const &t) noexcept;
	CONSTEXPR Vertex(T x, T y) noexcept;
	CONSTEXPR Vertex(T x, T y, T z) noexcept;
	
	// * MEMBER FUNCTIONS / METHODS * //
	CONSTEXPR Vertex		&set(T x, T y) noexcept;
	CONSTEXPR Vertex		&set(T x, T y, T z) noexcept;
	
	// * OPERATORS ****************** //
	CONSTEXPR Vertex		&operator=(Vertex const &rhs) noexcept;
	CONSTEXPR Vertex		&operator=(AssortedTupple const &rhs) noexcept;
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
	CONSTEXPR explicit operator AssortedTupple() const noexcept;
private:
	// * STATICS ******************** //
	static constexpr T					defValue{static_cast<T>(0)};
	static constexpr AttributePointer	attributes[]{
		&Vertex::x,
		&Vertex::y,
		&Vertex::z
	};
};

template <typename T>
std::ostream				&operator<<(std::ostream &o,
										Vertex<T, 3u> const &rhs);

# include "Vertex.size3.tpp"
# undef CAT_EQ_OP

#endif