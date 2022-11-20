#include<iostream>
#include<bits/stdc++.h>
using namespace std;

void worstfit(int block[],int process[],int b,int p){
  int index= INT_MIN;
  int maxempty = INT_MIN;
  int allocation[b] = {0};
  
  for(int i=0;i<b;i++){
    index = INT_MIN;
    maxempty= INT_MIN;
    for(int j=0;j<p;j++){
      if(block[j] >= process[i]){
        if((block[j]-process[i]) > maxempty){
          maxempty = block[j] - process[i];
          index = j;
        }
      }
    }
    if(index != INT_MIN){
      block[index] = block[index] - process[i];
      allocation[i] = index +1;
    } 
  }
  
  cout<<"process\t "<<"allocated block"<<endl;
  for(int i=0;i<p;i++){
    if(allocation[i]>0){
      cout<<process[i]<<"\t"<<allocation[i]<<endl;
    }
    else{
      cout<<process[i]<<"\t" <<"Not Allocated"<<endl;
    }
  }
}

int main(){
  int block[5] = {100,150,50,40,60};
  int process[5] = {20,50,80,100,10};
  
  int b = sizeof(block)/sizeof(block[0]);
  int p = sizeof(process)/sizeof(process[0]);
  
  worstfit(block,process,b,p);
  return 0;
}
