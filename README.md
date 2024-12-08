# **GameOfLifeV2**

---

## **Description**
**Le Jeu de la Vie** est une simulation informatique basée sur un automate cellulaire inventé par le mathématicien John Horton Conway en 1970. Ce projet implémente les règles simples mais fascinantes de ce jeu, où des cellules sur une grille évoluent à chaque itération en fonction de l'état de leurs voisines. Le but est de créer des motifs dynamiques qui peuvent représenter des structures stables, oscillantes ou même chaotiques.

---

## **Prérequis**
Avant de pouvoir exécuter ce projet, vous devez vous assurer d'avoir les outils suivants installés sur votre machine :

- CMake
- Un compilateur C++ compatible (par exemple GCC, Clang)

---

## **Installation**

### **Quelle est la syntaxe du pattern pour le jeu ?**

Tout d'abord, il faut que le pattern que vous voulez utiliser ait une **syntaxe particulière** pour le code le prenne en compte. La première ligne doit avoir **2 valeurs strictement supérieur à 0** qui représent le nombre de lignes et de colonnes dans l'exemple (5 lignes et 10 colonnes). 

**Puis le pattern en dessous ne comporte que les entiers 0 , 1 ,2 et 3 :**

 + **0 cellules mortes**

 + **1 cellules vivantes**

 + **2 cellules mortes immuables**

 + **3 cellules vivantes immuables**

> [!CAUTION]
> Le fichier doit bien évidemment être un .txt sinon il ne sera pas pris en compte.

<ins> Exemple : </ins>

```plaintext
5 10
0 0 1 0 0 0 0 0 0 0
0 0 0 1 0 0 0 0 0 0
0 1 1 1 0 0 3 3 3 0
0 0 0 0 0 0 0 0 0 0
0 0 0 0 0 0 0 2 2 0
````

### **Comment entrer le pattern ?**

Lorsque l'on exécute le code, on doit renseigner un fichier en entrée dans la console. Il faut renseigner soit l'adresse du fichier comme ceci ( **/chemin/vers/le/fichier.txt** )ou uniquement le nom du fichier si vous mettez votre .txt dans le dossier adapter à votre application pour Clion par exemple dans le dossier ( *cmake-build-debug* ).

Une fois entré correctement, il y a un message de succès et on passe à la sélection du mode d'affichage **Graphique** ou **Console**.

---

### **Mode Console**
Lorsque l'on choisit ce mode, il est demandé d'activer ou non l'option de la grille torique. *Une grille torique est un type de grille où les bords opposés sont connectés, formant ainsi une surface sans fin, comme un tore, où les cellules aux bords se connectent entre elles.*

Une fois l'option choisie, le programme crée automatiquement un dossier de sortie dans le répertoire courant (*cmake-build-debug* sur CLion), basé sur le nom du fichier d'entrée <nom_du_fichier_dentrée>_out. Si ce dossier existe déjà, une erreur est générée pour éviter toute perte de données. Si le dossier n'existe pas, un message de succès est renvoyé et les générations sont lancées. Pour des raisons de performance, le nombre de générations est limité à 100, mais cela peut être facilement modifié dans le code si nécessaire. Chaque génération est sauvegardée fichier par fichier.

---

### **Mode Graphique**
Lorsque vous choisissez ce mode, comme pour l'autre mode, il vous sera demandé d'activer la grille torique. Une fois cette option sélectionnée, vous devrez entrer la fréquence de rafraîchissement souhaitée. Et pour finir, l'affichage graphique s'ouvrira et vous pourrez observer le jeu en temps réel. À noter que ce mode ne prévoit pas de sauvegarde.

<ins> Représentation visuelle: </ins>

⬜️ **Cellules mortes**

⬛️ **Cellules vivantes**

🟥 **Cellules mortes immuables**

🟩 **Cellules vivantes immuables**

<ins> Même exemple mais avec affichage graphique: </ins>

```plaintext
5 10
0 0 1 0 0 0 0 0 0 0  |       ⬛️⬛️⬜️⬛️⬛️⬛️⬛️⬛️⬛️⬛️
0 0 0 1 0 0 0 0 0 0  |       ⬛️⬛️⬛️⬜️⬛️⬛️⬛️⬛️⬛️⬛️
0 1 1 1 0 0 3 3 3 0  |       ⬛️⬜️⬜️⬜️⬛️⬛️🟥🟥🟥⬛️
0 0 0 0 0 0 0 0 0 0  |       ⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️⬛️
0 0 0 0 0 0 0 2 2 0  |       ⬛️⬛️⬛️⬛️⬛️⬛️⬛️🟩🟩⬛️
 



````


---

 [Patterns créés par mes soins](https://drive.google.com/drive/folders/1abUCeNt5N0Q2OFq-pnItLVtpspVcLbbx?usp=drive_link)

---

### BOURLET Benjamin et PALISSE Thomas
