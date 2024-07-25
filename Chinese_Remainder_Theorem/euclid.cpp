#include <iostream>
#include <vector>
#include "euclid.h"

extern Combine;
extern DiophantineSolution;
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
// 求解线性丢番图方程 ax+by=c
DiophantineSolution Diophantine_equation(int a, int b, int c){
    int d = euclidean(a, b);
    if(c % d != 0){
        return DiophantineSolution {-1, -1, -1, -1};
    } else{
        Combine ParticularSolution = Extended_euclidean(a, b);
        ParticularSolution.c1 *= (c / d);
        ParticularSolution.c2 *= (c / d);
        DiophantineSolution ans =
                {ParticularSolution.c1, ParticularSolution.c2, b/d, -(a/d)};
        return ans;
    }
}
// 求解同余方程 ax和b模m同余
std::vector<int> Congruence_equation(int a, int b, int m){
    int d = euclidean(a, m);
    std::vector<int> Solution;
    if(b % d != 0){
        return Solution;
    } else{// 利用欧几里得算法找d个模m不同余的解
        DiophantineSolution ans = Diophantine_equation(a, -m, b);
        int k;
        for (int i = 0; i < d; ++i){
            Solution.push_back((k = ans.x0 + i * m / d) <= m ? k : k - m);
        }
        return Solution;
    }
}
// 利用Pollard rho算法尝试找到n的一个的因子
int Pollard_rho(int n, int seed){
    //使用多项式x^2+1
    int d = 1, x = seed, cnt = 0;
    std::vector<int> s{x};
    while(d == 1){
        x = f(x) % n;
        s.push_back(x);
        x = f(x) % n;
        s.push_back(x);
        d = euclidean(s[2*cnt+1] - s[cnt], n);
        ++cnt;
    }
    return d > 0 ? d : -d;
}