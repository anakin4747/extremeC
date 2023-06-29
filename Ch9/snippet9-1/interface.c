
typedef enum { SWEET, SOUR } taste_t;

// Function pointer type
typedef taste_t (*get_taste_func_t)(void*);

typedef struct {
    // Pointer to the definition of a virtual function
    get_taste_func_t get_taste_func;
} eatable_t;

eatable_t* eatable_new(){
    /* Do something idk */
}

void eatable_ctor(eatable_t* eatable){
    // We do not have any default definition for the virtual function
    eatable->get_taste_func = NULL;
}

// Virtual behaviour function
taste_t eatable_get_taste(eatable_t* eatable){
    return eatable->get_taste_func(eatable);
}