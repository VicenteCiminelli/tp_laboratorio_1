#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

/** \brief Este es menu sirve para elegir la opcion
 *
 * \param
 * \param
 * \return
 *
 */

void menuOpciones()
{
    printf("\n 1-Ingresar el 1er operando");

    printf("\n 2-Ingresar el 2do operando");

    printf("\n 3-Calcular todas las operaciones");

    printf("\n 4-Informar resultados");

    printf("\n 5-Salir");

    printf("\nIngrese opcion: ");


}

float primerNumero(float num1)
{
    printf("\nIngrese el primer numero: ");
    scanf("%f", &num1);

    return num1;

}

float segundoNumero(float num2)
{
    printf("\nIngrese el segundo numero: ");
    scanf("%f", &num2);

    return num2;

}

float sumar(float num1, float num2)
{
    return num1 + num2;

}

float Resta(float num1, float num2)
{
    return num1 - num2;

}

float division(float num1, float num2)
{
    return num1 / num2;

}

float multiplicacion(float num1, float num2)
{
    return num1 * num2;

}

int factorialN1(float num1)
{
    int factorial = (int)num1;
        if(factorial<0)
        {
            factorial=(-1);
        }
        else if(factorial==0)
        {
            factorial=1;
        }
        else
        {
            for(int i=factorial-1; i>0; i--)
            {
                factorial=factorial*i;
            }
        }
    return factorial;

}

int factorialN2(float num2)
{
    int factorial = (int)num2;
        if(factorial<0)
        {
            factorial=(-1);
        }
        else if(factorial==0)
        {
            factorial=1;
        }
        else
        {
            for(int i=factorial-1; i>0; i--)
            {
                factorial=factorial*i;
            }
        }
    return factorial;

}

