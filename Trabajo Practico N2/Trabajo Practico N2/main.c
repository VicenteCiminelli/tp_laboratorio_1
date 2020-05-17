#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"

#include <windows.h> ///BORRAR
#include <dos.h> ///BORRAR

#define tamE 10

eEmployee lE[50];

int main()
{

    int id = 1;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int opcion;

    int idABuscar=0;


    do
    {

        system("cls");
        menu();
        scanf("%d", &opcion);


        switch(opcion)
        {
            case 1:

                system("cls");
                printf("\n\n*****Alta Empleados*****\n");

                printf("\nIngrese Nombre: ");
                fflush(stdin);
                gets(name);
                system("cls");

                printf("\nIngrese Apellido: ");
                fflush(stdin);
                gets(lastName);
                system("cls");

                printf("\nIngrese salario: ");
                scanf("%f", &salary);
                system("cls");

                printf("\nIngrese sector: ");
                scanf("%d", &sector);
                system("cls");
                Beep(750, 300);///BORRAR
                altaEmpleado(lE,tamE,id,name,lastName,salary,sector);
                id++;
                break;

            case 2:

                system("cls");
                printf("Ingrese la id de el empleado que desea dar de baja: ");
                scanf("%d",&id);
                removeEmployee(lE, tamE, id);
                break;

            case 3:
                system("cls");
                printf("Ingrese la id de el empleado que desea modificar: ");
                scanf("%d",&idABuscar);
                modificarEmployee(lE,idABuscar,salary,sector,name,lastName,tamE);
                system("pause");
                break;

            case 4:
                system("cls");
                printEmployees(lE, tamE, sector, salary, sector, id);
                system("pause");
                break;

            case 5:
                system("cls");
                printf("\n\n\n**********Hasta Pronto**********\n\n\n\n\n\n\n\n");
                break;

        }
    }while(opcion != 5);

}
