class Rectangle:
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def display(self):
        print(f"Width: {self.width}, Height: {self.height}")

shape = Rectangle(10, 20)
shape.display()
shape.width = 15
shape.height = 25
shape.display()