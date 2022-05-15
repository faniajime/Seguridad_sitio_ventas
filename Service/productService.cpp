#include "productService.h"
#include "Database.cpp"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


productService::productService(){
  Database* db = new Database();
  if(db->connectToDatabase()){
    conn = db->getConnection();
  }else{
    printf("Hubo un error con la conexión");
    exit(1);
  }
}


void productService::error(){
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

productService::~productService(){}

bool productService::createProduct(string name, string description, string owner, int cost)
{
  if (conn==NULL){
      error();
  }
  string query = "CALL crear_producto( '" + name+ "','" + description  + "','" + to_string(cost) + "','" +  owner+ "')"  ;
  if (mysql_query(conn,query.c_str())){
      error();
  }
  return true;
}

bool productService::getProductById(int id)
{
  MYSQL_ROW row;
  MYSQL_RES* res;
  bool exists = false;
  string query = "CALL obtener_producto_por_id( '" + to_string(id) + "')"  ;
  if(!mysql_query(conn,query.c_str())){
    res = mysql_store_result(conn);

    //************
    int i = (int) mysql_num_rows(res);//cantidad de filas
    int j = (int) mysql_num_fields(res);//cantidad de columnas   

    MYSQL_FIELD     *columna;
    int l,k;
    unsigned long   *lon;
    string name,description,cost,owner;

    // Información sobre columnas usando mysql_fetch_fields:
      cout << endl << "Informacion sobre columnas:" << endl;
      columna = mysql_fetch_fields(res);
      for(l = 0; l < j; l++) {
         cout << "Nombre: " << columna[l].name << endl;
      }
      cout << endl;

      // Leer registro a registro y mostrar:
      for(l = 0; l < i; l++) {
         row = mysql_fetch_row(res);       
      }
      name = row[1];
      description = row[2];
      cost = row[3];
      owner = row[4];
      cout <<name<<endl;
      cout <<description<<endl;
      cout <<cost<<endl;
      cout <<owner<<endl;

    //***************************
  }else{
    error();
    
  }
  mysql_free_result(res);
  return true;
}

bool productService::updateProduct(int id,string name, string description, string owner, int cost)
{
  if (conn==NULL){
      error();
  }
  string query = "CALL actualizar_producto( '"+to_string(id)+"','" + name+ "','" + description  + "','" + to_string(cost) + "','" +  owner+ "')" ;
  if (mysql_query(conn,query.c_str())){
      error();
  }
  return true;
}
  
bool productService::deleteProduct(int id)
{
  if (conn==NULL){
    error();
  }
  string query = "CALL eliminar_producto("+to_string(id)+")";
  if (mysql_query(conn,query.c_str())){
      error();
  }
  return true;
}