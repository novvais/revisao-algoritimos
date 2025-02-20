#include <stdio.h>

int main() {
    float salario, salarioAumento, aumento;

    printf("Digite o salario do seu fundionario: ");
    scanf("%f", &salario);

    aumento = salario * 0.25;

    salarioAumento = aumento + salario;

    printf("O aumento foi de: %.2f. Novo salario: %.2f ", aumento, salarioAumento);
}
