#include <stdio.h>
#include <stdlib.h>
#include "menu.h"

int main()
{


    float num1 = 0;
    float num2 = 0;
    float resultadoSuma=0;
    float resultadoResta=0;
    float resultadoDivision=0;
    float resultadoMultiplicacion=0;
    int flagPrimerNumero = 0;
    int flagSegundoNumero = 0;
    int flagResultados = 0;
    int resultadoFactorialN1=0;
    int resultadoFactorialN2=0;
    char opcion=' ';

    do
    {
        menuOpciones();
        scanf("%c", &opcion);
        system("cls");

        switch(opcion)
        {
            case '1':
            num1 = primerNumero(num1);
            flagPrimerNumero = 1;
            break;

            case '2':
            num2 = segundoNumero(num2);
            flagSegundoNumero = 1;
            break;

            case '3':
            if (flagPrimerNumero == 0)
            {
                printf("\nDebes ingresar el 1er numero\n");
                system("pause");
            }
            else if (flagSegundoNumero == 0)
            {
                printf("\nDebes ingresar el 2do numero\n");
                system("pause");
            }
            else
            {
                resultadoSuma = sumar(num1, num2);
                resultadoResta = Resta(num1, num2);
                resultadoDivision = division(num1, num2);
                resultadoMultiplicacion = multiplicacion(num1, num2);
                resultadoFactorialN1 = factorialN1(num1);
                resultadoFactorialN2 = factorialN2(num2);
                flagResultados = 1;
            }
            break;
            case '4':

            if (flagResultados == 1)
            {
                printf("\nEl resultado de la suma de %1.f + %1.f es %1.f\n", num1, num2, resultadoSuma);
                printf("\nEl resultado de la resta de %1.f - %1.f es %1.f\n", num1, num2, resultadoResta);


                if(num1 == 0)
                {
                    printf("\nNo es posible dividir por 0\n");
                    system("pause");
                }
                else
                {
                    printf("\nEl resultado de la division de %2.f / %f es %f\n", num1, num2, resultadoDivision);
                }

                printf("\nEl resultado de la multiplicacion de %1.f * %1.f es %1.f\n", num1, num2, resultadoMultiplicacion);

                if(num1 < 0)
                {
                    printf("\nNo es posible calcular el factorial de el 1er operando porque es un numero negativo.\n");
                }
                else
                {
                    printf("\nEl resultado factorial de %1.f es %d\n\n", num1, resultadoFactorialN1);
                }

                if(num2 < 0)
                {
                    printf("\nNo es posible calcular el factorial de el 1er operando porque es un numero negativo.\n");
                }
                else
                {
                    printf("\nEl resultado factorial de %1.f es %d\n\n", num2, resultadoFactorialN2);
                }
            }
                system("pause");

                break;



            }

    }
    while(opcion != '5');
    return 0;
}


