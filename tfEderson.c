#include <stdio.h>
#include <string.h>

//////////////////VARIAVEIS UNIVERSAIS//////////////
int i;
char op;
//////////////DECLARACAO FUNCAO/////////////////////
int Sistemas();
int CadastroBugs();
int ListaBugs();
int CadastroSistema();
int AlterarBugs();
int CorrigirStatus();
int Busca();
int RelatorioA();
int RelatorioB();
int ExcluirBugs();
//////////////DECLARACAO STRUCT/////////////////////
struct CadastroBug{

    int codigo;
    char descricao[300];
    char Status[20];

};

struct Sistemas{

    int Bugs[10];
    char cliente[30];
    char nomeSis[30];
    char status[20];

};
    struct Sistemas si[10];
    struct CadastroBug c[10];
/////////////////////MAIN//////////////////////////
int main(){

    char opSis;
    char op1;
    char op2;


    printf(" Bem Vindo!\n\n");
    i = 0;

//////////////////////////////SWITCH MASTER//////////////////////////////
    while(i <10 ){
        printf("    Cadastro de Sistema:\n\n");
        CadastroSistema();
        printf("Deseja continuar cadastro?(s/n) ");
        scanf(" %c", &op);

        if(op == 's'){
            continue;
        }else{
            break;
        }
    }

    do{



        printf("\n    MENU: \n a)Ver lista de bugs\n b)Excluir Bug\n c)Buscar Bug\n d)Corrigir Bug\n e)Sair do sistema\n f)Relatorio de Bugs\n g)Relatorio do Sistema\n h)Cadastrar Bug\n\n ->");
        scanf(" %c", &op2);

        switch(op2){

        case 'a':

            printf("    ---AVISO--- \nBUGS JA EXISTENTES NAO PODEM SER DELETADOS OU ALTERADOS.\n");

            ListaBugs();

            printf("\n\nMostrar novos bug cadastrados?(s/n)");
            scanf(" %c", &op);

            if(op == 's'){

                for(i = 5; i < 10; i++){
                    printf(" %d\n %s\n %s\n", c[i].codigo, c[i].descricao, c[i].Status);

                }

            }else{
                break;
            }

            break;

        case 'b':

            ExcluirBugs();

            break;

        case 'c':
-
            Busca();

            break;

        case 'd':

            AlterarBugs();

            break;

        case 'e':

            return 0;

            break;

        case 'f':

            RelatorioA();

            break;

        case 'g':

            RelatorioB();

            break;

        case 'h':

            CadastroBugs();
            break;

        default:

            printf("    Opcao nao existente\n");
            break;
        }


    }while(1);


    return 0;

}
///////////////////IMPLEMENTACAO/////////////////////
int CadastroBugs(){


    for(i = 5; i < 10; i++){

        printf("\nCodigo: ");
        scanf("%d", &c[i].codigo);
        printf("Descricao: ");
        scanf("%s", &c[i].descricao);
        printf("Status: ");
        scanf("%s", &c[i].Status);

        printf("\nInserir novo bug?(s/n)\n");
        scanf(" %c", &op);

        if(op == 's'){
            continue;
        }else{
            break;
        }

    }

}

int ListaBugs(){


    c[0].codigo = 111;
    strcpy (c[0].descricao , " O brilho da tela pode nao responder aos ajustes. Algumas alteracoes de brilho podem nao se aplicar imediatamente. Uma reinicializacao deve resolver isso, para que as alteracoes sejam aplicadas.\n");
    strcpy (c[0].Status, "Corrigido.");

    c[1]. codigo = 222;
    strcpy (c[1].descricao, "Tem a biblioteca declarada, e o programa nao identifica.");
    strcpy (c[1].Status, "Nao Corrigido.");

    c[2]. codigo = 333;
    strcpy (c[2].descricao, "Tem a funcao declarada, e o comando de chamada nao faz nada.");
    strcpy (c[2].Status, "Corrigido.");

    c[3]. codigo = 444;
    strcpy (c[3].descricao, "Tem uma estrutura condicional que nao finaliza e passa para a proxima instrucao, fica repetindo o comando infinitamente.");
    strcpy (c[3].Status, "Corrigido.");

    c[4]. codigo = 555;
    strcpy (c[4].descricao, "O sistema interpreta movimentos do cursor sem que ele tenha sido movimentado.");
    strcpy (c[4].Status, "Corrigido.");

    printf(" %d\n %d\n %d\n %d\n %d\n", c[0].codigo, c[1].codigo, c[2].codigo, c[3].codigo, c[4].codigo);

}

int CadastroSistema(){

    for(i = 0; i < 5; i++){

        //si[i].Bugs = i;
        printf("Cliente: ");
        scanf("%s", &si[i].cliente);
        printf("Nome do Sistema: ");
        scanf("%s", &si[i].nomeSis);
        printf("Codigo do sistema: ");
        scanf("%d", &si[i].Bugs[i]);
        printf("Status: ");
        scanf("%s", &si[i].status);

        printf("\nInserir novo sistema?(s/n) ->");
        scanf(" %c", &op);

        if(op == 's'){
            continue;
        }else{
            break;
        }

    }

}

int AlterarBugs(){

    int s = -1;
    char novo[200];
    int cod;

    printf("\nCodigo do bug a ser alterado: ");
    scanf("%d", &cod);

    for(i = 0; i < 10; i++){

        if(c[i].codigo == cod){

            s = i;

        }
    }
    if(s == -1){ printf("\nCodigo nao encontrado");}
    else{

            printf("\nNova descricao:\n");
            scanf("%s", &novo);

            strcpy(c[s].descricao, novo);

    }

}

int CorrigirStatus(){

    int s ;
    int cod;
    char novo[20];

    printf("\nCodigo do bug a ser alterado: ");
    scanf("%d", &cod);

    for(i = 0; i < 10; i++){

        if(c[i].codigo == cod){

            s = i;

            printf("\nNovo status:\n");
            scanf("%s", &novo);

            strcpy(c[s].Status, novo);

        }

    }
   /* if(s = 0){
        printf("Codigo digitado nao encontrado!");
    }*/


}

int RelatorioA(){

     printf("\nRelatorio de Bugs:\n\n");

    for(i = 0;i<10;i++){
        printf("Codigo: %d\n\n", c[i].codigo);
        printf("Descricao: %s\n\n", c[i].descricao);
        printf("Status: %s\n\n", c[i].Status);
    }

}

int RelatorioB(){

    printf("\nRelatorio do Sistema:\n\n");

    for(i = 0;i<10;i++){
        printf("%d - ", si[i].Bugs[i]);
        printf("%s\n\n", si[i].nomeSis);
        printf("Cliente: %s\n\n", si[i].cliente);
        printf("Status: %s\n\n", si[i].status);
    }


}

int Busca(){

    int cod;
    int s=-1;

    while(s < 0){
        printf("\nDigite o codigo: ");
        scanf("%d", &cod);

        for(i = 0; i < 10; i++){

            if(c[i].codigo == cod){

                s = i;
            }
        }

        if(s < 0 ){
            printf("\nCodigo incorreto!\n");
        }else{

            printf("\n Codigo: %d\n\n Descricao: %s\n\n Status: %s\n\n", c[s].codigo, c[s].descricao, c[s].Status);

        }

    }
}

int ExcluirBugs(){

    int cod;
    int s=-1;


        printf("\nCodigo a remover: ");
        scanf("%d", &cod);

        for(i = 0; i < 10; i++){

            if(c[i].codigo == cod){

                s = i;
            }
        }

        if(s < 0 ){
            printf("\nCodigo incorreto!\n");
        }else{
            c[s].codigo = 0;
            c[s].descricao[0] = 0;
            c[s].Status[0] = 0;
        }
}
