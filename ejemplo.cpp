#include <iostream>
#include <string>
using namespace std;

struct EMP{
    int num;
    string nom;
    float ven[12];
    float salario;
};

int main (){
    EMP EMPLEADOS[100];
    int n, vtot=0,mayorvent=0,mayor=0;
    float totalVentas[100];
    cout<<"Ingresa el numero de empleados: ";
    cin>>n;
    for (int i=0; i<n; i++){
        cout<<"Ingresa el numero del empleado: ";
        cin>>EMPLEADOS[i].num;
        cout<<"Ingresa el nombre del empleado: ";
        cin.ignore();
        getline(cin,EMPLEADOS[i].nom);
        cout<<"Ingresa el numero de ventas del empleado:"<<endl;
        for (int j=0; j<12; j++){
            cout<<"Mes "<<j+1<<": ";
            cin>>EMPLEADOS[i].ven[j];
            totalVentas[i]=EMPLEADOS[i].ven[j]+totalVentas[i];
        }
            cout<<"Ingresa el salario del empleado: ";
            cin>>EMPLEADOS[i].salario;
    }
    for (int i=0; i<n; i++){
        if (totalVentas[i]>mayorvent){
            mayorvent=totalVentas[i];
            mayor=i;
        }
    }
        cout<<"Empleado Numero: "<<EMPLEADOS[mayor].num<<endl;
        cout<<"Nombre: "<<EMPLEADOS[mayor].nom<<endl;
        cout<<"Ventas: ";
        for (int j=0; j<12; j++){
            cout<<EMPLEADOS[mayor].ven[j]<<" ";
        }
        cout<<endl;
        cout<<"Salario: "<<EMPLEADOS[mayor].salario<<endl;
        
    return 0;
}