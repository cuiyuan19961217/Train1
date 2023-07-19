
#include "stdio.h"
#include "stdlib.h"
#include "list.h"
#include <string.h>



/* 描述：反转链表
     输入：
     输出：
     返回值：
*/
STLinkBook *Reserve(STLinkBook *phead)
{
    STLinkBook *pre = NULL,*pCur,*pTemp;
    if(  phead == NULL || phead ->next == NULL )
         return phead; 

     while(phead != NULL)
     {
               pTemp = phead->next;// 记录下一个结点    phead -> pTemp->3->4->5
               phead->next = pre;    //   pre<-phead x  Ptemp->3->4->5 断开当前结点与下一个结点的连接，并指向前一个结点
               pre = phead;   //    null <- phead /pre  x pTemp
               phead = pTemp;  //    null <-pre  x  phead /pTemp->3->4->5

     }
     
     return pre;

}

/* 描述：反转链表指定区域
     输入：
     输出：
     返回值：
*/
STLinkBook *ReserveDomain(STLinkBook *phead,int m,int n)
{
     STLinkBook *pre = NULL,*pcur;
    if(  phead == NULL || phead ->next == NULL )
         return phead; 

}

/* 描述：创建链表
     输入：
     输出：
     返回值：指针，指向STLinkBook数据类型
*/
STLinkBook *CreatLink()
{
     // 分配空间
     STLinkBook *pTemp;
       pTemp = (STLinkBook *) malloc(sizeof(STLinkBook));
     // 初始化
     pTemp->number = 0xff;
     memset(&(pTemp->book),0,sizeof(STBook)); //
     pTemp->next = NULL;
     return pTemp;
}

/* 描述：单链表删除
     输入：
     输出：
     返回值：
*/
void DeleteList(STLinkBook *phead)
{
    STLinkBook *pCur;
    if(phead == NULL )
    {
          printf("已经是空表，无需删除！");
    }
    while(phead !=NULL)
    {
          pCur = phead;
          phead = phead->next;
          pCur->next = NULL;
          free(pCur);
          
    } 
}

/* 描述：计算表长度
     输入：
     输出：
     返回值：
*/
int  ListLength(STLinkBook *phead)
{
     int Length = 0;
     while(phead)
     {
          phead = phead->next;
          Length++;

     }

     return Length;
}

/* 描述：从链表中查找相应的结点
     输入：STLinkBook *phead：头结点，char *name：限定条件（书名）
     输出：
     返回值：结点地址
*/
STLinkBook  *FindList(STLinkBook *phead,char *name)
{
     int uState = 0;
     if(phead == NULL || phead->next == NULL)
          return phead;

     while(phead)
     {
          for(int i = 0 ;i<sizeof(phead->book.Title);i++)
          {
               uState = 0;
               if(phead->book.Title[i] != name[i])
                    {
                         uState = 1;
                         break;
                    }

          }

          if(uState == 0)
               return phead;
          else
               phead = phead->next;
     }

     if(phead == NULL && uState == 1)
          printf("未找到与之匹配的内容！\n");
     return phead;


}

/* 描述：从链表中查找相应的结点并删除
     输入：STLinkBook *phead：头结点，char *name：限定条件（次序）
     输出：
     返回值：头结点地址
*/
STLinkBook  *FindNodeDelete(STLinkBook *phead,int num)
{
     int uState = 0; 
     STLinkBook *pre= NULL;
     STLinkBook *pTemp = phead ;
     if(phead == NULL || phead->next == NULL)
          return phead;

     while(pTemp)
     {
          uState = 0;
          if(pTemp->number != num)
          {
               uState = 1;
               pre = pTemp;
               pTemp = pTemp->next;
          }
               
          if(uState == 0)
          {
               pre->next = pTemp->next; // 跳过pTemp结点
               pTemp->next = NULL;
               free(pTemp);
               return phead;
          }          
                        
     }

     if(pTemp == NULL && uState == 1)
     {
          printf("未找到与之匹配的内容！\n");
          return phead;
     }

}

/* 描述：在链表的i位置前（后）插入新结点
     输入： STLinkBook *phead：头结点;
                    int pos：限定条件（位置）;
                    int method：限定条件（0：前或1：后）
                    STLinkBook *pInsert：待插入的结点
     输出：
     返回值：头结点地址
*/
STLinkBook  *InsertNode(STLinkBook *phead,STLinkBook *pInsert,int pos,int method)
{
          STLinkBook *pTemp = phead,*pre = NULL;
          STLinkBook *L = ( STLinkBook *)malloc(sizeof( STLinkBook )); // 头指针
          L->next = phead;  // 添加一个虚拟的前置结点
          
          if(phead == NULL)
               return phead;
          
          for(int i = 0;i<pos;i++)
          {
               
               pre = L;
               L = L->next;
               if(L== NULL)
               {
                    printf("当前待插入的链表长度为%d小于%d，请重新选择插入的位置！\n",i,pos);
                    return phead;
               }
               // 
               if(i == (pos-1))
               {
                    switch (method)
                    {
                         case 0:  // 前插入
                              if(pos == 1)
                              {
                                   pre->next = pInsert;
                                   pInsert->next = L;
                                   phead = pInsert;
                                   printf("在第%d个结点前插入结点成功！\n",pos);
                              }
                              else
                              {
                                   pre->next = pInsert;
                                   pInsert->next = L;
                                   printf("在第%d个结点前插入结点成功！\n",pos);
                              }
                              
                              break;
                         case 1: // 后插入
                              pInsert->next = L->next;
                              L->next = pInsert;
                              printf("在第%d个结点后插入结点成功！\n",pos);
                              break;
                         
                         default:
                              break;
                    }  // end switch

               } // end if

          } // end for     
          
          return phead;
}
