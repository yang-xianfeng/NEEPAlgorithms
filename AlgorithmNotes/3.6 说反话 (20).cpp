#include <cstdio>
#include <cstring>

int main() {
    char str[90];
    gets(str);
    int length = strlen(str);
    char res[90][90];
    int m = 0, n = 0;
    for (int i = 0; i < length; i++) {
        if (str[i] != ' ') {
            res[m][n++] = str[i];
        } else {
            res[m][n] = '\0';
            m++;
            n = 0;
        }
    }
    for (int i = m; i >= 0; i--) {
        printf("%s", res[i]);
        if (i > 0)
            printf(" ");
    }
    return 0;
}
