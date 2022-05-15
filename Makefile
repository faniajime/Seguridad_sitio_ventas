all: Service/test.cpp Models/productModel.cpp Service/productService.cpp
	gcc -o test Service/test.cpp Models/productModel.cpp Service/productService.cpp `mysql_config --cflags --libs` -lstdc++