#include <iostream>
#include <stack>
#include <cstdio>
#include <cstring>

using namespace std;

// 面试题1：赋值运算符函数
// 题目：如下为类型CMyString的声明，请为该类型添加赋值运算符函数。

class CMyString
{
public:
    CMyString(char* pData);
    CMyString(const CMyString& str);
    ~CMyString(void);
    CMyString& operator=(const CMyString& mystring);

    void Print();
      
private:
    char* m_pData;
};

CMyString::CMyString(char* pData)
{
    if(nullptr == pData)
    {
        m_pData = new char[1];
        m_pData[0] = '\0';
    }
    else
    {
        m_pData = new char[strlen(pData)+1];
        strcpy(m_pData, pData);
    }
    
}

CMyString::CMyString(const CMyString &str)
{
    m_pData = new char[strlen(str.m_pData)+1];
    strcpy(m_pData, str.m_pData);
}

CMyString::~CMyString(void)
{
    delete[] m_pData;
}

void CMyString::Print()
{
    printf("%s", m_pData);
}



class Single
{
private:
    Single(void)
    {

    }

    virtual ~Single(void)
    {

    }

    static Single* m_pInstance;
public:
    /** 单例模式 */
    static Single * GetInstance() 
    { 
        if(m_pInstance == nullptr)
            m_pInstance = new Single(); //c++11中static是线程安全的
        return m_pInstance; 
    }

    void test()
    {
        cout<<"Hello"<<endl;
    }


};

Single* Single::m_pInstance = nullptr;


// 面试题3（一）：找出数组中重复的数字
// 题目：在一个长度为n的数组里的所有数字都在0到n-1的范围内。数组中某些数字是重复的，但不知道有几个数字重复了，
// 也不知道每个数字重复了几次。请找出数组中任意一个重复的数字。例如，如果输入长度为7的数组{2, 3, 1, 0, 2, 5, 3}，
// 那么对应的输出是重复的数字2或者3。

bool duplicate(int numbers[], int length, int* duplication)
{
    if(nullptr == numbers || 0 == length || nullptr == duplication)
        return false;
    
    //异常保护
    for(int i= 0;i<length;i++)
    {
        if(numbers[i] > length -1 || numbers[i] < 0)
            return false;
    }

    for(int i = 0;i<length;i++)
    {
        while(numbers[i] != i)
        {
            if(numbers[i] == numbers[numbers[i]])
            {
                *duplication = numbers[i];
                return true;
            }
            int temp = numbers[i];
            numbers[i] = numbers[temp];
            numbers[temp] = temp;

        }
    }

    return false;

}

// 类二分查找
// 参数:
//        numbers:     一个整数数组
//        length:      数组的长度
// 返回值:             
//        正数  - 输入有效，并且数组中存在重复的数字，返回值为重复的数字
//        负数  - 输入无效，或者数组中没有重复的数字

int countRange(const int*numbers, int length, int start, int end)
{
    if(nullptr == numbers)
        return 0;
    
    int count = 0;

    for(int i = 0; i<length;i++)
    {
        if(numbers[i] >=start && numbers[i] <=end)
        {
            count++;
        }
    }

    return count;


}

int getDuplication2(const int* numbers, int length)
{
    if(nullptr == numbers || 0 == length)
        return -1;
    
    int start = 1; //原因是题目中给出起始为1，范围1-n
    int end = length -1; //数组长度n+1

    while(end >= start)
    {
        int mid = ((end - start) >>1) +start;
        int count = countRange(numbers, length, start, mid);

        if(end == start)
        {
            if(count > 1)
                return start;
            else
                break;
        }

        if(count > (mid - start + 1))
            end = mid;
        else
            start = mid+1;

    }

    return -1;

}


// 面试题4：二维数组中的查找
// 题目：在一个二维数组中，每一行都按照从左到右递增的顺序排序，每一列都按
// 照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个
// 整数，判断数组中是否含有该整数。


bool Find(int* matrix, int rows, int columns, int number)
{
    if(nullptr == matrix || rows <1 || columns <1) //未考虑单行单列类型
        return false;
    
    int row = 0;
    int col = columns - 1;
    while(row <rows && col >= 0)
    {
        if(matrix[row*columns + col] == number)
            return true;
        else if(matrix[row*columns + col] > number)
        {
            col--;
        }
        else
        {
            row++;
        }
    }

    return false;

}

// 面试题5：替换空格
// 题目：请实现一个函数，把字符串中的每个空格替换成"%20"。例如输入“We are happy.”，
// 则输出“We%20are%20happy.”。


/*length 为字符数组str的总容量，大于或等于字符串str的实际长度*/
void ReplaceBlank(char str[], int length)
{
    if(nullptr == str || length == 0)
        return;
    
    int len = 0;
    int blankLen = 0;
    while(str[len] != '\0')
    {
        
        if(str[len] == ' ')
        {
            blankLen++;
        }

        len++;
    }

    int newLen = len + 2*blankLen;

    if(newLen < len)
        return;

    while(len >=0 && newLen > len)
    {
        if(str[len] == ' ')
        {
            str[newLen--] = '0';
            str[newLen--] = '2';
            str[newLen--] = '%';
        }
        else
        {
            str[newLen--] = str[len];
        }

        len--;

    }


    return;
}



// 面试题6：从尾到头打印链表
// 题目：输入一个链表的头结点，从尾到头反过来打印出每个结点的值。

struct ListNode
{
    int       m_nValue;
    ListNode* m_pNext;
};
void PrintListReversingly_Recursively(ListNode* pHead)
{
    if(pHead != NULL)
    {
        if(NULL != pHead->m_pNext)
        {

            PrintListReversingly_Recursively(pHead->m_pNext);
        }

        printf("%d", pHead->m_nValue);
    }

    return;
}


void PrintListReversingly_Iteratively(ListNode* pHead)
{
    stack<int> res;
    while(pHead)
    {
        res.push(pHead->m_nValue);
        pHead = pHead->m_pNext;
    }

    while(!res.empty())
    {
        cout<<res.top()<<endl;
        res.pop();
    }
    return;
}

// 面试题7：重建二叉树
// 题目：输入某二叉树的前序遍历和中序遍历的结果，请重建出该二叉树。假设输
// 入的前序遍历和中序遍历的结果中都不含重复的数字。例如输入前序遍历序列{1,
// 2, 4, 7, 3, 5, 6, 8}和中序遍历序列{4, 7, 2, 1, 5, 3, 8, 6}，则重建出
// 图2.6所示的二叉树并输出它的头结点。
struct BinaryTreeNode 
{
    int                    m_nValue; 
    BinaryTreeNode*        m_pLeft;  
    BinaryTreeNode*        m_pRight; 
};
BinaryTreeNode *ConstructCore(int *startPre, int * endPre, int *startIn, int *endIn)
{
    int rootValue = startPre[0];
    BinaryTreeNode * dummyNode = new BinaryTreeNode();
    dummyNode->m_nValue = rootValue;
    dummyNode->m_pLeft = nullptr;
    dummyNode->m_pRight = nullptr;

    if(startPre == endPre)
    {
        if(startIn == endIn && *startPre == *startIn)
            return dummyNode;
        else
        {
            std::logic_error ex("Invalid Parameters");
            throw std::exception(ex);
        }
    }

    int *rootIn = startIn;
    while(rootIn <= endIn && *rootIn != rootValue)
    {
        ++rootIn;
    }

    if(rootIn == endIn && *rootIn != rootValue)
    {
        std::logic_error ex("Invalid Parameters");
        throw std::exception(ex);
    }
    int leftLength = rootIn - startIn;
    int* leftPreorderEnd = startPre + leftLength;
    if(leftLength > 0)
    {
        // 构建左子树
        dummyNode->m_pLeft = ConstructCore(startPre + 1, leftPreorderEnd,
                                           startIn, rootIn - 1);
    }
    if(leftLength < endPre - startPre)
    {
        // 构建右子树
        dummyNode->m_pRight = ConstructCore(leftPreorderEnd + 1, endPre,
                                       rootIn + 1, endIn);
    }

    return dummyNode;



}

BinaryTreeNode* Construct(int *preorder, int* inorder, int length)
{
    if(preorder == nullptr || inorder == nullptr || length <=0)
        return nullptr ;

    return ConstructCore(preorder, preorder + length - 1,
                         inorder, inorder + length - 1);

}

// 面试题8：二叉树的下一个结点
// 题目：给定一棵二叉树和其中的一个结点，如何找出中序遍历顺序的下一个结点？
// 树中的结点除了有两个分别指向左右子结点的指针以外，还有一个指向父结点的指针。

// 面试题9：用两个栈实现队列
// 题目：用两个栈实现一个队列。队列的声明如下，请实现它的两个函数appendTail
// 和deleteHead，分别完成在队列尾部插入结点和在队列头部删除结点的功能。

template <typename T> class CQueue
{
public:
    CQueue(void)
    {
        stack1.clear();
        stack2.clear();
    };
    ~CQueue(void)    
    {
        stack1.clear();
        stack2.clear();
    };
    // 在队列末尾添加一个结点
    void appendTail(const T& node)
    {
        stack1.push(nodes);
    };

    // 删除队列的头结点
    T deleteHead()
    {
        if(stack2.empty())
        {
            while(!stack1.empty())
            {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }

        T head = stack2.top();
        stack2.pop();
        return head;
        
    };

private:
    stack<T> stack1;
    stack<T> stack2;
};

// 面试题10：斐波那契数列
// 题目：写一个函数，输入n，求斐波那契（Fibonacci）数列的第n项。


long long Fibonacci_Solution1(unsigned int n)
{
    long long  res[3] = {0};
    res[0] = 0;
    res[1] = 1;
    res[2] = 1;
    if(n < 3)
        return res[n];
    for(unsigned int i =3; i<n+1;i++)
    {
        res[0] = res[2];
        res[2] = res[2] + res[1];
        res[1] = res[0];

    }

    return res[2];

}

int main(int argc, char* argv[])
{

    return 0;
}