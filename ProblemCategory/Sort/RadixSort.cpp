//http://www.cnblogs.com/cityflickr/p/3896109.html

//寻找数组中最大数的位数作为基数排序循环次数
int KeySize(int a[], int n){
    int key = 1;
    for(int i=0;i<n;i++){
        int temp = 1;
        int r = 10;
        while(a[i]/r>0){
            temp++;
            r*=10;
        }
        key = (temp>key)?temp:key;
    }
    return key;
}

//基数排序
void RadixSort(int a[], int n){
    int key = KeySize(a,n);
    int bucket[10][10]={0};
    int order[10]={0};
    for(int r = 1;key>0;key--,r*=10){
        for(int i=0;i<n;i++){
             int lsd = (a[i]/r)%10;
             bucket[lsd][order[lsd]++]=a[i];
        }

        int k = 0;
        for(int i = 0;i<10;i++){
            if(order[i]!=0){
                for(int j = 0;j<order[i];j++)
                    a[k++]=bucket[i][j];
            }
            order[i]=0;
        }
    }
}