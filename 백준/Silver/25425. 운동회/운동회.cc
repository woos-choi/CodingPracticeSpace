#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    long long n, m, a,k;
    cin >> n >> m >> a >> k;

    long long temp = a - k;
    //현재 남은 인원수를 temp라고 하자 (우리 팀은 제외하고)
    //지금 남음 팀원 수는
    long long min, max;
    min = temp / m + 1;
    if (temp % m != 0) min += 1;

    if (temp >= n - 1) max = n;
    else max = temp + 1;

    cout << max << " " << min;



}



