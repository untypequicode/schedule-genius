# Élèves

| ***id*** | **id** | nom | prenom | *matieres* | *groupes* | annee | *niveau* |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 0 | 0 | "Nom" | "Prénom" | [0, 1, 2] | [0, 1] | 2005 | 0 |
 
# Groupes
| ***id*** | **id** | nom | *profs* | *matieres* | horaire | *niveau* | *salles* |
| --- | --- | --- | --- | --- | --- | --- | --- |
| 0 | 0 | "Nom" | [0, 1, 2] | [0, 1] | ... | 0 | [0, 1, 2, 3]

# Professeurs
| ***id*** | **id** | nom | prenom | nombre heures | *salles* | horaire |
| --- | --- | --- | --- | --- | --- | --- |
| 0 | 0 | "Nom" | "Prénom" | 15 | [0, 1, 2] | ... |

# Niveaux
| ***id*** | **id** | nom | matieres | *profs* |
| --- | --- | --- | --- | --- |
| 0 | 0 | "Nom" | [0, 1, 2] | [0, 1, 2, 3] |

# Matières
| ***id*** | **id** | nom | nombre heures | *niveau* |
| --- | --- | --- | --- | --- |
| 0 | 0 | "Math" | 6 | [0] |

# Salles
| ***id*** | **id** | nom | horaire |
| --- | --- | --- | --- |
| 0 | 0 | "Nom" | ... |