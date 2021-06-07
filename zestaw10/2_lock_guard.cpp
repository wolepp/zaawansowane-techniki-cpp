#include <vector>
#include <algorithm>
#include <execution>
#include <mutex>

using namespace std;
using chrono::duration_cast;
using chrono::microseconds;
using chrono::steady_clock;

#define CALC_TIME(start, stop) duration_cast<microseconds>(stop - start).count() / 1000000.0

int main()
{
    vector<int> vec(10'000'000);
    iota(vec.begin(), vec.end(), 0); // wypełnienie 0, 1, 2, ...
    vector<int> output;

    mutex m;
    steady_clock::time_point start_par = steady_clock::now();
    for_each(execution::par, vec.begin(), vec.end(),
                  [&output, &m](int &elem) {
                      if (elem % 2 == 0)
                      {
                          lock_guard<mutex> lock{m};
                          output.push_back(elem);
                      }
                  });
    steady_clock::time_point stop_par = steady_clock::now();


    vector<int> output_seq;
    steady_clock::time_point start_seq = steady_clock::now();
    for_each(execution::seq, vec.begin(), vec.end(),
                  [&output](int &elem) {
                      if (elem % 2 == 0)
                      {
                          output.push_back(elem);
                      }
                  });
    steady_clock::time_point stop_seq = steady_clock::now();

    const auto format = "%-15s %3.6fs\n";
    printf(format, "sequenced policy", CALC_TIME(start_seq, stop_seq));
    printf(format, "parallel policy", CALC_TIME(start_par, stop_par));

}