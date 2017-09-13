#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
        {
           char name[10];
           int  age ;
           char address[100];
           char pastMedicalhistory[100];
           int  temp;
           char listOfHealthIssues[100];

        }  PATIENT_TYPE ;
main()
{
    PATIENT_TYPE outpatient[100] ;
    PATIENT_TYPE inpatient[100] ;
    int idx ;
    FILE *htmlPtr ;
    char tablestyle[100];
    char tableHeader[100];
    strcpy(tablestyle,"<head> <style> table, th, td { border: 1px solid black; } </style> </head>");
    strcpy(tableHeader, "<tr> <th>Name</th> <th>Age</th> <th>Address</th> <th> history </th> <th> Temperature </th></tr>");

    for(idx = 0; idx < 3 ;idx++)
    {
       printf("Enter the age: ");
       scanf("%d",&outpatient[idx].age); 

       printf("Enter the name: ");
       scanf("%s",outpatient[idx].name); 

       printf("Enter the address: ");
       scanf("%s",outpatient[idx].address); 

       printf("Enter the Medical history: ");
       scanf("%s",outpatient[idx].pastMedicalhistory); 

       printf("Enter the temperature: ");
       scanf("%d",&outpatient[idx].temp); 
       printf("-------------------- \n\n\n");
    }
    
    htmlPtr = fopen("/var/www/html/index.html","w");
    if (htmlPtr == NULL)
    {
       printf("Unable to open the html file index.html for  writing\n");
       exit(1);
    }    
    fprintf(htmlPtr,"<HTML>\n");

    
    fprintf(htmlPtr,"%s \n",tablestyle);
    fprintf(htmlPtr,"<TABLE>\n");
    fprintf(htmlPtr,"%s \n",tableHeader);

    for(idx = 0; idx < 5 ;idx++)
    {
       
       fprintf(htmlPtr,"<TR>"); 
       fprintf(htmlPtr,"<TD>%s</TD> ",outpatient[idx].name); 
       fprintf(htmlPtr,"<TD>%d</TD> ",outpatient[idx].age); 
       fprintf(htmlPtr,"<TD>%s</TD> ",outpatient[idx].address); 
       fprintf(htmlPtr,"<TD>%s</TD> ",outpatient[idx].pastMedicalhistory); 
       fprintf(htmlPtr,"<TD>%d</TD>\n ",outpatient[idx].temp);
       fprintf(htmlPtr,"</TR>"); 

    }

    fprintf(htmlPtr,"</TABLE>\n");
    fprintf(htmlPtr,"</HTML>\n");
    fclose(htmlPtr);
}

