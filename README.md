# bridge

Connecting array data between Python and C++ through the use of JSON files. 
Python and C++ modules use **tojson** and **jsonload** functions to convert arrays to .json DOK (Dictionary of Keys) and viceversa, respectively. See Usage Examples below. 

## Contributors

- [Andrew Garcia](https://github.com/andrewrgarcia) - creator and maintainer

## Contributing

1. Fork it (<https://github.com/your-github-user/tensorscout/fork>)
2. Create your feature branch (`git checkout -b my-new-feature`)
3. Commit your changes (`git commit -am 'Add some feature'`)
4. Push to the branch (`git push origin my-new-feature`)
5. Create a new Pull Request

## Sample Output
```ruby
array to DOK:
{
	"map": [
		[1],
		[4],
		[5],
		[8],
		[9]
	],
	"value": [2, 3, 2, 2, 2],
	"odims": [10]
}

DOK to array:
[0. 2. 0. 0. 3. 2. 0. 0. 2. 2.]
```

## Usage Examples

**C++**

```ruby
#include <iostream>
#include <vector>
#include <stdio.h>
#include "include/garcia/bridge.hpp"

int main()
{
    // CREATE A VECTORIZED ARRAY
    std::vector<int> vector0(8, 1);
    std::vector<int> DIMS = {2, 2, 2};
    std::string filename{"sample.json"};
    // pack vector to .json file
    tojson(filename, vector0, DIMS);

    // PROCESS JSON FILE BACK TO VECTOR
    std::vector<int> vector = jsonload(filename);
    // print vector
    std::cout << "\nvectorized array: " << std::endl;
    for (int i = 0; i < vector.size(); i++)
    {
        std::cout << vector[i] << " ";
    }
    std::cout << std::endl;
}
```

**Python**

```python
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
```



