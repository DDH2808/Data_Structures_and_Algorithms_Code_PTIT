#include <iostream>
#include <cmath> 
using namespace std;
long long sumDigits(long long x) {
    if (x < 10) return x * (x + 1) / 2;

    int d = log10(x);

    long long *a = new long long[d + 1];
    a[0] = 0;
    a[1] = 45;
    for (int i = 2; i <= d; i++)
        a[i] = a[i - 1] * 10 + 45 * pow(10, i - 1);

    long long p = pow(10, d);
    long long msd = x / p;

    long long result = msd * a[d] + (msd * (msd - 1) / 2) * p + msd * (1 + x % p) + sumDigits(x % p);

    delete[] a;
    return result;
}

long long sumDigitsInRange(long long n, long long m) {
    return sumDigits(m) - sumDigits(n - 1);
}

int main() {
    int t;
    cin >> t; 
    while (t--) {
        long long n, m;
        cin >> n >> m; 
        cout << sumDigitsInRange(n, m) << endl; 
    }
    return 0;
}