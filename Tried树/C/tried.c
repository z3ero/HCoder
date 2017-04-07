/*************************************************************************
	> File Name: tried.c
	> Author: Z3ero
	> Mail: lzzmyth@sina.com 
	> Created Time: 2017年04月07日 星期五 21时30分06秒
 ************************************************************************/
#include<stdio.h>
#define MAX 26   //字符集大小
typedef struct TrieNode
{
    int nCount;   //记录该字符出现的次数
    struct TrieNode* next[MAX];
}TrieNode;

TrieNode Memory[1000000];
int allocp=0;
 
/*初始化*/
void InitTrieRoot(TrieNode* *pRoot)
{
    *pRoot=NULL;
}
 
/*创建新结点*/
TrieNode* CreateTrieNode()
{
    int i;
    TrieNode *p;
    p=&Memory[allocp++];
    p->nCount=0;
    for(i=0;i<MAX;i++)
    {
        p->next[i]=NULL;
    }
    return p;
}
/*插入*/
void InsertTrie(TrieNode* *pRoot,char *s)
{
    int i,k;
    TrieNode*p;
    if(!(p=*pRoot))
    {
        p=*pRoot=CreateTrieNode();
    }
    i=0;
    while(s[i])
    {
        k=s[i++]-'a';//确定branch
        if(!p->next[k])
            p->next[k]=CreateTrieNode();
        p->next[k]->nCount++;
        p=p->next[k];
    }
}

//查找
int SearchTrie(TrieNode* *pRoot,char *s)
{
    TrieNode *p;
    int i,k;
    if(!(p=*pRoot))
    {
        return 0;
    }
    i=0;
    while(s[i])
    {
        k=s[i++]-'a';
        if(p->next[k]==NULL) return 0;
        p=p->next[k];
    }
    return p->nCount;
}

int main()
{
    int n,m;
    char arr[10];
    TrieNode *pRoot=NULL;
    InitTrieRoot(&pRoot);  //初始化字典树
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",arr);
        InsertTrie(&pRoot,arr);
    }
    scanf("%d",&m);
    while(m--)
    {
        scanf("%s",arr);
        printf("%d\n",SearchTrie(&pRoot,arr));
    }
    return 0;
}

