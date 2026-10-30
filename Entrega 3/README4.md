# Sistema de Controle de Estoque 4.0 em C

Projeto desenvolvido em Grupo durante os estudos de Análise e Desenvolvimento de Sistemas (ADS), com o objetivo de aprofundar meus conhecimentos na linguagem C e aplicar conceitos de programação na construção de um sistema completo de gerenciamento de estoque.

O Sistema de Controle de Estoque 4.0 permite cadastrar, consultar, alterar, excluir e organizar produtos, além de realizar cálculos e análises das informações armazenadas. O programa também utiliza arquivos de texto para salvar e carregar os dados, permitindo manter as informações entre diferentes execuções.

## Funcionalidades

- Cadastro de até 100 produtos.
- Registro do código, nome, preço e quantidade.
- Listagem de todos os produtos cadastrados.
- Consulta de produtos por código.
- Alteração das informações de produtos cadastrados.
- Exclusão de produtos, com reorganização dos registros.
- Verificação da situação do estoque: esgotado, baixo ou normal.
- Cálculo do valor financeiro total do estoque.
- Identificação do produto de maior valor total em estoque.
- Identificação do produto de menor valor total em estoque.
- Ordenação dos produtos em ordem crescente de código.
- Salvamento dos dados em arquivo de texto (`produtos.txt`).
- Carregamento dos dados salvos anteriormente.

## Conceitos utilizados

- Declaração e inicialização de variáveis.
- Tipos de dados: `int`, `float` e `char`.
- Estruturas de dados com `struct` e `typedef`.
- Vetores e arrays de estruturas.
- Modularização e reutilização de código por meio de funções.
- Protótipos e parâmetros de funções.
- Ponteiros e passagem de endereço de memória.
- Estruturas condicionais: `if`, `else` e `switch`.
- Estruturas de repetição: `for`, `while` e `do while`.
- Entrada e saída de dados com `fgets()` e `printf()`.
- Validação e conversão de dados.
- Manipulação de arquivos com `FILE`, `fopen()`, `fprintf()`, `fscanf()` e `fclose()`.
- Modos de abertura de arquivos: `w` (escrita) e `r` (leitura).
- Algoritmos de busca e comparação.
- Algoritmo de ordenação Bubble Sort.
- Organização e gerenciamento de informações.

## Tecnologias

- Linguagem C
- Visual Studio Code
- GCC (GNU Compiler Collection)

## Como compilar e executar

No terminal do VS Code, com o GCC instalado, utilize:

**Comando para compilar:**

```sh
gcc main.c -o estoque
```

**Comando para executar no Windows:**

```sh
.\estoque.exe
```

1. Clone este repositório ou baixe os arquivos do projeto.
2. Abra o código no Visual Studio Code.
3. Compile o arquivo utilizando o GCC.
4. Execute o programa pelo terminal.

## Demonstração do sistema

<img width="393" height="401" alt="menu" src="https://github.com/user-attachments/assets/a4ff0422-f6b0-4c33-8b1d-a9e56f009c50" />


O sistema apresenta um menu interativo com 13 opções, permitindo realizar todas as operações de gerenciamento de estoque.

Entre as funcionalidades implementadas na quarta etapa estão a alteração e exclusão de produtos, verificação da situação do estoque, identificação dos produtos de maior e menor valor e ordenação por código.

## Observação final

Durante o desenvolvimento deste projeto, evoluí meus conhecimentos em programação utilizando a linguagem C, colocando em prática conceitos fundamentais e recursos mais avançados da linguagem.

A quarta versão representa a integração desses conhecimentos em um sistema mais completo, com destaque para:

- Manipulação de estruturas de dados.
- Desenvolvimento de funções e modularização.
- Utilização de ponteiros.
- Manipulação de arquivos para persistência de dados.
- Implementação de operações de inclusão, consulta, alteração e exclusão.
- Aplicação de algoritmos de busca e ordenação.
- Validação de entradas e tratamento de dados.

# Autor e Contato

**GABRIEL JOSÉ DOS SANTOS**

gabriel.santos.gjs@outlook.com

(11) 991273616

[LinkedIn](https://www.linkedin.com/in/gabrieljdsantos)

[GitHub](https://github.com/gabrieljdsantos)

[Dev.to](https://dev.to/gabriel_jdsantos).

```Linguagem C```
