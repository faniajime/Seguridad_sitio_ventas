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
    string encryptWithTime(string phrase);
   private:
   string salt = "lapelos";
};

#endif
