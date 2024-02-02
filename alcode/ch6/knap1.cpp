#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
struct Goods								//��Ʒ�ṹ������ 
{
	int no;									//��Ʒ�ı��
	int w;									//��Ʒ������
	int v;									//��Ʒ�ļ�ֵ
	Goods(int no1,int w1,int v1)			//���캯�� 
	{
		no=no1;
		w=w1;
		v=v1;
	}
	bool operator<(const Goods&b) const		//���ڰ�v/w�ݼ����� 
	{
		return (double)v/w>(double)b.v/b.w;
	}	
};
int n=4;							//4����Ʒ
//int W=6;							//��������Ϊ6
//vector<Goods> g={Goods(0,5,4),Goods(1,3,4),Goods(2,2,3),Goods(3,1,1)};
int W=8; 
vector<Goods> g={Goods(0,2,6),Goods(1,4,8),Goods(2,3,3),Goods(3,2,2)};


vector<int> bestx;					//������Ž����� 
int bestv=0; 						//�������ֵ,��ʼΪ0 
struct QNode						//�����н������
{
	int i;							//��ǰ���(��Ʒ���) 
	int cw;							//��ǰ������
	int cv;							//��ǰ�ܼ�ֵ
	vector<int> x;					//��ǰ������
	double ub;						//�Ͻ�
	bool operator<(const QNode& b) const	//����<��ϵ����
	{
		return ub<b.ub;				//ubԽ��Խ���ȳ���
	}
};
void bound(QNode& e)		//�����i������Ͻ纯��ֵ
{	int rw=W-e.cw;								//������ʣ������
	double b=e.cv;								//��ʾ��Ʒ��ֵ���Ͻ�ֵ
	int j=e.i;
	while (j<n && g[j].w<=rw)
	{	rw-=g[j].w;								//ѡ����Ʒj
		b+=g[j].v;								//�ۼƼ�ֵ
		j++;
	}
	if (j<n)										//�����Ʒ(��ʱ��j����r(i)��ʽ�е�k)ֻ�ܲ���װ��
		b+=(double)g[j].v/g[j].w*rw;
	e.ub=b;
}

void EnQueue(QNode e,priority_queue<QNode>& pqu)		//���e���Ӳ���
{
	if (e.i==n)							//����Ҷ�ӽ��
	{	printf("  һ����[%d,%d]\n",e.cw,e.cv); 
		if (e.cv>bestv)						//�Ƚϸ������Ž�
		{	bestv=e.cv;
			bestx=e.x;
			printf("  ���Ž�bestv=%d\n",bestv); 
		}
	}
	else
	{
		printf("����\n"); 
		pqu.push(e);						//��Ҷ�ӽ�����
	} 
}
int sum=0;
void bfs()							//��0/1���������Ž�
{	QNode e,e1,e2;					//����3�����
	priority_queue<QNode> pqu;				//����һ������
	e.i=0;
	e.cw=0; e.cv=0;
	e.x.resize(n);
	bound(e);							//��������Ͻ�
	pqu.push(e);							//��������
	//printf("�����[%d,%d,%g]����\n",e.w,e.v,e.ub); 
	while (!pqu.empty())					//�Ӳ���ѭ��
	{
		e=pqu.top(); pqu.pop();			//���ӽ��e
		printf("(%d)���ӽ��[%d,%d,%g],i=%d\n",++sum,e.cw,e.cv,e.ub,e.i); 
		if (e.cw+g[e.i].w<=W)			//����(ѡ����Ʒe.i��֧)
		{	e1.cw=e.cw+g[e.i].w;			//ѡ����Ʒe.i
			e1.cv=e.cv+g[e.i].v;
			e1.x=e.x;
			e1.x[e.i]=1;				//ѡ����Ʒe.i
			e1.i=e.i+1;					//���ӽ��Ĳ�μ�1
			bound(e1); 
			printf("   ����[%d,%d,%g],e1.i=%d,  ",e1.cw,e1.cv,e1.ub,e1.i); 
			EnQueue(e1,pqu);
		} 
		else
			printf("   ����[%d,%d,%g],e1.i=%d ->cut\n",e1.cw,e1.cv,e1.ub,e1.i); 
		e2.cw=e.cw;					//��ѡ����Ʒe.i
		e2.cv=e.cv;
		e2.x=e.x;
		e2.x[e.i]=0;						//��ѡ����Ʒi
		e2.i=e.i+1;						//���ӽ��Ĳ�μ�1
		bound(e2);
		if (e2.ub>bestv)					//�Һ���(��ѡ����Ʒe.i��֧)
		{	
			printf("   �ҽ��[%d,%d,%g],e2.i=%d,  ",e2.cw,e2.cv,e2.ub,e2.i); 
			EnQueue(e2,pqu);
		} 
		else
			printf("   �ҽ��[%d,%d,%g],e2.i=%d ->cut\n",e2.cw,e2.cv,e2.ub,e2.i);
	}
}
void dispg()					//���g 
{
	for(int i=0;i<g.size();i++)
		printf("%d\t%d\t%d\t%g\n",g[i].no,g[i].w,g[i].v,(double)g[i].v/g[i].w);
}
void disp()							//������Ž�
{
	printf("���װ���\n");
	for (int i=0;i<n;i++)
		if (bestx[i]==1)
			printf("  ѡȡ��%d����Ʒ\n",g[i].no);
	printf("  ������=%d,�ܼ�ֵ=%d\n",W,bestv);
}

void knap()									//��0/1�������� 
{
	bestx.resize(n);
	vector<int> x(n);
	sort(g.begin(),g.end());
	printf("sort\n"); dispg();
	bfs();							//i��0��ʼ
}
int main()
{
	freopen("xyz.txt","w",stdout);
	printf("��֧�޽編���0/1��������:\n"); 
	knap();							//���ö���ʽ��֧�޽編��0/1��������
	disp();
}
