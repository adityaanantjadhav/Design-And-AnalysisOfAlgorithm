//here in this program we store position of queen in 1-D array instead of 2-D array of chessboard size
//eg. queen 0 at position (0,2) will be stored as arr[0]=2
// or queen 4 at position (4,3) will be stored as arr[4]=3
//here index of array tell us the no. of queen as well as the row of that queen 
// while value at that index tells the column no.

#include<iostream>
using namespace std;

int arr[10];

int nQueen(int n,int q){
    int col=0;                    //col tracks column of each queen
    while(col<n){                   //till column is less than n
        for(int i=0;i<n;i++){
            cout<<arr[i]<<"  ";     //print arr
        }cout<<endl;

        if(q==0){                   //for 0th queen just update the column and call fuction till all are placed
            arr[q]=col;
            int a=nQueen(n,q+1);
            if(a==0)
                return 0;
        }
        else{
            int flag=0;
            for(int i=q-1;i>=0;i--){            //check the position if any other queen is in same column or is diagonally intercept
                if((arr[i]==col) || abs(col-arr[i])==abs(q-i)){
                    cout<<"cannot place "<<q<<" at "<<col<<endl;
                    flag=1;
                    break;
                }
            }
            if(flag==0){            //if position is safe then update the column in arr 
                cout<<"can place "<<q<<" at "<<col<<endl;
                arr[q]=col;
                if(q==n-1){         //if this is the last queen which is placed then return 0 so that every thing ends
                    return 0;
                }
                else{               //else call function for next queen
                    int c=nQueen(n,q+1);
                    if(c==-1){          //if function returns -1 then next queen cannot be placed in any column and we need to update this queen into another column
                        cout<<"cannot place "<<q<<" at here "<<col<<endl;
                    }
                    if(c==0){           //0 return means all next queens are placed and we can stop 
                        return 0;
                    }
                }
            }
        }
        col++;  //update the column
    }
    if(col==n){     //if col is n means queen cannot be placed in any column and we need to replace previous queen
        col=0;
        return -1;
    }
}

void print(int n){      //prints the chess board
    cout<<"\n   ";
    for(int i=0;i<n;i++){
        cout<<i+1<<" ";
    }cout<<endl;
    for(int i=0;i<n;i++){
        cout<<i+1<<":|";
        for(int j=0;j<n;j++){
            if(arr[i]==j){
                cout<<"@";
            }
            else{
                cout<<" ";
            }   
            cout<<"|";
        }cout<<endl;
    }
}



int main(){
    int n;
    cout<<"enter the no. of queens::";
    cin>>n;
    for(int j=0;j<n;j++){       //initializing arr as 0
        arr[j]=0;
    }
    
    nQueen(n,0);
    print(n);


}