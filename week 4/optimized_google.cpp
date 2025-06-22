
#include <iostream>   // Required for std::cout, std::endl, std::fixed
#include <iomanip>    // Required for std::setprecision
#include <chrono>     // Required for std::chrono::high_resolution_clock

// Function to perform the calculation
// Uses long long for iterations to prevent overflow with large counts.
// Uses double for floating-point calculations to maintain precision and match Python's default float behavior.
double calculate(long long iterations, int param1, int param2) {
    double result = 1.0; // Initial value as in Python

    // Pre-calculate constants for optimization
    const double numerator_constant = -2.0 * param2;
    const double param2_sq = static_cast<double>(param2) * param2;

    for (long long i = 1; i <= iterations; ++i) {
        // The original two terms:
        // result -= (1.0 / (i * param1 - param2));
        // result += (1.0 / (i * param1 + param2));
        // are algebraically simplified to:
        // result += (-2 * param2) / ((i * param1)^2 - param2^2)

        // Convert i to double early to ensure subsequent multiplications are floating-point
        // and prevent potential intermediate integer overflows, maintaining precision.
        double i_param1_term = static_cast<double>(i) * param1;

        // Calculate the denominator term for the optimized formula
        double denominator = i_param1_term * i_param1_term - param2_sq;

        // Add the optimized term to the result
        result += numerator_constant / denominator;
    }
    return result;
}

int main() {
    // Define parameters for the calculation
    long long iterations = 100'000'000;
    int param1 = 4;
    int param2 = 1;

    // Record the start time using high-resolution clock
    auto start_time = std::chrono::high_resolution_clock::now();

    // Perform the calculation and multiply by 4 as per the Python script
    double result = calculate(iterations, param1, param2) * 4;

    // Record the end time
    auto end_time = std::chrono::high_resolution_clock::now();

    // Calculate the duration in seconds
    std::chrono::duration<double> duration = end_time - start_time;

    // Output the final result formatted to 12 decimal places
    std::cout << std::fixed << std::setprecision(12) << "Result: " << result << std::endl;

    // Output the execution time formatted to 6 decimal places
    std::cout << std::fixed << std::setprecision(6) << "Execution Time: " << duration.count() << " seconds" << std::endl;

    return 0;
}
