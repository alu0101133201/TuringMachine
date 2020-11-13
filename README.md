# Turing Machine
### Práctica 02 - Complejidad computacional 
###### Sergio Guerra Arencibia - ULL
###### 13/11/2020
  
Este repositorio contiene la implementación de una máquina de turing multicinta.

Definición  
```  
Una máquina de Turing es un dispositivo que manipula símbolos sobre una tira de cinta de acuerdo con una tabla de reglas. 
A pesar de su simplicidad, una máquina de Turing puede ser adaptada para simular la lógica de cualquier algoritmo de computador 
y es particularmente útil en la explicación de las funciones de una CPU dentro de un computador.  
Originalmente fue definida por el matemático inglés Alan Turing como una «máquina automática» en 1936 en la revista Proceedings of the London Mathematical Societynota. 
La máquina de Turing no está diseñada como una tecnología de computación práctica, sino como un dispositivo hipotético que representa una máquina de computación. 
Las máquinas de Turing ayudan a los científicos a entender los límites del cálculo mecánico.  
```  
En palabras del propio Alan Turing...
```
[...] una ilimitada capacidad de memoria obtenida en la forma de una cinta infinita marcada con cuadrados, en cada uno de los cuales podría 
imprimirse un símbolo. En cualquier momento hay un símbolo en la máquina; llamado el símbolo leído. La máquina puede alterar el símbolo 
leído y su comportamiento está en parte determinado por ese símbolo, pero los símbolos en otros lugares de la cinta no afectan el comportamiento 
de la máquina. Sin embargo, la cinta se puede mover hacia adelante y hacia atrás a través de la máquina, siendo esto una de las operaciones 
elementales de la máquina. Por lo tanto cualquier símbolo en la cinta puede tener finalmente una oportunidad.
```
La implementación se ha realizado en el lenguaje C++.  
La orientación a objetos utilizada consta de tres clases diferentes. La que está en un nivel más bajo (no usa ninguna de 
las otras dos) es la clase transición. Esta clase representa una transición simple entre dos estados de la MT.  
Después tenemos la clase estado, que es un objeto con un identificador y un conjunto de transiciones.  
También tenemos una clase cinta, que implementa el componente de cintas de la máquina de turing, pudiendo ser esta multicinta.  
Y por último tenemos una clase máquina de turing que implementa la funcionalidad del modelo de cómputo.

### Referencias  
[wikipedia](https://es.wikipedia.org/wiki/M%C3%A1quina_de_Turing)  
[video explicativo](https://www.youtube.com/watch?v=dNRDvLACg5Q&ab_channel=Computerphile)
