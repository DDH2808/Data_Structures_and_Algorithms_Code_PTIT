#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
using namespace std;
double distance(int x1, int y1, int x2, int y2) {
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2));
}

int main() {
    int T, N;
    cin >> T; 
    while (T--) {
        cin >> N; 
        vector<pair<int, int>> points(N);
        for (int i = 0; i < N; ++i) {
            cin >> points[i].first >> points[i].second;
        }

        double minDist = 1e9; 
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                double dist = distance(points[i].first, points[i].second, points[j].first, points[j].second);
                if (dist < minDist) {
                    minDist = dist;
                }
            }
        }
        cout << fixed << setprecision(6) << minDist << " "<< endl;
    }
    return 0;
}
