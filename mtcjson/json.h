#pragma once
#include"listas.h"


/**
 * @author Mtcraf22
 * @brief Esta libreria permite cargar objectos de un fichero json en estructuras de c.
 *   
 */


/**
 * @brief Estas macros indican el modo de añadir los ojectos JSON a un archivo 
 * usa APPEND para añadir objectos o REPLACE para replazar los objectos viejos
 * por nuevos
 * 
 */
#define APPEND 0
#define REPLACE 1


/**
 * @brief Estructura para parsear estructuras de tipo JSON
 * que son: leer objetos de un fichero .json o escribir en un fichero .json.
 * La estructura dispone de un bufer, que es una lista enlaçada, 
 * Para guardar objectos JSON en formato clave-valor.
 * 
 * 
 * Esta estructura funciona como un objecto, como una classe de python.
 * Por lo tanto hay que instaciar desde el  su  constructor.
 * 
 * @param ojb Bufer para guardar los objectos JSON rescatados de un fichero. 
 * Este bufer es dinamico, por lo tanto utiliza memoria dinamica.
 * @param get Metodo para rescatar informacion JSON de un fichero
 * @param dump Metodo para pushear informacion JSON a un fichero
 * @param to_str Convierte el bufer JSON en una cadena de texto
 * 
 */
typedef struct json
{
    Lista obj;
    Lista (*get)(struct json,char *);
    void(*dump)(struct json,char *,int);
    char*(*to_str)(struct json);
}Json_T;

/**
 * @brief Rescata todos los objectos JSON desde un fichero
 * 
 * @param json instacia de la structura Json_T
 * @param fichero Ruta del fichero a leer
 */
Lista JSON_get_all(Json_T json,char * fichero);
/**
 * @brief 
 * 
 * @param json 
 * @param fichero 
 * @param mode 
 */
void JSON_dump(Json_T json,char * fichero,int mode);
/**
 * @brief 
 * 
 * @param json 
 * @return char* 
 */
char* JSON_2_STRING(Json_T json);
/**
 * @brief 
 * 
 * @param nombre 
 * @param propiedad 
 * @return Pares 
 */
char* buscar_par(char* nombre, char* propiedad);
/**
 * @brief Constructor de los objectos tipo Json_T
 * 
 * @return Json_T 
 */

Json_T Json_parser();
/**
 * @brief Libera la distacia ya que el bufer obj es memoria dinamica
 * 
 * @param instace 
 */
void Desctructor_Json_parser(Json_T *instace);
