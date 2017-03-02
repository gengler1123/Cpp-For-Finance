# -*- coding: utf-8 -*-
"""
Created on Wed Jan 25 09:28:09 2017

@author: Gary
"""

import numpy as np



def nonlin(x,deriv=False):
    if(deriv==True):
        return x*(1-x)
    return 1/(1+np.exp(-x))


class SGDNN():
    def __init__(self,
                 hiddenSize_,
                 inputSize_=2,
                 outputSize_=3,
                 giveSeed_=False,
                 seed = 1):
        sizeHidden = 20
        if giveSeed_:
            np.random.seed(seed)
        self.syn0 = (2*np.random.random((inputSize_,sizeHidden)) - 1)/np.sqrt(hiddenSize_)
        self.syn1 = (2*np.random.random((sizeHidden,outputSize_)) - 1)/np.sqrt(hiddenSize_)
    
    
    def testPoint(self, X):
        l0 = X
        l1 = nonlin(np.dot(l0, self.syn0))
        l2 = nonlin(np.dot(l1, self.syn1))
        return l2
    
    def trainingAlgorithm(self,Data):
        '''Need to give Data combined with Labels'''
        All = Data
        for j in range(10000):
            if (j % 100) == 0:
                np.random.shuffle(All)
            A = All
            A = np.split(A, 50)
            for a in A:
                l0 = a[:,0:2]
                l1 = nonlin(np.dot(l0,self.syn0))
                l2 = nonlin(np.dot(l1,self.syn1))

                l2_error = a[:,2:5] - l2

                l2_delta = l2_error*nonlin(l2,deriv=True)

                l1_error = l2_delta.dot(self.syn1.T)

                l1_delta = l1_error * nonlin(l1,deriv=True)

                self.syn1 += 0.1*l1.T.dot(l2_delta)
                self.syn0 += 0.1*l0.T.dot(l1_delta)

            
            if (j % 1000 ) == 0:
                l0 = All[:,0:2]
                l1 = nonlin(np.dot(l0, self.syn0))
                l2 = nonlin(np.dot(l1, self.syn1))
                L2_Error = All[:,2:5] - l2
                print("Error: " + str(np.mean(np.abs(L2_Error))))
                    

if __name__ == "__main__":
    D1 = np.random.normal((5,5),(1,1),(1000,2))
    D2 = np.random.normal((-2,-3),(.5,.5),(1000,2))
    D3 = np.random.normal((2,-6),(.7,.3),(1000,2))
    
    import matplotlib.pyplot as plt    
    plt.figure()
    plt.scatter(D1[:,0],D1[:,1])
    plt.scatter(D2[:,0],D2[:,1])
    plt.scatter(D3[:,0],D3[:,1])
    plt.show()
    
    
    Points = []
    X = np.linspace(-5,5,100)
    Y = np.linspace(-8,8,100)    
    for x in X:
        for y in Y:
            Points.append(np.array([x,y]))
    
    Data = np.vstack([D1,D2,D3])
    
    L1 = np.array([[1,0,0] for i in range(len(D1))])
    L2 = np.array([[0,1,0] for i in range(len(D2))])
    L3 = np.array([[0,0,1] for i in range(len(D3))])
    
    Label = np.vstack([L1,L2,L3])
        
    
    All = np.hstack([Data,Label])
                     
    Network = SGDNN(5)
    Network.trainingAlgorithm(All)
    
    print("Testing")
    print("[-2,-3]")
    print(Network.testPoint(np.array([-2,-3])))
    print("[5,5]")
    print(Network.testPoint(np.array([5,5])))
    Vals = []    
    for p in Points:
        Vals.append(Network.testPoint(p))
    
    f = open("trainedValues.csv",'w')
    for i in range(len(Points)):
        Line = str(Points[i][0])+","+str(Points[i][1])+","+str(np.argmax(Vals[i])) +"\n"
        f.write(Line)
    f.close()
