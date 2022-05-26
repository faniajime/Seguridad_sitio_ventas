all: Service/test.cpp Models/productModel.cpp Service/productService.cpp
	gcc -o test Service/test.cpp Models/productModel.cpp Service/productService.cpp `mysql_config --cflags --libs` -lstdc++

homepage: 
	sudo g++ Service/ParserHandler.cpp Service/Database.cpp  Service/SessionService.cpp Service/UserService.cpp  Service/encryptionService.cpp Service/SHA256.cpp Views/homePageView.cpp Views/HeaderMenuView.cpp -o /var/www/cgi-bin/homePage `mysql_config --cflags --libs` -lstdc++

sellpage:
	sudo g++ Service/ParserHandler.cpp Service/UserService.cpp Service/Database.cpp Views/addProductView.cpp Views/HeaderMenuView.cpp Service/SessionService.cpp Service/encryptionService.cpp Service/ProductService.cpp Models/productModel.cpp Service/SHA256.cpp -o /var/www/cgi-bin/sellPage `mysql_config --cflags --libs` -lstdc++

loginpage:
	sudo g++ Service/ParserHandler.cpp Service/UserService.cpp Service/Database.cpp Views/loginPageView.cpp  Views/HeaderMenuView.cpp Service/SessionService.cpp Service/encryptionService.cpp Service/SHA256.cpp -o /var/www/cgi-bin/login `mysql_config --cflags --libs` -lstdc++
questions: 
	sudo g++ Service/ParserHandler.cpp Service/ParserHandler.h  Service/Database.cpp  Service/SessionService.cpp Service/UserService.cpp  Service/encryptionService.cpp Service/SHA256.cpp Views/questionsView.cpp Views/HeaderMenuView.cpp -o /var/www/cgi-bin/questions `mysql_config --cflags --libs` -lstdc++

	sudo g++ Service/ParserHandler.cpp Service/ParserHandler.h  Service/Database.cpp  Service/SessionService.cpp Service/UserService.cpp  Service/encryptionService.cpp Service/SHA256.cpp Service/test.cpp -o /var/www/cgi-bin/test `mysql_config --cflags --libs` -lstdc++

postregistration:
	sudo g++ Views/registrationView.cpp Service/ParserHandler.cpp Service/UserService.cpp Views/HeaderMenuView.cpp Service/Database.cpp -o /var/www/cgi-bin/postRegistration `mysql_config --cflags --libs` -lstdc++

registration:
	sudo g++ Views/registerPageView.cpp Service/ParserHandler.cpp Service/UserService.cpp Views/HeaderMenuView.cpp Service/Database.cpp -o /var/www/cgi-bin/registration `mysql_config --cflags --libs` -lstdc++
buypage:
	sudo g++ Service/ParserHandler.cpp Service/Database.cpp Views/productsView.cpp Views/HeaderMenuView.cpp Service/SessionService.cpp Service/encryptionService.cpp Service/ProductService.cpp Models/productModel.cpp Service/SHA256.cpp -o /var/www/cgi-bin/buyPage `mysql_config --cflags --libs` -lstdc++