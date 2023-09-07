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
    //进入欢迎界面
    
    //初始化部门数据库，员工数据库
    Sta spc;
    Dep cpc;

    //初始化
    initDep(&cpc);
    init_sta(&spc);
    home(&spc, &cpc);
    return 0;
}


