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
    int n, mayorvent=0, mayor;
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
        totalVentas[i] = 0;
        for (int j=0; j<12; j++){
            cout<<"Mes "<<j+1<<": ";
            cin>>EMPLEADOS[i].ven[j];
            totalVentas[i]=EMPLEADOS[i].ven[j]+totalVentas[i];
        }
            cout<<"Ingresa el salario del empleado: ";
            cin>>EMPLEADOS[i].salario;
            if (totalVentas[i]>100){
                EMPLEADOS[i].salario=EMPLEADOS[i].salario*1.1;
            }
    }
    cout<<"Empleados que tuvieron ventas menores a 30 en el mes de diciembre: "<<endl;
    for (int i=0; i<n; i++){   
        if (EMPLEADOS[i].ven[11]<30){
        cout<<"Empleado Numero: "<<EMPLEADOS[i].num<<endl;
        cout<<"Nombre: "<<EMPLEADOS[i].nom<<endl;
        cout<<"Ventas: ";
        for (int j=0; j<12; j++){
            cout<<EMPLEADOS[i].ven[j]<<" ";
        }
        cout<<endl;
        cout<<"Salario: "<<EMPLEADOS[i].salario<<endl;  
        }   
    }
    for (int i=0; i<n; i++){
        if (totalVentas[i]>mayorvent){
            mayorvent=totalVentas[i];
            mayor=i;
        }
    }
    cout<<"El empleado con mayores ventas es: "<<EMPLEADOS[mayor].nom<<endl;
    cout<<"Ventas: ";
        for (int j=0; j<12; j++){
            cout<<EMPLEADOS[mayor].ven[j]<<" ";
        }
    cout<<"Ventas totales: "<<totalVentas[mayor];
    return 0;
}
