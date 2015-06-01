// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   Vertex.hpp                                         :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/01 16:00:35 by ngoguey           #+#    #+#             //
//   Updated: 2015/06/01 16:00:36 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#ifndef FTCONSTEXPR_VERTEX_HPP
# define FTCONSTEXPR_VERTEX_HPP

# include <iostream>
# include <tuple>
# include <initializer_list>
# include <type_traits>
# include <stdexcept>

namespace ftce
{
# define CONSTEXPR constexpr
// # define CONSTEXPR 

template <typename T = float, size_t S = 3u>
class Vertex
{
	static_assert(std::is_arithmetic<T>::value,
				  "ftce::Vertex type must be arithmetic");
	static_assert(S == 2 || S == 3,
				  "ftce::Vertex size must be 2 or 3(default)");
};

# include "Vertex.size3.hpp"
# include "Vertex.size2.hpp"
# undef CONSTEXPR

};	// ftce (ftconstexpr)
#endif // ******************************************** FTCONSTEXPR_VERTEX_HPP //
