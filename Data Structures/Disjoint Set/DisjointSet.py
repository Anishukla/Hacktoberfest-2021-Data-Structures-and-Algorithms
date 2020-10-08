class DisjointSet:
    """
Disjoint Set data structure (Union–Find), is a data structure that keeps track of a 
set of elements partitioned into a number of disjoint (nonoverlapping) subsets.
Methods:
    
find: Determine which subset a particular element is in. Takes an element of any
subset as an argument and returns a subset that contains our element.
                                                
union: Join two subsets into a single subset. Takes two elements of any subsets
from disjoint_set and returns a disjoint_set with merged subsets.
                                                                        
get: returns current disjoint set.

"""
    _disjoint_set = list()

    def __init__(self, init_arr):
        self._disjoint_set = []
        if init_arr:
            for item in list(set(init_arr)):
                self._disjoint_set.append([item])
    def _find_index(self, elem):
        for item in self._disjoint_set:
            if elem in item:
                return self._disjoint_set.index(item)
        return None
    def find(self, elem):
        for item in self._disjoint_set:
            if elem in item:
                return self._disjoint_set[self._disjoint_set.index(item)]
        return None
                            
    def union(self,elem1, elem2):
        index_elem1 = self._find_index(elem1)
        index_elem2 = self._find_index(elem2)
        if index_elem1 != index_elem2 and index_elem1 is not None and index_elem2 is not None:
            self._disjoint_set[index_elem2] = self._disjoint_set[index_elem2]+self._disjoint_set[index_elem1]
            del self._disjoint_set[index_elem1]
        return self._disjoint_set
                                                                                                
    def get(self):
        return self._disjoint_set
