#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Cat {
	int age;
	char name[32];
	char color[32];
	char size[32];
	void (*print)(struct Cat*);
	void (*init)(struct Cat*, int, char*, char*, char*);
};

void Cat__print(struct Cat*);
void Cat__init(struct Cat*, int, char*, char*, char*);

void Cat__print(struct Cat* this) {
	printf("I'm a Cat named %s! I'm %d years old, %s, and %s.\n", this->name, this->age, this->size, this->color);
}

void Cat__init(struct Cat* this, int _age, char _name[32], char _color[32], char _size[32]) {
        this->age = _age;
        strcpy(this->name, _name);
        strcpy(this->color, _color);
        strcpy(this->size, _size);
        this->print = &Cat__print;
        this->init = &Cat__init;
}

int main() {
	struct Cat *cat = (struct Cat*)malloc(sizeof(struct Cat));
	Cat__init(cat, 4, "Sofie", "Brown", "Large");
	cat->print(cat);
	return 0;
}
