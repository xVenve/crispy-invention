import numpy as np
import pandas as pd

df = pd.read_csv("concrete.csv")

df_norm = (df - df.min()) / (df.max() - df.min())  # Normaliza la entrada
df_norm = df_norm.sample(frac=1)  # Aleatoriza las instancias
df_norm.to_csv("concreteProcessed.csv", index=False)  # Guardamos el fichero normalizado y aleatorizado

_7 = df_norm.sample(frac=0.7)  # Obtiene el 70 % de las entradas
_3 = df_norm.drop(_7.index)  # Obtiene el 30 % de las entradas
result = np.array_split(_3, 2)  # Del 30 % anterior, los divide en 2 partes, del 15 % de las entradas cada una

# Almacena los datos anteriores en cada fichero
_7.to_csv("training.csv", header=False, index=False)
result[0].to_csv("validation.csv", header=False, index=False)
result[1].to_csv("test.csv", header=False, index=False)
