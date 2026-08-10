#include "../exercise.h"

constexpr unsigned long long fibonacci(int i) {
    switch (i) {
        case 0:
            return 0;
        case 1:
            return 1;
        default:
            return fibonacci(i - 1) + fibonacci(i - 2);
    }
}

unsigned long long fibonacci_loop(int i) {
    unsigned long long first = 0;
    unsigned long long second = 1;

    for(int c = 0; c < i; c++){
        unsigned long long next = first + second;
        first = second;
        second = next;
    }

    return first;
} 

int main(int argc, char **argv) {
    //原fibonnacci函数使用了递归，constexpr需要在编译期中完成计算
    //fibonacci（90）重复调用数量巨大，编译器为了防止编译无限变慢，会限制常量表达式的计算次数
    //因此最后报告constexpr variable 'ANS' must be initialized by a constant expression
    constexpr auto FIB20 = fibonacci(20);
    ASSERT(FIB20 == 6765, "fibonacci(20) should be 6765");
    std::cout << "fibonacci(20) = " << FIB20 << std::endl;

    // TODO: 观察错误信息，修改一处，使代码编译运行
    // PS: 编译运行，但是不一定能算出结果……
    // AS: 将constexpr auto ANS = fibonacci(ANS_N);修改为auto ANS = fibonacci(ANS_N);可以编译通过
    //     但是为了解决递归深度大，计算过慢的问题，可以使用loop解决
    constexpr auto ANS_N = 90;
    auto ANS = fibonacci_loop(ANS_N);
    std::cout << "fibonacci(" << ANS_N << ") = " << ANS << std::endl;

    return 0;
}
