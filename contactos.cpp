#include <iostream>
using namespace std;

struct correo{
    string user;
    string domain;
};

struct contactoEmail{
    string nom;
    char sex;
    int edad;
    correo email;
};

void leerCorreo(correo &, string, string);
void leerContacto(contactoEmail &, string, char, int, correo);
void imprimeContacto(contactoEmail &);

int main(){
    int n, op,op2,num;
    string nom, user, domain, serv;
    char sex, op1;
    int edad;
    correo email;
    contactoEmail cont, lista[100];
    n = 0;
    do{
        system("cls");
        cout<<"Menu de opciones -------------------------"<<endl;
        cout<<"1. Agregar contacto"<<endl;
        cout<<"2. Modificar contactos"<<endl;
        cout<<"3. Mostrar contactos"<<endl;
        cout<<"4. Mostrar listado de contactos correspondientes a un servidor ingresado"<<endl;
        cout<<"5. Eliminar contacto"<<endl;
        cout<<"6. Buscar un contacto por email"<<endl;
        cout<<"0. Salir"<<endl;
        cout<<"Elige una opcion: "; cin>>op;
        switch(op){
            case 0:
                cout<<"Seguro que quiere salir (S/N): ";
                break;
            case 1:
                cout<<"Ingrese los datos de un usuario: "<<endl;
                cin.ignore();
                cout<<"Ingrese el nombre del contacto: "; getline(cin,nom);
                cout<<"Ingrese el sexo (M/F): "; cin>>sex;
                cout<<"Ingrese la edad: "; cin>>edad;
                cout<<"Ingrese el correo electronico (usuario@dominio): "<<endl;
                cout<<"\tIngrese el usuario: "; cin>>user;
                cout<<"\tIngrese el dominio: "; cin>>domain;
                leerCorreo(email,user,domain);
                leerContacto(cont,nom,sex,edad,email);
                lista[n] = cont;
                n++;
                system("pause");
                break;
            case 2:
                cout<<"Numero de contacto que quieres modificar (0,1,2,3,...): "<<endl;
                cin>>num;
                for (int a=0; a<=n; a++){
                    if (a==num){
                        cout<<"Menu de opciones (seleccione lo que desea modificar) --------------------------------------"<<endl;
                        cout<<"1. Nombre del contacto: "<<endl;
                        cout<<"2. El sexo del contacto (M/F): "<<endl; 
                        cout<<"3. La edad del contacto: "<<endl; 
                        cout<<"4. El correo electronico (usuario@dominio): "<<endl;
                        cout<<"\tusuario: "<<endl; 
                        cout<<"\tdominio: "<<endl; 
                        cin>>op2;
                        switch (op2){
                        case 1: 
                            cin.ignore();
                            cout<<"Ingrese el nombre del contacto: "; getline(cin,nom);
                        break;
                        case 2:
                            cout<<"Ingrese el sexo (M/F): "; cin>>sex;
                        break;
                        case 3:
                            cout<<"Ingrese la edad: "; cin>>edad;
                        break;
                        case 4:
                            cout<<"Ingrese el correo electronico (usuario@dominio): "<<endl;
                            cout<<"\tIngrese el usuario: "; cin>>user;
                            cout<<"\tIngrese el dominio: "; cin>>domain;
                        break;
                        default:
                            cout<<"opcion invalida!"<<endl;
                            break;
                        }
                    }
                }
                break;
            case 3:
                for(int i = 0; i < n; i++){
                    cout<<"Contacto #"<<i<<endl;
                    imprimeContacto(lista[i]);
                    cout<<endl;
                }
                system ("pause");
                break;
            case 4:
                cout<<"Ingrese el servidor: ";
                cin>>serv;
                for (int i=0; i<n ; i++){
                    if (serv==lista[i].email.domain){
                        imprimeContacto(lista[i]);
                    }
                }
                system("pause");
                break;
            case 5:
                
                break;
            case 6:
                cout<<"Ingrese su correo electronico"<<endl;
                cout<<"Ingrese el usuario: ";
                cin>>user;
                cout<<"Ingrese el dominio: ";
                cin>>domain;
                for (int i=0; i<n ; i++){
                    if (user==lista[i].email.user && domain==lista[i].email.domain){
                        imprimeContacto(lista[i]);
                    }
                }
                system("pause");
                
                break;
            default:
                cout<<"Opcion no valida!"<<endl;
                system("pause");
                break;
        }
    } while(op != 0);
    return 0;
}

void leerContacto(contactoEmail &c, string n, char s, int e, correo em){
    c.nom = n;
    c.sex = s;
    c.edad = e;
    c.email = em;
}

void leerCorreo(correo &c, string u, string d){
    c.user = u;
    c.domain = d;
}

void imprimeContacto(contactoEmail &c){
    cout<<"Nombre: "<<c.nom<<endl;
    cout<<"Sexo: "<<c.sex<<endl;
    cout<<"Edad: "<<c.edad<<endl;
    cout<<"Email: "<<c.email.user<<"@"<<c.email.domain<<endl;
}
