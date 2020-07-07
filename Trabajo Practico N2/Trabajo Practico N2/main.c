#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "menu.h"

#include <windows.h> ///BORRAR
#include <dos.h> ///BORRAR

#define tamE 1000



int main()
{
    eEmployee lE[tamE];

    initEmployees(lE, tamE);

    int id = 1;
    char name[51];
    char lastName[51];
    float salary = 0;
    int sector = 0;
    int opcion;
    int case1 = 0;

    int idABuscar=0;

    do
    {
        system("cls");
        menu();
        scanf("%d", &opcion);


        switch(opcion)
        {
            case 1:

                Beep(750, 300);///BORRAR
                altaEmpleado(lE,tamE,id,name,lastName,salary,sector);
                id++;
                case1= 1;
                break;

            case 2:
                if(case1 == 1)
                {
                    system("cls");
                    printf("Ingrese la id de el empleado que desea dar de baja: ");
                    scanf("%d",&id);
                    removeEmployee(lE, tamE, id);
                    break;
                }
                else
                {
                    system("cls");
                    printf("todavia no se ha ingresado ningun empleado\n");
                    system("pause");
                    break;
                }



            case 3:
                if(case1 == 1)
                {
                    system("cls");
                    printf("Ingrese la id de el empleado que desea modificar: ");
                    scanf("%d",&idABuscar);
                    modificarEmployee(lE, idABuscar, salary, sector, name, lastName, tamE);
                    system("pause");
                    break;
                }
                else
                {
                    system("cls");
                    printf("/*/*/*/*/*/*/todavia no se ha ingresado ningun empleado/*/*/*/*/*/*/*/*/*/*/*\n");
                    system("pause");
                    break;
                }



            case 4:
                if(case1 == 1)
                {
                    system("cls");
                    informarEmpleados(lE, tamE, id);
                    //printEmployees(lE, tamE, name, salary, sector, id);
                    system("pause");
                    fflush(stdin);
                    break;
                }
                else
                {
                    system("cls");
                    printf("todavia no se ha ingresado ningun empleado\n");
                    system("pause");
                    break;
                }



            case 5:
                system("cls");
                printf("\n\n\n**********Hasta Pronto**********\n\n\n\n\n\n\n\n");
                break;


            default:
                system("cls");
                printf("Opcion inValida ingresada\n");
                fflush(stdin);
                system("pause");
                break;

        }
    }while(opcion != 5);

}

