#include <iostream>
#include <thread>
#include <mutex>

namespace Limits
{
    constexpr size_t MAX_ITERS = 1'000'000;
}

std::mutex mutex;
std::condition_variable access;
volatile int cnt_iters = 0;

void thread_function(int parity)
{
    for (;;) {
        {
            std::unique_lock<std::mutex> lg(mutex);
            if (cnt_iters >= Limits::MAX_ITERS) {
                access.notify_one();
                break;
            }

            while ((cnt_iters & 1) == (parity ^ 1)) {
                access.wait(lg);
            }
            std::cout << (parity == 0 ? "ping" : "pong") << std::endl;
            ++cnt_iters;
        }
        access.notify_one();
    }
}

int main()
{
    std::thread t0(thread_function, 0);
    std::thread t1(thread_function, 1);

    t0.join();
    t1.join();
}