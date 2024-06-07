# Simulador de Caixa Eletrônico - "Banco do Batata"

## Sumário
- [Introdução](#Introdução)
- - [Visão do Produto](#Visão-do-produto)
- [Diagrama de Caso de Uso](#Diagrama-do-caso-de-uso)
- [Descrição do Fluxo de Eventos - Login](#Descricao-do-fluxo-de-eventos-normal-login)
- - Exceção
- [Descrição do Fluxo de Eventos - Efetuar Saque](#Descricao-do-fluxo-de-eventos-normal-efetuar-saque)
- - Exceção
- [Descrição do Fluxo de Eventos - Transferência](#Descricao-do-fluxo-de-eventos-normal-transferencia)
- - Exceção
- [Diagrama de Atividades](#Diagramas-de-atividades)
- [Problemas e Desafios](#Problemas-e-desafios)
- [Conclusão](#Conclusao)



## Introdução
Este simulador de caixa eletrônico realiza, dentro da própria máquina, funções de gerência do banco e funções da conta do cliente. Desde transferências, exibição de saldo, realização de saques e depósitos, até mesmo a visualização de relatórios de todas os registros realizados desde a implantação do sistema. 

### Visão do Produto

Para os clientes do "Banco do Batata" que tem interesse em realizar transações bancárias de todos os tipos a partir do Caixa Eletrônico, nosso sistema possui componentes de última geração para garantir a segurança e praticidade, tendo por diferencial dos demais caixas eletrônicos é a possibilidade do Gerente atender diretamente do caixa, sem a necessidade do cliente informar a senha, facilitando a questão de acessibilidade e inclusão. Uma senha única para a gerência que conseguirá acessar as funcionalidades da conta de pessoas que não têm tanta familiaridade com a tecnologia. 


| ID  | Prioridade | Título                  | Descrição                                                                                                                                                                                                  |
| :-: | ---------- | ----------------------- | ---------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- |
| 01  | 100        | Realizar Login          | Como usuário, necessito acessar as funcionalidades do caixa eletrônico, seja como Cliente, seja como Gerente, através de um login único.                                                                   |
| 02  | 92         | Realizar Transferências | Como usuário, desejo realizar transferências entre contas. Quando acessar como Cliente, preciso transferir da minha conta para outra; Quando acessar como Gerente, posso escolher de que conta transferir. |
| 03  | 90         | Consultar Extrato       | Como usuário, Cliente ou Gerente, quero realizar a operação de consultar o saldo de minha conta ou de outra qualquer (no caso de gerente).                                                                 |
| 04  | 85         | Realizar Depósito       | Como usuário, quero assegurar que o depósito na minha conta seja realizado com exatidão de valores. Como Gerente, quero assegurar que o cliente receberá o valor depositado com exatidão.                  |
| 05  | 70         | Realizar Saque          | Como Cliente, quero realizar a operação de saque da minha conta, para utilizar o dinheiro em espécie.                                                                                                      |
| 06  | 40         | Recarga de Celular      | Como Cliente, quero realizar a recarga do meu celular ou de outra pessoa a partir do saldo que tenho em caixa.                                                                                             |


## Diagrama de Caso de Uso 
![](https://i.imgur.com/ROWOztD.png)

## Descrição do Fluxo de Eventos Normal: Login
1. O Cliente insere login e senha
2. O programa analisa o login e senha e determina se exibirá o menu do Cliente ou o menu de Gerência
3. O caixa automático recebe do banco o menu determinado e exibe ao cliente
### Fluxo de evento de Exceção: Login
1. a) Login ou senha inválida: Se não consta na nossa base de dados, o sistema do caixa eletrônico encerrará o programa. 
   
## Descrição do Fluxo de Eventos Normal: Efetuar Saque
1. Após ter feito o login, o programa exibirá o menu selecionado
2. O cliente seleciona o menu de saque
3. O cliente informa a quantia desejada
4. O programa envia uma requisição à base de dados
5. Tendo sido aprovado o Saque, as notas são separadas
6. Após retirar do caixa eletrônico, o sistema retira a quantia da conta.

### Fluxo de Eventos de Exceção: Efetuar Saque
3. a) A quantia desejada não corresponde ao valor existente na conta, sendo excedente: Operação negada - falta de saldo. 
4. a) O caixa eletrônico não possui notas suficientes. Operação negada - falta de valor em espécie na máquina

## Descrição do Fluxo de Eventos Normal: Transferência
1. Após ter feito o login, o programa exibirá o menu selecionado
2. O cliente seleciona o menu de transferência
3. O cliente informa a quantia a ser transferida
4. O cliente informa a conta de destino
5. O programa envia uma requisição à base de dados
6. Tendo sido aprovada a transferência, o programa a efetua
7. Após a transferência, uma confirmação aparece na tela. 

### Fluxo de Eventos de Exceção: Transferência
3. a) Saldo em conta menor que a quantia desejada para transferência. Operação negada - falta de saldo. 
4. a) Conta inexistente

## Descrição do Fluxo de Eventos Normal: Criar Conta
1. Após logar como Gerente, o programa exibirá o menu de gerência
2. O gerente seleciona o campo de criar conta
3. Insere as informações necessárias recebidas do cliente no caixa eletrônico
4. O programa insere o novo cliente na base de dados
5. Após a inserção, uma confirmação aparece na tela. 

### Diagramas de Atividades
![](https://i.imgur.com/xj3dUFC.png)

![](https://i.imgur.com/sbtgefe.png)

![](https://i.imgur.com/rD4nPip.png)

# Problemas e Desafios
Há ainda uma questão de segurança na conta do gerente, existindo apenas uma conta para os gerentes de nossa agência. No entanto, como o "Banco do Batata" é um banco recente e localizado somente em uma única cidade (Mogi Guaçu). Assim, ambos compartilham o mesmo login e assinaram um termo de não utilização da conta como movimentação própria, sendo utilizada somente durante o trabalho na frente dos caixas. 

Houve também o desafio de mostrar o relatório na tela do caixa eletrônico, afim de que mostre uma entrada por vez ou selecionar uma data de início e data fim. Esta preocupação está em atualização pela equipe de desenvolvimento. 

# Conclusão 
Nosso sistema está pronto para ser lançado na inauguração do banco sendo testado meticulosamente pela equipe de desenvolvimento. Os mesmos se propuseram a criar um guia do usuário para apresentarem em planfetos para os clientes da agência. Além das dificuldades apresentadas, trabalhar neste projeto foi muito proveitoso para todos. No entanto, ainda há muito o que melhorar, como: a criação de uma interface gráfica para melhorar a experiência do usuário; impressão do relatório; solicitações de empréstimo direto no caixa com aprovação na hora e muito mais. A equipe está contente e buscará implementar a maioria na próxima atualização do sistema.
