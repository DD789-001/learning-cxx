#include "../exercise.h"

struct Fibonacci {
    unsigned long long cache[128];
    int cached;

    // TODO: 实现正确的缓存优化斐波那契计算
    unsigned long long get(int i) {
        if (i < 0) {
        throw std::out_of_range("下标不能是负数");
        }

        if (i >= 128) {
        throw std::out_of_range("下标超出 cache 范围");
        }

        if (i < cached) {
            return cache[i];
        } else {
            for (; cached <= i; ++cached) {
            cache[cached] = cache[cached - 1] + cache[cached - 2];
            }
        }

        return cache[i];
    }
};

int main(int argc, char **argv) {
    // TODO: 初始化缓存结构体，使计算正确
    Fibonacci fib = {};
    fib.cache[1] = 1;
    fib.cached = 2;
    ASSERT(fib.get(10) == 55, "fibonacci(10) should be 55");
    std::cout << "fibonacci(10) = " << fib.get(10) << std::endl;
    return 0;
}
