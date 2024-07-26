#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int longestCommonSubsequence(vector<int>& X, vector<int>& Y, vector<int>& Z, int nX, int nY, int nZ) {
    // Tạo mảng 3 chiều để lưu trữ kết quả
    vector<vector<vector<int>>> dp(nX + 1, vector<vector<int>>(nY + 1, vector<int>(nZ + 1, 0)));

    // Xây dựng mảng dp
    for (int i = 1; i <= nX; i++) {
        for (int j = 1; j <= nY; j++) {
            for (int k = 1; k <= nZ; k++) {
                if (X[i - 1] == Y[j - 1] && Y[j - 1] == Z[k - 1]) {
                    dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
                } else {
                    dp[i][j][k] = max(max(dp[i - 1][j][k], dp[i][j - 1][k]), dp[i][j][k - 1]);
                }
            }
        }
    }

    // Trả về độ dài dãy con chung dài nhất
    return dp[nX][nY][nZ];
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        int nX, nY, nZ;
        cin >> nX;

        vector<int> X(nX);
        for (int i = 0; i < nX; i++) {
            cin >> X[i];
        }

        cin >> nY;
        vector<int> Y(nY);
        for (int i = 0; i < nY; i++) {
            cin >> Y[i];
        }

        cin >> nZ;
        vector<int> Z(nZ);
        for (int i = 0; i < nZ; i++) {
            cin >> Z[i];
        }

        int result = longestCommonSubsequence(X, Y, Z, nX, nY, nZ);
        cout << result << endl;
    }

    return 0;
}