/*
Factorial Formula

n! = 1 x 2 x 3 x ... x n

*/

#include <iostream>
using namespace std;

long long fact(int n) {
    long long result = 1;

    for (int i = 1; i <= n; i++) {
        result *= i;
    }

    return result;
}

int main() {
    cout << fact(5) << endl;
    return 0;
}
