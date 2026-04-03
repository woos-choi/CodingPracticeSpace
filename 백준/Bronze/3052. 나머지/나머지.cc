#include <iostream>
#include <vector>
#include <set>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    set<int> s;
    for (int i=0; i<10; i++) {
        int data; cin >> data;
        s.insert(data % 42);
    }

    cout << s.size();

}