#include <iostream>
#include <vector>
#include "euclid.h"
using namespace std;
int main() {
//    std::vector<int> ans = Congruence_equation(3, 5, 8);
//    DiophantineSolution ans = Diophantine_equation(1, 2, 3);
//    cout << ans.x0 << "+n*(" << ans.x << ")" << endl;
//    cout << ans.y0 << "+n*(" << ans.y << ")" << endl;
//    for (auto &i : ans){
//        cout << i << " + 8 * n" << endl;
//    }
    cout << Pollard_rho(36287) << endl;
    return 0;
}
