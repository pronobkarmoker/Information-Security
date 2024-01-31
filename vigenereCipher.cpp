#include <bits/stdc++.h>
using namespace std;

string key = "deceptive";

string updateKey(string s, string key)
{
    string updateKey = key;
    updateKey += s;
    updateKey.erase((updateKey.size() - key.size()), updateKey.size());
    return updateKey;
}

string vigenereCipherEncryption(string s)
{
    key = updateKey(s, key);
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            ans += (char)((((s[i] - 'a') + (key[i] - 'a')) % 26) + 'a');
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            ans += (char)((((s[i] - 'A') + (key[i] - 'a')) % 26) + 'A');
        }
        else
        {
            ans += s[i];
        }
    }

    return ans;
}

string vigenereCipherDecryption(string s)
{
    string ans = "";

    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] >= 'a' && s[i] <= 'z')
        {
            ans += (char)(((((s[i] - 'a') - (key[i] - 'a')) + 26) % 26) + 'a');
        }
        else if (s[i] >= 'A' && s[i] <= 'Z')
        {
            ans += (char)(((((s[i] - 'A') - (key[i] - 'a')) + 26) % 26) + 'A');
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

    cout << "Encrypted string: ";
    cout << vigenereCipherEncryption(s) << endl;

    cout << "Decrypted string: ";
    cout << vigenereCipherDecryption(vigenereCipherEncryption(s)) << endl;

    return 0;
}