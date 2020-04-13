//
//  main.c
//  Mini Project
//  Operation Theatre Schedule
//  2018503069
//
//  Created by Vishal Ravi on 28/09/19.
//  Copyright © 2019 Vishal Ravi. All rights reserved.
//

#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>
#define max 100
typedef struct{int data[max],rear,front;char name[max][max];}pqueue;
typedef struct{char val[max][max];unsigned int top;}stack;
typedef struct {char name[100],oc[50];int time;}dis;
typedef struct NOE{char name[100],ocp[50];int time;struct NOE *next;}nod;
typedef struct{char name[1000],Bgrp[100],dis[100];int age,pri;}pat;
typedef struct {char name[20],ocp[25];}doc;
typedef struct NOD{char name[20],ocp[25];struct NOD *next;}noe;
typedef struct NODE{char name[100],Bgrp[10],DisName[100];int age,time,pri;struct NODE *next;}node;
typedef struct OR{char name[100],dname[100],Sname[100];int time;struct OR *next;}op;
typedef op *or;
typedef nod *disease;
typedef node *patient;
typedef noe *Doctor;
char stp[100];int flag=0;
Doctor ints(){return NULL;}
patient intse(){return NULL;}
disease intsw(){return NULL;}
or cror(char Pname[],char Dname[],char Sname[],int time)
{
    or t=NULL;
    t=(or)malloc(sizeof(op));
    strcpy(t->name,Pname);
    strcpy(t->dname,Dname);
    strcpy(t->Sname,Sname);
    t->time=time;
    t->next=NULL;
    return t;
}
or inor(or l,char Pname[],char Dname[],char Sname[],int time)
{
    or temp=cror(Pname,Dname,Sname,time);
    if(!l)    return temp;
    or t=l;
    while(l->next!=NULL)    l=l->next;
    l->next=temp;
    return t;
}
void pror(or l)
{
    while(l)
    {
        printf("Patient Name: %s\nDoctor Name: %s\nSurgery Name: %s\nTime: %d\n\n",l->name,l->dname,l->Sname,l->time);
        l=l->next;
    }
    printf("*****************************************************************\n");
    printf("\n");
}
void por(or l)
{
    while(l)
    {
        printf("Patient Name: %s\nSurgery Name: %s\nTime: %d\n\n",l->name,l->Sname,l->time);
        l=l->next;
    }
    printf("*****************************************************************\n");
    printf("\n");
}
void initialize(pqueue *p)
{
    p->rear=-1;
    p->front=-1;
}
int empty(pqueue *p)
{
    if(p->rear==-1)
        return(1);
 
    return(0);
}
int full(pqueue *p)
{
    if((p->rear+1)%max==p->front)
        return(1);
 
    return(0);
}
void enqueue(pqueue *p, int x,char s[])
{
    int i;
    if(full(p))
        printf("\nOverflow");
    else
    {
        if(empty(p))
        {
            p->rear=p->front=0;
            p->data[0]=x;
            strcpy(p->name[0], s);
        }
        else
        {
            i=p->rear;
 
            while(x<p->data[i])
            {
                p->data[(i+1)%max]=p->data[i];
                strcpy(p->name[(i+1)%max], p->name[i]);
                i=(i-1+max)%max;
                if((i+1)%max==p->front)
                    break;
            }
            i=(i+1)%max;
            p->data[i]=x;
            strcpy(p->name[i], s);
            p->rear=(p->rear+1)%max;
        }
    }
}
int dequeue(pqueue *p)
{
    int x=0;
    if(empty(p))
    {
        printf("\nUnderflow..");
    }
    else
    {
        x=p->data[p->front];
        if(p->rear==p->front)   //delete the last element
            initialize(p);
        else
            p->front=(p->front +1)%max;
    }
 
    return(x);
}
void prt(pqueue *p)
{
    int i,x;
    if(empty(p))
    {
        printf("\nQueue is empty..");
    }
    else
    {
        i=p->front;
 
        while(i!=p->rear)
        {
            x=p->data[i];
            printf("\n%d  %s",x,p->name[i]);
            i=(i+1)%max;
        }
 
        //prints the last element
        x=p->data[i];
        printf("\n%d",x);
    }
}
patient createe(char name[],char bg[],char dis[],int age, int pri)
{
    patient t=NULL;
    t=(patient)malloc(sizeof(node));
    strcpy(t->name,name);
    strcpy(t->Bgrp,bg);
    strcpy(t->DisName,dis);
    t->age=age;
    t->pri=pri;
    t->time=0;
    t->next=NULL;
    return t;
}
patient inse(patient l,char name[],char bg[],char dis[],int age, int pri)
{
    patient temp=createe(name,bg,dis,age,pri);
    if(!l)    return temp;
    patient t=l;
    while(l->next)    l=l->next;
    l->next=temp;
    return t;
}
void print(patient l)
{
    int cp=0;
    printf("*****************************************************************\n");
    while(l)
    {
        cp++;
        printf("Patient %d:\nName:  %s\nAge: %d\nBloog Group: %s\nDiagnosis:%s\nPriority: %d\n\n",cp,l->name,l->age,l->Bgrp,l->DisName,l->pri);
        l=l->next;
    }
    printf("*****************************************************************\n");
}

void intstack(stack *s){s->top=0;}
bool isempty(stack s){return s.top==0;}
bool isfull(stack s){return s.top==max-1;}
bool push(stack *s,char data[])
{
    if(isfull(*s))
        return false;
    s->top+=1;
    strcpy(s->val[s->top],data);
    return true;
}
bool pop(stack *s)
{
    if(isempty(*s))
        return false;
    s->top-=1;
    return true;
}
void distack(stack s)
{
    int i;
    if(!isempty(s))
    {
        for(i=s.top;i>0;i--)
        {
            printf("[%s] ",s.val[i]);
        }
    }
    else
        printf("Empty");
}
Doctor create1(char name[],char ocp[])
{
    Doctor t=NULL;
    t=(Doctor)malloc(sizeof(noe));
    strcpy(t->name,name);
    strcpy(t->ocp,ocp);
    t->next=NULL;
    return t;
}
Doctor insert(Doctor l,char name[],char ocp[])
{
   // Doctor temp=create1(name,ocp);
    if(!l)    return create1(name,ocp);
    Doctor t=l;
    while(l->next!=NULL)    l=l->next;
    l->next=create1(name,ocp);
    return t;
}
void disp(Doctor l)
{
    printf("*****************************************************************\n");
    while(l)
    {
        printf("Name:  %-20s\t\t\tSpecialization: %-20s\n\n",l->name,l->ocp);
        l=l->next;
    }
    printf("*****************************************************************\n");
}
disease create(int d,char str[],char st[])
{
    disease t=NULL;
    t=(disease)malloc(sizeof(nod));
    strcpy(t->name,str);
    strcpy(t->ocp,st);
    t->time=d;
    t->next=NULL;
    return t;
}
disease insertback(disease l,int d,char str[],char st[])
{
    if(!l)    return create(d,str,st);
    disease t=l;
    while(l->next)    l=l->next;
    l->next=create(d,str,st);
    return t;
}
void display(disease l)
{
    printf("*****************************************************************************************\n");
    while(l)
    {
        printf("Name: %-35s\t\tType:%20s\t\tTime:%3d\n",l->name,l->ocp,l->time);
        printf("\n");
        l=l->next;
    }
    printf("\n");
    printf("*****************************************************************************************\n");
}
stack find(Doctor d,stack s,char a[])
{
    Doctor l=d;
    while(d)
    {
        if(strcmp(d->ocp,a)==0)
            push(&s, d->name);
        d=d->next;
    }
    l=d;
    return s;
}
patient getTime(patient p,disease d)
{
    patient l=p;
    disease k=d;
    while(p)
    {
        d=k;
        while(d)
        {
            if(strcmp(p->DisName,d->name)==0)
            {  p->time=d->time; break;}
            d=d->next;
        }
        p=p->next;
    }
    return l;
}
/*void Osch(disease d,patient p,Doctor l)
{
    disease k=d;
    patient i=p;
    Doctor e=l;
    or o1=NULL,o2=NULL;
    while(
}*/
char *getSpec(char str[],disease d)
{
    while(d)
    {
        if(strcmp(str,d->name)==0)
            return d->ocp;
        d=d->next;
    }
    return 0;
}
char *getname(pqueue *p){return p->name[p->front];}
void ame(char str[],Doctor d1,stack *neuro,stack *genral,stack *cardio)
{
   if(strcmp(str,"Genral")==0)
    {
        strcpy(stp,genral->val[genral->top]);
        pop(genral);
    }
    else if(strcmp(str,"Cardio")==0)
    {
        strcpy(stp,cardio->val[cardio->top]);
        pop(cardio);
    }
    else if(strcmp(str,"Neurosurgery")==0)
    {
        strcpy(stp,neuro->val[neuro->top]);
        pop(neuro);
    }

}
int check(disease d,char name[])
{
    while(d)
    {
        if(strcmp(name,d->name)==0)
            return 1;
        d=d->next;
    }
    return 0;
}
void schedule(disease d,patient p,Doctor l)
{
   disease k=d;
    patient i=p;
    Doctor e=l;
    pqueue a,b,c;
    initialize(&a);
    initialize(&c);
    initialize(&b);
   while(p)
   {
       if(p->pri==3){//printf("%s%d",p->name,p->time);
           enqueue(&a, p->time,p->name);}
       if(p->pri==2)
           enqueue(&b, p->time,p->name);
       if(p->pri==1)
       enqueue(&c, p->time,p->name);
       p=p->next;
   }
    p=i;
    stack cardio,genral,neuro;
    intstack(&cardio);
    intstack(&genral);
    intstack(&neuro);
    cardio=find(l,cardio,"Cardio");
    genral=find(l,genral,"Genral");
    neuro=find(l,neuro,"Neurosurgery");//distack(cardio);
    int cp=0,time1=0,time2=0;
    char str[100],str2[100],DisName[120];char ocp[100];
    or o1=NULL,o2=NULL,o3=NULL;
    while(!empty(&a))
    {
            strcpy(str,getname(&a));
            p=i;
                while(p)
                {
                    if(strcmp(p->name,str)==0)
                    {
                        strcpy(ocp, getSpec(p->DisName, d));
                        ame(ocp, l,&neuro,&genral,&cardio);    strcpy(str2, stp);
                        if(flag%2==0)
                        {o1=inor(o1, p->name, str2, p->DisName, a.data[a.front]);}
                        else
                        {  o2=inor(o2, p->name, str2, p->DisName, a.data[a.front]);}
                        break;
                    }
                    p=p->next;
                }
                flag++;
                cp=dequeue(&a);
                
    }
       while(!empty(&b))
        {
            strcpy(str,getname(&b));
            p=i;
          
                while(p)
                {
                    if(strcmp(p->name,str)==0)
                    {
                        strcpy(ocp, getSpec(p->DisName, d));
                        ame(ocp, l,&neuro,&genral,&cardio);    strcpy(str2, stp);
                        if(flag%2==0)
                        {o1=inor(o1, p->name, str2, p->DisName, b.data[b.front]);}
                        else if(flag%2!=0)
                        {  o2=inor(o2, p->name, str2, p->DisName, b.data[b.front]);}
                        break;
                    }
                    p=p->next;
                }
                 flag++;
                    cp=dequeue(&b);
        }
    while(!empty(&c))
    {
        strcpy(str,getname(&c));
        p=i;
            while(p)
            {   
                if(strcmp(p->name,str)==0)
                {
                    strcpy(ocp, getSpec(p->DisName, d));
                    ame(ocp, l,&neuro,&genral,&cardio);    strcpy(str2, stp);
                    if(flag%2==0)
                    {o1=inor(o1, p->name, str2, p->DisName, c.data[c.front]);}
                    else if(flag%2!=0)
                    {   o2=inor(o2, p->name, str2, p->DisName, c.data[c.front]);}
                    break;
                }
                p=p->next;
            }
            flag++;
            cp=dequeue(&c);
            
        }
    printf("\t\t\t\t\t\t\t\t\t\tOPERATION THEATRE ONE SCHEDULE\n");
    printf("**************************************************************************************\n");
    pror(o1);
     printf("\t\t\t\t\t\t\t\t\t\tOPERATION THEATRE TWO SCHEDULE\n");
    printf("***************************************************************************************\n");
    pror(o2);
    if(o3!=NULL)
    {
        printf("These patients surgeries are pushed to the next day as the OR is already fully booked\n");
        por(o2);
    }
}
int main(int argc, const char * argv[]) {
    FILE * ptr1=fopen("/Users/vishalravi/Desktop/newdoctors.bin", "rb");
    FILE *ptr=fopen("/Users/vishalravi/Desktop/newdisease.bin", "rb");
    FILE *ptr2=fopen("/Users/vishalravi/Desktop/newpatient.bin", "rb");
    doc i11;Doctor d1=NULL;dis d9;disease d0=NULL;pat p;patient p1=NULL;
    while(fread(&i11,sizeof(doc),1,ptr1))
    { d1=insert(d1,i11.name,i11.ocp);}   //  disp(d1);
    while(fread(&d9,sizeof(dis),1,ptr))
     {d0=insertback(d0, d9.time,d9.name, d9.oc);}   //  display(d0);
    while(fread(&p,sizeof(pat),1,ptr2))
    {p1=inse(p1,p.name,p.Bgrp, p.dis, p.age,p.pri);}
    p1=getTime(p1, d0);
    int ch;char name[50],bgp[10],sname[50];int age,pri;
  //  schedule(d0, p1, d1);
   // printf("%d",check(d0, "Heart"));
    while(1)
    {
        printf("\t\t\t\t\t\t\t\t\tOPERATION THEATRE SCHEDULE \n\n");
        printf("1.Surgeries Performed in this Hospital\n");
        printf("2.Doctors currently on shift\n");
        printf("3.Patient who are admitted to get a surgery\n");
        printf("4.Operation Theatre Schedule Display\n");
        printf("5.To Add a new patient who has to get surgery\n");
        printf("6.Exit\n");
        printf("Enter your choice\n");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                    display(d0);
                    break;
            case 2:
                    disp(d1);
                    break;
            case 3:
                print(p1);
                break;
            case 4: schedule(d0, p1, d1);
                break;
            case 5:
                    printf("Enter the patient name:\n");
                    scanf("%s",name);
                    printf("Enter Blood Group of patient:\n");
                    scanf("%s",bgp);
                    printf("Enter the Surgery the patient requires:\n");
                    scanf("%c",sname);
                    scanf("%[^\n]",sname);
                    if(!check(d0, sname))
                    {
                        printf("This surgery is not performed in this hospital!!!!\n");
                        break;
                    }
                    printf("Enter Age\n");
                    scanf("%d",&age);
                    printf("How soon does the patient needs surgery(3-Immediate, 2-Avg, 3-Not serious)\n");
                    scanf("%d",&pri);
                    p1=inse(p1,name,bgp,sname,age,pri);
                    p1=getTime(p1, d0);
                    printf("\t\t\tt\t\tNEW OPERATION THEATRE SCHDEULE\n\n");
                    schedule(d0, p1, d1);
                    break;
                    
            case 6: exit(0);
            default:
                    printf("\nInvalid input\n");
                    break;
        }
    }
    free(d1);
    free(d0);
    free(p1);
    return 0;
    
}


