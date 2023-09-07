#pragma once

#define SIZE_STU 10

//员工信息节点
typedef struct staff_info {
    char sta_ID[9];     //员工编号
    char sta_name[5];   //员工姓名
    char department[9];  //所在部门
}sta;

//存储员工信息的顺序表
typedef struct staff
{
    sta* st;
    int size;
    int capacity;
}Sta;

#define SIZE_COU 10
//部门信息节点
typedef struct department_info {
    char dep_ID[9]; //部门编号
    char dep_name[9];   //部门名称
    int people; //员工数量
}dep;

//存储部门信息的顺序表
typedef struct course
{
    dep* cou;
    int size;
    int capacity;
}Dep;
