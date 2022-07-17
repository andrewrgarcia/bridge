import transfer
import numpy as np

X = np.random.choice([0,1,2,3],10,p=[0.7,0.1,0.1,0.1])

transfer.tojson('sample',X)