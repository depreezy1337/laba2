#include <stdio.h>
#include "IntVector.h"
#include <stdlib.h>
//#include <malloc.h>

IntVector* int_vector_new(size_t initial_capacity) {
	 IntVector* new_obj = (IntVector*)malloc(sizeof(IntVector));
	if (!new_obj) {
		return NULL;
	}
	new_obj->capacity = initial_capacity;
	new_obj->size = 0;
	new_obj->pointer = (int*)malloc(new_obj->capacity * sizeof(int));
	if (!new_obj->pointer) {
		free(new_obj);
			return NULL;
	}
	return new_obj;



}
 IntVector* int_vector_copy(const IntVector* v) {
	 IntVector* new_obj = int_vector_new(v->capacity);
	if (!new_obj) {
		return NULL;
	}
	new_obj->size = v->size;
	for (int i = 0; i <v->size; i++) {
		new_obj->pointer[i] = v->pointer[i];
	}
	return new_obj;
}
 
 
 void int_vector_free(IntVector* v) {
	free(v->pointer);
	free(v);
		 
 }


 int int_vector_get_item(const IntVector* v, size_t index, int* item) {
	 if (index >= v->size) {
		 return -1;
	 }
	 *item= v->pointer[index];
	 return 0;
 }


 int int_vector_set_item(IntVector* v, size_t index, int item) { //íå ìîæåò áûòü ìåíüøå íóëÿ
	 if (index >= v->size) {
		 return -1;
	 }
	 v->pointer[index] = item;
	 return 0;
 }


 size_t int_vector_get_size(const IntVector* v) {
	 return v->size;
 }

 size_t int_vector_get_capacity(const IntVector* v) {
	 return v->capacity;
 }


 int int_vector_push_back(IntVector* v, int item) {
	 if (v == NULL) {
		 return -1;
	 }
	 if (v->size == v->capacity) { // åñëè ìåñòî çàêîí÷èëîñü 
		 v->capacity==0? (v->capacity=1):(v->capacity *= 2);//îïðåäåëåíèå ¸ìêîñòè íîâîãî âåêòîðà
		 int* new_obj = (int*)realloc(v->pointer, sizeof(int) * v->capacity); 
		 if (!new_obj) {
			 v->pointer = NULL;
			 return -1;
		 }
		 v->pointer = new_obj; 
	 }	
	 v->pointer[v->size++]= item;
	  return 0;
 }


 void int_vector_pop_back(IntVector* v) {
	 if (v->size != 0) {
		 v->size--;
	}

 }


 int int_vector_shrink_to_fit(IntVector* v) {
	 if (v == NULL) {
		 return -1;
	 }
	 if (v->size == 0) {
		 free(v->pointer);
		 v->pointer = NULL;	
		 v->capacity = 0;
		 
	 }
	 else if (v->capacity > v->size) {
		 v->capacity = v->size;
		 int* new_obj = (int*)realloc(v->pointer, sizeof(int) * v->capacity);
		 if (!new_obj) {
			 v->pointer = NULL;
			 return -1;
		 }
		 v->pointer = new_obj;
		 
	 }
	 return 0;
 }



 int int_vector_resize(IntVector* v, size_t new_size) {
	 if (v == NULL) {
		 return -1;
	 }
	 if (new_size > v->size) {
		 if (new_size > v->capacity) {
			 int* new_obj = (int*)realloc(v->pointer, sizeof(int) * new_size);
			 if (!new_obj) {
				 return -1;
			 }
			 v->pointer = new_obj;
			 v->capacity = new_size;
		 }
		 for (int i = v->size; i < new_size; i++) {
			v->pointer[i] = 0;
		 }
		 v->size = new_size;
	 }
	 else if (new_size < v->size) {
		 v->size = new_size;
		return int_vector_shrink_to_fit(v);
	 }
	 return 0;
 }


 int int_vector_reserve(IntVector* v, size_t new_capacity) {
	 if (v == NULL) {
		 return -1;
	 }
	 if (new_capacity > v->capacity) {
		 v->capacity = new_capacity;
		 int* new_obj=(int*)realloc(v->pointer, sizeof(int) * new_capacity);
		 if (!new_obj) {
			 v->pointer = NULL;
			 return -1;
		 }
		 v->pointer = new_obj;
		 
	 }
	return 0;
 }
		 
