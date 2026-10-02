# Sistema de Controle de Estoque

Projeto desenvolvido em linguagem C para a disciplina da faculdade.

O objetivo do projeto é desenvolver um sistema simples de controle de estoque, utilizando estruturas de decisão e repetição.

## Funcionalidades

- Cadastro de produtos
- Consulta de produtos por código
- Verificação de estoque
- Cálculo do valor total do estoque
- Menu interativo
- Validação de opções do menu
- Cadastro de até 100 produtos

## Conceitos utilizados

- `if / else`
- `switch / case`
- `for`
- `while / do while`
- `break`
- `continue`
- Variáveis e vetores
- Entrada e saída com `scanf` e `printf`

Toda a lógica está dentro de `main`, usando apenas a biblioteca `stdio.h`, sem
funções auxiliares, constantes declaradas ou outras bibliotecas. As leituras são
feitas diretamente com `scanf`, sem limpeza da entrada. O `default` do menu
informa quando uma opção numérica não está entre 1 e 5.

## Tecnologias

- Linguagem C
- VS Code / Dev-C++

## Como compilar e executar

No terminal do VS Code, com GCC instalado, compile com:

```sh
gcc Trabalho.c -o Trabalho.exe
```

Depois, execute `./Trabalho.exe` no Linux ou `.\Trabalho.exe` no PowerShell do Windows.
No Dev-C++, abra `Trabalho.c` e use a opção de compilar e executar.

Informe preços usando ponto decimal, por exemplo `12.50`, e nomes em uma palavra,
como `Arroz` ou `Arroz_integral`, com até 49 caracteres. Use valores inteiros nos
campos de código e quantidade. O cadastro solicita `1` para continuar ou `0` para
retornar ao menu. Os dados ficam em memória durante a execução.

## Status

Em desenvolvimento

O projeto está sendo desenvolvido em etapas e poderá receber novas funcionalidades e melhorias posteriormente.

## Autor

Felipe Miguel Silva
