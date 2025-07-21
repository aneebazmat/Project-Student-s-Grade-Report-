#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
using namespace std;

// Function Prototypes 

void getInput (int array[],int numElements);
void remove(int array[],int & numElements,int removeItem);
void display (int array[],int numElements);
void removeAll(int array[],int & numElements,int removeItem);
void readData(string &testAnswers,string studentsID[],string Response1[], string Response2[],string studentResponse[],const int num_Students);
void testScore(string &testAnswers,string studentResponse[],int studentScore[],const int num_Students);
void percentageCalculation (int studentScore[],const int totalScore,float percentage[],const int num_Students);
void gradeCalculation (float percentage[],char grade[],const int num_Students);
void displayResult(string testAnswers,string studentsID[],string studentResponse[],int studentScore[],char grade[],const int num_Students);

// 1. Function to get input array

void getInput (int array[],int numElements)
{
    for(int i=0; i<numElements; i++)
    {
        cout << "Element " << i + 1 << " : ";
        cin >> array[i];
    }

}

// 2. Function to display array

void display (int array[],int numElements)
{
    
    for(int i=0; i<numElements; i++)
    {
        cout << array[i] << " ";
    }
    
}

// 3. Function to remove item and swap elements  

void remove(int array[],int &numElements,int removeItem)
{
    int flag = 0;
    int i,j;

    for(i=0; i<numElements; i++)
    {
        if(array[i] == removeItem)
        {
            flag = 1;
            array[i] = 0;

        for(j=i; j<numElements - 1; j++)
        {
            array[j] = array[j + 1];
        }
        numElements--;
        break;  

    //   Here actually it is working like this          // array[i] = array[i + 1];
                                                        // array[i + 1] = array[i + 2];
                                                        // array[i + 2] = array[i + 3];
                                                        // array[i + 3] = array[i + 4];
        }
    
       
    }
    if (flag == 0)
    {
        cout << "Required element not found in given Array." << endl;
    }
    else 
        display(array,numElements);
}

// 4. Function to remove all pointed items from array

void removeAll(int array[],int &numElements,int removeItem)
{
    int flag = 0;
    int i,j,k,l;

    for(i=0; i<numElements; i++)
    {
        if(array[i] == removeItem)
        {
            flag = 1;
            array[i] = 0;

        for(j=i; j<numElements - 1; j++)
        {
            array[j] = array[j + 1];

            for(k=j; k<numElements - 1; k++)
            {
                 if(array[k] == removeItem)
             {
                flag = 1;
                array[k] = 0;

                for(l=k; l<numElements - 1; l++)
                {
                    array[l] = array[l + 1];
                }
                numElements--;

            }
        }
        }
        numElements--;
        break;  

    //   Here actually it is working like this          // array[i] = array[i + 1];
                                                        // array[i + 1] = array[i + 2];
                                                        // array[i + 2] = array[i + 3];
                                                        // array[i + 3] = array[i + 4];
        }
    
       
    }
    if (flag == 0)
    {
        cout << "Required element not found in given Array." << endl;
    }
    else 
        display(array,numElements);
}

// 5. Function to read Students Data from File

void readData(string &testAnswers,string studentsID[],string Response1[], string Response2[],string studentResponse[],const int num_Students)
{
   ifstream infile;
   infile.open("students.txt");
   if(!infile)
   {
    cout << "Invalid file.Please open correct file. " << endl;
   }

   getline(infile,testAnswers);

    for(int i=0; i<num_Students; i++)
    {
        infile >> studentsID[i] >> Response1[i] >> Response2[i];
        studentResponse[i] = Response1[i] + Response2[i];
    }
    infile.close();
}

// 6. Function to Calculate Score of Students Response

void testScore(string &testAnswers,string studentResponse[],int studentScore[],const int num_Students)
{
    
    for(int i=0; i<num_Students; i++)
    {
        int correct = 0;
        int wrong = 0;
    
        for(int j=0; j<testAnswers.length(); j++)
       {
            if(studentResponse[i][j] == testAnswers[j])
            {
                correct++;
            }
            else
            {
                wrong++;
            }
       }
           studentScore[i] = (2 * correct) - (1 * wrong);   
    }
  
}

// 7. Function to claculate students percentage

void percentageCalculation (int studentScore[],const int totalScore,float percentage[],const int num_Students)
{
    for (int i=0; i<num_Students; i++)
    {
        percentage[i] = (static_cast<float>(studentScore[i]) / static_cast<float>(totalScore)) * 100;
    }
}

// 8. Function to calculate Students Grades

void gradeCalculation (float percentage[],char grade[],const int num_Students)
{
    for(int i=0; i<num_Students; i++)
    {
        if (percentage[i] >= 90)
        {
            grade[i] = 'A';
        }
        else
            if(percentage[i] >= 80)
            {
                grade[i] = 'B';
            }
         else
            if(percentage[i] >= 70)
            {
                grade[i] = 'C';
            }
         else
            if(percentage[i] >= 60)
            {
                grade[i] = 'D';
            }
        else
            {
                grade[i] = 'F';
            }
    }
}

// 9. Function to Display Students Results

void displayResult(string testAnswers,string studentsID[],string studentResponse[],int studentScore[],char grade[],const int num_Students)
{
    
    cout << "\n";
    cout << "Test Answer Key : " << testAnswers << endl;
    cout << "Total Marks :  40 " << endl;
    cout << "\n";

    cout << left << setw(20) << "Student ID's " << setw(30) << "Student's Answers " << setw(25) << "Student's Test Score" << setw(30) << "Student's Grade " << endl;
    cout << "\n";

    for(int i=0; i<num_Students; i++)
    {
       cout << left << setw(20) << studentsID[i]  << setw(30) << studentResponse[i] << setw(25) << studentScore[i] << setw(30) << grade[i] << endl; 

    }
}

// 10. Code's main Function

int main()
{
   
    int numElements;                                
    int array [numElements] = {};       
    int removeItem;

    cout << "\n";
    cout << "************************ Prgramming Fundamentals ********************************" << endl;
    cout << "\n";
    cout << "                             Assignment : 3                                      " << endl;
    cout << "\n";
    
    // Problem 1

    cout << "Problem : 1" << endl;
    cout << '\n';
    cout << "======================= Student's Grade Report =================================" << endl;
    cout << "\n";

     const int num_Students = 150;
    const int totalScore = 40;
    string testAnswers;
    string studentsID[num_Students] = {};
    string Response1[num_Students] = {};
    string Response2[num_Students] = {};
    string studentResponse[num_Students] = {};
    int studentScore[num_Students] = {};
    float percentage[num_Students] = {};
    char grade[num_Students] = {};
   
    readData(testAnswers,studentsID,Response1,Response2,studentResponse,num_Students);
    testScore(testAnswers,studentResponse,studentScore,num_Students);
    percentageCalculation(studentScore,totalScore,percentage,num_Students);
    gradeCalculation(percentage,grade,num_Students);
    displayResult(testAnswers,studentsID,studentResponse,studentScore,grade,num_Students);
    
    cout << "\n";
    cout << "==============================================" << endl;
    cout << "\n";

    // Problem 2

    cout << "Problem : 2" << endl;
    cout << "\n";

    cout << "Enter number of elements (size) to form array : ";
    cin >> numElements;
    cout << "\n";

    cout << "Enter elements in an Array." << endl;
    getInput(array,numElements);

    cout << "\n";
    cout << "Enter item to remove : ";
    cin >> removeItem;

    cout << "\n";
    cout << "Result after using remove function." << endl;
    remove(array,numElements,removeItem);

    cout << "\n";
    cout << "==============================================" << endl;
    cout << "\n";

    // Problem 3
    
    cout << "Problem : 3" << endl;
    cout << "\n";

    cout << "Enter number of elements (size) to form array : ";
    cin >> numElements;
    cout << "\n";

    cout << "Enter elements in an Array." << endl;
    getInput(array,numElements);

    cout << "\n";
    cout << "Enter item to remove : ";
    cin >> removeItem;

    cout << "\n";
    cout << "Result after using remove function." << endl;
    removeAll(array,numElements,removeItem);

    cout << "\n";
    cout << "===================== Thank You !! =====================" << endl;
    cout << "\n";

    return 0;
}