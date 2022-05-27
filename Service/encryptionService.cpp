#include "encryptionService.h"
#include <iostream>
#include <stdio.h>
#include <time.h>

const std::string currentDateTime() {
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    strftime(buf, sizeof(buf), "%Y-%m-%d.%X", &tstruct);

    return buf;
}

Encryptor::Encryptor()
{
}

Encryptor::~Encryptor()
{
}

string Encryptor::encrypt(string phrase){
    return sha256(phrase+salt);
}

bool Encryptor::theSame(string phrase, string compare){

    if(encrypt(phrase) == compare){
        return true;
    }else{
        return false;
    }
}

string Encryptor::encryptWithTime(string phrase){
    string timedstrng = phrase + currentDateTime();
    return sha256(timedstrng);
}

