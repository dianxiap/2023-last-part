#pragma once

#define SIZE_STU 10

//Ա����Ϣ�ڵ�
typedef struct staff_info {
    char sta_ID[9];     //Ա�����
    char sta_name[5];   //Ա������
    char department[9];  //���ڲ���
}sta;

//�洢Ա����Ϣ��˳���
typedef struct staff
{
    sta* st;
    int size;
    int capacity;
}Sta;

#define SIZE_COU 10
//������Ϣ�ڵ�
typedef struct department_info {
    char dep_ID[9]; //���ű��
    char dep_name[9];   //��������
    int people; //Ա������
}dep;

//�洢������Ϣ��˳���
typedef struct course
{
    dep* cou;
    int size;
    int capacity;
}Dep;
