#include<cstdio>
#include<cstdlib>
#include<cstring>
#pragma warning(disable:4996)

char FilePath[100];//文件路径
int FileLength=0;//文件大小
char* FileBuffer;//文件内容
size_t FileReadResult;//文件读取结果
FILE *fp;//文件指针

int main(int argc, char* argv[], char* envp[]){
	//控制参数为一个
	if (argc == 1) {
		printf("error:缺少参数!\n");
		return 0;
	}
	if (argc != 2) {
		printf("error:只能有一个参数!\n");
		return 0;
	}
	strcpy(FilePath,argv[1]);

	if (fp = fopen(FilePath, "rb")) {

		//获取文件大小
		fseek(fp, 0, SEEK_END);
		FileLength = ftell(fp);

		//分配内存以存储文件
		FileBuffer = (char*)malloc(sizeof(char)*FileLength);
		if (FileBuffer == NULL) {
			printf("error:内存错误!\n");
			return 0;
		}

		//读取文件存入内存
		fseek(fp, 0, SEEK_SET);
		FileReadResult = fread(FileBuffer, 1, FileLength, fp);
		if (FileReadResult != FileLength) {
			printf("error:读取错误!\n");
			return 0;
		}

		//输出文件内容
		int line = 2;
		printf("1     ");
		for (int i = 0; i < FileLength; i++) {
			printf("%c", FileBuffer[i]);
			if (FileBuffer[i] == '\n') {
				printf("%-6d", line);
				line++;
			}
		}
		
		free(FileBuffer);
		fclose(fp);
	}
	else {
		printf("error:文件不存在!\n");
		return 0;
	}
}