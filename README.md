# 数据结构与算法

## 看郝斌老师的视频,代码和笔记的整理

### 数据结构与算法


#### 概述
##### 定义：

    我们如何把现实中大量而复杂的问题以特定的数据类型和特定的存储结构保存到主存储器（内存）中，在此基础上为实现某个功能（比如查找某个元素，删除某个元素，对某个元素进行排序）而执行的相应的操作，这个相应的操作也叫算法。

    专门研究数据存储的问题

    数据结构 = 个体的存储 + 个体的关系的存储
    
    算法 = 对数据存储的操作

##### 算法：
    解题的方法和步骤

    衡量算法的标准
         时间复杂度：大概程序要执行的次数，而非执行时间
         空间复杂度：算法执行过程中大概所占用的最大内存
         难易程度
         健壮性

##### 地位：
    数据结构是软件中最核心的课程。
    程序 = 数据的存储 + 数据的操作 + 可以被计算机执行的语言

#### 预备知识
    指针
        指针的重要性：
            指针是C语言的灵魂
        定义
             地址
                内存单元的编号
                从0开始的非负整数
                范围： 0 -- FFFFFFFF（0 -- 4G-1）
             指针
                指针就是地址，地址就是指针。
                指针变量：存放‘内存单元地址‘的变量。
                指针的本质：一个操作受限的非负整数。
             分类
                 基本类型指针

                 指针和数组的关系
    结构体
         为什么会出现结构体
             为了表示一些复杂的数据，而普通的基本类型变量无法满足要求
         什么叫结构体
             结构体是用户根据实际需要，自己定义的复合数据类型
         如何使用结构体
             两种方式
                 struct Student st = {10,"张三",18;
                 struct Student *pst = &st;
                 第一种方式：    st.id = 10;
                 第二种方式：    pst->id = 10;
                               pst所指向结构体变量中的sid这个成员
         注意事项
             结构体变量不能加减乘除，但能相互赋值
             普通结构体变量和结构体指针作为函数传参的问题
        动态内存的分配与释放

#### 线性结构
##### 概述：
    把所有的节点，用一根直线穿起来

##### 连续存储【数组】
     什么叫数组
         元素类型相同，大小相等
             数组的优缺点
##### 离散存储【链表】
    定义：
         n个节点离散分配
         彼此通过指针相连
         每个节点只有一个前驱节点，每个节点只有一个后续节点
         首节点没有前驱节点，尾节点没有后续节点
         专业术语：
             首节点：
                 第一个有效的节点
             尾节点：
                 最后一个有效的节点
             头结点：
                 头结点的数据类型和首节点类型相同
                 第一个有效节点之前的那个节点
                 头结点并不存放有效数据
                 加头结点的目的是方便对链表的操作
             头指针
                 指向头结点的指针变量
             尾指针
                 指向尾节点的指针变量
         如果希望通过一个函数来对链表进行处理，我们至少需要接收链表的哪些参数：
             只需要一个参数：头指针
             因为我们通过头指针可以推算出链表的其他所有信息
    分类：
         单链表
             每一个节点只有一个指针域，且指向后一个节点
         双链表
             每一个节点有两个指针域
         循环链表
             能通过任何一个节点能找到其他所有节点（尾节点指向头结点）
         非循环链表
    算法：
         遍历
         查找
         清空
         销毁
         求长度
         排序
         插入节点
         删除节点
         算法：
             狭义的算法是与数据的存储方式密切相关
             广义的算法是与数据的存储方式无关
             泛型：
                 利用某种技术达到的效果就是：不同的存储方式，执行的操作是一样的
    链表的优缺点：

##### 线性结构的两种常见应用之一        栈
     定义：
         一种可以实现“先进后出”数据存储结构
         栈类似于箱子
     分类：
         静态栈
         动态栈
     算法：
         出栈
         压栈
     应用：
         函数调用
         中断
         表达式求值
         内存分配
         缓冲处理
         迷宫
##### 线性结构的两种常见应用之二        队列
     定义：
         一种可以实现“先进先出”的存储结构
     分类：
         链式队列 -- 用链表实现
         
         静态队列 -- 用数组实现
             静态队列通常必须是循环队列
             循环队列的讲解：
                 1.静态队列为什么必须是循环队列
                 2.循环队列需要几个参数来确定，及其含义
                     需要两个参数来确定
                         front
                         rear
                         
                 3.循环队列各个参数的含义
                     2个参数在不同的场合有不同的含义
                         front
                         rear
                     建议初学者先记住，然后慢慢体会
                         队列初始化
                             front和real的值都为空
                         队列非空
                             front代表的是队列的第一个元素
                             rear代表的是队列最后一个元素的下一个元素
                         队列空
                             front和rear的值相等，但不一定是0
                             
                 4.循环队列入队伪算法讲解
                     将值存入rear所代表的位置
                     rear = (rear + 1) % 数组的长度
                     
                 5.循环队列出队伪算法讲解
                     front = (front + 1) % 数组的长度
                 
                 6.如何判断循环队列为空
                     front = rear时为空
                     
                 7.如何判断循环队列已满
                    预备知识:
                        front的值可能比rear大
                        front的值可能比rear小
                        front的值可能跟rear相等
                    两种方式
                        1.多增加一个标识参数(一般不使用)
                        2.少用数组中的一个元素
                          如果(front = (rear + 1) % 数组的长度),则队列已满,反之则不满
            队列算法:
                入队
                出队
            队列的具体应用:
                所有和时间有关的操作都有队列的影子
                          

##### 专题：递归
    定义:
        一个函数自己直接或间接调用自己 
    递归满足的3个条件
        1.递归必须得有一个明确的终止条件
        2.该函数处理的数据规模必须在递减
        3.这个转化必须是可解的
    循环和递归
        递归:
            易于理解
            速度慢
            存储空间大
        循环:
            不易理解
            速度快
            存储空间小
    举例:
        a. 求阶乘
        b. 1+2+3+4+……+100的和
        c. 汉诺塔
            伪算法
            if(n > 1){
                把A柱子上的n-1个盘子从A借助C移动到B
                把A柱子上的第n个盘子移动到C
                再将B柱上的n-1个盘子借助A移动到C
            }
        d. 走迷宫
    递归的应用:
        树和森林就是以递归的方式定义的
        树和图的大多数算法都是以递归来实现的
        很多数学公式都是以递归方式定义的
            斐波拉契序列:
                1 2 3 5 8 13 21 34...

#### 非线性结构

##### 树(tree)
    定义
        专业定义:
            1.有且只有1个称为根的节点
            2.有若干个互不相交的子树,这些子树本身也是一颗树
        通俗定义:
            1.树是由节点和边组成
            2.每个节点只有一个父节点,但可以有多个子节点
            3.但又一个节点例外,该节点没有父节点,此节点称为根节点
        专业术语:
            节点  父节点 子节点 
            子孙  堂兄弟
            深度:
                从根节点到最底层节点的'层数'称之为深度
                根节点是第一层
            叶子节点:
                没有子节点的节点
            非终端节点:
                实际就是非叶子节点
            度:
                子节点的个数称为度
    分类
        一般树
            任意一个节点的子节点的个数都不受限制
        二叉树
            任意一个节点的子节点的个数最多两个
            且子节点的位置不可更改,左边的子节点称为左子树,右边的子节点称为右子树,左子树和右子树顺序不能改变
            分类:
                一般二叉树
                满二叉树
                    在不增加树的层数的前提下,无法再多添加一个节点的二叉树就是满二叉树
                完全二叉树
                    如果只是删除了满二叉树'最底层,最右边'的n个节点,这样形成的二叉树就是完全二叉树
                    当n == 0时,就是满二叉树
        森林
            n个互不相交的树的集合
    存储
        二叉树的存储
            连续存储[完全二叉树]
                优点:
                    查找某个父节点和子节点(也包括判断有没有子节点)的速度很快
                缺点:
                    内存空间浪费比较多(一般二叉树先架构成完全二叉树,很多节点存储的值都是垃圾值)
            链式存储
            
        一般树的存储
            双亲表示法
                求父节点方便
            孩子表示法
                求子节点方便
            双亲孩子表示法
                求父节点和子节点都很方便
            二叉树表示法(也叫孩子兄弟链表表示法)
                把一个普通树转换成二叉树来存储
                具体转换方法:
                    设法保证任意一个节点的
                        左指针域指向它的第一个孩子节点
                        右指针域指向它的下一个兄弟节点
                    只要能满足此条件,就可以把一个普通树转化为二叉树
                    一个普通树转换成的二叉树一定没有右子树
                    
        森林的存储
            先把森林转换成二叉树,再存储二叉树
    操作(二叉树)
        遍历
            先序遍历[先访问根节点]
                先访问根节点
                再先序访问左子树
                再先序访问右子树
            中序遍历[中间访问根节点]
                中序遍历左子树
                再访问根节点
                中序遍历右子树
            后序遍历[最后访问根节点]
                后序遍历左子树
                后序遍历右子树
                再访问根节点
        已知两种遍历序列求原始二叉树
            通过先序和中序 或者 中序和后序 我们可以还原出原始的二叉树
            但是通过先序和后序是无法还原出原始的二叉树
            
            换种说法
                只有通过先序和中序,或通过中序和后序
                我们才可以唯一的确定一个二叉树
    应用

##### 图(graph)


#### 查找和排序

##### 折半查找
##### 排序
     冒泡排序
     插入排序
     选择排序
     快速排序
     归并排序


















