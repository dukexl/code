# -*- coding: utf-8 -*-
"""
Created on Sun Aug 25 19:51:00 2019

@author: Administrator
"""

from pandas import Series;

#定义，可以混合定义
x = Series(['a', True, 1], index=['first', 'second', 'third'])
x = Series(['a', True, 1]);

#访问
print(x[1]);

#根据index访问
#x['first']  ????

#不能越界访问
x[2]
"""
#不能追加单个元素
x.append('2')
#追加一个序列
n = Series(['2'])
x.append(n)

#需要使用一个变量来承载变化
x = x.append(n)

'2' in x

#判断值是否存在
'2' in x.values

#切片
x[1:3]

#定位获取，这个方法经常用于随机抽样
x[[0, 2, 1]]

#根据index删除
x.drop(0)
x.drop('first')

#根据位置删除
x.drop(x.index[3])

#根据值删除
x['2'!=x.values]

"""

from pandas import DataFrame;

df = DataFrame({
    'age': [21, 22, 23], 
    'name': ['KEN', 'John', 'JIMI']
});

df = DataFrame(data={
    'age': [21, 22, 23], 
    'name': ['KEN', 'John', 'JIMI']
}, index=['first', 'second', 'third']);

df


#按列访问
print(df['age'])
#按行访问
df[1:2]
"""
#按行列号访问
df.iloc[0:1, 0:1] 

#按行索引，列名访问
df.at[0, 'name']

#修改列名
df.columns
df.columns=['age2', 'name2']

#修改行索引
df.index
df.index = range(1,4)
df.index

#根据行索引删除
df.drop(1, axis=0)
#默认参数axis=0
#根据列名进行删除
df.drop('age2', axis=1)

#第二种删除列的方法
del df['age2']

#增加行，注意，这种方法，效率非常低，不应该用于遍历中
df.loc[len(df)] = [24, "KENKEN"];

#增加列
df['newColumn'] = [2, 4, 6, 8];


"""