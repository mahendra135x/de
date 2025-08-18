#include <iostream>
#include <cmath>
using namespace std;

int bruteForceSummation(int base, int pow) {
    int total = 0;
    for (int i = 0; i <= pow; i++) {
        int term = 1;
        for (int j = 1; j <= i; j++) {
            term *= base;
        }
        total += term;
    }
    return total;
}
int iterativeSummation(int base, int pow) {
    int total = 0;
    int term = 1;
    for (int i = 0; i <= pow; i++) {
        total += term;
        term *= base;
    }
    return total;
}


int formulaSummation(int base, int exponent) {
    if (base == 1) return exponent + 1;  // Special case: 1 + 1 + ... (exponent + 1 times)
    return (pow(base, exponent + 1) - 1) / (base - 1);
}

int main() {
    int base, power;
    cout << "Enter the base of the summation: ";
    cin >> base;
    cout << "Enter the power of the summation: ";
    cin >> power;

    cout << "\nBrute Force: " << bruteForceSummation(base, power) << endl;
    cout << "Iterative : " << iterativeSummation(base, power) << endl;
    cout << "Formula : " << formulaSummation(base, power) << endl;

    return 0;
}
