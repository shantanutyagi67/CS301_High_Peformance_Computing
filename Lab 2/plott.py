import pandas as pd
from matplotlib import pyplot as plt
data0 = pd.read_csv(r'C:\Users\geekSA67\code\CS301_High_Peformance_Computing\Lab 2\3\ijk.txt', sep=",", header=None)
data1 = pd.read_csv(r'C:\Users\geekSA67\code\CS301_High_Peformance_Computing\Lab 2\3\ijk block.txt', sep=",", header=None)
x = [7+i for i in range(6)]
plt.figure(1)
plt.plot(x,data0.loc[0])
plt.plot(x,data1.loc[0])
plt.xlabel('Power of 2')
plt.ylabel('Time taken')
plt.legend(['ijk without blocking','ijk with blocking'])
plt.grid()
plt.show()