#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "questionsView.h"

using namespace std;


questionsView::questionsView() {

  parserHandler = new ParserHandler();
  //userHandler = new UserService();

  char* requestMethod = getenv("REQUEST_METHOD");
  char* queryString = getenv("QUERY_STRING");
  char* contentLength = getenv("CONTENT_LENGTH");
  char* requestAddress = getenv("REMOTE_ADDR");
  char* accessToken = getenv("HTTP_COOKIE");
  int queryLength = 0;
  int accessTokenLength = 0;

  if (contentLength != NULL) {
    queryLength = atoi(contentLength);
    queryString = (char*)malloc(queryLength);
    if(queryString != NULL) {
      for (int pos = 0; pos < queryLength; pos++) {
        queryString[pos] = fgetc(stdin);
      }
    }
  }

//  AQUI DEBERIAN IR LOS METODOS DEL PARSE QUERYM STRING, ETC

  if (requestMethod != NULL) {
    if (strcmp(requestMethod,"GET")== 0) {
      getResponse();
      
    }

    if(requestMethod == "POST") {
      postResponse();
    }
  }
}

questionsView::~questionsView() {

} 
bool questionsView::getResponse() {
  printPage();
  return true;
}

bool questionsView::postResponse() {
  printPage();
  return true;
}

void questionsView::printPage() {
    cout << "Content-type: text/html" << endl << endl;
    cout << "<!DOCTYPE html>" << endl;
    cout << "<html lang='en'>" << endl;
    cout << "<head>" << endl;
        cout << "<meta charset='UTF-8'>" << endl;
        cout << "<meta http-equiv='X-UA-Compatible' content='IE=edge'>" << endl;
        cout << "<meta name='viewport' content='width=device-width, initial-scale=1.0'>" << endl;
        cout << "<link rel='stylesheet' href='https://stackpath.bootstrapcdn.com/bootstrap/4.4.1/css/bootstrap.min.css'/>" << endl;
        cout << "<title>Preguntas y respuestas</title>" << endl;
    cout << "</head>" << endl;
    cout << "<body>" << endl;
        cout << "<section><br/><br/>" << endl;
        cout << "<h3 class='text-center mb-4 pb-2 text-primary fw-bold'>Preguntas y respuestas</h3>" << endl;
        cout << "<p class='text-center mb-5'>En esta página podrá encontrar preguntas, sugerencias y retroalimentación a la página, así como enviar sus propias sugerencias.</p>" << endl;
        cout << "<div class='row' style='text-align:center'><div class='col text-center'><button class='btn btn-primary btn-sm' style='align-content: center;' type='button'>Enviar pregunta o retroalimentación</button></div></div>" << endl;
        cout << "<div class='row' style='padding: 5vh;'>" << endl;
        for(int i = 0; i<5;++i){
            cout << "<div class='col-md-6 col-lg-4 mb-4'>" << endl;
            cout << "<h6 class='mb-3 text-primary'><i class='far fa-paper-plane text-primary pe-2'></i> A simple question?</h6>" << endl;
            cout << "<p><strong><u>Absolutely!</u></strong> We work with top payment companies which guarantees your safety and security. All billing information is stored on our payment processing partner.</p>" << endl;
            cout << "</div>" <<endl;
        }
    cout << "</div>" <<endl;
    cout << "</section>" <<endl;
    cout << "</body>" << endl;
    cout << "</html>" << endl;
}

int main () {
  questionsView questionsPage;
}