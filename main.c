#include <stdio.h>
#include <stdlib.h>

int main()
{
    float num1;
    float num2;
    float resultadoSuma;
    float resultadoResta;
    float resultadoDivision;
    float resultadoMultiplicacion;
    float factorial;
    int i;

    printf("Ingrese 1er Numero\n");
    scanf("%f", &num1);

    printf("Ingrese 2do Numero\n");
    scanf("%f", &num2);

    resultadoSuma = num1 + num2;
    resultadoResta = num1 - num2;
    resultadoDivision = num1 / num2;
    resultadoMultiplicacion = num1 * num2;

    factorial = 1;
    for(i=1;i<=num1;i++){
        factorial *= i;
    }


    printf("\n\n\n El Resultado de la suma entre %f y %f es : %f", num1, num2, resultadoSuma);
    printf("\n El resultado de la Resta entre %f y %f es : %f", num1, num2, resultadoResta);
    printf("\n El Resultado de la divicion entre %f y %f es : %f", num1, num2, resultadoDivision );
    printf("\n El Resultado de la Multiplicacion entre %f y %f es : %f",num1, num2, resultadoMultiplicacion);
    printf("\n El Resultado del factorial de %f es: %f",num1,factorial);

    return 0;
}
