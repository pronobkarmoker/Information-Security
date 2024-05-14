#include<bits/stdc++.h>
#include"structures.h"
using namespace std;

int main()
{
    //---------------------rsa ---------------------------
    /*int p,q;
    while(1)
    {
        puts("enter two distinct prime numbers. p & q");
        cin>>p>>q;

        if(p==q) puts("they are same. they must be different.");
        else if(!isPrime(p)) puts("p is not prime");
        else if(!isPrime(q)) puts("q is not prime");
        else if(isPrime(p) and isPrime(q)) break;
    }

    int n=p*q;
    int phiN=(p-1)*(q-1);
    cout<<"n= "<<n<<"\nphi n= "<<phiN<<"\n";
    int e;
    while(1)
    {
        cout<<"choose an e (public key component) such that 1<e<phi n and e and phi n are coprime\n";
        cin>>e;
        if(__gcd(e,phiN)!=1) puts("e and phi n must be coprime");
        else if(e>=phiN) puts("choose e such that 1<e<phi n");
        else break;
    }*/

    if(rsa("rsa.txt"))
    cout<<"rsa completed\n";

    //-------------------- rsa functionality ------------------------------
    cout<<BigMod(3,103,7)<<"\n";
    cout<<mulInv(3,7);
}
