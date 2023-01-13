#include <iostream>
#include <fstream>
#include <string.h>
#include <cstdlib>
#define lim_max 10

using namespace std;

int opt; //variavel global para usar em todos os menus do programa
int cont_max_dep=0; //contador para controlar o maximo de departamentos = 10
int cont_max_tp_eq=0; //contador para controlar o maximo de tipos de equipamentos = 10
int cont_max_eq=0; //contador para controlar o maximo de equipamentos = 10

// Tres classes - Tipo, Departamento e Equipamento
class Tipo_equipamento{

    private:
        int codigo;
        char descricao[50];
    public:
        // funcoes basicas de GET e SET
        char *get_descricao(){

            return descricao;
        }
        int get_codigo(){

            return codigo;
        }
        void set_codigo(int n){

            if (n>0){
                codigo = n;
            }
        }
        void set_descricao(char d[50]){

            if(strlen(d)>1){
                strcpy(descricao, d);
            }
        }
        Tipo_equipamento(){
            codigo = 1;
            strcpy(descricao, "Descricao Padrao");
        }
};
class Departamento{

    private:
        int codigo;
        char nome[50];
        char descricao[50];
        char localizacao[50];
    public:
        // funcoes basicas de GET e SET
        int get_codigo(){

            return codigo;
        }
        char *get_nome(){

            return nome;
        }
        char *get_descricao(){

            return descricao;
        }
        char *get_localizacao(){

            return localizacao;
        }
        void set_codigo(int n){

            if (n>0){
                codigo = n;
            }
        }
        void set_nome(char n[50]){

            if(strlen(n)>1){
                strcpy(nome, n);
            }
        }
        void set_descricao(char d[50]){

            if(strlen(d)>1){
                strcpy(descricao, d);
            }
        }
        void set_localizacao(char l[50]){

            if(strlen(l)>1){
                strcpy(localizacao, l);
            }
        }
        Departamento(){
            codigo = 1;
            strcpy(nome, "Nome Padrao");
            strcpy(descricao, "Descricao Padrao");
            strcpy(localizacao, "Localizacao Padrao");
        }
};
class Equipamento{

    int codigo;
    char nome[50];
    float preco;

    public:
        Tipo_equipamento *equip;
        Departamento *dp;

         int get_codigo(){

            return codigo;
        }
        char *get_nome(){

            return nome;
        }
        float get_preco(){
            return preco;
        }
        Departamento get_dep(){
            return *dp;
        }
        Tipo_equipamento get_tipo(){
            return *equip;
        }
        void set_codigo(int n){

            if (n>0){
                codigo = n;
            }
        }
        void set_nome(char n[50]){

            if(strlen(n)>1){
                strcpy(nome, n);
            }
        }
        void set_preco(float p){
            if (p>0){
                preco=p;
            }
        }
        void set_dep(Departamento *x){
            dp = x;
        }
        void set_tipo(Tipo_equipamento *y){
            equip = y;
        }

};

// Cria uma lista de departamentos
Departamento lista_depart[lim_max];
// Cria uma lista de tipos de equipamentos
Tipo_equipamento lista_tp_eq[lim_max];
// Cria uma lista de equipamentos
Equipamento lista_eq[lim_max];

// Funcoes departamentos
void lista_departamentos(){
    // funcao para listar todos os departamentos ja cadastrados

    for (int i=0; i<cont_max_dep; i++){
        cout<< "Codigo: "<<lista_depart[i].get_codigo()<<endl;
        cout<< "Nome: "<<lista_depart[i].get_nome()<<endl;
        cout<< "Descricao: "<<lista_depart[i].get_descricao()<<endl;
        cout<< "Localizacao: "<<lista_depart[i].get_localizacao()<<endl;
        cout<< "__________________________________"<<endl;
    }  
}
void criar_departamento(){
    // funcao para criar novos departamentos

    int num_dep; // Variavel para determinar quantos departamentos serao cadastrados
    cout<< "Digite quantos departamentos deseja cadastrar: ";
    cin>>num_dep;
    fflush(stdin);

    // Variaveis para armazenar as informações digitadas pelo usuario
    char nome[50];
    char descricao[50];
    char localizacao[50];

    // Verificar se ultrapassou o numero de departamentos
    if(num_dep + cont_max_dep > lim_max){
        cout<< "Não é possivel cadastrar!";
    }
    else{

        for(int i=cont_max_dep; i<(num_dep + cont_max_dep); i++){
            //determina um codigo aleatorio para o departamento
            lista_depart[i].set_codigo(rand()%100);

            //recebe o nome do departamento e armazena
            cout<< "Digite o nome do departamento: ";
            cin>> nome;
            fflush(stdin);
            lista_depart[i].set_nome(nome);

            //recebe a descrição do departamento e armazena
            cout<< "Digite a descricao do departamento: ";
            cin>> descricao;
            fflush(stdin);
            lista_depart[i].set_descricao(descricao);

            //recebe a localização do departamento e armazena
            cout<< "Digite a localizacao do departamento: ";
            cin>> localizacao;
            fflush(stdin);
            lista_depart[i].set_localizacao(localizacao);

            //confirma a criação do departamento
            cout<< "Departamento criado!"<<endl;
            cout<< "Codigo: "<<lista_depart[i].get_codigo()<<endl;
            cout<< "Nome: "<<lista_depart[i].get_nome()<<endl;
            cout<< "Descricao: "<<lista_depart[i].get_descricao()<<endl;
            cout<< "Localizacao: "<<lista_depart[i].get_localizacao()<<endl;
            cout<< "_________________________________________"<<endl;

        }
        cont_max_dep+=num_dep;
    }
}
void pesquisa_departamento(){
    //funcao para pesquisar departamentos

    char opc[50]; // variavel para receber a opcao do usuario de pesquisar por nome ou codigo
    int menu; // variavel para permitir o usuario sair da pesquisa caso nao tenha encontrado um departamento
    char nome[50]; 
    int codg;
    bool key = true; // variavel para permitir pesquisa novamente caso o nome ou codigo digitado esteja errado

    cout<< "Pesquisar por 'nome' ou 'codigo': ";
    cin>>opc;
    fflush(stdin);

    //compara a opc escolhida com uma string nome. Caso o usuario tenha digitado nome, entra na pesquisa por nome. Caso contrario, pesquisa por codigo
    if(strcmp(opc, "nome")==0){

        // percorre a lista de departamentos e compara o nome digitado com os nomes ja inseridos
        do{

            cout<< "Digite o nome do departamento: ";
            cin>> nome;
            fflush(stdin);

            for (int i=0; i<cont_max_dep; i++){

                if(strcmp(nome,lista_depart[i].get_nome())==0){

                    cout<< "Departamento encontrado!"<<endl;
                    cout<< "Codigo: "<<lista_depart[i].get_codigo()<<endl;
                    cout<< "Nome: "<<lista_depart[i].get_nome()<<endl;
                    cout<< "Descricao: "<<lista_depart[i].get_descricao()<<endl;
                    cout<< "Localizacao: "<<lista_depart[i].get_localizacao()<<endl;
                    cout<< "________________________________"<<endl;
                    key = true; //chave verdadeira para sair do while
                    i = cont_max_dep; //stop para encerrar a busca caso seja encontrado um departamento
                }
                else{
                    key = false; //chave falsa para continuar no while, ja que nao foi encontrado o departamento buscado
                }
            }
            if(key == false){
                cout<< "Departamento nao encontrado!"<<endl;
                cout<< "Buscar novamente(1) ou SAIR(0): "<<endl; // da opcao para o usuario sair sem que fique preso na pesquisa ate que apresente um departamento existente
                cin>> menu;
                fflush(stdin);

                if(menu == 0){
                    key = true;
                }
            }
        }
        while(key == false);
    }
    else{

        // percorre a lista de departamentos e compara o codigo digitado com os nomes ja inseridos
        do{
            cout<< "Digite o codigo do departamento: ";
            cin>> codg;
            fflush(stdin);

            for (int i=0; i<cont_max_dep; i++){

                if(codg==lista_depart[i].get_codigo()){

                    cout<< "Departamento encontrado!"<<endl;
                    cout<< "Codigo: "<<lista_depart[i].get_codigo()<<endl;
                    cout<< "Nome: "<<lista_depart[i].get_nome()<<endl;
                    cout<< "Descricao: "<<lista_depart[i].get_descricao()<<endl;
                    cout<< "Localizacao: "<<lista_depart[i].get_localizacao()<<endl;
                    cout<< "__________________________________"<<endl;
                    key = true;
                    i = cont_max_dep; //stop para encerrar a busca caso seja encontrado um departamento
                }
                else{
                    key = false;
                }
            }
            if(key == false){
                cout<< "Departamento nao encontrado!"<<endl;
                cout<< "Buscar novamente(1) ou SAIR(0): "<<endl; //da opcao para o usuario sair sem que fique preso na pesquisa ate que apresente um departamento existente
                cin>> menu;
                fflush(stdin);

                if(menu == 0){
                    key = true;
                }
            }
        }
        while(key == false);
    }
}
void atl_dep(){
    //funcao para atualizar dados dos departamentos

     char nome[50];
     char atl[50]; // variavel para armazenar o que o usuario deseja atualizar
     int opc_dado; // variavel para determinar qual informacao sera atualizada e permitir atualizacao de varios dados
     bool key = true; // variavel para permitir que o usuario digite novamente, caso digite o nome errado

    lista_departamentos();

    do{
        cout<< "Digite o nome do departamento que sera atualizado: ";
        cin>> nome;
        fflush(stdin);

            // percorre a lista de departamentos e compara o nome digitado com os nomes ja inseridos
            for (int i=0; i<cont_max_dep; i++){

                if(strcmp(nome,lista_depart[i].get_nome())==0){
                    key = true;
                    i = cont_max_dep; //stop para encerrar a busca caso seja encontrado um departamento

                    do{
                            cout<< "Qual dado voce deseja atualizar?"<<endl;
                            cout<< "[1] NOME"<<endl;
                            cout<< "[2] DESCRICAO"<<endl;
                            cout<< "[3] LOCALIZACAO"<<endl;
                            cout<< "[0] FINALIZAR"<<endl;
                            cin>> opc_dado;
                            fflush(stdin);

                            switch (opc_dado){
                                case 1:
                                    cout<< "Digite o novo nome: "<< endl;
                                    cin>> atl;
                                    lista_depart[i].set_nome(atl);
                                    cout<< "Nome atualizado!"<< endl;
                                    break;
                                case 2:
                                    cout<< "Digite a nova descricao: "<< endl;
                                    cin>> atl;
                                    lista_depart[i].set_descricao(atl);
                                    cout<< "Descricao atualizada!"<< endl;
                                    break;
                                case 3:
                                    cout<< "Digite a nova localizacao: "<< endl;
                                    cin>> atl;
                                    lista_depart[i].set_localizacao(atl);
                                    cout<< "Localizacao atualizada!"<< endl;
                                    break;
                                case 0:
                                    cout<< "Voltou"<< endl;
                            } 
                        }
                    while(opc_dado!=0);
                }
                else{
                    key = false;
                }
            }
            if(key == false){
                cout<<"Departamento nao encontrado!"<<endl;
                cout<< "Buscar novamente(1) ou SAIR(0): "<<endl; //da opcao para o usuario sair sem que fique preso na pesquisa ate que apresente um departamento existente
                cin>> opc_dado;
                fflush(stdin);

                if(opc_dado == 0){
                    key = true;
                }
            }
    }
    while (key == false);
}
void excl_dep(){
    //funcao para excluir um departamento (Define o departamento como o genérico da classe)
    char nome[50];

    lista_departamentos();

    cout<< "Digite o nome do departamento que sera excluido: ";
    cin>> nome;
    fflush(stdin);

        // percorre a lista de departamentos e compara o nome digitado com os nomes ja inseridos
        for (int i=0; i<cont_max_dep; i++){

            if(strcmp(nome,lista_depart[i].get_nome())==0){

                lista_depart[i] = Departamento();
            }
            else{
                cout<< "Departamento nao encontrado!";
            }
        }
}

// Funcoes tipos de equipamentos
void listar_tipos_equipamentos(){
    // funcao para listar todos os tipos de equipamentos ja cadastrados

    for (int i=0; i<cont_max_tp_eq; i++){
        cout<< "Codigo: "<<lista_tp_eq[i].get_codigo()<<endl;
        cout<< "Descricao: "<<lista_tp_eq[i].get_descricao()<<endl;
        cout<< "__________________________________"<<endl;
    }  

}
void criar_tipos_equipamentos(){
    // funcao para criar novos tipos de equipamentos

    int num_tp_eq; // Variavel para determinar quantos tipos de equipamentos serao cadastrados
    cout<< "Digite quantos tipos de equipamentos deseja cadastrar: ";
    cin>>num_tp_eq;
    fflush(stdin);

    char descricao[50];

    // Verificar se ultrapassou o numero de tipos de equipamentos
    if(num_tp_eq + cont_max_tp_eq > lim_max){
        cout<< "Não é possivel cadastrar! O numero maximo de tipos de equipamentos e 10 e ja existem "<< cont_max_dep;
    }
    else{

        for(int i=cont_max_tp_eq; i<(num_tp_eq + cont_max_tp_eq); i++){
            //determina um codigo aleatorio para o tipo de equipamento
            lista_tp_eq[i].set_codigo(rand()%100);

            //recebe a descrição do tipo de equipamento e armazena
            cout<< "Digite a descricao do tipo de equipamento: ";
            cin>> descricao;
            fflush(stdin);
            lista_tp_eq[i].set_descricao(descricao);

            //confirma a criação do tipo de equipamento
            cout<< "Tipo de equipamento criado!"<<endl;
            cout<< "Codigo: "<<lista_tp_eq[i].get_codigo()<<endl;
            cout<< "Descricao: "<<lista_tp_eq[i].get_descricao()<<endl;
            cout<< "______________________"<<endl;

        }
        cont_max_tp_eq+=num_tp_eq;
    }
}
void pesquisa_tipo_equipamento(){

    //funcao para pesquisar tipos de equipamentos

    int codg;

        cout<< "Digite o codigo do tipo de equipamento: ";
        cin>> codg;
        fflush(stdin);

        // percorre a lista de tipos de equipamentos e compara o codigo digitado com os codigos ja inseridos
        for (int i=0; i<cont_max_tp_eq; i++){

            if(codg==lista_tp_eq[i].get_codigo()){

                cout<< "Tipo de equipamento encontrado!"<<endl;
                cout<< "Codigo: "<<lista_tp_eq[i].get_codigo()<<endl;
                cout<< "Descricao: "<<lista_tp_eq[i].get_descricao()<<endl;
                cout<< "___________________________________"<< endl;
            }
        }

}
void atl_tp_eq(){
    //funcao para atualizar dados dos tipos de equipamentos

     char nome[50];
     char atl[50]; // variavel para armazenar o que o usuario deseja atualizar
     int opc_dado;

    listar_tipos_equipamentos();

    cout<< "Digite o nome do tipo de equipamento que sera atualizado: ";
    cin>> nome;
    fflush(stdin);

        // percorre a lista de tipos e compara o nome digitado com os nomes ja inseridos
        for (int i=0; i<cont_max_tp_eq; i++){

            if(strcmp(nome,lista_tp_eq[i].get_descricao())==0){

                do{
                    cout<< "Qual dado voce deseja atualizar? "<<endl;
                    cout<< "[1] DESCRICAO"<<endl;
                    cout<< "[0] FINALIZAR"<<endl;
                    cin>> opc_dado;
                    fflush(stdin);

                    switch (opc_dado){
                        case 1:
                            cout<< "Digite a nova descricao: "<< endl;
                            cin>> atl;
                            fflush(stdin);
                            lista_tp_eq[i].set_descricao(atl);
                            cout<< "Descricao atualizada!"<< endl;
                            break;
                        case 0:
                            cout<< "Voltou!"<< endl;
                    } 
                }
                while(opc_dado!=0);
            }
        }
}
void excluir_tipo_equip(){
    //funcao para excluir um tipo de equipamento (Define o tipo como o genérico da classe)
    char nome[50];

    lista_departamentos();

    cout<< "Digite o tipo de equipamento que sera excluido: ";
    cin>> nome;
    fflush(stdin);

        // percorre a lista de departamentos e compara o nome digitado com os nomes ja inseridos
        for (int i=0; i<cont_max_tp_eq; i++){

            if(strcmp(nome,lista_tp_eq[i].get_descricao())==0){

                lista_tp_eq[i] = Tipo_equipamento();
            }
            else{
                cout<< "Departamento nao encontrado!";
            }
        }
}

// Funcoes Equipamentos
void listar_equipamentos(){

    for (int i=0; i<cont_max_eq; i++){
        cout<< "Codigo: "<<lista_eq[i].get_codigo()<<endl;
        cout<< "Nome: "<<lista_eq[i].get_nome()<<endl;
        cout<< "Preco: "<<lista_eq[i].get_preco()<<endl;
        cout<< "Departamento: "<<lista_eq[i].dp->get_nome()<<endl;
        cout<< "Tipo de Equipamento: "<<lista_eq[i].equip->get_descricao()<<endl;
        cout<< "__________________________________"<<endl;
    } 
}
void criar_equipamentos(){

    int num_eq; // Variavel para determinar quantos equipamentos serao cadastrados
    cout<< "Digite quantos equipamentos deseja cadastrar: ";
    cin>>num_eq;
    fflush(stdin);

    char nome_dep[50]; // Variavel armazena o departamento em que o equipamento esta localizado
    char nome_tp_eq[50]; // Variavel armazena o nome do tipo de equipamento
    char nome_eq[50]; // Variavel armazena o nome do equipamento
    float preco_eq; // Variavel armazena o preco do equipamento

    if(num_eq + cont_max_eq > lim_max){
        cout<< "Não é possivel cadastrar! O numero maximo de equipamentos e 10 e ja existem "<< cont_max_dep;
    }
    else{

        for(int i=cont_max_eq; i<(num_eq + cont_max_eq); i++){
            //determina um codigo aleatorio para o equipamento
            lista_eq[i].set_codigo(rand()%100);

            lista_departamentos();

            cout<< "Em qual departamento o equipamento esta localizado?";
            cin>> nome_dep;
            fflush(stdin);

            // percorre a lista de departamentos e compara o nome digitado com os nomes ja inseridos
            for (int j=0; j<cont_max_dep; j++){

                if(strcmp(nome_dep,lista_depart[j].get_nome())==0){

                    cout<< "Departamento encontrado!"<<endl;
                    cout<< "Codigo: "<<lista_depart[j].get_codigo()<<endl;
                    cout<< "Nome: "<<lista_depart[j].get_nome()<<endl;
                    cout<< "Descricao: "<<lista_depart[j].get_descricao()<<endl;
                    cout<< "Localizacao: "<<lista_depart[j].get_localizacao()<<endl;
                    cout<< "____________________________"<<endl;

                    lista_eq[i].set_dep(&lista_depart[j]); //insere o departamento encontrado na classe equipamento
                }
            }

            listar_tipos_equipamentos();

            cout<< "Qual o tipo de equipamento?";
            cin>> nome_tp_eq;
            fflush(stdin);

            // percorre a lista de tipos de equipamentos e compara o codigo digitado com os codigos ja inseridos
            for (int j=0; j<cont_max_tp_eq; j++){

                if(strcmp(nome_tp_eq,lista_tp_eq[j].get_descricao())==0){

                    cout<< "Tipo de equipamento encontrado!"<<endl;
                    cout<< "Codigo: "<<lista_tp_eq[j].get_codigo()<<endl;
                    cout<< "Descricao: "<<lista_tp_eq[j].get_descricao()<<endl;
                    cout<< "_______________________________"<<endl;
                    lista_eq[i].set_tipo(&lista_tp_eq[j]);
                }
            }
            
            //recebe o nome do equipamento e armazena
            cout<< "Digite o nome do Equipamento: ";
            cin>> nome_eq;
            fflush(stdin);
            lista_eq[i].set_nome(nome_eq);

            //recebe a descrição do departamento e armazena
            cout<< "Digite o preco do equipamento: ";
            cin>> preco_eq;
            fflush(stdin);
            lista_eq[i].set_preco(preco_eq);

            //confirma a criação do tipo de equipamento
            cout<< "Equipamento cadastrado!"<<endl;
            cout<< "Codigo: "<<lista_eq[i].get_codigo()<<endl;
            cout<< "Nome: "<<lista_eq[i].get_nome()<<endl;
            cout<< "Preco: "<<lista_eq[i].get_preco()<<endl;
            cout<< "Departamento: "<<lista_eq[i].dp->get_nome()<<endl;
            cout<< "Tipo de Equipamento: "<<lista_eq[i].equip->get_descricao()<<endl;
            cout<< "__________________________________"<<endl;
        }
        cont_max_eq+=num_eq;
    }
}
void pesquisa_equipamento(){
    int codg;

        cout<< "Digite o codigo do equipamento: ";
        cin>> codg;
        fflush(stdin);

        // percorre a lista de equipamentos e compara o codigo digitado com os codigos ja inseridos
        for (int i=0; i<cont_max_eq; i++){

            if(codg==lista_eq[i].get_codigo()){

                cout<< "Equipamento encontrado!"<<endl;
                cout<< "Codigo: "<<lista_eq[i].get_codigo()<<endl;
                cout<< "Nome: "<<lista_eq[i].get_nome()<<endl;
                cout<< "Preco: "<<lista_eq[i].get_preco()<<endl;
                cout<< "Departamento: "<<lista_eq[i].dp->get_nome()<<endl;
                cout<< "Tipo de Equipamento: "<<lista_eq[i].equip->get_descricao()<<endl;
                cout<< "__________________________________"<<endl;
            }
        }
}
void atl_eq(){
    //funcao para atualizar dados dos equipamentos

     char nome[50];
     char atl[50]; // variavel para armazenar o que o usuario deseja atualizar
     float novo; // variavel para armazenar caso o usuario deseja atualizar o preco
     int opc_dado; // variavel para determinar qual informacao sera atualizada e permitir atualizacao de varios dados

    listar_equipamentos();

    cout<< "Digite o nome do equipamento que sera atualizado: ";
    cin>> nome;
    fflush(stdin);

        // percorre a lista de equipamentos e compara o nome digitado com os nomes ja inseridos
        for (int i=0; i<cont_max_eq; i++){

            if(strcmp(nome,lista_eq[i].get_nome())==0){

                do{
                    cout<< "Qual dado voce deseja atualizar?"<<endl;
                    cout<< "[1] NOME"<<endl;
                    cout<< "[2] PRECO"<<endl;
                    cout<< "[3] DEPARTAMENTO"<<endl;
                    cout<< "[4] TIPO DE EQUIPAMENTO"<<endl;
                    cout<< "[0] FINALIZAR"<<endl;
                    cout<< "_____________________"<<endl;
                    cin>> opc_dado;
                    fflush(stdin);

                    switch (opc_dado){
                        case 1:
                            cout<< "Digite o novo nome: "<< endl;
                            cin>> atl;
                            lista_eq[i].set_nome(atl);
                            cout<< "Nome atualizado!"<< endl;
                            break;
                        case 2:
                            cout<< "Digite o novo preco: "<< endl;
                            cin>> novo;
                            lista_eq[i].set_preco(novo);
                            cout<< "Descricao atualizada!"<< endl;
                            break;
                        case 3:
                            lista_departamentos();
                            cout<< "Digite o novo departamento: "<< endl;
                            cin>> atl;
                            for (int j=0; j<cont_max_tp_eq; j++){
                                if(strcmp(atl,lista_depart[j].get_descricao())==0){

                                    lista_eq[i].set_tipo(&lista_tp_eq[j]);
                                }
                            }
                            cout<< "Departamento atualizado!"<< endl;
                            break;
                        case 0:
                            cout<< "Voltou"<< endl;
                    } 
                }
                while(opc_dado!=0);
            }
        }
}
//funcoes dos menus
int menu_crud_tp_eq(){

    int codigo_funcionario;

    cout<<"Digite o seu codigo de ID: ";
    cin>>codigo_funcionario;
    fflush(stdin);

    if(codigo_funcionario==0){

        do{

        cout<<"[1] Novo tipo de equipamento\n";
        cout<<"[2] Pesquisar tipo de equipamento por codigo/nome\n";
        cout<<"[3] Atualizar tipo de equipamento existente\n";
        cout<<"[4] Excluir um tipo de equipamento\n";
        cout<<"[0] Voltar ao MENU inicial\n";
        cin>>opt;
        fflush(stdin);

        switch (opt){
            case 1:
                criar_tipos_equipamentos();
                break;
            case 2:
                pesquisa_tipo_equipamento();
                break;
            case 3:
                atl_tp_eq();
                break;
            case 4:
                cout<<"excluiu equipamento";
                break;
            case 0:
                cout<<"Voltou\n";
                break;
        }
        }while (opt!=0);
    }
    else{

         do{

        cout<<"[1] Pesquisar equipamento por codigo/nome\n";
        cout<<"[0] Voltar ao MENU inicial\n";
        cin>>opt;
        fflush(stdin);

        switch (opt){
            case 1:
                cout<<"Pesquisou equipamento";
                break;
            case 0:
                cout<<"Voltou\n";
                break;
        }
        }while (opt!=0);

    }

    return opt=1;

}
int menu_crud_dep(){

    int codigo_funcionario;

    cout<<"Digite o seu codigo de ID: ";
    cin>>codigo_funcionario;
    fflush(stdin);

    if(codigo_funcionario==0){

        do{

        cout<<"[1] Novo departamento\n";
        cout<<"[2] Pesquisar departamento por codigo/nome\n";
        cout<<"[3] Atualizar departamento existente\n";
        cout<<"[4] Excluir um departamento\n";
        cout<<"[0] Voltar ao MENU inicial\n";
        cin>>opt;
        fflush(stdin);

        switch (opt){
            case 1:
                criar_departamento();
                break;
            case 2:
                pesquisa_departamento();
                break;
            case 3:
                atl_dep();
                break;
            case 4:
                excl_dep();
                break;
            case 0:
                cout<<"Voltou\n";
                break;
        }
        }while (opt!=0);
    }
    else{

         do{

        cout<<"[1] Pesquisar departamento por codigo/nome\n";
        cout<<"[0] Voltar ao MENU inicial\n";
        cin>>opt;
        fflush(stdin);

        switch (opt){
            case 1:
                cout<<"Pesquisou equipamento";
                break;
            case 0:
                cout<<"Voltou\n";
                break;
        }
        }while (opt!=0);

    }

    return opt=2;
}
int menu_crud_eq(){

    int codigo_funcionario;

    cout<<"Digite o seu codigo de ID: ";
    cin>>codigo_funcionario;
    fflush(stdin);

    if(codigo_funcionario==0){

        do{

        cout<<"[1] Novo equipamento\n";
        cout<<"[2] Pesquisar equipamento por codigo/nome\n";
        cout<<"[3] Atualizar equipamento existente\n";
        cout<<"[0] Voltar ao MENU inicial\n";
        cin>>opt;

        switch (opt){
            case 1:
                criar_equipamentos();
                break;
            case 2:
                pesquisa_equipamento();
                break;
            case 3:
                atl_eq();
                break;
            case 0:
                cout<<"Voltou\n";
                break;
            }
        }while (opt!=0);
    }
    else{

         do{

        cout<<"[1] Pesquisar equipamento por codigo/nome\n";
        cout<<"[0] Voltar ao MENU inicial\n";
        cin>>opt;
        fflush(stdin);

        switch (opt){
            case 1:
                cout<<"Pesquisou equipamento";
                break;
            case 0:
                cout<<"Voltou\n";
                break;
        }
        }while (opt!=0);

    }

    return opt=3;
}
int salvar_dados(){

    do{
        cout<<"[1] Salvar Departamentos\n";
        cout<<"[2] Salvar tipos de equipamentos\n";
        cout<<"[3] Salvar equipamentos\n";
        cout<<"[0] SAIR\n";
        cin>>opt;
        fflush(stdin);

        switch (opt){
            case 1:{
                ofstream read_file("departamentos.txt");
                for(int i=0; i<cont_max_dep; i++){
                    read_file <<lista_depart[i].get_codigo()<<endl;
                    read_file <<lista_depart[i].get_nome()<<endl;
                    read_file <<lista_depart[i].get_descricao()<<endl;
                    read_file <<lista_depart[i].get_localizacao()<<endl;
                    read_file <<"________________________"<<endl;
                }
                read_file.close();
                break;
            }
            case 2:{
                ofstream read_file("tipos_equipamentos.txt");
                for (int i=0; i<cont_max_tp_eq; i++){
                    read_file<< "Codigo: "<<lista_tp_eq[i].get_codigo()<<endl;
                    read_file<< "Descricao: "<<lista_tp_eq[i].get_descricao()<<endl;
                    read_file<< "__________________________________"<<endl;
                }  
                read_file.close();
                break;
            }
            case 3:{
                ofstream read_file("equipamentos.txt");
                for (int i=0; i<cont_max_eq; i++){
                    read_file<< "Codigo: "<<lista_eq[i].get_codigo()<<endl;
                    read_file<< "Nome: "<<lista_eq[i].get_nome()<<endl;
                    read_file<< "Preco: "<<lista_eq[i].get_preco()<<endl;
                    read_file<< "Departamento: "<<lista_eq[i].dp->get_nome()<<endl;
                    read_file<< "Tipo de Equipamento: "<<lista_eq[i].equip->get_descricao()<<endl;
                    read_file<< "__________________________________"<<endl;
                } 
                read_file.close();
                break;
            }
        }
    }
    while (opt!=0);

    return opt=4;
}
int carregar_dados(){

    do{
        cout<<"[1] Imprimir Departamentos\n";
        cout<<"[2] Imprimir tipos de equipamentos\n";
        cout<<"[3] Imprimir equipamentos\n";
        cout<<"[0] SAIR\n";
        cin>>opt;
        fflush(stdin);

        switch (opt){
            case 1:{
                string departamentos;
                ifstream read_file("departamentos.txt");
                while(getline(read_file, departamentos)){
                    cout<<departamentos<<endl;
                }
                read_file.close();
                break;
            }
            case 2:{
                string tipos_equipamentos;
                ifstream read_file("tipos_equipamentos.txt");
                while(getline(read_file, tipos_equipamentos)){
                    cout<<tipos_equipamentos<<endl;
                }
                read_file.close();
                break;
            }
            case 3:{
                string equipamentos;
                ifstream read_file("equipamentos.txt");
                while(getline(read_file, equipamentos)){
                    cout<<equipamentos<<endl;
                }
                read_file.close();
                break;
            }
        }
    }
    while (opt!=0);

    return opt=5;
}

int main(){
    

    do{
        cout<<"[1] CRUD de departamento\n";
        cout<<"[2] CRUD de tipo de equipamento\n";
        cout<<"[3] CRUD de equipamentos\n";
        cout<<"[4] Salvar dados\n";
        cout<<"[5] Carregar dados\n";
        cout<<"[0] SAIR\n";
        cin>>opt;
        fflush(stdin);

        switch (opt){
            case 1:
                menu_crud_dep();
                break;
            case 2:
                menu_crud_tp_eq();
                break;
            case 3:
                menu_crud_eq();
                break;
            case 4:
                salvar_dados();
                break;
            case 5:
                carregar_dados();
                break;
            case 0:
                cout<<"SAIU";
                break;
            default:
                cout<<"Opcao Invalida!\n";
                break;
        }

    } 
    while (opt!=0);
    
}