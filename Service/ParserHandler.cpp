#include "ParserHandler.h"
#include <iostream>
#include <cstring>

using namespace std;

ParserHandler::ParserHandler(){

   ArgCnt = 0;
   for (int pos = 0; pos < MAX_ARGS; pos++)
      Name[pos] = Value[pos] = NULL;

}
ParserHandler::~ParserHandler(){}


void ParserHandler::parseQuery (int queryLength, char* queryString){

   int start_name, end_name, start_value, end_value = -1;
   while (end_value < queryLength)
   {

      start_name = end_name = end_value + 1;
      while ((end_name<queryLength) && (queryString[end_name] != '='))
         end_name++;
   

      Name[ArgCnt] = copy_string(queryString, start_name, end_name);
      decode_string(Name[ArgCnt]);


      start_value = end_value = end_name + 1;
      while ((end_value<queryLength) && (queryString[end_value] != '&'))
         end_value++;


      Value[ArgCnt] = copy_string(queryString, start_value, end_value);
      decode_string(Value[ArgCnt]);
      ArgCnt++;
   }
}
char* ParserHandler::copy_string(char *str, int start, int end)
{
   char *copy = (char *)malloc(end-start+1);
   if (copy == NULL) 
      return NULL;


   int pos;
   for (pos = start; pos < end; pos++)
      copy[pos-start] = str[pos];
   copy[pos-start] = '\0';
   return copy;
}

// para manejar digitos hex
void ParserHandler::decode_string(char *str)
{
   const char *digits = "0123456789ABCDEF";
   int length = strlen(str);

   int outpos = 0;
   for (int pos=0; pos<length; pos++)
   {
      // Handle white space
      if (str[pos] == '+')
         str[outpos++] = ' ';

      // Handle hex characters
      else if (str[pos] == '%')
      {
         char ch1 = toupper(str[++pos]);
         char ch2 = toupper(str[++pos]);
         str[outpos++] = 16*(strchr(digits, ch1)-strchr(digits,'0'))
                       + strchr(digits, ch2)-strchr(digits,'0'); 
      }


      else {
               str[outpos++] = str[pos];
      }

   }


   str[outpos] = '\0';
}


// busca el url por nombre
char *ParserHandler::GetArg(const char name[])
{

   for (int arg=0; arg<ArgCnt; arg++)
      if (strcmp(name, Name[arg]) == 0)
         return Value[arg];


   return NULL;
}

//se trae la llave del url
char *ParserHandler::GetName(int index)
{

   if ((index >= 0) && (index < ArgCnt))
      return Name[index];
   else 
      return NULL;
}

// se trae el valor del url del nombre
char *ParserHandler::GetValue(int index)
{
   // Lookup argument by location
   if ((index >= 0) && (index < ArgCnt))
      return Value[index];
   else 
      return NULL;
}


int ParserHandler::GetCnt()
{
   return ArgCnt;
}
