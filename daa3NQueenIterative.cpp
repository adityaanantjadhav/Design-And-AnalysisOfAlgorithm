
//TIB 26 Aditya Anant Jadhav

#include<iostream>
using namespace std;

int ans(int n,int arr[2][10],int q){     
	int i;
	if(q==0){
		if(arr[1][0]!=n-1){
			arr[1][0]=arr[1][0]+1;	
            cout<<"queen0 placed at (0,"<<arr[1][0]<<")\n";	
			q++;
			return q;
		}
		else{
			cout<<"unsuccessful attempt\n";
			return n;
		}	
	}
	else{
		for(i=(arr[1][q]+1);i<n;i++){
			int flag=0;
			for(int j=q-1;j>=0;j--){
				if((arr[1][j]==i) || (abs(q-arr[0][j])==abs(i-arr[1][j]))){
					cout<<"cannot place queen"<<q<<" at ("<<q<<","<<i<<")\n";
					flag=1;
					break;
				}
			}
			if(flag==0){
				cout<<"queen"<<q<<" can be placed at ("<<q<<","<<i<<")\n";
				arr[0][q]=q;
				arr[1][q]=i;
				q++;
				return q;
			}
		}
		if(i==n){
			arr[1][q]=-1;
			q--;
			cout<<"\nlets back track::\n";
			return q;
		}
		else{
			cout<<"this is fault::\n";
			return 0;
		}
	}
	
}
				

int main(){
	int n,q=1;
	cout<<"enter the no. of queen::";
	cin>>n;
	int arr[2][10];
	for(int l=0;l<n;l++){
		arr[0][l]=0;
		arr[1][l]=0;
	}
	while(q!=n){
        cout<<"x::";
        for(int i=0;i<n;i++){
            cout<<arr[0][i]<<"\t";
        }cout<<endl<<"y::";
        for(int i=0;i<n;i++){
            cout<<arr[1][i]<<"\t";
        }cout<<endl;

		q=ans(n,arr,q);
	}
	
	cout<<"row column\n";
	for(int i=0;i<n;i++){
		cout<<arr[0][i]<<"   "<<arr[1][i]<<endl;
	}


    cout<<endl<<" ";
    for(int l=0;l<n;l++){
        cout<<" "<<l;
    }cout<<endl;
    for(int i=0;i<n;i++){
        cout<<i;
        for(int j=0;j<n;j++){
            cout<<"|";
            if(arr[1][i]==j)
                cout<<"@";
            else    
                cout<<" ";
        }cout<<"|\n";
    }
}

/*		OUTPUT

enter the no. of queen::4
x::0    0       0       0
y::0    0       0       0
cannot place queen1 at (1,1)
queen1 can be placed at (1,2)
x::0    1       0       0
y::0    2       0       0
cannot place queen2 at (2,1)
cannot place queen2 at (2,2)
cannot place queen2 at (2,3)

lets back track::
x::0    1       0       0
y::0    2       -1      0
queen1 can be placed at (1,3)
x::0    1       0       0
y::0    3       -1      0
cannot place queen2 at (2,0)
queen2 can be placed at (2,1)
x::0    1       2       0
y::0    3       1       0
cannot place queen3 at (3,1)
cannot place queen3 at (3,2)
cannot place queen3 at (3,3)

lets back track::
x::0    1       2       0
y::0    3       1       -1
cannot place queen2 at (2,2)
cannot place queen2 at (2,3)

lets back track::
x::0    1       2       0
y::0    3       -1      -1

lets back track::
x::0    1       2       0
y::0    -1      -1      -1
queen0 placed at (0,1)
x::0    1       2       0
y::1    -1      -1      -1
cannot place queen1 at (1,0)
cannot place queen1 at (1,1)
cannot place queen1 at (1,2)
queen1 can be placed at (1,3)
x::0    1       2       0
y::1    3       -1      -1
queen2 can be placed at (2,0)
x::0    1       2       0
y::1    3       0       -1
cannot place queen3 at (3,0)
cannot place queen3 at (3,1)
queen3 can be placed at (3,2)
row column
0   1
1   3
2   0
3   2

  0 1 2 3
0| |@| | |
1| | | |@|
2|@| | | |
3| | |@| |

*/