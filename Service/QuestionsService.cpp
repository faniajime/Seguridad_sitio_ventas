
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include "QuestionsService.h"

QuestionService::QuestionService(){
  Database* db = new Database();
  if(db->connectToDatabase()){
    conn = db->getConnection();
  }else{
    exit(1);
  }
}

QuestionService::~QuestionService(){}

bool QuestionService::addQuestion(string pregunta, string email){
    if (conn==NULL){
        return false;
    }
    string query = "CALL crear_pregunta( '" + pregunta + "','" + usuario  + "','" + email  + "','" +  to_string(telefono)  + "','" + contrasena  + "','" + direccion  + "')"  ;
    if (mysql_query(conn,query.c_str())){
      return false;
    }
    return true;
}

bool UserService::checkUserExistByUsername(string username){
  MYSQL_ROW row;
  MYSQL_RES* res;
  char* response = 0;
  bool exists = false;
  string query = "CALL username_exists( '" + username + "')"  ;
  if(!mysql_query(conn,query.c_str())){
    res = mysql_use_result(conn);
    if((row=mysql_fetch_row(res))!=NULL){
      response = row[0];
    }
    if(response[0] == '1'){
      exists = true;
    }
  }else{
    error();
    
  }
  mysql_free_result(res);
  return exists;
}
bool UserService::checkUserExistByEmail(string email){
    MYSQL_ROW row;
    MYSQL_RES* res;
    char* response = 0;
    bool exists = false;
    string query = "CALL email_exists( '" + email + "')"  ;
    if(!mysql_query(conn,query.c_str())){
      res = mysql_use_result(conn);
      if((row=mysql_fetch_row(res))!=NULL){
        response = row[0];
      }
      if(response[0] == '1'){
        exists = true;
      }
    }else{
      error();
      
    }
    mysql_free_result(res);
    return exists;
}

bool UserService::passwordCorrect(string email, string password){
  MYSQL_ROW row;
  MYSQL_RES* res;
  char* response = 0;
  bool exists = false;
  string query = "CALL validate_password( '" + email + "','" + password + "')"  ;
  if(!mysql_query(conn,query.c_str())){
    res = mysql_use_result(conn);
    if((row=mysql_fetch_row(res))!=NULL){
      response = row[0];
    }
    if(response[0] == '1'){
      exists = true;
    }
  }else{
    error();
    
  }
  mysql_free_result(res);
  return exists;
}