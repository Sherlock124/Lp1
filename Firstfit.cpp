#include<iostream>
using namespace std;

void firstfit(int block[],int process[],int p, int b){
  int allocation[b]={0};
  
  for(int i=0;i<p;i++){
    for(int j=0;j<b;j++){
      if(block[j] >= process[i]){
        allocation[i] = j+1;
        block[j] = block[j] - process[i];
        break;
      }
    }
  }
  
  cout<<"process\t"<<"allocated block"<<endl;
  
  for(int i=0;i<p;i++){
    if(allocation[i] != 0){
      cout<<process[i]<<"\t "<<allocation[i]<<endl;
    }
    else{
      cout<<process[i]<<"\t "<<"Not allocated"<<endl;
    }
  }
}


int main(){
  int block[5] = {100,240,30,50,150};
  int process[5] = {140,25,50,120,200};
   
  int p = sizeof(process)/sizeof(process[0]);
  int b = sizeof(block)/sizeof(block[0]);

  firstfit(block,process,p,b);
  return 0;
}
