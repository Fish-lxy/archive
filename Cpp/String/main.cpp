#include<stdio.h>
#include "String.h"

int main(void) {
	String str1;
	String str2;
	String str3;

	strInit(&str1);
	strInit(&str2);
	strInit(&str3);


	strAssign(&str1, "abcdefgh");
	printf("str1:[%s]\n", str1.HEAD);

	strAssign(&str2, "cde");
	printf("str2:[%s]\n", str2.HEAD);

	strAssign(&str3, "ababa");
	printf("str3:[%s]\n", str3.HEAD);


	int pos = 0;
	strIndex(&str1, &str2, &pos);
	printf("\nstr2 in str1.position: %d\n", pos);
	

	int* strnext = (int*)malloc(sizeof(int) * str3.length);
	strGetNext(&str3, strnext);
	printf("str3.next: ");
	for (int i = 0; i < str3.length; i++)
		printf("%d ", strnext[i]);
	putchar('\n');

}