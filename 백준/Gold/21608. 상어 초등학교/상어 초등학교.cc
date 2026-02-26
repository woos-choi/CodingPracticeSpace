#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

class student {
public:
    int index;
    int x,y;
    vector<int> v;

    student(int index, vector<int> &v) {
        this->index = index;
        this->v = v;
    }
};

class Data {
public:
    int x;
    int y;
    int cnt_like;
    int cnt_empty;
    Data(int x, int y, int cnt_like,int cnt_empty) {
        this->x = x;
        this->y = y;
        this->cnt_like= cnt_like;
        this->cnt_empty= cnt_empty;
    }
};

bool compare(Data a, Data b) {
    if (a.cnt_like > b.cnt_like) return true;
    if (a.cnt_like < b.cnt_like) return false;
    if (a.cnt_empty > b.cnt_empty) return true;
    if (a.cnt_empty < b.cnt_empty) return false;
    if (a.x < b.x) return true;
    if (a.x > b.x) return false;
    if (a.y < b.y) return true;
    else return false;
}

void print_room(vector<vector<int>> &room);
vector<pair<int,int>> find_empty(vector<vector<int>> &room);
pair<int,int> find_data(vector<vector<int>> &room , vector<pair<int,int>> &empty_room, student &s);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n; cin >> n;
    int result = 0;

    vector<vector<int>> room;
    for (int i=0; i<n; i++) {
        vector<int> temp(n);
        for (int j=0; j<n; j++) temp[j] = -1;
        room.push_back(temp);
    }

    vector<student> v;
    for (int i=0; i<n * n ; i++) {
        int index; cin >> index;

        vector<int> temp(4);
        for (int j=0; j<4; j++) cin >> temp[j];
        v.emplace_back(index,temp);
    }

    for (int i=0; i<v.size(); i++) {

        vector<pair<int,int>> empty_room = find_empty(room);
        //cout << "-----------------\n";
        //print_room(room);
        pair<int,int> data = find_data(room,empty_room,v[i]);
        v[i].x = data.first, v[i].y = data.second;
        room[data.first][data.second] = v[i].index;
    }

    //이제 잘 담겼으니까 점수를 체크해야함
    for (int i=0; i<v.size(); i++) {
        int x_index = v[i].x;
        int y_index = v[i].y;

        int idx[4] = {0, 1, 0, -1};
        int idy[4] = {-1, 0, 1, 0};

        int cnt = 0;
        for (int j=0; j<4; j++) {
            if (x_index + idx[j] < 0 || x_index + idx[j] >= room.size() || y_index + idy[j] < 0 || y_index + idy[j] >= room.size()) continue;
            for (int k=0;k<4;k++) {
                if (v[i].v[k] == room[x_index + idx[j]][y_index + idy[j]]) cnt++;
            }
        }

        if (cnt == 1) result += 1;
        else if (cnt == 2) result += 10;
        else if (cnt == 3) result += 100;
        else if (cnt == 4) result += 1000;
    }

    cout << result;
}

//현재 학생 v[i]를 기준으로 비어있는 칸의 상하좌우에 빈칸이 몇개, 좋아하는 학생이 몇명인지 찾는 함수 구성
pair<int,int> find_data(vector<vector<int>> &room , vector<pair<int,int>> &empty_room, student &s) {

    vector<Data> temp_empty_room;
    vector<Data> temp_like_room;

    for (int i=0; i<empty_room.size(); i++) {
        int x_index = empty_room[i].first;
        int y_index = empty_room[i].second;

        int idx[4] = {0, 1, 0, -1};
        int idy[4] = {-1, 0, 1, 0};

        int cnt_empty = 0 , cnt_like = 0;
        for (int j=0; j<4; j++) {
            if (x_index + idx[j] < 0 || x_index + idx[j] >= room.size() || y_index + idy[j] < 0 || y_index + idy[j] >= room.size()) continue;
            if (room[x_index + idx[j]][y_index + idy[j]] == -1) cnt_empty++;
            else {
                for (int k=0; k<4; k++) {
                    if (s.v[k] == room[x_index + idx[j]][y_index + idy[j]]) {
                        cnt_like++;
                        break;
                    }
                }
            }
        }
        //cout << "x_index : " << x_index << " y_index : " << y_index << " / ";
        //cout << cnt_like << " " << cnt_empty << "\n";
        //현재 칸 기준 이 학생이 좋아하는 학생이 몇명있는지, 없다면 얼마나 비어있는지 체크 완료
        if (cnt_like != 0) temp_like_room.emplace_back(x_index,y_index,cnt_like, cnt_empty);
        else temp_empty_room.emplace_back(x_index,y_index,cnt_like,cnt_empty);

    }

    if (temp_like_room.size() > 0) {
        sort(temp_like_room.begin(),temp_like_room.end(),compare);
        return pair<int,int>(temp_like_room[0].x,temp_like_room[0].y);
    }

    sort(temp_empty_room.begin(),temp_empty_room.end(),compare);
    return pair<int,int>(temp_empty_room[0].x,temp_empty_room[0].y);

}

void print_room(vector<vector<int>> &room) {
    for (int i=0; i<room.size(); i++) {
        for (int j=0; j<room[i].size(); j++) {
            cout << room[i][j] << " ";
        }
        cout << '\n';
    }
    cout << '\n';
}

vector<pair<int,int>> find_empty(vector<vector<int>> &room) {
    vector<pair<int,int>> result;
    for (int i=0; i<room.size(); i++) {
        for (int j=0; j<room[i].size(); j++) {
            if (room[i][j] == -1) result.push_back({i, j});
        }
    }

    return result;
}