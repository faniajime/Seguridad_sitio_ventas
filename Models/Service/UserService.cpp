#include "UserService.h"
#include "Database.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

UserService::UserService(){
  Database* db = new Database();
  if(db->connectToDatabase()){
    conn = db->getConnection();
  }else{
    printf("Hubo un error con la conexión");
    exit(1);
  }
}


void UserService::error(){
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

UserService::~UserService(){}

bool UserService::createUser(string nombre, string usuario, string email, int telefono, string contrasena, string direccion){
    if (conn==NULL){
        error();
    }
    string query = "CALL crear_usuario( '" + nombre + "','" + usuario  + "','" + email  + "','" +  to_string(telefono)  + "','" + contrasena  + "','" + direccion  + "')"  ;
    if (mysql_query(conn,query.c_str())){
      error();
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

bool UserService::passwordCorrect(string username, string password){
  MYSQL_ROW row;
  MYSQL_RES* res;
  char* response = 0;
  bool exists = false;
  string query = "CALL validate_password( '" + username + "','" + password + "')"  ;
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