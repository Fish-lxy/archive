#include"Stack.h"
#include<stdio.h>

int Compare(char a, char b) {
	if ((a == '(' && b != ')') || (a == '[' && b != ']') || (a == '{' && b != '}')) {
		printf("左右不匹配\n");
		return 0;
	}
	else return 1;
}
void Count(Stack *s,char *str) {
	char out;
	for (int i = 0; str[i] != '\0'; i++) {
		if (str[i] == '(' || str[i] == '[' || str[i] == '{') {
			push(s, str[i]);
			continue;
		}
		if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
			if (isEmpty(s) != 0) {
				printf("右括号多余\n");
				return;
			}
			else
				pop(s, &out);
			if (Compare(out, str[i]) != 0);
			else {
				printf("左右不匹配\n");
				return;
			}
		}
	}
	if (isEmpty(s) == 0) {
		printf("左括号多余\n");
		
	}else printf("OK\n");

}

int brackets_main_start() {
	Stack brackets;
	initStack(&brackets);
	char str[100];
	fgets(str, 100, stdin);
	Count(&brackets, str);
	clear(&brackets);
	return 0;
}