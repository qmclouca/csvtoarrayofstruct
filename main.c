#include <stdio.h>
#include <locale.h>

struct my_record {
    int ordem;
    char letra;
    unsigned char texto;
};

int main() {
    setlocale(LC_ALL, "Portuguese");
    FILE* my_file = fopen("d:\\teste.csv", "r+");

    struct my_record records[9];
    size_t count = 0;

    for (; count < sizeof(records)/sizeof(records[0]); ++count){
        int got = fscanf(my_file, "%d,%c,%s", &records[count].ordem, &records[count].letra, &records[count].texto);
        if (got != 3) break; // wrong number of tokens - maybe end of file
    }

    for (int x=0; x<9;x++){
        printf("ordem: %d, letra: %c, texto: %s \n", (int) &records[x].ordem, (int) &records[x].letra, &records[x].texto);
    }

    fclose(my_file);
    return 0;
}

/*
 * typedef struct {
        char codCvm; //CODIGO CVM
        char cnpj; //CNPJ
        char denSoc; //DENOMINACAO SOCIAL
        char denCom; //COMERCIAL
        char datReg; //DATA DO REGISTRO
        char datConst; //DATA DA CONSTITUICAO
        char datCancel; //DATA DO CANCELAMENTO
        char motCancel; //MOTIVO DO CANCELAMENTO
        char sit; //SITUACAO
        char inisit; //INÍCIO DA SITUAÇÃO
        char setatividade; //SETOR DE ATIVIDADE
        char tipomerc; //TIPO DE MERCADO
        char catreg; //CATEGORIA DO REGISTRO
        char datinicat; //DATA INICIAL DA CATEGORIA
        char sitemissor; //SITUAÇÃO DO EMISSOR
        char datinisitemissor; //DATA INICIAL DA SITUAÇÃO DO EMISSOR
        char tipoend; //TIPO DE ENDEREÇO
        char logradouro; //LOGRADOURO
        char complemento; //COMPLEMENTO
        char bairro; //bairro
        char municipio; //municipio
        char uf; //UF
        char pais; //PAIS
        char cep; //cep
        char dddtel; //DDD DO TELEFONE
        char tel; //telefone
        char dddfax; //DDD do fax
        char fax; //fax
        char email; //email
        char tiporesp; //TIPO DE RESPONSÁVEL
        char nomeresp; //NOME DO RESPONSÁVEL
        char datiniresp; //DATA INICIAL DO RESPONSÁVEL
        char logresp; //LOGRADOURO DO RESPONSÁVEL
        char compresp; //COMPLEMENTO DO RESPONSÁVEL
        char bairroresp; //bairro do responsável
        char munresp; //MUNICÍPIO DO RESPONSÁVEL
        char ufresp; //UF do RESPONSÁVEL
        char paisresp; //PAIS DO RESPONSÁVEL
        char cepresp; //CEP RESPONSÁVEL
        char dddresp; //DDD do telefone do responsável
        char telresp; //telefone do responsável
        char dddfaxresp; //ddd do fax do responsável
        char faxresp; //número do fax do responsável
        char emailresp; //email do responsável
        char cnpjauditor; //CNPJ auditor
        char auditor; //nome do auditor
    }valores;

    valores dados; //instância uma variável display do tipo valores
 */