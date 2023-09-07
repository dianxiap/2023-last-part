#define _CRT_SECURE_NO_WARNINGS 1
#include "operator.h"

//开始页面
void home(Sta* spc, Dep* cpc) {
    printf("\n-------------------------欢迎进入部门员工管理系统！----------------------");
    int h;
    printf("\n\n                        请选择你要进行的操作：");
    printf("\n\n                             1.员工操作");
    printf("\n                             2.部门操作");
    printf("\n                             3.退出系统");
    printf("\n                                                      ");
    printf("\n                        请输入：");
    scanf("%d", &h);
    system("cls");

    switch (h) {
    case 1:
        sta_operate(spc, cpc);
        break;
    case 2:
        dep_operate(spc, cpc);
        break;
    default:
        system("cls");
        printf("BYE!");
        break;
    }
}

