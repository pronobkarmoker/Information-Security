#include <bits/stdc++.h>
using namespace std;

string caesarCipherEncryption(string s)
{
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            ans += (char)((s[i] - 'a' + 3) % 26 + 'a');
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            ans += (char)((s[i] - 'A' + 3) % 26 + 'A');
        }
        else
        {
            ans += s[i];
        }
    }
    return ans;
}

string caesarCipherDecryption(string s)
{
    string ans = "";
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            ans += (char)((s[i] - 'a' - 3 + 26) % 26 + 'a');
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            ans += (char)((s[i] - 'A' - 3 + 26) % 26 + 'A');
        }
        else
        {
            ans += s[i];
        }
    }
    return ans;
}

int main()
{
    string s;

    cout << "Enter the string: ";
    cin >> s;
    cout << "Encrypted string:";
    cout << caesarCipherEncryption(s) << endl;
    cout << "Decrypted string:";
    cout << caesarCipherDecryption(caesarCipherEncryption(s)) << endl;
    return 0;
}