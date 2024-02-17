#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct KeyValue{
    int key;
    int value;
    int filled;
};

struct KeyValue hashTable[SIZE];

void initHashTable(){
    for (int i = 0; i < SIZE; i++)
    {
        hashTable[i].filled = 0;
    }
}

int hash(int key){
    return key % SIZE;
}

void insert(int key, int value){
    int index = hash(key);
    while (hashTable[index].filled){
        index = (index + 1) % SIZE; 
    }
    hashTable[index].key = key;
    hashTable[index].value = value;
    hashTable[index].filled = 1;
}

int search(int key)
{
    int index = hash(key);
    int originalIndex = index;
    while (hashTable[index].filled){
        if (hashTable[index].key == key){
            return hashTable[index].value;
        }
        index = (index + 1) % SIZE; 
        if (index == originalIndex){
            break; 
        }
    }
    return -1;
}

void display()
{
    printf("Hash Table:\n");
    for (int i = 0; i < SIZE; i++){
        if (hashTable[i].filled){
            printf("Index %d: Key=%d, Value=%d\n", i, hashTable[i].key, hashTable[i].value);
        }
        else{
            printf("Index %d: NULL\n", i);
        }
    }
}

int main()
{
    initHashTable();
    insert(1, 10);
    insert(11, 20);
    insert(21, 30);
    insert(31, 40);
    insert(2, 50);
    display();
    int keyToSearch = 31;
    int value = search(keyToSearch);
    if (value != -1){
        printf("Value for key %d is %d\n", keyToSearch, value);
    }
    else{
        printf("Key %d not found\n", keyToSearch);
    }
    return 0;
}