#ifndef ENCRYPTIONSERVICE_H
#define ENCRYPTIONSERVICE_H
#include <string>

using namespace std;

class Encryptor {
  public:
    Encryptor();
    ~Encryptor();
    string encrypt(string phrase);
    bool theSame(string phrase, string sha);
   
};

#endif
