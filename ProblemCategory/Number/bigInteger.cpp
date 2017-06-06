#include <string.h>  
#include <vector>  
using namespace std;  
  
#define MAX 101  
  
struct BigInteger{  
    int digit[MAX];  
    int size;  

    BigInteger(){
        init();
    }

    void init(){
        size = 0;
        memset(digit, 0, sizeof(digit));
    }

    void set(char s[]){         //用一个小整数来设置高精度整数  
        int b = 0, l = strlen(s) - 1;
        while (s[b] == '0'&&b + 1 <=l)++b;
        for (int i = l, k = 0, t = 0, c = 1; i >= b; --i){
            t += (s[i] - '0') * c;
            k++;
            c *= 10;
            if (j == 4 || i == b){
                digit[size++] = t;
                k = 0;  t = 0;  c = 1;
            }
        }
    } 

    void set(int d){
        while (d >= 10000){
            digit[size++] = d % 10000;
            d /= 10000;
        }
        digit[size++] = d;
    }

    BigInteger operator + (const BigInteger &A) const{  
        BigInteger ret; 
        int c = 0,t;  
        for(int i = 0 ; i < size || i < A.size ; ++i){  
            t = digit[i] + A.digit[i] + c;  
            ret.digit[ret.size++] = t % 10000;  
            c = t / 10000;  
        }  
        if(c != 0)
            ret.digit[ret.size++] = c;  
        
        return ret;  
    }  

    BigInteger operator-(const BigInteger & b) const   //两个大数之间的相减运算 
    {
        int i, j, l;
        bool flag;
        BigInteger t1, t2;//let t1>t2
        if (*this<b)
            t1 = b,t2 = *this,flag = 1;
        else
            t1 = *this,t2 = b,flag = 0;
        l = t1.size;
        for (i = 0; i < l; i++){
            if (t1.digit[i] < t2.digit[i]){
                j = i + 1;
                while (t1.digit[j] == 0)
                    j++;
                t1.digit[j--]--;
                while (j > i)
                    t1.digit[j--] += 9999;
                t1.digit[i] += 10000 - t2.digit[i];
            }
            else
                t1.digit[i] -= t2.digit[i];
        }
        l = t1.size - 1;
        while (t1.digit[l] == 0 && l >= 1)
            l--;
        t1.size = l + 1;
        if (flag)
            t1.digit[l] = - t1.digit[l];
        return t1;
    }

    BigInteger operator*(const int x)const{
        BigInteger ret;
        int t, c = 0;
        for (int i = 0; i < size; ++i){
            t = digit[i] * x + c;
            ret.digit[ret.size++] = t % 10000;
            c = t / 10000;
        }
        while (c >= 10000){
            ret.digit[ret.size++] = c%10000;
            c /= 10000;
        }
        if (c!=0)
            ret.digit[ret.size++] = c;
        return ret;
    }

    BigInteger operator*(const BigInteger& b){
        BigInteger ret;
        int i, j;
        for (i = 0; i < size; ++i){
            int t, c = 0;
            for (j = 0; j < b.size; ++j){
                t = (ret.digit[i+j]+digit[i] * b.digit[j] + c);//10^(i+j)的系数
                ret.digit[i+j] = t % 10000;
                c = t / 10000;
            }
            if (c != 0)
                ret.digit[i + j] = c;//here j = b.size, instead of b.size-1
        }
        ret.size = i + j;
        while (ret.digit[ret.size - 1] == 0 && ret.size > 1)
            ret.size--;
        return ret;
    }

    BigInteger operator/(const int x){
        BigInteger ret;
        int i, down = 0;
        for (i = size - 1; i >= 0; i--)
        {
            ret.digit[i] = (digit[i] + down * 10000) / x;
            down = (digit[i] + down * 10000) % x;
        }
        ret.size = size;
        while (ret.digit[ret.size - 1] == 0 && ret.size > 1)
            ret.size--;
        return ret;
    }

    BigInteger operator^(int n) const    //大数的n次方运算
    {
        BigInteger t, ret;
        ret.set(1);
        int i;
        if (n<0) exit(-1);
        t = *this;
        while (n > 0){
            if (n & 1)
                ret = ret*t;
            t = t*t;
            n >>= 1;
        }
        return ret;
    }

    int operator % (const int x) const {  
        int r = 0,t;  
        for(int i = size - 1 ; i >= 0 ; --i){  
            t = r*10000 + digit[i];  
            r = t % x;  
        }  
        return r;  
    }  

    bool operator < (const BigInteger &A) const {  
        if(size != A.size)
            return size<A.size;  
        
        for(int i = size - 1 ; i >= 0 ; --i)
            if(digit[i] != A.digit[i])
                return digit[i] < A.digit[i];  
        return false;
    }

    void print(){
        int l = size-1;
        printf("%d", digit[l]);
        for (int i = l-1; i >= 0; --i)
            printf("%04d", digit[i]);
        cout << endl;
    }
};  

istream& operator>>(istream & in, BigInteger & b){
    char a[100]; cin >> a;
    b.set(a);
    return in;
}

ostream& operator<<(ostream&out, BigInteger& b){
    b.print();
    return out;
}