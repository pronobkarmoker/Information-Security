 #include"aes_ecb.hpp"
//#include"aes_ctr.hpp"

//#include"aes_cbc.hpp"
using namespace std;

int main()
{
    string inpt, encr ;
    cout << "Input : " ;
    getline( cin, inpt );
    encr = ecb_encryption( inpt ) ;
    write_file(encr);
    string decr;
     decr= getDecryptedText( encr ) ;
     write_dec_file(decr, inpt.size());
    cout<<decr<<endl;
}
