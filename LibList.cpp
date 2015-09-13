/*   DwyaneTalk@gmail.com
*   by lutao
*/
struct ListNode {
    int val;
    ListNode *next;
};
typedef struct ListNode ListNode;

ListNode *initList(int arr[], int num) {
    if (num == 0)    return NULL;
    ListNode *l = (ListNode*)malloc(sizeof(ListNode));
    l->val = arr[0];
    l->next = NULL;
    ListNode *tmp = l;
    int i;
    for (i = 1; i < num; i++) {
        tmp->next = (ListNode*)malloc(sizeof(ListNode));
        tmp->next->val = arr[i];
        tmp->next->next = NULL;
        tmp = tmp->next;
    }
    return l;
}

void printfList(ListNode *l) {
    ListNode *ll = l;
    while (ll) {
        printf("%d  ", ll->val);
        ll = ll->next;
    }
    printf("\n");
}