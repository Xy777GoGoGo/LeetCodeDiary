void handle(struct Node **last, struct Node **p, struct Node **nextStart) {
    if (*last) {
        (*last)->next = *p;  //*last 记录上一个节点
    }
    if (!(*nextStart)) {
        *nextStart = *p;
    }
    *last = *p;
}

struct Node *connect(struct Node *root) {
    if (!root) {
        return NULL;
    }
    struct Node *start = root;
    while (start) {//逐层
        struct Node *last = NULL, *nextStart = NULL;
        for (struct Node *p = start; p != NULL; p = p->next) {//完成一层
            if (p->left) {
                handle(&last, &(p->left), &nextStart);
            }
            if (p->right) {
                handle(&last, &(p->right), &nextStart);
            }
        }
        start = nextStart;
    }
    return root;
}

