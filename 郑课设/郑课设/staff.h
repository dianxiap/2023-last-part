#pragma once
#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "operator.h"
#include "head.h"

//��ʼ��˳���
void init_sta(Sta* pc);
//����Ա����Ϣ
void input_sta(Sta* spc, Dep* cpc);

//����Ա����Ϣ
void search_sta(Sta* spc, Dep* cpc);
//�����±����Ա����Ϣ
void search_sta_id(Sta* spc, Dep* cpc);
//������������Ա����Ϣ
void search_sta_name(Sta* spc, Dep* cpc);

//��ʾԱ����Ϣ
void show_sta(Sta* spc, Dep* cpc);
//�༭Ա����Ϣ
void edit_sta(Sta* spc, Dep* cpc);
//����Ա����Ϣ
void renew_sta(Sta* spc);
//ɾ��Ա����Ϣ
void delete_sta(Sta* spc, Dep* cpc);
//����Ա����Ϣ
void LordSta(Sta* pc);
//����Ա����Ϣ
void sta_operate(Sta* spc, Dep* cpc);