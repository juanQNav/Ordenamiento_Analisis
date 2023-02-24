//Algoritmo Insertion Sort
void insertionSort(int array[], int lenght) // recibimos al arreglo y su longitud
{
    int i, j, key; // declaramos las variables a utilizar
    
   //ciclo para recorrer los valores del arreglo, se considera que el primer elemento esta ordenado 
   for(j = 1; j < lenght; j++)
   {
    key = array[j];
    //insertar array[j] en la secuencia ordenada de A[0....j-1]
    i = j-1;
    while (i > 0 && array[i] > key)
    {
        array[i + 1] = array[i];//recorre el elemento mayor a la derecha
        i = i - 1; //decrementa el valor de i
    }
    array[i +1] = key;// inserta el nuevo elemento en su orden correcto
   }
}

//Algoritmo Selection Sort
void selectionSort(int array[], int lenght)//recibimos el arreglo y su tamaño
{
    int i, j,min, temp;//declaramos las variables a utilizar

    //ciclo para recorrer los valores del arreglo
    for(i = 0; i < lenght - 1; i++)
    {
    min = i; //consideramos que el elemento i es el minimo, guardamos la posición
            //recorremos el resto de elementos que nos quedan
        for(j =i + 1; j < lenght; j++) 
            if(array[j] < array[min]) //comprobamos que el elemento minimo sea realmente el minimo
                min = j;// en caso de que min no sea el minimo, actualizamos el minimo, guardando la posicion del nuevo
        //intercambiamos los valores
        temp = array[i];
        array[i] = array[min];
        array[min] = temp;        
    }
}
//Algoritmo Merge Sort
void merge(int array[], int low, int middle, int high) // recibimos el arreglo, el inicio, mitad y final
{
    int i, j, k;// declaramos las variables que vamos a usar en los ciclos

    // Numero de elementos en la parte izq y derecha
    int leftElements = middle - low + 1;
    int rigthElemnts = high - middle;

    //vectores izqierdo y derecho del tamaño de elemntos que le corresponde
    int leftArray[leftElements];
    int rigthArray[rigthElemnts];

    //recorremos los vectores izq y derecho, para asignar los valores que le corresponden 
    //de los vectores que queremos ordenar
    for (i = 0; i < leftElements; i++)
        leftArray[i] = array[low+i];

    for(j = 0; j < rigthElemnts; j++)
        rigthArray[j] = array[middle + 1 + j];

    //incializamos las varibles de los ciclos en cero, para volver a usarlas en los siguientes ciclos
    i = 0;
    j = 0;
    k = low; // se iguala al inicio

    //mezclamos los valores de los vectores izq y der en el vector que se recibio en la función
    while(i < leftElements && j <rigthElemnts) //i y j deben ser menores al numero de elementos izq y der
    {
        if (leftArray[i] <= rigthArray[j]){// el elemento i es menor al lemento j
            array[k] = leftArray[i];    // guardamos el elemento i en k (arreglo que recibimos en la función)
            i++;
        }else{
            array[k] = rigthArray[j]; //sino, se guarda el elemento j en k
            j++;
        }
        k++;
    }

    //estos ciclos vacian los vectores izq y derecho en caso que j y i sean menores a los elementos que 
    //hay en los vectores
    while (j < rigthElemnts)
    {
        array[k] = rigthArray[j];
        j++;
        k++;
    }
    while (i < leftElements)
    {
        array[k] = leftArray[i];
        i++;
        k++;
    }
}
void mergeSort(int array[], int low, int high)//recibimos el arreglo el inicio y el final 
{
    if(low < high){ // caso base, si el inicio es menor al final
        //dividimos el arreglo en dos partes
        int middle = low + (high - low)/2;
        mergeSort(array, low, middle); //dividimos las partes izquierdas recursivamente
        mergeSort(array, middle + 1, high); // dividimos las derechas
        merge(array,low,middle,high);// hacemos la mezcla
    }
}


//Algoritmo BubbleSort
void bubbleSort(int array[], int lenght)
{
    int i= 0,current;
    int permutation = 1;
    int actual;

    while (permutation)
    {
        permutation = 0;
        i++;
        for(current = 0; current < lenght - i; current++)
        {
            if(array[current] > array[current+1])
            {
                permutation = 1;
                //intercambio de los elmentos
                int temp = array[current];
                array[current] = array[current + 1];
                array[current + 1] = temp;
            }
        }
    }
}
//Algoritmo Quik Sort
void exchange(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
void partition(int array[], int low, int high, int *pivotpoint)//recibimos el arreglo, el inicio y el final
{
    int i, j;// declaramos las variables a usar en los ciclos
    int pivotetitem; 

    pivotetitem = array[low]; // obtenemos el valor del primer elemento del arreglo recibido
    j = low; // obtenemos la posición del primer elemento(indeice del elemento mas bajo)

    //recorrido de todos los elementos
    for(i = low + 1; i <= high; i++)
        if(array[i] < pivotetitem){ // si el elemento i es < al pivotitem (priemer elemento)
            j++;
            exchange(&array[i], &array[j]);//intercambiamos los valores en entre el elemento i y j
        }
    *pivotpoint = j; //cmabiamos el valor del pivote
    exchange(&array[low],&array[*pivotpoint]);// intercambiamos el primer elemento con el elemento pivote
}
void quickSort(int array[], int low, int high)// recibimos el arreglo, el inicio y el final
{
    int pivotpoint;//declaramos el pivote
    // Si high (el final) es mayor que low (el inicio)
    if(high > low)
    {
        //hacemos la particion del arreglo
        partition(array, low, high, &pivotpoint);
        quickSort(array, low, high - 1);//recursivamente hacemos lo msimo par la parte izquierda
        quickSort(array, pivotpoint + 1, high);// y para la derecha
    }
}

