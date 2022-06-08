#include <iostream>
#define INT_MAX 999999
using namespace std;

int n,ans;
bool visited[100];

struct gate{
    int loc, men;
}gates[4];

int findLeft(int index){
    for(int i = index; i>0; i--){
        if(visited[i]==false)
            return i;
    }
    return INT_MAX;
}

int findRight(int index){
    for(int i = index+1; i<=n; i++){
        if(visited[i]==false)
            return i;
    }
    return INT_MAX;
}

void solve(int x,int y, int z, int distance, int cur_gate){
    //optimization condition, never forget
    if(distance > ans) return;

    //base case when all the mens at the current gate have occupied their places change gate
    if(gates[cur_gate].men==0){
        if(cur_gate==x) cur_gate=y;
        else if(cur_gate==y) cur_gate=z;
        // if every possible combination is seen just return the minimum distance
        else{
            ans=min(ans,distance);
            return ;
        }
    }

    //recursive case
    //searching for vacant spot at the left of current gate
    int l = findLeft(gates[cur_gate].loc);
    //searching for vacant spot at the right of current gate
    int r = findRight(gates[cur_gate].loc);

    //cost of occupying the left vacant spot
    int costL = abs(gates[cur_gate].loc - l) + 1;
    //cost of occupying the right vaacant spot
    int costR = abs(gates[cur_gate].loc - r) + 1;

    bool goRight=true, goLeft=true;
    if(costL > costR) goLeft = false;
    if(costR > costL) goRight = false;

    if(goLeft){
        visited[l]=true;
        gates[cur_gate].men--;
        solve(x,y,z,distance + costL, cur_gate);
        //backtracking
        visited[l]=false;
        gates[cur_gate].men++;
    } 

    if(goRight){
        visited[r]=true;
        gates[cur_gate].men--;
        solve(x,y,z,distance + costR, cur_gate);
        //backtracking
        visited[r]=false;
        gates[cur_gate].men++;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--){
        cin>>n;

        //enter data for the positions and mens at the gate
        for(int i=1; i<=3; i++)
            cin>>gates[i].loc>>gates[i].men;

        for(int i=0; i<100; i++)
            visited[i]=false;
        
        ans=INT_MAX;
        //checking for all possible permutations of gate opening
        solve(1,2,3,0,1);
        solve(1,3,2,0,1);
        solve(2,1,3,0,2);
        solve(2,3,1,0,2);
        solve(3,1,2,0,3);
        solve(3,2,1,0,3);
        
        cout<<ans<<endl;
        
    }
    return 0;
}