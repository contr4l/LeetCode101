"""
2.1 插入排序
    存在序列（a1,a2,a3...,an），每次取出一个数插入新序列并维护正确顺序,时间复杂度O(n^2)。
"""
def InsertionSort1(lst):
    # 创建新列表的方式
    new_lst = []
    for i in lst:
        if not len(new_lst):
            new_lst.append(i)
        else:
            for j in range(0,len(new_lst)):
                if new_lst[j] > i:
                    new_lst.insert(j,i)
                    j = 0
                    break
            if j != 0:
                new_lst.append(i)
    return new_lst

def InsertionSort2(lst):
    # 操作原列表的方式,循环不变式为维持lst[0:j]是一个已排序的列表
    if len(lst) == 1:
        return
    for j in range(1,len(lst)):
        key = lst[j]
        j -= 1
        while j >=0 and lst[j] > key:
            lst[j+1] = lst[j]
            j -= 1
        lst[j+1] = key
    return lst

"""
Ex. 2.1-2 Rewrite the InsertionSort, make list have an descending order.
"""
def InsertionSort_up(lst):
    if len(lst) == 1:
        return lst
    for j in range(1,len(lst)):
        key = lst[j]
        j -= 1
        while j >=0 and lst[j] < key:
            lst[j+1] = lst[j]
            j -= 1
        lst[j+1] = key
    return lst

"""
Ex. 2.1-3 Linear Search problem
Input: list(a1,a2,...,an), constant v
output: index i s.t. list[i]==v or v = NIL while i not existed.
"""
def LinearSearch(lst, v):
    for i in range(0,len(lst)):
        if lst[i] == v:
            return i
    return 'NIL'

"""
Ex. 2.1-4 Binary integer sum
Input: n-bit integer A and n-bit integer B
Output: (n+1)-bit integer C
"""
def BinarySum(A, B):
    k = 0 # 进位标识
    res = ''
    while A != 0 or B != 0:
        i = A%10
        j = B%10
        tail = i+j+k
        res = str(tail%2) + res
        k = int(tail>=2)
        A,B = A//10,B//10
    return int(res)

"""
Ex. 2.2-2 选择算法：对list(a1,a2,...,an)，找出最小的数，放在A[0]，再找出次小的数，放在A[2]...
"""
def ChoosenSort(lst):
    j = 0
    while j != len(lst)-1:
        key = lst[j]
        pos = j
        for i in range(j,len(lst)):
            print(i)
            if lst[i] < key:
                key = lst[i]
                pos = i
        lst[pos],lst[j] = lst[j],lst[pos]
        j += 1
    return lst

"""
2.3 分治法——分解、解决、合并
归并排序
    分解：分解待排序的列表为各包含N/2元素的子列表
    解决：使用归并排序递归排序子列
    合并：合并两个已排序的子列
"""
def MergeSort(lst):
    if len(lst) == 1:
        return lst
    else:
        n = len(lst)//2
        lst1 = MergeSort(lst[0:n])
        lst2 = MergeSort(lst[n:len(lst)])
        return Merge(lst1,lst2)

def Merge(lst1,lst2):
    i = 0
    j = 0
    res = []
    while i < len(lst1) and j < len(lst2):
        if lst1[i] <= lst2[j]:
            res.append(lst1[i])
            i += 1
        else:
            res.append(lst2[j])
            j += 1
    res += lst1[i:]
    res += lst2[j:]
    return res

# 上述归并排序在Merge函数中引入了新列表res，将多占用N的内存，下为对自身列表进行操作的函数MergeSort()
# 由于是对列表本身的操作，甚至不需要return，类似于sort()
def MergeSort_S(lst,p,q):
    if p<q:
        r = (p+q)//2
        MergeSort_S(lst,p,r)
        MergeSort_S(lst,r,q)
        Merge_S(lst,p,q,r)

def Merge_S(lst,p,q,r):

print(MergeSort([9,8,7,5,4,3,2,1,0]))

