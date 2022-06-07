#include<iostream>
using namespace std;
int row,col;
int a[100][100],visited[100][100],loc[100][2];
int sol=999999;
bool issafe(int x,int y) {
	return (x>=0 && x<row && y>=0 && y<col && a[x][y]==1 && visited[x][y]==0);
}
bool research(int x,int y,int x1,int y1,int count) {
	if(x==x1 && y==y1) {
		visited[x][y]=1;
		if(sol>count) {
			sol=count;
		}
		return true;
	}
	if(issafe(x,y)) {
		visited[x][y]=1;
		if(research(x,y-1,x1,y1,count+1)==true) {
			return true;
		}
		if(research(x,y+1,x1,y1,count+1)==true) {
			return true;
		}
		if(research(x-1,y,x1,y1,count+1)==true) {
			return true;
		}
		if(research(x+1,y,x1,y1,count+1)==true) {
			return true;
		}
	}
	return false;
}
int main() {
	int t,index=1;
	cin>>t;
	while(t--) {
		cin>>row>>col;
		for(int i=0;i<row;i++) {
			for(int j=0;j<col;j++) {
				cin>>a[i][j];
				visited[i][j]=0;
			}
		}
		int rare;
		cin>>rare;
		for(int i=0;i<rare;i++) {
			cin>>loc[i][0]>>loc[i][1];
		}
		int longest=0,flag=0,long_index=0,maxdist[row*col];
		for(int i=0;i<row;i++) {
			for(int j=0;j<col;j++) {
				if(a[i][j]==1) {
					for(int k=0;k<rare;k++) {
						if(research(loc[k][0],loc[k][1],i,j,0)==true) {
							if(longest<sol) {
								longest=sol;
							}
							sol=INT_MAX;
						}
						else {
							flag=1;
							break;
						}
					//	memset(visited,0,sizeof(visited));
						for(int i=0;i<row;i++) {
							for(int j=0;j<col;j++) {
								visited[i][j]=0;
							}
						}
					}
					if(flag==0) {
						maxdist[long_index]=longest;
						long_index++;
					}
					else {
						flag=0;
					}
					longest=0;
				}
			}
		}
		int j=0;
		for(int i=1;i<long_index;i++) {
			if(maxdist[i]<maxdist[j]) {
				j=i;
			}
		}
		cout<<"#"<<index<<" "<<maxdist[j]<<endl;
		index++;
	}
	return 0;
}