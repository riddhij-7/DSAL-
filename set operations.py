class SetADT:
    def __init__(self):
        self.elements = []

    def add(self, element):
        if element not in self.elements:
            self.elements.append(element)

    def remove(self, element):
        if element in self.elements:
            self.elements.remove(element)

    def display(self):
        for element in self.elements:
            print(element)

    def search(self, element):
        return element in self.elements

    def iterator(self):
        return iter(self.elements)

    def size(self):
        return len(self.elements)

    def intersection(self, other_set):
        result = SetADT()
        if other_set:
            for element in self.elements:
                if element in other_set.elements:
                    result.add(element)
        return result

    def union(self, other_set):
        result = SetADT()
        if other_set:
            for element in self.elements:
                result.add(element)
            for element in other_set.elements:
                result.add(element)
        else:
            for element in self.elements:
                result.add(element)
        return result

    def difference(self, other_set):
        result = SetADT()
        if other_set:
            for element in self.elements:
                if element not in other_set.elements:
                    result.add(element)
        else:
            for element in self.elements:
                result.add(element)
        return result

    def is_subset(self, other_set):
        if other_set:
            for element in self.elements:
                if element not in other_set.elements:
                    return False
        return True

# Example Usage
set1 = SetADT()
set2 = SetADT()

# Adding elements
set1.add(1)
set1.add(2)
set1.add(3)

set2.add(4)
set2.add(2)
set2.add(6)

# Display elements
print("Set 1:")
set1.display()

print("Set 2:")
set2.display()

# Set size
print("Set 1 size:", set1.size())
print("Set 2 size:", set2.size())

# Membership test
print("Set 1 contains 2:", set1.search(2))

# Difference
difference = set1.difference(set2)
print("Difference (Set1 - Set2):", list(set1.difference(set2).iterator()))

# Union
union = set1.union(set2)
print("Union:", list(set1.union(set2).iterator()))

# Subset check
print("Is Set1 a subset of Set2?:", set1.is_subset(set2))

# Intersection
intersection = set1.intersection(set2)
print("Intersection:", list(set1.intersection(set2).iterator()))
