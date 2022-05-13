#include "ParserHandler.h"
#include <iostream>
#include <cstring>

using namespace std;

ParserHandler::ParserHandler(){
   // Initialize private variables
   ArgCnt = 0;
   for (int pos = 0; pos < MAX_ARGS; pos++)
      Name[pos] = Value[pos] = NULL;

}
ParserHandler::~ParserHandler(){}


void ParserHandler::parseQuery (int queryLength, char* queryString){
// Separate query_string into arguments 
   int start_name, end_name, start_value, end_value = -1;
   while (end_value < queryLength)
   {
      // Find argument name
      start_name = end_name = end_value + 1;
      while ((end_name<queryLength) && (queryString[end_name] != '='))
         end_name++;
   
      // Copy and decode name string
      Name[ArgCnt] = copy_string(queryString, start_name, end_name);
      decode_string(Name[ArgCnt]);

      // Find argument value
      start_value = end_value = end_name + 1;
      while ((end_value<queryLength) && (queryString[end_value] != '&'))
         end_value++;

      // Copy and decode value string
      Value[ArgCnt] = copy_string(queryString, start_value, end_value);
      decode_string(Value[ArgCnt]);
      ArgCnt++;
   }
}
char* ParserHandler::copy_string(char *str, int start, int end)
{
   // Create string
   char *copy = (char *)malloc(end-start+1);
   if (copy == NULL) 
      return NULL;

   // Copy substring
   int pos;
   for (pos = start; pos < end; pos++)
      copy[pos-start] = str[pos];
   copy[pos-start] = '\0';
   return copy;
}


// Function for decoding CGI strings.

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

      // Handle remaining characters
      else
         str[outpos++] = str[pos];
   }

   // Mark end of string
   str[outpos] = '\0';
}


// Argument lookup by name.
char *ParserHandler::GetArg(const char name[])
{
   // Lookup argument by name
   for (int arg=0; arg<ArgCnt; arg++)
      if (strcmp(name, Name[arg]) == 0)
         return Value[arg];

   // Return NULL if not found
   return NULL;
}

//--------------------------------------------------------------
// Argument name lookup by number.
//--------------------------------------------------------------
char *ParserHandler::GetName(int index)
{
   // Lookup argument by location
   if ((index >= 0) && (index < ArgCnt))
      return Name[index];
   else 
      return NULL;
}

//--------------------------------------------------------------
// Argument value lookup by number.
//--------------------------------------------------------------
char *ParserHandler::GetValue(int index)
{
   // Lookup argument by location
   if ((index >= 0) && (index < ArgCnt))
      return Value[index];
   else 
      return NULL;
}

//--------------------------------------------------------------
// Return number of CGI arguments.
//--------------------------------------------------------------
int ParserHandler::GetCnt()
{
   return ArgCnt;
}