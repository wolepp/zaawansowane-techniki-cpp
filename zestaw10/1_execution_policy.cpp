#include <iostream>
#include <vector>
#include <random>
#include <execution>
#include <chrono>

using namespace std;
using chrono::duration_cast;
using chrono::milliseconds;
using chrono::steady_clock;

#define N 20
#define CALC_TIME(start, stop) duration_cast<milliseconds>(stop - start).count() / 1000.0


vector<int> *genLargeVector(size_t vectorSize = 1'000'000)
{
    static random_device rnd_device;
    mt19937 mersenne_twister_engine{rnd_device()};
    uniform_int_distribution<int> dist{1, 100};

    auto gen = [&dist, &mersenne_twister_engine]() {
        return dist(mersenne_twister_engine);
    };

    vector<int> *v = new vector<int>(vectorSize);
    generate(begin(*v), end(*v), gen);
    return v;
}

void info(const string &s)
{
    cout << s << endl;
}

int main(int argc, char const *argv[])
{
    vector<int> *v1 = genLargeVector();
    vector<int> *v2 = new vector(*v1);
    vector<int> *v3 = new vector(*v1);
    vector<int> *v4 = new vector(*v1);

    info("running no policy");
    steady_clock::time_point start_std = steady_clock::now();
    for (long i = 0; i < N; i++)
    {
        sort(v1->begin(), v1->end());
    }
    steady_clock::time_point stop_std = steady_clock::now();

    // sequeced policy - wymusza wykonywanie w wątku,
    // który wywołał funkcję - brak równoległości
    info("running sequenced");
    steady_clock::time_point start_seq = steady_clock::now();
    for (long i = 0; i < N; i++)
    {
        sort(execution::seq, v2->begin(), v2->end());
    }
    steady_clock::time_point stop_seq = steady_clock::now();

    // parallel policy - informuje, że może być zrównoleglony
    info("running parallel");
    steady_clock::time_point start_par = steady_clock::now();
    for (long i = 0; i < N; i++)
    {
        sort(execution::par, v3->begin(), v3->end());
    }
    steady_clock::time_point stop_par = steady_clock::now();

    // parallel unsequenced policy - informuje, że może być zrównoleglony
    // oraz zwektoryzowany - wiele elementów może być przetworzonych jednocześnie
    info("running parallel unsequenced");
    steady_clock::time_point start_par_unseq = steady_clock::now();
    for (long i = 0; i < N; i++)
    {
        sort(execution::par_unseq, v4->begin(), v4->end());
    }
    steady_clock::time_point stop_par_unseq = steady_clock::now();

    const auto format = "%-28s %3.3fs\n";
    printf(format, "no policy", CALC_TIME(start_std, stop_std));
    printf(format, "sequenced policy", CALC_TIME(start_seq, stop_seq));
    printf(format, "parallel policy", CALC_TIME(start_par, stop_par));
    printf(format, "parallel unsequenced policy", CALC_TIME(start_par_unseq, stop_par_unseq));

    return 0;
}
