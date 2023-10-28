//Assignment 2 Bellman ford


#include<iostream>
using namespace std;

int main(){
	int v,e,source;
	
	
	cout<<"enter the no. of vertices::";
	cin>>v;
	cout<<"enter the no. of edges::";
	cin>>e;
	cout<<"enter the source vertex::";
	cin>>source;
	
	int mat[3][e];
	int dist[v];
	
	for(int i=0;i<e;i++){
		cout<<"enter the start vertex::";
		cin>>mat[0][i];
		cout<<"enter the ending vertex::";
		cin>>mat[1][i];;
		cout<<"enter the value of edge::";
		cin>>mat[2][i];;
	}
	
	cout<<"startpoint::";	
	for(int j=0;j<e;j++){
	 cout<<mat[0][j]<<"\t";
	}cout<<endl<<"end point ::";
	for(int j=0;j<e;j++){
	 cout<<mat[1][j]<<"\t";
	}cout<<endl<<"values   ::";
	for(int j=0;j<e;j++){
	 cout<<mat[2][j]<<"\t";
	}cout<<endl;
	
	for(int i=0;i<v;i++){
		dist[i]=999;
	}
	dist[source]=0;
	
	
	
	int start,end;
	for (int j = 0; j < v; j++)
	{
		int flag = 0;
		for (int i = 0; i < e; i++)
		{
			start = mat[0][i];
			end = mat[1][i];
			if (dist[start] != 999)
			{
				if (dist[end] > (dist[start] + mat[2][i]))
				{
					dist[end] = dist[start] + mat[2][i];
					flag = 1;
				}
			}
		}
		if (flag == 0 && j != (v - 1))
		{
			break;
		}
		else if (flag == 1 && j == (v - 1))
		{
			cout << "there exists a negative loop\n";
		}

		cout << "iteration " << j + 1 << ": ";
		for (int i = 0; i < v; i++)
		{
			cout << dist[i] << "\t";
		}
		cout << endl;
	}
}