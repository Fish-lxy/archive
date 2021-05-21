#include"Stack.h"
#include<stdio.h>
#include "app_line_editor.h"

int lineEdit_main_start(FILE *out) {
	if (out == NULL)
		return -1;

	Stack line;
	initStack(&line);
	printf("print:\n");
	char buffer[100];
	char ch;
	ch = getchar();
	while (ch != '\0') {
		while (ch != '\0' && ch != '\n') {
			if (ch == '#') {
				pop(&line, NULL);
			}
			else if (ch == '@') {
				clear(&line);
			}
			else {
				push(&line, ch);
			}
			ch = getchar();
		}
		push(&line, '\0');

		ElemType *p = line.BASE;
		int i;
		for (i = 0; isEmpty(&line) == 0; i++) {
			buffer[i] = *p;
			p++;
		}

		fputs(buffer, out);
		if (out == stdout)
			putchar('\n');
		clear(&line);
		if (ch != '\0')
			ch = getchar();
	}

}
