#define _CRT_SECURE_NO_WARNINGS 1
#include "select_project.h"

//��ʼҳ��
//��д�ߣ����庯
void home(Stu* spc, Cou* cpc, Sel* lpc) {
    printf("\n-------------------------��ӭ����ѡ��ϵͳ��----------------------");
    int h;
    printf("\n\n                        ��ѡ����Ҫ���еĲ�����");
    printf("\n\n                             1.ѧ������");
    printf("\n                             2.�γ̲���");
    printf("\n                             3.��ʼѡ��");
    printf("\n                             4.ѡ��ͳ��");
    printf("\n                             5.�˳�ϵͳ");
    printf("\n                                                      ");
    printf("\n                        �����룺");
    scanf("%d", &h);
    system("cls");

    switch (h) {
    case 1:
        stu_operate(spc,cpc,lpc);
        break;
    case 2:
        cou_operate(spc,cpc,lpc);
        break;
    case 3:
        choose(spc, cpc, lpc);
        break;
    case 4:
        statistic(lpc, spc, cpc);
        break;
    default:
        system("cls");
        printf("BYE!");
        break;
    }
}

//��ʼ��ѡ��˳���
void init_Sel(Sel* pc)
{
    sel* str = malloc(sizeof(sel) * SIZE_SEL);
    if (str == NULL)
    {
        perror("malloc fail");
        return;
    }
    pc->sel = str;
    pc->capacity = SIZE_SEL;
    pc->size = -1;

  
}

//��д�ߣ�������
//��ʼѡ��
void choose(Stu* spc, Cou* cpc, Sel* lpc) {
    char stu_id[10] = { 0 }, cou_id[10] = { 0 };
    printf("\n-------------------------��ӭ����ѡ��ϵͳ��----------------------");

    // ����ѡ��ѧ����Ϣ
    printf("\n\n������ѡ����ѧ�ţ�");
    fflush(stdin);
    scanf("%s", stu_id);

    int stu_index = -1, i;
    for (i = 0; i <= spc->size; i++) {
        if (strcmp(spc->st[i].stu_ID, stu_id) == 0) {
            stu_index = i;
            break;
        }
    }

    if (stu_index == -1) {
        printf("\n�����ڴ�ѧ��\n");
        system("pause");
        system("cls");
        home(spc, cpc, lpc);
        return;
    }

    // ¼��������Ϣ
    lpc->size++;
    lpc->sel[lpc->size].s = stu_index;

    // ����γ���Ϣ
    printf("\n\n������ѡ�޿γ̺ţ�");
    fflush(stdin);
    scanf("%s", cou_id);

    int cou_index = -1;
    for (i = 0; i <= cpc->size; i++) {
        if (strcmp(cpc->cou[i].course_ID, cou_id) == 0) {
            cou_index = i;
            break;
        }
    }

    if (cou_index == -1) {
        printf("\n�����ڴ˿γ̺�\n");
        lpc->size--;
        system("pause");
        system("cls");
        home(spc, cpc, lpc);
        return;
    }

    // ���γ��Ƿ��Ѿ�ѡ��
    for (i = 0; i <= lpc->size; i++) {
        if (lpc->sel[i].s == stu_index && lpc->sel[i].c == cou_index) {
            printf("\n�Ѿ�ѡ���˿γ̣������ظ�ѡ�Σ�\n");
            lpc->size--;
            system("pause");
            system("cls");
            home(spc, cpc, lpc);
            return;
        }
    }

    // ¼��γ���Ϣ
    lpc->sel[lpc->size].c = cou_index;
    cpc->cou[cou_index].people++;
    printf("\n¼��ɹ�!\n");
    system("pause");
    system("cls");
    home(spc, cpc, lpc);
}

//��д�ߣ������
/*ɾ��ѡ�μ�¼*/
void delete_sel(Cou* cpc,Sel* lpc,int q) {//ɾ����q+1����¼
    /*ע�⣡������û�н�x��1�����ں������ֶ���1��������㺯��ѭ������Ҫ��*/
    int h;
    cpc->cou[lpc->sel[q].c].people--;
    for (h = q; q < lpc->size; h++) {
        q++;
        lpc->sel[h].c = lpc->sel[q].c;
        lpc->sel[h].s = lpc->sel[q].s;
    }

}

//��д�ߣ����庯
//ѡ����Ϣͳ�Ƽ�¼
void statistic(Sel* lpc,Stu* spc,Cou* cpc) {
    printf("\n-------------------------��ӭ����ѡ��ϵͳ��----------------------");
    printf("\n\n                     ����ѧ����Ϣ��%d ��", spc->size + 1);
    printf("\n                     ���пγ���Ϣ��%d ��", cpc->size + 1);
    if (lpc->size == -1) {
        printf("\n                       ѡ�μ�¼��0 ��");
        printf("\n\n                     ");
        system("pause");
        system("cls");
        home(spc,cpc,lpc);
    }
    else {
        printf("\n\n                        ѡ�μ�¼ %d ����", lpc->size + 1);
        int m;
        for (m = 0; m <= lpc->size; m++) {
            printf("\n                     ================");
            printf("\n                     ��%d��", m + 1);
            printf("\n                     ѧ��ѧ�ţ�%s", spc->st[lpc->sel[m].s].stu_ID);
            printf("\n                     ѧ��������%s", spc->st[lpc->sel[m].s].stu_name);
            printf("\n                     �γ̺ţ�%s", cpc->cou[lpc->sel[m].c].course_ID);
            printf("\n                     �γ�����%s", cpc->cou[lpc->sel[m].c].course_name);
        }
        printf("\n\n            ");
        system("pause");
        system("cls");
        home(spc,cpc,lpc);
    }

}

