# -*- coding: utf-8 -*-
"""
Created on Wed Aug 21 14:19:42 2019

@author: Administrator
"""

def binary_search(list,item):
    low = 0
    high = len(list)-1
    
    while low<= high:
        mid = int( (low+high) / 2)
        guess = list[mid]
        if guess == item:
            return mid
        if guess>item:
            high=mid-1
        else:
            low = mid+1
            
    return None



if __name__=='__main__':
    my_list =[1,3,5,7,9]
    ret = binary_search(my_list,3)
    print (my_list)
    print ("ret:%s" % ret)
    ret1 = binary_search(my_list,-1)
    print ("ret1:%s" % ret1)