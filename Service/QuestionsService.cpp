
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
    string query = "CALL crear_pregunta( '" +  pregunta + "','" + email + "')"  ;
    if (!mysql_query(conn,query.c_str())){
      return false;
    }
    return true;
}


list<questionModel> QuestionService::getQuestions(){
  MYSQL_ROW row;
  MYSQL_RES* res;
  questionModel* question;
  list<questionModel> questionList;
  string query = "CALL get_preguntas( )" ;
  if(!mysql_query(conn,query.c_str())){
    res = mysql_store_result(conn);
    int i = (int) mysql_num_rows(res);//cantidad de filas
    int j = (int) mysql_num_fields(res);//cantidad de columnas   

    MYSQL_FIELD *columna;
    int l,k;
    string id, email, pregunta;

    columna = mysql_fetch_fields(res);
    for(l = 0; l < i; l++) {
        row = mysql_fetch_row(res);     
        id = row[0];  
        email = row[1];
        pregunta = row[2];
        question = new questionModel(email,pregunta, id);
        questionList.push_back(*question);
      }
  }else{
    return questionList;
    
  }
  mysql_free_result(res);
  return questionList;

}