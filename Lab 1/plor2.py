import pandas as pd
from matplotlib import pyplot as plt
data = pd.read_csv(r'C:\Users\geekSA67\Desktop\results.txt', sep=",", header=None)
print(data)
x = [8+i for i in range(22)]
plt.plot(x,data.loc[0])
plt.grid()
plt.show()