#ifndef SYMBOLESTABLE_H
#define SYMBOLESTABLE_H

#include "variable.h"
#include "Expression.h"

class Symboletable : public Variable
{
    public:
        Symboletable();
        virtual ~Symboletable();

        int hashf(char id); // hash function
        bool insert(char id, float value);
        char find(char id);
        bool deleteRecord(char id);
        bool modify(char id, float value);

        Variable * list[100];
    private:
};

#endif // SYMBOLESTABLE_H
