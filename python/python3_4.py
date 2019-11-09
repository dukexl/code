# -*- coding: utf-8 -*-
"""
Created on Sun Aug 25 20:03:56 2019

@author: Administrator
"""

"""
if 判断条件：
    执行语句……
else：
    执行语句……
"""

flag = False
name = 'luren'
if name == 'python':         # 判断变量否为'python'
    flag = True          # 条件成立时设置标志为真
    print('welcome boss')    # 并输出欢迎信息
else:
    print(name)              # 条件不成立时输出变量名称
    
    
    
num = 5     
if num == 3:            # 判断num的值
    print('boss')        
elif num == 2:
    print('user')
elif num == 1:
    print('worker')
elif num < 0:           # 值小于零时输出
    print('error')
else:
    print('roadman')     # 条件均不成立时输出
    
    

from pandas import Series;
from pandas import DataFrame;

for i in range(10):
    print('现在是： ', i)

for i in range(3, 10):
    print(i)

#遍历字符串
for letter in 'Python':
   print ('现在是 :', letter)

#遍历数组
fruits = ['banana', 'apple',  'mango']

for fruit in fruits:
   print ('现在是 :', fruit)

#遍历序列
x = Series(['a', True, 1], index=['first', 'second', 'third']);
print(x[0]);
print(x['second']);
print(x[2]);

for v in x:
    print("x中的值 ：", v);
    
for index in x.index:
    print("x中的索引 :", index);
    print("x中的值 :", x[index]);
    print("---------------------")

#遍历数据框
df = DataFrame({
    'age': Series([21, 22, 23]), 
    'name': Series(['KEN', 'John', 'JIMI'])
});

#遍历列名
for r in df:
    print(r);
    
#遍历列
for cName in df:
    print('df中的列 ：\n', cName)
    print('df中的值 ：\n', df[cName]);
    print("---------------------")

#遍历行，方法一
for rIndex in df.index:
    print('现在是第 ', rIndex, ' 行')
    print(df.irow(rIndex))

#遍历行，方法二
for r in df.values:
    print(r)
    print(r[0])
    print(r[1])
    print("---------------------")

#遍历行，方法三
for index, row in df.iterrows():
    print('第 ', index, ' 行：')
    print(row)
    print("---------------------")
    
    
    # -*- coding: utf-8 -*-
"""
Created on Sat Sep 26 20:45:51 2015

@author: TBKKEN
"""
from pandas import Series;
from pandas import DataFrame;

#最普通的while循环
i = 0
while i <= 9:
   print('遍历到 :', i);
   i = i+1;

#整合if判断语句，使用continue
i = 1
while i < 10:   
    i += 1              # i = i + 1
    if i%2 != 0:         # 非双数时跳过输出
        continue
    print(i)            # 输出双数2、4、6、8、10

#整合if判断语句，使用break
i = 1
while True:             # 循环条件为1必定成立
    print(i)            # 输出1~10
    i += 1
    if i > 10:          # 当i大于10时跳出循环
        break

#当然，我们也可以使用while语句来访问DataFrame等数据结构
df = DataFrame({
    'age': Series([21, 22, 23]), 
    'name': Series(['KEN', 'John', 'JIMI'])
});

rowCount = len(df);

i = 0;

while i<rowCount:
    print(df.irow(i));
    i = i+1;
    print("-------------------------")

