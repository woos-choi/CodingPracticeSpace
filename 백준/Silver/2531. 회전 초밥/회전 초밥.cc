#include <iostream>
#include <deque>
#include <vector>
#include <set>
#include <map>
#include <algorithm>

using namespace std;

/*
* 2531번 회전 초밥
* 1. 벨트의 임의의 한 위치부터 k개의 접시를 연속해서 먹을 경우 할인된 정액 가격으로 제공한다
* 2. 각 고객에게 초밥의 종류 하나가 쓰인 쿠폰을 발행, 1번 행사에 참여할 경우 이 쿠폰에 적혀진 종류의 초밥 하나를 무료로 제공
* 2-1. 이 쿠폰에 적혀진 종류의 초밥이 없는 경우 요리가 새로 만들어 손님에게 제공
* 
* 가능한 한 다양한 종류의 초밥을 먹으려고 함
* 이렇게 짜니까 시간초과가 나오는데.. 흠..

*/

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);

	int n, d, k, c;
	int result = -1;
	cin >> n >> d >> k >> c;

	//시간 초과가 나는데.. 어디서 시간 초과를 줄어야 할까
	vector<int> v(n);
	for (int i = 0; i < n; i++) cin >> v[i];

	map<int, int> m;
	m.insert({ c, 1 });
	for (int i = 0; i < k; i++) {
		if (m.find(v[i]) == m.end()) m.insert({ v[i],1 });
		else (*m.find(v[i])).second++;
	}

	result = max(result, (int)m.size());
	
	for (int i = 1; i < n; i++) {
		auto back_iter = m.find(v[i - 1]);
		if ((*back_iter).second > 1) (*back_iter).second--;
		else m.erase(back_iter);

		auto present_iter = m.find(v[(i + k - 1) % n]);
		if (present_iter == m.end()) m.insert({ v[(i + k - 1) % n],1 });
		else (*present_iter).second++;

		result = max(result, (int)m.size());
	}

	cout << result;

}