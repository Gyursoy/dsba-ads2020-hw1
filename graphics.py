import pandas as pd
import matplotlib.pyplot as plt

results = pd.read_csv('data.csv')
results.plot(x='n-digits')
plt.show()