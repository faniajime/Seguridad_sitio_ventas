#include "CartService.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>


CartService::CartService(){
  Database* db = new Database();
  if(db->connectToDatabase()){
    conn = db->getConnection();
  }else{
    //printf("Hubo un error con la conexión");
    exit(1);
  }
}


CartService::~CartService(){}

bool CartService::addtoCart(string user, string productID)
{
  if (conn==NULL){
  //    error();
    return false;
  }
  string query = "CALL add_to_cart( '" + user+ "','" + productID  + "')"  ;
  if (!mysql_query(conn,query.c_str())){
    //  error();
    return true;
  }
  return false;
}

bool CartService::isInCart(string productID)
{
  MYSQL_ROW row;
  MYSQL_RES* res;
  int response ;
  bool exists = false;
  string query = "CALL is_in_cart( '" + productID + "')"  ;
  if(!mysql_query(conn,query.c_str())){
    res = mysql_use_result(conn);
    if((row=mysql_fetch_row(res))!=NULL){
      response = stoi(row[0]);
    }
    if(response >= 1){
      exists = true;
    }
  }
  mysql_free_result(res);
  return exists;
}

list<productModel> CartService::getCart(string usuario)
{
  MYSQL_ROW row;
  MYSQL_RES* res;
  productModel* product;
  string query = "CALL get_cart( '"+ usuario+ "')"  ;
  if(!mysql_query(conn,query.c_str())){
    res = mysql_store_result(conn);

    //************
    int i = (int) mysql_num_rows(res);//cantidad de filas
    int j = (int) mysql_num_fields(res);//cantidad de columnas   

    MYSQL_FIELD     *columna;
    int l,k;
    //unsigned long   *lon;
    string name,description,cost,owner, id;
    columna = mysql_fetch_fields(res);

    // Leer registro a registro:
    for(l = 0; l < i; l++) {
      row = mysql_fetch_row(res);
      id = row[0];       
      name = row[1];
      description = row[2];
      cost = row[3];
      owner = row[4];
      product = new productModel(name,description,owner,stoi(cost), stoi(id));
      cart.push_back(*product);
    }
      
    //***************************
  }
  mysql_free_result(res);
  return cart;
}

bool CartService::buyCart(string user)
{
  if (conn==NULL){
  //    error();
    return false;
  }
  string query = "CALL buy_cart( '" + user+  "')"  ;
  if (!mysql_query(conn,query.c_str())){
    //  error();
    return true;
  }
  return false;
}

bool CartService::removeProduct(string usuario, string productID)
{
  if (conn==NULL){
  //    error();
    return false;
  }
  string query = "CALL remove_from_cart( '" + usuario+ "','" + productID  + "')" ;
  if (!mysql_query(conn,query.c_str())){
    //  error();
    return true;
  }
  return false;
}

bool CartService::deleteCart(string usuario)
{
  if (conn==NULL){
  //    error();
    return false;
  }
  string query = "CALL delete_cart( '" + usuario+ "')" ;
  if (!mysql_query(conn,query.c_str())){
    //  error();
    return true;
  }
  return false;
}

int CartService::getTotal(string usuario)
{
    MYSQL_ROW row;
    MYSQL_RES* res;
    string response;
    string user;
    string query = "CALL get_total( '" + usuario + "')"  ;
    if(!mysql_query(conn,query.c_str())){
      res = mysql_use_result(conn);
      if((row=mysql_fetch_row(res))!=NULL){
        response = row[0];
      }
    }
    mysql_free_result(res);
    return stoi(response);
}