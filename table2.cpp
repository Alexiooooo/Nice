#include<iostream>
#include<algorithm>
using namespace std;
int m,n,chislo[1001][1001],suma[1001][1001],naiM,posledno[1001];
const int INF=100000001;
bool ready[1001][1001];
int sum(int x,int y){
    if(ready[x][y]){
        return suma[x][y];
    }
    else if(x>=m||y>=n||x<0||y<0){
        return INF;
    }
     else if(y==0){
        suma[x][0]=chislo[x][0];
        ready[x][0]=true;
        return suma[x][0];
    }
    else{
        suma[x][y]=min(min(sum(x-1,y-1),sum(x,y-1)),min(sum(x,y-1),sum(x+1,y-1)))+chislo[x][y];
        ready[x][y]=true;
    }
    return suma[x][y];
}
int main(){
cin>>m>>n;
for(int i=0;i<m;i++){
    for(int j=0;j<n;j++){
        cin>>chislo[i][j];
    }
}
/*
for(int l=0;l<m;l++){
    posledno[l]=sum(l,n-1);
}
sort(posledno,posledno+m);
cout<<posledno[0];
*/

sum(0,n-1);
naiM=suma[0][n-1];
for(int k=1;k<m;k+=1){
    sum(k,n-1);
    if(suma[k][n-1]<naiM){
        naiM=suma[k][n-1];
    }
}
cout<<naiM;


return 0;
}
