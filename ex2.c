#include <stdio.h>
#include <string.h>

struct Assalariado {
    char nome[100];
    char sexo;
    float salario;
};

void classificaSalario(float salario, char* classificacao) {
    float salarioMinimo = 1400.00;

    if (salario > salarioMinimo) {
        strcpy(classificacao, "Acima do salario minimo");
    } else {
        strcpy(classificacao, "Abaixo do salario minimo");
    }
}

void mostraClassifica(struct Assalariado assalariado) {
    char classificacao[30];

    classificaSalario(assalariado.salario, classificacao);

    printf("Nome: %s\n", assalariado.nome);
    printf("Salario: %.2f reais\n", assalariado.salario);
    printf("Classificacao em relacao ao salario minimo: %s\n", classificacao);
    printf("Sexo: %c\n", assalariado.sexo);
    printf("\n");
}

int main() {
    int qtdAssalariados;

    printf("Digite a quantidade de assalariados: ");
    scanf("%d", &qtdAssalariados);

    struct Assalariado assalariados[qtdAssalariados];

    for (int i = 0; i < qtdAssalariados; i++) {
        printf("Digite o nome do assalariado: ");
        scanf("%s", assalariados[i].nome);

        printf("Digite o sexo do assalariado (M ou F): ");
        scanf(" %c", &assalariados[i].sexo);

        printf("Digite o salario do assalariado: ");
        scanf("%f", &assalariados[i].salario);

        while (assalariados[i].salario <= 1.00) {
            printf("O salario deve ser maior que 1 real. Digite novamente: ");
            scanf("%f", &assalariados[i].salario);
        }
    }

    int qtdAbaixoSalarioMinimo = 0;
    int qtdAcimaSalarioMinimo = 0;

    for (int i = 0; i < qtdAssalariados; i++) {
        char classificacao[30];

        classificaSalario(assalariados[i].salario, classificacao);

        if (strcmp(classificacao, "Abaixo do salario minimo") == 0) {
            qtdAbaixoSalarioMinimo++;
        } else {
            qtdAcimaSalarioMinimo++;
        }

        mostraClassifica(assalariados[i]);
    }

    printf("Quantidade de assalariados com salario abaixo do salario minimo: %d\n", qtdAbaixoSalarioMinimo);
    printf("Quantidade de assalariados com salario acima do salario minimo: %d\n", qtdAcimaSalarioMinimo);

    return 0;
}