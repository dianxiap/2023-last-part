#define _CRT_SECURE_NO_WARNINGS 1
#include "operator.h"

//��ʼҳ��
void home(Sta* spc, Dep* cpc) {
    printf("\n-------------------------��ӭ���벿��Ա������ϵͳ��----------------------");
    int h;
    printf("\n\n                        ��ѡ����Ҫ���еĲ�����");
    printf("\n\n                             1.Ա������");
    printf("\n                             2.���Ų���");
    printf("\n                             3.�˳�ϵͳ");
    printf("\n                                                      ");
    printf("\n                        �����룺");
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

