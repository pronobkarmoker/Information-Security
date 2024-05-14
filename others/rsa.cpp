#include<bits/stdc++.h>
using namespace std;

vector<int>cipher;

bool isPrime(int p)
{
    for(int i=2;i*i<=p;i++)
    {
        if(!(p%i)) return false;
    }
    return true;
}

int mulInv(int a,int b)
{
    int maxi,mini,q,r,t1=0,t2=1,t,take=b;
    maxi=max(a,b),mini=min(a,b);
    a=maxi,b=mini;
    while(b>0)
    {
        q=a/b;
        r=a%b;
        t=t1-(t2*q);
        maxi=max(b,r),mini=min(b,r);
        a=maxi,b=mini;
        t1=t2,t2=t;
    }
    if(t1<0) t1+=take;
    return t1;
}

int BigMod(int a,int b,int m)
{
    if(b==0) return 1;
    else if(b&1)
    {
        int v1=(a%m);
        int v2=BigMod(a,b-1,m)%m;
        return (v1*v2)%m;
    }
    else
    {
        int v1=BigMod(a,b/2,m)%m;
        return (v1*v1)%m;
    }
}

void encryption(string s,int b,int m)
{
    int a;
    cipher.clear();
    for(int i=0;i<s.size();i++)
    {
        a=s[i];
        cipher.push_back(BigMod(a,b,m));
    }
    puts("in hex:");
    for(int i=0;i<cipher.size();i++)
    {
        cout<< hex <<cipher[i];
    }
}

void decryption(int d,int m)
{
    string ans;
    puts("");
    for(int i=0;i<cipher.size();i++)
    {
        int v=BigMod(cipher[i],d,m);
        cout<<static_cast<char>(v);
    }
}


int main()
{
    int p,q;
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
    }

    int d=mulInv(e,phiN);
    cout<<"public key = {"<<e<<","<<n<<"}\n";
    cout<<"private key = {"<<d<<","<<n<<"}\n";

    freopen("rsa.txt","r",stdin);
    string message;
    getline(cin,message);
    cout<<"message = "<<message<<"\n";
    encryption(message,e,n);
    decryption(d,n);
    return 1;
}


// input 53, 97, 5. 41,53
