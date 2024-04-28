#include <climits> // For INT_MIN
#include <iostream>
#include <cstdlib> // For srand, rand
#include <ctime> // For time

using namespace std;

/**
 * Function to find the maximum subarray sum using a brute-force approach.
 * 
 * @param arr An array of integers.
 * @param n The size of the array.
 * @return The maximum subarray sum.
 */
int maxSubArraySum(int arr[], int n) {
    int max_sum = INT_MIN; // Initialize the maximum sum to the minimum possible integer value
    // Iterate through all subarrays and find the maximum sum
    for (int i = 0; i < n; i++) {
        int curr_sum = 0; // Initialize current sum for each starting index i
        for (int j = i; j < n; j++) {
            curr_sum += arr[j]; // Add the element at index j to the current sum
            max_sum = max(max_sum, curr_sum); // Update the maximum sum if the current sum is greater
        }
    }
    return max_sum; // Return the maximum subarray sum
}

/**
 * Function to generate an array of random integers and find the maximum subarray sum using a brute-force approach.
 * 
 * @param seed The seed value for random number generation.
 * @param size The size of the array to be generated.
 */
void runBruteForce(int seed, int size) {
    srand(seed); // Seed the random number generator
    int *arr = new int[size]; // Dynamically allocate memory for the array
    // Generate random integers and store them in the array
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 100 - 25;
    // Find the maximum subarray sum using the brute-force approach
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
    // Parse seed and size from command line arguments
    int seed = atoi(argv[1]);
    int size = atoi(argv[2]);
    // Run the brute-force approach with provided seed and size
    runBruteForce(seed, size);
    return 0; // Return 0 indicating successful execution
}

