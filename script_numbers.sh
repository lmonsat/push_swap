#!/bin/bash

# Les valeurs de départ
nombres=(1 2 3 4)

# Fonction pour générer les permutations
generate_permutations() {
    if [[ $1 -eq 1 ]]; then
        echo "${nombres[*]}"
    else
        for i in $(seq 0 $(($1 - 1))); do
            generate_permutations $(($1 - 1))
            if [[ $(($1 % 2)) -eq 0 ]]; then
                temp=${nombres[$i]}
                nombres[$i]=${nombres[$(($1 - 1))]}
                nombres[$(($1 - 1))]=$temp
            else
                temp=${nombres[0]}
                nombres[0]=${nombres[$(($1 - 1))]}
                nombres[$(($1 - 1))]=$temp
            fi
        done
    fi
}

# Appeler la fonction et exécuter les commandes pour chaque permutation
generate_permutations ${#nombres[@]} | while read -r permutation; do
    ARG="$permutation"
    echo "valgrind ./push_swap $ARG"
done
