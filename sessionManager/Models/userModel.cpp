#include <iostream>
#include "userModel.h"

using namespace std;

/*Constructor*/
userModel::userModel(string nombre, string user, string contrasena, string email, int telefono, string direccion){
    this->nombre = nombre;
    this->user = user;
    this->contrasena = contrasena;
    this->email = email;
    this->direccion = direccion;
    this->telefono = telefono;
}
userModel::userModel(){
    this->nombre = "";
    this->user = "";
    this->contrasena = "";
    this->email = "";
    this->direccion = "";
    this->telefono = '0';
}

/*Setters*/
void userModel:: setNombre(string nombre){
    this->nombre = nombre;
}

void userModel:: setuserModel(string user){
    this->user = user;
}

void userModel:: setContrasena(string contrasena){
    this->contrasena = contrasena;
}

void userModel:: setEmail(string email){
    this->email = email;
}

void userModel:: setDireccion(string direccion){
    this->direccion = direccion;
}

void userModel:: setTelefono(int telefono){
    this->telefono = telefono;
}

/*Getters*/
string userModel::getNombre(){
    return this->nombre;
}

string userModel::getuserModel(){
    return this->user;
}

string userModel::getContrasena(){
    return this->contrasena;
}

string userModel::getEmail(){
    return this->email;
}

string userModel::getDireccion(){
    return this->direccion;
}

int userModel::getTelefono(){
    return this->telefono;
}