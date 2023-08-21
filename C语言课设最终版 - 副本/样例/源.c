#define _CRT_SECURE_NO_WARNINGS 1

//编写者：吴佩函

#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include "headdefine.h"
#include "select_project.h"
#include "project.h"
#include "student.h"

int main() {
    //进入欢迎界面
    //学生数据库，课程数据库，选课记录
    Stu spc;
    Cou cpc;
    Sel lpc;

    //初始化
    initCou(&cpc);
    init_Sel(&lpc);
    init_stu(&spc);
    home(&spc,&cpc,&lpc);
    return 0;
}


 