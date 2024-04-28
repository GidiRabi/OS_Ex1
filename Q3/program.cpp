#include <iostream>
#include "../Q2/poisson.h" // taking the .h file from last question


using namespace std;

int main() {
    // Hardcoded lambda and k values from the assignment
    long double lambdas[] = {2,2,2,3,100};
    int ks[] = {1,10,2,3,3};

    // Calculate and print Poisson probabilities
    for (int i = 0; i < 5; ++i) {
        long double result = poisson_probability(lambdas[i], ks[i]);
        cout << "Poisson probability for lambda = " << lambdas[i] << ", k = " << ks[i] << ": " << fixed << result << endl;
    }

    return 0;
}

