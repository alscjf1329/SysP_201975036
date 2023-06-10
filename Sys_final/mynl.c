#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

void addLineNumbers(FILE* file, int width, char* separator, int startNumber, int increment);
void printUsage(char* programName);
int isBlankLine(const char* line);

int main(int argc, char* argv[]) {
    FILE* file;
    int opt;
    int width = 6;
    char* separator = "\t";
    int startNumber = 1;
    int increment = 1;

    // options ó��
    while ((opt = getopt(argc, argv, "w:s:v:i:")) != -1) {
        switch (opt) {
        case 'w':
            width = atoi(optarg);
            break;
        case 's':
            separator = optarg;
            break;
        case 'v':
            startNumber = atoi(optarg);
            break;
        case 'i':
            increment = atoi(optarg);
            break;
        default:
            fprintf(stderr,"Usage: %s [-w width] [-s separator] [-v startNumber] [-i increment] [file]\n");
            exit(EXIT_FAILURE);
        }
    }
    // ���ϸ� ���ڰ� �ϳ��� ���� ���
    if (optind < argc) {
        // r���� argv[optind]�� ���� file�� ����
        file = fopen(argv[optind], "r");
        if (file == NULL) {
            perror("Error opening file");
            exit(EXIT_FAILURE);
        }
    }
    
    addLineNumbers(file, width, separator, startNumber, increment);
    printf("\n");
    fclose(file);
    return 0;
}

// ��ȣ�� �ٿ��� ���
void addLineNumbers(FILE* file, int width, char* separator, int startNumber, int increment) {
    char line[BUFSIZ];
    int lineNumber = startNumber;

    while (fgets(line, sizeof(line), file) != NULL) {
        if (!isBlankLine(line)) {
            printf("%*d%s%s", width, lineNumber, separator, line);
            lineNumber += increment;
        }
        else {
            printf("%s", line);
        }
    }
}

// �� ������ Ȯ�����ִ� �Լ�
int isBlankLine(const char* line) {
    int i = 0;
    // EOFȮ��
    while (line[i] != '\0') {
        if (line[i] != ' ' && line[i] != '\t' && line[i] != '\n' && line[i] != '\r') {
            return 0;
        }
        i++;
    }
    return 1;
}