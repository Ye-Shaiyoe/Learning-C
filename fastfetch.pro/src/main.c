#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "colors.h"
#include "os.h"
#include "cpu.h"
#include "memory.h"
#include "uptime.h"
#include "ascii.h"
#include "gpu.h"
#include "kernel.h"
#include "version.h"
#include "shell.h"

void get_shell(char *shell) {
    const char *s = getenv("SHELL");
    if (s) {
        strcpy(shell, s);
    } else {
        strcpy(shell, "unknown");
    }
}

int main() {
    char os[128], os_id[64], cpu[128], gpu[256], kernel[128], shell[128];
    long ram_used, ram_total;
    int h, m;

    get_os(os);
    get_os_id(os_id);
    get_cpu(cpu);
    get_gpu(gpu);
    get_kernel(kernel);
    get_shell(shell);
    get_memory(&ram_used, &ram_total);
    get_uptime(&h, &m);
    print_ascii(os_id);

    #define LABEL(color, text) color text C_RESET

    printf(LABEL(C_BLUE,"OS:      ") "%s\n", os);
    printf(LABEL(C_BLUE,"Kernel:   ") "%s\n", kernel);
    printf(LABEL(C_BLUE,"CPU:      ") "%s\n", cpu);
    printf(LABEL(C_BLUE,"GPU:      ") "%s\n", gpu);
    printf(LABEL(C_BLUE,"RAM:      ") "%ldMB / %ldMB\n", ram_used, ram_total);
    printf(LABEL(C_BLUE,"Uptime:   ") "%dh %dm\n", h, m);
    printf(LABEL(C_BLUE,"Shell:    ") "%s\n", shell);


    return 0;
}
