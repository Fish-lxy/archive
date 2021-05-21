#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void initWindow();
void mainScreen();
void userScreen();
void bookScreen();
void loadFile();
void saveFile();
void newUserSave(char *, char *);
void newBookSave(char *, char *);
struct User *searchUser(char *);
struct Book *searchByNum(char *n);
struct Book *searchByName(char *na);
void userRegister();
int userLogin();
void userPasswordChange();
void addBook();
void putAllBook();
void searchBook();
void deleteBook();
void changeBook();

FILE *fp_book;
FILE *fp_user;

struct Book {
    char num[20];
    char name[20];
    struct Book *next;
};
struct User {
    char username[25];
    char password[25];
    struct User *next;
};

struct Book *HEAD_book; //书籍链表首地址
struct User *HEAD_user; //用户链表首地址
int LogStatus = 0;      //登录状态，1为以登录
char LogUser[10];       //已经登录的用户的用户名
char LogPassword[10];   //已经登录的用户的密码

int main(void) {
    initWindow();
    loadFile();
    mainScreen();
}
void initWindow() //初始化窗口大小和尺寸
{
    system("title 图书管理系统   作者：计科1902李欣雨");
    system("color 70");
    system("mode con cols=60 lines=25");
}
void mainScreen() //主页选项处理
{
    int i;
    while (1) {
        printf("******************************\n");
        printf("         图书管理系统\n\n");
        printf("          1.书籍管理\n");
        printf("          2.用户管理\n");
        printf("          0.结束\n\n");
        if (LogStatus == 1)
            printf("当前用户：%s\n", LogUser);
        else
            printf("当前未登录\n");
        printf("******************************\n");
        printf("选择一个选项：");
        scanf("%d", &i);
        switch (i) {
        case 1:
            system("cls");
            bookScreen();
            break;
        case 2:
            system("cls");
            userScreen();
            break;
        case 0:
            exit(0);
        default:
            printf("请输入正确的选项！\n");
            system("pause");
            system("cls");
        }
    }
}
void userScreen() //用户管理选项处理
{
    int i;
    while (1) {
        printf("******************************\n");
        printf("           用户管理\n\n");
        printf("1.登录\n");
        printf("2.注册\n");
        printf("3.修改密码\n");
        printf("0.返回\n\n");
        if (LogStatus == 1)
            printf("当前用户：%s\n", LogUser);
        else
            printf("当前未登录\n");
        printf("******************************\n");
        printf("选择一个选项：");
        scanf("%d", &i);
        switch (i) {
        case 1:
            userLogin();
            break;
        case 2:
            userRegister();
            break;
        case 3:
            userPasswordChange();
            break;
        case 0:
            system("cls");
            return;
        default:
            printf("请输入正确的选项！\n");
            system("pause");
            system("cls");
        }
    }
}
void bookScreen() //书籍管理选项处理
{
    if (LogStatus == 1) {
        int i;
        while (1) {
            printf("******************************\n");
            printf("           书籍管理\n\n");
            printf("1.添加书籍\n");
            printf("2.列出所有书籍\n");
            printf("3.查找书籍\n");
            printf("4.删除书籍\n");
            printf("5.修改书籍信息\n");
            printf("0.返回\n\n");
            printf("******************************\n");
            printf("选择一个选项：");
            scanf("%d", &i);
            switch (i) {
            case 1:
                addBook();
                break;
            case 2:
                putAllBook();
                break;
            case 3:
                searchBook();
                break;
            case 4:
                deleteBook();
                break;
            case 5:
                changeBook();
                break;
            case 0:
                system("cls");
                return;
            default:
                printf("请输入正确的选项！\n");
                system("pause");
                system("cls");
            }
        }
    } else {
        printf("未登录！\n必须先登录账号才能管理图书。\n\n");
        system("pause");
        system("cls");
    }
}
void loadFile() //读取文件并初始化链表
{
    HEAD_user = (struct User *)malloc(sizeof(struct User));
    HEAD_user->next = NULL;
    fp_user = fopen("userdata", "rb");
    if (fp_user == NULL) {
        fp_user = fopen("userdata", "wb");
        printf("  未找到用户文件！\n");
        printf("  将创建新的用户文件.\n\n");
        fclose(fp_user);
        system("pause");
        system("cls");
    } else {
        struct User *p1, *p2;
        p1 = (struct User *)malloc(sizeof(struct User));
        p2 = (struct User *)malloc(sizeof(struct User));
        p1 = HEAD_user;
        while (fread(p2, sizeof(struct User), 1, fp_user)) {
            p1->next = p2;
            p2 = p2->next;
            p2 = (struct User *)malloc(sizeof(struct User));
            p1 = p1->next;
        }
        fclose(fp_user);
    }

    HEAD_book = (struct Book *)malloc(sizeof(struct Book));
    HEAD_book->next = NULL;
    fp_book = fopen("database", "rb");
    if (fp_book == NULL) {
        fp_book = fopen("database", "wb");
        printf("  未找到数据文件！\n");
        printf("  将创建新的数据文件.\n\n");
        fclose(fp_book);
        system("pause");
        system("cls");
    } else {
        struct Book *p1, *p2;
        p1 = (struct Book *)malloc(sizeof(struct Book));
        p2 = (struct Book *)malloc(sizeof(struct Book));
        p1 = HEAD_book;
        while (fread(p2, sizeof(struct Book), 1, fp_book)) {
            p1->next = p2;
            p2 = p2->next;
            p2 = (struct Book *)malloc(sizeof(struct Book));
            p1 = p1->next;
        }
        fclose(fp_book);
    }
}
void saveFile() //将内存中链表的信息保存到文件
{
    fp_user = fopen("userdata", "wb");
    struct User *temp1 = HEAD_user->next;
    while (temp1 != NULL) {
        fwrite(temp1, sizeof(struct User), 1, fp_user);
        temp1 = temp1->next;
    }
    fclose(fp_user);

    fp_book = fopen("database", "wb");
    struct Book *temp2 = HEAD_book->next;
    while (temp2 != NULL) {
        fwrite(temp2, sizeof(struct Book), 1, fp_book);
        temp2 = temp2->next;
    }
    fclose(fp_book);
}
void newUserSave(char *un, char *pw) //新建用户，并将新用户首地址接到链表尾
{
    struct User *p1, *p2;
    p1 = (struct User *)malloc(sizeof(struct User));
    p2 = (struct User *)malloc(sizeof(struct User));
    p1 = HEAD_user;
    while (p1->next != NULL)
        p1 = p1->next;
    strcpy(p2->username, un);
    strcpy(p2->password, pw);
    p2->next = NULL;
    p1->next = p2;
    saveFile();
}
void newBookSave(char *n, char *na) //新建书籍，并将新用户首地址接到链表尾
{
    struct Book *p1, *p2;
    p1 = (struct Book *)malloc(sizeof(struct Book));
    p2 = (struct Book *)malloc(sizeof(struct Book));
    p1 = HEAD_book;
    while (p1->next != NULL)
        p1 = p1->next;
    strcpy(p2->num, n);
    strcpy(p2->name, na);
    p2->next = NULL;
    p1->next = p2;
    saveFile();
}
struct User *searchUser(char *na) //依据用户名查找用户信息，返回用户首地址
{
    struct User *temp;
    temp = HEAD_user;
    while (temp != NULL) {
        if (strcmp(na, temp->username) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
struct Book *searchByNum(char *n) //依据书号查找书籍信息，返回书籍首地址
{
    struct Book *temp;
    temp = HEAD_book;
    while (temp != NULL) {
        if (strcmp(n, temp->num) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
struct Book *searchByName(char *na) //依据书籍名查找书籍信息，返回书籍首地址
{
    struct Book *temp;
    temp = HEAD_book;
    while (temp != NULL) {
        if (strcmp(na, temp->name) == 0)
            return temp;
        temp = temp->next;
    }
    return NULL;
}
void userRegister() //注册用户处理
{
    char username[20];
    char password[20];
    struct User *reg;
    printf("输入新的用户名：");
    scanf("%s", username);
    reg = searchUser(username);
    if (reg != NULL) {
        printf("此用户已存在！");
        system("pause");
        system("cls");
        return;
    }
    printf("创建密码：");
    scanf("%s", password);
    newUserSave(username, password);
    printf("账户创建成功！\n");
    system("pause");
    system("cls");
}
int userLogin() //登录处理
{
    char username[20];
    char password[20];
    struct User *log;
    printf("输入用户名：");
    scanf("%s", username);
    log = searchUser(username);
    if (log == NULL) {
        printf("此用户不存在！\n");
        system("pause");
        system("cls");
        return 0;
    }
    printf("输入密码：");
    scanf("%s", password);
    if (strcmp(password, log->password) != 0) {
        printf("密码错误！\n");
        system("pause");
        system("cls");
        return 0;
    }
    strcpy(LogUser, username);
    strcpy(LogPassword, password);
    LogStatus = 1;
    printf("登录成功！\n");
    system("pause");
    system("cls");
    return 1;
}
void userPasswordChange() //修改密码处理
{
    char username[20];
    char password[20];
    struct User *cha;
    printf("输入要修改的用户名：");
    scanf("%s", username);
    cha = searchUser(username);
    if (cha == NULL) {
        printf("此用户不存在！");
        system("pause");
        system("cls");
        return;
    }
    printf("输入旧的密码：");
    scanf("%s", password);
    if (strcmp(password, cha->password) == 0) {
        printf("输入新的密码：");
        scanf("%s", password);
        strcpy(cha->password, password);
        printf("密码修改成功！\n");
        printf(" 用户： %s\n 新密码为：%s\n\n", cha->username, cha->password);
        saveFile();
        system("pause");
        system("cls");
        return;
    } else {
        printf("密码错误！\n");
        system("pause");
        system("cls");
        return;
    }
}
void addBook() //添加书籍处理
{
    char num[10];
    char name[10];
    printf("\n******************************\n");
    printf("输入新书的书名：");
    scanf("%s", name);
    printf("输入新书的书号：");
    scanf("%s", num);
    newBookSave(num, name);
    printf("成功添加新书！\n");
    printf(" 新书书号：%s\n", num);
    printf(" 新书名称：%s\n", name);
    system("pause");
    system("cls");
}
void putAllBook() //列出所有书籍处理
{
    struct Book *temp;
    temp = (struct Book *)malloc(sizeof(struct Book));
    temp = HEAD_book->next;
    system("cls");
    printf("******************************\n");
    printf("书号        书籍名\n");
    while (temp != NULL) {
        printf("%-10s 《%-s》\n", temp->num, temp->name);
        temp = temp->next;
    }
    printf("\n");
    system("pause");
    system("cls");
}
void searchBook() //寻找书籍处理
{
    struct Book *temp;
    temp = (struct Book *)malloc(sizeof(struct Book));
    int i;
    printf("\n******************************\n");
    printf("查找方式：\n 1.以书号查询\n 2.以书名查询\n 0.返回\n");
    printf("输入序号：");
    scanf("%d", &i);
    switch (i) {
    case 1: {
        char book[20];
        printf("输入要查询的书籍的书号：");
        scanf("%s", book);
        temp = searchByNum(book);
        if (temp == NULL)
            printf("\n没有此书籍！\n");
        else {
            printf("\n查询到的图书信息：\n");
            printf("书号        书籍名\n");
            printf("%-10s 《%-s》\n\n", temp->num, temp->name);
        }
        system("pause");
        system("cls");
        return;
    }
    case 2: {
        char book[20];
        printf("输入要查询的书籍的书名：");
        scanf("%s", book);
        temp = searchByName(book);
        if (temp == NULL)
            printf("\n没有此书籍！\n");
        else {
            printf("\n查询到的图书信息：\n");
            printf("书号        书籍名\n");
            printf("%-10s 《%-s》\n\n", temp->num, temp->name);
        }
        system("pause");
        system("cls");
        return;
    }
    case 0:
        system("cls");
        return;
    default:
        printf("请输入正确的选项！\n");
        system("pause");
        system("cls");
        return;
    }
}
void deleteBook() //删除书籍处理
{
    char num[10];
    char *e = "q";
    struct Book *exist;
    printf("输入要删除的书籍的书号：（输入q取消）");
    scanf("%s", num);
    exist = searchByNum(num);
    if (strcmp(e, num) == 0) {
        system("cls");
        return;
    } else if (exist == NULL) {
        printf("\n没有此书籍！\n");
        system("pause");
        system("cls");
        return;
    } else {
        struct Book *p1, *p2;
        p1 = HEAD_book;
        p2 = NULL;
        if (strcmp(p1->num, num) == 0) {
            HEAD_book = p1->next;
            printf("删除成功\n");
            return;
        }
        while (strcmp(p1->num, num) != 0) {
            p2 = p1;
            p1 = p1->next;
        }
        p2->next = p1->next;
        saveFile();
        printf("删除成功\n");
    }
    system("pause");
    system("cls");
}
void changeBook() //修改书籍名称处理
{
    char num[10];
    char name[10];
    char *i = "q";
    struct Book *cha;
    struct Book *exist;
    printf("输入要修改的书籍的书号：");
    scanf("%s", num);
    exist = searchByNum(num);
    if (strcmp(i, num) == 0) {
        system("cls");
        return;
    } else if (exist == NULL) {
        printf("\n没有此书籍！\n");
        system("pause");
        system("cls");
        return;
    } else {
        cha = searchByNum(num);
        printf("当前选定的书籍：\n");
        printf(" 书号：%s\n 书名：%s\n", cha->num, cha->name);
        printf("输入新的书名：（输入q取消）\n");
        scanf("%s", name);
        strcpy(cha->name, name);
        printf("修改成功\n");
        system("pause");
        system("cls");
        saveFile();
    }
}
