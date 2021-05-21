#include"Stack.h"

int initStack(Stack* newstack) {//初始化新栈
    if (newstack == NULL)
        return NullPointerError;
    newstack->BASE = (ElemType*)malloc(sizeof(ElemType) * INIT_SIZE);
    if (newstack->BASE == NULL)
        return AllocError;

    newstack->TOP = newstack->BASE;
    //初始化数据
    newstack->init = 1;
    newstack->length = 0;
    newstack->capacity = 5;
    return newstack->init;
}
int push(Stack* stack,ElemType inserted) {//入栈
    if (stack == NULL || stack->BASE == NULL)
        return NullPointerError;
    if (stack->init != 1)
        return UninitError;

    ElemType* newbase = NULL;
    ElemType* p1 = NULL;
    ElemType* p2 = NULL;

    int position;
    if (stack->length == 0)
        position = 0;
    else position=stack->length;

    //容量动态增长
    //当容量剩余2时，增长5
    if (stack->capacity - stack->length <= 2) {
        newbase = (ElemType*)realloc(stack->BASE, sizeof(ElemType) * (stack->capacity + ADD_SIZE));
        if (newbase == NULL)
            return AllocError;
        stack->capacity += ADD_SIZE;
        stack->BASE = newbase;
        stack->TOP = newbase + stack->length + 1;
    }
    p1 = &(stack->BASE[position]);
    if (stack->length == 0) {
        *p1 = inserted;
    }
    if (stack->length >= 1) {
        for (p2 = &(stack->BASE[stack->length - 1]); p2 >= p1; p2--) {
            *(p2 + 1) = *p2;
        }
        *p1 = inserted;
    }
    stack->TOP++;
    stack->empty = 0;
    stack->length++;
    return NoError;
}
int pop(Stack* stack, ElemType* out) {//出栈
    if (stack == NULL || stack->BASE == NULL) {
        if (out != NULL)
            *out = 0;
        return NullPointerError;
    }
    if (stack->init != 1) {
        if (out != NULL)
            *out = 0;
        return UninitError;
    }
    if (stack->length == 0) {
        if (out != NULL)
            *out = 0;
        return DataIllegalError;
    }

    ElemType* p1 = NULL;
    ElemType* p2 = NULL;

    int position = stack->length - 1;
    if (out != NULL)
        *out = stack->BASE[position];
    p1 = &(stack->BASE[position]);
    if (position == stack->length - 1) {
        *p1 = 0;
    }
    else {
        p2 = &(stack->BASE[stack->length - 1]);//获取表尾元素地址
        for (++p1; p1 <= p2; p1++) {
            *(p1 - 1) = *p1;
        }
    }

    stack->TOP--;
    stack->length--;
    if (stack->length == 0)
        stack->empty = 1;
    
    return NoError;
}
int getTop(Stack* stack, ElemType* out) {//获取栈顶元素
    if (stack == NULL || stack->BASE == NULL)
        return NullPointerError;
    if (stack->init != 1)
        return UninitError;
    if (stack->empty == 1)
        return NotExistError;
    if (stack->length == 0)
        return DataIllegalError;

    int position = stack->length - 1;
    if (out != NULL)
        *out = stack->BASE[position];
    return NoError;
}
int clear(Stack* stack) {//清除栈内数据
    if (stack == NULL || stack->BASE == NULL)
        return NullPointerError;
    if (stack->init != 1)
        return UninitError;
    for (int i = 0; i < stack->length; i++)
        stack->BASE[i] = 0;

    stack->TOP = stack->BASE;
    stack->empty = 1;
    stack->length = 0;
    return NoError;
}
int destory(Stack* stack) {//销毁栈
    clear(stack);
    stack->capacity = 0;
    stack->init = 0;
    free(stack->BASE);
    stack->BASE = NULL;
    stack->TOP = NULL;
    return NoError;
}
int isEmpty(Stack* stack) {//判空
    if (stack == NULL || stack->BASE == NULL)
        return NullPointerError;
    if (stack->init != 1)
        return UninitError;
    return stack->empty;
}
int getLength(Stack* stack) {//获取长度
    if (stack == NULL || stack->BASE == NULL)
        return NullPointerError;
    if (stack->init != 1)
        return UninitError;
    return stack->length;
}
int output(Stack* stack) {
    if (stack == NULL || stack->BASE == NULL)
        return NullPointerError;
    if (stack->init != 1)
        return UninitError;
    if (stack->empty == 1)
        return NotExistError;

    for (int i = 0; i < stack->length; i++)
        printf("第%d个元素的值：%d\n", i, stack->BASE[i]);
    return NoError;
}
