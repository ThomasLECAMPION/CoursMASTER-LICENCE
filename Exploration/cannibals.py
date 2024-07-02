from copy import deepcopy
import random

class State:
    def __init__(self, sides):
        self.sides = sides
        self.links = []

    def move(self, side, object1, object2):
        new_sides = deepcopy(self.sides)

        if(object1 in new_sides[side]):
            new_sides[side].remove(object1)
            new_sides[(side*(-1))+1].append(object1)
        if(object2 in new_sides[side]):
            new_sides[side].remove(object2)
            new_sides[(side*(-1))+1].append(object2)
        return State(new_sides)

    def equals(self, state):
        condition1 = (self.sides[0].count(0) == state.sides[0].count(0))
        condition2 = (self.sides[0].count(1) == state.sides[0].count(1))
        return condition1 and condition2

    def evaluate(self):
        #Victory
        if((self.sides[0].count(1) == 3) and (self.sides[1].count(0) == 3)):
            return 1
        #Defeat
        if(self.sides[0].count(0) > 0):
            if(self.sides[0].count(0) < self.sides[0].count(1)):
                return -1
        if(self.sides[1].count(0) > 0):
            if(self.sides[1].count(0) < self.sides[1].count(1)):
                return -1
        #Ongoing
        return 0

    def toString(self):
        print("State :")
        if(self.evaluate() == 0):
            print(" -side1:", end=" ")
            for i in self.sides[0]:
                print(i, end=" ")
            print("\n -side2:", end=" ")
            for i in self.sides[1]:
                print(i, end=" ")
            print("\n")
        elif(self.evaluate() == 1):
            print(" -Victory\n")
        elif(self.evaluate() == -1):
            print(" -Defeat\n")

def randomPathToWin(node):
    path.append(node)
    if(not node.equals(initial_state)):
        follow = False
        while not follow:
            follow = True
            link = random.choice(node.links)
            for state in path:
                if(state.equals(nodes[link])):
                    follow = False
        if(follow):
            randomPathToWin(nodes[link])

#dfs
def generateNodes(state):
    nodes.append(state)
    for side in range(2):
        for object1 in range(2):
            for object2 in range(3):
                addA = True
                addB = True
                new_state = state.move(side, object1, object2)
                if(new_state.evaluate() != -1):
                    if(new_state.equals(state)):
                        addB = False
                    else:
                        for link in state.links:
                            if(new_state.equals(nodes[link])):
                                addB = False
                    for node in nodes:
                        if(new_state.equals(node)):
                            addA = False
                    if(addB):
                        for i in range(len(nodes)):
                            if(nodes[i].equals(new_state)):
                                state.links.append(i)
                    if(addA):
                        generateNodes(new_state)

if __name__ == "__main__":
    sides = [[0, 0, 0], [1, 1, 1]]
    initial_state = State(sides)

    nodes = []
    generateNodes(initial_state)
    win = nodes[-1]

    path = []
    randomPathToWin(win)
    for node in path:
        node.toString()
