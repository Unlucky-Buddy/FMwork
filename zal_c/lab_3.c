#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#define dequeN 10


struct Deque {
    int data[dequeN];
    int last;
};

int dequeIsEmpty(struct Deque *d) {
    if (d->last == 0) { return 1; }
    else { return 0; }
}

void addInStart(struct Deque* d) {
    if (d->last == dequeN) {
        printf("\nНет мест, дек заполнен\n\n");
        return;
    }
    printf("\nЗначение > ");
    int valueNewItem = 0;
    scanf_s("%d", valueNewItem);
    for (int i = d->last; i > 0; i--) {
        d->data[i] = d->data[i - 1];
    }
    d->data[0] = valueNewItem;
    d->last++;
    printf("\nЭлемент добавлен\n\n");
    
}
void addInEnd(struct Deque* d) {
    if (d->last == dequeN) {
        printf("\nЗначение > ");
        return;
    }
    printf("\nЗначение > ");
    int valueNewItem = 0;
    scanf_s("%d", valueNewItem);
    d->data[d->last++] = valueNewItem;
    printf("\nЭлемент добавлен\n\n");
}
void deleteFromStart(struct Deque* d) {
    if (dequeIsEmpty(d) == 1) { printf("Нельзя удалить, дек пустой\n\n"); }
    else {
        for (int i = 0; i < d->last; i++) {
            d->data[i] = d->data[i + 1];
        }
        d->last--;
        printf("\nЭлемент удален\n\n");
    }
}
void deleteFromEnd(struct Deque* d) {
    if (dequeIsEmpty(d) == 1) { printf("Нельзя удалить, дек пустой\n\n"); }
    else {
        d->last--;
        printf("\nЭлемент удален\n\n");
    }
}

void readDeque(struct Deque* d)
{
    if (dequeIsEmpty(d) == 1) { printf("Дек пустой\n\n"); }
    else {
        for (int i = 0; i < d->last; i++) {
            printf("\n%d.\t%d", i, d->data[i]);
        }
        printf("\n\n\n");
    }
}
int main() {
    setlocale(LC_ALL, "Rus");

    printf("Petuhova Daria Ivanovna\n");
    //Petuhova Daria Ivanovna

    

    struct Deque deque;
    struct Deque *d = &deque;
    d->last = 0;
    int doNumber = 5;
    int* dn = &doNumber;
    while (doNumber != '0') {
        
        printf("0. Exit\n");
        printf("1. Добавить в начало\n");
        printf("2. Добавить в конец\n");
        printf("3. Удалить с начала\n");
        printf("4. Удалить с конца\n");
        printf("5. Вывести дек\n");
        

        scanf_s("%d", &doNumber);

        switch (doNumber)
        {
        case 0:
            break;
        case 1:
            addInStart(d);
            break;
        case 2:
            addInEnd(d);
            break;
        case 3:
            deleteFromStart(d);
            break;
        case 4:
            deleteFromEnd(d);
            break;
        case 5:
            readDeque(d);
            break;
        default:
            printf("Вы не выбрали действие\n\n");
            break;
        }
    }
}
