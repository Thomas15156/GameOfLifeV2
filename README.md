# **GameOfLifeV2**

---

## **Description**
**Le Jeu de la Vie** est une simulation informatique basée sur un automate cellulaire inventé par le mathématicien John Horton Conway en 1970. Ce projet implémente les règles simples mais fascinantes de ce jeu, où des cellules sur une grille évoluent à chaque itération en fonction de l'état de leurs voisines. Le but est de créer des motifs dynamiques qui peuvent représenter des structures stables, oscillantes ou même chaotiques.

---

## **Installation**

### **Comment utiliser un patern pour le jeux ?**
Tout d'abord, il faut que le pattern que vous voulez utiliser ait une **syntaxe particulière** pour le code le prenne en compte. La première ligne doit avoir **2 valeurs strictement supérieur à 0** qui représent le nombre de lignes et de colonnes dans l'exemple (5 lignes et 10 colonnes). 
Puis le pattern en dessous ne comporte que **les entiers 0 , 1 ,2 et 3 :**
**- 0 cellules mortes**
**- 1 cellules vivantes**
**- 2 cellules mortes immuables**
**- 3 cellules vivantes immuables**

> [!WARNING]
> Le fichier doit bien évidemment être un .txt sinon il ne sera pas pris en compte.

Exemple : 
```plaintext
5 10
0 0 1 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0
0 1 1 1 0 0 3 3 3 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 2 2 0
````

**Comment entrer le paterne ?**
Lorsque l'on exécute le code, on doit renseigner un fichier en entrée dans la console. Il faut renseigner soit l'adresse du fichier comme ceci ()ou uniquement le nom du fichier si vous mettez votre .txt dans le dossier adapter à votre application pour Clion par exemple dans le dossier *cmake-build-debug*.

Une fois entré correctement, il y a un message de succès et on passe à la sélection du mode d'affichage **Graphique** ou **Console**.

### **Mode Console**
Lorsque l'on choisit ce mode, on nous demande d'activer ou non l'option de la grille torique. *Une grille torique est un type de grille où les bords opposés sont connectés, formant ainsi une surface sans fin, comme un tore, où les cellules aux bords se connectent entre elles.*
Une fois choisi, le programme crée automatiquement un dossier de sortie dans le répertoire courant (*cmake-build-debug* sur CLion), basé sur le nom du fichier d'entrée <nom_du_fichier_dentrée>_out, et si ce dossier existe déjà, une erreur est générée pour éviter toute perte de données. Si le dossier n'existe pas, il renvoie un message de succès puis lance les générations. **Pour des soucis de performance, elles sont limitées à 100 générations, mais cela peut être modifié facilement dans le code si besoin**. Chaque génération est sauvegardée fichier par fichier.

### **Mode Grpahique**
Lorsque l'on choisit ce mode, comme pour l'autre mode on nous demande l'activation de la grille torique. Une fois choisit on nous demande d'entrée la fréquence de rafraichissement puis l'affichage graphique s'ouvre. 
Syntaxe graphique :
**⬜️ 0 cellules mortes**
**⬛️ 1 cellules vivantes**
**🟥 2 cellules mortes immuables**
**🟩 3 cellules vivantes immuables**

