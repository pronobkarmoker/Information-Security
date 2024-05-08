#ifndef AES_C_H
#define AES_C_H

void AESEncryption(unsigned char * plainText, unsigned char * expandedKey, unsigned char * cipher);
void AESDecryption(unsigned char * cipher, unsigned char * expandedKey, unsigned char * plainText);

#endif