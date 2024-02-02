#include<iostream>
#include<cstring>
#include<queue>
#include<vector>
using namespace std;
#define INF 0x3f3f3f3f			//��ʾ��
#define MAXN 51
//�����ʾ
int n;							//ͼ�������
//�������ʾ
struct Edge
{
    int vno;					//������ 
	int wt;						//��Ȩ 
    Edge(int v,int w):vno(v),wt(w) {}		//���캯�� 
};
vector<Edge> E[MAXN];			//ͼ���ڽӱ� 
int dist[MAXN];					//dist[i]Դ�㵽����i�����·������
int pre[MAXN];					//pre[i]��ʾԴ�㵽i�����·���ж���i��ǰ������
struct QNode					//���н������
{
	int i;						//���Ĳ��
    int vno;					//������
	int length;					//·������
};
int cnt=0;
void bfs(int s)						//����㷨
{
	QNode e,e1;
    queue<QNode> qu;
	e.vno=s;						//����Դ����e
	e.i=0;
	e.length=0;
	qu.push(e);					//Դ����e����
    dist[s]=0;
    while(!qu.empty())				//���в���ѭ��
    {
		e=qu.front(); qu.pop();		//�����н��e
		int u=e.vno;					//��Ӧ����Ϊu 
		printf("(%d)����%d,i=%d\n",++cnt,u,e.i); 
        for (int j=0;j<E[e.vno].size();j++)
		{
			int v=E[e.vno][j].vno;		//���ڶ���Ϊv
			printf("  �������ڵ�%d  ", v);
            if(dist[u]+E[u][j].wt<dist[v])		//��֧��u��v�б���·�����ȸ���
			{
                dist[v]=e.length+E[u][j].wt;
                printf("[%d,%d]:%d �޸�dist[%d]=%d\n",u,v,E[u][j].wt,v,dist[v]); 
				pre[v]=e.vno;
				e1.vno=v;			//�������ڵ�Ľ��e1
				e1.i=e.i+1;
				e1.length=dist[v];
				printf(" ��չ%d,e1.length=%d  i=%d\n",e1.vno,e1.length,e1.i); 				
				qu.push(e1);				//���e1����
            }
            else printf("û���޸�\n"); 
		}
    }
}
void addEdge(int i,int j,int w)		//ͼ������һ����
{
	E[i].push_back(Edge(j,w));
}
void dispapath(int s,int i)			//���s��i�����·��
{
	vector<int> path;
	if (s==i) return;
	if (dist[i]==INF)
		printf("    Դ��%d������%dû��·��\n",s,i);
	else
	{
		int k=pre[i];
		path.push_back(i);		//����Ŀ�궥��
		while (k!=s)			//�����м䶥��
		{
			path.push_back(k);
			k=pre[k];
		}
		path.push_back(s);		//����Դ��
		printf("    Դ��%d������%d�����·������: %d, ·��: ",s,i,dist[i]);
		for (int j=path.size()-1;j>=0;j--)	//���������������·��
			printf("%d ",path[j]);
		printf("\n");
	}
}
void dispallpath(int v)			//���Դ��v�������������·��
{
	for (int i=0;i<n;i++)
		dispapath(v,i);
}

int main()
{
	memset(dist,0x3f,sizeof(dist));	//��ʼ��Ϊ��
	n=6;							//����ͼ�Ķ������
	addEdge(0,2,10);				//����8����
	addEdge(0,4,30);
	addEdge(0,5,100);
	addEdge(1,2,4);
	addEdge(2,3,50);
	addEdge(3,5,10);
	addEdge(4,3,20);
	addEdge(4,5,60);
	printf("�ڽӱ�\n"); 
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<E[i].size();j++)
			printf("[%d,%d]:%d   ",i,E[i][j].vno,E[i][j].wt);
		printf("\n");
	}
	int s=0;						//Դ��
	bfs(s);
	printf("�����\n");
	dispallpath(s);
	return 0;
}
