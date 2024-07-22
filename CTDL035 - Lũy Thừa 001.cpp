#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
const ld epsilon = 1e-6;

int main()
{
    int test;
    cin >> test;
    while (test--)
    {
        ld a, b;
        int ans;
        cin >> a >> b;
        for (int k = 1; k <= 40; k++) 
        {
            ld l = pow(a, 1.0 / k);
            ld r = pow(b, 1.0 / k);
            
            ld checkleft = l - floor(l);
            ld checkright = r - ceil(r);
            if (abs(checkleft) <= epsilon)
                l = floor(l);
            else
                l = ceil(l);
            if (abs(checkright) <= epsilon)
                r = ceil(r);
            else
                r = floor(r);
            
            if (r - l >= 0)
            {
                ans = k;
            }
        }
        cout << ans << endl;
    }

    return 0;
}
