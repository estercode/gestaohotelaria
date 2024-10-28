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
    //fgets(novoHospede.nome, sizeof(novoHospede.nome), stdin);
    scanf(" %[^\n]", novoHospede.nome);
    clearBuffer();
    printf("CPF do Hóspede: ");
    fgets(novoHospede.cpf, sizeof(novoHospede.cpf), stdin);
  
    printf("E-mail do Hóspede: ");
    fgets(novoHospede.email, sizeof(novoHospede.email), stdin);
 
    printf("Número do Quarto: ");
    scanf("%d", &novoHospede.quarto);


    printf("Quantidade de dias de estadia: ");
    scanf("%d", &novoHospede.dias);
    clearBuffer();  

    // Adiciona o novo hóspede ao array
    hospedes[*totalHospedes] = novoHospede;
    (*totalHospedes)++;  

    // Salvar os hóspedes em um arquivo de texto e binário após cadastrar
    salvarHospedesTxt(hospedes, *totalHospedes);
    salvarHospedesBin(hospedes, *totalHospedes);

    printf("Hóspede cadastrado com sucesso!\n");
    return OK;
}

STATUS salvarHospedesTxt(Hospede *hospedes, int totalHospedes) {
    FILE *file = fopen("hospedes.txt", "w");
    if (file == NULL) {
        return ABRIR;  
    }

    for (int i = 0; i < totalHospedes; i++) {
        fprintf(file, "%d;%s;%s;%s;%d;%d\n", 
                hospedes[i].id,
                hospedes[i].nome,
                hospedes[i].cpf,
                hospedes[i].email,
                hospedes[i].quarto,
                hospedes[i].dias);
    }

    fclose(file);
    return OK;  
}


STATUS carregarHospedesTxt(Hospede *hospedes, int *totalHospedes) {
    FILE *file = fopen("hospedes.txt", "r");
    if (file == NULL) {
        return ARQUIVO_NAO_ENCONTRADO;  
    }

    while (fscanf(file, "%d;%99[^;];%14[^;];%99[^;];%d;%d\n", 
                  &hospedes[*totalHospedes].id,
                  hospedes[*totalHospedes].nome,
                  hospedes[*totalHospedes].cpf,
                  hospedes[*totalHospedes].email,
                  &hospedes[*totalHospedes].quarto,
                  &hospedes[*totalHospedes].dias) == 6) {
        (*totalHospedes)++;
    }

    fclose(file);
    return OK; 
}

STATUS salvarHospedesBin(Hospede *hospedes, int totalHospedes) {
    FILE *file = fopen("hospedes.bin", "wb");
    if (file == NULL) {
        return ABRIR;  
    }

    fwrite(hospedes, sizeof(Hospede), totalHospedes, file);
    fclose(file);
    return OK; 
}


STATUS carregarHospedesBin(Hospede *hospedes, int *totalHospedes) {
    FILE *file = fopen("hospedes.bin", "rb");
    if (file == NULL) {
        return ARQUIVO_NAO_ENCONTRADO;  // Arquivo não encontrado
    }

    *totalHospedes = fread(hospedes, sizeof(Hospede), MAX_HOSPEDES, file);
    fclose(file);
    return OK;  
}


STATUS listarHospedes(Hospede *hospedes, int totalHospedes) {
 if (totalHospedes == 0) {
        return ERRO;
    }

    printf("Lista de Hóspedes:\n");
    for (int i = 0; i < totalHospedes; i++) {
        printf("\nID: %d\nNome: %s\nQuarto: %d \nCheck-in: %d \nCheck-out: %d\n",
               hospedes[i].id, hospedes[i].nome, hospedes[i].quarto, hospedes[i].checkIn, hospedes[i].checkOut);
    }

    return OK;
}

STATUS checkIn(Hospede *hospedes, int totalHospedes) {
     char nome[100];
    int quarto;
    int encontrado = 0;

    printf("Informe o nome do hóspede: ");
    clearBuffer();  
    fgets(nome, sizeof(nome), stdin);
    nome[strcspn(nome, "\n")] = 0; 

    printf("Informe o número do quarto: ");
    scanf("%d", &quarto);
    clearBuffer(); 

    // Verificar hospede
    for (int i = 0; i < totalHospedes; i++) {
       
        printf(" Depuração: Hóspede #%d\n Nome: %s \n Quarto: %d\n", i, hospedes[i].nome, hospedes[i].quarto);

       
        if (strcmp(hospedes[i].nome, nome) == 0 && hospedes[i].quarto == quarto) {
            encontrado = 1;  
            break;
        }
    }

    if (encontrado) {
        printf(" Check-in realizado com sucesso para %s, quarto %d.\n", nome, quarto);
        return OK;
    } else {
        printf(" Não há reservas com esse nome ou quarto.\n");
        return ERRO;
    }
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