#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define MAX_ARGS 1000

class parserHandler{

    public:
    parserHandler();
    ~parserHandler();
    void parseQuery(int queryLength, char* queryString);
    char *copy_string(char *str, int start, int end);
    void decode_string(char *str);
    char *GetArg(const char name[]);
    char *GetName(int index);
    char *GetValue(int index);
    int GetCnt();
    private:
     int ArgCnt;
     char *Name[MAX_ARGS];
     char *Value[MAX_ARGS];
};