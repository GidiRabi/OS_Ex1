#include <iostream>
#include <cmath>

using namespace std;

long double poisson_probability(long double lambda, int k) {
    return (pow(lambda, k) * expf(-lambda)) / tgamma(k + 1);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        cout << "Error\n";
        return 1;
    }

    long double lambda = strtold(argv[1], nullptr);
    int k = atoi(argv[2]);

    long double result = poisson_probability(lambda, k);
    cout << fixed << result << endl;

    return 0;
}

