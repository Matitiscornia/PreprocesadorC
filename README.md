# Preprocesador de C
 Este programa se encarga de la etapa de preprocesamiento, previa a la compilación. Su funcionamiento consiste en eliminar comentarios y encargarse de las directivas #define y #undef.

# Implementacion

+ El programa esta diseñado como una maquina de estados, puede apreciar su funcionamiento en el diagrama que esta en "Preprocess.png".  
+ Se utilizo una hash table basada en el capitulo 6.6 del libro "el lenguaje de programación c".  

# ¿Como Utilizarlo?

 Para utilizar el programa tiene que abrir una consola y posicionarse en esta carpeta, luego para generar el ejecutable pruebe ingresando "make" o "mingw32-make".  Para probar su funcionamiento escribimos "preprocess.exe < Test.c", de esta forma le pasamos como entrada el archivo de prueba, también puede testearse con cualquier texto
 con sintaxis del lenguaje C.
