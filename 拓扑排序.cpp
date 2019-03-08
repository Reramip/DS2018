#include<iostream>
#include<queue>
#include<vector>
using namespace std;

vector<vector<int> > nodeNext;
int* indegree;
queue<int> q;

int main(){
    int n;
    cin>>n;
    indegree=new int[n+1];
    for(int i=0;i<=n;i++){
        indegree[i]=0;
    }
    nodeNext.resize(n+2);
    nodeNext.reserve(n+1);
    while(1){
        int now,next;
        cin>>now>>next;
        if(now==0&&next==0){
            break;
        }
        nodeNext[now].push_back(next);
        indegree[next]++;
    }
    for(int i=1;i<=n;i++){
        if(indegree[i]==0){
            q.push(i);
        }
    }
    while(!q.empty()){
        int now=q.front();
        cout<<now<<' ';
        q.pop();
        for(auto itr=nodeNext[now].begin();itr!=nodeNext[now].end();++itr){
            int value=*itr;
            if(--indegree[value]==0){
                q.push(value);
            }
        }
    }

    return 0;
}
