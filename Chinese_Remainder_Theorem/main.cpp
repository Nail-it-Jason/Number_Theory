#include <iostream>
#include "euclid.h"
using namespace std;
int main() {
    Combine ans = Extended_euclidean(3, 7);
    cout << ans.c1 << ans.c2 << endl;
    return 0;
}
