#define _CRT_SECURE_NO_WARNINGS 1
#include "staff.h"

//初始化员工顺序表
void init_sta(Sta* pc)
{
    assert(pc);
    sta* ptr = (sta*)malloc(sizeof(sta) * SIZE_STU);
    if (ptr == NULL)
    {
        perror("initstu fail");
        return;
    }
    pc->st = ptr;
    pc->capacity = SIZE_STU;
    pc->size = -1;

    //LordStu(pc);
}

//员工操作
void sta_operate(Sta* spc, Dep* cpc) {
    printf("\n-------------------------欢迎进入公司员工管理系统！----------------------");
    printf("\n\n                 请选择你要对员工进行的操作：");
    printf("\n\n                             1.添加");
    printf("\n                             2.查询");
    printf("\n                             3.显示");
    printf("\n                             4.返回主页面");
    printf("\n                                                      ");
    printf("\n                        请输入：");
    int i;
    scanf("%d", &i);
    system("cls");
    switch (i) {
    case 1://添加员工信息 
        input_sta(spc, cpc );
        break;
    case 2://查询员工信息 
        search_sta(spc, cpc);
        break;
    case 3://显示所有员工信息
        show_sta(spc, cpc);
        break;
    case 4:
        renew_sta(spc);
        home(spc, cpc);
        break;
    }
}
//插入员工信息
void input_sta(Sta* spc, Dep* cpc) {
    char flag;
    FILE* fp;

    fp = fopen("staff.txt", "a+");
    if (fp == NULL) {
        printf("打开文件失败！");
        return;
    }
    printf("员工编号\t员工姓名\t所在部门\t\n");
    while (1) {
        spc->size++;
        scanf("%s %s %s", spc->st[spc->size].sta_ID, spc->st[spc->size].sta_name, spc->st[spc->size].department);

        // 查重
        for (int i = 0; i < spc->size; i++) {
            if (strcmp(spc->st[i].sta_ID, spc->st[spc->size].sta_ID) == 0) {
                printf("该员工已存在，请重新输入！\n");
                scanf("%s %s %s", spc->st[spc->size].sta_ID, spc->st[spc->size].sta_name, spc->st[spc->size].department);
                i = -1;
            }
        }

        // 更新部门人数
        for (int i = 0; i <= cpc->size; i++) {
            if (strcmp(cpc->cou[i].dep_name, spc->st[spc->size].department) == 0) {
                cpc->cou[i].people++;
                break;
            }
        }

        fprintf(fp, "%s\t%s\t%s\n", spc->st[spc->size].sta_ID, spc->st[spc->size].sta_name, spc->st[spc->size].department);
        printf("\n录入成功，继续录入输入y，返回上一级请按任意键：");
        fflush(stdin);
        scanf(" %c", &flag);

        fclose(fp);
        if (flag != 'y' && flag != 'Y') {
            break;
        }

        fp = fopen("staff.txt", "a");
    }
    renew_sta(spc);
    system("cls");
    sta_operate(spc, cpc);
    renew_sta(spc);

}


/*查询员工信息*/
void search_sta(Sta* spc, Dep* cpc) {
    system("cls");
    printf("\n请选择查询方式：");
    printf("\n  1.编号查询");
    printf("\n  2.姓名查询");
    printf("\n请选择：");
    int h;
    scanf(" %d", &h);
    switch (h) {
    case 1:
        search_sta_id(spc, cpc);
        break;
    case 2:
        search_sta_name(spc, cpc);
        break;

    }
}

/*编号查询*/
void search_sta_id(Sta* spc, Dep* cpc) {
    system("cls");
    char id[9] = { 0 };
    printf("\n输入要查询的员工编号:");
    fflush(stdin);
    scanf("%s", id);
    int i;
    for (i = 0; i <= spc->size; i++) {
        if (strcmp(spc->st[i].sta_ID, id) == 0) {
            system("cls");
            printf("查找成功!");
            printf("\n\n\t员工编号\t员工姓名\t所在部门");
            printf("\n\t-----------------------------------------------------------------");
            printf("\n\t%s\t%s\t%s\n", spc->st[i].sta_ID, spc->st[i].sta_name, spc->st[i].department);
            system("pause");
            system("cls");
            sta_operate(spc, cpc);
            return;
        }
    }

    system("cls");
    printf("没有找到符合条件的员工！\n");
    system("pause");
    system("cls");
    sta_operate(spc, cpc);
}

void search_sta_name(Sta* spc, Dep* cpc) {
    system("cls");
    char name[9] = { 0 };
    printf("\n输入要查询的员工姓名:");
    fflush(stdin);
    scanf("%s", name);
    int i;
    for (i = 0; i <= spc->size; i++) {
        if (strcmp(spc->st[i].sta_name, name) == 0) {
            system("cls");
            printf("查找成功!");
            printf("\n\n\t员工编号\t员工姓名\t所在部门");
            printf("\n\t-----------------------------------------");
            printf("\n\t%s\t%s\t%s\n", spc->st[i].sta_ID, spc->st[i].sta_name, spc->st[i].department);
            system("pause");
            system("cls");
            sta_operate(spc, cpc);
            return;
        }
    }

    system("cls");
    printf("没有找到符合条件的员工！\n");
    system("pause");
    system("cls");
    sta_operate(spc, cpc);
}

//排序
int cmp_sta_id(const void* a, const void* b) {
    sta* pa = (sta*)a;
    sta* pb = (sta*)b;
    return strcmp(pa->sta_ID, pb->sta_ID);
}

int cmp_sta_name(const void* a, const void* b) {
    sta* pa = (sta*)a;
    sta* pb = (sta*)b;
    return strcmp(pa->sta_name, pb->sta_name);
}



/*显示所有员工信息*/
void show_sta(Sta* spc, Dep* cpc) {
    int h;
    if (spc->size == -1) {
        printf("\n还没有录入信息！\n");
        system("pause");
        system("cls");
        sta_operate(spc, cpc);
    }
    system("cls");
    printf("\n\n\t员工编号\t员工姓名\t所在部门");
    printf("\n\t---------------------------------------------------------");
    for (h = 0; h <= spc->size; h++) {
        printf("\n\t%s\t%s\t%s\n", spc->st[h].sta_ID, spc->st[h].sta_name, spc->st[h].department);
    }
    fflush(stdin);
    printf("\n\t1.修改");
    printf("\n\t2.删除");
    printf("\n\t3.按照员工编号排序");
    printf("\n\t4.按照员工姓名排序");
    printf("\n\t5.返回");
    printf("\n\n\t选择要进行的操作：");
    int flag;
    fflush(stdin);
    scanf("%d", &flag);

    switch (flag) {
    case 1:
        edit_sta(spc, cpc);
        break;
    case 2:
        delete_sta(spc, cpc);
        break;
    case 3: // 按照员工编号排序
        qsort(spc->st, spc->size + 1, sizeof(sta), cmp_sta_id);
        show_sta(spc, cpc);
        break;
    case 4: // 按照员工姓名排序
        qsort(spc->st, spc->size + 1, sizeof(sta), cmp_sta_name);
        show_sta(spc, cpc);
        break;
    default:
        system("cls");
        sta_operate(spc, cpc);
        break;
    }
}

void edit_sta(Sta* spc, Dep* cpc) {
    printf("\n输入需要编辑的员工的员工编号：");
    char id[10] = { 0 };
    getchar();
    scanf("%s", id);
    int h;
    for (h = 0; h <= spc->size; h++) {
        if (strcmp(spc->st[h].sta_ID, id) == 0) {//找到需要编辑的行
            system("cls");
            printf("\n\n\t员工编号\t员工姓名\t所在部门");
            printf("\n\t-----------------------------------------");
            printf("\n\t%s\t%s\t%s\n", spc->st[spc->size].sta_ID, spc->st[spc->size].sta_name, spc->st[spc->size].department);
            printf("\n这是修改前的数据，请依次输入修改值：\n\t");
            fflush(stdin);
            scanf("%s %s %s", spc->st[h].sta_ID, spc->st[h].sta_name, spc->st[h].department);
            int k;
            for (k = 0; k <= spc->size; k++) {
                if (strcmp(spc->st[k].sta_ID, spc->st[h].sta_ID) == 0) {
                    if (k == h) {
                        continue;
                    }
                    else {//员工编号不唯一
                        printf("\n此员工编号已存在！重新输入员工编号：");
                        fflush(stdin);
                        scanf("%s", spc->st[h].sta_ID);
                        k = -1;
                    }
                }
            }
            /*将修改信息写入文件*/
            //思想：将原文件重新写入一遍
            renew_sta(spc);
            system("cls");
            printf("修改成功！\n");
            system("pause");
            system("cls");
            sta_operate(spc, cpc);
        }
    }
    printf("\n此员工编号不存在！\n");
    system("pause");
    system("cls");
    sta_operate(spc, cpc);
    renew_sta(spc);

}

void delete_sta(Sta* spc, Dep* cpc)
{
    printf("\n输入需要删除的员工的员工编号：");
    char id[10] = { 0 };
    getchar();
    scanf("%s", id);
    int h;
    for (h = 0; h <= spc->size; h++) {
        if (strcmp(spc->st[h].sta_ID, id) == 0) {//找到需要删除的行
            system("cls");
            
            // 更新部门人数
            for (int i = 0; i <= cpc->size; i++) {
                if (strcmp(cpc->cou[i].dep_name, spc->st[h].department) == 0) {
                    cpc->cou[i].people--;
                    break;
                }
            }

            int k;
            for (k = h + 1; k <= spc->size; k++, h++) {//将数组直接向前移动
                strcpy(spc->st[h].sta_ID, spc->st[k].sta_ID);
                strcpy(spc->st[h].sta_name, spc->st[k].sta_name);
                strcpy(spc->st[h].department, spc->st[h].department);
            }
            /*将修改信息写入文件*/
            //思想：将原文件重新写入一遍
            renew_sta(spc);
            spc->size--;
            system("cls");
            printf("删除成功！\n");
            system("pause");
            system("cls");
            sta_operate(spc, cpc);
        }
    }
    printf("\n此员工编号不存在！\n");
    system("pause");
    system("cls");
    sta_operate(spc, cpc);
    renew_sta(spc);
}
//更新员工数据库
void renew_sta(Sta* pc) {
    FILE* fp;
    fp = fopen("staff.txt", "w+");
    if (fp == NULL) {
        printf("\n打开文件失败，无法保存至文件。\n");
        return;
    }
    fprintf(fp, "员工编号\t员工姓名\t所在部门\n");
    if (pc->size == -1) {
        fclose(fp);
        return;
    }
    int h;
    for (h = 0; h <= pc->size; h++) {
        fprintf(fp, "%s\t%s\t%s\n", pc->st[h].sta_ID, pc->st[h].sta_name, pc->st[h].department);
    }
    fclose(fp);

}


