import matplotlib.pyplot as plt
import numpy as np
import math

y = np.loadtxt("capture.txt",dtype = float)
n = len(y)  
x = np.array(range(n))
plt.plot(x,y)
plt.show()