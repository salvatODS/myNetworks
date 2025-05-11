#include <iostream>
#include <thread>
#include <atomic>
#include <vector>

std::atomic<int> counter(0); // Atomic counter

void increment(int iterations) {
    for (int i = 0; i < iterations; ++i) {
        ++counter; // Atomic increment
    }
}

int main() {
    const int numThreads = 4;
    const int iterations = 100000;

    std::vector<std::thread> threads;

    // Create threads
    for (int i = 0; i < numThreads; ++i) {
        threads.emplace_back(increment, iterations);
    }

    // Join threads
    for (auto& t : threads) {
        t.join();
    }

    std::cout << "Final counter value: " << counter.load() << std::endl;

    return 0;
}