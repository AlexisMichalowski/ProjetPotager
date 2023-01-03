# ProjetPotager
MiniInfo1 BIBS 

# Potager

Ce programme permet de simuler un environnement, le potager, représenté par un damier de 30x30 cases. Dans ce potager sont introduits des tomates, des pucerons (représentés en vert) et des coccinelles (représentées en rouge). Ces entités se déplacent et interagissent entre elles en fonction du temps : les tomates murissent, les pucerons mangent les tomates mures, les coccinelles chassent et mangent les pucerons. Les pucerons et les coccinelles ont également une espérance de vie et peuvent se reproduire.
La direction des coccinelles et des tomates est indiquée par les symboles suivants :
- vers la gauche <
- vers la droite >
- vers le haut ∧
- vers le bas ∨
- en diagonale NO ou SE \
- en diagonale NE ou SO /
Au début de la simulation, l'ensemble des tomates est mûr, on introduit 20 pucerons et 10 coccinelles. 
Le programme vous demande de choisir entre deux types d'afichage : l'affichage console ou l'affichage avec interface graphique, à l'aide de la librairie [SDL](https://www.libsdl.org).
Le programme permet également de choisir entre deux niveaux : 
- niveau 1 : les tomates et les pucerons sont présents
- niveau 2 : les tomates, les pucerons et les coccinelles sont présents

## Auteurs

- [Alexis Michalowski](https://github.com/AlexisMichalowski)
- [Rachel Foare](https://github.com/RachelFoare)


## Documentation

[SDL](https://zestedesavoir.com/tutoriels/1014/utiliser-la-sdl-en-langage-c/)


## Lancer le programme

Pour lancer le programme, saisir cette commade dans le terminal pour le compiler et l'executer

```bash
  make all
  ./main
```

