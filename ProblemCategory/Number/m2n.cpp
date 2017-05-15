//m进制数转n进制数

void m2n(int m, char* mNum, int n, char* nNum) 
{
    int i = 0;
    char c, *p = nNum;
 
    //这是一个考察地方，是否能用最少乘法次数。
    while (*mNum != '\0')
        i = i*m + *mNum++ - '0';
     
    //辗转取余
    while (i) {
        *p++ = i % n + '0';
        i /= n;
    }
    *p-- = '\0';
 
    //逆置余数序列
    while (p > nNum) {
        c = *p;
        *p-- = *nNum;
        *nNum++ = c;
    }
}