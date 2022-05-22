# ----------------------------------------------------
#  Masrik Dahir
#  Date: 04/15/2022
#
#  ---------------------------------------------------
#  Usage Guide
#  (1) pip install rectpack
#  (2) pip install Shapely
#  (3) pip install tkinter
#  (4) python .\Assignment7.py .\25PercentFill.txt
#  (5) python .\Assignment7.py .\50PercentFill.txt
#  (6) python .\Assignment7.py .\75PercentFill.txt
#  (7) python .\Assignment7.py .\95PercentFill.txt
#
# ----------------------------------------------------


# importing library: rectpack, tkinter, and sys
from rectpack import newPacker
from tkinter import *
import sys

# Class CustomCanvas to set the attributes for the CustomCanvas
class CustomCanvas:

    # Declaring local variables
    background = None
    ws = None

    # Constructor for CustomCanvas
    # Takes 2 arguments (height and wisth) and creates a CustomCanvas based on the height and width
    def __init__(self, height, width):

        # creates a toplevel widget of Tk
        CustomCanvas.ws = Tk()

        # Setting the title "Assignment 7: Creating Rectangles"
        CustomCanvas.ws.title("Assignment 7: Creating Rectangles")

        # Setting atrributes with given height and width for the rectangle
        CustomCanvas.background = \
            Canvas(
                CustomCanvas.ws,
                width=width,
                height=height,
                bg="#F70D1A"
            )

        # Pack the background
        CustomCanvas.background.pack()

# CLass Rectangle to create a rectangle in a specific position of the canvas
class Rectangle:

    # Constructor of Rectangle class
    # Takes four arguments (height, width, x, y)
    # The default value of x and y is set to 0
    def __init__(self, height, width, x=0, y=0):
        self.height = height
        self.width = width
        Rectangle.x = x
        Rectangle.y = y

# function pack that takes two arguments: allRect and canvasSize
# allRect is the a list of Rectangle objects and
# canvasSize a tuple containing a canvas’ height and width
# pack() determine a location for each rectangle using add_bin() funciton of newPacker
# to ensure that there is no overlap
def pack(allRect, CanvasSize):

    # Setting up the height (first value of CanvasSize) and width (second value of CanvasSize)
    height = int(CanvasSize[0])
    width = int(CanvasSize[1])

    # object variables creates the canvas window using the canvas height and canvas width
    object = newPacker()
    object.add_bin(int(height), int(width))
    object_list = []

    # We append height and width of all the rectangle objects to object_list
    for rect in allRect:
        object_list.append((int(rect.height), int(rect.width)))

    # We iterate throught the object_list
    # for each element of object_list we create a Rectangle Object by using the add_rect() function
    for i in object_list:
        object.add_rect(*i)

    # Pack the rectangles
    object.pack()

    # return the list of objects
    return list(object[0])


def main():

    # Takes the first argument from commandline by sys.argv[1]
    path = sys.argv[1]

    # Creating canvas_height and canvas_weight variables
    canvas_height = 0
    canvas_weight = 0

    # opening the txt files path to read lines
    with open(path) as lines:

        # Set the size to the line height and width
        # We get the height and width of the canvas by using split(",") built-in function
        size = lines.readline().strip().split(",")

        # Setting canvas_height and canvas_weight to canvas height and canvas width
        canvas_height = size[0]
        canvas_weight = size[1]

        # Create a rectangles list
        rectangles = []

        # Get the rest of the height and width which correspond to the rectangle height and width
        # Create rectangle object (after spliting by comma) and append the rectangel objects to rectangles list
        for dimention in lines:
            rectangles.append(Rectangle(*dimention.strip().split(",")))

    # Creating the canvas with height=canvas_height and width=canvas_weight
    CustomCanvas(canvas_height, canvas_weight)

    # Creating rectangles object with rectangles list and the size
    rectangles = pack(rectangles, size)

    # drawing rectangle from the rectangles object
    # X-cooridnate  : rectangle.x
    # Y-cooridnate  : rectangle.y
    # width         : rectangle.x + rectangle.width
    # length        : rectangle.y + rectangle.height
    for rectangle in rectangles:
        CustomCanvas.background.create_rectangle(rectangle.x, rectangle.y, rectangle.x + rectangle.width, rectangle.y + rectangle.height, outline="black", fill="#228B22")

    # Run the mainloop()
    CustomCanvas.ws.mainloop()

# Calling the main function()
if __name__ == "__main__":
    main()
