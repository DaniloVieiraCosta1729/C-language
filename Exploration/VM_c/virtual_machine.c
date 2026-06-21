#include <assert.h>
#include <stdio.h>

typedef enum {INST_PUSH, INST_POP, INST_ADD, INST_SUB, INST_PRINT} type_instruction;

typedef struct
{
    type_instruction type;
    int operand;
} instruction;

instruction program[] ={
    {.type = INST_PUSH, .operand = 1},
    {.type = INST_PUSH, .operand = 2},
    {.type = INST_PUSH, .operand = 5},
    {.type = INST_ADD},
    {.type = INST_ADD},
    {.type = INST_PRINT}
};
#define PROGRAM_SIZE (sizeof(program) / sizeof(instruction))

#define STACK_CAPACITY 2048
int stack[STACK_CAPACITY];
size_t current_stack_size = 0;

int stack_push(int value)
{
    assert(current_stack_size < STACK_CAPACITY);

    stack[current_stack_size++] = value; // atribui o valor para o current_stack_size e depois incrementa.

    return value;
}

int stack_pop()
{
    assert(current_stack_size > 0);

    return stack[--current_stack_size]; // decrementa e returna o valor nesse indice.
}

void save_program(const char * path)
{
    FILE * file = fopen(path, "wb");

    size_t bytes = fwrite(program, sizeof(instruction), PROGRAM_SIZE, file);

    fclose(file);
}

int main(int argc, char const *argv[])
{
    save_program("programa_de_computador.bin");

    for (size_t i = 0; i < PROGRAM_SIZE; i++)
    {
        switch (program[i].type)
        {
        case INST_PUSH:
            stack_push(program[i].operand);
            break;
        
        case INST_POP:
            stack_pop();
            break;

        case INST_ADD:
        {
            int x = stack_pop();
            int y = stack_pop();
            stack_push(x + y);
            break;
        };
        case INST_PRINT:
            int x = stack_pop();
            printf("%d\n", x);
            break;
        default:
            break;
        }
    }
    
    return 0;
}
