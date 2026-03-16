#include <iostream>
#include <cmath>
#include <string>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    long long result;
    for (int i=0; i<t; i++) {
        int data; cin >> data;
        if (data % 2 == 1) result = 0;
        else result = pow(2,data/2);
        cout << result << '\n';
    }
}