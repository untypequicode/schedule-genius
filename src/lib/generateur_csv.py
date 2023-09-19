""" CSV generator """
from random import randint

NOMBRE_ELEVE = 200

prenoms = ["Alice", "Bob", "Charlie", "David", "Eve", "Frank", "Grace", "Hannah", "Ivy", "Jack",
"Katherine", "Liam", "Mia", "Noah", "Olivia", "Peter", "Quinn", "Rachel", "Samuel", "Taylor",
"Ursula", "Victor", "Wendy", "Xavier", "Yasmine", "Zane"]
noms_de_famille = ["Dupont", "Martin", "Dubois", "Bernard", "Thomas", "Robert", "Richard", "Petit", "Durand", "Leroy",
                   "Moreau", "Simon", "Laurent", "Lefebvre", "Michel", "Garcia", "David", "Roux", "Bonnet", "Fournier",
                   "Lopez", "Legrand", "Martinez", "Ferreira", "Fernandez", "Blanc", "André", "Leroux", "Rousseau"]
matieres_communes_1 = ["Francais", "Histoire" "Geo", "EMC", "EPS", "SPC", "SVT", "Maths","NSI","Philo","Anglais","Espagnole","Allemand","Italien","Russe"]

with open('eleve.csv', 'w') as eleve:
    eleve.write("Prenom;Nom;annee;")
    for i in range(1,11):
        eleve.write(f"matiere{i};")
    eleve.write("\n")
    for i in range(NOMBRE_ELEVE):
        eleve.write(f"{prenoms[randint(0,len(prenoms)-1)]};{noms_de_famille[randint(0,len(noms_de_famille)-1)]};")
        annee = randint(1,3)
        eleve.write(f"{annee};")
        matiere_remain = matieres_communes_1.copy()
        nombre_matiere = randint(0,10)
        for i in range(nombre_matiere):
            matiere_i = randint(0, len(matiere_remain)-1)
            matiere_temp = matiere_remain[matiere_i]
            matiere_remain.pop(matiere_i)
            eleve.write(f"{matiere_temp};")
        for i in range(10 - nombre_matiere):
            eleve.write("None;")
        eleve.write("\n")

