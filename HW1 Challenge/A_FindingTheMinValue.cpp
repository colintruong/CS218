#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

/*
Step 1: Given f(x) = x^2 / ln x + a * x, find the derivative to detect when delta x = 0. This comes out to be
x(2 ln x - 1) + a (ln x)^2 = 0
Step 2: Plug in a and solve for x. Use the bisection method where the minimum occurs between 1 < x < sqrt(e). Use something similar to
binary search to find the exact value.
Step 3: Plug x back into the original equation to find the y value.
*/

double minValue(double a) {
    // Step 2
    double l = 1.0;
    double r = sqrt(exp(1.0));

    while (r - l > 1e-9) {
        double mid = (l + r) / 2;

        double interval = mid * (2 * log(mid) - 1) + a * pow(log(mid), 2);

        if (interval < 0) {
            l = mid;
        } else if (interval > 0) {
            r = mid;
        }
    }
    double x_min = (l + r) / 2;
    return (x_min * x_min / log(x_min)) + a * x_min;
}

int main() {
    double a;
    cin >> a;
    cout << fixed << setprecision(9) << minValue(a) << endl;
    return 0;
}