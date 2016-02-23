Chronos : libchronos
====================
# Présentation
La bibliothèque **libchronos** (programmée en C) permettra l'accès à l'information et à la modification de certains aspects du système.

Elle sera notamment capable de fournir des informations sur le matériel (**CPU**, **GPU**, **RAM**, **Carte son**) ainsi que sur les processus, elle proposera une **API** pour permettre aux développeurs de l'utiliser de manière efficace.

Son rôle sera déterminant dans la création des futurs programmes (Gestionnaire de fenêtres, de tâches, barre des tâches ...)

# Cahier des charges
> (temporaire)

1. Création de routines bas niveau permettant l'accès à l'information coté matériel. **[En cours]**
2. Création de routines bas niveau permettant l'accès à l'information côté software (processus en cours d'execution, recherche de fichiers, disque ...)
3. Intégration de D-BUS (communication inter processus) pour permettre à plusieurs programmes de communiquer

# Exemple de l'API
> (temporaire)

**CPU**
```c
	Processor *processor; // structure
	processor = getCPU(); // remplissage de la structure

	printf("CPU = \nvendor id : %s\nmodel name : %s\ncores : %d\nfamily : %d\n",
		processor->vendor_id, processor->model_name, processor->cores, processor->cpu_family);

	clear(processor); // Nettoyage mémoire allouée
```

# Compilation

**Fichier de test**
```gcc
gcc main.c src/*.c -o a
```