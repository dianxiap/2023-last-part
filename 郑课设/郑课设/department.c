#define _CRT_SECURE_NO_WARNINGS 1
#include "department.h"


//��ʼ��˳���
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
    printf("\n-------------------------��ӭ���벿��Ա������ϵͳ��----------------------");
    printf("\n\n                 ��ѡ����Ҫ�Բ��Ž��еĲ�����");
    printf("\n\n                             1.���");
    printf("\n                             2.��ѯ");
    printf("\n                             3.��ʾ");
    printf("\n                             4.������ҳ��");
    printf("\n                                                      ");
    printf("\n                        �����룺");
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

//���벿����Ϣ
void input_dep(Sta* spc, Dep* cpc) {
    char flag;
    FILE* fp;
    //--�ж��ļ��Ƿ�Ϊ��
    fp = fopen("department.txt", "a+");
    flag = fgetc(fp);
    if (flag == EOF) {
        fprintf(fp, "���ű��\t��������\tԱ������\n");
    }
    fclose(fp);
    //--
    fp = fopen("department.txt", "a+");
    if (fp == NULL) {
        printf("���ļ�ʧ�ܣ�");
        system("cls");
        dep_operate(spc, cpc);
    }
    printf("���ű��\t��������\n");
    while (1) {
        cpc->size++;
        scanf("%s %s", &cpc->cou[cpc->size].dep_ID, &cpc->cou[cpc->size].dep_name);
        cpc->cou[cpc->size].people = 0;
        //--���ݲ���
        int h;
        for (h = 0; h < cpc->size; h++) {
            if (cpc->size == 0) break; // ��һ�����ݲ���Ҫ����
            if (strcmp(cpc->cou[h].dep_ID, cpc->cou[cpc->size].dep_ID) == 0) {
                printf("�ò��ű���Ѵ��ڣ����������룡\n");
                scanf("\n%s %s", &cpc->cou[cpc->size].dep_ID, &cpc->cou[cpc->size].dep_name);
                h = -1;
            }
        }
        //--
        fprintf(fp, "%s\t%s\t%d\n", cpc->cou[cpc->size].dep_ID, cpc->cou[cpc->size].dep_name, cpc->cou[cpc->size].people);
        printf("\n¼��ɹ�������¼������y��������һ���밴�������");
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

/*��ѯ������Ϣ*/
void search_dep(Sta* spc, Dep* cpc) 
{
    system("cls");
    printf("\n��ѡ���ѯ��ʽ��");
    printf("\n  1.�γ̺Ų�ѯ");
    printf("\n  2.�γ�����ѯ");
    printf("\n��ѡ��");
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
    printf("\n���벿�ű��:");
    fflush(stdin);
    scanf("%s", id);
    int h;
    for (h = 0; h <= cpc->size; h++) {
        if (strcmp(cpc->cou[h].dep_ID, id) == 0) {
            system("cls");
            printf("���ҳɹ�!");
            printf("\n\n\t���ű��\t��������\tԱ������");
            printf("\n\t---------------------------------");
            printf("\n\t%s\t%s\t%d\n", cpc->cou[h].dep_ID, cpc->cou[h].dep_name, cpc->cou[h].people);
            system("pause");
            system("cls");
            dep_operate(spc, cpc);
        }
    }
    system("cls");
    printf("û�д˲��ű�ţ�\n");
    system("pause");
    system("cls");
    dep_operate(spc, cpc);
}

/*�������Ʋ�ѯ*/
void search_dep_name(Sta* spc, Dep* cpc) {
    system("cls");
    char name[20] = { 0 };
    printf("\n���벿������:");
    fflush(stdin);
    scanf("%s", name);
    int h;
    int found = 0;
    for (h = 0; h <= cpc->size; h++) {
        if (strcmp(cpc->cou[h].dep_name, name) == 0) {
            found = 1;
            system("cls");
            printf("���ҳɹ�!");
            printf("\n\n\t���ű��\t��������\tԱ������");
            printf("\n\t---------------------------------");
            printf("\n\t%s\t%s\t%d\n", cpc->cou[h].dep_ID, cpc->cou[h].dep_name, cpc->cou[h].people);
            break;
        }
    }
    if (found == 0) {
        system("cls");
        printf("û�д˲������ƣ�\n");
    }
    system("pause");
    system("cls");
    dep_operate(spc, cpc);
}

//����

int cmp_people(const void* a, const void* b)
{
    return ((dep*)b)->people - ((dep*)a)->people;
}

int cmp_depID(const void* a, const void* b)
{
    return strcmp(((dep*)a)->dep_ID, ((dep*)b)->dep_ID);
}


/*��ʾ���в�����Ϣ*/
void show_dep(Sta* spc, Dep* cpc) {
    int h;
    if (cpc->size == -1) {
        printf("\n��û��¼����Ϣ��\n");
        system("pause");
        system("cls");
        dep_operate(spc, cpc);
    }
    system("cls");
    printf("\n\n\t���ű��\t��������\tԱ������\tԱ�����");
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
            printf("��");
        }
        printf("\n");
    }
    //
    fflush(stdin);
    printf("\n\n\t1.�޸�");
    printf("\n\t2.ɾ��");
    printf("\n\t3.����(Ա������)");
    printf("\n\t4.����(���ű��)");
    printf("\n\t5.����");
    printf("\n\n  ѡ��Ҫ���еĲ�����");
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

/*�༭������Ϣ*/
void edit_dep(Sta* spc, Dep* cpc) {
    printf("\n������Ҫ�༭�Ĳ��ű�ţ�");
    char id[10] = { 0 };
    getchar();
    scanf("%s", id);
    int h;
    for (h = 0; h <= cpc->size; h++) {
        if (strcmp(cpc->cou[h].dep_ID, id) == 0) {//�ҵ���Ҫ�༭����
            system("cls");
            printf("\n\n\t���ű��\t��������\tԱ������");
            printf("\n\t---------------------------------");
            printf("\n\t%s\t%s\t%d\n", cpc->cou[h].dep_ID, cpc->cou[h].dep_name, cpc->cou[h].people);
            printf("\n�����޸�ǰ�����ݣ������������޸�ֵ��\n\t");
            fflush(stdin);
            scanf("%s %s %d", &cpc->cou[h].dep_ID, &cpc->cou[h].dep_name, &cpc->cou[h].people);
            int k;
            for (k = 0; k <= cpc->size; k++) {
                if (strcmp(cpc->cou[k].dep_ID, cpc->cou[h].dep_ID) == 0) {
                    if (k == h) {
                        continue;
                    }
                    else {//���ű�Ų�Ψһ
                        printf("\n�˲��ű���Ѵ��ڣ��������룺");
                        fflush(stdin);
                        scanf("%s", &cpc->cou[h].dep_ID);
                        k = -1;
                    }
                }
            }
            /*���޸���Ϣд���ļ�*/
            //˼�룺��ԭ�ļ�����д��һ��
            renew_dep(cpc,spc);
            system("cls");
            printf("�޸ĳɹ���\n");
            system("pause");
            system("cls");
            dep_operate(spc, cpc);
        }
    }
    printf("\n�˲��ű�Ų����ڣ�\n");
    system("pause");
    system("cls");
    dep_operate(spc, cpc);
    renew_dep(cpc,spc);

}

/*ɾ��������Ϣ*/
void delete_dep(Sta* spc, Dep* cpc) {
    printf("\n������Ҫɾ���Ĳ��ű�ţ�");
    char id[10] = { 0 };
    getchar();
    scanf("%s", id);
    int h;
    for (h = 0; h <= cpc->size; h++) {
        if (strcmp(cpc->cou[h].dep_ID, id) == 0) {//�ҵ���Ҫɾ������
            system("cls");

            // ����Ա�����ڲ�����Ϣ
            for (int i = 0; i <= spc->size; i++) {
                if (strcmp(spc->st[i].department, cpc->cou[h].dep_name) == 0) {
                    strcpy(spc->st[i].department, "������ɾ��");
                }
            }

            //���ֻ��һ����¼
            if (cpc->size == 1) {
                cpc->size = 0;
                renew_dep(cpc,spc);
                printf("ɾ���ɹ���\n");
                system("pause");
                system("cls");
                dep_operate(spc, cpc);
            }
            //�鿴�Ƿ���Ա��
            if (cpc->cou[h].people != 0) {//��Ա��ʱ
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
            for (k = h + 1; k <= cpc->size; k++, h++) {//������ֱ����ǰ�ƶ�
                strcpy(cpc->cou[h].dep_ID, cpc->cou[k].dep_ID);
                strcpy(cpc->cou[h].dep_name, cpc->cou[k].dep_name);
                cpc->cou[h].people = cpc->cou[k].people;
            }
            /*���޸���Ϣд���ļ�*/
            //˼�룺��ԭ�ļ�����д��һ��
            renew_dep(cpc,spc);
            cpc->size--;
            system("cls");
            printf("ɾ���ɹ���\n");
            system("pause");
            system("cls");
            dep_operate(spc, cpc);
        }
    }
    printf("\n�˲��ű�Ų����ڣ�\n");
    system("pause");
    system("cls");
    dep_operate(spc, cpc);
    renew_dep(cpc,spc);
}

//���²������ݿ�
void renew_dep(Dep* pc, Sta* spc) {
    FILE* fp;
    fp = fopen("department.txt", "w+");
    if (fp == NULL) {
        printf("\n���ļ�ʧ�ܣ��޷��������ļ���\n");
        return;
    }
    fprintf(fp, "���ű��\t��������\tԱ������\tԱ�����\n");
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



