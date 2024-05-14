#include<bits/stdc++.h>
#include"structures.h"
using namespace std;

int main()
{
    puts("----------------------sha--------------------------");
    puts("sha : ");
    if(sha())
        cout<<"\nsha completed\n";
    else
        cout<<"not completed\n";

    puts("------------------------------sha functionality--------------------------");
    puts("sumA func");
    unsigned long long int a=0x5678ef4578dfae45;
    unsigned long long int b=0x3678ff4878bfae45;
    unsigned long long int c=0x2687ef4578cfae45;
    cout<<sumA(a)<<"\n";

    puts("sumE func");
    cout<<sumE(a)<<"\n";

    puts("sigma0");
    cout<<sigma0(a)<<"\n";

    puts("sigma1");
    cout<<sigma1(a)<<"\n";

    puts("maj");
    cout<<maj(a,b,c)<<"\n";

    puts("ch");
    cout<<ch(a,b,c)<<"\n";

    puts("rotr");
    cout<<ROTR(a,23)<<"\n";
}