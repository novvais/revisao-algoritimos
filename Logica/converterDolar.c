#include <stdio.h>

int main() {
    float real, valorConvertido, dolar = 5.78;

    printf("Digite o valor em real a ser convertido: ");
    scanf("%f", &real);

    valorConvertido = real / dolar;

    printf("O valor convertido para dolar e: %.2f", valorConvertido);
}
