#define _CRT_SECURE_NO_WARNINGS 1
#include "staff.h"

//��ʼ��Ա��˳���
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

//Ա������
void sta_operate(Sta* spc, Dep* cpc) {
    printf("\n-------------------------��ӭ���빫˾Ա������ϵͳ��----------------------");
    printf("\n\n                 ��ѡ����Ҫ��Ա�����еĲ�����");
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
    case 1://���Ա����Ϣ 
        input_sta(spc, cpc );
        break;
    case 2://��ѯԱ����Ϣ 
        search_sta(spc, cpc);
        break;
    case 3://��ʾ����Ա����Ϣ
        show_sta(spc, cpc);
        break;
    case 4:
        renew_sta(spc);
        home(spc, cpc);
        break;
    }
}
//����Ա����Ϣ
void input_sta(Sta* spc, Dep* cpc) {
    char flag;
    FILE* fp;

    fp = fopen("staff.txt", "a+");
    if (fp == NULL) {
        printf("���ļ�ʧ�ܣ�");
        return;
    }
    printf("Ա�����\tԱ������\t���ڲ���\t\n");
    while (1) {
        spc->size++;
        scanf("%s %s %s", spc->st[spc->size].sta_ID, spc->st[spc->size].sta_name, spc->st[spc->size].department);

        // ����
        for (int i = 0; i < spc->size; i++) {
            if (strcmp(spc->st[i].sta_ID, spc->st[spc->size].sta_ID) == 0) {
                printf("��Ա���Ѵ��ڣ����������룡\n");
                scanf("%s %s %s", spc->st[spc->size].sta_ID, spc->st[spc->size].sta_name, spc->st[spc->size].department);
                i = -1;
            }
        }

        // ���²�������
        for (int i = 0; i <= cpc->size; i++) {
            if (strcmp(cpc->cou[i].dep_name, spc->st[spc->size].department) == 0) {
                cpc->cou[i].people++;
                break;
            }
        }

        fprintf(fp, "%s\t%s\t%s\n", spc->st[spc->size].sta_ID, spc->st[spc->size].sta_name, spc->st[spc->size].department);
        printf("\n¼��ɹ�������¼������y��������һ���밴�������");
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


/*��ѯԱ����Ϣ*/
void search_sta(Sta* spc, Dep* cpc) {
    system("cls");
    printf("\n��ѡ���ѯ��ʽ��");
    printf("\n  1.��Ų�ѯ");
    printf("\n  2.������ѯ");
    printf("\n��ѡ��");
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

/*��Ų�ѯ*/
void search_sta_id(Sta* spc, Dep* cpc) {
    system("cls");
    char id[9] = { 0 };
    printf("\n����Ҫ��ѯ��Ա�����:");
    fflush(stdin);
    scanf("%s", id);
    int i;
    for (i = 0; i <= spc->size; i++) {
        if (strcmp(spc->st[i].sta_ID, id) == 0) {
            system("cls");
            printf("���ҳɹ�!");
            printf("\n\n\tԱ�����\tԱ������\t���ڲ���");
            printf("\n\t-----------------------------------------------------------------");
            printf("\n\t%s\t%s\t%s\n", spc->st[i].sta_ID, spc->st[i].sta_name, spc->st[i].department);
            system("pause");
            system("cls");
            sta_operate(spc, cpc);
            return;
        }
    }

    system("cls");
    printf("û���ҵ�����������Ա����\n");
    system("pause");
    system("cls");
    sta_operate(spc, cpc);
}

void search_sta_name(Sta* spc, Dep* cpc) {
    system("cls");
    char name[9] = { 0 };
    printf("\n����Ҫ��ѯ��Ա������:");
    fflush(stdin);
    scanf("%s", name);
    int i;
    for (i = 0; i <= spc->size; i++) {
        if (strcmp(spc->st[i].sta_name, name) == 0) {
            system("cls");
            printf("���ҳɹ�!");
            printf("\n\n\tԱ�����\tԱ������\t���ڲ���");
            printf("\n\t-----------------------------------------");
            printf("\n\t%s\t%s\t%s\n", spc->st[i].sta_ID, spc->st[i].sta_name, spc->st[i].department);
            system("pause");
            system("cls");
            sta_operate(spc, cpc);
            return;
        }
    }

    system("cls");
    printf("û���ҵ�����������Ա����\n");
    system("pause");
    system("cls");
    sta_operate(spc, cpc);
}

//����
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



/*��ʾ����Ա����Ϣ*/
void show_sta(Sta* spc, Dep* cpc) {
    int h;
    if (spc->size == -1) {
        printf("\n��û��¼����Ϣ��\n");
        system("pause");
        system("cls");
        sta_operate(spc, cpc);
    }
    system("cls");
    printf("\n\n\tԱ�����\tԱ������\t���ڲ���");
    printf("\n\t---------------------------------------------------------");
    for (h = 0; h <= spc->size; h++) {
        printf("\n\t%s\t%s\t%s\n", spc->st[h].sta_ID, spc->st[h].sta_name, spc->st[h].department);
    }
    fflush(stdin);
    printf("\n\t1.�޸�");
    printf("\n\t2.ɾ��");
    printf("\n\t3.����Ա���������");
    printf("\n\t4.����Ա����������");
    printf("\n\t5.����");
    printf("\n\n\tѡ��Ҫ���еĲ�����");
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
    case 3: // ����Ա���������
        qsort(spc->st, spc->size + 1, sizeof(sta), cmp_sta_id);
        show_sta(spc, cpc);
        break;
    case 4: // ����Ա����������
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
    printf("\n������Ҫ�༭��Ա����Ա����ţ�");
    char id[10] = { 0 };
    getchar();
    scanf("%s", id);
    int h;
    for (h = 0; h <= spc->size; h++) {
        if (strcmp(spc->st[h].sta_ID, id) == 0) {//�ҵ���Ҫ�༭����
            system("cls");
            printf("\n\n\tԱ�����\tԱ������\t���ڲ���");
            printf("\n\t-----------------------------------------");
            printf("\n\t%s\t%s\t%s\n", spc->st[spc->size].sta_ID, spc->st[spc->size].sta_name, spc->st[spc->size].department);
            printf("\n�����޸�ǰ�����ݣ������������޸�ֵ��\n\t");
            fflush(stdin);
            scanf("%s %s %s", spc->st[h].sta_ID, spc->st[h].sta_name, spc->st[h].department);
            int k;
            for (k = 0; k <= spc->size; k++) {
                if (strcmp(spc->st[k].sta_ID, spc->st[h].sta_ID) == 0) {
                    if (k == h) {
                        continue;
                    }
                    else {//Ա����Ų�Ψһ
                        printf("\n��Ա������Ѵ��ڣ���������Ա����ţ�");
                        fflush(stdin);
                        scanf("%s", spc->st[h].sta_ID);
                        k = -1;
                    }
                }
            }
            /*���޸���Ϣд���ļ�*/
            //˼�룺��ԭ�ļ�����д��һ��
            renew_sta(spc);
            system("cls");
            printf("�޸ĳɹ���\n");
            system("pause");
            system("cls");
            sta_operate(spc, cpc);
        }
    }
    printf("\n��Ա����Ų����ڣ�\n");
    system("pause");
    system("cls");
    sta_operate(spc, cpc);
    renew_sta(spc);

}

void delete_sta(Sta* spc, Dep* cpc)
{
    printf("\n������Ҫɾ����Ա����Ա����ţ�");
    char id[10] = { 0 };
    getchar();
    scanf("%s", id);
    int h;
    for (h = 0; h <= spc->size; h++) {
        if (strcmp(spc->st[h].sta_ID, id) == 0) {//�ҵ���Ҫɾ������
            system("cls");
            
            // ���²�������
            for (int i = 0; i <= cpc->size; i++) {
                if (strcmp(cpc->cou[i].dep_name, spc->st[h].department) == 0) {
                    cpc->cou[i].people--;
                    break;
                }
            }

            int k;
            for (k = h + 1; k <= spc->size; k++, h++) {//������ֱ����ǰ�ƶ�
                strcpy(spc->st[h].sta_ID, spc->st[k].sta_ID);
                strcpy(spc->st[h].sta_name, spc->st[k].sta_name);
                strcpy(spc->st[h].department, spc->st[h].department);
            }
            /*���޸���Ϣд���ļ�*/
            //˼�룺��ԭ�ļ�����д��һ��
            renew_sta(spc);
            spc->size--;
            system("cls");
            printf("ɾ���ɹ���\n");
            system("pause");
            system("cls");
            sta_operate(spc, cpc);
        }
    }
    printf("\n��Ա����Ų����ڣ�\n");
    system("pause");
    system("cls");
    sta_operate(spc, cpc);
    renew_sta(spc);
}
//����Ա�����ݿ�
void renew_sta(Sta* pc) {
    FILE* fp;
    fp = fopen("staff.txt", "w+");
    if (fp == NULL) {
        printf("\n���ļ�ʧ�ܣ��޷��������ļ���\n");
        return;
    }
    fprintf(fp, "Ա�����\tԱ������\t���ڲ���\n");
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


