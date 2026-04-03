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

    string s; cin >> s;
    vector<int> v;
    int sum = 0;

    for (int i=0; i<s.length(); i++) {
        v.push_back(stoi(s.substr(i, 1)));
        sum += stoi(s.substr(i,1));
    }

    sort(v.begin(),v.end(),compare);
    if ((sum % 3 != 0) || (v.back() != 0)) cout << "-1";
    else {
        for (int i=0; i<v.size(); i++) cout << v[i];
    }
    //cout << sum;


}