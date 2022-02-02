#include<stdio.h>
#include<stdint.h>
void main(void){

uint32_t val1 = 0xAA5500FF;
uint32_t val2 = 0x55AAFF00;
const uint32_t *ptr_to_const_val = &val1;
uint32_t * const const_ptr_to_val = &val1;
printf("first ptr const: %x\n", *ptr_to_const_val);
printf("first const ptr: %x\n", *const_ptr_to_val);

//*ptr_to_const_val += 1; //Błąd - wartość spod wskaźnika tylko do odczytu
ptr_to_const_val = &val2; //OK
*const_ptr_to_val += 1; //OK
//const_ptr_to_val = &val2; //Błąd - wskaźnik tylko do odczytu
//nie można go podmienić na inny

printf("ptr const: %x\n", *ptr_to_const_val);
printf("const ptr: %x\n", *const_ptr_to_val);

}