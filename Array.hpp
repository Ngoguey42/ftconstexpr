
#ifndef ARRAY_CLASS_HPP
# define ARRAY_CLASS_HPP

// #include <iostream>

namespace ftce //ft_ConstExpr
{
template<typename T, size_t S>
class Array
{
public:

	// * NESTED OBJECTS ************* //
	class iterator
	{
	public:
		iterator();
		iterator(iterator const &src);
		virtual ~iterator();
		
		iterator				&operator=(iterator const &rhs);
		bool					operator!=(iterator const &rhs);
		T const					&operator*(void) const;
		iterator				&operator++(void);
		
		void					setPtr(T const *ptr);
		
	private:
		T const					*_ptr;
	};
	
	// * CTORS / DTORS ************** //
	constexpr Array();
	constexpr Array(Array const &src);
	
	// * OPERATORS ****************** //
	constexpr Array				&operator=(Array const &rhs);
	constexpr T					&operator[](size_t s);
	constexpr T const			&operator[](size_t s) const;
	
	// * MEMBER FUNCTIONS / METHODS * //
	constexpr size_t			getLastIndex(void) const;
	constexpr size_t			size(void) const;
	iterator					begin(void) const;
	iterator					end(void) const;
	
protected:
private:
	// * ATTRIBUTES ***************** //
	T							_data[S];
	size_t						_lastIndex;
};

#include "Array.class.tpp"
};

#endif // *************************************** ARRAY_CLASS_HPP //
