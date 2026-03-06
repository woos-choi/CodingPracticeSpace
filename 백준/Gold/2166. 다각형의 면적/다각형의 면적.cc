#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

/**
 * 2166. 다각형의 면적
 * 어떻게 하면 면적을 효율적으로 구할 수 있을 까..
 */

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    //신발끈 공식 쓰는 것 같은데
    int n; cin >> n;
    double sum = 0;
    vector<double> x;
    vector<double> y;

    for (int i=0; i<n; i++) {
        double a, b; cin >> a >> b;
        x.push_back(a);
        y.push_back(b);
    }

    double first = 0;
    for (int i=0; i<n; i++) {
        if (i == n - 1) first += x[i] * y[0];
        else first += x[i] * y[i + 1];
    }

    double second = 0;
    for (int i=0; i<n; i++) {
        if (i == n - 1) second += y[i] * x[0];
        else second += y[i] * x[i + 1];
    }

    sum = abs(first-second);
    sum /=2;
    cout.precision(15);
    //cout << sum << '\n';

    cout.precision(1);
    cout<<fixed;

    cout << sum;


}



