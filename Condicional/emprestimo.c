#include <stdio.h>

void inserirDados(float *salario, int *qtdParcelas, float *valorEmprestimo) {
    printf("Digite o seu salario: ");
    scanf("%f", salario);

    printf("Digite o valor do emprestimo: ");
    scanf("%f", valorEmprestimo);

    printf("Digite a quantidade de vezes que voce deseja parcelar: ");
    scanf("%i", qtdParcelas);
}

void calcularParcelas(float valorEmprestimo, int qtdParcelas, float *valorParcela) {
    *valorParcela = valorEmprestimo / qtdParcelas;
}

void verificarEmprestimo(float salario, float valorParcela) {
    float limite = salario * 0.20;

    if (valorParcela > limite) { 
        printf("Emprestimo recusado!\n");
    } else {
        printf("Emprestimo aprovado!\n");
    }
}

int main() {
    float salario, emprestimo, valorParcela;
    int qtdParcelas;

    printf("Inserindo dados...\n\n");

    inserirDados(&salario, &qtdParcelas, &emprestimo);

    calcularParcelas(emprestimo, qtdParcelas, &valorParcela);

    printf("\nVerificando o emprestimo...\n\n");

    verificarEmprestimo(salario, valorParcela);

    return 0;
}
