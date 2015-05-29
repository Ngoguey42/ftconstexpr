
#ifndef FTCONSTEXPR_VTSCOLOR_HPP
# define FTCONSTEXPR_VTSCOLOR_HPP

# include <iostream>
# include <tuple>
# include <initializer_list>
# include <type_traits>
# include <stdexcept>

#include "Vertex.hpp"
#include "Color.hpp"

#define CONSTEXPR constexpr
// # define CONSTEXPR 

template <size_t NVts, typename TVts = float, size_t SVts = 3u,
		  typename Tco = unsigned char,
		  unsigned int MAXVALco = std::is_floating_point<Tco>::value
		  ? 1u
		  : 255u>
class VtsColor
{
	static_assert(NVts > 0,
				  "ftce::VtsColor 'size_t NVts' above 0");
	static_assert(std::is_arithmetic<TVts>::value,
				  "ftce::VtsColor 'typename TVts = float' must be arithmetic");
	static_assert(SVts == 2 || SVts == 3,
				  "ftce::VtsColor 'size_t SVts = 3u' must be 2 or 3(default)");
	static_assert(std::is_arithmetic<Tco>::value,
				  "ftce::Color 'Tco' must be arithmetic"); 
	static_assert(MAXVALco > 0,
				  "ftce::Color 'unsigned int MAXVALco' must be above 0.");
private:
	// * NESTED OBJECTS ************* //
	
public:
	// * NESTED OBJECTS ************* //
	typedef /*ftce::*/Vertex<TVts, SVts>			Vertex;
	typedef /*ftce::*/Color<Tco, MAXVALco>			Color;

	// * ATTRIBUTES ***************** //
	Color											c;
	Vertex											v[NVts];
	
	// * CTORS / DTORS ************** //
	CONSTEXPR VtsColor() noexcept;
	CONSTEXPR VtsColor(VtsColor const &src) noexcept;
	// * COLOR CTORS ****** //
	CONSTEXPR VtsColor(Color const &c) noexcept;
	CONSTEXPR VtsColor(Tco r, Tco g, Tco b) noexcept;
	CONSTEXPR VtsColor(std::initializer_list<Tco> lc) noexcept;
	// * VERTEX CTORS ***** //
	template<typename... Vertices>
	CONSTEXPR VtsColor(Color const &c, Vertices... lv) noexcept;
	template<typename... Vertices>
	CONSTEXPR VtsColor(Tco r, Tco g, Tco b, Vertices... lv) noexcept;
	
	// * MEMBER FUNCTIONS / METHODS * //
	
	// * OPERATORS ****************** //
	CONSTEXPR VtsColor				&operator=(VtsColor const &src) noexcept;
	CONSTEXPR Vertex				&operator[](size_t i) noexcept;
	CONSTEXPR Vertex const			&operator[](size_t i) const noexcept;
private:
	// * STATICS ******************** //
};

# include "VtsColor.tpp"
// # include "VtsColor.size1.hpp"
# undef CONSTEXPR

#endif // ****************************************** FTCONSTEXPR_VTSCOLOR_HPP //
