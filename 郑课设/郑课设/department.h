#pragma once
#include <stdio.h>
#include <malloc.h>
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "operator.h"
#include "head.h"

//��ʼ��˳���
void initDep(Dep* pc);

//���벿����Ϣ
void input_dep(Sta* spc, Dep* cpc);

//��ѯ������Ϣ
void search_dep(Sta* spc, Dep* cpc);

//���ձ�Ų���
void search_dep_id(Sta* spc, Dep* cpc);

//���ղ�����������
void search_dep_name(Sta* spc, Dep* cpc);

//��ʾ������Ϣ
void show_dep(Sta* spc, Dep* cpc);

//�޸Ĳ�����Ϣ
void edit_dep(Sta* spc, Dep* cpc);
//���²������ݿ�
void renew_dep(Dep* pc);
//ɾ���ò���
void delete_dep(Sta* spc, Dep* cpc);

//���Ų���
void dep_operate(Sta* spc, Dep* cpc);

//���ز������ݿ�
void Lorddep(Dep* pc);