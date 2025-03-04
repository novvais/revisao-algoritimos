#include <stdio.h>
#include <string.h>

void cadastrandoCliente(char *nome, float *salario) {
    getchar();
    printf("Digite seu nome: ");
    fgets(nome, 50, stdin);
    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite o seu salario: ");
    scanf("%f", salario);
}

void verificarEmprestimo(float salario, float valorParcela) {
    float limite = salario * 0.20;
    if (valorParcela > limite) { 
        printf("Emprestimo recusado!\n");
    } else {
        printf("Emprestimo aprovado!\n");
    }
}

void calcularParcelas(float salario, float *valorEmprestimo, int *qtdParcelas, float *valorParcela) {
    printf("Digite o valor do emprestimo: ");
    scanf("%f", valorEmprestimo);

    printf("Digite a quantidade de vezes que voce deseja parcelar: ");
    scanf("%i", qtdParcelas);

    *valorParcela = *valorEmprestimo / *qtdParcelas;

    printf("O VALOR DAS PARCELAS FICA: %d PARCELAS DE %.2f. \n", *qtdParcelas, *valorParcela);

    char escolha;
    printf("DESEJA CONTINUAR E FINALIZAR O EMPRESTIMO? Y/N ");
    getchar();
    scanf("%c", &escolha);

    switch (escolha) {
        case 'Y':
            verificarEmprestimo(salario, *valorParcela);
            break;
        case 'N':
            printf("SAINDO...\n");
            break;
        default:
            printf("Opcao invalida.\n");
            break;
    }
}

void verificarParcelas(float emprestimo, float valorParcela) {
    int parcelasPagas = 0;
    float valorFaltaEmprestimo, valorPago;

    printf("Digite quantas parcelas voce ja pagou: ");
    scanf("%i", &parcelasPagas);

    valorPago = valorParcela * parcelasPagas;
    valorFaltaEmprestimo = emprestimo - valorPago;

    printf("Ainda falta %.2f do emprestimo para pagar.\n", valorFaltaEmprestimo);
}

int main() {
    char nome[50];
    float salario, emprestimo, valorParcela;
    int escolha, qtdParcelas;

    printf("=== SIMULANDO SEU EMPRESTIMO ===\n\n");
    printf("1 - CADASTRO\n");
    printf("2 - SIMULAR EMPRESTIMO\n");
    printf("3 - VERIFICAR QUANTAS PARCELAS FALTAM\n");
    printf("4 - SAIR\n\n");
    printf("Qual sua escolha? ");
    scanf("%i", &escolha);
    printf("\n");

    switch (escolha) {
        case 1:
            printf("=== CADASTRO ===\n\n");
            cadastrandoCliente(nome, &salario);
            printf("Cadastro efetuado com sucesso!\n\n");
            break;
        case 2:
            printf("=== EMPRESTIMO ===\n");
            calcularParcelas(salario, &emprestimo, &qtdParcelas, &valorParcela);
            break;
        case 3:
            printf("=== VERIFICANDO QUANTAS PARCELAS FALTAM ===\n");
            verificarParcelas(emprestimo, valorParcela);
            break;
        case 4:
            printf("Saindo...\n");
            break;
        default:
            printf("Opcao invalida!\n");
            break;
    }

    return 0;
}
