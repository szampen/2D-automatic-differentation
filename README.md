# 2D-Automatic-Differentation: C++ Forward-Mode Automatic Differentation Library

A high-performance, header-only C++ library for Forward-Mode Automatic Differentation(AD). The lib uses Jet propagation (an extension of dual numbers) to simultaneously compute the function's value and its exact first and second-order partial derivatives.

## Key features
- **Header-only Architecture:** The mathematical logic resides entirely in `jet.hpp`, allowing the compiler to perform aggressive optimizations (`inline`) and eliminating function-call overhead.
- **Full Hessian Matrix:** Computes all second-order partial derivatives for functions of two variables.
- **Operator Overloading:** The mathematical code looks natural. It supports addition, subtraction, multiplication, and division between Jets and scalars.
- **Elementary Functions:** Built-in support for `sin(x)`, `cos(x)`, and `exp(x)`, along with their propagation to higher-order derivatives via the Chain Rule.

## Project Structure

```text
2D-automatic-differentation/
├── Makefile                # Build script for the application and tests
├── README.md               #
├── .gitignore              
├── include/
│   ├── jet.hpp             # CORE ENGINE: Jet structure and algebra
│   └── function.hpp        # Testing function definition
├── src/
│   └── main.cpp            # Entry point (CLI), handles I/O streams
└── tests/
    ├── test_jet.cpp        # Unit tests for Jet operations with assertions
    └── test_function.cpp   # Integration tests verified with Mathematica
```

## Build & Run

This project uses `make`. It requires a compiles that supports the `C++17` standard.

1. **Clone the repository**

```bash
git clone https://github.com/szampen/2D-automatic-differentation.git
cd 2D-automatic-differentation
```

2. **Build the application**

To compile the main program and all the tests, run the following command:

```bash
make all
```

3. **Run the solver**

The application expects data from standard input(stdin).

```bash
./autodiff_solver
```

**Clean binaries**

To remove all compiled executable files:
```bash
make clean
```

## Input/Output format

This program calculates derivatives at specific points provided by user.

**Input data:**

The first line is the number of points `N`. The following `M` lines contain the coordinates `x_i` and `y_i`

```text
4
0.0 1.0
1.0 -1.0
-2.0 2.0
10.0 0.1
```

**Output data:**

For each point, the program outputs 6-space separated values with 15-decimal precision: `f`, `f_x`, `f_y`, `f_xx`, `f_xy`, `f_yy`.

```text
0.756802495307928 0.000000000000000 2.820892232343080 -0.550484746419296 0.000000000000000 6.742753957524750
...
```

## How to define your own function?

To compute Jets for a new function, simply edit `include/function.hpp` file. The function must be defined as a template `template<typename T>`, which allows it to be evaluated using both standard `double` types and the `Jet` structures.

After updating the function, simply rebuild the project (`make all`). The gradient vector and Hessian matrix values will be automatically updated for every tested point.

