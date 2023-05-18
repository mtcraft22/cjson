/**
 * @file cadenes.h
 * @version 0.1
 * @date 6/5/23
 * @author mtcraft22
 */
#define OK 1;
#define WARNING 0;
#define FATAL -1;
/** 
 * @brief cad_split Like a strtok
 * @param string string to split
 * @param separator char to split the string
 * @return char** firts ocurence of separated string 
*/
char* cad_split(char* string, int separator);

/** @brief return of string slice from init to final You must free de return value
*   @param string string to make slice
*   @param init string position to star the slice
*   @param final string position to end the slice
*/
char * cad_slice(char* string, int init,int final);

/** 
* return string lenght 
*/
int cad_len(char * string);