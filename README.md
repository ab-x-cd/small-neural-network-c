# Réseau de Neurones en C

Ce projet est une implémentation simple et éducative d'un réseau de neurones feed-forward écrit en langage C. Il comprend des opérations matricielles de base, un système de suivi de mémoire (`memtrack`), et une implémentation minimale d'un réseau de neurones avec une fonction d'activation ReLU dans la passe avant.

## Utilité

Ce projet sert principalement à des fins éducatives. Il permet d'apprendre :
- Les principes fondamentaux des réseaux de neurones artificiels
- L'implémentation d'opérations matricielles en C
- La gestion de la mémoire en C
- L'utilisation de CMake pour la construction de projets C

Il peut également servir de base pour des expérimentations plus avancées avec les réseaux de neurones.

## Intérêts

- **Pas de dépendances externes** : Le projet utilise uniquement la bibliothèque standard C, ce qui le rend facile à compiler et à exécuter sur n'importe quel système supportant un compilateur C.
- **Code simple et lisible** : Idéal pour comprendre les mécanismes internes des réseaux de neurones sans abstractions complexes.
- **Suivi de mémoire intégré** : Le module `memtrack` permet de surveiller l'utilisation de la mémoire, utile pour le débogage et l'optimisation.
- **Tests inclus** : Des programmes de test simples pour vérifier le bon fonctionnement des opérations matricielles.
- **Multiplateforme** : Fonctionne sous Windows, Linux et macOS.

## Prérequis

- CMake (version 3.10 ou supérieure)
- Un compilateur C (GCC, Clang, MSVC selon la plateforme)
- (Optionnel) Ninja pour des compilations plus rapides

## Installation et Construction

Le projet utilise CMake comme système de construction. Voici les instructions pour chaque plateforme :

### Linux

1. Ouvrez un terminal et naviguez vers le répertoire du projet.

2. Créez un répertoire de construction et configurez CMake :
   ```bash
   mkdir -p build
   cd build
   cmake .. -DCMAKE_BUILD_TYPE=Release
   ```

3. Compilez le projet :
   ```bash
   cmake --build . --config Release
   ```

4. Les exécutables `neural_network` et `test_matrix` seront créés dans le répertoire `build`.

### macOS

Les étapes sont identiques à Linux. Vous pouvez installer les outils nécessaires avec Homebrew :

```bash
brew install cmake
```

Puis suivez les mêmes commandes que pour Linux.

### Windows

#### Avec Visual Studio (recommandé)

1. Ouvrez une invite de commandes ou PowerShell en tant qu'administrateur.

2. Créez le répertoire de construction :
   ```cmd
   mkdir build
   cd build
   ```

3. Configurez avec CMake :
   ```cmd
   cmake .. -G "Visual Studio 17 2022" -A x64
   ```

4. Compilez :
   ```cmd
   cmake --build . --config Release
   ```

#### Avec Ninja

Si vous préférez utiliser Ninja :

1. Assurez-vous que Ninja est installé et dans le PATH.

2. Configurez et compilez :
   ```cmd
   mkdir build
   cd build
   cmake .. -G Ninja
   cmake --build . --config Release
   ```

Les exécutables `neural_network.exe` et `test_matrix.exe` seront créés dans le répertoire `build\Release` (avec Visual Studio) ou `build` (avec Ninja).

## Utilisation

Après compilation, vous pouvez exécuter les programmes :

### Programme principal (`neural_network`)

Ce programme démontre la création et l'utilisation d'un réseau de neurones simple :

- Crée un réseau avec 3 couches (3 entrées, 5 neurones cachés, 2 sorties)
- Affiche l'utilisation de la mémoire avant et après l'allocation
- Libère la mémoire

Exécution :
```bash
# Linux/macOS
./neural_network

# Windows
.\neural_network.exe
```

### Tests des matrices (`test_matrix`)

Ce programme teste les opérations d'addition et de multiplication de matrices :

Exécution :
```bash
# Linux/macOS
./test_matrix

# Windows
.\test_matrix.exe
```

Le programme affiche "PASSED" ou "FAILED" pour chaque test.

## Structure du Projet

- `include/` : Fichiers d'en-tête (.h)
  - `matrix.h` : Définitions pour les opérations matricielles
  - `memtrack.h` : Suivi de l'utilisation mémoire
  - `network.h` : Structures du réseau de neurones
- `src/` : Code source (.c)
  - `main.c` : Programme principal de démonstration
  - `matrix.c` : Implémentation des opérations matricielles
  - `memtrack.c` : Implémentation du suivi mémoire
  - `network.c` : Implémentation du réseau de neurones
- `tests/` : Programmes de test
  - `test_matrix.c` : Tests des opérations matricielles
- `CMakeLists.txt` : Configuration CMake

## Notes Techniques

- Le module `memtrack` encapsule les allocations mémoire pour les matrices, mais le réseau utilise `malloc`/`free` standard. Pour un suivi complet, il faudrait adapter le code du réseau.
- Les opérations matricielles incluent une vérification basique des dimensions, mais ne gèrent pas les erreurs de manière robuste.
- La fonction d'activation utilisée est ReLU (Rectified Linear Unit).
- Les poids sont initialisés avec de petites valeurs aléatoires.

## Contribution

Les contributions sont les bienvenues ! N'hésitez pas à :
- Ouvrir des issues pour signaler des bugs ou proposer des améliorations
- Soumettre des pull requests pour ajouter des fonctionnalités
- Améliorer la documentation

## Licence

Ce projet n'inclut pas de fichier de licence. Si vous souhaitez utiliser ce code, veuillez ajouter une licence appropriée.

---

Petit projet éducatif d'implémentation de réseau de neurones en C.