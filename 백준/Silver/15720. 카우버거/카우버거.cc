#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

bool compare(int a, int b) {
    if (a > b) return true;
    return false;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int b, c, d;
    cin >> b >> c >> d;

    int max_size = 0;
    if (b >= c && b >= d) max_size = b;
    else if (c >= b && c >= d) max_size = c;
    else if (d >= b && d >= c) max_size = d;

    vector<int> v1;
    vector<int> v2;
    vector<int> v3;
    int sum = 0;

    for (int i=0; i<b; i++) {
        int data; cin >> data;
        sum += data;
        v1.push_back(data);
    }
    sort(v1.begin(),v1.end(), compare);

    for (int i=0; i<c; i++) {
        int data; cin >> data;
        sum += data;
        v2.push_back(data);
    }
    sort(v2.begin(),v2.end(), compare);

    for (int i=0; i<d; i++) {
        int data; cin >> data;
        sum += data;
        v3.push_back(data);
    }
    sort(v3.begin(),v3.end(), compare);

    int total = 0;
    for (int i=0; i<max_size; i++) {
        if (v1.size() > i && v2.size() > i && v3.size() > i) {
            total += ((v1[i] + v2[i] + v3[i]) * 0.9);
            //cout << "total : " << total << '\n';
        }

        else {
            if (v1.size() > i) total += v1[i];
            if (v2.size() > i) total += v2[i];
            if (v3.size() > i) total += v3[i];
        }
    }

    cout << sum << '\n';
    cout << total;

}