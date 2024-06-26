#ifndef GERENCIA_H_INCLUDED
#define GERENCIA_H_INCLUDED
#include <stdio.h>

#include "Cliente.h"  // recebe a struct

int exibe_inicio_banco();
int exibe_menu_gerente();
void atualiza_clientes(Cliente c[], int tamanho_agencia);
void exibe_saldo(Cliente c[], int indice_da_conta);
int verifica_cadastrados();
int encontrar_conta(Cliente c[], int conta_buscada, int tamanho_agencia);
int encontrar_pix(Cliente c[], int conta_buscada, int tamanho_agencia);
int saque_deposito_conta(int operacao, Cliente c[], int indice_da_conta);
int transferencia_entre_contas(Cliente c[], int indice_da_conta);
int pix_entre_contas(Cliente c[], int indice_da_conta);
int movimentar_conta(Cliente c[], int indice_da_conta, int tamanho_agencia);
void cria_conta_cliente(Cliente c[], int tamanho_agencia);
void imprime_relatorio(int operacao, char s[11], int conta, int conta_destino,
                       double saldo_antigo, double saldo_novo,
                       double valor_movimentacao);
#endif  // !GERENCIA_H_INCLUDED
