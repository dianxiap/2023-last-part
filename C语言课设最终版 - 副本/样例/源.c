#define _CRT_SECURE_NO_WARNINGS 1

//��д�ߣ����庯

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "headdefine.h"
#include "select_project.h"
#include "project.h"
#include "student.h"

int main() {
    //���뻶ӭ����
    //ѧ�����ݿ⣬�γ����ݿ⣬ѡ�μ�¼
    Stu spc;
    Cou cpc;
    Sel lpc;

    //��ʼ��
    initCou(&cpc);
    init_Sel(&lpc);
    init_stu(&spc);
    home(&spc,&cpc,&lpc);
    return 0;
}


 