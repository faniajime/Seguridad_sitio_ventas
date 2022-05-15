include "productService.h"
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
  string query = "CALL crear_producto( " + name + "," + description  + "," + to_string(cost)  + "," +  owner  + ")" ;
  if (mysql_query(conn,string_query)){
      error();
  }
  return true;
}

productModel productService::getProductById(int id)
{

}

bool productService::updateProduct(int id,string name, string description, string owner, int cost)
{
  if (conn==NULL){
      error();
  }
  string query = "CALL actualizar_producto( "to_string(id)+ ","  + name + "," + description  + "," + to_string(cost)  + "," +  owner  + ")" ;
  if (mysql_query(conn,string_query)){
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
  if (mysql_query(conn,string_query)){
      error();
  }
  return true;
}