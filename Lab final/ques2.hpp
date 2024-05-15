#include <bits/stdc++.h>
using namespace std;

string pre_process(string input)
{
    stringstream fS;

    for (int i = 0; i < input.size(); ++i)
    {
        fS << bitset<8>(input[i]);
    }

    string s1024;

    s1024 = fS.str();

    cout << "Binary representation before padding: " << s1024 << endl;
    int originalLength = s1024.length();
    int extraCells;

    int modded = s1024.length() % 1024;

    if (1024 - modded >= 128)
    {
        extraCells = 1024 - modded;
    }
    else if (1024 - modded < 128)
    {
        extraCells = 2048 - modded;
    }

    s1024 += "1";

    for (int y = 0; y < extraCells - 129; y++)
    {
        s1024 += "0";
    }

    string lengthBits = std::bitset<128>(originalLength).to_string();

    s1024 += lengthBits;

    return s1024;
}