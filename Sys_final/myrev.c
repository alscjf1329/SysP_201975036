#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void printReverse(FILE* file) {
    if (file == NULL) {
        printf("������ �� �� �����ϴ�.\n");
        return;
    }

    fseek(file, 0, SEEK_END);
    long size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char* buffer = (char*)malloc(size + 1);
    if (buffer == NULL) {
        printf("�޸� �Ҵ翡 �����߽��ϴ�.\n");
        return;
    }

    fread(buffer, 1, size, file);
    buffer[size] = '\0';

    for (long i = size - 1; i >= 0; i--) {
        putchar(buffer[i]);
    }

    free(buffer);
}

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("���� �̸��� �����ؾ� �մϴ�.\n");
        return 1;
    }

    for (int i = 1; i < argc; i++) {
        FILE* file = fopen(argv[i], "r");
        printReverse(file);
        fclose(file);
    }

    return 0;
}
