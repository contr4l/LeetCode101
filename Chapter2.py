import sys
sys.setrecursionlimit(100)

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

# 对列表本身进行操作的归并排序
def Merge_S(lst,p,q,r):
    L = lst[p:q+1]+[10000]
    R = lst[q+1:r+1]+[10000]
    i = j = 0
    for k in range(p,r+1):
        if L[i]<=R[j]:
            lst[k]=L[i]
            i += 1
        else:
            lst[k]=R[j]
            j += 1

def MergeSort_S(lst,p,r):
    if p<r:
        q = (p+r) // 2
        MergeSort_S(lst,p,q)
        MergeSort_S(lst,q+1,r)
        Merge_S(lst,p,q,r)
    return lst

"""
Ex. 2.3-2 重写Merge_S，不使用哨兵
"""
def Merge_S2(lst,p,q,r):
    L = lst[p:q+1]
    R = lst[q+1:r+1]
    i = j = 0
    k = p
    while i<q+1-p and j<r-q:
        if L[i]<=R[j]:
            lst[k]=L[i]
            i += 1
        else:
            lst[k]=R[j]
            j += 1
        k += 1
    if i == q+1-p:
        lst[k:r+1] = R[j:]
    else:
        lst[k:r+1] = L[i:]

"""
*Ex. 2.3-7 描述一个O(nlgn)的算法，给定集合S和整数x，确定S中是否有两个数之和为x
"""
# 先构造一个二分查找的函数
def BinarySearch(sorted_list,x):
    lw = 0
    hg = len(sorted_list)-1
    while lw<hg-1:
        mid = (lw + hg) // 2
        if sorted_list[lw] == x: return lw
        if sorted_list[mid] == x: return mid
        if sorted_list[hg] == x: return hg
        if sorted_list[mid] < x:
            lw = mid
        else:
            hg = mid
    return -1

def SearchSum(S,x):
    MergeSort_S(S,0,len(S)-1)
    for pos,i in enumerate(S):
        if BinarySearch(S,x-i) not in (pos,-1):
            return True
    return False

"""
Ex. 2-2 冒泡排序
"""
def BubbleSort(lst):
    k = 0
    while k < len(lst)-1:
        i = 0
        while i < len(lst)-k-1:
            if lst[i]>lst[i+1]:
                lst[i],lst[i+1] = lst[i+1],lst[i]
            i += 1
        k += 1
        print(lst)
    return lst

"""
Ex. 2-4 逆序对数量
"""
def InversionNum(lst):



print(BubbleSort([9,8,7,6,5,4,3,2,1]))