#include <iostream>
#include "euclid.h"

extern Combine;
// 欧几里得算法求解最大公因数
int euclidean(int a, int b){
    int r;
    while((r = a % b) != 0){
        a = b;
        b = r;
    }
    return b;
}
// 求解最大公因数并返回线性组合
Combine Extended_euclidean(int a, int b){
    int s0 = 1, s1 = 0, s2 = 0, t0 = 0, t1 = 1, t2 = 1;

    int r, q;
    while((r = a % b) != 0){
        q = a / b;
        s2 = s0 - q * s1;
        t2 = t0 - q * t1;
        s0 = s1;
        s1 = s2;
        t0 = t1;
        t1 = t2;
        a = b;
        b = r;
    }
    return Combine {s2, t2};
}