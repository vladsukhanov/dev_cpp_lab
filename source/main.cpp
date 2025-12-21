#include <iostream>
#include <string>
#include <future>
#include <chrono>

#include "Base.hpp"
#include "TempFun.hpp"
#include "Instrumentor_Cherno.h"

#define PROFILING_CHERNO 1
#if PROFILING_CHERNO
    #if defined(_MSC_VER)
        #define PROFILE_FUNCTION() InstrumentationTimer timer##__LINE__(__FUNCSIG__)
    #elif defined(__GNUC__) || defined(__clang__)
        #define PROFILE_FUNCTION() InstrumentationTimer timer##__LINE__(__PRETTY_FUNCTION__)
    #else
        #define PROFILE_FUNCTION() InstrumentationTimer timer##__LINE__(__func__)
    #endif
#else
    #define PROFILE_FUNCTION()
#endif

int square(int x)
{
    PROFILE_FUNCTION();

    std::this_thread::sleep_for(std::chrono::milliseconds(100)); // Simulate some work

    return x * x;
}

void exampleFunction()
{
    PROFILE_FUNCTION();

    // Simulate some work
    std::this_thread::sleep_for(std::chrono::milliseconds(200));
}

void runBenchmarks()
{
    PROFILE_FUNCTION();

    std::cout << "Running benchmarks..." << std::endl;

    std::thread a([]() { square(5); });
    exampleFunction();

    a.join();
}

// int main()
// {
//     Instrumentor::Get().BeginSession("Main Session");

//     runBenchmarks();

//     Instrumentor::Get().EndSession();

// }

void* operator new(std::size_t size)
{
    std::cout << "[new] Allocating " << size << " bytes\n";
    return std::malloc(size); // важно: malloc
}

int main()
{
    std::string myStr = "1234567890123456";

    std::cout << "String: " << myStr << std::endl;
}
