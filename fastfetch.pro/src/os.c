#include <stdio.h>
#include <string.h>
#include "os.h"

static void read_value(const char *key, char *out) {
    FILE *f = fopen("/etc/os-release", "r");
    if (!f) {
        strcpy(out, "unknown");
        return;
    }

    char line[256];
    while (fgets(line, sizeof(line), f)) {
        if (strncmp(line, key, strlen(key)) == 0) {
            char *v = strchr(line, '=');
            if (!v) break;

            v++;
            if (*v == '"') v++;
            strcpy(out, v);
            out[strcspn(out, "\"\n")] = 0;
            break;
        }
    }
    fclose(f);
}

void get_os(char *out) {
    read_value("PRETTY_NAME", out);
}

void get_os_id(char *out) {
    read_value("ID", out);
}
