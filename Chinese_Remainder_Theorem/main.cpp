#include <iostream>
#include <vector>
#include "euclid.h"
using namespace std;
int main() {
    std::vector<int> ans = Congruence_equation(7, 1, 31);
//    DiophantineSolution ans = Diophantine_equation(1, 2, 3);
//    cout << ans.x0 << "+n*(" << ans.x << ")" << endl;
//    cout << ans.y0 << "+n*(" << ans.y << ")" << endl;
    for (auto &i : ans){
        cout << i << " + 31 * n" << endl;
    }
    return 0;
}
