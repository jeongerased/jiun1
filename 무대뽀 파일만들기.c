#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>

//과제를 위해 500메가 이상 데이터 파일이 필요했다...
int main() {
	const char* file_d = "test.dat";//파일 이름
	char* buf = "500메가 이상 데이터파일 만들기\n";//32바이트
	const int size = 16384000;//32*32=1024(1키로바이트)*1024*5 = 정확히 500메가;;

	FILE* fpd = fopen(file_d, "wb");//바이너리 쓰기모드
	if (fpd == NULL) return;
	
	printf("시작...\n");
	for (int i = 0; i < size; i++) {
		if (i == (size * 25 / 100)) printf("25%% 완료...\n");
		if (i == (size * 50 / 100)) printf("50%% 완료...\n");
		if (i == (size * 75 / 100)) printf("75%% 완료...\n");
		fwrite(buf, sizeof(char), 32, fpd);
	}
	printf("완성...\n");
	fclose(fpd);

	return 0;
}