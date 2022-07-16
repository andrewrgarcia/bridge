import json
import numpy as np

def oneD():
    arr = np.zeros(arraydims[0])
    for c in range(len(data['map'])):
        x = data['map'][c]
        arr[x] = np.array(data['value'])[c]
    return arr

def twoD():
    Y,X = arraydims
    arr = np.zeros((Y,X))
    for c in range(len(data['map'])):
        y,x = data['map'][c]
        arr[y,x] =  arr_values[c]
    return arr

def threeD():
    Z,Y,X = arraydims
    arr = np.zeros((Z,Y,X))
    for c in range(len(data['map'])):
        z,y,x = data['map'][c]
        arr[z,y,x] = data['value'][c]
    return arr

proc = { 1: oneD,  2: twoD,  3: threeD }

file = open('sample.json')
data = json.load(file)

print('DOK:\n',data)

data['map']
arraydims = np.array(data["objdims"])
arr_values = np.array(data['value'])

print('multidimensional array:\n',proc[arraydims.shape[0]]())
