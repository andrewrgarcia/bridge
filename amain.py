import json
import numpy as np

def oneD(data):
    arr = np.zeros(data["odims"])
    for c in range(len(data['map'])):
        x = data['map'][c][0]
        arr[x] = data['value'][c]
    return arr

def twoD(data):
    Y,X = data["odims"]
    arr = np.zeros((Y,X))
    for c in range(len(data['map'])):
        y,x = data['map'][c]
        arr[y,x] =  data['value'][c]
    return arr

def threeD(data):
    Z,Y,X = data["odims"]
    arr = np.zeros((Z,Y,X))
    for c in range(len(data['map'])):
        z,y,x = data['map'][c]
        arr[z,y,x] = data['value'][c]
    return arr

def load(filename):

    proc = { 1: oneD,  2: twoD,  3: threeD }

    file = open(filename+'.json')
    data = json.load(file)

    print('DOK:\n',data)

    # data['map']
    DIM = len(data["odims"])
    print(DIM)
    # arr_values = np.array(data["value"])

    array = proc[DIM](data)

    return array

array_form = load('sample')

print('multidimensional array:\n',array_form)
