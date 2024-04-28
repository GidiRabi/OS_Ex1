#include <climits> // For INT_MIN
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

/**
 * Function to find the maximum subarray sum crossing the middle element.
 * 
 * @param arr An array of integers.
 * @param low The lowest index of the subarray.
 * @param mid The middle index of the subarray.
 * @param high The highest index of the subarray.
 * @return The maximum subarray sum crossing the middle element.
 */
int maxCrossingSum(int arr[], int low, int mid, int high) {
    int left_sum = INT_MIN; // Initialize left sum to the minimum possible integer value
    int sum = 0;
    // Calculate the maximum sum of the left subarray
    for (int i = mid; i >= low; i--) {
        sum += arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }

    int right_sum = INT_MIN; // Initialize right sum to the minimum possible integer value
    sum = 0;
    // Calculate the maximum sum of the right subarray
    for (int i = mid + 1; i <= high; i++) {
        sum += arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }

    return left_sum + right_sum; // Return the sum of the maximum left and right subarray sums
}

/**
 * Function to find the maximum subarray sum using the divide-and-conquer approach.
 * 
 * @param arr An array of integers.
 * @param low The lowest index of the subarray.
 * @param high The highest index of the subarray.
 * @return The maximum subarray sum.
 */
int maxSubArraySum(int arr[], int low, int high) {
    if (low == high) // Base case: If the subarray has only one element, return that element
        return arr[low];

    int mid = (low + high) / 2; // Calculate the middle index of the subarray

    // Return the maximum of three possible cases:
    // 1. Maximum subarray sum in the left subarray
    // 2. Maximum subarray sum in the right subarray
    // 3. Maximum subarray sum crossing the middle element
    return max(max(maxSubArraySum(arr, low, mid),
                   maxSubArraySum(arr, mid + 1, high)),
               maxCrossingSum(arr, low, mid, high));
}

/**
 * Function to generate an array of random integers and find the maximum subarray sum using the divide-and-conquer approach.
 * 
 * @param seed The seed value for random number generation.
 * @param size The size of the array to be generated.
 */
void runDivideAndConquer(int seed, int size) {
    srand(seed); // Seed the random number generator
    int *arr = new int[size]; // Dynamically allocate memory for the array
    // Generate random integers and store them in the array
    for (int i = 0; i < size; ++i)
        arr[i] = rand() % 100 - 25;
    // Find the maximum subarray sum using the divide-and-conquer approach
    maxSubArraySum(arr, 0, size - 1);
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
    // Run the divide-and-conquer approach with provided seed and size
    runDivideAndConquer(seed, size);
    return 0; // Return 0 indicating successful execution
}

