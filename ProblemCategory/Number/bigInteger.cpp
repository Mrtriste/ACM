#include <string.h>  
#include <vector>  
using namespace std;  
  
#define MAX 101  
  
struct bigInteger{  
    int digit[MAX];  
    int size;  
    void init(){  
        for(int i = 0 ; i < MAX ; ++i){  
            digit[i] = 0;  
        }  
        size = 0;  
    }  
    void set(char s[]){         //用一个小整数来设置高精度整数  
        init();  
        int l = strlen(s);  
        for(int i = l-1 , j = 0 , t = 0 , c = 1 ; i >= 0 ; --i){  
            t += (s[i]-'0') * c;  
            j++;  
            c *= 10;  
            if(j == 4 || i == 0){  
                digit[size++] = t;  
                j = 0;  t = 0;  c = 1;  
            }  
        }  
    }  
    bigInteger operator * (const int x) const {  
        bigInteger ret;  
        ret.init();  
        int carry = 0;  
        for(int i = 0 ; i < size ; ++i){  
            int t = (digit[i] * x + carry) % 10000;  
            carry = (digit[i] * x + carry) / 10000;  
            ret.digit[ret.size++] = t;  
        }  
        if(carry != 0){  
            ret.digit[ret.size++] = carry;  
        }  
        return ret;  
    }  
    bigInteger operator + (const bigInteger &A) const{  
        bigInteger ret;  
        ret.init();  
        int carry = 0;  
        for(int i = 0 ; i < size || i < A.size ; ++i){  
            int t = digit[i] + A.digit[i] + carry;  
            carry = t / 10000;  
            t = t % 10000;  
            ret.digit[ret.size++] = t;  
        }  
        if(carry != 0){  
            ret.digit[ret.size++] = carry;  
        }  
        return ret;  
    }  
    bool operator < (const bigInteger &A) const {  
        if(size != A.size){  
            return size<A.size;  
        }  
        else{  
            for(int i = size - 1 ; i >= 0 ; --i){  
                if(digit[i] != A.digit[i]){  
                    return digit[i] < A.digit[i];  
                }  
            }  
        }  
    }  
    int operator % (const int x) const {  
        int r = 0;  
        for(int i = size - 1 ; i >= 0 ; --i){  
            int t = r*10000 + digit[i];  
            r = t % x;  
        }  
        return r;  
    }  
};  