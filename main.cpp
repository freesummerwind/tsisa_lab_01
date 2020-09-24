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

void dichotomy(double lower, double upper,
        const double epsilon, const double delta) {
    cout << "\nPart 1. Finding minimum of the function with dichotomy method\n"
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
         << std::string(76, '-') << '\n';

    while (upper - lower > epsilon) {
        beautifulPrintingForPart1(lower, upper);
        double x1 = lower + (upper - lower) / 2 - delta,
                x2 = lower + (upper - lower) / 2 + delta;
        myFunctionFromTask(x1) < myFunctionFromTask(x2)
        ? upper = x1
        : lower = x2;
    }
    cout << '|' << std::setw(13) << lower << ' '
         << '|' << std::setw(13) << upper << ' '
         << '|' << std::setw(13) << upper - lower << ' '
         << '|' << std::string(9, ' ') << "l < epsilon" << std::string(9, ' ') << '|' << '\n'
         << std::string(76, '-') << '\n'
         << "Minimum is reached at the point x = " << std::setprecision(3)
            << lower + (upper - lower) / 2 << " +- " << std::setprecision(2)
            << (upper - lower) / 2 << '\n';
}

const double LOWER_EDGE = -2.;
const double UPPER_EDGE = 0.;
const double EPSILON = .1;

int main() {
    cout << "Variant 4.\nFunction: cos(x)*th(x)\nInterval: [" << LOWER_EDGE << " " << UPPER_EDGE << "]\n";

    dichotomy(LOWER_EDGE, UPPER_EDGE, EPSILON, .01);  // Part 1. Dichotomy

    return 0;
}
