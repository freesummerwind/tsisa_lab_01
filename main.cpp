#include <cmath>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;

double myFunctionFromTask(double x) {
    return std::cos(x) * std::tanh(x);
}

void beautifulPrintingForPart1(double ak, double bk) {
    cout << '|' << std::setw(11) << ak
        << '|' << std::setw(11) << bk
        << '|' << std::setw(11) << bk - ak
        << '|' << std::setw(11) << myFunctionFromTask(ak)
        << '|' << std::setw(11) << myFunctionFromTask(bk) << '|';
}

const double LOWER_EDGE = -2.;
const double UPPER_EDGE = 0.;
const double EPSILON = .1;

int main() {
    cout << "Variant 4.\nFunction: cos(x)*th(x)\nInterval: [" << LOWER_EDGE << " " << UPPER_EDGE << "]\n";
    cout << "Part 1. Finding minimum of the function with dichotomy method\n";

    {
        const double DELTA = .01;
        beautifulPrintingForPart1(LOWER_EDGE, UPPER_EDGE);
    }

    return 0;
}
