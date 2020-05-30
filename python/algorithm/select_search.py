# -*- coding: utf-8 -*-
"""
Created on Thu Aug 22 09:50:10 2019

@author: Administrator
"""

#mylist=[5,3,6,2,10]
#print(mylist)
#print(range(len(mylist)))


# 1 min  2 select
def SMin(mylist):
    sMin = mylist[0]
    fMin = 0;
    for i in range(1,len(mylist)):
        if(mylist[i] < sMin):
            sMin = mylist[i]
            fMin = i
            
    return fMin


def SSelect(mylist):
    newlist = []
    for i in range(len(mylist)):
        smallest = SMin(mylist)
        newlist.append(mylist.pop(smallest))
        
    return newlist

if __name__=='__main__':
    mylist=[5,3,6,2,10]
    print ("hello")
    print (mylist)
    print (SSelect(mylist))
    
    