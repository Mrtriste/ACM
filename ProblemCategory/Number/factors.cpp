//一个数的因子个数

/**
 * 有没有漏掉呢？
 * 
 * 假设存在一个正整数 K,使得 K * M = N, 且  K 不在 1, sqrt(N)之间，且M 为正整数
 * 那么 M必在(1, sqrt(N))之间，否则 K*M >sqrt(N)*sqrt(N) = N,与 K*M = N矛盾
 * 即只要存在两个正整数K, M,使得 K * M = N,那么K， M中必有一个在[1, sqrt(N)]区间中
 */
//o(sqrt(n))
int factors(int N){
    if(1 == N) return 1;
    int count = 2;// 1 与 N 必是
    int sqrt_N = (int)sqrt(N);
    int r;
    for(int i = 2; i <= sqrt_N; i++){
        if(0 == N % i){
            if(i == sqrt_N){
                r = N / i;
                if(r == i){//比如 4 = 2 * 2；那么2 只能算一个
                    count++;
                }else{
                    count += 2;
                }
            }else{
                count += 2;
            }
        }
    }
     
    return count;
}