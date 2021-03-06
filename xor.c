#include <stdio.h>

void main(int argc, char *argv[]) {
    FILE *fi, *fo;
    char *cp;
    int c;

    if ((cp = argv[1]) && *cp != '\0') {
        if ((fi = fopen(argv[2], "rb")) != NULL) {

            while ((c = getc(fi)) != EOF) {
                if (!*cp) cp = argv[1];
                c ^= *(cp++);
                putc(c, fo); /* lookup putc */
            }
        }
        fclose(fi);
    }
}

