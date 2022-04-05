#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    char strin[255];
    memset(strin, '\0', 255);
    while(fgets(strin, sizeof strin, stdin) != NULL) {
        int inx = 0;
        while(strin[inx] != '\n') {
            printf("%c", strin[inx]);
            ++inx;
        }
        printf("\n");
    }
    return 0;
}
