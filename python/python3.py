# -*- coding: utf-8 -*-
"""
Created on Wed Aug 21 22:19:27 2019

@author: Administrator
"""
# print 3.1
x = 1;
y = 2;

z = x > y;

t = True;
f = False;
print (x)
print (y)
print (z)
print (t)
print (f)

print (True & True)
print (True & False)
print (False & False)

print (True | True)
print (True | False)
print (False | False)


print (not True)
print (not False)
print ('\n')
# print 3.2

x = 1;
y = 2;

print(x + y)
print(x - y)
print (x * y)
print(x / y)

#取整
print(7 // 4)
#求余
print(10 % 4)

#乘方
print(2 ** 3)

#一个关于浮点数运算需要注意的地方
a = 4.2
b = 2.1
print(a + b)

print ((a + b) == 6.3) # 需要将6.3转换为Decimal

from decimal import Decimal
a = Decimal('4.2')
b = Decimal('2.1')
a + b

print(a + b)

print ((a + b) == Decimal('6.3'))


x = '我是一个字符串';
y = "我也是一个字符串";

print (x)
print (y)
#字符串str用单引号(' ')或双引号(" ")括起来

#使用反斜杠(\)转义特殊字符。
# =============================================================================
s = 'Yes,he doesn\'t'
print(s, type(s), len(s))
# 
# #如果你不想让反斜杠发生转义，
# #可以在字符串前面添加一个r，表示原始字符串
print('C:\some\name')
# 
print(r'C:\some\name')
# 
# #反斜杠可以作为续行符，表示下一行是上一行的延续。
# #还可以使用"""..."""或者'''...'''跨越多行
s1 = "abcd\
efg"
print(s1);
# 
s = """
Hello I am fine!
Thinks.
"""
print(s);
# 
# #字符串可以使用 + 运算符串连接在一起，或者用 * 运算符重复：
print('str'+'ing', 'my'*3)
# 
# #Python中的字符串有两种索引方式
# #第一种是从左往右，从0开始依次增加
# #第二种是从右往左，从-1开始依次减少
# #注意，没有单独的字符类型，一个字符就是长度为1的字符串
word = 'Python'
print(word[0], word[5])
print(word[-1], word[-6])
# 
# #还可以对字符串进行切片，获取一段子串
# #用冒号分隔两个索引，形式为变量[头下标:尾下标]
# #截取的范围是前闭后开的，并且两个索引都可以省略
word = 'ilovepython'
print(word[1:5])  #'love'
print(word[:])  #'ilovepython'
print(word[5:])  #'python'
print(word[-10:-6]) #'love'

# #Python字符串不能被改变
# #向一个索引位置赋值，比如word[0] = 'm'会导致错误。
# word[0] = 'm'
# 
# 
# #检测开头和结尾
filename = 'spam.txt'
print(filename.endswith('.txt'))
 
print(filename.startswith('file:'))
 
url = 'http://www.python.org'
print(url.startswith('http:'))
 
choices = ('http:', 'https')
url = 'https://www.python.org'
print(url.startswith(choices[0]))
 
choices = ['http:', 'https']
url = 'https://www.python.org'
print(url.startswith(choices[1]))
 
 
 #查找某个字符串
string = "I am KEN"
print(string.find("am"))
print(string.find("boy"))
 #忽略大小写的搜索
 
import re
text = 'UPPER PYTHON, lower python, Mixed Python'
print(re.findall('python', text, flags=re.IGNORECASE))
 
 #搜索和替换
text = 'yeah, but no, but yeah, but no, but yeah'
print(text.replace('yeah', 'yep'))
 
 #忽略大小写的替换
text = 'UPPER PYTHON, lower python, Mixed Python'
print(re.sub('python', 'snake', text, flags=re.IGNORECASE))
 
 #合并拼接字符串
parts = ['Is', 'Chicago', 'Not', 'Chicago?']
print(' '.join(parts))
#'Is Chicago Not Chicago?'
print(','.join(parts))
#'Is,Chicago,Not,Chicago?'
print(''.join(parts))
#'IsChicagoNotChicago?'
print (parts)
# =============================================================================

#接下来几节课中，我们还会有一些常用的字符串使用方法