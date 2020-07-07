#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayEmployees.h"
#include "menu.h"

int altaEmpleado(eEmployee* lE, int tamE, int id, char name[],char lastName[],float salary,int sector)///FUNCIONA
{

    int todoOk = 0;
    eEmployee auxEmployee;

                printf("\n\n*****Alta Empleados*****\n");
                printf("\nIngrese Nombre: ");
                fflush(stdin);
                gets(name);
                system("cls");

                while(validar_nombre(name) == 0)
                {

                    printf("*/*/*/*/*/*/*/los nombres y apellidos no pueden llevar numeros/*/*/*/*/*/*/*/*\n");
                    printf("\nIngrese Nombre: ");
                    fflush(stdin);
                    gets(name);
                    system("cls");
                    validar_nombre(name);

                }


                system("cls");
                printf("\nIngrese Apellido: ");
                fflush(stdin);
                gets(lastName);
                system("cls");

                while(validar_nombre(lastName) == 0)
                {
                    printf("*/*/*/*/*/*/*/los nombres y apellidos no pueden llevar numeros/*/*/*/*/*/*/*/*\n");
                    printf("\nIngrese Apellido:");
                    fflush(stdin);
                    gets(lastName);
                    system("cls");
                    validar_nombre(lastName);
                }

                printf("\nIngrese salario: ");
                scanf("%f", &salary);
                if(salary < 0)
                {
                    printf("salario no puede ser Inferior a cero");
                    printf("\nIngrese salario Valido: ");
                    scanf("%f", &salary);

                }
                system("cls");

                printf("\nIngrese sector: ");
                scanf("%d", &sector);
                if(sector < 0)
                {
                    printf("salario no puede ser Inferior a cero");
                    printf("\nIngrese salario Valido: ");
                    scanf("%d", &sector);

                }
                system("cls");

            for(int i = 0; i < tamE; i++)
            {

                if(lE[i].isEmpty==1)
                {
                    auxEmployee.id = id;
                    strcpy(auxEmployee.name, name);
                    strcpy(auxEmployee.lastName, lastName);
                    auxEmployee.salary = salary;
                    auxEmployee.sector = sector;
                    auxEmployee.isEmpty = 0;
                    lE[i] = auxEmployee;
                    todoOk = 1;
                    break;

                }
            }
    return todoOk;
}

void modificarEmployee(eEmployee* lE, int id, int salary, int sector, char name[], char lastName[], int tamE)
{
    char auxName[50];
    char auxLastName[50];
    float auxSalary;
    int auxSector;
    char opcionSalir;
    eEmployee auxEmployee;
    int encontrado = 0;

    printf("**** Modificacion de empleado****\n\n");
    for(int i = 0; i < tamE; i++)
    {
        if(lE[i].id == id)
        {
            auxEmployee = lE[i];
            do
            {
                fflush(stdin);
                switch(menuModificarEmployee())
                {
                case 1:
                    printf("Ingrese el nuevo nombre: ");
                    scanf("%s", auxName);
                    strcpy(auxEmployee.name, auxName);
                    break;
                case 2:
                    printf("Ingrese el nuevo apellido: ");
                    scanf("%s", auxLastName);
                    strcpy(auxEmployee.lastName, auxLastName);
                    break;
                case 3:
                    printf("Ingrese el nuevo Salario: ");
                    scanf("%f", &auxSalary);
                    auxEmployee.salary = auxSalary;
                    break;
                case 4:
                    printf("Ingrese el nuevo Sector: ");
                    scanf("%d", &auxSector);
                    auxEmployee.sector = auxSector;
                    break;
                case 5:
                    printf("Quiere salir? 's' para salir 'n' para quedarse: ");
                    fflush(stdin);
                    scanf("%c", &opcionSalir);
                    break;
                }

            }
            while(opcionSalir != 's');
            lE[i] = auxEmployee;
            encontrado = 1;
            break;
        }
    }
    if(encontrado == 0)
    {
        printf("No se encontro el id buscado");
    }
}

int initEmployees(eEmployee* lE, int tamE)
{
	int inEm = -1;
	if(lE != NULL)
	{
		for(int i = 0; i < tamE; i++)
		{
			lE[i].isEmpty = 1;
			inEm = 0;
		}
	}
	return inEm;
}

int buscarEspacio(eEmployee* list, int len)
{
	int indice = -1;
		for(int i = 0; i < len; i++)
		{
			if(list[i].isEmpty)
			{
				indice = i;
				break;
			}
		}
	return indice;
}

int findEmployeeById(eEmployee* lE, int tamE, int id)
{
	int indice = -1;
	for(int i = 0; i < tamE; i++)
	{
		if( lE[i].id == id )
		{
			indice = i;
			break;
		}
	}
	return indice;
}

int removeEmployee(eEmployee* lE, int tamE, int id)
{
	int isOk = -1;
	eEmployee emptyEmp;
	emptyEmp.id = 0;
	emptyEmp.isEmpty = 1;
	emptyEmp.lastName[0] = '\0';
	emptyEmp.name[0] = '\0';
	emptyEmp.salary = 0;
	emptyEmp.sector = 0;

	int indice = findEmployeeById(lE,tamE,id);

				if(indice == -1 && lE == NULL)
				{
					printf("\nID incorrecto\n\n");
				}
				else
				{
				    lE[indice] = emptyEmp;
                    printf("Empleado removido con exito.\n\n");
					isOk = 0;
				}

	return isOk;
}

int sortEmployees(eEmployee* lE, int tamE, int orden)
{
	int isOk = -1;
	eEmployee auxEmployee;

	if(lE != NULL)
	{
		for(int i = 0; i < tamE -1; i++)
		{
			for(int j = i + 1; j < tamE; j ++)
			{
				isOk = 0;

				if(lE[i].isEmpty == 0 && lE[j].isEmpty == 0)
				{
					switch(orden)
					{
						case 0:
							if(lE[i].sector < lE[j].sector || (lE[i].sector == lE[j].sector && (strcmp(lE[i].lastName, lE[j].lastName)) < 0))
							{
								auxEmployee = lE[i];
								lE[i] = lE[j];
								lE[j] = auxEmployee;
							}
							break;
						case 1:
							if(lE[i].sector > lE[j].sector || (lE[i].sector == lE[j].sector && (strcmp(lE[i].lastName, lE[j].lastName)) > 0))
							{
								auxEmployee = lE[i];
								lE[i] = lE[j];
								lE[j] = auxEmployee;
							}
							break;
						default:
							printf("No es un orden valido.\n");
					}
				}
			}
		}
	}
	return isOk;
}

/*void printEmployees(eEmployee* lE,int tamE, char name, float salary, int sector, int id)
{

    printf("**** Listado de Empleados ****\n\n");
    printf(" Id                      nombre           apellido               salario              sector      \n\n");

    for(int i = 0; i < tamE; i++)
    {
        if(lE[i].isEmpty == 0)
            {
                printf("%d               %10s             %10s                   %2.f                 %d  \n", lE[i].id, lE[i].name, lE[i].lastName, lE[i].salary, lE[i].sector);
            }

    }
}*/

void printEmployees(eEmployee* lE,int tamE, char name, float salary, int sector, int id)
{
    int i;
    printf("\nID    Nombre    Apellido     Sueldo   Sector\n\n\n");
    for(i=0; i<tamE; i++)
    {
        if(lE[i].isEmpty==0)
        {
            printf("\n%d    %s     %s      %.2f      %d",lE[i].id,lE[i].name,lE[i].lastName,lE[i].salary,lE[i].sector);
        }
    }
}

void informarEmpleados(eEmployee* lE,int tamE, int* id)
{
    int opcion;
    int i;
    int contadorSalarios;
    float acumuladorSalarios;
    float promedioSalarios;
    int mayorAlSalarioPromedio;
    contadorSalarios=0;
    acumuladorSalarios=0;
    mayorAlSalarioPromedio=0;


        printf("\n1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.");
        printf("\n2. Total y promedio de los salarios, y cuantos empleados superan el salario promedio.");
        printf("\nIngerse opcion: ");
        scanf("%d",&opcion);
        switch(opcion)
        {
        case 1:
            sortEmployees(lE,tamE,1);
            printEmployees(lE, tamE, ' ', 0, 0, 0);
            break;
        case 2:
            for(i=0; i<tamE; i++)
            {
                if(lE[i].isEmpty==0)
                {
                    contadorSalarios++;
                    acumuladorSalarios=acumuladorSalarios+lE[i].salary;

                }
            }
            promedioSalarios=acumuladorSalarios/(float)contadorSalarios;
            for(i=0; i<tamE; i++)
            {
                if(lE[i].salary>promedioSalarios && lE[i].isEmpty==0)
                {
                    mayorAlSalarioPromedio++;
                }
            }
            printf("\nSalarios Totales: %.2f",acumuladorSalarios);
            printf("\nPromedio de salarios: %.2f",promedioSalarios);
            printf("\nEmpleados que superan al sueldo promedio: %d\n\n",mayorAlSalarioPromedio);
            break;
        default:
            printf("\nOpcion invalida!");
            break;
        }
}
