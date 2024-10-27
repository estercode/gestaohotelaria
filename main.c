#include <stdio.h>
#include "hotelaria.h"

int main() {
    Hospede hospedes[MAX_HOSPEDES];
    int totalHospedes = 0;

    carregarHospedesTxt(hospedes, &totalHospedes);  // Carregar dados ao iniciar o programa

    int opcao;
    do {
        printf("\n\tMENU PRINCIPAL - HOTELARIA\n\t\n");
        printf("\t1 - Cadastrar Hospede\n\t");
        printf("2 - Listar Hospedes\n\t");
        printf("3 - Buscar Hospede\n\t");
        printf("4 - Realizar Check-out\n\t");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                cadastrarHospede(hospedes, &totalHospedes);
                break;
            case 2:
                listarHospedes(hospedes, totalHospedes);
                break;
            case 3:
                buscarHospede(hospedes, totalHospedes);
                break;
            case 4:
                checkOutHospede(hospedes, &totalHospedes);
                break;
            case 0:
                printf("ATÉ LOGO...\n");
                break;
            default:
                printf("Opção inválida.\n");
        }
    } while (opcao != 0);

    return 0;
}
