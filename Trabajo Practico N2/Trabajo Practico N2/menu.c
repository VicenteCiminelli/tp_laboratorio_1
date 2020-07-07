#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

#include "ArrayEmployees.h"
#include "menu.h"

void menu()
{
    printf("\n-*-*-*-*-*-*-*-*-Menu Empleados-*-*-*-*-*-*-*-*-");
    printf("\n\n1- Alta Empleado");
    printf("\n2- Baja Empleado");
    printf("\n3- Modificar Empleado");
    printf("\n4- Listar Empleados");
    printf("\n5- Salir");
    printf("\nIngrese Respuesta: ");

}

int menuModificarEmployee()
{
    system("cls");
    int opcion;

    printf("\n\nQue desea modificar?:");
    printf("\n1. Nombre");
    printf("\n2.Apellido");
    printf("\n3.Salario");
    printf("\n4.Sector");
    printf("\n5.No quiero modificar nada");
    printf("\nIngrese la opcion: ");
    scanf("%d", &opcion);

    return opcion;
}

int validar_nombre(char cadena[])
{
    int cadenaValida = 0;
    int cantidadCaracteres;
    cantidadCaracteres=strlen(cadena);

    if(cantidadCaracteres != 0)
    {
        for(int i=0;i< cantidadCaracteres; i++)
        {
            if(isalpha(cadena[i])!=0)
            {
                cadenaValida = 1;
                break;
            }
        }
    }
    else
    {
        cadenaValida = 0;
    }


    return cadenaValida;
}
