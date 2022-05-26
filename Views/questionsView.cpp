#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <cstring>
#include "questionsView.h"

using namespace std;


questionsView::questionsView() {

  parserHandler = new ParserHandler();
  //userHandler = new UserService();
  headerMenuView = new HeaderMenuView();

  char* requestMethod = getenv("REQUEST_METHOD");
  char* queryString = getenv("QUERY_STRING");
  char* contentLength = getenv("CONTENT_LENGTH");
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
    cout << "<html lang='es'>" << endl;
    cout << "<head>" << endl;
    cout << "<head> <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css'rel='nofollow' integrity='sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm' crossorigin='anonymous'>" <<endl;
    cout << "<title>Contactenos</title>" << endl;
     cout<<"<meta charset='utf-8'>"<<endl;
    cout << "</head>" << endl;
    headerMenuView->printHeader();
    cout << "<body>" << endl;
        cout << "<section><br/><br/>" << endl;
        cout << "<h2 class='text-center mb-4 pb-2 text-primary fw-bold'>Contactenos</h2>" << endl;
        cout << "<p class='text-center mb-5'>En esta página podrá encontrar preguntas, sugerencias y retroalimentación a la página, así como enviar sus propias sugerencias.</p>" << endl;
              cout<< "<form action='questions' method= 'POST'>"<<endl;
              cout << "<div class='form-outline form-white mb-4'>" << endl;
              cout << "<input name='userEmail' type='email' id='typeEmailX' class='form-control form-control-lg' />" << endl;
              cout << "<label class='form-label' for='typeEmailX'>Email</label>" << endl;
              cout << "</div>"<< endl;
              cout << "<div class='form-outline form-white mb-4'>" <<endl;
              cout << "<input name='userPassword' type='password' id='typePasswordX' class='form-control form-control-lg' />" << endl;
              cout << "<label class='form-label' for='typePasswordX'>Password</label>" << endl;
              cout << "</div>" << endl;
              cout << "<p class='small mb-5 pb-lg-2'><a class='text-white-50' href='#!'> Forgot password?</a></p>" << endl;
              cout << " <button class='btn btn-outline-light btn-lg px-5' type='submit'>Login</button>" << endl;
              cout<<"</form>"<<endl;
        cout << "<div class='row' style='text-align:center'><div class='col text-center'><button class='btn btn-primary btn-sm' style='align-content: center;' type='button'>Contactanos</button></div></div>" << endl;
        cout << "<br/> <br/><h4 class='text-center mb-4 pb-2 text-primary fw-bold'>Sugerencias y preguntas anteriores</h4>" << endl;
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