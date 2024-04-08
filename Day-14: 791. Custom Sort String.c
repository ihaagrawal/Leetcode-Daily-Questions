// 791. Custom Sort String (MEDIUM)
// https://leetcode.com/problems/custom-sort-string/description/?envType=daily-question&envId=2024-03-11

char* customSortString(char* order, char* s) {
    int i,j,k=0;
    int order_len=strlen(order), s_len=strlen(s);

    char* str = (char*)malloc(sizeof(char) * (order_len + s_len + 1)); 
    
    for(i=0;i<order_len;i++)
        {
            char ch=order[i];
            for(j=0;j<s_len;j++)
                {
                    if(s[j]==ch)
                        {
                            str[k]=ch;
                            k++;
                        }
                } 
        }
    for(j=0;j<s_len;j++)
        {
            char ch=s[j];
            if(!strchr(order, ch))
                {
                    str[k]=ch;
                    k++;
                }
        }
    str[k]='\0';
    return str;
}
