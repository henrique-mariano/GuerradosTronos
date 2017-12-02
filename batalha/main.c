#include <stdio.h>
#include "arvore.h"
#include "lista.h"
#include "lertxt.h"
#include "escolha.h"
#include "fila.h"
#include "batalha.h"

int main(void){
    t_node* root = tree_create();
    cList* list = NULL;
    list = list_fill(list);
    cNode* aux = NULL;
    t_node* player = NULL;
    tree_character_fill(root, list, aux);
    tree_print_preorder(root);
    printf("%d\n", height(root));
    int i = escolha(list);
    t_node* enemy = character_search_tree ( (character_search( 5, list ) ), root);
    aux = character_search(i - 1, list);
    player = character_search_tree(aux, root);
    printf("%s\n", player->character->name);
    battle_finder( root, player );
    tree_print_preorder(root);
    free_list(list);
    tree_free(root);
    return 0;
}