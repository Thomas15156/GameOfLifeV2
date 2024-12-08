# **GameOfLifeV2**

---

## **Description**
**Le Jeu de la Vie** est une simulation informatique basée sur un automate cellulaire inventé par le mathématicien John Horton Conway en 1970. Ce projet implémente les règles simples mais fascinantes de ce jeu, où des cellules sur une grille évoluent à chaque itération en fonction de l'état de leurs voisines. Le but est de créer des motifs dynamiques qui peuvent représenter des structures stables, oscillantes ou même chaotiques.

---

## **Installation**

### **Comment utiliser un patern pour le jeux ?**
Tout d'abord, il faut que le pattern que vous voulez utiliser ait une **syntaxe particulière** pour le code le prenne en compte. La première ligne doit avoir **2 valeurs strictement supérieur à 0** qui représent le nombre de lignes et de colonnes dans l'exemple (5 lignes et 10 colonnes). Puis le pattern en dessous ne comporte que **les entiers 0 , 1 ,2 et 3 :**
**-0 cellules mortes
-1 cellules vivantes
-2 cellules mortes immuables 
-3 cellules vivantes immuables 

> [!WARNING]
> Urgent info that needs immediate user attention to avoid problems.


`#ff2200`Le fichier doit bien évidemment être un .txt sinon il sera pas pris en compte.

Exemple : 
5 10
0 0 1 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0
0 1 1 1 0 0 3 3 3 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 2 2 0

**<ins> Comment entrer le paterne </ins>**
Lorsque le on exécute le code on doit renseigner un fichier en entrée dans la console. Il faut renseigner soit l'adresse du fichier comme ceci ()ou uniquement le nom du fichier si vous mettez votre .txt dans le dossier adapter à votre application pour Clion par exemple dans le dossier *cmake-build-debug*.

Une fois entré correctement il y a un message de succés et on passe à la sélection du mode d'affichage **Graphique** ou **Console**.

### **Mode Console**
