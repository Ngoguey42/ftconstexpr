
#ifndef FTCONSTEXPR_VERTEX_SIZE3_HPP
# define FTCONSTEXPR_VERTEX_SIZE3_HPP

# include "Vertex.hpp"

# define CAT_EQ_OP(OP) OP ## =

template <typename T>
class Vertex<T, 3u>
{
private:
	// * NESTED OBJECTS ************* //
	typedef T							Vertex::*AttributePointer;
	typedef std::tuple<T, T, T>			AssortedTuple3;
	typedef std::pair<T, T>				AssortedTuple2;
public:
	// * ATTRIBUTES ***************** //
	T						x;
	T						y;
	T						z;
	
	// * CTORS / DTORS ************** //
	CONSTEXPR Vertex() noexcept;
	CONSTEXPR Vertex(Vertex const &rhs) noexcept;
	CONSTEXPR Vertex(std::initializer_list<T> l) noexcept;
	CONSTEXPR Vertex(AssortedTuple2 const &t) noexcept;
	CONSTEXPR Vertex(AssortedTuple3 const &t) noexcept;
	CONSTEXPR Vertex(T x, T y) noexcept;
	CONSTEXPR Vertex(T x, T y, T z) noexcept;
	virtual ~Vertex() = default;
	
	// * MEMBER FUNCTIONS / METHODS * //
	CONSTEXPR Vertex		&set(T x, T y) noexcept;
	CONSTEXPR Vertex		&set(T x, T y, T z) noexcept;
	
	// * OPERATORS ****************** //
	CONSTEXPR Vertex		&operator=(Vertex const &rhs) noexcept;
	CONSTEXPR Vertex		&operator=(AssortedTuple2 const &rhs) noexcept;
	CONSTEXPR Vertex		&operator=(AssortedTuple3 const &rhs) noexcept;
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
	CONSTEXPR explicit operator AssortedTuple3() const noexcept;
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

#endif // ************************************** FTCONSTEXPR_VERTEX_SIZE3_HPP //
