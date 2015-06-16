#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define MAX_CHAR        100             /* max characters per string */
#define MAXNUM          100             /* stack size increasement every time */
#define MAX_LENTH       10              /* the max length of every number */

#define TRUE            1
#define FALSE           0

#define YES                     1
#define NO                      -1
#define UN_KNOWN        0

#define SHIFT           1
#define REDUCE          2
#define GOTO            3
#define ACC                     4


typedef struct Regulate
{
        char **pregulates;
        int num;
}Regulate,*pRegulate;

typedef struct Closure
{
        int num;
        char **pregulate;
}Closure,*pClosure;


typedef struct Project
{
        int num;
        pClosure pclosure;

}Project,*pProject;

typedef struct Parse
{
        int num;
        char **pproceed;
}Parse,*pParse;

typedef struct Analyze          /* analyze table */
{
        int num;
        pParse pparse;
}Analyze,*pAnalyze;




typedef struct
{
        char *symbol;
        int num;
        int top;
}Stack_symbol,*pStack_symbol;   /* symbol stack */

typedef struct
{
        int *state;
        int num;
        int top;
}Stack_state,*pStack_state;     /* state(status) stack */


/* load the productions from file */
void input(pRegulate pregu,char *filename);

/* output the productions from file */
void output_regulate_from_file(pRegulate pregu);

/* construct the terminal & non-terminal symbol arrays */
void generate(pRegulate pregu,char **non_terminal,char **terminal);

/* symbol in terminal & non-terminal symbol arrays ? */
int symbol_found(char symbol,char *pgather);

/* save the productions from the user input to file */
void input_to_file(char *filename);


/* output the arrays */
void output_gather(char *pstring);

/* the string contains the given symbol ? */
int contain(char *string,char symbol);

/* the non-terminal symbol has none productions? */
int all_delete(char non_terminal,char **pregulates,int n);

/* get the index of symbol */
int get_index(char *pgaher,char symbol);

/* print the error message */
void print_error(char *perror);

/* the right part of production is NUL('~')? */
int contain_null(char *pregulates);

/* the all non-terminal symbols of the right part of production can derive NUL('~')? */
int all_are_null(char *pregulates,int *pnull,char *non_terminal);

/* the right part of production is indexed to NO? */
int contain_no(char *pregulates,int *pnull,char *non_terminal);

/* construct the symbol arrays which can derive NUL('~') */
void to_null(int **pnull,pRegulate pregu,char *non_terminal,char *terminal,int *pleft_recursive);

/* for debug, output the status of non-terminal symbols which whether can derive NUL('~') or not */
void output_null(int *pnull,int len);


/* void output_regulate_from_files(char **pregulates,int n); */

/* has unknown status? */
int exist_unknown(int *pnull,int n);

/* construct a symbol array which contains all symbols, non-terminal symbols,
 * terminal symbols and '#' included */
void get_all_symbol(char **pall_symbol,char *nonterminal,char *terminal);


void init_flag(int **pflag,int n);

/* the given symbol can derive NUL('~')? */
int can_obtain_null(char *non_terminal,int *pnull,char symbol);

/* calculate the FIRST SET */
char cal_FIRST(char symbol,char **pFIRST,pRegulate pregu, char *pall_symbol,char *terminal,char *non_terminal,int *pnull,int *flag,int *pleft_recursive);

/* add to the FIRST SET */
void addto_gather(char symbol,char newsymbol,char *non_terminal,char **pgather);

/* output the FOLLOW SET */
void output_follow(char **pFOLLOW,char *non_terminal);

/* output the FIRST SET */
void output_first(char **pFIRST,char *pall_symbol);

/* calculate the FOLLOW SET */
char cal_FOLLOW(char symbol,char **pFIRST,char **pFOLLOW,pRegulate pregu, char *pall_symbol,char *non_terminal,int *pnull,int *flag,int *pleft_recursive);

/* construct DFA */
void cal_DFA(pProject *ppro,int index,char **pFOLLOW,pRegulate pregu,pAnalyze *pana,char *pall_symbol,char *non_terminal,char *terminal);

/* construct CLOSURE */
void cal_closure(pProject *ppro,int index,pRegulate pregu,char *pregulate,char *non_terminal);

/* insert '.' to production, and save the result to PREGU argument */
void insert_dot(char **pregu,char *pregulate);

/* a new PROJECT? */
int is_newDFA(pProject *ppro,int num,char *pregulate);

/* init a PROJECT */
void init_DFA(pProject *ppro);

/* '.' moves back */
void dot_move_back(char *pregulate);

/* argument PGATHER contains argument SYMBOL? */
int obtained(char *pgather,char symbol);

void output_closure(pClosure pclosure);

/* output PROJECT SET */
void output_project(pProject ppro,int index);

/* outpu the element of analyze table */
void output_parse(pParse pparse,char *pall_symbol);

/* outpu the analyze table */
void output_analyze_table(pAnalyze pana,char *pall_symbol);

/* atoi() */
int string_to_int(char *pint);

/* itoa() */
void int_to_string(char **pitostr,int inum);

/* analyze the sentence whether matched syntax */
void parse(char *pcontent,pStack_state p_state,pStack_symbol p_symbol,pRegulate pregu,pAnalyze pana,char *pall_symbol);

/* get the sentences from user input */
void getcontents(char **pstring,char *terminal);

void output_DFA(pAnalyze pana,char *pall_symbol);

void output_info();



int main(int argc, char *argv[])
{
        Regulate regu;
        pProject ppro=NULL;
        pAnalyze pana=NULL;
        Stack_symbol  s_symbol;
        Stack_state       s_state;
        char *ptemp_regulate=NULL;
        char filename[]="productions.txt";
        char *non_terminal=NULL;
        char *terminal=NULL;
        int *pnull=NULL;
        char *pall_symbol=NULL;
        char **pFIRST=NULL;
        char **pFOLLOW=NULL;
        int *flag=NULL;
        int i;
        int k;
        int len_of_all_symbol;
        int len;
        int terminal_num;
        char *pcontent=NULL;
        int *pleft_recursive=NULL;      /* left recursive(direct or indirect)? */
        char *ptemp=NULL;

        printf("\n\t********************* SLR(1) Analyzer *******************");
        printf("\n\t*\tfunction:        analyze SLR(1)");
        printf("\n\t*\tlanguage:        C ");
        printf("\n\t*\tauthors: Youshen et David");
        printf("\n\t*********************************************************\n");
        printf("\n\t\t\tWelcome to use");
        output_info();

        input_to_file(filename);
        input(&regu,filename);
        output_regulate_from_file(&regu);

        if(0==regu.num)
                print_error("\nNo productions found");

        generate(&regu,&non_terminal,&terminal);

        len=strlen(non_terminal)+1;
        pleft_recursive=(int*)malloc(sizeof(int)*len);
        for(i=0;i<len;i++)
        {
                pleft_recursive[i]=FALSE;               /* initiate to false */
        }
        to_null(&pnull,&regu,non_terminal,terminal,pleft_recursive);


        /* output_null(pnull,strlen(non_terminal)); */ /* for debugging */
        get_all_symbol(&pall_symbol,non_terminal,terminal);

        /* output_gather(pall_symbol); */               /* for debugging */


        len_of_all_symbol=strlen(pall_symbol);
        len=strlen(non_terminal)+1;


        pFIRST=(char **)malloc(sizeof(char*)*len_of_all_symbol);

        pFOLLOW=(char **)malloc(sizeof(char*)*(len)); /* '$' included */
        for(i=0;i <len_of_all_symbol;i++)
        {
                pFIRST[i]=NULL;

        }
        for(i=0;i<len;i++)
        {
                pleft_recursive[i]=FALSE;
                pFOLLOW[i]=NULL;


        }
        init_flag(&flag,len_of_all_symbol);

        /* output_null(flag,len_of_all_symbol); */


        for(i=0;i<len_of_all_symbol;i++)
        {

                cal_FIRST(pall_symbol[i],pFIRST,&regu,pall_symbol,terminal,non_terminal,pnull,flag,pleft_recursive);

        }

        output_first(pFIRST,pall_symbol);

        /* reset flags */
        for(i=0;i<len_of_all_symbol;i++)
        {
                flag[i]=FALSE;
        }

        for(i=0;i<len-1;i++)
        {
                cal_FOLLOW(non_terminal[i],pFIRST,pFOLLOW,&regu,pall_symbol,non_terminal,pnull,flag,pleft_recursive);
        }

        output_follow(pFOLLOW,non_terminal);

        /* construct DFA and analyze table */


        terminal_num=strlen(terminal);
        ptemp=(char*)malloc(sizeof(char)*(terminal_num+2));
        if(!ptemp)
                print_error("\nCan not get more memory!");
        strcpy(ptemp,terminal);
        strcat(ptemp,"#");

        terminal=ptemp;


        insert_dot(&ptemp_regulate,regu.pregulates[0]);
        init_DFA(&ppro);  /* initiate the first project */

        cal_closure(&ppro,0,&regu,ptemp_regulate,non_terminal);

        len_of_all_symbol=strlen(pall_symbol);

        for(i=0;i<=ppro->num;i++)
        {

                pana=(pAnalyze)realloc(pana,sizeof(Analyze)*(i+1));
                pana->num=i;


                pana[i].pparse=(pParse)malloc(sizeof(Parse));
                pana[i].pparse->num=len_of_all_symbol;
                pana[i].pparse->pproceed=(char**)malloc(sizeof(char*)*(len_of_all_symbol));


                for(k=0;k<len_of_all_symbol;k++)
                {
                        pana[i].pparse->pproceed[k]=NULL;
                }


                cal_DFA(&ppro,i,pFOLLOW,&regu,&pana,pall_symbol,non_terminal,terminal);


        }
        output_project(ppro,ppro->num);
        output_DFA(pana,pall_symbol);
        output_analyze_table(pana,pall_symbol);
        printf("\nthe productions can be SLR(1) analyzed\n");

        getcontents(&pcontent,terminal);


        parse(pcontent,&s_state,&s_symbol,&regu,pana,pall_symbol);

        printf("Over\n");

        return 0;
}




void output_info()
{
        printf("\n\t\t---------------------------------------");
        printf("\n\t\t\tPress Enter please...");
        getchar();
}

void output_DFA(pAnalyze pana,char *pall_symbol)
{
        int len;
        int i;
        int j;
        int inum;
        len=strlen(pall_symbol);
        printf("\nDFA:");
        printf("\n-------------------------------------------------------------------\n");
        for(i=0;i<len;i++)
        {
                if('$'==pall_symbol[i] || '#'==pall_symbol[i])
                        continue;
                printf("\t%c",pall_symbol[i]);
        }
        for(i=0;i<=pana->num;i++)
        {
                printf("\nP[%d]",i);

                for(j=0;j<len;j++)
                {
                        if(j==get_index(pall_symbol,'$') || j==get_index(pall_symbol,'#'))
                                continue;
                        if(!pana[i].pparse->pproceed[j]
                                        || 'R'==pana[i].pparse->pproceed[j][0]
                                        || 'A'==pana[i].pparse->pproceed[j][0])
                        {
                                printf("\t  ");
                        }
                        else if('S'==pana[i].pparse->pproceed[j][0])
                        {
                                inum=string_to_int(pana[i].pparse->pproceed[j]+1);
                                printf("\tP[%d]",inum);
                        }
                        else
                        {
                                inum=string_to_int(pana[i].pparse->pproceed[j]);
                                printf("\tP[%d]",inum);
                        }
                }
        }
        output_info();
}



void input_to_file(char *filename)
{
        FILE *fp;
        char string[20];

        char temp1[20];
        int num=1;

        printf("\nPlease input productions(e.g. A->a) \n['$' reserved for the beginning symbol, '~' stands for NUL, two ENTER for end]\n\n");
        fgets(string, sizeof(string), stdin);

        while(0==strcmp(string,""))
                fgets(string, sizeof(string), stdin);

        if((fp=fopen(filename,"w"))==NULL)
        {
                printf("Cannot open this file!\n");
                exit(0);
        }

        while(string[0]>='A'&&string[0]<='Z'&&string[1]=='-'&&string[2]=='>'&&string[3]!='\0')
        {
                int i=3;
                char temp[20];
                char *p=string+3;
                char *q=string+3;

                if(1==num)
                {
                        temp1[0]='$';temp1[1]='-';temp1[2]='>';temp1[3]=string[0];temp1[4]='\0';
                        fprintf(fp,"%s\n",temp1);
                }
                num++;

                temp[0]=string[0];
                temp[1]=string[1];
                temp[2]=string[2];
                temp[3]='\0';

                if(contain(string,'|'))
                {
                        while(*q!='\0')
                        {
                                if(*q=='|')
                                {
                                        while(p<q)
                                        {
                                                temp[i]=*p;
                                                i++;
                                                p++;
                                        }
                                        temp[i]='\0';

                                        fprintf(fp,"%s\n",temp);
                                        i=3;
                                        p=q+1;

                                }
                                q++;
                        }

                        while(p<q)
                        {
                                temp[i]=*p;
                                i++;
                                p++;
                        }
                        temp[i]='\0';

                        fprintf(fp,"%s\n",temp);
                }
                else
                {

                        fprintf(fp,"%s\n",string);
                }

                fgets(string, sizeof(string), stdin);


        }
        fclose(fp);
}

int contain(char *string,char symbol)
{
        char *p=string;
        while(*p!='\0')
        {
                if(*p==symbol)
                        return TRUE;
                p++;
        }
        return FALSE;
}

int pop_state(pStack_state p_stack)
{

        if(p_stack->top >=0)
                return p_stack->state[p_stack->top--];
        else
        {
                printf("\n error:at the bottom of the db_stack!exit...\n");
                exit(1);
                return p_stack->state[p_stack->top];
        }
}
char pop_symbol(pStack_symbol p_stack)
{
        if(p_stack->top )
                return p_stack->symbol[p_stack->top--];
        else
        {
                printf("\n error:at the bottom of the db_stack!exit...\n");
                exit(1);
                return p_stack->symbol[p_stack->top];
        }
}


void push_symbol(pStack_symbol p_stack,char t)
{
        if(p_stack->top<p_stack->num)
                p_stack->symbol[++(p_stack->top)]=t;
        else
        {
                p_stack->symbol=(char*)realloc(p_stack->symbol,sizeof(char)*(p_stack->num+MAXNUM));
                p_stack->symbol[++(p_stack->top)]=t;
        }

}
void push_state(pStack_state p_stack,int t)
{
        if(p_stack->top<p_stack->num)
                p_stack->state[++(p_stack->top)]=t;
        else
        {
                p_stack->state=(int*)realloc(p_stack->state,sizeof(int)*(p_stack->num+MAXNUM));
                p_stack->state[++(p_stack->top)]=t;
        }


}


void print_symbol_stack(pStack_symbol p_stack)
{
        int i=1;
        printf("\t");
        while(i<=p_stack->top)
        {
                printf("%c",p_stack->symbol[i]);
                i++;
        }
}


void print_state_stack(pStack_state p_stack)
{
        int i=1;
        printf("\t");
        while(i<=p_stack->top)
        {
                printf("%d",p_stack->state[i]);
                i++;
        }
}


void getcontents(char **pstring,char *terminal)
{
        char t;
        int i=0;
        printf("\nPlease input  any symbol of \"%s\". \t'#' indicates the end:\n",terminal);
        scanf("%c",&t);
        *pstring=(char*)malloc(sizeof(char)*2);
        while('#'!=t)
        {
                (*pstring) =(char*)realloc(*pstring,sizeof(char)*(i+3));
                (*pstring)[i]=t;
                scanf("%c",&t);

                i++;
        }
        (*pstring)[i]='#';
        (*pstring)[++i]='\0';

}

void stack_symbol_init(pStack_symbol p_stack)
{

        p_stack->symbol=(char*)malloc(sizeof(char)*MAXNUM);
        p_stack->num=MAXNUM;
        p_stack->top=0;
}


void stack_state_init(pStack_state p_stack)
{
        p_stack->state=(int*)malloc(sizeof(int)*MAXNUM);
        p_stack->num=MAXNUM;
        p_stack->top=0;

}

char get_stack_symbol_top(pStack_symbol p_stack)
{
        return p_stack->symbol[p_stack->top];
}


int get_stack_state_top(pStack_state p_stack)
{
        return p_stack->state[p_stack->top];
}


void parse(char *pcontent,pStack_state p_state,pStack_symbol p_symbol,pRegulate pregu,pAnalyze pana,char *pall_symbol)
{
        char *pre;
        char *ptemp;
        int top_state;
        char temp;
        int convert2num;
        int num;
        int result;
        int i;
        int step=0;
        char *pregulate;


        stack_state_init(p_state);
        stack_symbol_init(p_symbol);
        push_state(p_state,0);
        push_symbol(p_symbol,'#');


        printf("\nstep\tstate\t\tsymbol\t\tstring\t\taction\n");
        while('\0'!=*pcontent)
        {

                step++;
                printf("%d",step);
                print_state_stack(p_state);
                printf("\t");
                print_symbol_stack(p_symbol);
                printf("\t\t%s\t",pcontent);
                top_state=get_stack_state_top(p_state);


                /* get the action from ACTION table */
                pre=pana[top_state].pparse->pproceed[get_index(pall_symbol,*pcontent)];

                if(!pre)
                {
                        printf("\terror\n");
                        exit(1);
                }

                temp=pre[0]; /* get the first symbol from ACTION table */
                /* printf("%c",temp); */

                switch(temp)
                {
                        case 'S': /* SHIFT */
                                convert2num=0;
                                printf("\tshift\n");
                                convert2num=string_to_int(pre+1);

                                push_state(p_state,convert2num);
                                push_symbol(p_symbol,*pcontent);
                                pcontent++;

                                break;

                        case 'R': /* REDUCE */
                                convert2num=0;
                                printf("\treduce\n");
                                convert2num=string_to_int(pre+1);

                                ptemp=pregu->pregulates[convert2num];

                                if('~'!=ptemp[3])
                                {
                                        num=strlen(ptemp)-3;
                                        for(i=0;i<num;i++)
                                        {

                                                pop_state(p_state);
                                                pop_symbol(p_symbol);
                                        }
                                }

                                /* get top stack state */
                                top_state=get_stack_state_top(p_state);

                                /* get the left symbol of current production */
                                pregulate=pana[top_state].pparse->pproceed[get_index(pall_symbol,ptemp[0])];
                                if(!pregulate)
                                {
                                        printf("\nerror:goto table error!");
                                        exit(1);
                                }

                                result=string_to_int(pregulate);

                                /* push the symbol and state */
                                push_state(p_state,result);
                                push_symbol(p_symbol,ptemp[0]);


                                break;

                        case 'A':
                                printf("\taccept\n");
                                exit(0);
                                break;
                        default:
                                printf("\terror:!");
                                exit(1);
                }
        }
}





void output_parse(pParse pparse,char *pall_symbol)
{
        int i;
        for(i=0;i<pparse->num;i++)
        {
                if('$'==pall_symbol[i])
                        continue;
                if(!pparse->pproceed[i])
                        printf("\t  ");
                else
                        printf("\t%s ",pparse->pproceed[i]);

        }
}
void output_analyze_table(pAnalyze pana,char *pall_symbol)
{
        int i;
        int len=strlen(pall_symbol);
        printf("\n Analyze Table \n-------------------------------------------------------------------\n");
        for(i=0;i<len;i++)
        {
                if('$'==pall_symbol[i])
                        continue;
                printf("\t%c",pall_symbol[i]);
        }
        for(i=0;i<=pana->num;i++)
        {
                printf("\n[%d]",i);

                output_parse(pana[i].pparse,pall_symbol);
        }
        output_info();
}



void output_closure(pClosure pclosure)
{
        int i;
        for(i=0;i<pclosure->num;i++)
                printf("\n%s   ",pclosure->pregulate[i]);
}


void output_project(pProject ppro,int index)
{
        int i;
        printf("\n\nProject Set");
        printf("\n---------------------------------------------");
        for(i=0;i<=index;i++)
        {
                printf("\n----------------------");
                printf("\nProject[%d]:",i);
                output_closure(ppro[i].pclosure);
        }

        output_info();
}


/* get the first symbol after '.' in production */
char get_symbol_after_dot(char *pregulate)
{
        char *p=pregulate;
        while(*p)
        {
                if('.'==*p)
                        return *(p+1);
                p++;
        }
        return *p;
}

/* delete the '.' from production */
void delete_dot(char *pregulate)
{
        int len;
        int i;
        int index;
        len=strlen(pregulate);
        index=get_index(pregulate,'.');
        for(i=index;i<len;i++)
        {
                pregulate[i]=pregulate[i+1];
        }
}

int get_action(char symbol,char *terminal)
{

        if('\0'==symbol)
                return REDUCE;
        else if(obtained(terminal,symbol))
                return SHIFT;
        else
                return GOTO;
}

void  insert_symbol(char *pitostr,char temp,int index)
{
        int i;

        for(i=index;i>0;i--)
        {
                pitostr[i]=pitostr[i-1];
        }
        pitostr[i]=temp;

}


void int_to_string(char **pitostr,int inum)
{
        int i;
        int mod;
        int len;

        char temp[MAX_LENTH];
        for(i=0;i<MAX_LENTH;i++)
                temp[i]='\0';

        mod=inum%10;

        if(0==inum)
        {
                (*pitostr)=(char *)malloc(sizeof(char)*2);
                (*pitostr)[0]='0';
                (*pitostr)[1]='\0';
                return ;
        }

        i=0;
        while(inum>10)
        {
                temp[i]=mod+'0';
                i++;

                inum=(inum-mod)/10;

                mod=inum%10;

        }

        if(mod==0)
        {

                temp[i]=mod+'0';
                mod=inum/10;
                i++;
                temp[i]=mod+'0';

                temp[i+1]='\0';
        }
        else
        {
                temp[i]=mod+'0';
                temp[i+1]='\0';
        }
        len=strlen(temp);
        (*pitostr)=(char *)malloc(sizeof(char)*(len+1));

        for(i=len;i>0;i--)
                (*pitostr)[len-i]=temp[i-1];
        (*pitostr)[len]='\0';

}




void cal_analyze_table(char *pregulate,char **pFOLLOW,pAnalyze *pana,int status,int to_status,pRegulate pregu,char *non_terminal,char *terminal,char *pall_symbol)
{
        char symbol;
        int index;
        char *ptemp_regulate=NULL;
        char *itostr=NULL;
        int len;
        int length;
        int flag;
        int i;
        int j;


        ptemp_regulate=pregulate;


        symbol=get_symbol_after_dot(ptemp_regulate);



        flag=get_action(symbol,terminal);





        switch(flag)
        {
                case GOTO: /* if the symbol after '.' is non-terminal symbol, construct the GOTO table */

                        index=get_index(pall_symbol,symbol);
                        int_to_string(&itostr,to_status);


                        len=strlen(itostr);
                        /*if((*pana)[status].pparse->pproceed[index])
                                print_error("\nthe productions cannot be SLR(1) analyzed\nExit...\n");
*/
                        (*pana)[status].pparse->pproceed[index]=(char*)malloc(sizeof(char)*(len+1));
                        strcpy((*pana)[status].pparse->pproceed[index],itostr);


                        break;

                case REDUCE: /* if the symbol after '.' is '\0', do REDUCE,
                                if it's '$', do accept */


                        /* dot_move_back(pregulate); */
                        ptemp_regulate=(char*)malloc(sizeof(char)*(strlen(pregulate)+1));
                        strcpy(ptemp_regulate,pregulate);
                        delete_dot(ptemp_regulate);
                        if('\0'==ptemp_regulate[3])
                                ptemp_regulate[3]='~';
                        for(i=0;i<pregu->num;i++)
                                if(0==strcmp(ptemp_regulate,pregu->pregulates[i]))
                                        break;

                        /* find the production's index */
                        int_to_string(&itostr,i);
                        len=strlen(itostr);

                        length=strlen(terminal);
                        index=get_index(non_terminal,ptemp_regulate[0]);

                        /* scan all the terminal symbols, if they belong to the
                         * FOLLOW SET of left non-terminal symbol of production,
                         * do construct */
                        for(j=0;j<length;j++)
                        {


                                if(!obtained(pFOLLOW[index],terminal[j]))
                                        continue;

                              /*  if((*pana)[status].pparse->pproceed[j])
                                {

                                        print_error("\nthe productions cannot be SLR(1) analyzed\Exit...\n");
                                }*/
                                (*pana)[status].pparse->pproceed[j]=(char*)malloc(sizeof(char)*(len+2));
                                if('$'==ptemp_regulate[0])     /* if the left part of production is '$', accept */
                                {
                                        strcpy((*pana)[status].pparse->pproceed[j],"ACC");
                                }
                                else
                                {

                                        strcpy((*pana)[status].pparse->pproceed[j],"R");
                                        strcat((*pana)[status].pparse->pproceed[j],itostr);
                                }
                                /*      (*pana)[status].pparse->num++; */
                        }
                        break;


                case SHIFT:  /* if the symbol after '.' is terminal symbol, do SHIFT */
                        index=get_index(pall_symbol,symbol);
                        int_to_string(&itostr,to_status);

                        len=strlen(itostr);
                        /*if((*pana)[status].pparse->pproceed[index])
                                print_error("\nthe productions cannot be SLR(1) analyzed\Exit...\n");*/
                        (*pana)[status].pparse->pproceed[index]=(char*)malloc(sizeof(char)*(len+2));
                        strcpy((*pana)[status].pparse->pproceed[index],"S");
                        strcat((*pana)[status].pparse->pproceed[index],itostr);
                        /*      (*pana)[status].pparse->num++; */
                        break;


                default:
                        print_error("\n in cal_annalyze_table()...\nEXIT...\n");
        }
}




int found(char *pregulate,pClosure pclosure)
{
        int i;
        for(i=0;i<pclosure->num;i++)
                if(0==strcmp(pregulate,pclosure->pregulate[i]))
                        return TRUE;
        return FALSE;
}

int all_regulate_equal(pClosure pclosure1,pClosure pclosure2)
{
        int i;

        if(pclosure1->num!=pclosure2->num)
                return FALSE;
        else
        {
                for(i=0;i<pclosure1->num;i++)
                        if(!found(pclosure1->pregulate[i],pclosure2) || !found(pclosure2->pregulate[i],pclosure1))
                                return FALSE;
                return TRUE;
        }
}



/* '.' moves forward */
void  dot_move_forward(char *pregulate)
{
        char *p=pregulate;
        char temp;
        while(*p)
        {
                if('.'==*p)
                {
                        temp=*p;
                        *p=*(p-1);
                        *(p-1)=temp;
                        return ;
                }
                p++;
        }
}

int is_newDFA(pProject *ppro,int num,char *pregulate)
{
        int i;
        int j;
        char *pregu=NULL;
        char *ptemp_regulate=(char*)malloc(sizeof(char)*(strlen(pregulate)+1));
        strcpy(ptemp_regulate,pregulate);
        dot_move_back(ptemp_regulate);

        for(i=0;i<=(*ppro)->num;i++)
        {
                if(found(ptemp_regulate,(*ppro)[i].pclosure))
                {


                        for(j=0;j<(*ppro)[i].pclosure->num;j++)
                        {
                                /* if it's '.', it's not core */
                                if('.'==(*ppro)[i].pclosure->pregulate[j][3])
                                {
                                        continue;
                                }

                                pregu=(char*)malloc(sizeof(char)*(strlen((*ppro)[i].pclosure->pregulate[j])+1));
                                strcpy(pregu,(*ppro)[i].pclosure->pregulate[j]);

                                dot_move_forward(pregu);

                                if(!found(pregu,(*ppro)[num].pclosure))
                                {


                                        free(pregu);
                                        pregu=NULL;
                                        break;
                                }
                                /*      else
                                        printf("\n production %s is in project %s!!",(*ppro)[i].pclosure->pregulate[j],num); */

                        }
                        if(j==(*ppro)[i].pclosure->num)
                        {

                                return i;
                        }

                }

        }
        if(i>(*ppro)->num)
        {

                return  NO;
        }
        else
                return i;

}


void dot_move_back(char *pregulate)
{
        char *p=pregulate;
        char temp;
        while(*p)
        {
                if('.'==*p)
                {
                        temp=*(p+1);
                        *(p+1)='.';
                        *p=temp;
                        return ;
                }
                else
                        p++;
        }
}


void insert_dot(char **pregu,char *pregulate)
{
        int i;
        int len=strlen(pregulate);
        (*pregu)=(char *)malloc(sizeof(char)*(len+2));
        for(i=0;i<=len;i++)
        {
                if(i<3)
                        (*pregu)[i]=pregulate[i];
                else if(3==i)
                {
                        if('~'==pregulate[i])
                        {
                                (*pregu)[i]='.';
                                (*pregu)[i+1]='\0';
                                return;
                        }
                        else
                        {
                                (*pregu)[i]='.';
                                (*pregu)[i+1]=pregulate[i];
                        }
                }
                else
                        (*pregu)[i+1]=pregulate[i];
        }
}

/* the symbol after '.' is calculated (that is the symbol after '.' is same
 / in several productions in one project) */

int exist_DFA(char *pregulate,Analyze pana,char *pall_terminal,int *pindex)
{
        int index;
        char symbol;
        char *p;
        symbol=get_symbol_after_dot(pregulate);

        index=get_index(pall_terminal,symbol);
        if(NULL==pana.pparse->pproceed[index])
        {

                return FALSE;
        }
        else
        {

                p=pana.pparse->pproceed[index];

                if('S'==p[0] )
                {       p++;
                        *pindex=string_to_int(p);
                        return TRUE;
                }
                else if('0'<=p[0] && p[0]<='9')
                {
                        *pindex=string_to_int(p);
                        return TRUE;
                }
              /*  else if('R'==p[0])
                {
                        print_error("\nthe productions cannot be SLR(1) analyzed");

                }*/
                /*      else

                        printf("\n accepted symbol?"); */
                return -1;

        }
}


int string_to_int(char *pint)
{
        int str2num=0;
        char *p=pint;
        while(*p!='\0')
        {
                str2num=str2num*10+(*p-'0');
                p++;
        }
        return str2num;
}

void cal_DFA(pProject *ppro,int index,char **pFOLLOW,pRegulate pregu,pAnalyze *pana,char *pall_symbol,char *non_terminal,char *terminal)
{
        int num;
        char *pregulate=NULL;
        int i;
        char temp_char;
        char *ptemp_regulate=NULL;
        int  to_index=-1;
        /* pProject ptemp_project=NULL; */


        num=(*ppro)[index].pclosure->num;

        for(i=0;i<num;i++)              /* scan every production in one project */
       {
                pregulate=(*ppro)[index].pclosure->pregulate[i];



                temp_char=get_symbol_after_dot(pregulate);

                if(temp_char!='\0')     /* the symbol after '.' is NOT '\0' */
                {
                        /* if the symbol after '.' is calculated, find the project and
                         * save it to argument TO_INDEX */
                        if(exist_DFA(pregulate,(*pana)[index],pall_symbol,&to_index))
                        {


                                /*      output_project(*ppro,1); */

                                if(to_index>index)
                                {
                                        ptemp_regulate=(char*)malloc(sizeof(char)*(strlen(pregulate)+1));
                                        strcpy(ptemp_regulate,pregulate);
                                        dot_move_back(ptemp_regulate);
                                        cal_closure(ppro,to_index,pregu,ptemp_regulate,non_terminal);
                                }

                                /*      exit(1); */

                        }
                        else
                        {

                                /* if the same project exists, free it */
                               if((to_index=is_newDFA(ppro,index,pregulate))!=NO)
                                {
                                        cal_analyze_table(pregulate,pFOLLOW,pana,index,to_index,pregu,non_terminal,terminal,pall_symbol);

                                }
                                else
                                {
                                        *ppro=(pProject)realloc(*ppro,sizeof(Project)*((*ppro)->num+2));
                                        if(!*ppro)
                                        {
                                                printf("\nERROR:Can not malloc memory!");
                                                exit(1);
                                        }


                                        (*ppro)->num++;
                                        (*ppro)[(*ppro)->num].pclosure=(pClosure)malloc(sizeof(Closure));
                                        (*ppro)[(*ppro)->num].pclosure->pregulate=NULL;
                                        (*ppro)[(*ppro)->num].pclosure->num=0;



                                        ptemp_regulate=(char*)malloc(sizeof(char)*(strlen(pregulate)+1));
                                        strcpy(ptemp_regulate,pregulate);
                                        dot_move_back(ptemp_regulate);



                                        cal_closure(ppro,(*ppro)->num,pregu,ptemp_regulate,non_terminal);


                                        cal_analyze_table(pregulate,pFOLLOW,pana,index,(*ppro)->num,pregu,non_terminal,terminal,pall_symbol);



                                }
                        }
                }
                else            /* if the symbol after '.' is '\0' */
                {

                        cal_analyze_table(pregulate,pFOLLOW,pana,index,UN_KNOWN,pregu,non_terminal,terminal,pall_symbol);

                }

        }

}



void init_DFA(pProject *ppro)
{
        (*ppro)=(pProject)malloc(sizeof(Project));
        (*ppro)->pclosure=(pClosure)malloc(sizeof(Closure));
        (*ppro)->num=0;
        (*ppro)->pclosure->num=0;
        (*ppro)->pclosure->pregulate=NULL;
}

void cal_closure(pProject *ppro,int index,pRegulate pregu,char *pregulate,char *non_terminal)
{
        int num;
        int len=strlen(pregulate);
        char symbol;
        int i;
        int j;
        char *ptemp_regulate=NULL;
        num=(*ppro)[index].pclosure->num;

        (*ppro)[index].pclosure->pregulate=(char **)realloc((*ppro)[index].pclosure->pregulate,(num+1)*sizeof(char*));
        (*ppro)[index].pclosure->pregulate[num]=(char*)malloc(sizeof(char)*(len+1));
        strcpy((*ppro)[index].pclosure->pregulate[num],pregulate);
        (*ppro)[index].pclosure->num++;
        num=(*ppro)[index].pclosure->num;

        for(i=0;i<(*ppro)[index].pclosure->num;i++)
        {
                symbol=get_symbol_after_dot((*ppro)[index].pclosure->pregulate[i]);

                /* if the symbol after '.' is not-terminal symbol */
                if(obtained(non_terminal,symbol))
                {
                        for(j=0;j<pregu->num;j++)
                        {
                                /* find all the productions belong to the symbol */
                                if(symbol==pregu->pregulates[j][0])
                                {


                                        num=(*ppro)[index].pclosure->num;
                                        insert_dot(&ptemp_regulate,pregu->pregulates[j]);

                                        if(found(ptemp_regulate,(*ppro)[index].pclosure))
                                                continue;
                                        (*ppro)[index].pclosure->pregulate=(char **)realloc((*ppro)[index].pclosure->pregulate,(num+1)*sizeof(char*));
                                        (*ppro)[index].pclosure->pregulate[num]=(char*)malloc(sizeof(char)*(len+2));
                                        strcpy((*ppro)[index].pclosure->pregulate[num],ptemp_regulate);
                                        (*ppro)[index].pclosure->num++;
                                }
                        }
                }
        }
}





int contain_symbol(char * p,char symbol)  /* FOLLOW SET */
{
        char *ptemp=p;
        int i;
        int length=strlen(ptemp);

        for(i=3;i<length;i++)
        {
                if(symbol==ptemp[i])
                        return i;
        }
        return FALSE;
}

#if 0
void first_add(char symbol,char newsymbol,int id,char *pall_symbol,char **pFIRST)
{
        int index_newsymbol=get_index(pall_symbol,newsymbol);
        int j;
        int len=strlen(pFIRST[index_newsymbol]);
        for(j=0;j<len;j++)
        {

                if(TRUE==id) /* delete the NUL('~') when adding to the SET */
                {


                        if('~'==pFIRST[index_newsymbol][j])
                                continue;
                        addto_gather(symbol,pFIRST[index_newsymbol][j],pall_symbol,pFIRST);
                }
                else
                {
                        /* if('\0'==FIRST[index_newsymbol][j])
                           continue; */

                        addto_gather(symbol,pFIRST[index_newsymbol][j],pall_symbol,pFIRST);

                }

        }

}

#endif

void follow_add_from_first(char symbol,char FIRST_element,char *non_terminal,char *pall_symbol,char **pFIRST,char **pFOLLOW)
{

        int index_first;

        int i;
        int len;
        index_first=get_index(pall_symbol,FIRST_element);
        len=strlen(pFIRST[index_first]);
        for(i=0;i<len;i++)
        {
                if('~'==pFIRST[index_first][i])
                        continue;
                addto_gather(symbol,pFIRST[index_first][i],non_terminal,pFOLLOW);
        }


}

void follow_add(char symbol,char newsymbol,char *non_terminal,char **pFOLLOW)
{


        int index_follow;
        int i;
        int len;
        if('~'==newsymbol)
                return ;
        index_follow=get_index(non_terminal,newsymbol);
        if(!pFOLLOW[index_follow])
                return ;
        len=strlen(pFOLLOW[index_follow]);
        for(i=0;i<len;i++)
        {
                addto_gather(symbol,pFOLLOW[index_follow][i],non_terminal,pFOLLOW);
        }



}


char cal_FOLLOW(char symbol,char **pFIRST,char **pFOLLOW,pRegulate pregu, char *pall_symbol,char *non_terminal,int *pnull,int *flag,int *pleft_recursive)
{
        char **p=pregu->pregulates;
        int j;

        if(flag[get_index(non_terminal,symbol)])
                return symbol;

        /* if the current symbol is false when checking left recursive,
         * change it to true */
        if(!pleft_recursive[get_index(non_terminal,symbol)])
                pleft_recursive[get_index(non_terminal,symbol)]=TRUE;


        /*      output_regulate_from_file(pregu); */


        for(j=0;j<pregu->num;j++)
                if(p[j]) /* scan all the productions */
                {
                        int position=contain_symbol(p[j],symbol); /* find the current symbol's position */
                        int length=strlen(p[j]);
                        int i;
                        char *ptemp=p[j];


                        if('$'==symbol) /* the beginning symbol */
                                addto_gather(symbol,'#',non_terminal,pFOLLOW);

                        if(FALSE==position) /* find the current symbol's production */
                        {
                                /*      p++; */
                                continue;
                        }

                        /* if the current symbol stands at the most right position of production */
                        if(position==length-1 )
                        {
                                if(ptemp[0]==ptemp[position])
                                {
                                        continue;
                                }
                                else if(pleft_recursive[get_index(non_terminal,ptemp[0])])
                                        follow_add(symbol,ptemp[0],non_terminal,pFOLLOW);
                                else
                                        follow_add(symbol,cal_FOLLOW(ptemp[0],pFIRST,pFOLLOW,pregu,pall_symbol,non_terminal,pnull,flag,pleft_recursive),non_terminal,pFOLLOW);
                                /*              output_follow(pFOLLOW,non_terminal);
                                                return symbol; */
                        }
                        else
                        {

                                /* add all the symbols after current symbol to FOLLOW(symbol) */
                                for(i=position+1;i<length;i++)
                                {

                                        /* if there is a symbol cannot derive NUL('~'), scan next production */
                                        if(!can_obtain_null(non_terminal,pnull,ptemp[i]))
                                        {
                                                follow_add_from_first(symbol,ptemp[i],non_terminal,pall_symbol,pFIRST,pFOLLOW);
                                                break;
                                        }
                                        else
                                        {
                                                follow_add_from_first(symbol,ptemp[i],non_terminal,pall_symbol,pFIRST,pFOLLOW); /* delete NUL('~') */
                                        }

                                }
                                if(i==length) /* if all the symbols after current symbol can derive NUL('~') */
                                {
                                        if(pleft_recursive[get_index(non_terminal,ptemp[0])])
                                                follow_add(symbol,ptemp[0],non_terminal,pFOLLOW);
                                        else
                                                follow_add(symbol,cal_FOLLOW(ptemp[0],pFIRST,pFOLLOW,pregu,pall_symbol,non_terminal,pnull,flag,pleft_recursive),non_terminal,pFOLLOW);
                                }
                        }
                        /*      p++; */
                }

        pleft_recursive[get_index(non_terminal,symbol)]=FALSE;

        flag[get_index(non_terminal,symbol)]=TRUE;
        return symbol;
}

void output_first(char **pFIRST,char *pall_symbol)
{
        int len=strlen(pall_symbol);
        int i;
        printf("\n\nFIRST SET\n");
        for(i=0;i<len;i++)
        {
                if(pFIRST[i])
                        printf("\nFIRST[%c]=%s",pall_symbol[i],pFIRST[i]);
        }
        output_info();
}

void output_follow(char **pFOLLOW,char *non_terminal)
{
        int len=strlen(non_terminal);
        int i;
        printf("\n\nFOLLOW SET\n\n");
        for(i=0;i<len;i++)
        {
                if(pFOLLOW[i])
                        printf("\nFOLLOW[%c]=%s",non_terminal[i],pFOLLOW[i]);
        }
        output_info();
}

void init_flag(int **pflag,int n)
{
        int i;
        *pflag=(int*)malloc(sizeof(int)*n);
        for(i=0;i<n;i++)
                (*pflag)[i]=FALSE;
}


int obtained(char *pgather,char symbol)
{
        int i;
        int index=strlen(pgather);
        for(i=0;i<index;i++)
        {
                if(pgather[i]==symbol)
                {
                        return TRUE;
                }
        }


        return FALSE;
}



int can_obtain_null(char *non_terminal,int *pnull,char symbol)
{

        int index;
        if(!obtained(non_terminal,symbol))
                return FALSE;
        index=get_index(non_terminal,symbol);
        if(pnull[index]==YES)
                return TRUE;
        else
                return FALSE;
}


int is_regulate_right_nonterminal(char *pregu,char *terminal)
{
        char *p=pregu;
        int i;
        int length=strlen(p);
        for(i=3;i<length;i++)
        {
                if(obtained(terminal,p[i]))
                        return FALSE;
        }
        return TRUE;
}


int is_equal(char *psymbol)
{
        char *ptemp=psymbol;
        if(ptemp[0]==ptemp[3])
        {
                return TRUE;
        }
        else
        {
                return  FALSE;
        }
}

int get_position(char *pregu,char *non_terminal,int *pnull)
{
        char *p=pregu;
        int i;
        int length=strlen(p);
        for(i=3;i<length;i++)
        {
                if(!can_obtain_null(non_terminal,pnull,p[i]))
                {
                        return i;
                }
        }
        return FALSE;
}



void first_add(char symbol,char newsymbol,int id,char *pall_symbol,char **pFIRST)
{
        int index_newsymbol=get_index(pall_symbol,newsymbol);
        int j;
        int len;
        if(!pFIRST[index_newsymbol])
                return ;
        len=strlen(pFIRST[index_newsymbol]);
        for(j=0;j<len;j++)
        {

                if(TRUE==id) /* delete NUL('~') when adding to the SET */
                {


                        if('~'==pFIRST[index_newsymbol][j])
                                continue;
                        addto_gather(symbol,pFIRST[index_newsymbol][j],pall_symbol,pFIRST);
                }
                else
                {
                        /* if('\0'==FIRST[index_newsymbol][j])
                           continue; */

                        addto_gather(symbol,pFIRST[index_newsymbol][j],pall_symbol,pFIRST);

                }

        }

}

void addto_gather(char symbol,char newsymbol,char *non_terminal,char **pgather)
{
        int index;
        int len;
        index=get_index(non_terminal,symbol);

        if(!pgather[index])
        {
                pgather[index]=(char*)malloc(sizeof(char)*2);
                pgather[index][0]=newsymbol;
                pgather[index][1]='\0';
        }
        else
        {
                /* the argument NEWSYMBOL already added? */
                if(obtained(pgather[index],newsymbol))
                        return ;
                len=strlen(pgather[index]);
                pgather[index]=(char*)realloc(pgather[index],sizeof(char)*(len+1));
                pgather[index][len]=newsymbol;
                pgather[index][len+1]='\0';
        }


}





char cal_FIRST(char symbol,char **pFIRST,pRegulate pregu, char *pall_symbol,char *terminal,char *non_terminal,int *pnull,int *flag,int *pleft_recursive)
{
        char **p=pregu->pregulates;
        char *ptemp=*p;
        int j;

        /* if the current symbol's FIRST SET calculated, return it */
        if(flag[get_index(pall_symbol,symbol)])
                return symbol;

        /* if the symbol is terminal symbol, add itself */
        if(obtained(terminal,symbol))
        {
                addto_gather(symbol,symbol,pall_symbol,pFIRST);

                return symbol;


        }
#if 0
        else if(!obtained(pall_symbol,symbol)) /* error if the symbol is neither terminal nor non-terminal */
        {
                printf("\nerror: %c is inlegal!\nexit...\n",symbol);
                exit(1);
        }
#endif
        else if(obtained(non_terminal,symbol)) /* the symbol is non-terminal */
        {

                /* if the current symbol is false when checking left recursive,
                 * change it to true */
                if(!pleft_recursive[get_index(non_terminal,symbol)])
                        pleft_recursive[get_index(non_terminal,symbol)]=TRUE;

                for(j=1;j<pregu->num;j++)
                {if(p[j]) /* scan every production */
                        {
                                ptemp=p[j];
                                if(ptemp[0]!=symbol) /* find a production belongs to current symbol */
                                {

                                        /*      p++; */
                                        continue;
                                }


                                if(can_obtain_null(non_terminal,pnull,symbol))
                                {

                                        addto_gather(symbol,'~',pall_symbol,pFIRST);

                                        /*              output_first(pFIRST,pall_symbol); */
                                }

                                /* the first symbol of right part of production is terminal symbol */
                                if(obtained(terminal,ptemp[3]))
                                {
                                        addto_gather(symbol,ptemp[3],pall_symbol,pFIRST);
                                        /*      output_first(pFIRST,pall_symbol); */

                                }
                                else if('~'==ptemp[3])
                                {
                                        /*      p++; */
                                        continue;
                                }
                                else /* if(is_nonterminal(symbol))  */
                                {
                                        /* if all the symbols of right part of production are
                                         * non-terminal symbols, and the first symbol of right
                                         * part of production is not the current symbol */
                                        if(is_regulate_right_nonterminal(p[j],terminal) && !is_equal(p[j]))
                                        {
                                                /* get the position of the non-terminal symbol,
                                                 * which cannot derive NUl('~') */
                                                int length=get_position(p[j],non_terminal,pnull);
                                                /* if there is a non-terminal which cannot derive NUl('~')
                                                 * in the right part of production */
                                                if(length)
                                                {

                                                        int i;

                                                        /* calculate the FIRST SET, from one by
                                                         * one in production */
                                                        for(i=3;i<length;i++)
                                                        {

                                                                if(pleft_recursive[get_index(non_terminal,ptemp[i])])
                                                                        break;
                                                                first_add(symbol,cal_FIRST(ptemp[i],pFIRST,pregu,pall_symbol,terminal,non_terminal,pnull,flag,pleft_recursive),TRUE,pall_symbol,pFIRST);
                                                        }

                                                        if(pleft_recursive[get_index(non_terminal,ptemp[i])])
                                                                first_add(symbol,ptemp[i],FALSE,pall_symbol,pFIRST);
                                                        else
                                                                first_add(symbol,cal_FIRST(ptemp[i],pFIRST,pregu,pall_symbol,terminal,non_terminal,pnull,flag,pleft_recursive),FALSE,pall_symbol,pFIRST);

                                                }
                                                else /* the all symbols of right part of
                                                        production can derive NUL('~') */
                                                {
                                                        int length=strlen(p[j]);
                                                        int i;
                                                        for(i=3;i<length;i++)
                                                        {
                                                                if(pleft_recursive[get_index(non_terminal,ptemp[i])] )
                                                                        break;
                                                                first_add(symbol,cal_FIRST(ptemp[i],pFIRST,pregu,pall_symbol,terminal,non_terminal,pnull,flag,pleft_recursive),FALSE,pall_symbol,pFIRST);
                                                                /*                      output_first(pFIRST,pall_symbol); */
                                                        }

                                                        /* add the NUL('~') */
                                                        addto_gather(symbol,'~',pall_symbol,pFIRST);
                                                        /*              output_first(pFIRST,pall_symbol); */
                                                }
                                        }
                                        else /* if there is a terminal symbol in the production
                                                at least(or there is at least one non-terminal
                                                symbol which cannot derive NUL('~') */
                                        {
                                                int i=3;
                                                ptemp=p[j];
                                                do
                                                {
                                                        if(obtained(non_terminal,ptemp[i]) &&  pleft_recursive[get_index(non_terminal,ptemp[i])])
                                                                break;
                                                        first_add(symbol,cal_FIRST(ptemp[i],pFIRST,pregu,pall_symbol,terminal,non_terminal,pnull,flag,pleft_recursive),FALSE,pall_symbol,pFIRST);
                                                        i++;
                                                }while(can_obtain_null(non_terminal,pnull,ptemp[i-1]));  /*|| !obtained(terminal,ptemp[i-1]) */
                                        }
                                }

                                /*              p++; */
                        }
                }


        }
        if(j==pregu->num)
        {
                flag[get_index(pall_symbol,symbol)]=TRUE;

        }
        if(obtained(non_terminal,symbol))
                pleft_recursive[get_index(non_terminal,symbol)]=FALSE;

        return symbol;
}


void get_all_symbol(char **pall_symbol,char *non_terminal,char *terminal)
{
        int len=strlen(non_terminal)+strlen(terminal)+2;
        *pall_symbol=(char*)malloc(sizeof(char)*len);
        strcpy(*pall_symbol,terminal);
        strcat(*pall_symbol,"#");
        strcat(*pall_symbol,non_terminal);
}



/* has unknown status? */
int exist_unknown(int *pnull,int n)
{
        int i;
        for(i=0;i<n;i++)
                if(pnull[i]==UN_KNOWN)
                        return TRUE;
        return FALSE;
}

void output_null(int *pnull,int len)
{
        int i;
        for(i=0;i<len;i++)
                printf("%d\n",pnull[i]);
}



/* the right part of production is indexed to NO? */
int contain_no(char *pregulates,int *pnull,char *non_terminal)
{
        char *p=pregulates+3;
        int index;
        while(*p!='\0')
        {

                index=get_index(non_terminal,*p);
                if(pnull[index]==NO)
                        return TRUE;
                p++;
        }

        return FALSE;
}


/* the all non-terminal symbols of the right part of production can derive NUL('~')? */
int all_are_null(char *pregulates,int *pnull,char *non_terminal)
{
        char *p=pregulates+3;
        int index;


        while(*p!='\0')
        {

                index=get_index(non_terminal,*p);

                if(pnull[index]!=YES)
                {

                        return FALSE;
                }
                p++;

        }
        return TRUE;
}

int  contain_null(char *pregulates)
{


        if(pregulates[3]=='~')
        {

                return TRUE;
        }

        return FALSE;
}




void print_error(char *perror)
{
        printf("\n%s\nEXIT...\n",perror);
        exit(1);
}


int get_index(char *pgather,char symbol)
{
        int index;
        int length=strlen(pgather);
        for(index=0;index<length;index++)
        {

                if(pgather[index]==symbol)
                        return index;
        }
        printf("\n Inlegal symbol:'%c'",symbol);
        print_error("\nInlegal Symbol Found!\n");
        return -1;

}


int all_delete(char non_terminal,char **pregulates,int n)
{
        int i;


        for(i=0;i<n;i++)
        {

                if(!pregulates[i])
                        continue;
                if(non_terminal==pregulates[i][0])
                        return FALSE;
        }
        return TRUE;
}

void output_gather(char *pstring)
{
        printf("\ngaher:%s\n",pstring);
}


int symbol_found(char symbol,char *pgather)
{
        char *p=pgather;
        while(*p!='\0')
        {

                if(symbol==*p)
                        return TRUE;
                p++;
        }

        return FALSE;
}

/* construct the terminal & non-terminal symbol arrays */
void generate(pRegulate pregu,char **non_terminal,char **terminal)
{
        int i;
        int index;
        char *p=NULL;
        if(!*non_terminal)
        {
                *non_terminal=(char *)malloc(sizeof(char));
                (*non_terminal)[0]='\0';
        }
        if(!*terminal)
        {
                *terminal=(char *)malloc(sizeof(char));
                (*terminal)[0]='\0';

        }
        for(i=0;i<pregu->num;i++)
        {
                p=pregu->pregulates[i];

                while(*p!='\0')
                {
                        /* skip the "->" of production */
                        if(*p==pregu->pregulates[i][1] && *(p+1)==pregu->pregulates[i][2])
                        {
                                p+=2;
                                continue;
                        }
                        if(('A'<=*p && *p <= 'Z') || '$'==*p) /* non-terminal symbol */
                        {


                                index=strlen(*non_terminal);
                                *non_terminal=(char *)realloc(*non_terminal,sizeof(char)*(index+2));
                                (*non_terminal)[index]='\0';


                                if(symbol_found(*p,*non_terminal))      /* the symbol added already */
                                {

                                        p++;
                                }
                                else    /* add it */
                                {
                                        index=strlen(*non_terminal);
                                        (*non_terminal)[index]=*p;
                                        (*non_terminal)[++index]='\0';
                                        p++;

                                }
                        }
                        else if(*p=='~')
                        {
                                p++;
                                continue;
                        }
                        else    /* terminal symbol */
                        {

                                index=strlen(*terminal);
                                *terminal=(char *)realloc(*terminal,sizeof(char)*(index+2));
                                (*terminal)[index]='\0';


                                if(symbol_found(*p,*terminal))  /* the symbol added already */
                                {
                                        p++;

                                }
                                else /* add it */
                                {


                                        index=strlen(*terminal);
                                        (*terminal)[index]=*p;
                                        (*terminal)[++index]='\0';
                                        p++;
                                }

                        }
                }
        }

}


void output_regulate_from_file(pRegulate pregu)
{
        int i;
        printf("\nextend productions:");
        for(i=0;i<pregu->num;i++)
                printf("\n[%d]%s",i,pregu->pregulates[i]);
}

void input(pRegulate pregu,char *filename)
{
        char temp_regulate[MAX_CHAR];
        FILE *fp;
        fp=fopen(filename,"r");
        if(!fp)
        {
                printf("\nERROR:Can not open FILE '%s'!\n",filename);
                exit(1);
        }

        pregu->num=0;
        pregu->pregulates=NULL;
        while(!feof(fp))        /* read productions from file */
        {
                fscanf(fp,"%s",temp_regulate);
                if(feof(fp))
                        break;
                pregu->pregulates=(char **)realloc(pregu->pregulates,(pregu->num+1)*sizeof(char*));
                pregu->pregulates[pregu->num]=(char *)malloc(sizeof(char)*(strlen(temp_regulate)+1));
                strcpy(pregu->pregulates[pregu->num],temp_regulate);
                pregu->num++;
        }
        fclose(fp);


}



int contain_terminal(char *pregulates,char *terminal)
{
        int i;
        char *p=pregulates+3;
        int index=strlen(terminal);


        if(*p=='~')
                return FALSE;
        while(*p!='\0')
        {

                for(i=0;i<index;i++)
                        if(*p==terminal[i])
                                return TRUE;
                p++;
        }

        return FALSE;
}




void to_null(int **pnull,pRegulate pregu,char *non_terminal,char *terminal,int *pleft_recursive)
{
        char **pregulates=NULL;
        char temp;
        int i;
        int j;
        int index;
        int len;
        int k;

        /* allocate the space to store the non-terminal symbol which can derive NUL('~'),
         * including '~'. */
        *pnull=(int *)malloc(sizeof(int)*(strlen(non_terminal)));
        /* save the productions */
        pregulates=(char **)malloc(sizeof(char *)*(pregu->num));
        for(i=0;i<pregu->num;i++)
        {
                pregulates[i]=(char *)malloc(sizeof(char)*(strlen(pregu->pregulates[i])+1));
                strcpy(pregulates[i],pregu->pregulates[i]);

        }

        for(i=0;i<pregu->num;i++)
                (*pnull)[i]=UN_KNOWN;

        for(i=0;i<pregu->num;i++) /* scan each production */
        {
                if(!pregulates[i])
                        continue;


                if(pregulates[i][3]==pregulates[i][0])
                {
                        temp=pregulates[i][0];
                        free(pregulates[i]);
                        pregulates[i]=NULL;
                        if(all_delete(temp,pregulates,pregu->num))
                        {

                                index=get_index(non_terminal,temp);
                                (*pnull)[index]=NO;

                        }
                        continue;
                }

                /* if the right part of production contains terminal symbol,
                 * remove the production */
                if(contain_terminal(pregulates[i],terminal))
                {

                        temp=pregulates[i][0];

                        free(pregulates[i]);
                        pregulates[i]=NULL;

                        /* the non-terminal symbol has none productions */
                        if(all_delete(temp,pregulates,pregu->num))
                        {

                                index=get_index(non_terminal,temp);
                                (*pnull)[index]=NO;

                        }


                }

                /* the right part of production is NUL('~')? */
                else if(contain_null(pregulates[i]))
                {


                        index=get_index(non_terminal,pregulates[i][0]);

                        (*pnull)[index]=YES;
                        temp=pregulates[i][0];

                        for(j=1;j<pregu->num;j++)
                        {
                                if(!pregulates[j])
                                        continue;

                                if(temp==pregulates[j][0])
                                {
                                        free(pregulates[j]);
                                        pregulates[j]=NULL;
                                }
                        }
                }
        }

        /*      output_null(*pnull,strlen(non_terminal)); */



        /* the 2nd step */
        while(exist_unknown(*pnull,strlen(non_terminal)))
        {
                for(i=0;i<pregu->num;i++)
                {


                        if(!pregulates[i])
                                continue;
                        pleft_recursive[get_index(non_terminal,pregulates[i][0])]=TRUE;


                        if((len=strlen(pregulates[i])))
                        {

                                for(k=3;k<len;k++)
                                {

                                        if(YES==(*pnull)[get_index(non_terminal,pregulates[i][k])])
                                        {

                                                continue;
                                        }
                                        else
                                                break;
                                }

                                if(obtained(non_terminal,pregulates[i][k])
                                                && UN_KNOWN==(*pnull)[get_index(non_terminal,pregulates[i][k])]
                                                && pleft_recursive[get_index(non_terminal,pregulates[i][k])])
                                {
                                        temp=pregulates[i][0];
                                        free(pregulates[i]);
                                        pregulates[i]=NULL;
                                        if(all_delete(temp,pregulates,pregu->num))
                                        {
                                                index=get_index(non_terminal,temp);
                                                (*pnull)[index]=NO;
                                        }

                                        pleft_recursive[get_index(non_terminal,temp)]=FALSE;
                                        continue;
                                }
                        }



                        /* the all non-terminal symbols of the right part of
                         * production can derive NUL('~')? */
                        if(all_are_null(pregulates[i],*pnull,non_terminal))
                        {

                                index=get_index(non_terminal,pregulates[i][0]);
                                (*pnull)[index]=YES;
                        }
                        else if(contain_no(pregulates[i],*pnull,non_terminal))
                                /* the right part of production is indexed to NO? */
                        {
                                temp=pregulates[i][0];
                                free(pregulates[i]);
                                pregulates[i]=NULL;
                                if(all_delete(temp,pregulates,pregu->num))
                                {
                                        index=get_index(non_terminal,temp);
                                        (*pnull)[index]=NO;
                                }
                        }
                }
        }

}
