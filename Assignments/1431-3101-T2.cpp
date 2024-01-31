#include <bits/stdc++.h>
using namespace std;

string updateString(string s)
{
    string ans = "";
    int i = 0;

    //  convert j to i
    for (int j = 0; j < s.length(); j++)
    {
        if (s[j] == 'j')
        {
            s[j] = 'i';
        }
    }

    while (i < s.length())
    {

        if (i == s.length() - 1)
        {
            ans += s[i];
            ans += 'x';
            break;
        }

        if (s[i] == s[i + 1])
        {
            ans += s[i];
            ans += 'x';
            i++;
        }
        else
        {
            ans += s[i];
            ans += s[i + 1];
            i += 2;
        }
    }

    return ans;
}

string playfairCipherEncryption(string s, char diagram[5][5])
{

    s = updateString(s);

    string ans = "";

    for (int i = 0; i < s.length(); i += 2)
    {
        int r1, c1, r2, c2;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (s[i] == diagram[j][k])
                {
                    r1 = j;
                    c1 = k;
                }
                if (s[i + 1] == diagram[j][k])
                {
                    r2 = j;
                    c2 = k;
                }
            }
        }

        if (r1 == r2)
        {
            ans += diagram[r1][(c1 + 1) % 5];
            ans += diagram[r2][(c2 + 1) % 5];
        }
        else if (c1 == c2)
        {
            ans += diagram[(r1 + 1) % 5][c1];
            ans += diagram[(r2 + 1) % 5][c2];
        }
        else
        {
            ans += diagram[r1][c2];
            ans += diagram[r2][c1];
        }
    }

    return ans;
}

string playfairCipherDecryption(string s, char diagram[5][5])
{
    string ans = "";

    for (int i = 0; i < s.length(); i += 2)
    {
        int r1, c1, r2, c2;
        for (int j = 0; j < 5; j++)
        {
            for (int k = 0; k < 5; k++)
            {
                if (s[i] == diagram[j][k])
                {
                    r1 = j;
                    c1 = k;
                }
                if (s[i + 1] == diagram[j][k])
                {
                    r2 = j;
                    c2 = k;
                }
            }
        }

        if (r1 == r2)
        {
            ans += diagram[r1][(c1 - 1 + 5) % 5];
            ans += diagram[r2][(c2 - 1 + 5) % 5];
        }
        else if (c1 == c2)
        {
            ans += diagram[(r1 - 1 + 5) % 5][c1];
            ans += diagram[(r2 - 1 + 5) % 5][c2];
        }
        else
        {
            ans += diagram[r1][c2];
            ans += diagram[r2][c1];
        }
    }

    return ans;
}

int main()
{
    char diagram[5][5];
    string userstr;

    fstream file;
    file.open("playfairDiagram.txt", ios::in);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            file >> diagram[i][j];
        }
    }

    file.close();

    cout << "Enter the string: ";
    cin >> userstr;

    cout << "Encrypted string: ";
    cout << playfairCipherEncryption(userstr, diagram) << endl;

    cout << "Decrypted string: ";
    cout << playfairCipherDecryption(playfairCipherEncryption(userstr, diagram), diagram) << endl;
    cout << "[To get actual string, remove extra 'x' from the string]";
}