#include <iostream>
#include <iomanip>
#include <chrono>
using namespace std;
using namespace std::chrono;
 
int main(){
    const long long iterations = 100000000;
    const int param1 = 4;
    const int param2 = 1;
    double result = 1.0;
    
    auto start = high_resolution_clock::now();
    for(long long i = 1; i <= iterations; i++){
        double j = i * param1 - param2;
        result -= 1.0 / j;
        j = i * param1 + param2;
        result += 1.0 / j;
    }
    result *= 4.0;
    auto end = high_resolution_clock::now();
    
    duration<double> exec_time = end - start;
    
    cout << fixed << setprecision(12) << "Result: " << result << "\n";
    cout << fixed << setprecision(6) << "Execution Time: " << exec_time.count() << " seconds\n";
    return 0;
}