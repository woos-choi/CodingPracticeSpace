#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int a, b, c;
    while (true) {
        cin >> a >> b >> c;
        if ( a== 0 && b == 0 & c == 0) break;

        if (a >= b && a >= c && a >= b + c) cout << "Invalid\n";
        else if (b >= c && b >= a && b >= a + c) cout << "Invalid\n";
        else if (c >= a && c >= b && c >= b + a) cout << "Invalid\n";
        else if (a == b && b == c) cout << "Equilateral\n";
        else if ((a == b && a != c) || (b == c && b != a) || (a == c && a != b)) cout << "Isosceles\n";
        else if (a != b && b != c && a != c) cout << "Scalene\n";
    }

}

