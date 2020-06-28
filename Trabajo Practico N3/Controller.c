#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#include <string.h>

#define NAME_LEN 40


int controller_loadFromText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 1;
	FILE* pFile;
	pFile =  fopen(path,"r");
	system("cls");

		 if(pFile != NULL)
		 {
			 parser_EmployeeFromText(pFile,pArrayListEmployee);
			 printf("Archivo encontrado.\n\n");
			 todoOk = 0;

		 }
		 else
		 {
			 printf("Archivo no encontrado\n");
		 }
		 fclose(pFile);




    return todoOk;
}

int controller_loadFromBinary(char* path , LinkedList* pArrayListEmployee)
{

	int todoOk = 1;
	FILE* pFile;

	pFile = fopen(path, "rb");

	if(pFile != NULL)
	{
		if(!parser_EmployeeFromBinary(pFile, pArrayListEmployee))
		{
			todoOk = 0;
			printf("Archivo de texto cargado con exito\n");
		}
		else
		{
			printf("Error\n");
		}
	}
	else
	{
		printf("Error\n");
	}
	fclose(pFile);
    return todoOk;

}

int controller_addEmployee(LinkedList* pArrayListEmployee)
{


	int todoOk = 1;
	Employee* aux  = employee_new();


	system("cls");

	if((utn_getCadena(aux->nombre,20,3,"Ingrese el nombre del empleado: ","Ingrese un nombre valido.\n") == 0))
			{
				if(employee_setNombre(aux, aux->nombre) == 0)
				{
					if(utn_getEntero(&aux->horasTrabajadas, 3, "Ingrese las horas de trabajo del empleado: ", "Ingrese un numero valido.\n",0,9999999) == 0)
					{
						if(employee_setHorasTrabajadas(aux, aux->horasTrabajadas) == 0)
						{
							if(utn_getEntero(&aux->sueldo, 3, "Ingrese el sueldo del empleado: ", "Ingrese un numero valido.\n",1,9999999) == 0)
							{
								if(employee_setSueldo(aux, aux->sueldo) == 0)
								{
									if(utn_getEntero(&aux->id, 3, "Ingrese el id del empleado: ", "Ingrese un numero valido.\n",0,9999999) == 0)
									{
										if(compareId(pArrayListEmployee, aux->id))
										{
											ll_add(pArrayListEmployee, aux);
										}
										else
										{
											printf("Id usado.\n\n");
										}
									}
								}
							}
						}
					}
				}
			}

	 return todoOk;

}

int controller_editEmployee(LinkedList* pArrayListEmployee)
{
        int todoOk = 1;
		int auxId;
		int nuevoId;
		char nuevoNombre[20];
		int nuevasHoras;
		int nuevoSueldo;
		Employee* pEmpleado = employee_new();
		int indice = -1;
		char confirmar;
		char confirmarSwitch;

		system("cls");

			if((utn_getEntero(&auxId, 2, "Ingrese el id del empleado que quiere modificar: ", "Error. Id no encontrado\n", 0, 150000 )) == 0)
			{
				indice = findEmployeeById(pArrayListEmployee, auxId);
				//printf("%d", indice);
				if(indice >= 0)
				{
					printf("Id    Nombre   Horas Trabajadas   Sueldo\n\n");
					printEmployee(pArrayListEmployee, indice);            //muestra al empleado que se va a modificar

					printf("\nConfirma la modificacion del empleado ?'s' para aceptar, 'n' para negar ");
					fflush(stdin);
					scanf("%c", &confirmar);
					if(confirmar == 's')
					{

						do
						{
							switch(menuModificacion())
							{
								case 1:				//modificacion de id
									system("cls");
									pEmpleado = ll_get(pArrayListEmployee,indice);
									printf("Ingrese el nuevo id: ");
									scanf("%d", &nuevoId);
									employee_setId(pEmpleado, nuevoId);
									printf("Id modificado.\n");
									break;

								case 2:              //modificacion de nombre
									system("cls");
									pEmpleado = ll_get(pArrayListEmployee,indice);
									printf("Ingrese el nuevo nombre: ");
									fflush(stdin);
									gets(nuevoNombre);
									employee_setNombre(pEmpleado, nuevoNombre);
									printf("Nombre modificado.\n");

									break;
								case 3:                   //modificacion de horas
										system("cls");
										pEmpleado = ll_get(pArrayListEmployee,indice);
										printf("Ingrese las nuevas horas: ");
										scanf("%d", &nuevasHoras);
										employee_setHorasTrabajadas(pEmpleado, nuevasHoras);
										printf("Horas modificadas.\n");
									break;

								case 4:                                     //modificacion de sueldo
									pEmpleado = ll_get(pArrayListEmployee,indice);
									printf("Ingrese el nuevo sueldo: ");
									scanf("%d", &nuevoSueldo);
									employee_setSueldo(pEmpleado, nuevoSueldo);
									printf("Sueldo modificado.\n");
									break;

								case 5:
									printf("Desea salir? 's' para salir, 'n' para quedarse: ");
									fflush(stdin);
									scanf("%c", &confirmarSwitch);
									break;
                                default:
                                    printf("la opcion ingresada es erronea");
                                    break;

							}
							system("pause");
							system("cls");

						}while(confirmarSwitch != 's');

						employee_delete(pEmpleado);

						todoOk = 0;
					}
					else if(indice == -1)
					{
						printf("\nNo se encontro un empleado con ese id\n\n");
					}
				}
			}

    return todoOk;
}

int controller_removeEmployee(LinkedList* pArrayListEmployee)
{

	int todoOk = 1;
	int auxId;
	int ultId = 1;
	Employee* pEmployee;
	int index;
	char confirm = 'n';

	if(pArrayListEmployee != NULL)
	{
		controller_ListEmployee(pArrayListEmployee);

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmployee = ll_get(pArrayListEmployee, i);

			employee_getId(pEmployee, &auxId);
			if(auxId >= ultId)
			{
				ultId = auxId;
			}
		}
		if(!utn_getEntero(&auxId, 2, "Ingrese ID de empleado a eliminar del sistema.\n", "Error, ID invalido", 0, ultId))
		{
			index = findEmployeeById(pArrayListEmployee, auxId);
			if(index == -1)
			{
			    printf("No hay registro de un empleado con ese ID\n\n");
			}
			else
            {
				printf("\n ID    Nombre   Horas Trabajadas   Sueldo\n\n");
				printEmployee(pArrayListEmployee, index);

				printf("Confirma baja del empleado? s/n: ");
				scanf("%c", &confirm);
				if(confirm == 's')
				{
					ll_remove(pArrayListEmployee, index);
					employee_delete(pEmployee);

					printf("Baja exitosa\n");

					todoOk = 0;
				}
			}
		}
	}
    return todoOk;

}

int controller_ListEmployee(LinkedList* pArrayListEmployee)
{
	int todoOk = 1;
	int tam = ll_len(pArrayListEmployee);
	system("cls");
		if(pArrayListEmployee != NULL)
		{
			printf("Id     Nombre      Horas    Sueldo\n\n");
			for(int i = 0; i < tam; i++)
			{
					printEmployee(pArrayListEmployee, i);
			}
			todoOk = 0;
		}
			else
			{
				printf("No hay empleados para mostrar.\n");
			}
    return todoOk;
}

int sortName(void* firstName, void* secondName)
{
    int change;
    Employee* firstNameEmployee;
    Employee* secondNameEmployee;

    if(firstName != NULL && secondName != NULL)
    {
        firstNameEmployee = (Employee*) firstName;
        secondNameEmployee = (Employee*) secondName;

        change = strcmp(firstNameEmployee->nombre, secondNameEmployee->nombre);
    }

    return change;
}

int controller_sortEmployee(LinkedList* pArrayListEmployee)
{

    int flag = 0;
    int todoOk = 1;

    printf("Espere por favor...\n");
    ll_sort(pArrayListEmployee, sortName, 1);

    todoOk = 0;

    if(todoOk == 0)
    {
        printf("Los empleados fueron ordenados exitosamente\n");
    }
    else
    {
        printf("Error al ordenar los empleados\n");
    }


    printf("***** Listado de Empleados *****\n");
    printf("  Id      Nombre    Apellido     Sueldo    Sector\n\n");

    for(int i=0; i < ll_len(pArrayListEmployee); i++)
    {
        if(pArrayListEmployee != NULL)
        {
            controller_ListEmployee(pArrayListEmployee);
            flag = 1;
            system("pause");
        }
    }
    if(flag == 0)
    {
        printf("*** No hay empleados que listar ***\n");
    }

    return todoOk;
}

int controller_saveAsText(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 1;
	FILE* pFile;
	int auxId;
	char auxName[NAME_LEN];
	int auxHTrab;
	int auxSalario;
	Employee* pEmployee;

	if(pArrayListEmployee != NULL && path != NULL)
	{
		pFile = fopen(path, "w");
		if(pFile != NULL)
		{
			todoOk = 0;
			for(int i = 0; i < ll_len(pArrayListEmployee); i++)
			{
				pEmployee = ll_get(pArrayListEmployee, i);

				employee_getId(pEmployee, &auxId);
                employee_getNombre(pEmployee, auxName);
                employee_getHorasTrabajadas(pEmployee, &auxHTrab);
                employee_getSueldo(pEmployee, &auxSalario);

                fprintf(pFile, "%d,%s,%d,%d\n", auxId, auxName, auxHTrab, auxSalario);
			}

			fclose(pFile);

			printf("Archivo guardado correctamente\n");
		}
		else if(todoOk == 1)
        {
            printf("Error\n");
        }
	}

    return todoOk;



}

int controller_saveAsBinary(char* path , LinkedList* pArrayListEmployee)
{
	int todoOk = 1;
	FILE* pFile;
	Employee* pEmployee;

		pFile = fopen(path, "wb");

		for(int i = 0; i < ll_len(pArrayListEmployee); i++)
		{
			pEmployee = (Employee*) ll_get(pArrayListEmployee, i);
			if(pEmployee != NULL)
            {
                fwrite(pEmployee, sizeof(Employee), 1, pFile);
                todoOk = 0;
            }
		}

		if(todoOk == 0)
        {
            printf("Archivo guardado correctamente\n");
        }
        else
        {
            printf("No se ah podido guardar el archivo");
        }

		fclose(pFile);

    return todoOk;
}

//creo la funcion menu
int menuModificacion()
{
	int option;
	system("cls");

	printf("****Menu de modificacion****\n\n");

	printf("1. Modificar Id\n");
	printf("2. Modificar nombre.\n");
	printf("3. Modificar horas trabajadas.\n");
	printf("4. Modificar sueldo.\n");
	printf("5. Salir.\n");


	printf("Ingrese una opcion: ");
	scanf("%d", &option);

	return option;


}
