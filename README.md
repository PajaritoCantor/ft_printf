Funciones variádicas

Las funciones variádicas permiten un número arbitrario de parámetros de tipo arbitrario.

int printf(const char* format, ...)

La signatura de una función variádica tiene como parámetro una elipsis '...' que quiere decir: Unos cuantos parámetros más de tipo desconocido

En las funciones variádicas una elipsis siempre tiene que ser el último parámetro
Los parámetros con nombre y sin valor por defecto son parámetros obligatorios

Cuando se llama a una función variádica, el compilador guarda todos los parámetros en el stack.
* El problema es ¿cómo accedemos a estos parámetros ya que no tienen nombre?...
  La solución viene por unas macros cuya implementación depende tanto de cada compilador:
  1. Define un nombre con va_list
  2. Inicializa el accceso a los parámetros anónimos con va_start
  3. Obtiene un nuevo parámetro con cada llamada a va_arg
  4. Recoge la basura con va_end
 
Funciones variádicas como printf permiten implementar funciones con un número de parámetros arbitrario de forma eficaz
* Desgraciadamente dependen de que el usuario provee una lista con los tipos de los parámetros suministrados
* Al hacerlo mal, una fución variádica puede leer o incluso escribir en la memoria de forma no controlada
* La macro va_arg simplemente devuelve un valor del tipo especificado en el segundo parámetro y mueve el puntero de lectura tantos bytes como el tamaño de este tipo

Va_list: Este tipo de dato se utiliza para acceder a los argumentos variables en funciones
  * Se utiliza una variable de tipo va_list para acceder a cada elemento de la lista de argumentos
Va_start: Esta macro permite el acceso a los argumentos de la variable después del último argumento fijo en una función
  * Se invocará va_start con una instancia válida de un objeto va_lis aantes de realizar cualquier llamada va_arg
Va_arg: Esta macro se expande a una expresión del tipo que corresponde al siguiente parámetro de la lista va_list
  * Antes de llamar a va_args, la lista va_list debe ser inicializada por una llamada a va_start o va_copy, sin ninguna llamada intermedia a va_end
Va_end: Se utiliza para realizar la limpieza
  * Después de la llamada de va_end, la variable es indefinida
