import bridge
import numpy as np

X = np.random.choice([0,1,2,3],10,p=[0.7,0.1,0.1,0.1])

bridge.tojson('sample',X)


array_form = bridge.jsonload('sample')

print('multidimensional array:\n',array_form)