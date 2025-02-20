#include <stdio.h>
#include <stdlib.h>

void inserirNotas(float *atividades, float *prova, float *notaBimestre) {
    printf("Digite as notas das Atividades Praticas: ");
    scanf("%f %f %f", &atividades[0], &atividades[1], &atividades[2]);

    printf("Digite a nota da Prova: ");
    scanf("%f", prova);

    printf("\n");

   for (int i = 0; i < 3; i++)
   {
    if (atividades[0] < 0 || atividades[0] > 10) {
        printf("Nota invalida! A nota nao pode ser maior que 10 ou menor que 0");

        exit(1);
    }
   }
   
   *notaBimestre = ((atividades[0] + atividades[1] + atividades[2]) / 3) * 0.3 + (*prova * 0.7);
}

void calculandoNotaFinal(float *notasBimestre, float *notaFinal) {
    *notaFinal = (notasBimestre[0] + notasBimestre[1]) / 2;
}

int main() {
    float notaFinal, atividadesB1[3], atividadesB2[3], notaProvaB1, notaProvaB2;
    float notaBimestre[2];

    printf("-- Inserindo notas do 1 Bimestre -- \n\n");

    inserirNotas(atividadesB1, &notaProvaB1, &notaBimestre[0]);
    
    printf("-- Inserindo notas do 2 Bimestre -- \n\n");

    inserirNotas(atividadesB2, &notaProvaB2, &notaBimestre[1]);

    printf("Calculando Nota Final do aluno... \n\n");

    calculandoNotaFinal(notaBimestre, &notaFinal);

    printf("A nota final do aluno e: %.2f ", notaFinal);
}
