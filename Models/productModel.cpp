#include <iostream>
#include "productModel.h"


/*Constructor*/

productModel::productModel(){
	this->name = "Hola";
	this->description = "description";
	this->owner = "owner";
	this->cost = 100;
}

productModel::productModel(string name, string description, string owner, int cost){
	this->name = name;
	this->description = description;
	this->owner = owner;
	this->cost = cost;

}

/*Setters*/
void productModel::setName ( string name){
	this->name = name;
}

void productModel::setDescription( string description){
	this->description = description;
}

void productModel::setOwner( string owner){
	this->owner = owner;
}

void productModel::setCost( int cost){
	this->cost = cost;
}

/*Getters*/

string productModel::getName(){
	return this->name;
}

string productModel::getDescription(){
	return this->description;
}


string productModel::getOwner(){
	return this->owner;
}

int productModel::getCost(){
	return this->cost;
}
