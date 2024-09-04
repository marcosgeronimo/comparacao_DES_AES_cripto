#include <stdio.h>
#include <string.h>

#define TAMANHO_CHAVE_DES 8
#define TAMANHO_BLOCO_DES 8

void des_criptografar(unsigned char *chave, unsigned char *texto_claro, unsigned char *texto_cifrado) {
    unsigned char agenda_chave[16][6];

    // Gera a chave de programação
    des_configurar_chave(chave, agenda_chave);

    // Encripta o texto em claro (1 bloco de 8 bytes)
    unsigned char bloco[TAMANHO_BLOCO_DES];
    memcpy(bloco, texto_claro, TAMANHO_BLOCO_DES);
    des_criptografar_bloco(agenda_chave, bloco, texto_cifrado);
}

int main() {
    unsigned char chave[TAMANHO_CHAVE_DES] = "cuscuzzz";
    unsigned char texto_claro[TAMANHO_BLOCO_DES] = "bodinhoo";
    unsigned char texto_cifrado[TAMANHO_BLOCO_DES];

    memset(texto_cifrado, 0, TAMANHO_BLOCO_DES);

    des_criptografar(chave, texto_claro, texto_cifrado);

    printf("Texto cifrado: ");
    
    int i;
    for (i = 0; i < TAMANHO_BLOCO_DES; i++) {
        printf("%02x", texto_cifrado[i]);
    }
    printf("\n");

    return 0;
}

