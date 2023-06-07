#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

// �Լ� ����
void print_last_n_lines(FILE* file, int n);
void print_last_n_chars(FILE* file, int n);
void print_quiet(FILE* file);

int main(int argc, char* argv[]) {
    // �ɼ� �ʱ�ȭ
    int n = 10; // �⺻������ 10�� ���
    int c = 0;  // ���� �� �ɼ� �ʱ�ȭ
    int q = 0;  // ������ ��� �ɼ� �ʱ�ȭ

    // ����� �μ� ó��
    int opt;
    while ((opt = getopt(argc, argv, "n:c:q")) != -1) {
        switch (opt) {
        case 'n':
            n = atoi(optarg);
            break;
        case 'c':
            c = atoi(optarg);
            break;
        case 'q':
            q = 1;
            break;
        default:
            fprintf(stderr, "����: %s [-n ����] [-c ����] [-q] ����...\n", argv[0]);
            return 1;
        }
    }

    // ���� ó��
    for (int i = optind; i < argc; i++) {
        char* filename = argv[i];

        // ���� ����
        FILE* file = fopen(filename, "r");
        if (file == NULL) {
            perror("���� ���� ����");
            continue;
        }

        // ���ϸ� ���
        if (!(argc - optind == 1) && !q) {
            printf("==> %s <==\n", filename);
        }

        // ���ǿ� ���� ���
        if (c > 0) {
            // -c �ɼ����� ������ ���� ����ŭ ���
            print_last_n_chars(file, c);
        }
        else {
            // -n �ɼ����� ������ �� ����ŭ ���
            print_last_n_lines(file, n);
        }

        // ���� �ݱ�
        fclose(file);

        // ���� �� ������ ���� ���� ���
        if (!(argc - i == 1) && !q) {
            printf("\n");
        }
    }

    return 0;
}

// ������ ���Ͽ��� ������ n���� ����ϴ� �Լ�
void print_last_n_lines(FILE* file, int n) {
    char buffer[BUFFER_SIZE][BUFFER_SIZE];
    int count = 0;

    // ������ ������ �����鼭 ���۸� ��ȯ��Ű�鼭 �ֱ� n�� ����
    while (fgets(buffer[count % n], BUFFER_SIZE, file) != NULL) {
        count++;
    }

    int start = (count > n) ? (count % n) : 0;
    int lines_to_print = (count > n) ? n : count;

    for (int i = 0; i < lines_to_print; i++) {
        printf("%s", buffer[(start + i) % n]);
    }
}

// ������ ���Ͽ��� ������ n���� ���ڸ� ����ϴ� �Լ�
void print_last_n_chars(FILE* file, int n) {
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);

    int chars_to_read = (n < file_size) ? n : file_size;
    char buffer[BUFFER_SIZE];

    fseek(file, -chars_to_read, SEEK_END);

    while (fgets(buffer, BUFFER_SIZE, file) != NULL) {
        printf("%s", buffer);
    }
}

