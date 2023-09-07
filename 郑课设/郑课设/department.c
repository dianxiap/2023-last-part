#define _CRT_SECURE_NO_WARNINGS 1
#include "department.h"


//初始化顺序表
void initDep(Dep* pc)
{
    assert(pc);
    dep* tem = (dep*)malloc(sizeof(dep) * SIZE_COU);
    if (tem == NULL)
    {
        perror("malloc fail");
        return;
    }
    pc->cou = tem;
    pc->capacity = SIZE_COU;
    pc->size = -1;
    pc->cou->people = 0;

    //LordCou(pc);
}
void dep_operate(Sta* spc, Dep* cpc) {
    printf("\n-------------------------欢迎进入部门员工管理系统！----------------------");
    printf("\n\n                 请选择你要对部门进行的操作：");
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
    case 1:
        input_dep(spc, cpc);
        break;
    case 2:
        search_dep(spc, cpc);
        break;
    case 3:
        show_dep(spc, cpc);
    case 4:
        renew_dep(cpc,spc);
        home(spc, cpc);
        break;
    }
}

//插入部门信息
void input_dep(Sta* spc, Dep* cpc) {
    char flag;
    FILE* fp;
    //--判断文件是否为空
    fp = fopen("department.txt", "a+");
    flag = fgetc(fp);
    if (flag == EOF) {
        fprintf(fp, "部门编号\t部门名称\t员工数量\n");
    }
    fclose(fp);
    //--
    fp = fopen("department.txt", "a+");
    if (fp == NULL) {
        printf("打开文件失败！");
        system("cls");
        dep_operate(spc, cpc);
    }
    printf("部门编号\t部门名称\n");
    while (1) {
        cpc->size++;
        scanf("%s %s", &cpc->cou[cpc->size].dep_ID, &cpc->cou[cpc->size].dep_name);
        cpc->cou[cpc->size].people = 0;
        //--数据查重
        int h;
        for (h = 0; h < cpc->size; h++) {
            if (cpc->size == 0) break; // 第一条数据不需要查重
            if (strcmp(cpc->cou[h].dep_ID, cpc->cou[cpc->size].dep_ID) == 0) {
                printf("该部门编号已存在，请重新输入！\n");
                scanf("\n%s %s", &cpc->cou[cpc->size].dep_ID, &cpc->cou[cpc->size].dep_name);
                h = -1;
            }
        }
        //--
        fprintf(fp, "%s\t%s\t%d\n", cpc->cou[cpc->size].dep_ID, cpc->cou[cpc->size].dep_name, cpc->cou[cpc->size].people);
        printf("\n录入成功，继续录入输入y，返回上一级请按任意键：");
        fflush(stdin);
        scanf("%c", &flag);
        fclose(fp);
        if (flag != 'y' && flag != 'Y') break;
        fp = fopen("department.txt", "a");
    }
    renew_dep(cpc,spc);
    system("cls");
    dep_operate(spc, cpc);
}

/*查询部门信息*/
void search_dep(Sta* spc, Dep* cpc) 
{
    system("cls");
    printf("\n请选择查询方式：");
    printf("\n  1.课程号查询");
    printf("\n  2.课程名查询");
    printf("\n请选择：");
    int h;
    scanf(" %d", &h);
    switch (h) {
    case 1:
        search_dep_id(spc, cpc);
        break;
    case 2:
        search_dep_name(spc, cpc);
        break;
    }
}
void search_dep_id(Sta* spc, Dep* cpc) {
    system("cls");
    char id[9] = { 0 };
    printf("\n输入部门编号:");
    fflush(stdin);
    scanf("%s", id);
    int h;
    for (h = 0; h <= cpc->size; h++) {
        if (strcmp(cpc->cou[h].dep_ID, id) == 0) {
            system("cls");
            printf("查找成功!");
            printf("\n\n\t部门编号\t部门名称\t员工数量");
            printf("\n\t---------------------------------");
            printf("\n\t%s\t%s\t%d\n", cpc->cou[h].dep_ID, cpc->cou[h].dep_name, cpc->cou[h].people);
            system("pause");
            system("cls");
            dep_operate(spc, cpc);
        }
    }
    system("cls");
    printf("没有此部门编号！\n");
    system("pause");
    system("cls");
    dep_operate(spc, cpc);
}

/*部门名称查询*/
void search_dep_name(Sta* spc, Dep* cpc) {
    system("cls");
    char name[20] = { 0 };
    printf("\n输入部门名称:");
    fflush(stdin);
    scanf("%s", name);
    int h;
    int found = 0;
    for (h = 0; h <= cpc->size; h++) {
        if (strcmp(cpc->cou[h].dep_name, name) == 0) {
            found = 1;
            system("cls");
            printf("查找成功!");
            printf("\n\n\t部门编号\t部门名称\t员工数量");
            printf("\n\t---------------------------------");
            printf("\n\t%s\t%s\t%d\n", cpc->cou[h].dep_ID, cpc->cou[h].dep_name, cpc->cou[h].people);
            break;
        }
    }
    if (found == 0) {
        system("cls");
        printf("没有此部门名称！\n");
    }
    system("pause");
    system("cls");
    dep_operate(spc, cpc);
}

//排序

int cmp_people(const void* a, const void* b)
{
    return ((dep*)b)->people - ((dep*)a)->people;
}

int cmp_depID(const void* a, const void* b)
{
    return strcmp(((dep*)a)->dep_ID, ((dep*)b)->dep_ID);
}


/*显示所有部门信息*/
void show_dep(Sta* spc, Dep* cpc) {
    int h;
    if (cpc->size == -1) {
        printf("\n还没有录入信息！\n");
        system("pause");
        system("cls");
        dep_operate(spc, cpc);
    }
    system("cls");
    printf("\n\n\t部门编号\t部门名称\t员工数量\t员工编号");
    printf("\n\t--------------------------------------------------");
    for (h = 0; h <= cpc->size; h++) {
        printf("\n\t%s\t%s\t%d\t", cpc->cou[h].dep_ID, cpc->cou[h].dep_name, cpc->cou[h].people);
        int count = 0;
        for (int i = 0; i <= spc->size; i++) {
            if (strcmp(spc->st[i].department, cpc->cou[h].dep_name) == 0) {
                printf("%s ", spc->st[i].sta_ID);
                count++;
            }
        }
        if (count == 0) {
            printf("无");
        }
        printf("\n");
    }
    //
    fflush(stdin);
    printf("\n\n\t1.修改");
    printf("\n\t2.删除");
    printf("\n\t3.排序(员工数量)");
    printf("\n\t4.排序(部门编号)");
    printf("\n\t5.返回");
    printf("\n\n  选择要进行的操作：");
    int flag;
    fflush(stdin);
    scanf("%d", &flag);
    switch (flag) {
    case 1:
        edit_dep(spc, cpc);
        break;
    case 2:
        delete_dep(spc, cpc);
        break;
    case 3:
        qsort(cpc->cou, cpc->size + 1, sizeof(dep), cmp_people);
        show_dep(spc, cpc);
        break;
    case 4:
        qsort(cpc->cou, cpc->size + 1, sizeof(dep), cmp_depID);
        show_dep(spc, cpc);
        break;
    default:
        system("cls");
        dep_operate(spc, cpc);
        break;
    }
    renew_dep(cpc,spc);

}

/*编辑部门信息*/
void edit_dep(Sta* spc, Dep* cpc) {
    printf("\n输入需要编辑的部门编号：");
    char id[10] = { 0 };
    getchar();
    scanf("%s", id);
    int h;
    for (h = 0; h <= cpc->size; h++) {
        if (strcmp(cpc->cou[h].dep_ID, id) == 0) {//找到需要编辑的行
            system("cls");
            printf("\n\n\t部门编号\t部门名称\t员工数量");
            printf("\n\t---------------------------------");
            printf("\n\t%s\t%s\t%d\n", cpc->cou[h].dep_ID, cpc->cou[h].dep_name, cpc->cou[h].people);
            printf("\n这是修改前的数据，请依次输入修改值：\n\t");
            fflush(stdin);
            scanf("%s %s %d", &cpc->cou[h].dep_ID, &cpc->cou[h].dep_name, &cpc->cou[h].people);
            int k;
            for (k = 0; k <= cpc->size; k++) {
                if (strcmp(cpc->cou[k].dep_ID, cpc->cou[h].dep_ID) == 0) {
                    if (k == h) {
                        continue;
                    }
                    else {//部门编号不唯一
                        printf("\n此部门编号已存在，重新输入：");
                        fflush(stdin);
                        scanf("%s", &cpc->cou[h].dep_ID);
                        k = -1;
                    }
                }
            }
            /*将修改信息写入文件*/
            //思想：将原文件重新写入一遍
            renew_dep(cpc,spc);
            system("cls");
            printf("修改成功！\n");
            system("pause");
            system("cls");
            dep_operate(spc, cpc);
        }
    }
    printf("\n此部门编号不存在！\n");
    system("pause");
    system("cls");
    dep_operate(spc, cpc);
    renew_dep(cpc,spc);

}

/*删除部门信息*/
void delete_dep(Sta* spc, Dep* cpc) {
    printf("\n输入需要删除的部门编号：");
    char id[10] = { 0 };
    getchar();
    scanf("%s", id);
    int h;
    for (h = 0; h <= cpc->size; h++) {
        if (strcmp(cpc->cou[h].dep_ID, id) == 0) {//找到需要删除的行
            system("cls");

            // 更新员工所在部门信息
            for (int i = 0; i <= spc->size; i++) {
                if (strcmp(spc->st[i].department, cpc->cou[h].dep_name) == 0) {
                    strcpy(spc->st[i].department, "部门已删除");
                }
            }

            //如果只有一条记录
            if (cpc->size == 1) {
                cpc->size = 0;
                renew_dep(cpc,spc);
                printf("删除成功！\n");
                system("pause");
                system("cls");
                dep_operate(spc, cpc);
            }
            //查看是否有员工
            if (cpc->cou[h].people != 0) {//有员工时
                int a;
                for (a = 0; a <= spc->size; a++) {
                    if (spc->st[a].department == h) {
                        delete_sta(cpc, spc, a);
                        a = -1;
                        spc->size--;
                        continue;
                    }
                }
            }
            int k;
            for (k = h + 1; k <= cpc->size; k++, h++) {//将数组直接向前移动
                strcpy(cpc->cou[h].dep_ID, cpc->cou[k].dep_ID);
                strcpy(cpc->cou[h].dep_name, cpc->cou[k].dep_name);
                cpc->cou[h].people = cpc->cou[k].people;
            }
            /*将修改信息写入文件*/
            //思想：将原文件重新写入一遍
            renew_dep(cpc,spc);
            cpc->size--;
            system("cls");
            printf("删除成功！\n");
            system("pause");
            system("cls");
            dep_operate(spc, cpc);
        }
    }
    printf("\n此部门编号不存在！\n");
    system("pause");
    system("cls");
    dep_operate(spc, cpc);
    renew_dep(cpc,spc);
}

//更新部门数据库
void renew_dep(Dep* pc, Sta* spc) {
    FILE* fp;
    fp = fopen("department.txt", "w+");
    if (fp == NULL) {
        printf("\n打开文件失败，无法保存至文件。\n");
        return;
    }
    fprintf(fp, "部门编号\t部门名称\t员工数量\t员工编号\n");
    if (pc->size == -1) {
        fclose(fp);
        return;
    }
    int h;
    for (h = 0; h <= pc->size; h++) {
        fprintf(fp, "%s\t%s\t%d\t", pc->cou[h].dep_ID, pc->cou[h].dep_name, pc->cou[h].people);
        for (int i = 0; i <= spc->size; i++) {
            if (strcmp(spc->st[i].department, pc->cou[h].dep_name) == 0) {
                fprintf(fp, "%s ", spc->st[i].sta_ID);
            }
        }
        fprintf(fp, "\n");
    }
    fclose(fp);
}



