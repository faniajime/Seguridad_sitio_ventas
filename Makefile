all: Service/test.cpp Models/productModel.cpp Service/productService.cpp
	gcc -o test Service/test.cpp Models/productModel.cpp Service/productService.cpp `mysql_config --cflags --libs` -lstdc++

homepage: sudo g++ Service/ParserHandler.cpp Service/ParserHandler.h  Service/Database.cpp  Service/SessionService.cpp Service/UserService.cpp  Service/encryptionService.cpp Service/SHA256.cpp Views/homePageView.cpp Views/HeaderMenuView.cpp -o /var/www/cgi-bin/homePage `mysql_config --cflags --libs` -lstdc++