#include "text_editor.h"

int main() {
    printf("======================================\n");
    printf(" SELAMAT DATANG DI PUH TEXT EDITOR GW  \n");
    printf("======================================\n");
    printf("Text Editor Sederhana Berbasis Console\n");
    printf("Dibuat dengan Bahasa C\n");
    printf("======================================\n\n");
    
    TextBuffer *buffer = buffer_create();
    if (!buffer) {
        printf("Error: Gagal membuat buffer!\n");
        return 1;
    }
    
    editor_run(buffer);
    
    buffer_destroy(buffer);
    
    return 0;
}
