#include<iostream>
using namespace std;

int main(){
    int arr[6]={20,30,10,20,40,50};
    int length=sizeof(arr)/sizeof(arr[0]);
 
    for(int i=0; i<length; i++){
        for(int j=i+1; j<length; j++){
            if(arr[i]==arr[j]){
                for(int k=j; k<length; k++){
                    arr[k]=arr[k+1];
                }
                length--;      
           }
        else{
            j++;
         }
        }
    }
    cout << "Array after removing duplicates: ";
    for (int i = 0; i < length; i++){
        cout << arr[i] << " ";
    }
}