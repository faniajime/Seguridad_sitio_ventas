#ifndef PRODUCTMODEL_H
#define PRODUCTMODEL_H

#include <string>
using namespace std;

class productModel
{
     public:
        productModel();
	productModel(string,string,string, int, int);
	void setName(string);
        void setDescription(string);
        void setCost(int);
        void setOwner(string);
        string getName();
	string getDescription();
        string getOwner();
	int getCost();
        void listProducts();
        string name, description, owner;
        int id;
        int cost;
    private:
    
    
};
#endif
