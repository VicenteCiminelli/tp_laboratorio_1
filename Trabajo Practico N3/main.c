#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Employee.h"

/****************************************************
    Menu:
     1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).
     2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).
     3. Alta de empleado
     4. Modificar datos de empleado
     5. Baja de empleado
     6. Listar empleados
     7. Ordenar empleados
     8. Guardar los datos de los empleados en el archivo data.csv (modo texto).
     9. Guardar los datos de los empleados en el archivo data.csv (modo binario).
    10. Salir
*****************************************************/

//Llamo a la funcion Menu
int menu();

int main()
{

	setbuf(stdout, NULL);

    char confirm;
	int flagTexto = 0;      //bandera para el archivo de tetxo
	int flagBinario = 0;	  //bandera para el archivo binario

    LinkedList* listaEmpleados = ll_newLinkedList();
    do{
        system("cls");
        switch(menu())
        {
            case 1:
            	if(flagTexto == 0 && flagBinario != 1)  //para que entre solo si no se cargo el otro achivo
            	{
					if(controller_loadFromText("data.csv",listaEmpleados) == 0)
					{
						flagTexto = 1;     //se cargo como texto
					}
            	}
            	else
            	{
            		printf("Ya fue Cargado el archivo anteriormente.\n");
            	}
                break;

            case 2:
            	if(flagTexto != 1 && flagBinario == 0) //para que entre solo si no se cargo el otro achivo
                  {

            		if(controller_loadFromBinary("data.bin",listaEmpleados) == 0)
            			{
            				flagBinario = 1;	//se cargo el archivo como binario
            			}

                   }
                   else
                    {
                        printf("Ya cargo un archivo anteriormente.\n");
                    }
                    break;

                case 3:
                if(flagTexto == 1 || flagBinario == 1)
                {
                    controller_addEmployee(listaEmpleados);
                }
                else
                {
                    printf("Primero debe cargar un archivo");
                }
            	break;

            case 4:

                if(flagTexto == 1 || flagBinario == 1)
				{
					controller_editEmployee(listaEmpleados);
				}
				else
				{
					printf("Primero debe cargar un archivo.\n");
				}
            	break;

            case 5:
                if(flagTexto == 1 || flagBinario == 1)
				{
            		controller_removeEmployee(listaEmpleados);
				}
				else
				{
					printf("Primero debe cargar un archivo.\n");
				}

            	break;

            case 6:
                if(flagTexto == 1 || flagBinario == 1)
				{
            		controller_ListEmployee(listaEmpleados);
				}
				else
				{
					printf("Primero debe cargar un archivo.\n");
				}
            	break;

            case 7:

            	  if(flagTexto == 1 || flagBinario == 1)
				{
					controller_sortEmployee(listaEmpleados);
				}
				else
				{
					printf("Primero debe cargar un archivo.\n");
				}
            	break;

            case 8:

                if(flagTexto == 1 || flagBinario == 1)
            	{
            		controller_saveAsText("data.csv", listaEmpleados);
            	}
            	else
				{
					printf("Primero debe cargar un archivo.\n");
				}

            	break;

            case 9:

                if(flagTexto == 1 || flagBinario == 1)
            	{
            		controller_saveAsBinary("data.bin", listaEmpleados);
            	}
            	else
				{
					printf("Primero debe cargar un archivo.\n");
				}

            case 10:
            		printf("Quiere Salir? 's'/'n': ");
            		fflush(stdin);
            		scanf("%c", &confirm);

            	break;

            default:
                printf("La opcion ingresada es Invalida");
                break;

        }


        system("pause");
        system("cls");

    }while(confirm != 's');
    ll_deleteLinkedList(listaEmpleados);


    return 0;

}

// Creo la Funcion Menu
int menu()
{
    int option;

    system("cls");
    printf("***** Sistema de Empleados ******\n\n");
    printf("1. Cargar los datos de los empleados desde el archivo data.csv (modo texto).\n");
    printf("2. Cargar los datos de los empleados desde el archivo data.csv (modo binario).\n");
    printf("3. Alta de empleado\n");
    printf("4. Modificar datos de empleado\n");
    printf("5. Baja de empleado\n");
    printf("6. Listar empleados\n");
    printf("7. Ordenar empleados por nombre\n");
    printf("8. Guardar los datos de los empleados en el archivo data.csv (modo texto).\n");
    printf("9. Guardar los datos de los empleados en el archivo data.csv (modo binario).\n");
    printf("10. Salir\n");
    printf("\nElija una opcion: ");
    fflush(stdin);
    scanf("%d", &option);

    return option;
}
