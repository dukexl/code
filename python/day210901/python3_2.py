# -*- coding: utf-8 -*-
"""
Created on Sun Aug 25 19:38:32 2019

@author: Administrator
"""

#列表中，可以有不同的数据类型，以及相同的值
a = ['him', 25, 100, 'her', 100, 25]
print(a)

#和字符串一样，列表同样可以被索引和切片，
#列表被切片后返回一个包含所需元素的新列表
a[1:3]

#列表还支持串联操作，使用+操作符
a = [1, 2, 3, 4, 5]
a + [6, 7, 8]
#[1, 2, 3, 4, 5, 6, 7, 8]

#列表中的元素是可以改变的：
a = [1, 2, 3, 4, 5, 6]
a[0] = 9
a[2:5] = [13, 14, 15]
a
#[9, 2, 13, 14, 15, 6]
a[2:5] = []   # 删除
a
#[9, 2, 6]

#判断值是否存在列表中
25 in a

2 in a

#判断多个值，那么就要用到set
print(a)
print(set([2, 100]) <= set(a))
print(set([2,6]) <= set(a))

# 元祖 tuple
a = (1991, 2014, 'physics', 'math')
print(a, type(a), len(a))
#(1991, 2014, 'physics', 'math') <class 'tuple'> 4
#元组与字符串类似，可以被索引且下标索引从0开始，
#也可以进行截取/切片

#其实，可以把字符串看作一种特殊的元组。
tup = (1, 2, 3, 4, 5, 6)
print(tup[0], tup[1:5])
#1 (2, 3, 4, 5)
#tup[0] = 11  # 修改元组元素的操作是非法的

#虽然tuple的元素不可改变，但它可以包含可变的对象，比如list列表。
#构造包含0个或1个元素的tuple是个特殊的问题，所以有一些额外的语法规则：
tup1 = () # 空元组
tup2 = (20,)
tup2 = (20)

#另外，元组也支持用+操作符：
tup1, tup2 = (1, 2, 3), (4, 5, 6)

print(tup1+tup2)
#(1, 2, 3, 4, 5, 6)

# 集合 set
student = {'Tom', 'Jim', 'Mary', 'Tom', 'Jack', 'Rose'}
print(student)   # 重复的元素被自动去掉
#{'Jim', 'Jack', 'Mary', 'Tom', 'Rose'}

'Rose' in student  # membership testing（成员测试）
#True

'KEN' in student  # membership testing（成员测试）

# set可以进行集合运算
a = set('abracadabra')
b = set('alacazam')
print(a)
print(b)
#{'a', 'b', 'c', 'd', 'r'}
print(a - b)     # a和b的差集
#{'b', 'd', 'r'}
a | b     # a和b的并集
#{'l', 'm', 'a', 'b', 'c', 'd', 'z', 'r'}
a & b     # a和b的交集
#{'a', 'c'}
a ^ b     # a和b中不同时存在的元素
#{'l', 'm', 'b', 'd', 'z', 'r'}

a = ['him', 25, 100, 'her', 100, 25]

#判断多个值，那么就要用到set
print(set([25, 100]) <= set(a))



# 字典 dic
dic = {}  # 创建空字典
tel = {'Jack':1557, 'Tom':1320, 'Rose':1886}
print(tel)
#{'Tom': 1320, 'Jack': 1557, 'Rose': 1886}

print(tel['Jack'])   # 主要的操作：通过key查询
#1557

del tel['Rose']  # 删除一个键值对
tel

tel['Mary'] = 4127  # 添加一个键值对
tel
#{'Tom': 1320, 'Jack': 1557, 'Mary': 4127}

list(tel.keys())  # 返回所有key组成的list
#['Tom', 'Jack', 'Mary']

sorted(tel.keys()) # 按key排序
#['Jack', 'Mary', 'Tom']

'Tom' in tel       # 成员测试
#True

'Mary' not in tel  # 成员测试
#False

'KEN' in tel

#构造函数 dict() 直接从键值对sequence中构建字典，当然也可以进行推导，如下：
dict([('sape', 4139), ('guido', 4127), ('jack', 4098)])
#{'jack': 4098, 'sape': 4139, 'guido': 4127}

dict(sape=4139, guido=4127, jack=4098)
#{'jack': 4098, 'sape': 4139, 'guido': 4127}

