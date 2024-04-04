#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void is_primal() {
    int x, bool_primal = 1;
    printf("Digite um número: ");
    scanf("%d", &x);
    if(x > 2) {
        for (int i = 2; i < x; i++) {
            if (x % i == 0) {
                bool_primal = 0;
            }
        }
    }
    printf("Constatamos que o número %d: %s", x, bool_primal == 0 ? "não é primo" : "é primo");
}

void tabuada(){
    int x;
    printf("Digite um número: ");
    scanf("%d", &x);
    for (int i = 0; i <= x; ++i) {
        printf("%d X %d = %d\n", x, i, (x*i));
    }
}

void sum_media(){
    printf("Calcularemos a média de todos os números inseridos. Para terminar o cálculo, digite um número negativo\n");
    int soma = 0, contador =0, x;
    do{
        printf("Digite um número: ");
        scanf("%d", &x);
        if(x < 0)
            break;

        contador += 1;
        soma += x;
    }while(x>0);
    double media = (double) soma/contador;
    printf("A média dos %d numeros digitados foi: %.4lf", contador, media);
}

void lower_higher(){
    int array[9] = {0};
    for(int i = 0; i < 9; i++){
        array[i] = 1+rand() % (20);
        printf("%d\t", array[i]);
    }
    for(int i = 0; i < 8; ++i){
        for (int j = 0; j < 9-i-1; ++j) {
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    printf("\nMenor número: %d\n", array[0]);
    printf("Maior número: %d", array[8]);
}

int call_of_exercises(int a){
    switch (a) {
        case 1:
            is_primal();
            return 0;
            break;
        case 2:
            tabuada();
            return 0;
            break;
        case 3:
            sum_media();
            return 0;
            break;
        case 4:
            lower_higher();
            return 0;
            break;
        case 5:
            return 0;
            break;
        case 6:
            return 0;
            break;
        case 7:
            return 0;
            break;
        case 8:
            return 0;
            break;
        case 9:
            return 0;
            break;
        case 10:
            return 0;
            break;
        case 11:
            return 0;
            break;
        case 12:
            return 0;
            break;
        case 13:
            return 0;
            break;
        case 14:
            return 0;
            break;
        case 15:
            return 0;
            break;
        case 16:
            return 0;
            break;
        case 99:
            printf("Saindo...\n\n");
            return 99;
            break;
        default:
            printf("Exercício não encontrado, retornando ao menu...\n");
            return 0;
            break;
    }
    return 0;
}

int main() {
    // Exercícios separados em funções.
    srand(time(NULL));
    int menu = 0;

    do {
        printf("\n\nBem-vindo à lista de exercícios: \n");
        printf("Por favor, escolha um exercício: ");
        printf("\n\n1. Num Primo\t\t2.Tabuada\t\t3.Media\n4.Maior menor\t\t5. Inverte Vetor\t\t6. Elementos Distintos\n"
               "7. Interseção de vetor \t\t8.Concatenação\t\t9.Soma matriz\n10.Transposição Matriz\t\t11.Multiplica matriz\t\t12.Matriz identidade"
               "\n13.Diagonal Soma\t\t14.Ordenar vetor\t\t15.Fatorial\t\t16.Converte base\n");
        printf("\n\n99 para sair\nDigite sua opção: ");
        scanf("%d", &menu);
        menu = call_of_exercises(menu);
    } while (menu != 99);
}