// ************************************************************************** //
//                                                                            //
//                                                        :::      ::::::::   //
//   main.cpp                                           :+:      :+:    :+:   //
//                                                    +:+ +:+         +:+     //
//   By: ngoguey <ngoguey@student.42.fr>            +#+  +:+       +#+        //
//                                                +#+#+#+#+#+   +#+           //
//   Created: 2015/06/01 15:51:05 by ngoguey           #+#    #+#             //
//   Updated: 2015/06/01 15:51:10 by ngoguey          ###   ########.fr       //
//                                                                            //
// ************************************************************************** //

#include "Vertex.hpp"
#include "Vertex.test.hpp"

#include "Color.hpp"
#include "Color.test.hpp"

#include "VtsColor.hpp"
#include "VtsColor.test.hpp"

int main(void)
{
	ftce::testVertex();
	ftce::testColor();
	ftce::testVtsColor();
	return (0);
}
