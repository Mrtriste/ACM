int maxSubSum(const vector<int> & arr,int &begin,int &end){
    int maxSum=0;
    int currSum=0;
    int newbegin=0;
    for(int i=0;i<arr.size();++i){
        currSum+=arr[i];
        if(currSum>maxSum){
            maxSum=currSum;
            begin=newbegin;
            end=i;
        }
        if(currSum<0){
            currSum=0;
            newbegin=i+1;
        }
    }
    return maxSum;
}