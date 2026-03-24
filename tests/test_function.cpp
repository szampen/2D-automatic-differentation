#include <iostream>
#include <cassert>
#include <cmath>
#include "jet.hpp"
#include "function.hpp"

bool is_close(double a, double b, double tolerance = 1e-8){
    return std::abs(a - b) < tolerance;
}


int main() {
    Jet x(0.0, 1.0, 0.0, 0.0, 0.0, 0.0);
    Jet y(1.0, 0.0, 1.0, 0.0, 0.0, 0.0);

    Jet res = testing_function(x, y);

    // f(0, 1) = 0.756802495307928
    assert(is_close(res.val, 0.756802495307928));
    
    // fx(0, 1) = 0.0
    assert(is_close(res.dx, 0.0));
    
    //  fy(0, 1) = 2.82089223234308
    assert(is_close(res.dy, 2.82089223234308));

    std::cout << "Basic function test passed!" << std::endl;
    return 0;
}