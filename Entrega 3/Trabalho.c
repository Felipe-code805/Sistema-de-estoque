#include <stdio.h>

// alteração teste

int main(){
    int opcao;


    do{
        printf("====================\n");
        printf("    ESTOQUE 3.0\n");
        printf("====================\n");
        printf("[1] Cadastrar produtos\n");
        printf("[2] Listar produtos\n");
        printf("[3] Consultar produto\n");
        printf("[4] Salvar dados\n");
        printf("[5] Carregar dados\n");
        printf("[6] Calcular valor do estoque\n");
        printf("[7] Sair do sistema\n");

        printf("Digite uma opcao: ");

        while (scanf("%d", &opcao) != 1 || opcao < 1 || opcao > 7){
            printf("Opcao invalida.\nDigite um numero de 1 a 7: ");
            scanf("%*s");
        }

    switch (opcao) {

    case 1: //Cadastrar produtos
        printf("====================\n");
        printf("CADASTRAR PRODUTOS\n");
        printf("====================\n");
        break;

    case 2: //Listar produtos
        printf("====================\n");
        printf("LISTAR PRODUTOS\n");
        printf("====================\n");
        break;
    
    case 3: //Consultar produto
        printf("====================\n");
        printf("CONSULTAR PRODUTO\n");
        printf("====================\n");
        break;
    
    case 4: //Salvar dados
        printf("====================\n");
        printf("SALVAR DADOS\n");
        printf("====================\n");
        break;

    case 5: //Carregar dados
        printf("====================\n");
        printf("CARREGAR DADOS\n");
        printf("====================\n");
        break;

    case 6: //Calcular valor do estoque
        printf("====================\n");
        printf("CALCULAR VALOR TOTAL DO ESTOQUE\n");
        printf("====================\n");
        break;

    case 7:
        // Sair do sistema
        printf("Saindo do sistema...\n");
        break;

    default:
        //opção inválida
        printf("Opcao invalida.\nPor favor, digite uma opcao de 1 a 7.\n");
        break;

        }
    } while(opcao != 7);
    
    return 0;
}