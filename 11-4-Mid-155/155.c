struct stack
{
    int dat;
    int min;
};

typedef struct 
{
    //正常 stack
    struct  stack stackDat[10000];
    int     stackTop;
} MinStack;


MinStack* minStackCreate() 
{
    MinStack* newStack      = (MinStack *) malloc(sizeof(MinStack));
    newStack->stackTop      = 0;
    return newStack;
}

void minStackPush(MinStack* obj, int val) 
{
    //先压如数据栈
    obj->stackDat[obj->stackTop].dat = val;
    
    //当前值 小于等于 辅助栈顶值
    if(!obj->stackTop || val <= obj->stackDat[obj->stackTop-1].min )
    {
        obj->stackDat[obj->stackTop].min = val;
    }
    else
    {
        obj->stackDat[obj->stackTop].min = obj->stackDat[obj->stackTop-1].min;
    }
    obj->stackTop++;
}

void minStackPop(MinStack* obj)
{
    obj->stackTop--;
}

int minStackTop(MinStack* obj) 
{
    return obj->stackDat[obj->stackTop-1].dat; 
}

int minStackGetMin(MinStack* obj) 
{
    return obj->stackDat[obj->stackTop-1].min; 
}

void minStackFree(MinStack* obj) 
{
    free(obj);
}
