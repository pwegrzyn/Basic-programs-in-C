/*Patryk Wegrzyn
* Programowanie Imperatywne*/

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    struct Node* next;
    struct Node* prev;
    int val;
};

//--Declarations--

int empty(struct Node*);
int size(struct Node*);
void push_front(struct Node**, int);
void print(struct Node*);
struct Node* getNode(int);
void push_back(struct Node**, int);
void removeX(struct Node**, int);
void pop_front(struct Node**);
void pop_back(struct Node**);
int front(struct Node*);
int back(struct Node*);
void clear(struct Node**);

//--Main--

int main(void)
{
    //lista reperezetowana jest przez wskaznik do jej pierwszego elementu
    //w tym przypadku jest to "list"

    struct Node* list = NULL;

    push_front(&list, 4);
    push_front(&list, 2);
    push_front(&list, 8);
    push_back(&list, 2);
    push_front(&list, 25);
    push_back(&list, 2);
    push_front(&list, 2);
    push_front(&list, 2);
    //tak wyglada teraz lista: 2,2,25,8,2,4,2,2

    printf("Poczatkowa lista: \n");
    print(list);

    removeX(&list, 2);

    printf("Po usunieciu z niej wszystkich 2-jek wylgada ona tak: \n");
    print(list);

    printf("Rozmiar listy wynosi teraz: %d\n", size(list));

    printf("Back = %d\n", back(list));

    printf("Front = %d\n", front(list));

    push_front(&list, 5);
    push_back(&list, 10);

    printf("Do listy dodano na poczatek 5 oraz na koniec 10: \n");
    print(list);

    pop_front(&list);

    printf("Po usunieciu z niej poczatku: \n");
    print(list);

    pop_back(&list);

    printf("Po usunieciu z niej konca: \n");
    print(list);

    printf("Teraz usuwam calkowicie liste z pamieci.\n");

    clear(&list);

    if(empty(list)) printf("Lista jest teraz pusta.\n");
    return 0;
}

//--Defs--

struct Node* getNode(int x)     //procedura ta tworzy nowy wezel z kluczem x
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    if( ptr == NULL) return NULL;
    ptr->val = x;
    ptr->next = NULL;
    ptr->prev = NULL;
    return ptr;
};

int empty(struct Node* head)    //sprawdza czy list jest pusta
{
    return head == NULL;
}

int size(struct Node* head)     //zwraca rozmiar listy
{
    int n = 0;
    while(head!= NULL)
    {
        head = head->next;
        ++n;
    }
    return n;
}

void push_front(struct Node** head, int x)      //dodaje element na poczatek listy
{
    struct Node* newNode = getNode(x);
    if((*head) == NULL){
        (*head) = newNode;
        return;
    }
    else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
        return;
    }
}

void print(struct Node* head)          //wypisuje liste
{
    if(empty(head)) return;
    while(head != NULL)
    {
        printf("%d ", head->val);
        head = head->next;
    }
    printf("\n");
}

void push_back(struct Node** head, int x)       //wstawia element na koniec
{
    struct Node* newNode = getNode(x);
    if(*head == NULL)
    {
        *head = newNode;
        return;
    }
    else
    {
        struct Node* p = *head;
        while(p->next != NULL) p = p->next;
        p->next = newNode;
        newNode->prev = p;
        return;
    }
}

void removeX(struct Node** head, int x)     //usuwa z listy wszystkie elementy o kluczu x
{
    if(*head == NULL) return;
    while((*head)->val == x) pop_front(&(*head));
    struct Node* p = *head;
    while(p != NULL)
    {
        if(p->val == x)
        {
            p->prev->next = p->next;
            if(p->next != NULL) p->next->prev = p->prev;
            struct Node* r = p;
            p = p->next;
            free(r);
        }
        else p = p->next;
    }
    return;

}

void pop_front(struct Node** head)      //usuwa pierwszy element
{
    if(*head == NULL) return;
    struct Node* p = *head;
    *head = (*head)->next;
    if(*head != NULL) (*head)->prev = NULL;
    free(p);
}

void pop_back(struct Node** head)       //usuwa ostatnie element
{
    if(*head == NULL) return;
    struct Node* p = *head;
    while(p->next != NULL) p = p->next;
    if(p->prev != NULL) p->prev->next = NULL;
    else *head = NULL;
    free(p);
}

int front(struct Node* head)        //zwraca wartosc pierwszego elementu
{
    //funkcja przyjmuje, ze lista jest niupusta
    return head->val;
}

int back(struct Node* head)     //zwraca wartosc ostatniego elementu
{
    //funkcja ta przyjmuje, ze lista jest niepusta
    while(head->next != NULL) head = head->next;
    return head->val;
}

void clear(struct Node** head)      //usuwa liste z pamieci
{
    if(*head == NULL) return;
    while(*head != NULL)
    {
        struct Node* p = *head;
        *head = (*head)->next;
        free(p);
    }
}

