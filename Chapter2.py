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
        return lst
    for j in range(1,len(lst)):
        key = lst[j]
        j -= 1
        while j >=0 and lst[j] > key:
            lst[j+1] = lst[j]
            j -= 1
        lst[j+1] = key
    return lst


# print(InsertionSort2([5,4,3,2,1]))

