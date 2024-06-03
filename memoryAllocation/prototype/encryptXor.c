#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAX_INPUT_SIZE 100
char* encrypt(char key, char tobeEncrypted[], int tamanho, char hexString[]){
    for(int i = 0; i < tamanho; i++){
        tobeEncrypted[i] ^= key;
    }
    for(int i = 0; i < tamanho; i++){ 
        sprintf(hexString + (2 * i), "%02X", (unsigned char)tobeEncrypted[i]);
    }
    return hexString;
}
char* decrypt(char key, char toBeDecrypted[], int tamanho){
    for(int i = 0; i < tamanho; i++){
        toBeDecrypted[i] ^= key;
    }
    return toBeDecrypted;
}
int main(){
    while(1){
    char userInput[MAX_INPUT_SIZE] = {0};
    char hexaValue[MAX_INPUT_SIZE] = {0};
    char chave;
    int userOption;
    int leitura;
        do{
            printf("1. Criptografar\n2. Descriptografar\n3. Sair\n> ");
            leitura = scanf("%d", &userOption);
            if(leitura != 1 || userOption != 1 && userOption != 2 && userOption != 3){
                while(getchar() != '\n');
                printf("Digite um numero valido.\n");
                continue;
            }
        }while(userOption != 1 && userOption != 2 && userOption != 3 || leitura != 1);
        switch(userOption){
            case 1:{
                do{
                while(getchar() != '\n');
                printf("Digite a chave: ");
                chave = getchar();
                }while(!isalpha(chave));
                while(getchar() != '\n');
                printf("Digite o que deseja criptografar (100 characters): ");
                fgets(userInput, MAX_INPUT_SIZE, stdin);
                char toBeEncrypted[MAX_INPUT_SIZE];
                strcpy(toBeEncrypted, userInput);
                int tamanho = strlen(toBeEncrypted);
                char *hexString = (char *)malloc(sizeof(char) * (2 * tamanho +1));
                if(hexString == NULL){
                    printf("Nao foi possivel alocar a memoria.\n");
                    exit(1);
                }
                encrypt(chave, toBeEncrypted, tamanho, hexString);
                printf("*===================================================================*\n");
                printf("\t\tChave: %c\n", chave);
                printf("\t\tTexto: %s", userInput);
                printf("\t\tCriptografado: %s\n", hexString);
                printf("*===================================================================*\n");
                free(hexString);
                break;
            }
            case 2:{
                do{
                    while(getchar() != '\n');
                    printf("Digite a chave: ");
                    chave = getchar();
                }while(!isalpha(chave));
                while(getchar() != '\n');
                printf("Digite o hexa: ");
                fgets(hexaValue, sizeof(hexaValue), stdin);
                char toBeDecrypted[MAX_INPUT_SIZE] = {0};
                for(int i = 0; i < MAX_INPUT_SIZE; i++){
                    sscanf(hexaValue + (2 * i), "%2X", (unsigned int *)&toBeDecrypted[i]);
                }
                decrypt(chave, toBeDecrypted, MAX_INPUT_SIZE);
                for(int i = 0; i < MAX_INPUT_SIZE; i++){
                    if(toBeDecrypted[i] != '\n'){
                        toBeDecrypted[i] = toBeDecrypted[i];
                    }else{
                        toBeDecrypted[i] = '\0';
                    }
                } // FIM LOOP FOR
                printf("*===================================================================*\n");
                printf("\t\tChave: %c\n", chave);
                printf("\t\tCriptografado: %s", hexaValue);
                printf("\t\tDescriptografado: %s\n", toBeDecrypted);
                printf("*===================================================================\n");
                break;
            }
            case 3:{
                printf("Saindo....");
                exit(0);
                break;              
            }
            default:
                printf("Opcao invalida");
                break;
        }// FIM SWTICH
    }// FIM WHILE 
return 0;
} // FIM MAIN

















































