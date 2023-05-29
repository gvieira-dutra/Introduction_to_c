/*
*****************************************************************************
                        Assignment 1 - Milestone 3
Full Name  : Gleison Vieira Dutra
Student ID#: 119237220
Email      : gvieira-dutra@myseneca.ca
Section    : NHH

Authenticity Declaration:
I declare this submission is the result of my own work and has not been
shared with any other student or 3rd party content provider. This submitted
piece of work is entirely of my own creation.
*****************************************************************************
*/

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>

#define START_HOUR 10
#define END_HOUR 14
#define APPT_INTERVAL 30


// include the user library "core" so we can use those functions
#include "core.h"
// include the user library "clinic" where the function prototypes are declared
#include "clinic.h"

//////////////////////////////////////
// DISPLAY FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's the patient table header (table format)
void displayPatientTableHeader(void)
{
    printf("Pat.# Name            Phone#\n"
           "----- --------------- --------------------\n");
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Displays a single patient record in FMT_FORM | FMT_TABLE format
void displayPatientData(const struct Patient* patient, int fmt)
{
    if (fmt == FMT_FORM)
    {
        printf("Name  : %s\n"
               "Number: %05d\n"
               "Phone : ", patient->name, patient->patientNumber);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
    else
    {
        printf("%05d %-15s ", patient->patientNumber,
               patient->name);
        displayFormattedPhone(patient->phone.number);
        printf(" (%s)\n", patient->phone.description);
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display's appointment schedule headers (date-specific or all records)
void displayScheduleTableHeader(const struct Date* date, int isAllRecords)
{
    printf("Clinic Appointments for the Date: ");

    if (isAllRecords)
    {
        printf("<ALL>\n\n");
        printf("Date       Time  Pat.# Name            Phone#\n"
               "---------- ----- ----- --------------- --------------------\n");
    }
    else
    {
        printf("%04d-%02d-%02d\n\n", date->year, date->month, date->day);
        printf("Time  Pat.# Name            Phone#\n"
               "----- ----- --------------- --------------------\n");
    }
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Display a single appointment record with patient info. in tabular format
void displayScheduleData(const struct Patient* patient,
                         const struct Appointment* appoint,
                         int includeDateField)
{
    if (includeDateField)
    {
        printf("%04d-%02d-%02d ", appoint->date.year, appoint->date.month,
               appoint->date.day);
    }
    printf("%02d:%02d %05d %-15s ", appoint->time.hour, appoint->time.min,
           patient->patientNumber, patient->name);

    displayFormattedPhone(patient->phone.number);

    printf(" (%s)\n", patient->phone.description);
}


//////////////////////////////////////
// MENU & ITEM SELECTION FUNCTIONS
//////////////////////////////////////

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// main menu
void menuMain(struct ClinicData* data)
{
    int selection;

    do {
        printf("Veterinary Clinic System\n"
               "=========================\n"
               "1) PATIENT     Management\n"
               "2) APPOINTMENT Management\n"
               "-------------------------\n"
               "0) Exit System\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');
        switch (selection)
        {
        case 0:
            printf("Are you sure you want to exit? (y|n): ");
            selection = !(inputCharOption("yn") == 'y');
            putchar('\n');
            if (!selection)
            {
                printf("Exiting system... Goodbye.\n\n");
            }
            break;
        case 1:
            menuPatient(data->patients, data->maxPatient);
            break;
        case 2:
            menuAppointment(data);
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient Management
void menuPatient(struct Patient patient[], int max)
{
    int selection;

    do {
        printf("Patient Management\n"
               "=========================\n"
               "1) VIEW   Patient Data\n"
               "2) SEARCH Patients\n"
               "3) ADD    Patient\n"
               "4) EDIT   Patient\n"
               "5) REMOVE Patient\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 5);
        putchar('\n');
        switch (selection)
        {
        case 1:
            displayAllPatients(patient, max, FMT_TABLE);
            suspend();
            break;
        case 2:
            searchPatientData(patient, max);
            break;
        case 3:
            addPatient(patient, max);
            suspend();
            break;
        case 4:
            editPatient(patient, max);
            break;
        case 5:
            removePatient(patient, max);
            suspend();
            break;
        }
    } while (selection);
}

// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Patient edit
void menuPatientEdit(struct Patient* patient)
{
    int selection;

    do {
        printf("Edit Patient (%05d)\n"
               "=========================\n"
               "1) NAME : %s\n"
               "2) PHONE: ", patient->patientNumber, patient->name);
        
        displayFormattedPhone(patient->phone.number);
        
        printf("\n"
               "-------------------------\n"
               "0) Previous menu\n"
               "-------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 2);
        putchar('\n');

        if (selection == 1)
        {
            printf("Name  : ");
            inputCString(patient->name, 1, NAME_LEN);
            putchar('\n');
            printf("Patient record updated!\n\n");
        }
        else if (selection == 2)
        {
            inputPhoneData(&patient->phone);
            printf("Patient record updated!\n\n");
        }

    } while (selection);
}


// !!! DO NOT MODIFY THIS FUNCTION DEFINITION !!!
// Menu: Appointment Management
void menuAppointment(struct ClinicData* data)
{
    int selection;

    do {
        printf("Appointment Management\n"
               "==============================\n"
               "1) VIEW   ALL Appointments\n"
               "2) VIEW   Appointments by DATE\n"
               "3) ADD    Appointment\n"
               "4) REMOVE Appointment\n"
               "------------------------------\n"
               "0) Previous menu\n"
               "------------------------------\n"
               "Selection: ");
        selection = inputIntRange(0, 4);
        putchar('\n');
        switch (selection)
        {
        case 1:
            importAppointments("appointmentData.txt", data->appointments, data->maxAppointments);
            viewAllAppointments(data);  
            suspend();
            break;
        case 2:

            viewAppointmentSchedule(data);  
            suspend();
            break;
        case 3:
            addAppointment(data->appointments, data->maxAppointments,
                           data->patients, data->maxPatient);  
            suspend();


            ////class
            //int i;
            //printf("\n\n 006\n");
            //for (i = 0; i < data->maxAppointments; i++)
            //{
            //    if (data->appointments[i].patientNumber > 0)
            //    {
            //        printf("paitnet number = %d\n", data->appointments[i].patientNumber);
            //    }
            //}
            //printf("\n\n");



            break;
        case 4:
            removeAppointment(data->appointments, data->maxAppointments,
                              data->patients, data->maxPatient);  
            suspend();
            break;
        }
    } while (selection);
}


// ---------------------------------------------------------------------------
// !!! INSERT/COPY YOUR MS#2 FUNCTION DEFINITIONS BELOW... !!!
// Note: Maintain the same order/sequence as it is listed in the header file
//       Properly organize/categorize any new functions accordingly
// ---------------------------------------------------------------------------


// Display's all patient data in the FMT_FORM | FMT_TABLE format
void displayAllPatients(const struct Patient patient[], int max, int fmt)
{
    int nOfPatients = 0;
    int i;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber != 0)
        {
            if (i == 0)
            {
                displayPatientTableHeader();
            }
            displayPatientData(&patient[i], fmt);
            nOfPatients++;
        }
    }

    if (nOfPatients == 0)
    {
        printf("*** No records found ***\n");
    }
    printf("\n");

    return;
}


// Search for a patient record based on patient number or phone number
void searchPatientData(const struct Patient patient[], int max)
{
    int selection;

    printf("Search Options\n");
    printf("==========================\n");
    printf("1) By patient number\n");
    printf("2) By phone number\n");
    printf("..........................\n");
    printf("0) Previous menu\n");
    printf("..........................\n");
    printf("Selection: ");
    selection = inputIntRange(0, 2);

    switch (selection)
    {
    case 1:
        searchPatientByPatientNumber(patient, max);
        break;
    case 2:
        searchPatientByPhoneNumber(patient, max);
        break;
    case 0:
        printf("\n");
        break;

    }

    return;
}


// Add a new patient record to the patient array
void addPatient(struct Patient patient[], int max)
{
    int i, index = -1;

    for (i = 0; i < max && index == -1; i++)
    {
        if (patient[i].patientNumber == 0)
        {
            index = i;
        }
    }
    if (index == -1)
    {
        printf("ERROR: Patient listing is FULL!\n\n");
    }
    else
    {
        patient[index].patientNumber = nextPatientNumber(patient, max);
        inputPatient(&patient[index]);
    }

    return;
}


// Edit a patient record from the patient array
void editPatient(struct Patient patient[], int max)
{
    int patientToEdit, patientIndex = -1;

    printf("Enter the patient number: ");

    patientToEdit = inputIntPositive();
    printf("\n");
    patientIndex = findPatientIndexByPatientNum(patientToEdit, &patient[0], max);

    if (patientIndex == -1)         // will be true if there is no patient with given index
    {
        printf("\nERROR: Patient record not found!");
    }
    else                            // a patient was found
    {
        menuPatientEdit(&patient[patientIndex]);
    }

    return;

}


// Remove a patient record from the patient array
void removePatient(struct Patient patient[], int max)
{
    int patientToRemove;
    int index = -1;
    int selection = 0;

    struct Patient delPat = { 0 };

    printf("Enter the patient number: ");
    patientToRemove = inputIntPositive();

    index = findPatientIndexByPatientNum(patientToRemove, patient, max);
    printf("\n");

    if (index != -1)        // means that we found a patient
    {
        displayPatientData(&patient[index], FMT_FORM);
        printf("\nAre you sure you want to remove this patient record? (y/n): ");
        selection = (inputCharOption("yn") == 'y');         // will be true if user decides to continue by selecting yes

        if (selection)
        {
            patient[index] = delPat;
            printf("Patient record has been removed!\n");
        }
        else
        {
            printf("Operation aborted.\n");
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n");
    }
    printf("\n");

    return;
}



// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// Milestone #3 mandatory functions...

// !!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

// View ALL scheduled appointments
void viewAllAppointments(struct ClinicData* data)
{
    int i, validate;
    int num;
    
    importAppointments("appointmentData.txt", data->appointments, data->maxAppointments);

    displayScheduleTableHeader(&data->appointments->date, 1);


    for (i = 0; i < 15; i++)
    {
        num = data->appointments[i].patientNumber;
        validate = findPatientIndexByPatientNum(num, data->patients, data->maxPatient);
            if (num>0)
            {
              displayScheduleData( &data->patients[validate], &data->appointments[i], FMT_TABLE);
            }
    }
    printf("\n");
  
    return;
}

// View appointment schedule for the user input date
void viewAppointmentSchedule(struct ClinicData* data)
{
    int year, month, day, i, j, validation;

    printf("Year        : ");
    year = inputIntRange(2022, 2050);
    printf("Month (1-12): ");
    month = inputIntRange(1, 12);

    if ((year % 4 == 0) && (month == 2))
    {
        printf("Day (1-29)  : ");
        day = inputIntRange(1, 29);
    }
    else if (month == 2)
    {
        printf("Day (1-28)  : ");
        day = inputIntRange(1, 28);
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
    {
        printf("Day (1-31)  : ");
        day = inputIntRange(1, 31);
    }
    else
    {
        printf("Day (1-30)  : ");
        day = inputIntRange(1, 30);
    }
    printf("\n");

    for (i = 0; i < data->maxAppointments; i++)
    {
        if (data->appointments[i].date.year == year && data->appointments[i].date.month == month && data->appointments[i].date.day == day)
        {
            displayScheduleTableHeader(&data->appointments[i].date, 0);
            i = data->maxAppointments;
        }
    }

    for ( i = 0; i < data->maxAppointments; i++)
    {
        if(data->appointments[i].date.year == year && data->appointments[i].date.month == month && data->appointments[i].date.day == day)
        {
            for ( j = 0; j < data->maxPatient; j++)
            {
                validation = (data->appointments[i].patientNumber == data->patients[j].patientNumber) ? 1 : 0;
                if (validation)
                {
                    displayScheduleData(&data->patients[j], &data->appointments[i], 0);
                }
            }
        }
    }


    printf("\n");

    return;
}


// Add an appointment record to the appointment array
void addAppointment(struct Appointment* appoint, int maxAppoint, struct Patient* patient, int maxPatient)
{
    int i, emptyIndex;
    int patientNum, year, month, day, hour, min;
    int timeslot = 0;

    for (i = 0; i < maxAppoint; i++)
    {
        if (appoint[i].patientNumber < 1)
        {
            emptyIndex = i;
            i = maxAppoint;
        }
    }
    
        printf("Patient Number: ");
        patientNum = inputIntPositive();
        
            do
            {
                printf("Year        : ");
                year = inputIntRange(2022, 2050);

                printf("Month (1-12): ");
                month = inputIntRange(1, 12);

                if ((year % 4 == 0) && (month == 2))
                {
                    printf("Day (1-29)  : ");
                    day = inputIntRange(1, 29);
                }
                else if (month == 2)
                {
                    printf("Day (1-28)  : ");
                    day = inputIntRange(1, 29);
                }
                else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
                {
                    printf("Day (1-31)  : ");
                    day = inputIntRange(1, 31);
                }
                else
                {
                    printf("Day (1-30)  : ");
                    day = inputIntRange(1, 30);
                }

                do {
                    printf("Hour (0-23)  : ");
                    hour = inputIntRange(1, 28);

                    printf("Minute (0-59): ");
                    min = inputIntRange(0, 59);

                    if (hour < START_HOUR || hour > END_HOUR || min % 15 != 0 || (hour == END_HOUR && min >= APPT_INTERVAL))
                    {
                        printf("ERROR: Time must be between %d:00 and %d:00 in %d minute intervals.\n\n", START_HOUR, END_HOUR, APPT_INTERVAL);
                    }

                } while ((hour < START_HOUR || hour > END_HOUR || min % 15 != 0 || (hour == END_HOUR && min >= APPT_INTERVAL)));

                timeslot = 0;
                for (i = 0; i < maxAppoint; i++)
                {
                    if ((appoint[i].date.year == year) && (appoint[i].date.month == month) && (appoint[i].date.day == day) && (appoint[i].time.hour == hour) && (appoint[i].time.min == min))
                    {
                        timeslot = 1;
                        printf("\nERROR: Appointment timeslot is not available!\n\n");
                    }
                }

            } while (timeslot == 1);
        
            
            appoint[emptyIndex].patientNumber = patientNum;
            appoint[emptyIndex].date.year = year;
            appoint[emptyIndex].date.month = month;
            appoint[emptyIndex].date.day = day;
            appoint[emptyIndex].time.hour = hour;
            appoint[emptyIndex].time.min = min;

            FILE* fp = NULL;

             fp = fopen("appointmentData.txt", "a");

             if (fp != NULL)
             {
                 fprintf(fp, "%d,%d,%d,%d,%d,%d\n", patientNum, year, month, day, hour, min);
                 fclose(fp);
             }
             else
             {
                 printf("Failed to open file\n");
             }

            //importAppointments("appointmentData.txt", patient, maxAppoint);

           printf("\n*** Appointment scheduled! ***\n\n");

           return;
}


// Remove an appointment record from the appointment array
void removeAppointment(struct Appointment appoint[], int maxAppoint, struct Patient patient[], int maxPatient)
{
    int i;
    int patientNumber, year, month, day;
    int found = 0;
    int appointmentIndex = -1;
    int patientIndex;
    struct Appointment delAppt = { 0 };

    int patN = 0, yearTa=0, monthTa=0, dayTa=0, hourTa=0, minTa=0;

    printf("Patient Number: ");
    patientNumber = inputIntPositive();

    for (i = 0; i < maxPatient; i++)
    {
        if (patient[i].patientNumber == patientNumber)
        {
            patientIndex = i;
            found = 1;
        }
    }

    if (found == 1)
    {
        printf("Year        : ");
        year = inputIntRange(2022, 2050);
        printf("Month (1-12): ");
        month = inputIntRange(1, 12);
        if ((year % 4 == 0) && (month == 2))
        {
            printf("Day (1-29)  : ");
            day = inputIntRange(1, 29);
        }
        else if (month == 2)
        {
            printf("Day (1-28)  : ");
            day = inputIntRange(1, 29);
        }
        else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        {
            printf("Day (1-31)  : ");
            day = inputIntRange(1, 31);
        }
        else
        {
            printf("Day (1-30)  : ");
            day = inputIntRange(1, 30);
        }

        for (i = 0; i < maxAppoint ; i++)
        {
            if (patient[patientIndex].patientNumber == appoint[i].patientNumber && year == appoint[i].date.year && month == appoint[i].date.month && day == appoint[i].date.day) 
            {
                appointmentIndex = i;
                i = maxAppoint;
            }
        }



        if (appointmentIndex != -1)
        {

            printf("\nName  : %s\n", patient[patientIndex].name);
            printf("Number: %05d\n", patient[patientIndex].patientNumber);
            printf("Phone : ");
            displayFormattedPhone(patient[patientIndex].phone.number);
            printf(" (%s)\n", patient[patientIndex].phone.description);

            printf("Are you sure you want to remove this appointment (y,n): ");
            if (inputCharOption("yn") == 'y')
            {
                
                
                appoint[appointmentIndex] = delAppt;


                    FILE* fp = NULL;

                    fp = fopen("appointmentData.txt", "w");

                    if (fp != NULL)
                    {
                        for ( i = 0; i < maxAppoint; i++)
                        {
                            patN = appoint[i].patientNumber;
                            yearTa = appoint[i].date.year;
                            monthTa = appoint[i].date.month;
                            dayTa = appoint[i].date.day;
                            hourTa = appoint[i].time.hour;
                            minTa = appoint[i].time.min;
                            if (patN > 1);
                            {
                            fprintf(fp, "%d,%d,%d,%d,%d,%d\n", patN , yearTa , monthTa , dayTa, hourTa, minTa);
                            }
                        }
                        fclose(fp);
                    }
                    else
                    {
                        printf("Failed to open file\n");
                    }


                printf("\nAppointment record has been removed!\n\n");
            
            
            }
            else
            {
                printf("\n***Operation Aborted!***\n\n");
            }
        }
    }
    else
    {
        printf("ERROR: Patient record not found!\n\n");
    }
    

    return;
}


//////////////////////////////////////
// UTILITY FUNCTIONS
//////////////////////////////////////

// Search and display patient record by patient number (form)
void searchPatientByPatientNumber(const struct Patient patient[], int max)
{
    int patientNumber;
    int index;

    printf("\nSearch by patient number: ");
    patientNumber = inputIntPositive();

    index = findPatientIndexByPatientNum(patientNumber, patient, max);

    if (index == -1)
    {
        // no patient was found
        printf("\n*** No records found ***\n\n");
        suspend();
        searchPatientData(patient, max);
    }
    else
    {
        // a patient was found
        printf("\n");
        displayPatientData(&patient[index], FMT_FORM);
        printf("\n");
        suspend();
        searchPatientData(patient, max);
    }

    return;
}


// Search and display patient records by phone number (tabular)
void searchPatientByPhoneNumber(const struct Patient patient[], int max)
{

    char phoneToSearch[PHONE_LEN + 1];
    int i, found = 0;

    printf("\nSearch by phone number: ");
    inputCString(phoneToSearch, 10, 10);

    printf("\n");
    displayPatientTableHeader();

    for (i = 0; i < max; i++)
    {
        if (!(strcmp(phoneToSearch, patient[i].phone.number)))
        {
            found++;
            displayPatientData(&patient[i], FMT_TABLE);
        }
    }
    if (found == 0)
    {
        printf("\n*** No records found ***\n");
    }
    printf("\n");
    suspend();
    searchPatientData(patient, max);

    return;
}


// Get the next highest patient number
int nextPatientNumber(const struct Patient patient[], int max)
{
    int i, highestNum = 0;

    for (i = 0; i < max; i++)
    {
        if (patient[i].patientNumber > highestNum)
        {
            highestNum = patient[i].patientNumber;
        }
    }

    return highestNum + 1;
}


// Find the patient array index by patient number (returns -1 if not found)
int findPatientIndexByPatientNum(int patientNumber,
    const struct Patient patient[], int max)
{
    int i, index = -1;
    
    for (i = 0; i < max; i++)
    {
        if (patientNumber == patient[i].patientNumber)
        {
            index = i; //found the patient, pass index
        }
    }

    return index;
}



//////////////////////////////////////
// USER INPUT FUNCTIONS
//////////////////////////////////////

// Get user input for a new patient record
void inputPatient(struct Patient* patient)
{

    printf("Patient Data Input\n");
    printf("------------------\n");
    printf("Number: %05d\n", patient->patientNumber);
    printf("Name  : ");

    inputCString(patient->name, 1, NAME_LEN);
    printf("\n");
    inputPhoneData(&patient->phone);
    printf("*** New patient record added ***\n\n");
    return;
}


// Get user input for phone contact information
void inputPhoneData(struct Phone* phone)
{
    int phoneType;

    printf("Phone Information\n");
    printf("-----------------\n");
    printf("How will the patient like to be contacted?\n");
    printf("1. Cell\n");
    printf("2. Home\n");
    printf("3. Work\n");
    printf("4. TBD\n");
    printf("Selection: ");

    phoneType = inputIntRange(1, 4);

    switch (phoneType)
    {
    case 1:
        strcpy(phone->description, "CELL");
        printf("\nContact: %s\n", phone->description);
        break;
    case 2:
        strcpy(phone->description, "HOME");
        printf("\nContact: %s\n", phone->description);
        break;
    case 3:
        strcpy(phone->description, "WORK");
        printf("\nContact: %s\n", phone->description);
        break;
    case 4:
        strcpy(phone->description, "TBD");
        break;
    }

    if (phoneType != 4)
    {
        printf("Number : ");
            phoneValidation(phone->number, PHONE_LEN, PHONE_LEN);
    }
    else
    {

    }
    printf("\n");
    return;
}



//////////////////////////////////////
// FILE FUNCTIONS
//////////////////////////////////////

// Import patient data from file into a Patient array (returns # of records read)
int importPatients(const char* datafile, struct Patient patients[], int max)
{
    FILE* fp = NULL;
    int i, value=0;

    fp = fopen(datafile, "r");

    if (fp != NULL)
    {
        for ( i = 0; i < max; i++)
        {
            
            if (fscanf(fp, "%d|%[^|]|%[^|]|%[^\n]", &patients[i].patientNumber, patients[i].name, patients[i].phone.description, patients[i].phone.number) > 0)
            {
                value++;
            }
            else
            {
                i = max;
            }
        }          
            fclose(fp);
    }
    else
    {
        printf("Failed to open file\n");
    }

    return value;
}


// Import appointment data from file into an Appointment array (returns # of records read)
int importAppointments(const char* datafile, struct Appointment appoints[], int max)
{
    
    FILE* fp = NULL;
    int i, value = 0;

    fp = fopen(datafile, "r");


    if (fp != NULL)
    {
        for (i = 0; i < max; i++)
        {
           

                if(fscanf(fp, "%d,%d,%d,%d,%d,%d\n", &appoints[i].patientNumber, &appoints[i].date.year, &appoints[i].date.month, &appoints[i].date.day, &appoints[i].time.hour, &appoints[i].time.min) > 0)
                {
                    value++;
                }
                else
                {
                    i = max;
                }
            
        }
        fclose(fp);
    }
    else
    {
        printf("Failed to open file\n");
    }

    sortAppts(appoints, value);


    return value;
}

// Find the lowest appointment from the list in the list of appointments. 
int findLowestAppts(struct Appointment appoints[], int num) {
    int i;
    int lowestYear = 99999;
    int lowestMonth = 12;
    int lowestDay = 31;
    int lowestHour = 23;
    int lowestMin = 59;
    int index = -1;

    // Find lowest year
    for (i = 0; i < num; i++)
    {
        if (appoints[i].patientNumber != 0 && appoints[i].date.year < lowestYear)
        {
            lowestYear = appoints[i].date.year;
        }
    }
    
    // Find lowest month
     for ( i = 0; i < num; i++)
     {
        if (appoints[i].patientNumber != 0 && appoints[i].date.year == lowestYear && appoints[i].date.month < lowestMonth)
        {
            lowestMonth = appoints[i].date.month;
        }
     }

      // Find lowest day
     for ( i = 0; i < num; i++)
     {
        if (appoints[i].patientNumber != 0 && appoints[i].date.year == lowestYear && appoints[i].date.month == lowestMonth && appoints[i].date.day < lowestDay)
        {
            lowestDay = appoints[i].date.day;
        }
     }

      // Find lowest hour
     for ( i = 0; i < num; i++)
     {
        if (appoints[i].patientNumber != 0 && appoints[i].date.year == lowestYear && appoints[i].date.month == lowestMonth && appoints[i].date.day == lowestDay && appoints[i].time.hour < lowestHour)
        {
            lowestHour = appoints[i].time.hour;
        }
     }

     // Find lowest min
     for ( i = 0; i < num; i++)
     {
        if (appoints[i].patientNumber != 0 && appoints[i].date.year == lowestYear && appoints[i].date.month == lowestMonth && appoints[i].date.day == lowestDay && appoints[i].time.hour == lowestHour && appoints[i].time.min < lowestMin)
        {
            lowestMin = appoints[i].time.min;
            index = i;
        }
     }
 
    return index; 
}

// Organize the appointments in chronological order, as received from the findLowestAppts function.
void sortAppts(struct Appointment appoints[], int num)
{
    int i, index;
    struct Appointment temp[51] = { {0} };

    for ( i = 0; i < num; i++)
    {
        index = findLowestAppts(appoints, num);
        temp[i].patientNumber = appoints[index].patientNumber;
        temp[i].date.year = appoints[index].date.year;
        temp[i].date.month = appoints[index].date.month;
        temp[i].date.day = appoints[index].date.day;
        temp[i].time.hour = appoints[index].time.hour;
        temp[i].time.min = appoints[index].time.min;

        appoints[index].patientNumber = 0;
    }

    for (i = 0; i < num; i++)
    {
        appoints[i].patientNumber = temp[i].patientNumber;
        appoints[i].date.year = temp[i].date.year;
        appoints[i].date.month = temp[i].date.month;
        appoints[i].date.day = temp[i].date.day;
        appoints[i].time.hour = temp[i].time.hour;
        appoints[i].time.min = temp[i].time.min;

    }

    return;
}

