int write_bytecode_test() {
    int nbytecode = 11;
    int i = 0;
    text[i++] = 0;
    text[i++] = 4;
    text[i++] = 99;
    text[i++] = IMM;
    text[i++] = 16;
    text[i++] = PUSH;
    text[i++] = IMM;
    text[i++] = 2;
    text[i++] = ADD;
    text[i++] = PUSH;
    text[i++] = EXIT;


    FILE *fp;
    char *filename = "src.cbc";
    fp = fopen(filename, "rb+");
    if (fp == NULL) {
        printf("ASM is not found! Create new one.\n");
    }
    fwrite(text, sizeof(int), nbytecode, fp);
    fclose(fp);
    for (int i = 0; i < nbytecode; i++) {
        printf("%d 0x%08X\n", text[i], text[i]);
    }
    printf("\n");
}