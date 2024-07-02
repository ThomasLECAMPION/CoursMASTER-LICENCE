#DFS
def parcoursProfondeur(sommet):
    parcours.append(sommet)
    for i in range(len(graphe)):
        if (graphe[sommet][i] >= 1) and (not i in parcours):
            parcoursProfondeur(i)

#BFS
def parcoursLargeur(sommet):
    file = []
    file.append(sommet)
    parcours.append(sommet)
    while file:
        sommet = file[0]
        file.pop(0)
        for i in range(len(graphe)):
            if (graphe[sommet][i] >= 1) and (not i in parcours):
                file.append(i)
                parcours.append(i)

def afficherGraphe():
    print("Représentation du graphe:")
    for x in graphe:
        for y in x:
            print(str(y) + " ", end="")
        print("\n", end="")

def construireGraphe():
    taille = int(input("Nombre de noeuds du graphe ?\n"))
    graphe = [ [0]*taille for i in range(taille)]
    i=0
    while i<taille:
        try:
            suivant = int(input("Noeud " + str(i) + ": " + str(graphe[i]) + "\n"))
            graphe[i][suivant] = 1
        except:
            i+=1
    return graphe

if __name__ == "__main__":
    graphe = construireGraphe()
    afficherGraphe()

    depart = int(input("Noeud de départ:\n"))

    parcours = []
    print("DFS:")
    parcoursProfondeur(depart)
    print(parcours)

    parcours.clear()
    print("BFS:")
    parcoursLargeur(depart)
    print(parcours)
