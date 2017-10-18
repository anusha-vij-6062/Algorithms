#include <iostream>
#include <limits>
#include <cfloat>
#include <stdlib.h>

using namespace std;

/****************************************************************
Function:      Dynamically create space for a 2D matrix
Parameters:    int rows: matrix has "rows" many rows
               int cols: matrix has "cols" number of columns
Return:        two dimentional array
****************************************************************/
int **create_Array(int rows,int cols)
{
    int **arr;
    arr=new int*[rows];
    
    
    for( int row=0; row<rows;row++)
    {
        arr[row]=new int[cols];
    }
    
    return (arr);
    
}


/*****************************************************************************
Function:      to assign values of the array with random values
Parameters:    int rows:  matrix has "rows" many rows
               int cols:  matrix has "cols" number of columns
               int **arr: pointer to a pointer where the values are to stored
Return:        the filled two dimentional array
*******************************************************************************/

int  **Fill_Array(int** arr,int rows, int cols)
{
    for(int i=0;i<rows;i++)
        for(int j=0;j<cols;j++)
            arr[i][j]=rand() % 10 +1;
    
    return arr;
    
}


/*****************************************************************************
Function:      to precomputed the summed array table of the 2D matrix
Parameters:    int rows:  matrix has "rows" many rows
               int cols:  matrix has "cols" number of columns
               int **arr: pointer to a pointer where the values are to stored
Return:        the summed array matrix
******************************************************************************/
int ** precompute(int **arr, int **SAT, int n,int m)
{
    int temp=0;
    for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
            SAT[i][j]=0;
    
    for(int i=0;i<n;i++)
    { temp=0;
        for(int j=0;j<m;j++)
        {
            for( int x=0;x<=i;x++)
                temp=temp+arr[x][j];
            
            SAT[i][j]=temp;
        }
        
        
    }
    return SAT;
}


/***********************************************************************************************************
 Function:      computes the area of the rectangle covered by the passed coordinates in O(1) time complexity
 Parameters:    int x1: x coordinates of top left corner
                int y1: y position of top left corner
                int x2: x position of bottom right corner
                int y2: y position of bottom right corner
                int **SAT: pointer to a pointer of summed area matrix
 Return:        integer value of computed area
 ************************************************************************************************************/
int ans(int x1,int y1,int x2,int y2,int** SAT)
{
    
    int A=0,B=0,C=0,D=0;
    
    if(x1==0 && y1==0)
    {
        D=SAT[x2][y2];
    }
    
    
    if(x1==0 && y1>0)
    {
        D=SAT[x2][y2];
        C=SAT[x2][y1-1];
    }
    
    if(y1==0 && x1>0)
    {
        D=SAT[x2][y2];
        B=SAT[x1-1][y2];
        
    }
    
    if(x1>0 && y1>0)
    {
        A=SAT[x1-1][y1-1];
        D=SAT[x2][y2];
        B=SAT[x1-1][y2];
        C=SAT[x2][y1-1];
        
    }
    
    
    return(D+A-B-C);
    
}

void print(int** arr,int rows,int cols)
{
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<cols;j++)
            cout<<arr[i][j]<<"\t";
        cout<<endl;
        
    }
    cout<<endl;
}






int main()
{
    int **SAT,**arr,rows,cols;
    int x1=0,y1=0,x2=0,y2=0;
    cout<<"Enter the numbers of rows and columns\n";
    cin>>rows>>cols;
    
    //Create 2 dynamic 2D arrays
    arr=create_Array(rows,cols);
    SAT=create_Array(rows,cols);
    
    //Fill the array with random values generated from 1 to 100
    arr=Fill_Array(arr,rows,cols);
    
    //Precompute the Summed Array Table of the given array
    SAT=precompute(arr,SAT,rows,cols);
    
    //Function to print
    print(arr,rows,cols);
    print(SAT,rows,cols);
    
    cout<<"Enter the top left corner\n";
    cin>>x1>>y1;
    cout<<"Enter the bottom right corner\n";
    cin>>x2>>y2;
    
    //Function call to calculate the area covered by the points given by the user
    cout<<endl<<ans(x1,y1,x2,y2,SAT)<<endl;
    
    return 0;
}
