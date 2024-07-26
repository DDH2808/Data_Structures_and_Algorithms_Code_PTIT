#include <iostream>
#include <vector>

using namespace std;

int tinhTongChuSo(int n) {
    vector<int> ketQua(10000, 0);
    ketQua[0] = 1;
    int tong = 0;

    for (int i = 2; i <= n; i++) {
        for (int j = 0; j < ketQua.size(); j++) {
            ketQua[j] *= i;
        }

        for (int j = 0; j < ketQua.size() - 1; j++) {
            ketQua[j + 1] += ketQua[j] / 10;
            ketQua[j] %= 10;
        }
    }

    for (int i = ketQua.size() - 1; i >= 0; i--) {
        if (ketQua[i] != 0) {
            for (int j = i; j >= 0; j--) {
                tong += ketQua[j];
            }
            break;
        }
    }

    return tong;
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        cout << tinhTongChuSo(n) << endl;
    }

    return 0;
}