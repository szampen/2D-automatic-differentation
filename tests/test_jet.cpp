#include <iostream>
#include <cassert>
#include <cmath>
#include "jet.hpp"

bool is_close(double a, double b, double tolerance = 1e-8){
    return std::abs(a - b) < tolerance;
}

void test_addition() {
    Jet a(1, 2, 3, 4, 5, 6);
    Jet b(6, 5, 4, 3, 2, 1);
    Jet c = a + b;
    assert(c.val == 7 && c.dx == 7 && c.dyy == 7);
}

void test_multiplication() {
    // f(x,y) = x * y
    Jet x(2.0, 1.0, 0.0, 0.0, 0.0, 0.0);
    Jet y(3.0, 0.0, 1.0, 0.0, 0.0, 0.0);
    Jet f = x * y;
    
    assert(f.val == 6.0); // 2 * 3
    assert(f.dx == 3.0);  // df/dx = y = 3
    assert(f.dy == 2.0);  // df/dy = x = 2
    assert(f.dxy == 1.0); // d^2f / dxdy = 1
    assert(f.dxx == 0.0);
}

void test_sin() {
    // f(x) = sin(x) for x = pi/2
    Jet x(M_PI / 2.0, 1.0, 0.0, 0.0, 0.0, 0.0);
    Jet f = sin(x);
    
    assert(is_close(f.val, 1.0)); // sin(pi/2) = 1
    assert(is_close(f.dx, 0.0));  // cos(pi/2) = 0
    assert(is_close(f.dxx, -1.0)); // -sin(pi/2) = -1
}

int main(){
    test_addition();
    test_multiplication();
    test_sin();
    std::cout << "All Jet AD tests passed!" << std::endl;
    return 0;
}