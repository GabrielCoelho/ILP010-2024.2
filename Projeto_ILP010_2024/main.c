/* Copyright 2024 Gabriel Coelho */
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "Cliente.h"  // Inclusão do Struct
#include "Gerencia.h" // Inclusão das funções

int main(int argc, char *argv[]) {
  // Declaração das Variáveis
  Cliente clientes_agencia[10];
  char arquivo_nome[10] = "banco.tbd";
  int numero_conta_pesquisada = 0, resp_menu_gerente = 0, menu_movimentacao = 0,
      clientes_cadastrados = verifica_cadastrados(), conta_buscada,
      indice_encontrado, conta_encontrada_inicio = 0, senha_conta = 0;
  atualiza_clientes(clientes_agencia, 10);

  // Início do Banco.
  while (numero_conta_pesquisada == 0) {
    // Recebe o retorno do início e verifica se a agência está
    // cadastrada
    numero_conta_pesquisada = exibe_inicio_banco();
    // 9 para sair do programa e imprimir no arquivo
    if (numero_conta_pesquisada == 9) {
      printf("Obrigado por utilizar nosso programa!\nSaindo com "
             "segurança...");
      FILE *file_agencia = fopen(arquivo_nome, "w");
      for (int i = 0; i < clientes_cadastrados; i++) {
        fprintf(file_agencia, "%d %d %s %s %d %.2lf %d\n",
                clientes_agencia[i].codigo_cliente,
                clientes_agencia[i].agencia_num,
                clientes_agencia[i].nome_cliente,
                clientes_agencia[i].sobrenome_cliente,
                clientes_agencia[i].conta_corrente,
                clientes_agencia[i].saldo_atual, clientes_agencia[i].chave_pix);
      }
      sleep(2);
      return 0;
    }

    conta_encontrada_inicio =
        encontrar_conta(clientes_agencia, numero_conta_pesquisada, 10);
    if (conta_encontrada_inicio == 20) {
      printf("Conta não encontrada, tente novamente.\n");
      sleep(3);
      numero_conta_pesquisada = 0;
    } else {
      printf("Digite a senha: ");
      scanf("%d", &senha_conta);
      if (senha_conta !=
          clientes_agencia[conta_encontrada_inicio].agencia_num) {
        printf("Senha incorreta\nTente novamente\n");
        sleep(2);
        numero_conta_pesquisada = 0;
        continue;
      } else {
        if (clientes_agencia[conta_encontrada_inicio].conta_corrente == 1234) {
          printf("Você está prestes a entrar no "
                 "banco. Por favor, "
                 "aguarde... \n\n");
          sleep(3);
          resp_menu_gerente = 0;
          while (resp_menu_gerente == 0) {
            // recebe a resposta do menu de
            // gerência
            resp_menu_gerente = exibe_menu_gerente();
            switch (resp_menu_gerente) {
              // Movimentação da conta
            case 1:
              printf("\nDigite o número "
                     "da conta a ser "
                     "movimentada: ");
              scanf("%d", &conta_buscada);
              indice_encontrado =
                  encontrar_conta(clientes_agencia, conta_buscada, 10);
              if (indice_encontrado != 20) {
                printf("Conta "
                       "encontrada "
                       "em "
                       "nosso "
                       "sistema\nAgua"
                       "r"
                       "de "
                       "a leitura "
                       "dos "
                       "dados\n\n");
                sleep(3);
                menu_movimentacao =
                    movimentar_conta(clientes_agencia, indice_encontrado, 10);
                if (menu_movimentacao == 1) {
                  resp_menu_gerente = 0;
                } else {
                  printf("Pane "
                         "no "
                         "siste"
                         "m"
                         "a, "
                         "algum"
                         "a"
                         " cois"
                         "a"
                         " está"
                         " "
                         "desco"
                         "n"
                         "figur"
                         "a"
                         "da\nS"
                         "a"
                         "indo "
                         "do "
                         "progr"
                         "a"
                         "ma "
                         "com "
                         "segur"
                         "a"
                         "nça.."
                         ".");
                  sleep(4);
                  return 0;
                }
              } else {
                printf("Conta não "
                       "encontrada, "
                       "por favor, "
                       "tente "
                       "novamente\n"
                       "\n");
                resp_menu_gerente = 0;
              }
              break;
              // Criação de nova conta
            case 2:
              cria_conta_cliente(clientes_agencia, clientes_cadastrados);
              clientes_cadastrados++;
              printf("Conta cadastrada "
                     "com sucesso!\n\n");
              sleep(1);
              resp_menu_gerente = 0;
              break;
              // Exibição do saldo da
              // conta
            case 3:
              printf("Por favor, informe o "
                     "número da conta: ");
              scanf("%d", &conta_buscada);
              indice_encontrado =
                  encontrar_conta(clientes_agencia, conta_buscada, 10);
              if (indice_encontrado == 20) {
                printf("Conta não "
                       "encontrada\nR"
                       "e"
                       "tornando ao "
                       "menu "
                       "gerencial\n"
                       "\n");
                sleep(2);
              } else {
                exibe_saldo(clientes_agencia, indice_encontrado);
              }
              resp_menu_gerente = 0;
              break;
              // Volta para o menu
              // principal
            case 9:
              numero_conta_pesquisada = 0;
              break;
              // Caso não tenha digitado
              // entre 1-3 ou 9 para sair
            default:
              printf("Por favor digite um "
                     "item do menu\n");
              resp_menu_gerente = 0;
              break;
            }
          }
          if (resp_menu_gerente == 9) {
            continue;
          }
        } else {
          menu_movimentacao =
              movimentar_conta(clientes_agencia, conta_encontrada_inicio, 10);
          if (menu_movimentacao == 1) {
            numero_conta_pesquisada = 0;
            continue;
          } else {
            printf("Pane "
                   "no "
                   "siste"
                   "m"
                   "a, "
                   "algum"
                   "a"
                   " cois"
                   "a"
                   " está"
                   " "
                   "desco"
                   "n"
                   "figur"
                   "a"
                   "da\nS"
                   "a"
                   "indo "
                   "do "
                   "progr"
                   "a"
                   "ma "
                   "com "
                   "segur"
                   "a"
                   "nça.."
                   ".");
            sleep(4);
            return 0;
          }
        }
      }
    }
    return EXIT_SUCCESS;
  }
}
