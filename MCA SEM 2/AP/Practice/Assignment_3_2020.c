#include<stdio.h>
#include<conio.h>
#include<stdlib.h>

/* Function Declaration */
void heap_sorting( int[], int );
void heapify( int [], int, int );
void merged_ascending(int [], int [], int , int );
void merged_descending(int [], int [], int , int );

/* Main using command line arguments*/
void main( int argc, char *argv[] )
{
    int values_file_1[20], values_file_2[20], i = 0 , number, length1 = 0, length2 = 0;

    FILE *file1 = fopen(argv[1], "r"); //open file1 in read mode
    FILE *file2 = fopen(argv[2], "r"); //open file2 in read mode

    if(file1 && file2)  // check whether both file1 & file2 open successfully 
    {
        // scan until the end of file
        while(fscanf(file1, "%d", &number) > 0) 
        {
            values_file_1[i] = number; // store every line into array
            i++;
        }
        length1 = i;    // store length of the array for file1
        fclose(file1);  //close the txt file1

        i = 0; // reset the i value to zero 

        // scan until the end of file
        while(fscanf(file2, "%d", &number) > 0) 
        {
            values_file_2[i] = number;  // store every line into array
            i++;
        }
        length2 = i;     // store length of the array for file2
        fclose(file2);  //close the txt file2
    }
    // this part run when files failed to open or not found
    else{
        puts ("Unable to Open Files");
        exit(0);
    }
   
    //sorting the array using heap sort
    heap_sorting( values_file_1, length1 ); 
    heap_sorting( values_file_2, length2 );

    merged_ascending(values_file_1,values_file_2,length1,length2);
    merged_descending(values_file_1,values_file_2,length1,length2);

    getch();
}

// will swap two values
void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// heap sorting technique
void heap_sorting(int arr[], int n) 
{
    int i;
    for ( i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }
  
    for ( i = n - 1; i >= 0; i--) 
    {
        swap(&arr[0], &arr[i]);
        heapify(arr, i, 0);
    }
}

// heapify algorithm for heap sort
void heapify(int arr[], int n, int i) 
{
    int largest = i, left = 2 * i + 1, right = 2 * i + 2;
  
    if (left < n && arr[left] > arr[largest])
    {
        largest = left;
    }
      
    if (right < n && arr[right] > arr[largest])
    {
        largest = right;
    }
  
    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        heapify(arr, n, largest);
    }
}

// merge both the file elements into ascending order into final output file
void merged_ascending(int values_file_1[], int values_file_2[], int length1, int length2)
{
    int i = 0, j = 0;
    FILE * fp;
    fp = fopen ("patel_sortedlist_ascending.txt","w");
    for( i = 0; i < length1 && j < length2; i++ )
    {
        if( values_file_1[i] < values_file_2[j] )
        {
            fprintf (fp, "%d\n",values_file_1[i]);
        }
        else
        {
            fprintf (fp, "%d\n",values_file_2[j]);
            j++;
            i--;
        }
    }
    while( i != length1 )
    {
        fprintf (fp, "%d\n",values_file_1[i]);
        i++;
    }

	while( j != length2 )
	{
		fprintf (fp, "%d\n",values_file_1[i]);
        j++;
	}
    fclose(fp);
}


// merge both the file elements into descending order into final output file
void merged_descending(int values_file_1[], int values_file_2[], int length1, int length2)
{
    int i, j = length2 - 1;
    FILE * fp;
    fp = fopen ("patel_sortedlist_descending.txt","w");
    for( i = length1 - 1; i >= 0  && j >= 0 ; i-- )
    {
        if( values_file_1[i] > values_file_2[j] )
        {
            fprintf (fp, "%d\n",values_file_1[i]);
        }
        else
        {
            fprintf (fp, "%d\n",values_file_2[j]);
            j--;
            i++;
        }
    }
    while( i != -1 )
    {
        fprintf (fp, "%d\n",values_file_1[i]);
        i--;
    }

	while( j != -1 )
	{
		fprintf (fp, "%d\n",values_file_1[i]);
        j--;
	}
    fclose(fp);
}