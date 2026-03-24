#ifndef JET_HPP
#define JET_HPP

#include <cmath>
#include <iostream>

struct Jet{
    double val, dx, dy, dxx, dxy, dyy;

    // Default constructor
    Jet() : val(0), dx(0), dy(0), dxx(0), dxy(0), dyy(0) {}

    // Parameterized constructor
    Jet(double v, double dx, double dy, double dxx, double dxy, double dyy)
        : val(v), dx(dx), dy(dy), dxx(dxx), dxy(dxy), dyy(dyy) {}

    // Copy constructor
    Jet(const Jet& other)
        : val(other.val), dx(other.dx), dy(other.dy), dxx(other.dxx), dxy(other.dxy), dyy(other.dyy) {}

    // Assignment operator
    Jet& operator=(const Jet& other)
    {
        if(this != &other)
        {
            val = other.val;
            dx = other.dx;
            dy = other.dy;
            dxx = other.dxx;
            dxy = other.dxy;
            dyy = other.dyy;
        }
        return *this;
    }

    // Negation operator
    Jet operator-() const
    {
        return Jet(-val, -dx, -dy, -dxx, -dxy, -dyy);
    }
};

//Arithmetic operators

// Jet + Jet
inline Jet operator+(const Jet& a, const Jet& b)
{
    return Jet(a.val + b.val,
                  a.dx + b.dx,
                  a.dy + b.dy,
                  a.dxx + b.dxx,
                  a.dxy + b.dxy,
                  a.dyy + b.dyy);
}

// Jet - Jet
inline Jet operator-(const Jet& a, const Jet& b)
{
    return Jet(a.val - b.val,
                  a.dx - b.dx,
                  a.dy - b.dy,
                  a.dxx - b.dxx,
                  a.dxy - b.dxy,
                  a.dyy - b.dyy);
}

// Jet * Jet
inline Jet operator*(const Jet& a, const Jet& b)
{
    return Jet(a.val * b.val,
                  a.dx * b.val + b.dx * a.val,
                  a.dy * b.val + b.dy * a.val,
                  a.val * b.dxx + 2 * (a.dx * b.dx) + a.dxx * b.val,
                  a.val * b.dxy + a.dy * b.dx + a.dx * b.dy + a.dxy * b.val,
                  a.val * b.dyy + 2 * (a.dy * b.dy) + a.dyy * b.val);
}

// Jet / Jet
inline Jet operator/(const Jet& a, const Jet& b)
{
    double b_2 = (b.val * b.val);
    return Jet(a.val/b.val,
                  (a.dx * b.val - a.val * b.dx) / b_2,
                  (a.dy * b.val - a.val * b.dy) / b_2,
                  (b_2 * (a.dxx * b.val - a.val * b.dxx) - 2 * (b.val * b.dx) * (a.dx * b.val - a.val * b.dx))/(b_2 * b_2),
                  (b_2 * (a.dxy * b.val + a.dy * b.dx - a.val * b.dxy - b.dy * a.dx) - 2 * (b.val *  b.dx) * (a.dy * b.val - a.val * b.dy))/(b_2 * b_2),
                  (b_2 * (a.dyy * b.val - a.val * b.dyy) - 2 * (b.val * b.dy) * (a.dy * b.val - a.val * b.dy))/(b_2 * b_2));
}


// Operations between Jet and double

// Jet + double
inline Jet operator+(const Jet& a, const double b) { return a + Jet(b,0,0,0,0,0); }

// double + Jet
inline Jet operator+(const double b, const Jet& a) { return Jet(b,0,0,0,0,0) + a; }

// Jet - double
inline Jet operator-(const Jet& a, const double b) { return a - Jet(b,0,0,0,0,0); }

// double - Jet
inline Jet operator-(const double b, const Jet& a) { return Jet(b,0,0,0,0,0) - a; }

// Jet * double
inline Jet operator*(const Jet& a, const double b) { return a * Jet(b,0,0,0,0,0); }

// double * Jet
inline Jet operator*(const double b, const Jet& a) { return Jet(b,0,0,0,0,0) * a; }

// Jet / double
inline Jet operator/(const Jet& a, const double b) { return a / Jet(b,0,0,0,0,0); }

// double / Jet
inline Jet operator/(const double b, const Jet& a) { return Jet(b,0,0,0,0,0) / a; }


// Elementary functions

// sin(Jet)
inline Jet sin(const Jet& a) {
    return Jet(
        std::sin(a.val),
        std::cos(a.val) * a.dx,
        std::cos(a.val) * a.dy,
        std::cos(a.val) * a.dxx - std::sin(a.val) * a.dx * a.dx,
        std::cos(a.val) * a.dxy - std::sin(a.val) * a.dx * a.dy,
        std::cos(a.val) * a.dyy - std::sin(a.val) * a.dy * a.dy
    );
}

// cos(Jet)
inline Jet cos(const Jet& a) {
    return Jet(
        std::cos(a.val),
        -std::sin(a.val) * a.dx,
        -std::sin(a.val) * a.dy,
        -std::cos(a.val) * a.dx * a.dx - std::sin(a.val) * a.dxx,
        -std::cos(a.val) * a.dx * a.dy - std::sin(a.val) * a.dxy,
        -std::cos(a.val) * a.dy * a.dy - std::sin(a.val) * a.dyy
    );
}

// exp(Jet)
inline Jet exp(const Jet& a) {
    double e_val = std::exp(a.val);
    return Jet(
        e_val,
        e_val * a.dx,
        e_val * a.dy,
        e_val * a.dx * a.dx + e_val * a.dxx,
        e_val * a.dx * a.dy + e_val * a.dxy,
        e_val * a.dy * a.dy + e_val * a.dyy
    );
}

#endif