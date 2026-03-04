#include<string.h>
#include <stdio.h>

int main()
{
    char str[110];
    fgets(str, 110, stdin);
    int l = strlen(str);
    str[l-1] = '\0';
    l--;
    
    char ans[110] = "";
    for(int i=0;i<l;i+=2){
        int t = str[i+1] - '0';
        t++;
        while(t--){
            int n = strlen(ans);
            ans[n] = str[i];
        }
    }
    
    printf("%s", ans);

    return 0;
}
