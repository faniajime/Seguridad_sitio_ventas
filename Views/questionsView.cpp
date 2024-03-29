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
  questionService = new QuestionService();
  questionService2 = new QuestionService();
  questionService3 = new QuestionService();


  char* requestMethod = getenv("REQUEST_METHOD");
  char* queryString = getenv("QUERY_STRING");
  char* contentLength = getenv("CONTENT_LENGTH");
  char* requestAddress = getenv("REMOTE_ADDR");
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
  
  //parseQuery(queryString,queryLength,parserHandler);

//  AQUI DEBERIAN IR LOS METODOS DEL PARSE QUERYM STRING, ETC
  if (queryString != NULL && contentLength != NULL) {
    parserHandler->parseQuery(queryLength, queryString);
  }
  if (requestMethod != NULL) {
    if (strcmp(requestMethod,"GET")== 0) {
      getResponse();
    }

    if (strcmp(requestMethod,"POST") ==0) {
      postResponse();
    }

  }
}

questionsView::~questionsView() {

} 
bool questionsView::getResponse() {
  
  questions = questionService->getQuestions();
  printPage();
  return true;
}

bool questionsView::postResponse() {

  char * userEmail = parserHandler->GetArg("userEmail");
  char * userQuestion = parserHandler->GetArg("question");
  string email = userEmail;
  string question = userQuestion;
  if (userEmail != NULL) {
    if (userQuestion != NULL) {
      questionService2->addQuestion(email,question);
      questions = questionService3->getQuestions();
      printPage();
    }
  }
  return true;
}

void questionsView::printPage() {
    cout << "Content-type: text/html" << endl << endl;
    cout << "<!DOCTYPE html>" << endl;
    cout << "<html lang='es'>" << endl;
    cout << "<head>" << endl;
    cout << "<head> <link rel='stylesheet' href='https://maxcdn.bootstrapcdn.com/bootstrap/4.0.0/css/bootstrap.min.css'rel='nofollow' integrity='sha384-Gn5384xqQ1aoWXA+058RXPxPg6fy4IWvTNh0E263XmFcJlSAwiGgFAW/dAiS6JXm' crossorigin='anonymous'>" <<endl;
    cout << "<title>Contact us</title>" << endl;
     cout<<"<meta charset='utf-8'>"<<endl;
    cout << "</head>" << endl;
    headerMenuView->printHeader();
    cout << "<body>" << endl;
        cout << "<section><br/><br/>" << endl;
        cout << "<h2 class='text-center mb-4 pb-2 text-primary fw-bold'>Contact us!</h2>" << endl;
        cout << "<p class='text-center mb-5'>In this page you will find questions and feedback given to this site, also you can make your own suggestions.</p>" << endl;
              cout<< "<form action='QA' method='POST' style='padding-left:20vh;padding-right:20vh;'>"<<endl;
              cout << "<div class='form-outline form-white mb-4'>" << endl;
              cout << "<label class='form-label' for='email'>Email:</label>" << endl;
              cout << "<input name='userEmail' type='email' id='email' class='form-control form-control-lg' />" << endl;
              cout << "</div>"<< endl;
              cout << "<div class='form-outline form-white mb-4'>" <<endl;
              cout << "<label class='form-label' for='question'>Question, suggestion or complaint:</label>" << endl;
             cout << "<input name='question' type='question' id='question' rows='3' class='form-control' required pattern='[a-zA-Z0-9 \.\,\?]+' title = 'please refrain from using special characters. We know what you are trying to do!' style='height:200px;font-size:14pt;' />" << endl;
              cout << "</div>" << endl;
              cout << "<div class='row' style='text-align:center'><div class='col text-center'><button class='btn btn-primary btn-sm' style='align-content: center;' type='submit'>Enviar</button></div></div>" << endl;
              cout<<"</form>"<<endl;

        cout << "<br/> <br/><h4 class='text-center mb-4 pb-2 text-primary fw-bold'>Suggestions and questions made for our users</h4>" << endl;
        cout << "<div class='row' style='padding: 5vh;'>" << endl;
        if(questions.size() >0){
          for(const auto& question : questions){
              cout << "<div class='col-md-6 col-lg-4 mb-4'>" << endl;
              cout << "<h6 class='mb-3 text-primary'><i class='far fa-paper-plane text-primary pe-2'></i> Retroalimentacion</h6>" << endl;
              cout << "<p>" << question.pregunta << "</p>" << endl;
              cout << "</div>" <<endl;
          }
        }else{
          cout << "<p><strong>There isn't any feedback yet...</strong></p>" <<endl;
        }
    cout << "</div>" <<endl;
    cout << "</section>" <<endl;
    cout << "</body>" << endl;
    cout << "</html>" << endl;
}

int main () {
  questionsView questionsPage;
}
