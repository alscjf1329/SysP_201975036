#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]) {
	char* name = argv[1];

	int idx = 0;
	// root�Ͻ�
	if (name[strlen(name) - 1] == '/') {
		printf("/\n");
		return 0;
	}
	// idx ������ / ���� index�� ����
	for (int i = 0; i < strlen(name); i++) {
		if (name[i] == '/') idx = i+1;
	}
	for (int i = idx; i < strlen(name); i++) {
		printf("%c", name[i]);
	}


	printf("\n");
	return 0;
}