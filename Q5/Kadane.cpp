#include <climits> // For INT_MIN
#include <iostream>
#include <cstdlib> // For srand, rand
#include <ctime> // For time

using namespace std;

/**
 * Function to find the maximum subarray sum using Kadane's Algorithm.
 * 
 * @param arr An array of integers.
 * @param n The size of the array.
 * @return The maximum subarray sum.
 */
int maxSubArraySum(int arr[], int n) {
    int max_so_far = INT_MIN, max_ending_here = 0;
    for (int i = 0; i < n; i++) {
        max_ending_here = max_ending_here + arr[i];
        if (max_so_far < max_ending_here)
            max_so_far = max_ending_here;
        if (max_ending_here < 0)
            max_ending_here = 0;
    }
    return max_so_far;
}

/**
 * Function to generate an array of random integers and find the maximum subarray sum using Kadane's Algorithm.
 * 
 * @param seed The seed value for random number generation.
 * @param size The size of the array to be generated.
 */
void runKadane(int seed, int size) {
    srand(seed); // Seed the random number generator
    int *arr = new int[size]; // Dynamically allocate memory for the array
    // Generate random integers and store them in the array
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 100 - 25;
    // Find the maximum subarray sum using Kadane's Algorithm
    maxSubArraySum(arr, size);
    delete[] arr; // Free memory allocated for the array
}

/**
 * Main function to parse command line arguments and execute the program.
 * 
 * @param argc The number of command line arguments.
 * @param argv An array of command line arguments.
 * @return 0 on successful execution, 1 otherwise.
 */
int main(int argc, char *argv[]) {
    // Check if correct number of command line arguments are provided
    if (argc != 3) {
        cerr << "Usage: " << argv[0] << " <seed> <size>" << endl;
        return 1; // Return 1 indicating incorrect usage
    }
   

