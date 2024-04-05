#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void bubble_sort(int *array, int num){
    for(int i = 0; i < num-1; ++i){
        for (int j = 0; j < num-i-1; ++j) {
            if(array[j] > array[j+1]){
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
}
void bubble_sort_inverse(int *array, int num){
    for(int i = 0; i < num-1; ++i){
        for (int j = num; j > 0; --j) {
            if(array[j] > array[j-1]){
                int temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }
        }
    }
}
void return_array_items(int *array, int len){
    for(int i = 0; i < len; i++){
        array[i] = 1+rand() % (20);
        printf("%d\t", array[i]);
    }
}

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
    for (int i = 0; i <= 10; ++i) {
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
    return_array_items(array, 9);
    bubble_sort(array, 9);
    printf("\nMenor número: %d\n", array[0]);
    printf("Maior número: %d", array[8]);
}

void inverse_array(){
    int array[10] = {0};
    return_array_items(array, 10);
    bubble_sort(array, 10);
    printf("\nVetor em ordem crescente:\n");
    for (int i = 0; i < 10; ++i) {
        printf("[%d] \t", array[i]);
    }
    printf("\nVetor em ordem decrescente:\n");
    bubble_sort_inverse(array, 10);
    for (int i = 0; i < 10; ++i) {
        printf("[%d] \t", array[i]);
    }
}

void distinct_elements(){
    int array[8] = {0};
    int contagem = 0, distinto = 0;
    return_array_items(array, 8);
    for (int i = 0; i < 7; ++i) {
        for (int j = 1; j < 7; ++j) {
            if (array[i] != array[j]){
                contagem += 1;
                continue;
            }else{
                contagem -=1;
            }
        }
        if(contagem != 0){
            distinto +=1;
            contagem = 0;
        }
    }
    if(distinto != 0) {
        printf("\nForam encontrados %d elementos distintos no array!", distinto);
    } else{
        printf("\nNenhum elemento é distinto no array\n");
    }
}

void intersection_array(){
    int array[10] = {0}, array_2[10] = {0};
    return_array_items(array, 10);
    printf("\n");
    return_array_items(array_2, 10);
    for(int i = 0; i < 10; ++i){
        for (int j = 0; j < 10; ++j) {
            if(array[i] == array_2[j]){
                printf("\nEncontrado o elemento %d na posição Array1(%d) "
                       "= Array2(%d)\n", array[i], i+1, j+1);
            }
        }
    }

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
            inverse_array();
            return 0;
            break;
        case 6:
            distinct_elements();
            return 0;
            break;
        case 7:
            intersection_array();
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