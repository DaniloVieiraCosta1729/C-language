#include <windows.h>
#include <string.h>
#include <stdio.h>

void escreverClipboard(const char* texto) {
    const size_t tamanho = 88;
    HGLOBAL hMem = GlobalAlloc(GMEM_MOVEABLE, tamanho);
    memcpy(GlobalLock(hMem), texto, tamanho);
    GlobalUnlock(hMem);

    OpenClipboard(NULL);
    EmptyClipboard();
    SetClipboardData(1, hMem);
    CloseClipboard();
}

int main() {
    const char* mensagem = "Texto enviado para a área de transferência!";
    escreverClipboard(mensagem);
    printf("Texto copiado!\n");
    return 0;
}
