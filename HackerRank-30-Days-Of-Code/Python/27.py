def minimum_index(seq):
    if len(seq) == 0:
        raise ValueError("Cannot get the minimum value index from an empty sequence")
    min_idx = 0
    for i in range(1, len(seq)):
        if seq[i] < seq[min_idx]:
            min_idx = i
    return min_idx
class TestDataEmptyArray(object):
    
    @staticmethod
    def get_array():
        return list()
        # complete this function

class TestDataUniqueValues(object):

    @staticmethod
    def get_array():
        return [5, 2, 8, 3, 1, -6, 9]
        # complete this function

    @staticmethod
    def get_expected_result():
        return 5
        # complete this function

class TestDataExactlyTwoDifferentMinimums(object):

    @staticmethod
    def get_array():
        # complete this function
        return [5, 2, 8, 3, 1, -6, 9, -6, 10]

    @staticmethod
    def get_expected_result():
        # complete this function
        return 5
