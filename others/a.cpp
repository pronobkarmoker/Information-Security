#include<bits/stdc++.h>
#include"structures.h"
using namespace std;

int main()
{
    puts("------------ aes --------------------");
    string file="input.txt";
    if(CTREN(file))
        cout<<"encryption completed\n";
    else
        cout<<"not completed\n";

    string file1="message.aes";
    if(CTRDE(file1))
        cout<<"decryption completed\n";
    else
        cout<<"not completed\n";

    // here
    puts("------------------------- aes functioanlity-----------------------");
    puts("subbyte: ");
    unsigned char stateA[16];
    string st="shifatjahanshifa";
    puts("input in hex: ");
    for(int i=0; i<16; i++)
    {
        stateA[i]=st[i];
        cout << hex << (int) stateA[i];
        cout << " ";
    }
    puts("");
    SubBytes(stateA);
    puts("output after subbyte: ");
    for (int i = 0; i < 16; i++)
    {
        cout<<hex<<(int)stateA[i]<<" ";
    }
    puts("");
    // dangerous part of my work!!
    // stage : shiftrows  4 4 kore dekhabo
    puts("Shiftrows: ");
    for(int i=0; i<16; i++)
    {
        if(i%4==0) puts("");
        cout << hex << (int) stateA[i];
        cout << " ";
    }
    puts("");
    ShiftRows(stateA);
    for (int i = 0; i < 16; i++)
    {
        cout<<hex<<(int)stateA[i]<<" ";
    }
    puts("");

    // stage : MixColumn
    puts("MixColumn: ");
    for (int i = 0; i < 16; i++)
    {
        cout<<hex<<(int)stateA[i]<<" ";
    }
    puts("");
    MixColumns(stateA);
    puts("after : ");
    for (int i = 0; i < 16; i++)
    {
        cout<<hex<<(int)stateA[i]<<" ";
    }
    puts("");

    // stage : add round key lagbe na apatoto
    puts("add round key: before");
    for (int i = 0; i < 16; i++)
    {
        cout << hex << (int) stateA [i];
        cout << " ";
    }
    puts("");
    //AddRoundKey(stateA);
    // now look for inv
    puts("inverse mix column");
    InverseMixColumns(stateA);
    puts("after : ");
    for (int i = 0; i < 16; i++)
    {
        cout<<hex<<(int)stateA[i]<<" ";
    }
    puts("");

    puts("inverse shift rows:");
    InvShiftRows(stateA);
    for (int i = 0; i < 16; i++)
    {
        cout<<hex<<(int)stateA[i]<<" ";
    }
    puts("");

    puts("inverse sub byte: ");
    InvSubBytes(stateA);
    puts("output after subbyte: ");
    for (int i = 0; i < 16; i++)
    {
        cout<<hex<<(int)stateA[i]<<" ";
    }
    puts("");
}