#include <stdio.h>
#include <stdlib.h>
#include <string.h>

static char *substring(char *s, int p, int l) {
    char *buff;
    buff = malloc(sizeof(char) * l);
    for(int i=p,j=0; i<p+l; ++i,++j) {
        buff[j] = s[i];
    }
    return buff;
}


int main(void) {
    printf("%s\n", substring("HelloMine",1,3));
    return 0;
}

