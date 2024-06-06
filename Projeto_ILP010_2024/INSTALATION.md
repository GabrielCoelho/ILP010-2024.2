# Instalação 

Recomendamos qualquer máquina UNIX, preferencialmente GNU/Linux, para utilização com [GCC](https://gcc.gnu.org/). Computadores Windows com CLion podem funcionar, mas notem que a limpeza da tela não será executada. 

## Compilando

```terminal
gcc main.c Gerencia.c -o bancoBatata -lm 
```

Dentro da pasta do projeto, execute este comando no terminal tendo o GCC pré-instalado. 

> **Observação**
> O compilador irá retornar quatro avisos sobre o tamanho de uma variável de texto estar reservando 11 bytes e utilizando menos. Isto é esperado devido ao modo como os desenvolvedores resolveram imprimir os *logs* no relatório.

## Executando 

Ainda no terminal, execute dentro da pasta `./bancoBatata` e o banco estará funcionando. 

[Veja o Guia do Usuário](https://github.com/GabrielCoelho/ILP010-2024.2/blob/main/Projeto_ILP010_2024/GUIDE.md) para entender as funcionalidades do nosso banco. 
