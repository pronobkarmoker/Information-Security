#include<bits/stdc++.h>
#include"structures.h"
using namespace std;

int main()
{
    freopen("input.txt","r",stdin);
    char message[1024];

    cout << "Enter the message to encrypt: ";
    cin.getline(message, sizeof(message));
    cout << message << endl;

    // Pad message to 16 bytes
    int originalLen = strlen((const char *)message);

    int paddedMessageLen = originalLen;

    if ((paddedMessageLen % 16) != 0)
    {
        paddedMessageLen = (paddedMessageLen / 16 + 1) * 16;
    }

    unsigned char * paddedMessage = new unsigned char[paddedMessageLen];


    for (int i = 0; i < paddedMessageLen; i++)
    {
        if (i >= originalLen)
        {
            paddedMessage[i]=0;
        }
        else
        {
            paddedMessage[i]= message[i];
        }

    }

    unsigned char * encryptedMessage = new unsigned char[paddedMessageLen];
    unsigned char * outputMessage = new unsigned char[paddedMessageLen];

    string str;
    ifstream infile;
    infile.open("keyfile.txt", ios::in | ios::binary);

    if (infile.is_open())
    {
        getline(infile, str); // The first line of file should be the key
        infile.close();
    }

    else
        cout << "Unable to open file";

    istringstream hex_chars_stream(str);

    unsigned char key[16];
    int i = 0;
    unsigned int c;
    while (hex_chars_stream >> hex >> c)
    {
        key[i] = c;
        i++;
    }

    unsigned char expandedKey[176];

    KeyExpansion(key, expandedKey);
    string nonce="abcdzyxw";
    unsigned long long int ctr=1;

    for (int i = 0; i < paddedMessageLen; i += 16)
    {
        string in=nonce;
        string add=to_string(ctr);
        string ca;
        for(int j=0;j<8-add.size();j++)
        {
            ca+='0';
        }
        in+=ca;
        in+=add;
        cout<<in<<"\n";
        ctr++;
        //istringstream ss(in);
        unsigned char take[16];
        copy(in.begin(),in.end(),take);
        AESEncrypt(take, expandedKey,outputMessage+i);
        for(int j=0;j<16;j++)
        encryptedMessage[j+i]=outputMessage[i+j]^paddedMessage[i+j];

    }

    cout << "Encrypted message in hex:" << endl;
    for (int i = 0; i < paddedMessageLen; i++)
    {
        cout << hex << (int) encryptedMessage[i];
        cout << " ";
    }

    cout << endl;

    ofstream outfile;
    outfile.open("message.aes", ios::out | ios::binary);
    if (outfile.is_open())
    {
        outfile << encryptedMessage;
        outfile.close();
        cout << "Wrote encrypted message to file message.aes" << endl;
    }

    else
        cout << "Unable to open file";

    // Free memory
    delete[] paddedMessage;
    delete[] encryptedMessage;

    return 0;
}
