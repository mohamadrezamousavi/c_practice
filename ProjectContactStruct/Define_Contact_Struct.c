# include <stdio.h>
# include <stdlib.h>
# include <string.h>

struct Contact {
    char name[50];
    char phone[20];
    char email[40];
    int age;
};

struct Contact* creatContact(){

    struct Contact *contactPtr;

    contactPtr = malloc(sizeof(struct Contact));
    
    if (contactPtr == NULL)
    {
        printf("Memory Allocation Failed\n");
        return NULL;
    }
    else
        printf("Contact created successfully\n");

    contactPtr->name[0] = '\0';
    contactPtr->phone[0] = '\0';
    contactPtr->email[0] = '\0';
    contactPtr->age = 0;
    return contactPtr;
}

void populateContact (struct Contact *ptr){
    printf("Enter Name: ");
    fgets(ptr->name, 50,stdin);
    ptr->name[strcspn(ptr->name, "\n")] = '\0';

    printf("Enter Phone: ");
    fgets(ptr->phone, 20,stdin);
    ptr->phone[strcspn(ptr->phone, "\n")] = '\0';

    printf("Enter Email: ");
    fgets(ptr->email, 40,stdin);
    ptr->email[strcspn(ptr->email,"\n")] = '\0';

    printf("Enter Age: ");
    scanf("%d", &(ptr->age));  
    
    if (ptr->age < 0 || ptr->age > 120)
        printf("Invalid Age");
    else 
        printf("Contact populated successfully\n");
}

void displayContact(const struct Contact *ptr){
    printf("====Contact Info====\n");
    printf("Name: %s\n", ptr->name);
    printf("Phone: %s\n", ptr->phone);
    printf("Email: %s\n", ptr->email);
    printf("Age: %d\n", ptr->age); 
    printf("=====================\n");

    int len = strlen(ptr->name);
    printf("Name Length: %d\n", len);

    if (ptr->age <= 12)
        printf("Generation: Child\n");
    else if (ptr->age > 12 && ptr->age <= 19)
        printf("Generation: Teenager\n");
    else if (ptr->age > 19 && ptr->age <= 39)
        printf("Generation: Young Adult\n");
    else if (ptr->age > 39 && ptr->age <=59)
        printf("Generation: Middle Aged Adult\n");
    else 
        printf("Generation: Senior\n");

    char *emailPtr;
    emailPtr = strchr(ptr->email, '@');
    if (emailPtr == NULL)
        printf("Invalid Email\n");
    else
        printf("Email Valid\n");
}

void updateContact(struct Contact *ptr){
    int choice;
    while(1){
        printf("Which field needs update:\n1. Name\n2. Phone\n3. Email\n4. Age\nEnter choice (1-4): ");
        scanf("%d", &choice);

        if (choice >= 1 && choice <= 4)
            break;
        printf("Invalid Choice, try again\n");
    }


    if (choice == 1){
        printf("Enter new Name: ");
        getchar(); // consume leftover \n in buffer
        fgets(ptr->name, 49, stdin);
        ptr->name[strcspn(ptr->name, "\n")] = '\0';
    }
    else if (choice == 2){
        printf("Enter new Phone: ");
        getchar(); // consume leftover \n in buffer
        fgets(ptr->phone, 19, stdin);
        ptr->phone[strcspn(ptr->phone, "\n")] = '\0';       
    }
    else if (choice == 3){
        printf("Enter new Email: ");
        getchar(); // consume leftover \n in buffer
        fgets(ptr->email, 19, stdin);
        ptr->email[strcspn(ptr->email, "\n")] = '\0';       
    }
    else {
        printf("Enter new Age: ");
        scanf("%d", &(ptr->age));     
    }

    printf("Contact Updated\n");

        
    
}

int main (){


    struct Contact *newContact;
    newContact = creatContact();
    if (newContact == NULL)
        printf("Failed to create contact\n");
    else
        printf("Contact initialized with default values\n");
    
    populateContact(newContact);
    printf("---Initial Contact---\n");
    displayContact(newContact);
    printf("---Updating Contact---\n");
    updateContact(newContact);
    printf("---Updated Contact---\n");    
    displayContact(newContact);
    free(newContact);
    printf("Contact management completed\n");
        
    return 0;
}

