#include <iostream>
#include <vector>
#include <set>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
    if (a.length() < b.length()) return true;
    if (a.length() > b.length()) return false;
    if (a.length() == b.length()) {
        if (a < b) return true;
        return false;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    vector<string> v;
    vector<string> v_boj;
    set<string> s;
    set<string> s_boj;
    int n; cin >> n;
    cin.get();

    for (int i=0; i<n; i++){
        string data;
        getline(cin,data);

        if (data.substr(0,7) == "boj.kr/") {
            if (s_boj.find(data) == s_boj.end()) v_boj.push_back(data);
        }

        else {
            if (s.find(data) == s.end()) v.push_back(data);
        }
    }

    sort(v.begin(),v.end(),compare);
    sort(v_boj.begin(),v_boj.end(),compare);
    for (int i=0; i<v.size(); i++) cout << v[i] << '\n';
    for (int i=0; i<v_boj.size(); i++) cout << v_boj[i] << '\n';

}