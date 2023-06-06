#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>

int main(int argc, char* argv[]) {
    int opt;
    char* separator = "\t"; // �⺻ ������

    // �ɼ� ó���� ���� ����
    while ((opt = getopt(argc, argv, "s:")) != -1) {
        switch (opt) {
        case 's':
            separator = optarg; // -s �ɼ��� ���ڸ� �����ڷ� ����
            break;
        case '?':
            fprintf(stderr, "�߸��� �ɼ��Դϴ�.\n");
            return 1;
        }
    }

    // ���ϸ� ���ڰ� ���� ���
    if (optind >= argc) {
        fprintf(stderr, "����: %s [-s ������] ����...\n", argv[0]);
        return 1;
    }

    // ���� ó��
    int lineNumber = 1;
    for (int i = optind; i < argc; i++) {
        FILE* file = fopen(argv[i], "r");
        if (file == NULL) {
            fprintf(stderr, "������ �� �� �����ϴ�: %s\n", argv[i]);
            continue;
        }

        char line[256];
        while (fgets(line, sizeof(line), file) != NULL) {
            printf("%d%s%s", lineNumber, separator, line);
            lineNumber++;
        }

        fclose(file);
    }

    return 0;
}
