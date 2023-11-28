#include <stdio.h>
#include <stdlib.h>

/* Define the structure for a singly linked list node */
struct listint_s {
    int n;
    struct listint_s *next;
};

typedef struct listint_s listint_t;

/**
 * check_cycle - Check if a singly linked list has a cycle.
 * @list: A pointer to the head of the linked list.
 *
 * Return: 0 if there is no cycle, 1 if there is a cycle.
 */
int check_cycle(listint_t *list) {
    listint_t *tortoise, *hare;

    /* Check for an empty list */
    if (list == NULL)
        return (0);

    tortoise = hare = list;

    /* Traverse the list using tortoise and hare pointers */
    while (hare != NULL && hare->next != NULL) {
        tortoise = tortoise->next;
        hare = hare->next->next;

        /* If the pointers meet, there is a cycle */
        if (tortoise == hare)
            return (1);
    }

    /* If hare reaches the end of the list, there is no cycle */
    return (0);
}

/* Example usage */
int main(void) {
    /* Create a linked list with a cycle */
    listint_t *head, *node1, *node2;

    head = malloc(sizeof(listint_t));
    node1 = malloc(sizeof(listint_t));
    node2 = malloc(sizeof(listint_t));

    if (head == NULL || node1 == NULL || node2 == NULL) {
        perror("Error: Unable to allocate memory");
        return (1);
    }

    head->n = 1;
    head->next = node1;

    node1->n = 2;
    node1->next = node2;

    node2->n = 3;
    node2->next = head;  /* Creating a cycle */

    /* Check if there is a cycle */
    if (check_cycle(head))
        printf("There is a cycle in the linked list.\n");
    else
        printf("There is no cycle in the linked list.\n");

    /* Free allocated memory */
    free(head);
    free(node1);
    free(node2);

    return (0);
}
