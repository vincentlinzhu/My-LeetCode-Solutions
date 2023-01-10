class Container:
    """
    A container of integers that should support
    addition, removal, and search for the median integer
    """
    def __init__(self):
        self.container = []
        pass

    def add(self, value): # type: (int) -> None
        """
        Adds the specified value to the container

        :param int value:
        """
        # TODO: implement this method
        self.container.append(value)
        pass

    def delete(self, value): # type: (int) -> bool
        """
        Attempts to delete one item of the specified value from the container

        :param int value:
        :return: True, if the value has been deleted, or
                 False, otherwise.
        """
        # TODO: implement this method
        if value in self.container:
            self.container.remove(value)
            return True
        else:
            return False

    def get_median(self): # type: () -> int
        """
        Finds the container's median integer value, which is
        the middle integer when the all integers are sorted in order.
        If the sorted array has an even length,
        the leftmost integer between the two middle
        integers should be considered as the median.

        :return int: The median if the array is not empty, or
        :raise Exception: a runtime exception, otherwise.
        """
        # TODO: implement this method
        n = len(self.container)
        s = sorted(self.container)
        if n:
            return s[(n - 1) / 2]  
        else:
            return s[n / 2]
