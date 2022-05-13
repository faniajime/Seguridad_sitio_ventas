#ifndef PRODUCTMODEL_H
#define PRODUCTMODEL_H

#include <string>
using namespace std;

class productModel
{
     public:

	productModel(string,string,string, int);
	void setName(string);
        void setDescription(string);
        void setCost(int);
        void setOwner(string);
        string getName();
	string getDescription();
        string getOwner();
	int getCost();
        void listProducts();
        
    private:
    string name, description, owner;
    int cost;
};
#endif