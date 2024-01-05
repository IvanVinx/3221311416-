#include <stdio.h>
#include <string.h>
#define min(a,b) a>b? b:a
void manacher(char *s, char *r)
{
  char t[2500]={0},len[2500]={0};//len[]->长度;t->用于处理的string
  t[0]='*';t[1]='#';
  for(int i=0;s[i]!=0;i++)//预处理 +‘#’
  {
  t[2*i+2]=s[i];
  t[2*i+3]='#' ;
  }
  int mx=0,i,mid=0,ans=0,x;
  for( i=1;t[i]!=0;i++)
  {
    if(i<mx)
    len[i]= min(len[mid*2-i],mx-i);
    else len[i]=1;
    while(t[i-len[i]]==t[i+len[i]])
    len[i]++;
    if(len[i]+i>mx)
    {
       mx=len[i]+i;
       mid=i;
    }
    /*！！注意mid不是最大的中间位置！！！
      是当前的可容纳最多元素的字串的中间位置
      mx边界 need choose the big */
    if(len[i]>ans)
    {
        ans=len[i];
	    x=i;//x——>最大子串的位置
    }
  }  //ans->the length of the longest string 
    // you can try a example like abba->*a#b#b#a#
  //or   aba->#a#b#a#
  ans--;//-1就将半径变为长度
  
  int j=0;
  for(i=x-ans;i<=x+ans;i++)//mid -〉 t[]中的位置
   {
       if(t[i]!='#'&&t[i]!='*')
        {
          r[j]=t[i];
          j++;
        }
   }
}//题目要求输出最长字串
int main()
{
    char s[1001]= {0}, r[1001] = {0};
    scanf("%s", s);
    manacher(s, r);
    printf("%s", r);
    return 0;
}



