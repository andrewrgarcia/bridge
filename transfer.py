import numpy as np

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

def tojson(filename, array):
    
    DIM = len(array.shape)
    
    fundict = {1: oneD, 2:twoD, 3:threeD}

    dict = fundict[DIM](array)
    
    print(dict)
    with open(filename+'.json', 'w') as f:
        f.write(str(dict).replace("'","\"")) 

    return dict


