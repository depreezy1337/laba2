#include <stdio.h>
#include "IntVector.h"
#include <stdlib.h>
#define amount 10
#define print_vector(a) printf("%s = ", #a);PRINT_vector(a);printf("size = %lld, capacity = %lld\n", int_vector_get_size(a), int_vector_get_capacity(a));

void PRINT_vector(IntVector* vector) {
	for (int i = 0; i < vector->size; i++) {
		printf("%d ", vector->pointer[i]);
	}
	printf("\n");
}

int main() {
	printf("                                          Demonstraciya realizovannih funkciy\nSozdaem massiv i zapolnyaem ego znacheniyami\n ");
	IntVector* a = int_vector_new(amount);
	a->size = amount;
	for (int i = 0; i < a->size; i++) {
		a->pointer[i] = i;
	}
	print_vector(a);
	printf("Sozdaem copiyu vectora a(int_vector_copy) \n ");
	IntVector* b = int_vector_copy(a);
	print_vector(b);
	printf("Dobavlyaem element 77 v konec vectora(int_vector_push_back) \n ");
	int_vector_push_back(b,77);
	print_vector(b);
	printf("Umenshaem capacity do size(int_vector_shrink_to_fit) \n ");
	int_vector_shrink_to_fit(b);
	print_vector(b);
	printf("Vivodim vector a \n");
	print_vector(a);
	int_vector_pop_back(a);
	printf("Udalyaem posledniy element vectora a(int_vector_pop_back) \n");
	print_vector(a);
	int_vector_reserve(a, 20);
	printf("Izmenyaem capacity vectora a(int_vector_reserve) \n");
	print_vector(a);
	int_vector_resize(a, 0);
	printf("Izmenyaem size vectora(int_vector_resize) \n");
	print_vector(a);
	int_vector_resize(a, 9);
	printf("Izmenyaem size vectora(int_vector_resize) \n");
	print_vector(a);
	int item;
	printf("Esli poluchilos schitat' element[10] vectora b(int_vector_get_item), to zapisivaem ego v konec vektora a(int_vector_set_item) \n");
	if (int_vector_get_item(b, 10, &item) == 0 && a->size > 0) {
		int_vector_set_item(a,(size_t)a->size - 1, item);
	}
	print_vector(a);
	int_vector_free(a);
	int_vector_free(a);
	//print_vector(a);
	int_vector_free(b);
	//print_vector(b);

}