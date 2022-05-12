#include "UserService.h"


UserService::UserService(){
  db = new Database();
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
    string query = "CALL crear_usuario( " + nombre + "," + usuario  + "," + email  + "," +  telefono  + "," + contrasena  + "," + direccion  + ")"  ;
    if (mysql_query(conn,string_query)){
       error();
    }
    return true;
}
