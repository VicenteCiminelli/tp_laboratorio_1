#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Employee.h"
#include "parser.h"
#include "utn.h"
#include "Controller.h"
#include <string.h>

int parser_EmployeeFromText(FILE* pFile , LinkedList* pArrayListEmployee)
{
    int todoOk = 1;
	Employee* pEmployee;
	char id[200];
	char nombre[200];
	char horasTrabajadas[200];
	char sueldo[200];

	if(pFile != NULL && pArrayListEmployee != NULL)
	{
	    fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo);
		do
		{
			if(fscanf(pFile, "%[^,],%[^,],%[^,],%[^\n]\n", id, nombre, horasTrabajadas, sueldo) == 4)
			{
				pEmployee = employee_newParametros(id, nombre, horasTrabajadas, sueldo);

				if(pEmployee != NULL)
				{
					ll_add(pArrayListEmployee, pEmployee);
					todoOk = 0;
				}
			}
			else
			{
				break;
			}

		}while(feof(pFile) == 0);
	}

    return todoOk;
}

int parser_EmployeeFromBinary(FILE* pFile , LinkedList* pArrayListEmployee)
{

	int todoOk = 1;
	Employee* pEmployee;

	if(pFile != NULL)
	{
		do
		{
			pEmployee = employee_new();
			if(fread(pEmployee, sizeof(Employee), 1, pFile) == 1)
			{
				ll_add(pArrayListEmployee, pEmployee);
				printf("Añadido correctamente\n");
				todoOk = 0;
			}
		}while(!feof(pFile));
	}

    return todoOk;
}
