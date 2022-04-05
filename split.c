#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <errno.h>

char **r_str(char *str, uint8_t size) {
    char **res = malloc(sizeof(char *) * size);
    char *split = strtok(str, " ");
    uint8_t inx = 0;
    while(split) {
        res[inx] = strdup(split);
        split = strtok(NULL, " ");
        ++inx;
    }
    return res;
}

int main(void) {
    fprintf(stdout, "%s\n", strerror(errno));
    return(-1);

    char a[100] = "Hello Nama Saya Arson Marianus";
    char **xy = r_str(a, 5);

    for(uint8_t i = 0; i < 5; ++i) {
        printf("%s\n", xy[i]);
    }

    free(xy);
    return 0;
}
