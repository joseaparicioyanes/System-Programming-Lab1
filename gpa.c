/** 
 **************************************************************
 * Purpose/Description: This is a program to calculate the gpa of the students. A structure is used to store the information for each course, course name, credits, and grade.
                        There is an array of courses (stuct) to store the courses taken by the student. There is a function ( createCourses) that creates 6 different courses to test the program.
			In general terms, what the program really does is to use the information of the courses to show the user (in table form) the information of each course (including the grade 
			obtained), the totals and the current gpa.  
 * Author’s Name: Jose Aparicio
 * Author’s Panther ID: 6186111
 * Certification: I hereby certify that this work is my own and none of it is
 * the work of any other person.
 * ************************************************************
 */
#include<stdio.h>


struct course                 // structure to store all the components of each course (name,credit,and grade)
{
	char courseName[10];  //char array to store the course name
	int credits;          // integer variable to store the number of credits
	float grade;          //float variable to store the grade
};

void createCourses(struct course courses[]);                   // declaring the function create courses
int totalCredits(struct course courses[], int totalCourses);   // declaring the function calculate the total number of credits /*This function is not necessary, it can be replaced by a more efficient method, but I am using it to practice the use of  functions.*/
int main() //main function
{
	char studentName[30];    		 //creating a char array to store the student name
	const int totalCourses=6;                //number of courses
	struct course courses[totalCourses];     //creating an array of 6 courses to store all the courses
	int PID = 6186111;        		 //int variable to store the panther id
	strcpy(studentName,"Jose Aparicio");	 // initializing the student name with my name
	createCourses(courses); 		 //calling the createCourses function with courses as argument

	printf("\n\n\nStudent Name: %s\n",studentName);    //displaying the student name
	printf("Panther ID: %d\n",PID);                    // displaying the panther id
	int i;                                             //int variable to use in the for loop
	float total=0;                                     //float variable to store the total Grade Points Earned
	printf("____________________________________________________\n| Course    Credits   Grade     Grade Points Earned |\n____________________________________________________\n");  //displaying the first row
	for(i=0; i<totalCourses;i++)                       //for loop to check all the elements in the array
	{
	printf("| %-10s%4d%11.2f%24.2f |\n____________________________________________________\n", courses[i].courseName,courses[i].credits,courses[i].grade,courses[i].credits*courses[i].grade);/*displaying a row per course with all the info*/
	total+=courses[i].credits*courses[i].grade;        //getting the total Grade Points Earned
	}
	printf("| Total%9d%35.2f |\n____________________________________________________\n",totalCredits(courses, totalCourses),total);   //displaying the last row with the totals
	printf("Current GPA: %.2f",(total/((float)totalCredits(courses,totalCourses))));
	printf("\n\n\n");    //3 new lines to separate the output from all the othr text on the console
	return 0;
}

int totalCredits(struct course courses[], int totalCourses)
{
	int i;                                  //variable to use in the for loop
	int tCredits=0;			        //variable to store the total number of credits
	for(i=0;i<totalCourses;i++)
		tCredits+=courses[i].credits;   //getting the total number of credits
	return tCredits;		        //returning the total number of credits

}

void createCourses(struct course courses[])
{
	strcpy(courses[0].courseName,"COP2010");    //adding the name of a course
	courses[0].credits=3; 			    //setting the credits
	courses[0].grade=4;			    //setting the grade

	strcpy(courses[1].courseName,"ENC1101");    //adding the name of a course
        courses[1].credits=3;			    //setting the credits
        courses[1].grade=2.67;			    //setting the grade

	strcpy(courses[2].courseName,"ENC1102");    //adding the name of a course
        courses[2].credits=3;                       //setting the credits
        courses[2].grade=2.98;                      //setting the grade

	strcpy(courses[3].courseName,"CGS3095");    //adding the name of a course
        courses[3].credits=3;                       //setting the credits
        courses[3].grade=3;                         //setting the grade

	strcpy(courses[4].courseName,"COP2800");    //adding the name of a course
        courses[4].credits=3;                       //setting the credits
        courses[4].grade=3.67;                      //setting the grade
	
        strcpy(courses[5].courseName,"EEL4120");    //adding the name of a course
        courses[5].credits=2;                       //setting the credits
        courses[5].grade=3.45;                      //setting the grade

}


