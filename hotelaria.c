#include "hotelaria.h"
#include <stdio.h>
#include <string.h>

STATUS cadastrarHospede(Hospede *hospedes, int *totalHospedes) {
    printf("Cadastrar Hospede Check In\n");
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