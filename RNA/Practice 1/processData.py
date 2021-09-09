import numpy as np
import pandas as pd

df = pd.read_csv('concrete.csv')

df_norm = (df - df.min()) / (df.max() - df.min())
df_norm = df_norm.sample(frac=1)
df_norm.to_csv('concreteProcessed.csv', index=False)

_7 = df_norm.sample(frac=0.7)
_3 = df_norm.drop(_7.index)
result = np.array_split(_3, 2)

_7.to_csv('training.csv', index=False)
result[0].to_csv('validation.csv', index=False)
result[1].to_csv('test.csv', index=False)
