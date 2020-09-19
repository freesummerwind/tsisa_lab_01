#include <cmath>
#include <iomanip>
#include <iostream>

using std::cin;
using std::cout;

double myFunctionFromTask(double x) {
    return std::cos(x) * std::tanh(x);
}

void beautifulPrintingForPart1(double ak, double bk) {
    cout << '|' << std::setw(13) << ak << ' '
        << '|' << std::setw(13) << bk << ' '
        << '|' << std::setw(13) << bk - ak << ' '
        << '|' << std::setw(13) << myFunctionFromTask(ak) << ' '
        << '|' << std::setw(13) << myFunctionFromTask(bk) << ' ' << '|' << '\n';
}

const double LOWER_EDGE = -2.;
const double UPPER_EDGE = 0.;
const double EPSILON = .1;

void dichotomy(double lower, double upper) {
    cout << "Part 1. Finding minimum of the function with dichotomy method\n\n"
         << std::string(76, '_') << '\n'
         << '|' << std::string(3, ' ') << "Start of" << std::string(3, ' ')
         << '|' << std::string(4, ' ') << "End of" << std::string(4, ' ')
         << '|' << std::string(2, ' ') << "Length of" << std::string(3, ' ')
         << '|' << std::string(14, ' ')
         << '|' << std::string(14, ' ') << '|' << '\n'
         << '|' << std::string(1, ' ') << "the interval" << std::string(1, ' ')
         << '|' << std::string(1, ' ') << "the interval" << std::string(1, ' ')
         << '|' << std::string(1, ' ') << "the interval" << std::string(1, ' ')
         << '|' << std::string(4, ' ') << "f(ak)" << std::string(5, ' ')
         << '|' << std::string(4, ' ') << "f(bk)" << std::string(5, ' ') << '|' << '\n'
         << '|' << std::string(5, ' ') << "(ak)" << std::string(5, ' ')
         << '|' << std::string(5, ' ') << "(bk)" << std::string(5, ' ')
         << '|' << std::string(5, ' ') << "(l)" << std::string(6, ' ')
         << '|' << std::string(14, ' ')
         << '|' << std::string(14, ' ') << '|' << '\n'
         << std::string(76, '_') << '\n';
    const double DELTA = .01;
    while(upper - lower > EPSILON) {
        beautifulPrintingForPart1(lower, upper);
        double x1 = lower + (upper - lower) / 2 - DELTA,
                x2 = lower + (upper - lower) / 2 + DELTA;
        myFunctionFromTask(x1) < myFunctionFromTask(x2)
        ? upper = x1
        : lower = x2;
    }
    cout << '|' << std::setw(13) << lower << ' '
         << '|' << std::setw(13) << upper << ' '
         << '|' << std::setw(13) << upper - lower << ' '
         << '|' << std::string(9, ' ') << "l < epsilon" << std::string(9, ' ') << '|' << '\n'
         << std::string(76, '_') << '\n';
}

int main() {
    cout << "Variant 4.\nFunction: cos(x)*th(x)\nInterval: [" << LOWER_EDGE << " " << UPPER_EDGE << "]\n";
    cout << "Part 1. Finding minimum of the function with dichotomy method\n";

    {
        const double DELTA = .01;
        beautifulPrintingForPart1(LOWER_EDGE, UPPER_EDGE);
    }

    return 0;
}
