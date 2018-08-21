# DataStructure

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
        ○ 时间复杂度：大概程序要执行的次数，而非执行时间
        ○ 空间复杂度：算法执行过程中大概所占用的最大内存
        ○ 难易程度
        ○ 健壮性

##### 地位：
    数据结构是软件中最核心的课程。
    程序 = 数据的存储 + 数据的操作 + 可以被计算机执行的语言

#### 预备知识
    指针
        指针的重要性：
            指针是C语言的灵魂
        定义
            ○ 地址
                内存单元的编号
                从0开始的非负整数
                范围： 0 -- FFFFFFFF（0 -- 4G-1）
            ○ 指针
                指针就是地址，地址就是指针。
                指针变量：存放‘内存单元地址‘的变量。
                指针的本质：一个操作受限的非负整数。
            ○ 分类
                § 基本类型指针

                § 指针和数组的关系
    结构体
        • 为什么会出现结构体
            ○ 为了表示一些复杂的数据，而普通的基本类型变量无法满足要求
        • 什么叫结构体
            ○ 结构体是用户根据实际需要，自己定义的复合数据类型
        • 如何使用结构体
            ○ 两种方式
                struct Student st = {10,"张三",18};
                struct Student *pst = &st;
                § 第一种方式：    st.id = 10;
                § 第二种方式：    pst->id = 10;
                                pst所指向结构体变量中的sid这个成员
        • 注意事项
            ○ 结构体变量不能加减乘除，但能相互赋值
            ○ 普通结构体变量和结构体指针作为函数传参的问题
        动态内存的分配与释放

#### 线性结构
##### 概述：
    把所有的节点，用一根直线穿起来

##### 连续存储【数组】
    • 什么叫数组
        ○ 元素类型相同，大小相等
            • 数组的优缺点
##### 离散存储【链表】
##### 线性结构的两种常见应用之一        栈
    • 定义：
        ○ 一种可以实现“先进后出”数据存储结构
        ○ 栈类似于箱子
    • 分类：
        ○ 静态栈
        ○ 动态栈
    • 算法：
        ○ 出栈
        ○ 压栈
    • 应用：
        ○ 函数调用
        ○ 中断
        ○ 表达式求值
        ○ 内存分配
        ○ 缓冲处理
        ○ 迷宫
##### 线性结构的两种常见应用之二        队列
    • 定义：
        ○ 一种可以实现“先进先出”的存储结构
    • 分类：
        ○ 链式队列 -- 用链表实现
        ○ 静态队列 -- 用数组实现
            § 静态队列通常必须是循环队列
            § 循环队列的讲解：
                □ 1.静态队列为什么必须是循环队列
                □ 2.循环队列需要几个参数来确定，及其含义
                    ® 需要两个参数来确定
                        ◊ front
                        ◊ rear
                □ 3.循环队列各个参数的含义
                    ® 2个参数在不同的场合有不同的含义
                        ◊ front
                        ◊ rear
                    ® 建议初学者先记住，然后慢慢体会
                        ◊ 队列初始化
                            } front和real的值都为空
                        ◊ 队列非空
                            } front代表的是队列的第一个元素
                            } rear代表的是队列最后一个元素的下一个元素
                        ◊ 队列空
                            } front和rear的值相等，但不一定是0
                □ 4.循环队列入队伪算法讲解
                    ® 将值存入rear所代表的位置
                    ® rear = (rear + 1) % 数组的长度
                □ 5.循环队列出队伪算法讲解
                    ® front = (front + 1) % 数组的长度
                □ 6.如何判断循环队列为空
                    ® front = rear时为空
                □ 7.如何判断循环队列已满

##### 专题：递归
    a. 1+2+3+4+……+100的和
    b. 求介乘
    c. 汉诺塔
    d. 走迷宫



















