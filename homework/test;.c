#include <stdio.h>
#include <gmp.h>

void calculateFactorial(int n) {
    mpz_t result;
    mpz_init(result); // 初始化结果变量为0

    // 计算阶乘
    mpz_fac_ui(result, n);

    // 将结果以十进制形式输出
    gmp_printf("%d! = %Zd\n", n, result);

    // 释放变量内存
    mpz_clear(result);
}

int main() {
    calculateFactorial(40);
    return 0;
}