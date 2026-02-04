#include "text_editor.h"

// Cari teks mulai dari baris tertentu
// Return: nomor baris yang ditemukan (0-indexed), atau -1 jika tidak ditemukan
int search_text(TextBuffer *buffer, const char *search_str, int start_line) {
    if (!buffer || !search_str || start_line < 0) return -1;
    
    for (int i = start_line; i < buffer->line_count; i++) {
        if (strstr(buffer->lines[i], search_str) != NULL) {
            return i;
        }
    }
    
    return -1;
}

// Replace teks
// Return: jumlah penggantian yang dilakukan
int replace_text(TextBuffer *buffer, const char *search_str, const char *replace_str, int replace_all) {
    if (!buffer || !search_str || !replace_str) return 0;
    
    int replace_count = 0;
    
    for (int i = 0; i < buffer->line_count; i++) {
        char *pos = strstr(buffer->lines[i], search_str);
        
        while (pos != NULL) {
            // Buat string baru dengan hasil replace
            size_t search_len = strlen(search_str);
            size_t replace_len = strlen(replace_str);
            size_t old_len = strlen(buffer->lines[i]);
            size_t new_len = old_len - search_len + replace_len;
            
            char *new_line = (char*)malloc((new_len + 1) * sizeof(char));
            if (!new_line) return replace_count;
            
            // Copy bagian sebelum search_str
            size_t prefix_len = pos - buffer->lines[i];
            strncpy(new_line, buffer->lines[i], prefix_len);
            
            // Copy replace_str
            strcpy(new_line + prefix_len, replace_str);
            
            // Copy bagian setelah search_str
            strcpy(new_line + prefix_len + replace_len, pos + search_len);
            
            // Ganti baris dengan yang baru
            free(buffer->lines[i]);
            buffer->lines[i] = new_line;
            
            replace_count++;
            buffer->modified = 1;
            
            // Jika replace_all, cari kemunculan berikutnya
            if (replace_all) {
                pos = strstr(buffer->lines[i] + prefix_len + replace_len, search_str);
            } else {
                break;
            }
        }
        
        // Jika hanya replace sekali dan sudah ketemu, berhenti
        if (!replace_all && replace_count > 0) {
            break;
        }
    }
    
    return replace_count;
}

// Tampilkan semua hasil pencarian
void search_display_results(TextBuffer *buffer, const char *search_str) {
    if (!buffer || !search_str) return;
    
    int found_count = 0;
    
    printf("\nHasil pencarian untuk '%s':\n", search_str);
    printf("====================================\n");
    
    for (int i = 0; i < buffer->line_count; i++) {
        if (strstr(buffer->lines[i], search_str) != NULL) {
            printf("%4d | %s\n", i + 1, buffer->lines[i]);
            found_count++;
        }
    }
    
    if (found_count == 0) {
        printf("Tidak ditemukan.\n");
    } else {
        printf("====================================\n");
        printf("Ditemukan di %d baris\n", found_count);
    }
}