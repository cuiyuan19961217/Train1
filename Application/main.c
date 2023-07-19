
#include "stdio.h"
#include "stdlib.h"
#include "list.h"
#include <string.h>
#include "GlobalDefine.h"
#include "/home/VsCode_Project/Train1/Application/Io/Lan.h"
#include "/home/VsCode_Project/Train1/Application/common/com.h"


int main()
{
        STLinkBook *pTemp = NULL;
        STLinkBook *phead =  CreatLink();
        STLinkBook *p1 = CreatLink();
        STLinkBook *p2 = CreatLink();
        STLinkBook *p3 = CreatLink();
        STLinkBook *p4 = CreatLink();
        phead->number = 1;
        phead->next = p1;
        p1->number = 2;
        p1->next = p2;
        p2->number = 3;
        char name[10] = "012345678";
        memcpy( p2->book.Title,name,10);
       
        p2->next = p3;
        p3->number = 4;
        p3->next = p4;
        p4->number = 5;
        p4->next = NULL;
       
       

        printf("hello world!123456!\n");
        printf("结构体STBook的大小：%d\n",sizeof(STBook)); 
        printf("链表STLinkBook的大小：%d\n",sizeof(STLinkBook)); 
        printf("int的大小：%d\n",sizeof(int)); 
        printf("指针的大小：%d\n",sizeof(STLinkBook *)); 
        printf("p1->book.Title的大小：%d,%d\n",sizeof(p1->book.Title),strlen(p1->book.Title)); 
        printf("p1->number的地址：%p\n",&(p1->number)); 
        printf("p1->book.Title的地址：%p\n",&(p1->book.Title)); 
        
        int Length =ListLength(phead);   // 统计链表长度   
        pTemp = Reserve(  phead); //反转链表
        STLinkBook *position = FindList(pTemp,name); //查找链表中符合限定条件的结点
        STLinkBook *pnew = FindNodeDelete(pTemp,4);//查找链表中符合限定条件的结点并删除该结点
        DeleteList(pTemp); // 删除整个链表
        Length =ListLength(pTemp); // 统计链表长度
        //system("pause");
        return 0;


}