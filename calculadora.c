#include <stdio.h>

void sumar(float n1, float n2){
    float resul = n1 + n2;
    printf("%.2f + %.2f = %.2f",n1,n2,resul);
}

void resta(float n1, float n2){
    float resul = n1 - n2;
    printf("%.2f - %.2f = %.2f",n1,n2,resul);
}

void division(float n1, float n2){
    if (n2 == 0)
    {
        printf("No se puede dividir por 0\n");
        return;
    }
    
    float resul = n1 / n2;
    printf("%.2f / %.2f = %.2f",n1,n2,resul);
}

void multiplicacion(float n1, float n2){
    float resul = n1 * n2;
    printf("%.2f * %.2f = %.2f",n1,n2,resul);
}

void pedirnumero(float *n1, float *n2){
    printf("Ingrese el primer numero: ");
    scanf("%f", n1);
    printf("Ingrese el segundo numero: ");
    scanf("%f", n2);
}

void operaciones(){
    printf("1. Suma\n");
    printf("2. Resta\n");
    printf("3. Division\n");
    printf("4. Multiplicacion\n");
    printf("5. Salir\n");

    printf("Elije una operacion: ");
    
}

int main(){

    int op;
    float n1, n2;


    printf(".......calculadora.......\n");
    printf("\n");

    while (1)
    {
        operaciones(op);
        scanf("%d",&op);

        switch (op)
        {
        case 1:
            pedirnumero(&n1,&n2);
            sumar(n1,n2);
            printf("\n");
            break;
        case 2:
            pedirnumero(&n1,&n2);
            resta(n1,n2);
            printf("\n");
            break;
        case 3:
            pedirnumero(&n1,&n2);
            division(n1,n2);
            printf("\n");
            break;
        case 4:
            pedirnumero(&n1,&n2);
            multiplicacion(n1,n2);
            printf("\n");
            break;
        case 5:
            printf("Saliendo...");
            return 0;
        default:
            printf("Ingrese una operacion valida!!\n");
        }
    }
    return 0;
}