#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

int main() {
    srand(time(NULL));
    printf("\033[0;32m");
    
    for(int i = 0; i < 1000000; i++) {
        int bit = rand() % 2;
        printf("%d", bit);
        
        if((i + 1) % 273 == 0) {
            printf("\n");
        }
        
        fflush(stdout);
        
    }
    
    printf("\033[0m\n");
    // usleep(100);            // <-Optional: boleh di uncomment hehe~
    return 0;
}
