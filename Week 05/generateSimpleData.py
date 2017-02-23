# -*- coding: utf-8 -*-
"""
Created on Thu Feb 23 10:21:12 2017

@author: Gary
"""
import numpy as np
import matplotlib.pyplot as plt

D1 = np.random.normal((5,5),(1,1),(500,2))
D2 = np.random.normal((-2,-3),(.5,.5),(500,2))
D3 = np.random.normal((2,-6),(.7,.3),(500,2))


with open('simpleData.csv','w') as f:
    for d in D1:
        f.write(str(d[0])+","+str(d[1])+",1,0,0\n")
        pass
    for d in D2:
        f.write(str(d[0])+","+str(d[1])+",0,1,0\n")
        pass
    for d in D3:
        f.write(str(d[0])+","+str(d[1])+",0,0,1\n")
        pass

plt.figure()
plt.scatter(D1[:,0],D1[:,1])
plt.scatter(D2[:,0],D2[:,1])
plt.scatter(D3[:,0],D3[:,1])
plt.savefig("simpleData.png")
plt.show()