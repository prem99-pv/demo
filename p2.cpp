#include<iostream>
using namespace std;

int main(){
    int arr[6]={10,20,30,20,40,8};

    int largest;
    int secondLargest;
    largest=secondLargest=arr[0];

    for(int i=1; i<6; i++){
        if(arr[i]>largest){
            secondLargest=largest;
            largest=arr[i];
        }
        else if(arr[i]>secondLargest && arr[i]!=largest){
            secondLargest=arr[i];
        }
    }
    cout << "Largest: " << largest << endl;
    cout << "Second Largest: " << secondLargest << endl;
    
}