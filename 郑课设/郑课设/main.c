#define _CRT_SECURE_NO_WARNINGS 1

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "operator.h"
#include "head.h"
#include "staff.h"
#include "department.h"

int main() {
    //���뻶ӭ����
    
    //��ʼ���������ݿ⣬Ա�����ݿ�
    Sta spc;
    Dep cpc;

    //��ʼ��
    initDep(&cpc);
    init_sta(&spc);
    home(&spc, &cpc);
    return 0;
}


