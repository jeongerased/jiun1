#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//������ ���� 500�ް� �̻� ������ ������ �ʿ��ߴ�...
int main() {
	const char* file_d = "test.dat";//���� �̸�
	char* buf = "500�ް� �̻� ���������� �����\n";//32����Ʈ
	const int size = 16384000;//32*32=1024(1Ű�ι���Ʈ)*1024*5 = ��Ȯ�� 500�ް�;;

	FILE* fpd = fopen(file_d, "wb");//���̳ʸ� ������
	if (fpd == NULL) return;
	
	printf("����...\n");
	for (int i = 0; i < size; i++) {
		if (i == (size * 25 / 100)) printf("25%% �Ϸ�...\n");
		if (i == (size * 50 / 100)) printf("50%% �Ϸ�...\n");
		if (i == (size * 75 / 100)) printf("75%% �Ϸ�...\n");
		fwrite(buf, sizeof(char), 32, fpd);
	}
	printf("�ϼ�...\n");
	fclose(fpd);

	return 0;
}