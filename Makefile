all: Service/test.cpp Models/productModel.cpp Service/productService.cpp
	gcc -o test Service/test.cpp Models/productModel.cpp Service/productService.cpp `mysql_config --cflags --libs` -lstdc++

homepage: sudo g++ Service/ParserHandler.cpp Service/ParserHandler.h  Service/Database.cpp  Service/SessionService.cpp Service/UserService.cpp  Service/encryptionService.cpp Service/SHA256.cpp Views/homePageView.cpp Views/HeaderMenuView.cpp -o /var/www/cgi-bin/homePage `mysql_config --cflags --libs` -lstdc++


questions: 

g++ Service/ParserHandler.cpp Service/ParserHandler.h  Service/Database.cpp  Service/SessionService.cpp Service/UserService.cpp  Service/encryptionService.cpp Service/SHA256.cpp Views/questionsView.cpp Views/HeaderMenuView.cpp -o /var/www/cgi-bin/questions `mysql_config --cflags --libs` -lstdc++

g++ Service/ParserHandler.cpp Service/ParserHandler.h  Service/Database.cpp  Service/SessionService.cpp Service/UserService.cpp  Service/encryptionService.cpp Service/SHA256.cpp Service/test.cpp -o /var/www/cgi-bin/test `mysql_config --cflags --libs` -lstdc++