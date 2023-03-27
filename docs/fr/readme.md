EncryptPad est une application de visualisation et d’édition de texte chiffré symétriquement. Grâce à son interface graphique et en ligne de commande simple, EncryptPad propose un outil pour chiffrer et déchiffrer des fichiers binaires sur le disque, tout en offrant des mesures efficaces pour protéger les informations. De plus, EncryptPad utilise le format de fichier **OpenPGP** [RFC 4880](https://tools.ietf.org/html/rfc4880) qui est largement adopté pour sa qualité. Contrairement à d’autres logiciels OpenPGP dont le but principal est le chiffrement asymétrique, l’objectif premier d’EncryptPad est le chiffrement symétrique.

## Table des matières

* [Caractéristiques](#features)
* [Plateformes prises en charge](#supported-platforms)
* [Pourquoi utiliser EncryptPad ?](#why-use-encryptpad)
* [Quand ai-je besoin d’EncryptPad ?](#when-encryptpad)
* [Quand ne puis-je pas utiliser EncryptPad ?](#when-can-i-not)
* [Types de fichiers](#file-types)
  – [GPG](#gpg)
  – [EPD](#epd)
  – [Prise en charge des fonctions](#feature-support)
* [Qu’est-ce qu’un fichier clé EncryptPad ?](#key-file)
* [Format de fichier EPD lors du chiffrement avec clé](#epd-file-format)
* [Utiliser CURL pour télécharger automatiquement des clés d’un stockage distant](#use-curl)
* [Faiblesses connues](#known-weaknesses)
* [Interface en ligne de commande](#command-line-interface)
  – [encryptcli](#command-line-encryptcli)
  – [encryptpad](#command-line-encryptpad)
* [Installer EncryptPad](#installing)
    – [Exécutable portable](#portable-exe)
    – [Arch Linux](#install-on-arch)
    – [Ubuntu ou Linux Mint](#install-on-ubuntu)
* [Compiler EncryptPad sous Windows](#compile-on-windows)
  – [Prérequis](#prerequisites)
  – [Étapes](#steps)
* [Compiler EncryptPad sous macOS](#compile-on-macos)
* [Compiler EncryptPad sous Linux](#compile-on-linux)
    – [Fedora](#build-on-fedora)
    – [Ubuntu](#build-on-ubuntu)
    – [Debian](#build-on-debian)
    – [openSUSE](#build-on-opensuse)
    – [Archlinux](#build-on-archlinux)
    – [FreeBSD](#build-on-freebsd)
	- [VoidLinux](#compiler-sous-voidlinux)
* [Mode portable](#mode-portable)
* [Mode FakeVim](#fakevim-mode)
    – [FakeVim : commandes d’entrée et de sortie](#fakevim-input-output)
* [EncryptPad stocke-t-il les phrases de passe en mémoire pour rouvrir les fichiers ?](#passphrases-in-memory)
* [Remerciements](#acknowledgements)
* [Vérification de l’intégrité par EncryptPad](#integrity-verification)
    – [Signature OpenPGP et autorité de certification](#openpgp-signing)
    – [Processus de vérification étape par étape](#verification-process)
* [Licence](#license)
* [Contact et rétroaction](#contacts)


<div id="features"></div>

## Caractéristiques

* Chiffrement **symétrique**
* Protection par **phrase de passe**
* Protection par **fichier clé**
* Combinaison d’une **phrase de passe et d’un fichier clé**
* **Générateur de fichiers clés** aléatoires 
* **Dépôt de clés** dans un dossier caché du dossier personnel de l’utilisateur
* Le chemin d’un fichier clé peut être stocké dans un fichier chiffré. Si cette option est activée, **vous n’avez pas à indiquer le fichier clé** chaque fois que vous ouvrez des fichiers.
* Chiffrement de **fichiers binaires** (images, vidéos, fichiers compressés, etc.)
* Mode **FakeVim** pour modifier des fichiers avec une interface qui ressemble à Vim
* Mode **lecture seulement** pour empêcher les modifications accidentelles de fichiers
* Encodage de texte **UTF8**
* **Fins de ligne configurable** Windows ou Unix
* Un **générateur de phrases de passe** personnalisable aide à créer des phrases de passe aléatoires robustes.
* Format de fichier compatible avec **OpenPGP**
* **S2K itéré et salé**
* **Les phrases de passe ne sont pas conservées en mémoire** pour être réutilisées, seulement les résultats S2K ([plus…](#passphrases-in-memory))
* Algorithmes de chiffrement : **TripleDES, CAST5, AES, AES192, AES256, Camellia128, Camellia192, Camellia256, Twofish**
* Algorithmes de hachage : **SHA-1, SHA-256, SHA-384, SHA-512, SHA-224**
* Protection de l’intégrité : **SHA-1**
* Compression : **ZLIB, ZIP, Bzip2**
* **Armure ASCII**
* Les ** fichiers volumineux de plusieurs giga-octets** sont pris en charge

<div id="supported-platforms"></div>

## Plateformes prises en charge

* Windows

* Linux

* Mac OS

<div id="why-use-encryptpad"></div>

## Pourquoi utiliser EncryptPad ?

* Code base **multiplateforme : EncryptPad a été compilé sur trois systèmes d’exploitation populaires et peut être adapté à d’autres.

* **Portable** : il suffit de copier l’exécutable sur une clé USB ou un disque réseau pour l’utiliser sur tous vos ordinateurs.

* **Convivial** : EncryptPad est un éditeur de texte et un outil de chiffrement pour fichiers binaires, mais il enregistre des fichiers chiffrés, compressés et dont l’intégrité est protégée.

* À **code source ouvert** avec un code base concis : vous pouvez lire le code ou demander à quelqu’un de confiance de le lire pour vous afin de vous assurer qu’il n’y a pas de porte dérobée et que vos informations sont en sécurité.

* Format de fichier **OpenPGP** : vous pouvez chiffrer un fichier avec un autre outil (gpg par exemple) qui utilise ce format, et l’ouvrir ensuite avec EncryptPad, et vice versa.

* **Protection double** : des fichiers clés générés aléatoirement en plus de phrases de passe.

<div id="when-encryptpad"></div>

## Quand ai-je besoin d’EncryptPad ?

* Vous avez un fichier contenant des informations délicates telles que des noms de compte, des phrases de passe ou des numéros d’identification. Ce fichier est stocké sur un support sans protection, ou vous ne pouvez pas contrôler qui y accède, que ce soit au travail, sur un ordinateur portable lors de déplacements, une clé USB ou un disque nuagique.

* Vous devez envoyer un fichier chiffré à quelqu’un avec qui vous avez prédéterminé un secret (une phrase de passe ou un fichier clé). Dans ce cas, vous devez échanger le secret en personne (pas par un protocole Internet accessible) pour que le fichier protégé soit déchiffré par le destinataire.

* You are on public transport or a common area where **somebody can see your screen**.

* Vous devez être protégé contre une attaque par force brute au cas où votre moyen de stockage tomberait dans les mains de quelqu’un. EncryptPad permet de générer une clé et de la stocker séparément des informations chiffrées. Une personne non autorisée aurait besoin de deux secrets pour ouvrir un fichier : la phrase de passe et la clé. Examinons cet exemple : vous stockez votre fichier chiffré sur une carte mémoire flash et vous le protégez par phrase de passe. De plus, vous protégez le fichier avec un fichier clé et stockez la clé sur les ordinateurs utilisés pour ouvrir le fichier. Si la carte mémoire flash est perdue, la phrase de passe ne suffira pas pour déchiffrer vos informations. Le fichier clé est aussi exigé, et il n’est pas sur la carte mémoire flash.

<div id="when-can-i-not"></div>

## Quand ne puis-je pas utiliser EncryptPad ?

* Vous devez envoyer un fichier à quelqu’un avec qui vous **n’avez pas prédéterminé un secret partagé** (une phrase de passe ou un fichier clé). Dans ce cas, il vous faut un chiffrement asymétrique avec des clés publique et privée. Heureusement, de nombreux outils pratiques sont adaptés à la tâche. 

* Vous êtes dans un transport en commun ou dans un espace public où **quelqu’un peut voir votre écran**.

*  EncryptPad est inefficace sur un ordinateur infecté par un logiciel espion ou un virus. Ne l’utilisez pas sur un **ordinateur public, partagé ou compromis** si vous n’avez pas confiance en sa sécurité.

* **IMPORTANT** : avant d’utiliser EncryptPad, vous devez vous assurer qu’il est légal d’utiliser dans votre pays les techniques de chiffrement fournies par EncryptPad. Vous trouverez des informations pertinentes sur [cryptolaw.org](http://www.cryptolaw.org/).

* **IMPORTANT** : si vous avez oublié votre phrase de passe ou si vous avez perdu un fichier clé, rien ne peut être fait pour accéder à vos informations chiffrées. Il n’y a aucune porte dérobée dans les formats qu’EncryptPad prend en charge. Les développeurs d’EncryptPad n’assument aucune responsabilité en cas de fichiers corrompus ou invalides, conformément à la licence.

<div id="file-types"></div>

## Types de fichiers

Le format est déterminé par l’extension du fichier. Les principales extensions des fichiers chiffrés sont GPG et EPD.

<div id="gpg"></div>

### GPG

Ce type de fichier se conforme au format OpenPGP et est compatible avec les autres outils OpenPGP. Utilisez-le si vous devez ouvrir un fichier où vous ne disposez pas d’EncryptPad. Le format ne prend pas en charge la protection double (fichier clé + phrase de passe). Vous devez donc choisir entre un fichier clé et une phrase de passe, mais ne pouvez pas utiliser les deux. De plus, il ne peut pas enregistrer le chemin du fichier clé dans le fichier chiffré. Cela signifie que chaque fois que vous ouvrirez un fichier chiffré avec un fichier clé, l’application vous demandera quel fichier clé utiliser.

<div id="epd"></div>

### EPD

Format propre à EncryptPad. Les autres logiciels OpenPGP ne pourront pas l’ouvrir à moins que le fichier n’ait été protégé que par une phrase de passe. Si seule la protection par phrase de passe a été utilisée, le fichier est en fait un fichier GPG (voir la section GPG ci-dessus). Cependant, si la protection par fichier clé est utilisée, c’est un fichier GPG dans un conteneur [WAD](https://fr.wikipedia.org/wiki/.wad). Consulter le chapitre suivant pour plus de détails.

<div id="feature-support"></div>

### Prise en charge des fonctions

<table style="border: 1px solid black">
<tr>
<th>Type</th><th>Caractéristique</th><th>Prise en charge</th><th>Chemin du fichier clé\*</th><th>Compatible OpenPGP</th><th>Format de fichier</th>
</tr>
<tr><td>GPG</td><td>Phrase de passe</td><td>oui</td><td>n.d.</td><td>oui</td><td>Fichier OpenPGP</td></tr>
<tr><td>GPG</td><td>Fichier clé</td><td>oui</td><td>non</td><td>oui</td><td>Fichier OpenPGP</td></tr>
<tr><td>GPG</td><td>Fichier clé et phrase de passe</td><td>non</td><td>n.d.</td><td>n.d.</td><td>n.d.</td></tr>
<tr><td>EPD</td><td>Phrase de passe</td><td>oui</td><td>n.d.</td><td>oui</td><td>Fichier OpenPGP</td></tr>
<tr><td>EPD</td><td>Fichier clé</td><td>oui</td><td>oui</td><td>non</td><td>Imbriqué : WAD/OpenPGP</td></tr>
<tr><td>EPD</td><td>Fichier clé et phrase de passe</td><td>oui</td><td>oui</td><td>non</td><td>Imbriqué : OpenPGP/WAD/OpenPGP</td></tr>
</table>

\*  L’emplacement du fichier clé se trouve dans l’en-tête d’un fichier chiffré afin que l’utilisateur n’ait pas à l’indiquer lors du déchiffrement.

<div id="key-file"></div>

## Qu’est-ce qu’un fichier clé EncryptPad ?
Dans un chiffrement symétrique, la même séquence est utilisée pour chiffrer et pour déchiffrer les données. L’utilisateur ou une autre
application fournit habituellement la séquence sous la forme d’une phrase de passe saisie ou d’un fichier. En plus des
phrases de passe saisies, EncryptPad génère des fichiers avec des séquences aléatoires appelés « fichiers clés ».

Quand l’utilisateur crée un fichier clé, EncryptPad génère une séquence aléatoire d’octets, demande une
phrase de passe à l’utilisateur, chiffre la séquence générée et l’enregistre dans un fichier.

Le format du fichier est OpenPGP. D’autres applications OpenPGP peuvent aussi créer et 
ouvrir les fichiers clés EncryptPad comme les lignes de commande ci-dessous le démontrent.

Quand EncryptPad génère un nouveau fichier clé, il est approximativement équivalent à la commande `gpg2` suivante.

    pwmake 1024 | gpg2 -c --armor --cipher-algo AES256 > ~/.encryptpad/foo.key

`pwmake` génère une séquence aléatoire que `gpg2` chiffre à son tour. Il demandera la
phrase de passe pour chiffrer la séquence.

Quand vous utilisez cette clé pour chiffrer `test3.txt`, la commande `gpg` équivalente est comme suit :

    gpg2 --decrypt ~/.encryptpad/foo.key \
    | gpg2 --passphrase-fd 0 --batch -c --cipher-algo AES256 \
    -o /tmp/test3.txt.gpg /tmp/test3.txt

Le premier processus `gpg2` déchiffre `foo.key` et le dirige vers le descripteur 0 du second processus
par un opérateur de transfert de données . `gpg2` lit la séquence du descripteur avec `--passphrase-fd 0`.

Quand EncryptPad ouvre le fichier chiffré protégé avec `foo.key`, les commandes `gpg` équivalentes sont

    gpg2 --decrypt ~/.encryptpad/foo.key \
    | gpg2 --passphrase-fd 0 --batch --decrypt \
    -o /tmp/test4.txt /tmp/test3.txt.gpg

Comme vous pouvez le voir, les autres applications OpenPGP peuvent aussi utiliser les clés EncryptPad.

<div id="epd-file-format"></div>

## Format EPD lors d’un chiffrement avec clé

Un fichier enregistré peut avoir trois structures différentes selon le mode de protection :

1. **Phrase de passe seulement** (une phrase de passe est utilisée pour protéger un fichier, mais aucune clé n’est spécifiée). Le fichier est un fichier OpenPGP ordinaire.

2. **Clé seulement** (une phrase de passe n’est pas définie, mais un fichier clé est utilisé pour la protection). Le fichier est un fichier WAD. [WAD](https://fr.wikipedia.org/wiki/.wad) est un format simple qui combine plusieurs fichiers binaires en un seul. Vous pouvez ouvrir un fichier WAD avec [Slade](http://slade.mancubus.net/). Il contient deux fichiers : 
    * Fichier OpenPGP chiffré avec la clé
    * `__X2_KEY` est un fichier texte en clair contenant le chemin de la clé si l’option « Emplacement de clé persistante dans le fichier chiffré » est activée. Sinon, il a une taille de zéro.

3. **Protégé par phrase de passe et clé**. Le fichier produit est un fichier OpenPGP contenant un fichier WAD tel que décrit en 2.

<div id="use-curl"></div>

## Utiliser CURL pour télécharger automatiquement des clés d’un stockage distant

Si une URL **[CURL](http://curl.haxx.se/) est précisée dans le champ **Chemin du fichier clé** de la boîte de dialogue **Définir une clé de chiffrement**, EncryptPad essaiera de lancer un processus curl pour télécharger la clé à partir d’un hôte distant. Si vous souhaitez utiliser cette fonction, vous devez définir le chemin de l’exécutable CURL dans les paramètres d’EncryptPad. 

Examinons un scénario d’utilisation : en voyage, vous ouvrez un fichier chiffré sur votre ordinateur portable. Si vous protégez le fichier avec une phrase de passe et une clé, et que votre portable est perdu ou volé, le malfaiteur pourra attaquer votre fichier par force brute, car la clé est aussi stockée sur l’ordinateur portable. Pour empêcher cela, EncryptPad prend les mesures suivantes :

1. Chiffre le fichier texte en clair avec la clé
2. Copie le fichier chiffré dans un fichier WAD avec l’URL HTTPS ou SFTP non chiffrée vers le fichier clé contenant les paramètres d’authentification.
3. Chiffre le fichier WAD du point 2 avec la phrase de passe. 

Si le fichier tombe dans les mains d’un malfaiteur, il devra d’abord attaquer par force brute la phrase de passe afin d’obtenir l’URL de la clé et les paramètres d’authentification. Dans la mesure où une attaque par force brute prend beaucoup de temps, l’utilisateur pourra retirer la clé ou changer l’authentification afin que les paramètres précédents deviennent désuets.

<div id="known-weaknesses"></div>

## Faiblesses connues

* EncryptPad stocke du texte non chiffré en mémoire. Si un vidage de la mémoire est effectué automatiquement après un plantage du système ou de l’application, ou si une partie de la mémoire est enregistrée dans le fichier d’échange, les informations délicates se trouveront sur le disque. Il est parfois possible de configurer un système d’exploitation pour empêcher les vidages et l’utilisation d’un fichier d’échange. Il est recommandé de fermer EncryptPad quand il n’est pas utilisé.

<div id="command-line-interface"></div>

## Interface en ligne de commande

### encryptcli
<div id="command-line-encryptcli"></div>

**encryptcli** est l’exécutable pour chiffrer et déchiffrer des fichiers en ligne de commande. Lancez-le sans argument pour voir les paramètres proposés. Ci-dessous un exemple de chiffrement d’un fichier avec une clé :

    # générer une nouvelle clé et la protéger avec la phrase de passe « clé ».
    # --key-pwd-fd 0 pour lire la phrase par de la clé à partir de descripteur 0
    echo -n "clé" | encryptcli --generate-key --key-pwd-fd 0 ma_clé.key

    # chiffrer texte_en_clair.txt avec ma_clé.key créé ci-dessus.
    # La phrase de passe de la clé est envoyé par le descripteur de fichier 3
    cat texte_en_clair.txt | encryptcli -e --key-file ma_clé.key \
    --key-only --key-pwd-fd 3 -o texte_en_clair.txt.gpg 3< <(echo -n "clé")

### encryptpad
<div id="command-line-encryptpad"></div>

**encryptpad** est l’exécutable en mode graphique. Ci-dessous ses paramètres en ligne de commande :

    `--lang` – pour forcer une langue d’IUG

    `--log-file` – préciser le journal pour le diagnostic

    `--log-severity` – la sévérité du journal peut être soit : none, fatal, error, warning, info, debug ou verbose

<div id="installing"></div>

## Installer EncryptPad

<div id="portable-exe"></div>

### Exécutable portable

Des fichiers binaires portables sont proposés pour Windows et Apple. Ils peuvent être copiés sur une clé USB ou
placés sur un disque réseau.

<div id="install-on-arch"></div>

### Arch Linux

Utiliser des empreintes pour recevoir des clés gpg pour EncryptPad et Botan

    gpg --recv-key 621DAF6411E1851C4CF9A2E16211EBF1EFBADFBC
    gpg --recv-key 634BFC0CCC426C74389D89310F1CFF71A2813E85

Installer les paquets AUR ci-dessous :

– [botan-stable](https://aur.archlinux.org/packages/botan-stable/)<sup><small>AUR</small></sup>
– [encryptpad](https://aur.archlinux.org/packages/encryptpad/)<sup><small>AUR</small></sup>

`pacaur` installe `botan-stable` automatiquement comme dépendance d’`encryptpad`.

<div id="install-on-ubuntu"></div>

### Ubuntu ou Linux Mint par PPA

Il existe plusieurs PPA sur Launchpad compilés sur les serveurs de Canonical à partir des fichiers source d’EncryptPad. Utilisez les commandes ci-dessous pour installer les paquets :

    sudo add-apt-repository ppa:evpo/main
    sudo apt update
    sudo apt install encryptpad encryptcli

Pour les versions d’Ubuntu antérieures à Impish, utilisez le PPA d’Alin Andrei ci-dessous :

    sudo add-apt-repository ppa:nilarimogard/webupd8
    sudo apt update
    sudo apt install encryptpad encryptcli

<div id="compile-on-windows"></div>

## Compiler EncryptPad sous Windows

<div id="prerequisites"></div>

### Prérequis

1. [**Le cadre d’applications Qt**](http://www.qt.io/download-open-source/) fondé sur MingW 32 bits (la dernière version a été testée avec Qt 5.10.1).
2. MSYS : vous pouvez en utiliser un regroupé avec [**Git pour Windows**](http://git-scm.com/download/win). Vous utilisez probablement déjà Git.
3. Python : toute version récente fonctionnera

<div id="steps"></div>

### Étapes

1. Modifier la variable d’environnement de session **PATH** afin d’inclure l’ensemble d’outils Qt et Python. **mingw32-make**, **g++**, **qmake**, **python.exe** devraient se trouver dans le chemin de recherche globale de votre session bash Git. Personnellement, je modifie bash.bashrc et ajoute une ligne tel que `PATH=/c/Python35-32:/c/Qt/5.10.1/mingw53_32/bin:/c/Qt/Tools/mingw530_32/bin:/c/MinGW/msys/1.0/bin:/bin` afin de ne pas polluer la variable PATH à l’échelle du système.

2. Extraire les fichiers sources d’EncryptPad dans un dossier.

3. Exécuter le script **configure.py --help** pour voir les options proposées. Pour tout compiler :

    ./configure.py --cpu x86 --os mingw --static
    make

La commande configure fonctionnera toujours si vous exécutez votre console avec des privilèges d’administrateur. Si vous ne voulez pas l’exécuter en tant qu’administrateur, ajoutez `--link-method hardlink` aux options.
Si la compilation réussie, vous devriez voir l’exécutable **./bin/release/encryptpad.exe**

Prendre note que si vous voulez qu’EncryptPad fonctionne en un seul exécutable sans dll, vous devez compiler le d’applications Qt vous-même de façon statique. Cela prend quelques heures. De nombreuses instructions décrivant comment accomplir cela se trouvent sur Internet. L’article le plus populaire recommande d’utiliser un script PowerShell. Bien qu’il soit très pratique (je l’ai utilisé une fois), on ne veut pas toujours mettre à niveau son PowerShell et installer les lourdes dépendances qui viennent avec. Et donc, la fois d’après, j’ai lu le script et j’ai tout fait manuellement. Heureusement qu’il n’y avait pas trop d’étapes.

<div id="compile-on-macos"></div>

## Compiler EncryptPad sous macOS

Vous devez installer Qt 5, Python et exécuter :

    export PATH=$HOME/Qt/5.12.11/clang_64/bin/:$PATH
    ./configure.py --ldflags "-mmacosx-version-min=11.0" --cxxflags "-mmacosx-version-min=11.0"
    make

Changez le chemin de Qt et remplacez les versions minimales de macOS suivant le besoin. La commande fonctionnera sans elles, mais le résultat sera limité à la version actuelle.

<div id="compile-on-linux"></div>

## Compiler EncryptPad sous Linux

<div id="build-on-fedora"></div>

### Fedora

Installer les dépendances et outils :

    dnf install gcc make qt5-qtbase-devel gcc-c++ python libstdc++-static glibc-static botan2-devel bzip2-devel zlib-devel

Ouvrir le dossier encryptpad :

    ./configure.py
    make
    sudo make install

<div id="build-on-ubuntu"></div>

### Ubuntu

Installer les dépendances et outils :

    apt-get install qt5-default qtbase5-dev gcc g++ make python pkg-config zlib1g-dev libbotan-2-dev libbz2-dev

Ouvrir le dossier source d’Encryptpad :

    ./configure.py
    make
    sudo make install

<div id="build-on-debian"></div>

### Debian

Installer les dépendances et outils :

    apt-get install qtbase5-dev gcc g++ make python3 zlib1g-dev pkg-config libbotan-2-dev libbz2-dev

Ouvrir le dossier source d’Encryptpad :

    python3 ./configure.py
    make
    sudo make install

<div id="build-on-opensuse"></div>

### openSUSE

Installer les dépendances et outils :

    zypper install gcc gcc-c++ make python pkg-config zlib-devel libqt5-qtbase-devel libbotan-devel libbz2-devel

Ouvrir le dossier source d’Encryptpad :

    ./configure.py
    make
    sudo make install

<div id="build-on-archlinux"></div>

### Archlinux

Installer les dépendances et outils :

    pacman -S --needed base-devel
    pacman -S qt5-base python botan zlib bzip2

Ouvrir le dossier source d’Encryptpad :

    ./configure.py
    make
    sudo make install

<div id="build-on-freebsd"></div>

### FreeBSD

Installer les dépendances et outils :

    pkg install python pkgconf botan2 qt5

Ouvrir le dossier source d’Encryptpad :

    ./configure.py
    make

<div id="compiler-sous-voidlinux"></div>

### Void Linux

Installer les dépendances et outils : 
	
	sudo xbps-install base-devel qt5-devel python3 botan-devel bzip2-devel libzip-devel

Ouvrir le dossier source d’Encryptpad :

    ./configure.py
    sudo make install
	
<div id="mode-portable"></div>

## Mode portable

EncryptPad vérifie la présence d’un sous-dossier nommé `encryptpad_repository` dans le dossier de l’exécutable. S’il existe, il est utilisé pour les paramètres et les fichiers clés. Le dossier `.encryptpad` situé dans le profil de l’utilisateur est alors ignoré. L’exécutable EncryptPad et `encryptpad_repository` peuvent être copiés vers un support amovible, et ainsi être utilisés sur plusieurs ordinateurs. Il convient de noter qu’il est moins sécuritaire de conserver sur le même support amovible documents chiffrés et fichiers clés. Séparez-les si possible.

<div id="fakevim-mode"></div>

## Mode FakeVim

Le mode FakeVim vous permet de modifier les fichiers avec une interface qui ressemble à Vim.

Pour activer le mode :

1. Accéder aux Paramètres…/Préférences…
2. Cocher « Activer FakeVim » 
3. Redémarrer EncryptPad

Pour configurer FakeVim, créer et modifier le fichier à l’emplacement ci-dessous :

Linux and macOS:

    ~/.encryptpad/vimrc

<br>Sous windows, dans le dossier personnel de l'utilisateur

    _encryptpad/vimrc

Vous trouverez plus de renseignements sur l'interface FakeVim dans la [page Web de la bibliothèque FakeVim](https://github.com/hluk/FakeVim)

<div id="fakevim-input-output"></div>
### FakeVim : commandes d’entrée et de sortie

Le mode ex prend en charge des commandes de lecture et d’écriture de fichiers. Les commandes d’entrée de sortie font partie des opérations suivantes EncryptPad suivantes :

    :r <file> – Ficher > Ouvrir…

    :w – Fichier > Ouvrir

    :w <file>– Fichier > Enregistrer sous…

    :q – Fichier > Fermer

Les commandes ci-dessus peuvent aussi être combinées :

    :wq
    :wq <file>

Le registre + de Vim s’intègre au presse-papiers du système. Vous pouvez aussi ajouter la ligne ci-dessous au fichier vimrc pour intégrer le registre sans nom au presse-papiers du système.

    set clipboard=unnamedplus

<div id="passphrases-in-memory"></div>

## EncryptPad stocke-t-il les phrases de passe en mémoire pour rouvrir les fichiers ?
Après avoir été saisis, une phrase de passe et un sel aléatoire sont hachés avec un algorithme S2K. Le résultat est utilisé comme clé de chiffrement pour chiffrer ou déchiffrer le fichier. Une réserve de ces résultats S2K est générée chaque fois que l’utilisateur saisit une nouvelle phrase de passe. Cela permet d’enregistrer ou de charger plusieurs fois les fichiers protégés par cette phrase de passe sans l’avoir. La taille de la réserve peut-être changée dans la boîte de dialogue Préférences. Au moment d’écrire ceci, la dernière version a une valeur par défaut de 8. Cela signifie que vous pouvez enregistrer un fichier 8 fois avant qu’EncryptPad ne vous demande de saisir la phrase de passe de nouveau. Vous pouvez augmenter ce chiffre, mais cela aura un impact sur les performances, car les algorithmes S2K comprenant de nombreuses itérations sont lents par nature.

<div id="acknowledgements"></div>

## Remerciements

EncryptPad utilise les cadres d’applications et les bibliothèques suivants :

1. [**Cadre d’applications Qt**](http://www.qt.io/)
2. [**Botan**](http://botan.randombit.net/)
3. [**stlplus**](http://stlplus.sourceforge.net/)
5. [**Makefiles**](http://stlplus.sourceforge.net/makefiles/docs/)
4. [**zlib**](http://zlib.net/)
6. [**gtest**](http://code.google.com/p/googletest/)
7. [**Jeu d’icônes famfamfam Silk 1.3**](http://www.famfamfam.com/lab/icons/silk/)
8. [**plog**](https://github.com/SergiusTheBest/plog)
9. [**FakeVim**](https://github.com/hluk/FakeVim)

<div id="integrity-verification"></div>

## Vérification de l’intégrité d’EncryptPad

<div id="openpgp-signing"></div>

### Signature OpenPGP et autorité de certification

Tous les téléchargements associés à EncryptPad sont signés avec la clé OpenPGP suivante :

`EncryptPad (Releases) 2048R/A2813E85` 

`software@evpo.net` 

`Empreinte de la clé = 634B FC0C CC42 6C74 389D  8931 0F1C FF71 A281 3E85`

J’ai aussi un certificat de signature de code délivré par une autorité de certification (CA). Pour établir une connexion entre mon certificat CA et la clé OpenPGP ci-dessus, j’ai créé un exécutable signé avec le certificat CA contenant les empreintes et la clé OpenPGP. Vous trouverez `ca_signed_pgp_signing_instructions` dans les téléchargements. J’ai en fait créé un pont de confiance entre mon certificat CA et la clé OpenPGP.

Il y a plusieurs raisons pour lesquelles je n’ai pas simplement utilisé le certificat CA :

1. EncryptPad est fondée sur la norme OpenPGP et la promeut.
2. La signature OpenPGP est plus souple.
3. La certification CA a un coût de fonctionnement, ce qui n’est pas le cas de la signature OpenPGP.

<div id="verification-process"></div>

### Processus de vérification étape par étape

1. Télécharger les paquets et leur signature OpenPGP.
2. Importer la clé EncryptPad (Releases) dans votre trousseau GPG.
3. S’assurer que c’est bien la clé EncryptPad (Releases) valide en vérifiant son empreinte avec `ca_signed_pgp_signing_instructions`.
4. Vérifier avec GPG les signatures des fichiers téléchargés.

<div id="license"></div>

## Licence

EncryptPad est un logiciel libre et gratuit : vous pouvez le redistribuer ou le modifier
selon les conditions de la [licence générale publique GNU](http://www.gnu.org/licenses/) telle que publiée par
« Free Software Foundation », soit la version 2 de la licence, soit
toute version ultérieure (à votre gré).

EncryptPad est distribuée en espérant qu’elle sera utile,
mais SANS GARANTIE, sans même la garantie tacite de QUALITÉ
MARCHANDE ou D’ADÉQUATION À UN BUT PARTICULIER. Voir la
licence générale publique GNU pour plus de détails.

<div id="contact"></div>

## Contact et rétroaction

Si votre question concerne EncryptPad, veuillez l’envoyer à la liste de diffusion **encryptpad@googlegroups.com** reliée au [groupe public de discussion](https://groups.google.com/d/forum/encryptpad).

Gestionnaire de bogues et contributions : [github.com/evpo/EncryptPad/issues](https://github.com/evpo/EncryptPad/issues)

Pour tout autre sujet, contacter Evgeny Pokhilko **software@evpo.net**

[http://www.evpo.net/encryptpad](http://www.evpo.net/encryptpad)
