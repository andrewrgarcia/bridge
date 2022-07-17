import json
import numpy as np


def tojson(filename, array):

    def oneD(array):
        X = array.shape[0]

        dict = {}

        dict["map"] =\
        [ [i] for i in range(X) if array[i] != 0 ]

        dict["value"] =\
        [ array[i] for i in range(X) if array[i] != 0 ]

        dict["odims"] = [X]

        return dict

    def twoD(array):
        Y,X = array.shape

        dict = {}

        dict["map"] =\
        [ [j,i] for j in range(Y) for i in range(X) if array[j,i] != 0 ]

        dict["value"] =\
        [ array[j,i] for j in range(Y) for i in range(X) if array[j,i] != 0 ]

        dict["odims"] = [Y,X]

        return dict

    def threeD(array):
        Z,Y,X = array.shape

        dict = {}

        dict["map"] =\
        [ [k,j,i] for k in range(Z) \
        for j in range(Y) for i in range(X) if array[k,j,i] != 0 ]

        dict["value"] =\
        [ array[k,j,i] for k in range(Z) \
        for j in range(Y) for i in range(X) if array[k,j,i] != 0 ]

        dict["odims"] = [Z,Y,X]

        return dict
    
    DIM = len(array.shape)
    
    fundict = {1: oneD, 2:twoD, 3:threeD}

    dict = fundict[DIM](array)
    
    print(dict)
    with open(filename, 'w') as f:
        f.write(str(dict).replace("'","\"")) 

    return dict


def jsonload(filename):

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

    proc = { 1: oneD,  2: twoD,  3: threeD }

    file = open(filename)
    data = json.load(file)

    print('DOK:\n',data)

    # data['map']
    DIM = len(data["odims"])
    print(DIM)
    # arr_values = np.array(data["value"])

    array = proc[DIM](data)

    return array


