#include <iostream>
#include <iomanip>
#include "function.hpp"
#include "jet.hpp"

void print_jet(const Jet& a){
    std::cout << a.val << " " << a.dx << " " << a.dy << " " << a.dxx << " " << a.dxy << " " << a.dyy << std::endl;
}

int main(){
    std::cout << std::setprecision(17);
    int number_of_points;
    std::cin >> number_of_points;
    for (int i = 0; i < number_of_points; i++){
        double x,y;
        std::cin >> x >> y;
        Jet result = testing_function(Jet(x,1,0,0,0,0), Jet(y,0,1,0,0,0));
        print_jet(result);
    }

    return 0;
}