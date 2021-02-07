import pandas as pd
from matplotlib import pyplot as plt
data = pd.read_csv(r'C:\Users\geekSA67\code\CS301_High_Peformance_Computing\Lab 2\b1.txt', sep=",", header=None)
data1 = pd.read_csv(r'C:\Users\geekSA67\code\CS301_High_Peformance_Computing\Lab 2\b2.txt', sep=",", header=None)

data11 = pd.read_csv(r'C:\Users\geekSA67\code\CS301_High_Peformance_Computing\Lab 2\b3.txt', sep=",", header=None)
x = [4+i for i in range(12)]
plt.figure(1)
plt.plot(x,data.loc[0])
plt.plot(x,data1.loc[0])
plt.plot(x,data11.loc[0])
plt.xlabel('Power of 2')
plt.ylabel('Time taken')
plt.legend(['Without Optimisation','Loop Reordering','Reducing Repetitive computations'])
plt.grid()
plt.show()