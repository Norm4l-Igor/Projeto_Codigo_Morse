#include <stdio.h>
#include <string.h>

static const char *MORSE_TABLE[26] = {
    ".-",   // A
    "-...", // B
    "-.-.", // C
    "-..",  // D
    ".",    // E
    "..-.", // F
    "--.",  // G
    "....", // H
    "..",   // I
    ".---", // J
    "-.-",  // K
    ".-..", // L
    "--",   // M
    "-.",   // N
    "---",  // O
    ".--.", // P
    "--.-", // Q
    ".-.",  // R
    "...",  // S
    "-",    // T
    "..-",  // U
    "...-", // V
    ".--",  // W
    "-..-", // X
    "-.--", // Y
    "--.."  // Z
};

char buscar_letra(const char *codigo) {
    int i;
    for (i = 0; i < 26; i++)
        if (strcmp(MORSE_TABLE[i], codigo) == 0)
            return (char)('A' + i);
    return '?';
}

int detectar_corrupcao(const char *token) {
    int len = (int)strlen(token);
    return (len > 0 && token[len - 1] == '*');
}

void imprimir_prefixo(const char *prefixo) {
    int i, prefixo_len = (int)strlen(prefixo);
    putchar('[');
    for (i = 0; i < 26; i++)
        if (strncmp(MORSE_TABLE[i], prefixo, prefixo_len) == 0)
            putchar('A' + i);
    putchar(']');
}

void processar_token(const char *token) {
    if (detectar_corrupcao(token)) {
        int len = (int)strlen(token);
        char prefixo[32];
        strncpy(prefixo, token, len - 1);
        prefixo[len - 1] = '\0';
        imprimir_prefixo(prefixo);
    } else {
        putchar(buscar_letra(token));
    }
}


int main(void) {
    char linha[210];
    char token[32];
    int  t, i, comp;

    if (fgets(linha, sizeof(linha), stdin) == NULL)
        return 0;

    comp = (int)strlen(linha);
    if (comp > 0 && linha[comp - 1] == '\n')
        linha[--comp] = '\0';

    t = 0;
    i = 0;

    while (i <= comp) {
        char c = linha[i];

        if (c == ' ' || c == '\0') {
            if (t > 0) {
                token[t] = '\0';
                processar_token(token);
                t = 0;
            }
            if (c == ' ') {
                if (linha[i + 1] == ' ') {
                    putchar(' ');
                    i += 2;
                } else {
                    i += 1;
                }
            } else {
                break;
            }
        } else {
            if (t < 31)
                token[t++] = c;
            i++;
        }
    }

    putchar('\n');
    return 0;
}
