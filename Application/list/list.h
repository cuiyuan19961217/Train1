

// 变量声明
// 测试链表
typedef struct list
{
    /* data */
    int  number;
    struct list *next;   
    
} List;
// 结构体：一本书的概述
typedef struct book{
        
        char Title[10];  // 书名
        char Writer[12];  // 作者 
        char Kind[10];  // 分类
        int  PageNum;  // 页数

}  STBook;
// 链表
 typedef struct booklink{

    int number;
    STBook book;  // 数据
    struct booklink *next; // 指针

} STLinkBook;

//  函数声明
/* 描述：创建链表
     输入：
     输出：
     返回值：指针，指向STLinkBook数据类型
*/
STLinkBook *CreatLink();
/* 描述：反转链表
     输入：
     输出：
     返回值：
*/
STLinkBook *Reserve(STLinkBook *phead);
/* 描述：反转链表的指定区域
     输入：
     输出：
     返回值：
*/
STLinkBook *ReserveDomain(STLinkBook *phead,int m,int n);

/* 描述：单链表删除
     输入：
     输出：
     返回值：
*/
void DeleteList(STLinkBook *phead);

/* 描述：计算表长度
     输入：头结点
     输出：
     返回值：int 长度
*/
int  ListLength(STLinkBook *phead);


/* 描述：从链表中查找相应的结点
     输入：STLinkBook *phead：头结点，char *name：限定条件（书名）
     输出：
     返回值：结点地址
*/
STLinkBook  *FindList(STLinkBook *phead,char *name);

/* 描述：从链表中查找相应的结点并删除
     输入：STLinkBook *phead：头结点，char *name：限定条件（次序）
     输出：
     返回值：头结点地址
*/
STLinkBook  *FindNodeDelete(STLinkBook *phead,int num);