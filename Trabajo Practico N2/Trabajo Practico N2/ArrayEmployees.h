#ifndef ARRAYEMPLOYEES_H_INCLUDED
#define ARRAYEMPLOYEES_H_INCLUDED
typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;

}eEmployee;



#endif // ARRAYEMPLOYEES_H_INCLUDED

void modificarEmployee(eEmployee* lE, int id, int salary, int sector, char name[], char lastName[], int tamE);

/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

void menu();

/** \brief  To indicate that all position in the array are empty,
*          this function put the flag (isEmpty) in TRUE in all
*          position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
* */

int initEmployees(eEmployee* lE, int tamE);

/** \brief add in a existing list of employees the values received as parameters
*     in the first empty position
* \param list employee
*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without free space] - (0) if Ok
* */

int altaEmpleado(eEmployee* lE, int tamE, int id, char name[],char lastName[],float salary,int sector);

/** \brief register a new employee
*
* \param  The user must enter Name and lastName
* \param The user must enter salary and sector
* \return Employee
* */

int findEmployeeById(eEmployee* lE, int tamE,int id);

/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee
*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't find a employee] - (0) if Ok
* */

int removeEmployee(eEmployee* lE, int tamE, int id);

/** \brief Sort the elements in the array of employees, the argument order indicate UP or DOWN order
*
* \param list Employee
*
* \param len int
* \param order int  [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
* */

int sortEmployees(eEmployee* lE, int tamE, int order);

/** \brief print the content of employees array
*
* \param list Employee
*
* \param length int
* \return int
* */
void printEmployees(eEmployee* lE,int tamE, char name, float salary, int sector, int id);

/** \brief print
 *
 * \param
 * \param
 * \return
 *
 */
void informarEmpleados(eEmployee* lE,int tamE, int* id);
