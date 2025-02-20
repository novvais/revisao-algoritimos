#include <stdio.h>

void inserirDados(float *salario, int *qtdParcelas, float *valorEmprestimo) {
    printf("Digite o seu salario: "):
    scanf("%f", salario);

    printf("Digite o valor do emprestimo: ");
    scanf("%f", valorEmprestimo);

    printf("Digite a quantidade de vezes que voce deseja parcelar: ");
    scanf("%i", parcelas);
}

void calcularParcelas(float valorEmprestimo, int *qtdParcelas, float *valorParcela) {
    *valorParcela = valorEmprestimo / qtdParcelas;
}

char verficar(float *salario, float *valorParcela, char *resultado) {
    
}

int main() {
    float salario, qtdParcelas, emprestimo, valorParcela;

    printf("Inserindo dados...");

    inserirDados(&salario, &qtdParcelas, &emprestimo);


}
