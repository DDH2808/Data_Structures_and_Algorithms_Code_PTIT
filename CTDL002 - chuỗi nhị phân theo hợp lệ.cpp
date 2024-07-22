#include <iostream>
#include <string>

using namespace std;

void generateAllStrings(string& s, int index)
{
    if (index == s.size()) 
    {
        cout << s << endl; 
        return;
    }

    if (s[index] == '?') 
    {
        s[index] = '0';
        generateAllStrings(s, index + 1); 
        s[index] = '1';
        generateAllStrings(s, index + 1); 
        s[index] = '?'; 
    }
    else 
    {
        generateAllStrings(s, index + 1); 
    }
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        string s;
        cin >> s;

        generateAllStrings(s, 0);
    }
    return 0;
}
