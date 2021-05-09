#include "symboletable.h"
#include <iostream>

using namespace std;

// Create empty table
Symboletable::Symboletable()
{
    for (int i = 0; i < 100; i++)
    { list[i] = NULL;}
}

Symboletable::~Symboletable()
{
    //dtor
}

// Function to insert an _csteV
bool Symboletable::insert(char id, float value)
{
    int index = hashf(id);
    Variable* p = new Variable(id, value);

    if (list[index] == NULL) {
        list[index] = p;
        return true;
    }

    else {
        Variable* start = list[index];
        while (start->next != NULL)
            start = start->next;

        start->next = p;


        return true;
    }

    return false;
}

// Function to modify an id
bool Symboletable::modify(char id, float expectedValue)
{
    int index = hashf(id);
    Variable* start = list[index];

    if (start == NULL)
        return "-1";

    while (start != NULL) {
        if (start->getCsteV() == id) {
            start->setValeur(expectedValue);
            return true;
        }
        start = start->next;
    }

    return false; //not found
}

// Function to delete an id
bool Symboletable::deleteRecord(char id)
{
    int index = hashf(id);
    Variable* tmp = list[index];
    Variable* par = list[index];

    // no _csteV is present at that index
    if (tmp == NULL) {
        return false;
    }
    // only one _csteV is present
    if (tmp->getCsteV() == id && tmp->next == NULL) {
        tmp->next = NULL;
        delete tmp;
        return true;
    }

    while (tmp->getCsteV() != id && tmp->next != NULL) {
        par = tmp;
        tmp = tmp->next;
    }
    if (tmp->getCsteV() == id && tmp->next != NULL) {
        par->next = tmp->next;
        tmp->next = NULL;
        delete tmp;
        return true;
    }

    // delete at the end
    else {
        par->next = NULL;
        tmp->next = NULL;
        delete tmp;
        return true;
    }
    return false;
}

// Function to check existence of an id
char Symboletable::find(char id)
{
    int index = hashf(id);
    Variable* start = list[index];

    if (start == NULL)
        return -1;

    while (start != NULL) {

        if (start->getCsteV() == id) {
            cout << "Found " << id;
            return true;
        }

        start = start->next;
    }

    return -1; // not found
}

int Symboletable::hashf(char id)
{
    int asciiSum = 0;

    for (int i = 0; i < id; i++) {
        asciiSum = asciiSum + id;
    }

    return (asciiSum % 100);
}
