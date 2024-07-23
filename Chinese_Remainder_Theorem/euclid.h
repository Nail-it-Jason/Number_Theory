#ifndef EUCLID_H
#define EUCLID_H
typedef struct{
    int c1;
    int c2;
}Combine;

typedef struct{
    int x0;
    int y0;
    int x;
    int y;
}DiophantineSolution;

int euclidean(int a, int b);
Combine Extended_euclidean(int a, int b);
DiophantineSolution Diophantine_equation(int a, int b, int c);
std::vector<int> Congruence_equation(int a, int b, int m);
#endif
