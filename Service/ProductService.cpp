#include "ProductService.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


ProductService::ProductService(){
  Database* db = new Database();
  if(db->connectToDatabase()){
    conn = db->getConnection();
  }else{
    printf("Hubo un error con la conexión");
    exit(1);
  }
}


void ProductService::error(){
    fprintf(stderr, "%s\n", mysql_error(conn));
    mysql_close(conn);
    exit(1);
}

ProductService::~ProductService(){}

bool ProductService::createProduct(string name, string description, int cost, string owner)
{
  if (conn==NULL){
  //    error();
  }
  string query = "CALL crear_producto( '" + name+ "','" + description  + "','" + to_string(cost)+ "','" +owner+ "')"  ;
  if (!mysql_query(conn,query.c_str())){
    return true;
    //  error();
  }
  return false;
}

productModel ProductService::getProductById(int id)
{
  MYSQL_ROW row;
  MYSQL_RES* res;
  productModel* producto;
  string query = "CALL obtener_producto_por_id( '" + to_string(id) + "')"  ;
  if(!mysql_query(conn,query.c_str())){
    res = mysql_store_result(conn);

    //************
    int i = (int) mysql_num_rows(res);//cantidad de filas
    int j = (int) mysql_num_fields(res);//cantidad de columnas   

    MYSQL_FIELD     *columna;
    int l,k;
    unsigned long   *lon;
    string name,description,cost,owner, id;

    // Información sobre columnas usando mysql_fetch_fields:
      //cout << endl << "Informacion sobre columnas:" << endl;
      columna = mysql_fetch_fields(res);
      /*
      for(l = 0; l < j; l++) {
         cout << "Nombre: " << columna[l].name << endl;
      }
      cout << endl;*/

      // Leer registro a registro:
      for(l = 0; l < i; l++) {
         row = mysql_fetch_row(res);       
      }
      id = row[0];
      name = row[1];
      description = row[2];
      cost = row[3];
      owner = row[4];
      producto = new productModel(name,description,owner,stoi(cost), stoi(id));
    //***************************
  }else{
    error();
    
  }
  mysql_free_result(res);
  return *producto;
}

list<productModel> ProductService::getProducts()
{
  MYSQL_ROW row;
  MYSQL_RES* res;
  productModel* product;
  string query = "CALL obtener_productos( )" ;
  if(!mysql_query(conn,query.c_str())){
    res = mysql_store_result(conn);

    //************
    int i = (int) mysql_num_rows(res);//cantidad de filas
    int j = (int) mysql_num_fields(res);//cantidad de columnas   

    MYSQL_FIELD     *columna;
    int l,k;
    //unsigned long   *lon;
    string name,description,cost,owner, id;

    // Información sobre columnas usando mysql_fetch_fields:
      //cout << endl << "Informacion sobre columnas:" << endl;
      columna = mysql_fetch_fields(res);
      /*
      for(l = 0; l < j; l++) {
         cout << "Nombre: " << columna[l].name << endl;
      }
      cout << endl;
    */
      // Leer registro a registro:
      for(l = 0; l < i; l++) {
         row = mysql_fetch_row(res); 

         id= row[0];      
        name = row[1];
        description = row[2];
        cost = row[3];
        owner = row[4];
        product = new productModel(name,description,owner,stoi(cost), stoi(id));
        productsList.push_back(*product);
      }
      
    //***************************
  }else{
    error();
    
  }
  mysql_free_result(res);
  return productsList;
}

bool ProductService::updateProduct(int id,string name, string description, string owner, int cost)
{
  if (conn==NULL){
      error();
  }
  string query = "CALL actualizar_producto( '"+to_string(id)+"','" + name+ "','" + description  + "','" + to_string(cost) + "','" +  owner+ "')" ;
  if (!mysql_query(conn,query.c_str())){
      error();
  }
  return true;
}
  
bool ProductService::deleteProduct(int id)
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


list<productModel> ProductService::searchProductByKey(string keyword)
{
  MYSQL_ROW row;
  MYSQL_RES* res;
  productModel* product;
  string query = "CALL get_products_by_keyword( '" + keyword + "')" ;
  if(!mysql_query(conn,query.c_str())){
    res = mysql_store_result(conn);

    //************
    int i = (int) mysql_num_rows(res);//cantidad de filas
    int j = (int) mysql_num_fields(res);//cantidad de columnas   

    MYSQL_FIELD     *columna;
    int l,k;
    //unsigned long   *lon;
    string name,description,cost,owner, id;

    // Información sobre columnas usando mysql_fetch_fields:
      //cout << endl << "Informacion sobre columnas:" << endl;
      columna = mysql_fetch_fields(res);
      /*
      for(l = 0; l < j; l++) {
         cout << "Nombre: " << columna[l].name << endl;
      }
      cout << endl;
    */
      // Leer registro a registro:
      for(l = 0; l < i; l++) {
         row = mysql_fetch_row(res); 

         id= row[0];      
        name = row[1];
        description = row[2];
        cost = row[3];
        owner = row[4];
        product = new productModel(name,description,owner,stoi(cost), stoi(id));
        productsList.push_back(*product);
      }
      
    //***************************
  }else{
    error();
    
  }
  mysql_free_result(res);
  return productsList;
}