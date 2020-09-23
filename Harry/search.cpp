#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define SIZE 100


int main() {
    FILE* file_ptr;
    file_ptr = fopen("harry.txt", "r");

    char Harry[] = "harry";
    int len_h = strlen(Harry);
    char Potter[] = "potter";
    int len_p = strlen(Potter);
    char boy_who_lived[] = "boy who lived";
    int len_bwl = strlen(boy_who_lived);

    int c_Harry = 0;
    int c_Potter = 0;
    int c_boy_who_lived = 0;

    char str[SIZE];


    if (file_ptr != NULL) {
        printf("File was found\n");
        while (fgets(str, SIZE, file_ptr) != NULL) {
            int i = 0, j = 0;
            int len_str = strlen(str);
            _strlwr(str);

            while ((i <= len_str - len_h) & (j < len_h) || (i <= len_str - len_p) & (j < len_p) || (i <= len_str - len_bwl) & (j < len_bwl)) {
                if (str[i + j] == Harry[j]) {
                    j++;
                    if (j == len_h) {
                        c_Harry++;
                        i++;
                        j = 0;
                    }
                }
                else if (str[i + j] == Potter[j]) {
                    j++;
                    if (j == len_p) {
                        c_Potter++;
                        i++;
                        j = 0;
                    }
                }
                else if (str[i + j] == boy_who_lived[j]) {
                    j++;
                    if (j == len_bwl) {
                        c_boy_who_lived++;
                        i++;
                        j = 0;
                    }
                }
                else {
                    i++;
                    j = 0;
                }
            }
        }

    }
    else {
        printf("file not found");
    }

    printf("Harry: %d\n", c_Harry);
    printf("Potter: %d\n", c_Potter);
    printf("Boy who lived: %d\n", c_boy_who_lived);
    return 0;
}