#include <iostream>
using namespace std;

const int MaxLen = 20;

class Map{
private:
	bool Visit[MaxLen];
	int Matrix[MaxLen][MaxLen];
	int Vexnum;
	void DFS(int v);
public:
	void SetMatrix(int vnum,int mx[MaxLen][MaxLen]);
	void DFSTraverse();
};
void Map::SetMatrix(int vnum, int mx[20][20])
{
	int i,j;
	Vexnum = vnum;
	for(i=0;i<MaxLen;i++)
		for(j=0;j<MaxLen;j++)
			Matrix[i][j] = 0;
	for(i=0;i<Vexnum;i++)
		for(j=0;j<Vexnum;j++)
			Matrix[i][j]=mx[i][j];
}
void Map::DFSTraverse()
{
	int v;
	for(v=0;v<Vexnum;v++)
		Visit[v]=false;
	for(v=0;v<Vexnum;v++)
	{
		if(!Visit[v])
			DFS(v);
	}
	cout<<endl;
}
void Map::DFS(int v)
{
	int w,i,k;
	Visit[v] = true;
	cout<<v<<" ";
	int *Adjvex = new int[Vexnum];
	for(w=0;w<Vexnum;w++)
		Adjvex[w]=-1;
	k=0;
	for(w=0;w<Vexnum;w++)
	{
		if(Matrix[v][w]==1)
			Adjvex[k++]=w;
	}
	i=0;
	for(w=Adjvex[i];w>=0;w=Adjvex[++i])
	{
		if(!Visit[w])
			DFS(w);
	}
	delete Adjvex;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int matrix[MaxLen][MaxLen];
		for(int i=0;i<MaxLen;i++)
		{
			for(int j=0;j<MaxLen;j++)
				matrix[i][j]=0;
		}
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				cin>>matrix[i][j];

		Map m;
		m.SetMatrix(n,matrix);
		m.DFSTraverse();
	}
}



