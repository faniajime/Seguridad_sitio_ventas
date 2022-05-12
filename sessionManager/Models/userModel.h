#ifndef userModel_H
#define userModel_H

#include <string>
using namespace std;

class userModel
{
    public:
    userModel ();
    userModel (string nombre, string user, string contrasena, string email, int telefono, string direccion);
    ~userModel();
    userModel(string,string,string,string,string,int);
    void setNombre(string nombre); 
    void setuserModel(string user);//primarykey
    void setContrasena(string contrasena);
    void setEmail(string email);
    void setTelefono(int telefono);
    void setDireccion(string direccion);
    string getNombre();
    string getuserModel();
    string getContrasena();
    string getEmail();
    int getTelefono();
    string getDireccion();
    void ingresarConID(string id);
    void agregarArticuloVenta(/*Producto */);
    void agregarArticuloCarrito(/*Producto*/);
    void realizarCompra();
    void salirDelSistema();

    private:
    string nombre, user, contrasena, email,direccion;
    int telefono;

};
#endif