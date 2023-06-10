#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 4096

int number_lines = 0;
int show_ends = 0;
int show_tabs = 0;
int show_nonprint = 0;
int squeeze_blank = 0;
int main(int argc, char* argv[]) {
    int opt;
    while ((opt = getopt(argc, argv, "nbsETv")) != -1) {
        switch (opt) {
            case 'n':
                number_lines = 1;
                break;
            case 'b':
                number_lines = 1;
                squeeze_blank = 1;
                break;
            case 'E':
                show_ends = 1;
                break;
            case 'T':
                show_tabs = 1;
                break;
            case 'v':
                show_nonprint = 1;
                break;
            case 's':
                squeeze_blank = 1;
                break;
            default:
                fprintf(stderr, "Invalid option: -%c\n", optopt);
                return 1;
        }
    }
    // �Է� ���� ������ �ϳ��� ������
    if (optind >= argc) {
        fprintf(stderr, "Usage: %s [options] <file>\n", argv[0]);
        return 1;
    }

    const char* filename = argv[optind];
    display_file(filename);

    return 0;
}

// ���� ����ϴ� �Լ�
void display_file(const char* filename) {
    FILE* file = fopen(filename, "r");
    // ���� ���� �� ���� ó��
    if (file == NULL) {
        perror("fopen");
        return;
    }
    char buffer[BUFFER_SIZE];
    int lineNums = 1;
    int firstNL = 1;
    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        // s option (�������� ������ �ϳ��� �ٿ���)�̸鼭 '\n'�� ���
        if (squeeze_blank && buffer[0] == '\n') {
            // b option�� �����ϱ� ����
            if (!number_lines) {
                if (firstNL) {
                    firstNL = 0;
                    printf("\n");
                }
            }
            else {
                printf("\n");
            }
            continue;
        }

        firstNL = 1;
        if (number_lines) {
            printf("%6d  ", lineNums++);  // ���� ��ȣ ���
        }
        int i = 0;
        while (buffer[i] != '\0') {
            if (show_ends && buffer[i] == '\n') {
                printf("$\n");
            }
            else if (show_tabs && buffer[i] == '\t') {
                printf("^I");
            }
            else if (show_nonprint) {
                if (buffer[i] == '\n' || buffer[i] == '\t') {
                    printf("%c", buffer[i]);
                }
                else if (buffer[i] < 32 || buffer[i] > 126) {
                    printf("^%c", buffer[i] + 64);
                }
                else {
                    putchar(buffer[i]);
                }

            }
            else {
                putchar(buffer[i]);
            }
            i++;
        }
    }

    fclose(file);
}