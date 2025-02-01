#include "../push_swap.h"
#include <stdlib.h>
#include <limits.h>

// Fonction de comparaison pour qsort
int compare(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// Crée un tableau trié à partir de la pile
int *sorted_array(t_list *stack, int size) {
    int *arr = malloc(size * sizeof(int));
    t_list *tmp = stack;
    for (int i = 0; i < size; i++) {
        arr[i] = tmp->value;
        tmp = tmp->next;
    }
    qsort(arr, size, sizeof(int), compare);
    return arr;
}

// Calcule le nombre de rotations pour stack_a
int calculate_rotations_a(t_list *a, int value) {
    if (!a) return 0;
    int rotations = 0;
    t_list *current = a;
    int max = INT_MIN;
    int min = INT_MAX;
    t_list *tmp = a;
    
    while (tmp) {
        if (tmp->value > max) max = tmp->value;
        if (tmp->value < min) min = tmp->value;
        tmp = tmp->next;
    }
    
    if (value < min || value > max) {
        while (current->value != min) {
            rotations++;
            current = current->next;
        }
    } else {
        while (!(current->value < value && current->next->value > value)) {
            rotations++;
            current = current->next;
        }
        rotations++;
    }
    
    if (rotations > ft_lstsize(a) / 2)
        rotations -= ft_lstsize(a);
    return rotations;
}

// Calcule le nombre de rotations pour stack_b
int calculate_rotations_b(t_list *b, int value) {
    int rotations = 0;
    t_list *current = b;
    while (current && current->value != value) {
        rotations++;
        current = current->next;
    }
    if (rotations > ft_lstsize(b) / 2)
        rotations -= ft_lstsize(b);
    return rotations;
}

// Exécute les rotations optimisées
void perform_rotations(t_list **a, t_list **b, int rot_a, int rot_b) {
    while (rot_a > 0 && rot_b > 0) {
        rr(a, b, 1);
        rot_a--;
        rot_b--;
    }
    while (rot_a < 0 && rot_b < 0) {
        rrr(a, b, 1);
        rot_a++;
        rot_b++;
    }
    while (rot_a > 0) {
        ra(a, 1);
        rot_a--;
    }
    while (rot_a < 0) {
        rra(a, 1);
        rot_a++;
    }
    while (rot_b > 0) {
        rb(b, 1);
        rot_b--;
    }
    while (rot_b < 0) {
        rrb(b, 1);
        rot_b++;
    }
}

// Phase 1: Pousse les éléments de stack_a vers stack_b par blocs
void push_chunks_to_b(t_list **a, t_list **b, int size) {
    int *sorted = sorted_array(*a, size);
    int chunk_size = (size <= 100) ? 15 : 30;
    int chunks = size / chunk_size + (size % chunk_size != 0);

    for (int i = 0; i < chunks; i++) {
        int pivot = sorted[i * chunk_size];
        int elements_pushed = 0;
        while (elements_pushed < chunk_size && *a) {
            if ((*a)->value <= pivot) {
                pb(a, b, 1);
                elements_pushed++;
            } else {
                ra(a, 1);
            }
        }
    }
    free(sorted);
}

// Phase 2: Ramène les éléments de stack_b vers stack_a de manière optimisée
void greedy_push_back_to_a(t_list **a, t_list **b) {
    while (*b) {
        t_list *current = *b;
        int min_cost = INT_MAX;
        int best_rot_a = 0;
        int best_rot_b = 0;

        while (current) {
            int rot_b = calculate_rotations_b(*b, current->value);
            int rot_a = calculate_rotations_a(*a, current->value);
            int total_cost = abs(rot_a) + abs(rot_b);

            if (total_cost < min_cost) {
                min_cost = total_cost;
                best_rot_a = rot_a;
                best_rot_b = rot_b;
            }
            current = current->next;
        }
        perform_rotations(a, b, best_rot_a, best_rot_b);
        pa(a, b, 1);
    }
}

// Algorithme principal pour les listes de taille > 5
void algo_n(t_list **a, t_list **b) {
    int size = ft_lstsize(*a);
    push_chunks_to_b(a, b, size);
    greedy_push_back_to_a(a, b);
}

