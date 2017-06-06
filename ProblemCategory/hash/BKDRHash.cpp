int BKDRHash(char* s)  
{  
    long long seed=131;  
    long long hash=0;  
    while(*s)  
    {  
        hash=hash*seed+(*s++);  
    }  
    return (hash & 0x7FFFFFFF);  
} 