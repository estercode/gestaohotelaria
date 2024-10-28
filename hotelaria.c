#include "hotelaria.h"
#include <stdio.h>
#include <string.h>

// cadastra um novo hóspede
STATUS cadastrarHospede(Hospede *hospedes, int *totalHospedes) {
    if (*totalHospedes >= MAX_HOSPEDES) {
        return LIMITEUSUARIOS;  // Limite de hóspedes atingido
    }

    Hospede novoHospede;
    novoHospede.id = *totalHospedes + 1; 
    printf("Nome do Hóspede: ");
    fgets(novoHospede.nome, sizeof(novoHospede.nome), stdin);
    clearBuffer();
    printf("CPF do Hóspede: ");
    fgets(novoHospede.cpf, sizeof(novoHospede.cpf), stdin);
    clearBuffer();  
    printf("E-mail do Hóspede: ");
    fgets(novoHospede.email, sizeof(novoHospede.email), stdin);
    clearBuffer(); 
    printf("Número do Quarto: ");
    scanf("%d", &novoHospede.quarto);
    clearBuffer();  

    printf("Quantidade de dias de estadia: ");
    scanf("%d", &novoHospede.dias);
    clearBuffer();  

    // Adiciona o novo hóspede ao array
    hospedes[*totalHospedes] = novoHospede;
    (*totalHospedes)++;  // Incrementa o total de hóspedes

    // Salvar os hóspedes em um arquivo de texto e binário após cadastrar
    salvarHospedesTxt(hospedes, *totalHospedes);
    salvarHospedesBin(hospedes, *totalHospedes);

    printf("Hóspede cadastrado com sucesso!\n");
    return OK;
}

STATUS salvarHospedesTxt(Hospede *hospedes, int totalHospedes) {
    printf("Salvar TXT\n");
    return OK;
}

STATUS carregarHospedesTxt(Hospede *hospedes, int *totalHospedes) {
    printf("Carregar TXT\n");
    return OK;
}
STATUS salvarHospedesBin(Hospede *hospedes, int totalHospedes) {
    printf("Salvar BIN\n");
    return OK;
}

STATUS carregarHospedesBin(Hospede *hospedes, int *totalHospedes) {
    printf("Carregar BIN\n");
    return OK;
}

STATUS listarHospedes(Hospede *hospedes, int totalHospedes) {
    printf("Listar Hospede\n");
    return OK;
}

STATUS buscarHospede(Hospede *hospedes, int totalHospedes) {
    printf("Buscar Hospede\n");
    return OK;
}

STATUS checkOutHospede(Hospede *hospedes, int *totalHospedes) {
    printf("CheckOut Hospede\n");
    return OK;
}


void clearBuffer() {
  int c;
  while ((c = getchar()) != '\n' && c != EOF)
    ;
}