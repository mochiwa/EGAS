# ----------------EGAS----------------
## GitHub:
  - Aucune modification ne doit être faite dans la Branch Master, mais toujours
dans une nouvelle Branch (ne pas hésiter à créer des branches c'est fait pour).
  - Rien n’interdit d’avoir plusieurs branches ou même des branches de branch
(dans le cas d’un commit alors pas besoin de validation de l’équipe vue que
ce sont vos branches de branches...).
  - Pour chaque Pull Request (merge/fusion de votre branch à la branch Master)
décrire clairement vos modifications et ne JAMAIS merger c'est propre Pull
Request 
 - Toujours supprimer les branches des merges effectués.
 - Utiliser l'onglet Project comme Board où seront mises les diverses taches à
faire, en progression, fini et enfin en cas de problème. Si vous déplacez un 'to
do' (ou autre) dans une colonne , édité le en inscrivant votre nom et la date
afin d'avoir un suivie 
  Si vous découvrez un bug ouvrir un Issues.
  - Je vous conseille vivement d’utiliser https://desktop.github.com/ si vous
n’utilisez pas GIT (on linux) car la gestion des fichiers deviendra très vite un
casse-tête ! (il vaut mieux ‘perdre’ 2h à comprendre comment fonction github
desktop plutôt que des heures plus tard !).
  - ### Cas Pratique:
    > Je veux modifier le nom d'une variable
    > - Créer un nouveau TO DO dans PROJECT.
    > - Créer une nouvelle branch avec mon nom en début ex : mochiwa-
editFunction.
    > - Je passe mon TO DO en IN PROGRESS.
    > - Je télécharge ma branch ou les fichiers désirés.
    > - Je fais les modifications.
    > - Je retourne sur GITHUB et je VERIFIE que je suis bien dans MA branch (mochiwa-editFunction) !
    > - J'upload mes fichiers/mon project (bien faire attention au path des fichiers si vous le faite manuellement).
    > - Je propose un Pull Request à l'équipe qui décide de valider.
    > - Une fois que l'équipe à validé on passe le IN PROGRESS à DONE.
    
## Comprendre EGAS:
  - Le but d’EGAS est de pouvoir générer des requêtes à partir de fichiers produit par Jmerise et ce qu’importe le type SGBD.
  - Voici le déroulement du programme :
    - 4 dossiers sont crées ,
      - input où seront placés les fichiers générés par Jmerise.
      - tmp où sera placée chaque table présente dans un fichier Jmerise.
      - output où seront placés les fichiers de requêtes générés.
      - Bibli où seront placés toutes les fichiers de données où allez pioché pour la génération
    - Au lancement du programme on choisit le fichier SQL parmi ceux placés dans le input
    - Le programme le découpe en plusieurs fichiers qui représente les tables
    - Demande le type de SGBD (Oracle,mysql,...)
    - Renomme chaque fichier avec son nom de table histoire d’être propre
    - Crée autant d’objects Table qu’il y a de fichier dans le tmp , ces tables sont composées d’attributes (nom et un type)
    - On parcour les tables et leurs attributes , on verifie si un attribute est ou non clée primaire ou étrangaire (dans ce cas générer des numéros de clé
      existante) sinon on demande à l’user de choisir le fichier où pioché une data (ce fichier étant dans le dossier Bibli)
    - une fois la table complète on demande combien de requête générer
    - on les écrit dans le output (tout dans un seul et unique fichier).
      
## Le travail:
  - J’ai tenté de produire un coeur où théoriquement vous n’avez pas à
toucher(SQLParser) et une interface que tout le monde utilisera
(TableReader par ex qui est abstraite) ainsi si je souhaite créer un object
capable de lire un fichier table de type Oracle je créerais un object
OracleTableReader qui héritera du TableReader et vous n’aurez qu’à
surcharger les méthodes abstraites en utilisant les fonctions public du
SQLParser sans même vous occuper de la lecture de fichier ! :)
  - En gros le travail de tous sera de créer à partir de bases solides des reader
et writer de SGBD (un exemple avec MYSQL est déjà opé).
  - A ceci se rajoutent les taches de base, debug , compatibilité , un coup de
main pour le dev du noyau ,etc

## Règles de commentaires:
Il est important d’utiliser les commentaires à la doxygen (normalement tous
les IDE porpose une autocompletion sinon c’est fastidieux ... ) voici ce qui
dans tous les cas doit figurer (voir dans le code pour plus de détails):
``` 
/**
* @brief Description très brève de la fonction
* @param nom_du_param description (si param il y a)
* @return ce que la fonction retourne
* @note Si un commentaire supplémentaire est nécessaire
* @author Votre nom / pseudo
* @date Date de création
**/
```
## Dernières infos:
  - Faire un max de feedback ! Si un truc ne vas pas , une incompréhension , un
idée etc , il faut la balancé !!!
  - Les règles listés dans le README ne sont que des convention , on peut en ajouter ou enlevé !
