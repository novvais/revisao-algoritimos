#include <stdio.h>
#include <string.h>

void cadastrandoCliente(char *nome, float *salario) {
    getchar();

    printf("Digite seu nome: ");
    fgets(nome, 50, stdin);

    nome[strcspn(nome, "\n")] = '\0';

    printf("Digite o seu salario: ");
    scanf(" %f", salario);
}

void verificarEmprestimo(float salario, float valorParcela) {
    float limite = salario * 0.20;

    if (valorParcela > limite) { 
        printf("Emprestimo recusado!\n\n");
    } else {
        printf("Emprestimo aprovado!\n\n");
    }
}

void calcularParcelas(float salario, float *valorEmprestimo, int *qtdParcelas, float *valorParcela) {
    printf("Digite o valor do emprestimo: ");
    scanf(" %f", valorEmprestimo);

    printf("Digite a quantidade de vezes que voce deseja parcelar: ");
    scanf(" %i", qtdParcelas);

    *valorParcela = *valorEmprestimo / *qtdParcelas;

    printf("O valor das parcelas fica: %ix parcelas %.2f. \n\n", *qtdParcelas, *valorParcela);

    char escolha;

    printf("DESEJA CONTINUAR E FINALIZAR O EMPRESTIMO (Y/N)? ");
    scanf(" %c", &escolha);
    getchar();

    printf("\n");

    switch (escolha) {
        case 'Y':
        case 'y':
            verificarEmprestimo(salario, *valorParcela);
            break;
        case 'N':
        case 'n':
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
    scanf(" %i", &parcelasPagas);

    printf("\n");

    valorPago = valorParcela * parcelasPagas;

    valorFaltaEmprestimo = emprestimo - valorPago;

    printf("Ainda falta %.2f do emprestimo para pagar. \n\n", valorFaltaEmprestimo);
}

int main() {
    char nome[50];
    float salario, emprestimo, valorParcela;
    int escolha, qtdParcelas;

    while (1) {
        printf("=== SIMULANDO SEU EMPRESTIMO ===\n\n");

        printf("1 - CADASTRO\n");
        printf("2 - SIMULAR EMPRESTIMO\n");
        printf("3 - VERIFICAR QUANTAS PARCELAS FALTAM\n");
        printf("4 - SAIR\n\n");

        printf("Qual sua escolha? ");
        scanf(" %i", &escolha);

        printf("\n");

        switch (escolha) {
            case 1:
                printf("=== CADASTRO ===\n\n");

                cadastrandoCliente(nome, &salario);

                printf("Cadastro efetuado com sucesso!\n\n");
                break;
            case 2:
                printf("=== EMPRESTIMO ===\n\n");

                calcularParcelas(salario, &emprestimo, &qtdParcelas, &valorParcela);
                break;
            case 3:
                printf("=== VERIFICANDO QUANTAS PARCELAS FALTAM ===\n\n");

                verificarParcelas(emprestimo, valorParcela);
                break;
            case 4:
                printf("Saindo...");

                return 0;
                break;
            default:
                printf("Opcao invalida.\n");
                break;
        }
    }

    return 0;
}
