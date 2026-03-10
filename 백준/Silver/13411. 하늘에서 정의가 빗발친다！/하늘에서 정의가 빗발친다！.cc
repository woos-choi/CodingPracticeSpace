#include <iostream>
#include <climits>
#include <queue>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;

/*
* 13411번. 하늘에서 정의가 빗발친다.
*/

class Dot {
public:
	int x, y, v;
	double result;
	int index;

	Dot(int x, int y, int v, int index) {
		this->x = x;
		this->y = y;
		this->v = v;
		this->index = index;
		result = 0;
	}
};

bool compare(Dot a, Dot b) {
	if (a.result < b.result) return true;
	if (a.result > b.result) return false;
	if (a.index < b.index) return true;
	return false;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	int n; cin >> n;

	vector<Dot> vec;
	for (int i = 0; i < n; i++) {
		int x, y, v;
		cin >> x >> y >> v;

		vec.push_back(Dot(x, y, v, i + 1));
	}

	for (int i = 0; i < vec.size(); i++) {
		double dist = vec[i].x * vec[i].x + vec[i].y * vec[i].y;
		dist = sqrt(dist);
		vec[i].result = dist / vec[i].v;
	}

	sort(vec.begin(), vec.end(), compare);
	for (int i = 0; i < vec.size(); i++) cout << vec[i].index << '\n';


}