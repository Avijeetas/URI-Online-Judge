
#include<string.h>
#include<stdio.h>
int g[205][205],n,a,b;
void floyd()
{
  for(int k=1;k<=n;k++)
    for(int i=1;i<=n;i++)
   		for(int j=1;j<=n;j++)
            g[i][j]|=(g[i][k]&g[k][j]);

}
int main()
{
	while(~scanf("%d",&n) &&n)
	{
		memset(g,0,sizeof g);
				char s[205];
	
		while(~scanf("%d %d",&a,&b) && a &&b)
		{

			scanf("%s",s);
			for(int i=0;i<strlen(s);i++)
			{
				g[a][b]|=1<<(s[i]-'a');
			}
		}
		floyd();
		while(~scanf("%d %d",&a,&b) && a &&b)
		{
			int f=0;
			for(int i=0;i<26;i++)
			{
				if(g[a][b]& (1<<i))
				{
					printf("%c",'a'+i);
					f=1;
				}
			}
			if(!f)
			printf("-");
			printf("\n");
		}
			printf("\n");
	}
	return 0;
	
}