#include <stdio.h>
#include <conio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

#define N 20001


int  add ( char *, char *, char * );
int  sub ( char *, char *, char * );
int  mul ( char *, char *, char * );
int  div ( char *, char *, char *, char * );
int poW ( char *t, char *k, char *res );
int poWmod ( char *t, char *k, char *mod, char *res );
int cmp(char *a, char *b);
int RobinTest(char *n);
char *randomstr(char *bound);
void del_zero ( char * a, char * b );
int NOD( char * ,char * , char * );
int NOD_rash ( char * a, char * b, char * d, char * x, char * y );

int add ( char *aa, char *bb, char * res )
{
        int i, j, k;	//������� �������� ��������� � ����������
        int cr;			//������� �������� � ������� ������
        int tmp;			//����� ���������� ������������ ��������
    char * a, * b;

    a = new char [N];
    b = new char [N];
        * res = '\0';					//�������� ������ � �����������
        del_zero (aa,bb);
    strcpy (a,aa);
    strcpy (b,bb);
        i = strlen(a);		//�������� � ����� ���������
        j = strlen(b);		//
        k = 0;				//������ ���������� ��������� � ������
        cr = 0;				//�������� ������� ��������

        //���� ������������ ��������
        do
        {
                //�������� �� ������� ���� ������� �������� � ������
                if ( i )	i--;
                //���� ������ ����������, ������� ����� ������
                //���������� ��� ������� ��������
                else		a[i] = '0';
                if ( j )	j--;
                else		b[j] = '0';

                //���������� ���������� �������� � ������ ��������
                //� ��������� ���� � �� �����
                tmp = a[i]+b[j]+cr-96;
                res[k] = tmp%10+48;		//������� ������ ����� - � ���������
                cr = tmp/10;				//������� ������ - �������
                k++;							//��������� �� ������� ����������
        }
        //���������, ���� �� ������������ ������� ��������� � ���� ������� ��������
        while ( i || j || cr );
        res[k] = '\0';			//������ ���� ����� ����� � ����� ������� ����������
        strrev(res);

    free (a);
    free (b);

        return 0;
}

int sub ( char *aa, char *bb, char * res )
{
        char * a, * b;		//��������� �� ������ (�������) ������������ � �����������
        int i, j, k;		//������� �������� ������������, ����������� � ��������
        int tmp;				//����� ���������� ������������ ����������
        int flg;				//������� ��������������� ��������
        int cr;				//������� ����� �� �������� �������

        a = new char [N];		//�������� ������ ��� ������ ������������
        b = new char [N];		//� �����������
        * a = * b = '\0';		//���������� ������ �����
        del_zero (aa,bb);

        //������������ �������� (������ ����������� � ����������)
        flg = 0;				//������������, ��� �������� ������������
        //���� ����� 1-�� �������� ������ ����� 2-��, ���������� ������������
        if ( strlen(aa)<strlen(bb) )
                flg = 1;
        else
                //�����, ���� ����� ���������, ���������� ����� ��������� ����������
                //�� ������� � �������
                if ( strlen(aa)==strlen(bb) )
                        for ( i=0; i<strlen(aa); i++ )
                        {
                                //���� ������� ����� 1-�� ��������, �������, ��� ����� 2-��
                                //��������� ���������, �������� ������������
                                if ( aa[i]>bb[i] )
                                        break	;
                                //���� �� ������� ����� 2-�� ��������, �������, ��� ����� 1-��
                                //��� �� ��������� ���������� ���������, �������� ������������
                                if ( aa[i]<bb[i] )
                                {
                                        flg = 1;		//������ ������� ��������������� ��������
                                        break;
                                }
                        }

        //���� �������� ������������, �� ����������� ��������� 2-� (�������)
        //�������, � �� ���������� 1-�
        if ( flg )
        {
                strcpy (a,bb);		//�������� ������ �� 2-� ��������� � ������ ������������
                i = strlen(bb);	//���������� ��� �����
                strcpy (b,aa);		//�������� ������ � 1-� ��������� � ������ �����������
                j = strlen(aa);	//���������� ��� �����
        }
        //���� �������� ��������������
        else
        {
                strcpy (a,aa);		//1-� ������� ��������� �� �����������
                i = strlen(aa);	//
                strcpy (b,bb);		//2-� - �� ����������
                j = strlen(bb);	//
        }

        k = 0;		//���������� ����� � ��������� �����
        cr = 0;		//������� ����� ����
        //���� ������������ ���������
        do
        {
                //���������� ����� �������� ��������
                //�� �������� ������������ � �����������
                if ( i )	i--;
                else		a[i] = 48;
                if ( j )	j--;
                else		b[j] = 48;
                //���������� ����������� ���������� � ������ ����� �� ������� ��������
                tmp = a[i]-b[j]-cr;
                //���� ��������� ������������ ��������� �����������, ������ ����
                //�� �������� �������
                if ( tmp<0 )
                {
                        cr = 1;			//��������� ������� �����
                        tmp = 10+tmp;	//������������ ��������� � ������ �����
                }
                else
                        //���� �� ��������� �������������, ��������� ������� �����,
                        //���� �� ��� ������ �� �������� �������
              if ( a[i]!='0' )	cr = 0;
                res[k] = tmp+48;		//���������� ��������� � ������ ��������
                k++;						//��������� � ���������� ������� �������
        }
        while ( i || j );			//���������, ���� �� ����������� ������� ���������
        res[k] = '\0';				//���������� � res ��� ����� ������

        //������� ���� ����� ��������� �������
        k--;			//��������� �� ��������� ����� ������� �����������
                                        //(����� �������� � �������� �������)
        //���� ����� ���� � ����� ������� �������� ������ 1, ������� ��
        while ( res[k]=='0' && k )
        {
                res[k] = '\0';			//�������� ������� ������ �� ������ ����� ������
                k--;						//�������� � ������ �������
        }
        strrev(res);
    free (a);
    free (b);
        return flg;					//���������� ������� ���������������
}

int mul ( char *aa, char *bb, char * res )
{
        char * a, * b;				//��������� ��������� � �����������
        int na, nb;					//���������� ��� �������� ���� ����������
        int i, j, k;				//������� �������� ���������� � ������������
        int tmp;						//����� ���������� ������������ ���������
        int cr;						//����� �������� � ������� �������
        char * buf1, * buf2;		//��������� �� �������� ������
        char *A, *B;

        A = new char [N];
        B = new char [N];
        strcpy(A,aa);
        strcpy(B,bb);
        * res = '\0';					//�������� ������ � �����������
        buf1 = new char [N*2];	//�������� ������ ��� �������� ������
        buf2 = new char [N*2];	//
        * buf1 = * buf2 = '\0';	//��������� ������ �����
        del_zero (A,B);
        //���������� �������, �� ������� ����� ������������� ���������
        //�������� - ����� ���������. �������� �� ���, ��� ������
        i = strlen(B)-strlen(A);		//��������� �������� ���� ���������

        //���� ������ 1-�, �� �������� �� ����
        if ( i>0 )
        {
                a = B;              //������������� ��������� �� 1-� ���������
                           //�� ������ ������ � 2-� ���������
                na = strlen(B)-1;	//����������� ����� 1-�� ���������
                b = A;					//������������� ��������� �� 2-� ���������
                                                                        //�� ������ ������ � 1-� ���������
                nb = strlen(A)-1;	//���������� ����� 2-�� ���������
        }
        //���� �� 2-� ������� �� ������� 1-��, �� ������ ��� ������ ����������
        else
        {
                a = A;					//1-� ������� ������ 1-� ����������
                na = strlen(A)-1;	//���������� ��� �����
                b = B;					//2-� ������� ������ 2-� ����������
                nb = strlen(B)-1;	//���������� ��� �����
        }

        //���� ���������������� ��������� �� ����� "���������"
        //�������� �� 2-�� ��������� �� ����� � ������,
        //������� ������ ����� �� 1-� ���������
        for ( j=nb; j>=0; j-- )
        {
                //��������� ������ ������� �������������� ���������
                //����������� ������ �� �������� ������� 2-�� ���������
                for ( k=0; k<nb-j; k++ )
                        buf1[k] = '0';
                cr = 0;						//�������� ����� �������� � ������� �������

                //���� ������������ ���������
                for ( i=na; i>=0; i-- )
                {
                        //����������� ����� ������� ��������� � ������� ������ �������
                        //� ������ �������� ����� ���� � �������� �� ������� ��������
                        tmp = (a[i]-48)*(b[j]-48)+cr;
                        //������� ������ ������������ ����� � ������ ��������. ����������
                        buf1[k] = tmp%10+48;
                        k++;						//��������� �� ������� ��������. ���������
                        cr = tmp/10;			//������� �� ������ ������� � ������� ������
                }
                //������, ���� ���������, ������� � ������� ������
                if (cr)
                {
                        buf1[k] = cr+48;	//���������� ������� � ��������� ������
                        k++;					//��������� �� ������� ��������. ����������
                }
                buf1[k] = '\0';	//��������� �� ������� ��������. ���������� ������
                strrev (buf1);			//������������ �� � ���������� (��������) �������
                add (buf1,buf2,res);		//���������� � �����������, ������������� � res
                strcpy (buf2,res);	//�������� � ���������. ����� ����������� ���������
        }
        return 0;
}

int div ( char *a, char *b, char * res, char * rem )
{
        char * buf1, * buf2;			//��������� �� �������� ������
        char c;							//�������� ���������� ����������
        int i, j;							//������ ��������� �������
        int q;							//������� ������������ 1-�� ������� �
                                                                                //������������� �����������
                                                                                //������ ����������� ����������� ������
                                                                                //�������������� ������������ ����� � ���������
        int nb;							//���������� ��� �������� ����� ������ ��������

        * res = '\0';					//�������� ������ � �����������
        * rem = '\0';

        del_zero (a,b);
        if ((strlen(b)==1) && (b[0])=='0')
        {
                return 666;
        }
        if ((strlen(a)==1) && (a[0])=='0')
        {
                strcat (res,"0");
                strcpy (rem,a);
                return 0;
        }
        //���� ����� �������� ������ ����� ��������, �� ������� ����� ����
        if ( strlen(a)<strlen(b) )
        {
                strcat (res,"0");			//����� � ������ ���������� ����
                strcpy (rem,a);			//������� ������� ���������� �������
                return 0;					//������� �� ���������
        }
        else
        {
                buf1 = new char [N];		//�������� ������ ��� �������� ������
                buf2 = new char [N];		//
                * buf1 = * buf2 = '\0';	//���������� ������ �����
                nb = strlen(b);			//���������� ����� ��������

                //��������� ����� ��� ��������������  ��������
                //��� ������� ����� �������
                strncat (buf1,a,nb);	//�������� �� �������� ����������� ���������� ��������
                a += nb;					//��������� �� ������ � ������� �� ������ ����� ����������
                int fuck = 0;
                //���� ������� "���������"
                do
                {
                        fuck ++;
                        if (fuck==43)
                                fuck++;
            q = 1;					//������� ������������ �� ����
            //���������� ����� ������� �� �������
                                i = strlen (buf1);
                                //������� �� ������ ������������ ����,
                                //���� �� ��� ����
            if ( strlen(buf1)==1 && buf1[0]=='0' )
            {
               * buf1 = '\0';		//������ �������� ������ ������
               i--;					//��������� �� �����
            }
            //���� ������ � ������� ��� �� ����� �
            //����� � ������������� ������� �� ��������
            //��������� ��� �� ������ � �������
            if ( strlen(a)>0 && i<nb )
            {
                 strncat (buf1,a,1);		//�������� � ����� 1-� ������
                 a++;							//��������� �� ������ � �������
                 i++;
                 q = 0;								//����������� ������ ������� ������
                 if ( strcmp(buf1,"0")==0 )
                 {
                    * buf1 = '\0';
                    i--;
                    strcat (res,"0");
                    q = 1;
                 }
                                                                //������� ������� q
                 //����� �������� �� ������ ������� �� ������ � �������
                 //� �����, ���� �� ��������� ������ ����������, ����
                 //���� �� ���������� ������ � �������
                 while ( i<nb && strlen(a) )
                 {
                    strncat (buf1,a,1);	//�������� ������ � �����
                    if ( !q )
                        strcat (res,"0");		//���������� � ���������� ����
                    q = 0;
                    a++;						//��������� �� ������ ��������
                    i++;						//����������� ������ ������� ������
                    if ( buf1[0]=='0' )
                    {
                        * buf1 = '\0';
                        i--;
                        //buf1[--i] = '\0';
                    }
                 }
                 if ( strlen(buf1)<strlen(b) && strlen(a)==0 )
                 {
                                                        if ( !q )
                                                          strcat (res,"0");
                                                        if ( strlen(res)==0 )
                                                                strcat (res,"0");
                            if ( strlen(buf1)!=0 )
                                                            strcpy (rem,buf1);
                            else
                                strcpy (rem,"0");
                            free (buf1);
                            free (buf2);
                                                        return 1;
                                                }
            }

         //���������, ����� �� ���������� � ����� �������������� ������
                        for ( i=0; i<strlen(buf1); i++ )
                        {
                                //���� � ������� ������� ������ � ������ ������, ��� � ��������
                                //���������� ����������� � ����� �������������� ������
                                if ( buf1[i]<b[i] /*&& buf1[0]!='0'*/ )
                                {
                                        if ( strlen(a) )
                                        {
                                                strncat (buf1,a,1);			//�������� ������ � �����
                                                if ( strlen(res) && !q )	//���� ��� �� ������ ������
                                                {									//
                                                strcat (res,"0");	//��������� ��������� �����
                                                        q = 0;				//������� ������� q
                        }
                                                a++;								//��������� �� ������ � �������
                                                break;							//����������� ����������
                                        }
                                        else
                                        {
                                                if ( strlen(res)==0 )
                                                        strcpy (res,"0");
                                                if ( !q )
                                                          strcat (res,"0");
                                                strcpy (rem,buf1);
                        free (buf1);
                        free (buf2);
                                                return 0;
                                        }
                                }
                                else
                                        //���� �� � ������� ������� ������ � ������ ������
                                        if ( buf1[i]>b[i] )			//
                                        break;						//����������� ���������
            }
                        i = 0;									//�������� ������� ��� ��������
                        //���� ��������� �������� �� ��������
                        //������� ������: �������� ������������, ���� ����� ����
                        while ( !sub(buf1,b,buf2) )
                        {
                                strcpy (buf1,buf2);	//�������� �������� � 1-� �����
                                i++;						//����������� ������� ��������
                        }

                        c = i+48;					//������� ��������� �� ������� ��������
                        strncat (res,&c,1);		//���������� ��������� � ������ � �����������
                }
                while ( strlen(a) );
                strcpy (rem,buf1);			//���������� �������
                if ( strlen(rem)==0 )
                        strcpy (rem,"0");
        }

    free (buf1);
    free (buf2);

        return 1;
}

//������� �������� ������ ����� � ������� �������� ���������
void del_zero ( char * a, char * b )
{
        int j;
        while(1)
        {
                if ((a[0]!='0') || (strlen(a)==1)) break; //���� ��������� �� 0, ����������� ��������
                for (j=0; j<strlen(a)-1; j++)   //�������� ����� ��  ���� ������ �����
                {
                        a[j]=a[j+1];
                }
                a[strlen(a)-1]='\0';    //������� ������� ������ ������ � ����� �����

        }

        while(1)
        {
                if ((b[0]!='0') || (strlen(b)==1)) break;  //���� ��������� �� 0, ����������� ��������
                for (j=0; j<strlen(b)-1; j++)   //�������� ����� ��  ���� ������ �����
                {
                        b[j]=b[j+1];
                }
                b[strlen(b)-1]='\0';   //������� ������� ������ ������ � ����� �����
        }
}

char *randomstr(char *bound)
{
        int k = strlen(bound), n = rand()%k + 1;
        char * randstr = new char [N];
        char * buf = new char [N];

        char character[2]="";
        strcpy(randstr,"");
        while(1)
        {
                char character[2]="";
                strcpy(randstr,"");
                for (int i=0; i<n; i++)
                {
                        int a = rand()%10;
                        itoa(a,character,10);
                        strcat(randstr,character);
                }
                strcpy(buf,randstr);
                if (n < k)
                {
                        del_zero(randstr,buf);
                        return randstr;
                }
                if (!cmp(buf,bound))
                {
                        del_zero(randstr,buf);
                        return randstr;
                }
        }
}

int poW ( char *t, char *k, char *res )
{
        char *buf1 = new char [N];
    char *buf2 = new char [N];
    char *r = new char [N];
        char *a = new char [N];
        char *b = new char [N];
    strcpy(buf1,"");
    strcpy(buf2,"");
    strcpy(r,"");
    strcpy(res,"1");
        strcpy(a,t);
        strcpy(b,k);
    while(strcmp(b,"0")!=0)
    {
                div(b,"2",buf1,buf2);
        if (buf2[0] == '1')
        {
                        mul(res,a,buf1);
            strcpy(res,buf1);
        }
        mul(a,a,buf1);
        strcpy(a,buf1);
        div(b,"2",buf1,buf2);
        strcpy(b,buf1);
    }
        return 1;
}

int poWmod ( char *t, char *k, char *mod, char *res )
{
        char *buf1 = new char [N];
        char *buf2 = new char [N];
        char *r = new char [N];
        char *a = new char [N];
        char *n = new char [N];
        strcpy(r,"1");
        strcpy(a,t);
        strcpy(n,k);
        long long i=0;

        while(strcmp(n,"0")!=0)
        {
                i++;
                if (int(n[strlen(n)-1])%2==0)
                {
                        div(n,"2",buf1,buf2);
                        strcpy(n,buf1);
                        mul(a,a,buf1);
                        div(buf1,mod,buf2,a);
                }
                else
                {
                        sub(n,"1",buf1);
                        strcpy(n,buf1);
                        mul(r,a,buf1);
                        div(buf1,mod,buf2,r);
                }
        }
        strcpy(res,r);
        return 1;
}

int cmp(char *a, char *b)
{
        if (strlen(a)>strlen(b))
                return 1;
        if (strlen(b)>strlen(a))
                return 0;
    int n = strlen(a) >= strlen(b)? strlen(a): strlen(b);

        for (int i=0; i<n; i++)
        {
                if (a[i]>b[i])
                        return 1;
                else if (b[i]>a[i])
                        return 0;
        }
        return 2;
}

int RobinTest(char *n)
{
        char *buf, *buf1, *buf2, *s, *r, *j, *nn, *a, *y;
        y = new char [N];
        buf1 = new char [N];
        buf2 = new char [N];
        buf = new char [N];
        s = new char [N];
        r = new char [N];
        j = new char [N];
        nn = new char [N];
        a = new char [N];
        sub(n,"2",buf);
        strcpy(a,"1");
        while(strcmp(a,"1")==0 || strcmp(a,"0")==0)
                a = randomstr(buf);
        sub(n,"1",nn);
        strcpy(s,"2");
        while(2)
        {
                poW("2",s,buf);
                if (cmp(buf,nn) == 1)
                {
                        strcpy(s,"1");
                        div(nn,"2",r,buf2);
                        break;
                }
                div(nn,buf,buf1,buf2);
                if (buf2[0]=='0')
                {
                        div(buf1,"2",buf,buf2);
                        if (strcmp(buf2,"0")!=0)
                        {
                                strcpy(r,buf1);
                                break;
                        }
                }
                add(s,"1",buf);
                strcpy(s,buf);
        }
        poWmod(a,r,n,y);
        if (strcmp(y,"1")!=0 && strcmp(y,nn)!=0)
        {
                strcpy(j,"1");
                sub(s,"1",buf);
                while(cmp(j,buf)!=1 && strcmp(y,nn)!=0)
                {
                        poWmod(y,"2",n,buf1);
                        if (strcmp(buf1,"1")==0)
                                return 0;
                        strcpy(y,buf1);
                        add(j,"1",buf1);
                        strcpy(j,buf1);
                }
                if(strcmp(y,nn)!=0)
                        return 0;
        }
        return 1;
}

//���������� ��� �� ��������� �������
int NOD ( char * a, char * b, char * res )
{
        char * buf1, * buf2, *aa, *bb;
                long long iter = 0;
        buf1 = new char [N];		//�������� ������ ��� �������� ������
        buf2 = new char [N];
                aa = new char [N];
                bb = new char [N];
                strcpy(aa,a);
                strcpy(bb,b);
        mul(aa,bb,buf2);
        while(strcmp(buf2,"0")!=0)  //���� a ��� b �� ����� 0
        {
                if(sub(aa,bb,buf1)==0)  //���� a <= b
                {
                        div (aa,bb,buf1,buf2);  //a = a % b
                        strcpy (aa,buf2);
                }
                else
                {
                        div (bb,aa,buf1,buf2);  //b = b % a
                        strcpy (bb,buf2);
                }
                mul(aa,bb,buf2);   //�������� a � b �� ��������� 0
                                iter ++;
        }
        add(aa,bb,res);         // ���� + ����
        return 1;
}

int NOD_rash ( char * a, char * b, char * d, char * x, char * y )
{
        char *r0, *r1, *r2, *x0, *x1, *y0, *y1, *q, *A, *B;
        char * buf1, * buf2;
        buf1 = new char [N];		//�������� ������ ��� �������� ������
        buf2 = new char [N];
        A = new char [N];
        B = new char [N];
        r0 = new char [N];
        r1 = new char [N];
        r2 = new char [N];
        x0 = new char [N];
        x1 = new char [N];
        y0 = new char [N];
        y1 = new char [N];
        q = new char [N];
        bool X1flg = false, X0flg = false, Y1flg = false, Y0flg = false;

        strcpy(A,a);
        strcpy(B,b);

        if(sub(A,B,buf1))
        {
                strcpy(buf1,A);
                strcpy(A,B);
                strcpy(B,buf1);
        }

        strcpy(r0,A);
        strcpy(r1,B);
        strcpy(x0,"1");
        strcpy(x1,"0");
        strcpy(y0,"0");
        strcpy(y1,"1");
        strcpy(q,"");
        strcpy(r2,"");

        for (;;)
        {
                div(r0,r1,q,buf1);
                mul(q,r1,buf1);
                sub(r0,buf1,r2);
                if (strcmp(r2,"0")==0)
                        break;
                else
                {
                        mul(q,x1,buf1);
                        strcpy(buf2,x1);
                        if (X0flg == X1flg)
                        {
                                if (!X0flg && sub(x0,buf1,x1))
                                {
                                        X0flg = X1flg;
                                        X1flg = true;
                                }
                                else if (X0flg && sub(x0,buf1,x1))
                                {
                                        X0flg = X1flg;
                                        X1flg = false;
                                }
                        }
                        else
                                add(x0,buf1,x1);

                        strcpy(x0,buf2);

                        mul(q,y1,buf1);
                        strcpy(buf2,y1);
                        if (Y0flg == Y1flg)
                        {
                                if (!Y0flg && sub(y0,buf1,y1))
                                {
                                        Y0flg = Y1flg;
                                        Y1flg = true;
                                }
                                else if (Y0flg && sub(y0,buf1,y1))
                                {
                                        Y0flg = Y1flg;
                                        Y1flg = false;
                                }
                        }
                        else
                                add(y0,buf1,y1);

                        strcpy(y0,buf2);

                        strcpy(r0,r1);
                        strcpy(r1,r2);
                }
        }

        mul(x1,A,buf1);
        mul(y1,B,buf2);
        if (sub(buf1,buf2,x0) && strcmp(x0,r1)==0)
        {
                strcpy(x,"-");
                strcat(x,x1);
                strcpy(y,y1);
        }
        else if (sub(buf2,buf1,x0) && strcmp(x0,r1)==0)
        {
                strcpy(x,x1);
                strcpy(y,"-");
                strcat(y,y1);
        }

        strcpy(d,r1);

        return 1;
}

