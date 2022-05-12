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
    }
    return true;
}
