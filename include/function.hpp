#ifndef FUNCTION_HPP
#define FUNCTION_HPP

#include "jet.hpp"
#include <cmath>

template<typename T>
T testing_function(const T& x, const T& y)
{
    return sin(x * x - 2.0 * (y + 1.0)) / exp(-y * y + cos(x * y));
}

#endif 