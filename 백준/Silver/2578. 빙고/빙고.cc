#include <iostream>
#include <queue>
#include <vector>
#include <climits>
#include <string>
#include <algorithm>

using namespace std;

int arr[5][5];
void find_pos(int data);
void find_bingo(int &flag);

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int cnt = 0;

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) cin >> arr[i][j];
    }

    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            int data; cin >> data;
            find_pos(data);

            int flag = 0;
            find_bingo(flag);
            cnt++;
            if (flag >= 3) {
                cout << cnt;
                return 0;
            }
        }
    }


}

void find_pos(int data) {
    for (int i=0; i<5; i++) {
        for (int j=0; j<5; j++) {
            if (arr[i][j] == data) {
                arr[i][j] = -1;
                return;
            }
        }
    }
}

void find_bingo(int &flag) {
    int temp_cnt = 0;
    for (int i=0; i<5; i++) {
        int temp_flag = 0;
        for (int j=0; j<5; j++) {
            if (arr[i][j] != -1) {
                temp_flag = 1;
                break;
            }
        }

        if (temp_flag == 0) flag++;
    }

    for (int j=0; j<5; j++) {
        int temp_flag = 0;
        for (int i=0; i<5; i++) {
            if (arr[i][j] != -1) {
                temp_flag = 1;
                break;
            }
        }
        if (temp_flag == 0) flag++;
    }

    int temp_flag = 0;
    for (int i=0; i<5; i++) {
        if (arr[i][i] != -1) {
            temp_flag = 1;
            break;
        }
    }
    if (temp_flag == 0) flag++;
    temp_flag = 0;
    for (int i=0; i<5; i++) {
        if (arr[i][4-i] != -1) {
            temp_flag = 1;
            break;
        }
    }
    if (temp_flag == 0) flag++;
}


