#include<iostream>
using namespace std;

int main(){
    int arr[6]={20,-10,30,-20,40,8};
    int pos=0, neg=0;
    int posval[6];
    int negval[6];
    int j=0 , k=0;
    for(int i=0;i<6;i++)
    {
        if(arr[i]>0){
            pos++;
            posval[j]=arr[i];
            j++; 
        }
        else if(arr[i]<0){
            neg++;
            negval[k]=arr[i];
            k++;
        }
       
    }
  
    cout<<"Positive values: ";
    for(int i=0;i<j;i++)
    {
        cout<<posval[i]<<" ";
    }
    cout<<endl;
    cout<<"Negative values: ";
    
    for(int i=0;i<k;i++)
    {
        cout<<negval[i]<<" ";
    }
    cout<<endl;
}