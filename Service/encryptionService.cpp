#include "encryptionService.h"
#include "SHA256.h"


Encryptor::Encryptor()
{
}

Encryptor::~Encryptor()
{
}

string Encryptor::encrypt(string phrase){
    return sha256(phrase);
}

bool Encryptor::theSame(string phrase, string compare){

    if(encrypt(phrase) == compare){
        return true;
    }else{
        return false;
    }
}
