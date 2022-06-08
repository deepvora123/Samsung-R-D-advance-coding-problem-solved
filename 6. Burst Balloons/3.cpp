#include<iostream>
using namespace std;

int findLeft(int arr[],int n,int j,bool isBurst[],bool &found){//To find next left balloon that is not burst
	if(j <= 0){
		found = false;
		return 1;
	}
	for(int i=j-1;i>=0;i--){
		if(!isBurst[i]){
			return arr[i];
		}
	}
	found = false;
	return 1;//If no ballon found return 1
}

int findRight(int arr[],int n,int j,bool isBurst[],bool &found){//To find next right balloon that is not burst
	if(j >= n){
		found = false;
		return 1;
	}
	for(int i=j+1;i<=n;i++){
		if(!isBurst[i]){
			return arr[i];
		}
	}
	found = false;
	return 1;//If no ballon found return 1
}

int calc(int arr[],int n,int j,bool isBurst[]){//Calculate points to burst the current balloon
	int points=0;
	bool leftFound=true,rightFound=true;//To check if balloons exist to the left and right of current balloon
	int left = findLeft(arr,n-1,j,isBurst,leftFound);
	int right = findRight(arr,n-1,j,isBurst,rightFound);
	if(!leftFound && !rightFound){//If current balloon is the last balloon
		points += arr[j];
	}else{
		points += left * right;
	}
	return points;
}

void maxPoints(int arr[],int n,int cp,int curr_ans,int &ans,int count,bool isBurst[]){
	if(count == n){//If number of balloons burst equals total number of balloons
		if(curr_ans > ans){
			ans = curr_ans;
			return;
		}
	}
	for(int i=0;i<n;i++){
		
		if(!isBurst[i]){
			isBurst[i] = true;
			maxPoints(arr,n,i,curr_ans+calc(arr,n,i,isBurst),ans,count+1,isBurst);
			isBurst[i] = false;
		}
	}
}

int main(){
	int n;//No of balloons
	cin >> n;
	int ans=0;//Final answer
	int arr[n];
	bool isBurst[n];//To maintain if balloon is burst or not
	for(int i=0;i<n;i++){
		cin >> arr[i];
		isBurst[i] = false;
	}
	maxPoints(arr,n,0,0,ans,0,isBurst);
	cout << ans;
	return 0;
}