#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

#define TAMANHO_CHAVE_AES 16
#define TAMANHO_BLOCO_AES 16

void aes_criptografar(unsigned char *chave, unsigned char *texto_claro, unsigned char *texto_cifrado) {
    AES_KEY aes_key;
    AES_set_encrypt_key(chave, TAMANHO_CHAVE_AES * 8, &aes_key);

    int i;
    for (i = 0; i < strlen(texto_claro); i += TAMANHO_BLOCO_AES) {
        unsigned char bloco[TAMANHO_BLOCO_AES];
        memcpy(bloco, texto_claro + i, TAMANHO_BLOCO_AES);
        AES_encrypt(bloco, texto_cifrado + i, &aes_key);
    }
}

int main() {
    unsigned char chave[TAMANHO_CHAVE_AES] = "minha_chave_secreta";
    unsigned char texto_claro[] = "olá_mundo";
    unsigned char texto_cifrado[strlen(texto_claro) + 1];

    aes_criptografar(chave, texto_claro, texto_cifrado);

    printf("Texto cifrado: ");
    
    int i;
    for (i = 0; i < strlen(texto_claro); i++) {
        printf("%02x", texto_cifrado[i]);
    }
    printf("\n");

    return 0;
}

