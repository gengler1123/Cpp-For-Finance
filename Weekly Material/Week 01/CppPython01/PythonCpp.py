# -*- coding: utf-8 -*-
"""
Created on Fri Dec 23 08:59:35 2016

@author: Gary
"""

import pandas as pd
import os


myFile = "newData.csv"

os.system("CppPython01.exe newData.csv")

df = pd.read_csv("newData.csv", header=None)

plt.figure()
plt.scatter(df[0],df[1])
plt.show()