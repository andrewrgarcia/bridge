import bridge
import numpy as np

'CREATE A 1-D VECTOR'
X = np.random.choice([0,1,2,3],10,p=[0.7,0.1,0.1,0.1])
'pack vector to .json file'
bridge.tojson('sample.json',X)

'PROCESS JSON FILE BACK TO VECTOR'
array_form = bridge.jsonload('sample.json')
'print vector'
print('array:\n',array_form)