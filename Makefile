all:
	sudo g++ Service/ParserHandler.cpp Service/CartService.cpp Models/productModel.cpp Service/Database.cpp  Service/SessionService.cpp Service/UserService.cpp  Service/encryptionService.cpp Service/SHA256.cpp Views/homePageView.cpp Views/HeaderMenuView.cpp -o /var/www/cgi-bin/homePage `mysql_config --cflags --libs` -lstdc++ -std=c++1y
	sudo g++ Service/ParserHandler.cpp Service/UserService.cpp Service/Database.cpp Views/addProductView.cpp Views/HeaderMenuView.cpp Service/SessionService.cpp Service/encryptionService.cpp Service/ProductService.cpp Models/productModel.cpp Service/SHA256.cpp  Service/CartService.cpp -o /var/www/cgi-bin/sellPage `mysql_config --cflags --libs` -lstdc++ -std=c++1y
	sudo g++ Service/ParserHandler.cpp Service/UserService.cpp Service/Database.cpp Views/loginPageView.cpp  Views/HeaderMenuView.cpp Service/SessionService.cpp Service/encryptionService.cpp Models/productModel.cpp Service/SHA256.cpp Service/CartService.cpp -o /var/www/cgi-bin/login `mysql_config --cflags --libs` -lstdc++ -std=c++1y
	sudo g++ Service/ParserHandler.cpp Models/questionModel.cpp Service/ParserHandler.h  Service/Database.cpp  Service/SessionService.cpp Service/UserService.cpp Service/QuestionsService.cpp Service/encryptionService.cpp Models/productModel.cpp Service/SHA256.cpp Views/questionsView.cpp Service/CartService.cpp Views/HeaderMenuView.cpp -o /var/www/cgi-bin/QA `mysql_config --cflags --libs` -lstdc++ -std=c++1y
	sudo g++ Views/registrationView.cpp Service/SHA256.cpp Service/ParserHandler.cpp Service/encryptionService.cpp Service/UserService.cpp Views/HeaderMenuView.cpp Service/Database.cpp Service/CartService.cpp Models/productModel.cpp Service/SessionService.cpp -o /var/www/cgi-bin/postRegistration `mysql_config --cflags --libs` -lstdc++ -std=c++1y
	sudo g++ Views/registerPageView.cpp Service/SHA256.cpp Service/encryptionService.cpp Service/ParserHandler.cpp Service/UserService.cpp Views/HeaderMenuView.cpp Service/Database.cpp Service/CartService.cpp Models/productModel.cpp Service/SessionService.cpp -o /var/www/cgi-bin/registration `mysql_config --cflags --libs` -lstdc++ -std=c++1y
	sudo g++ Service/ParserHandler.cpp Service/Database.cpp Views/productsView.cpp Views/HeaderMenuView.cpp Service/encryptionService.cpp Service/SHA256.cpp Service/SessionService.cpp Service/ProductService.cpp Models/productModel.cpp Service/CartService.cpp -o /var/www/cgi-bin/buyPage `mysql_config --cflags --libs` -lstdc++ -std=c++1y
	sudo g++ Service/ParserHandler.cpp Service/Database.cpp Views/paymentView.cpp Views/HeaderMenuView.cpp Service/encryptionService.cpp Service/SHA256.cpp Service/SessionService.cpp Service/ProductService.cpp Models/productModel.cpp Service/CartService.cpp -o /var/www/cgi-bin/payPage `mysql_config --cflags --libs` -lstdc++ -std=c++1y

homepage: 
	sudo g++ Service/ParserHandler.cpp Service/Database.cpp  Service/SessionService.cpp Service/UserService.cpp  Service/encryptionService.cpp Service/SHA256.cpp Views/homePageView.cpp Views/HeaderMenuView.cpp Service/CartService.cpp -o /var/www/cgi-bin/homePage `mysql_config --cflags --libs` -lstdc++

sellpage:
	sudo g++ Service/CartService.cpp Service/ParserHandler.cpp Service/UserService.cpp Service/Database.cpp Views/addProductView.cpp Views/HeaderMenuView.cpp Service/SessionService.cpp Service/encryptionService.cpp Service/ProductService.cpp Models/productModel.cpp Service/SHA256.cpp -o /var/www/cgi-bin/sellPage `mysql_config --cflags --libs` -lstdc++

loginpage:
	sudo g++ Service/ParserHandler.cpp Service/UserService.cpp  Service/CartService.cpp Service/Database.cpp Views/loginPageView.cpp  Views/HeaderMenuView.cpp Service/SessionService.cpp Service/encryptionService.cpp Service/SHA256.cpp -o /var/www/cgi-bin/login `mysql_config --cflags --libs` -lstdc++
questions: 
	sudo g++ Service/ParserHandler.cpp Service/CartService.cpp Service/Database.cpp Models/questionModel.cpp Views/HeaderMenuView.cpp Service/QuestionsService.cpp Service/SessionService.cpp Service/UserService.cpp Service/encryptionService.cpp Service/SHA256.cpp Views/questionsView.cpp -o /var/www/cgi-bin/questions `mysql_config --cflags --libs` -lstdc++


postregistration:
	sudo g++ Views/registrationView.cpp Service/SHA256.cpp Service/CartService.cpp Service/ParserHandler.cpp Service/encryptionService.cpp Service/UserService.cpp Views/HeaderMenuView.cpp Service/Database.cpp -o /var/www/cgi-bin/postRegistration `mysql_config --cflags --libs` -lstdc++

registration:
	sudo g++ Views/registerPageView.cpp Service/CartService.cpp Service/SHA256.cpp Service/encryptionService.cpp Service/ParserHandler.cpp Service/UserService.cpp Views/HeaderMenuView.cpp Service/Database.cpp -o /var/www/cgi-bin/registration `mysql_config --cflags --libs` -lstdc++
	
buypage:
	sudo g++ Service/ParserHandler.cpp Service/Database.cpp Views/productsView.cpp Views/HeaderMenuView.cpp Service/encryptionService.cpp Service/SHA256.cpp Service/SessionService.cpp Service/ProductService.cpp Models/productModel.cpp Service/CartService.cpp -o /var/www/cgi-bin/buyPage `mysql_config --cflags --libs` -lstdc++
payPage:
	sudo g++ Service/ParserHandler.cpp Service/Database.cpp Views/paymentView.cpp Views/HeaderMenuView.cpp Service/encryptionService.cpp Service/SHA256.cpp Service/SessionService.cpp Service/ProductService.cpp Models/productModel.cpp Service/CartService.cpp -o /var/www/cgi-bin/payPage `mysql_config --cflags --libs` -lstdc++
