public class Quicksort {
    public static void swap(int arr[] , int i,int j){
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    static int partition(int arr[],int low,int high){

        int pivot = arr[low];
        int leftptr = low;
        int rightptr = high;

        while(leftptr<=rightptr){

            while(leftptr<=high && arr[leftptr]<=pivot){
                leftptr++;
            }
            while(rightptr>=low && arr[rightptr]>pivot){
                rightptr--;
            }
            if(leftptr<rightptr){
                swap(arr,leftptr,rightptr);


            }
        }

        swap(arr,low,rightptr);


        return rightptr;

    }
    static void quickSort(int arr[],int low,int high){
        if(low<high){
            int pivotidx = partition(arr,low,high);
            quickSort(arr, low, pivotidx-1);
            quickSort(arr, pivotidx+1, high);

        }
    }
    public static void main(String[] args){

        int arr[] = {4,6,2,5,7,9,1,3};
        quickSort(arr,0,7);

        for(int i=0;i<arr.length;i++){
            System.err.print(arr[i]+ " ");
        }
    }
    
}
