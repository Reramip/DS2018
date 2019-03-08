#include<iostream>
#include<vector>
#include<stack>
using namespace std;

vector<vector<int> >nodeNext;
int* critical;
int* cost;

int main(){
    int n;
    cin>>n;
    nodeNext.resize(n+3);
    nodeNext.reserve(n+2);
    critical=new int[n+2];
    cost=new int[n+2];
    for(int i=0;i<n+2;++i){
        critical[i]=0;
        cost[i]=0;
    }
    while(1){
        int now,next,weight;
        cin>>now>>next>>weight;
        if(now==0&&next==0) break;
        nodeNext[now].push_back(next);
        int temp=cost[now]+weight;
        if(temp>cost[next]){
            cost[next]=temp;
            critical[next]=now;
        }
    }
    stack<int> s;
    s.push(n+1);
    int to_find=critical[n+1];
    for(int i=n+1;i>=0;i--){
        if(i==to_find){
            s.push(i);
            to_find=critical[i];
        }
    }
    while(!s.empty()){
        cout<<s.top()<<' ';
        s.pop();
    }

    return 0;
}
