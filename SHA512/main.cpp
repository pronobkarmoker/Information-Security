#include "sha.h"
#include <bits/stdc++.h>

int main()
{
    do
    {
        // Input
        cout << "Enter a string (press 'x' to terminate): ";
        string S;
        getline(cin, S);
        if (S == "x")
            break;
        // Function Call
        cout << S << ": " << SHA512(S) << endl;
    } while (true);

    return 0;
}