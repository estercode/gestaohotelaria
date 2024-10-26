#ifndef HOTELARIA_H
#define HOTELARIA_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_HOSPEDES 100


typedef struct {
    int id;
    char nome[100];
    int quarto;
    int checkIn;
    int checkOut;
} Hospede;


typedef enum {
    OK,                      
    LIMITEUSUARIOS,          
    ERRO,                   
    ARQUIVO_NAO_ENCONTRADO,  
    ABRIR,                   
    ESCREVER,                
    FECHAR,                 
    LER                      
} STATUS;




STATUS cadastrarHospede(Hospede *hospedes, int *totalHospedes);
STATUS salvarHospedesTxt(Hospede *hospedes, int totalHospedes);
STATUS carregarHospedesTxt(Hospede *hospedes, int *totalHospedes);
STATUS salvarHospedesBin(Hospede *hospedes, int totalHospedes);
STATUS carregarHospedesBin(Hospede *hospedes, int *totalHospedes);
STATUS listarHospedes(Hospede *hospedes, int totalHospedes);
STATUS buscarHospede(Hospede *hospedes, int totalHospedes);
STATUS checkOutHospede(Hospede *hospedes, int *totalHospedes);
void clearBuffer();

#endif 