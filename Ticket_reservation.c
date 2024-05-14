/**********************************************************
Name : Sudharsan M
Date   : 01/05/2024
Description: Bus Ticket Reservation Using Doubly Linked List
*********************************************************/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include<time.h>

struct Reservation_node
{
    int passenger_num;
    char name[20];
    int r_code;
    int cost;
    struct Reservation_node *next;
    struct Reservation_node *prev;
};
typedef struct Reservation_node rnode;

void login();
void bus_list();
void display_seats_list(int bus[30]);
void book_bus_ticket();
int bus_cost(int );
rnode *creat_node(int, const char *, int, int);
rnode *insert(rnode *, int, const char *, int, int);
void seat_status();
void reservation_info();
void cancel();

rnode *head = NULL;

int bus_seats[30][8] = {0};
void red()
{
    printf("\033[1;31m");
}
void normal_clr()
{
    printf("\033[0m");
}
void green()
{
    printf("\033[0;32m");
}

void login()
{
    char uid[20] = "sunms2000@gmail.com";
    char upassword[10] = "Admin123";
    char user_Id[30];
    char user_paswrd[10];
    printf("=========================================================\n");
    printf("\t\t\033[1;31mWELCOME TO BUS RESERVATION\033[0m\n");
    printf("=========================================================\n");
login:
{
    printf("Enter User mail Id:");
    gets(user_Id);
    printf("Enter user password:");
    gets(user_paswrd);
}
    int id = strcmp(uid, user_Id);
    int value = strcmp(upassword, user_paswrd);
    if (value != 0)
    {
        red();
        printf("Invalid Password\n");
        normal_clr();
        goto login;
    }
    else if (id != 0)
    {
        red();
        printf("Invalid User Id\n");
        normal_clr();
        goto login;
    }
    else
    {
        green();
        printf("Loged In Successfull.");
        normal_clr();
    }
}
void bus_list()
{
    red();
    printf("=========================================================================================\n");
    printf("Bus No\t\t Bus Name\t\t Destination\t\t\t Far\t\t Time\n");
    printf("\n");
    printf(" [1]\t\t Inter city smart bus\t Virudhunagr to Madurai\t\t 2000\t\t 05:00  AM\n");
    printf(" [2]\t\t Sundhara Ttavels\t Aruppukotai to Thiruchi\t 1000\t\t 07:15  AM\n");
    printf(" [3]\t\t Egloo travels\t\t Madurai to Theni\t\t 1500\t\t 09:45  AM\n");
    printf(" [4]\t\t Senthil travels\t Virudhunagr to Thirunelveli\t 2100\t\t 11:00  AM\n");
    printf(" [5]\t\t VKV travels\t\t Virudhunagr to Coimbatore\t 1800\t\t 01:30  PM\n");
    printf(" [6]\t\t Kamesh travels\t\t Madurai to Selam\t\t 2500\t\t 09:45  PM\n");
    printf(" [7]\t\t Sri kumaran travels\t Thirunelveli to Ooty\t\t 2500\t\t 09:45  PM\n");
    printf(" [8]\t\t Nithiya travels\t Madurai to Bangalur\t\t 2500\t\t 09:45  PM\n");
    normal_clr();
    printf("\n");
    printf("Press Enter to Countinue.\n");
    getch();
}
int bus_cost(int busnum)
{
    switch(busnum)
    {
        case 1:
            return 2000;
            break;
        case 2:
            return 1000;
            break;
        case 3:
            return 1500;
            break;
        case 4:
            return 2100;
            break;
        case 5:
            return 1800;
            break;
        case 6:
            return 2500;
            break;
        case 7:
            return 2500;
            break;
        case 8:
            return 2500;
            break;
        default:
            printf("Invalid\n");
            break;
    }
}
void display_seats_list(int bus[30])
{

    for (int i = 1; i <= 30; i++)
    {
        red();
        if (i > 0 && i < 10)
        {
            printf("\t0%d.", i);
            
        }
        else
            printf("\t%d.", i);
        normal_clr();
        {
            if (bus[i] == 0)
                printf("Empty");
            else
            {
                green();
                printf("Booked");
                normal_clr();
            }
        }
        printf("         ");
        if (i % 3 == 0)
            printf("\n");
    }
}
void book_bus_ticket()
{
    int bus_num, seat_num, num_of_seats, cust_id;
    char cust_name[20];
    int rand_num;
bus_choice:
    printf("Enter your bus number:");
    scanf("%d", &bus_num);
    if (bus_num <= 0 || bus_num > 8)
    {
        red();
        printf("Please Enter Valid choice !!");
        normal_clr();
        goto bus_choice;
    }
    printf("\n");
    display_seats_list(bus_seats[bus_num]);
bus_seat_choice:
    printf("Enter the No.of Seats you want:");
    scanf("%d", &num_of_seats);
    if (num_of_seats <= 0 || num_of_seats > 30)
    {
        red();
        printf("We have only 30 seats. So, Enter Valid Seat Number!");
        normal_clr();
        goto bus_seat_choice;
    }
    for (int i = 1; i <= num_of_seats; i++)
    {
        printf("\n");
    seat:
        printf("Enter Seat Number:");
        scanf("%d", &seat_num);
        if (seat_num < 1 || seat_num > 30)
        {
            red();
            printf("We have only 30 seats. so, Enter valid seat Number.\n");
            normal_clr();
            goto seat; 
        }
        if (bus_seats[bus_num][seat_num] == 1)
        {
            red();
            printf("Sorry! This Seat already Booked.Enter valid seat Number.\n");
            normal_clr();
            goto seat;
        }
        cust_id = (1000 * bus_num) + seat_num;
        bus_seats[bus_num][seat_num] = 1;
        rand_num = rand();
        printf("Enter your Name:");
        scanf("%s", &cust_name);
        int cost = bus_cost(bus_num);
        printf("=================================================================\n");
        green();
        printf("Your Customer ID is     : %d\n", cust_id);
        printf("Your Reservation Code is: %d\n", rand_num);
        printf("Your Travel Fair is     : %d\n", cost); 
        normal_clr();
        printf("Please Notedown That Reservation Number For Cancel Booking Tickets.\n");
        printf("=================================================================\n");
        head = insert(head, cust_id, cust_name, rand_num, cost);  
    }      
}
rnode *creat_node(int id, const char *name, int randnum, int cost)
{
    rnode *newnode = (rnode *)malloc(sizeof(rnode));
    if (newnode != NULL)
    {
        newnode->passenger_num = id;
        strcpy(newnode->name, name);
        newnode->r_code = randnum;
        newnode->cost = cost;
        newnode->next = NULL;
        newnode->prev = NULL;
    }
    return newnode;
}
rnode *insert(rnode *head, int id, const char *name, int rand_num, int cost)
{
    rnode *newnode = creat_node(id, name, rand_num, cost);
    if (newnode == NULL)
    {
        red();
        printf("Memory allocation failed!, Ticket not booked.\n");
        normal_clr();
        return head;
    }
    if (head == NULL)
        return newnode; // newnode becomes head.

    rnode *current = head;
    while (current != NULL)
    {
        if (current->passenger_num > id)
        {
            newnode->prev = current->prev;
            newnode->next = current;
            if (current->prev != NULL)
            {
                current->prev->next = newnode;
            }
            else
            {
                head = newnode;
            }
            current->prev = newnode;
            return head;
        }
        else if (current->passenger_num < id)
        {
            if (current->next == NULL)
            {
                current->next = newnode;
                newnode->prev = current;
                return head;
            }
        }
        else
        {
            printf("Duplicate customer ID. Cannot book ticket.\n");
            free(newnode);
            return head;
        }
        current = current->next;
    }
}
void seat_status()
{
    int bus_num;
    bus_list();
    bus_num:
    printf("Enter Bus Number:");
    scanf("%d", &bus_num);
    if(bus_num <= 0 || bus_num > 8)
    {
        red();
        printf("Invalid Bus Number!, Please Enter Valid Bus Number.\n");
        normal_clr();
        goto bus_num;
    }
    else
    {
        printf("\n");
        display_seats_list(bus_seats[bus_num]);
    } 
}
void reservation_info()
{
    int reserv_code;
    printf("Enter Your Reservation Code:");
    scanf("%d", &reserv_code);
    rnode* temp = head;
    while (temp != NULL)
    {
        if (reserv_code == temp->r_code)
        {
            printf("Your Name          %s\n", temp->name);
            printf("Your Customer Id   %d\n", temp->passenger_num);
            printf("Your Bus Number    %d\n", (temp->passenger_num)/1000);
            printf("Your Seat Number   %d\n", (temp->passenger_num)%1000);
            printf("Your Travel Cost   %d\n", temp->cost);
            return;
        }
        temp = temp->next;
    }
    red();
    printf("No reservation found with provided code.\n");
    normal_clr();
}
void cancel()
{
    int reserv_code, bus_num, seat_num;
    int cust_id;
    char decision;
    rnode *temp = head;
    printf("Enter Your Reservation Code: ");
    scanf("%d", &reserv_code);
    while (temp != NULL)
    {
        if (temp->r_code == reserv_code)
        {
            printf("Enter Your Customer Id: ");
            scanf("%d", &cust_id);
            if (cust_id == temp->passenger_num)
            {
                bus_num = cust_id / 1000;
                seat_num = cust_id % 1000;
                printf("Your Bus Number is %d and Your Seat Number is %d\n", bus_num, seat_num);
                display_seats_list(bus_seats[bus_num]);
                printf("Press 'Y' to cancel the seat: ");
                scanf(" %c", &decision); // space before %c to consume newline
                if (decision == 'Y' || decision == 'y')
                {
                    bus_seats[bus_num][seat_num] = 0;
                    if (temp->prev == NULL)
                    {
                        head = temp->next;
                    }
                    else if (temp->next == NULL)
                    {
                        temp->prev->next = NULL;
                    }
                    else
                    {
                        temp->prev->next = temp->next;
                        temp->next->prev = temp->prev;
                    }
                    free(temp);
                    printf("Your Reservation Seat Cancellation Successful.\n");
                    display_seats_list(bus_seats[bus_num]);
                    return;
                }
                else
                {
                    printf("Your Reservation Seat Cancellation Unsuccessful.\n");
                    return;
                }
            }
            else
            {
                printf("Your Customer Id is Incorrect. Enter Valid Customer Id.\n");
                return;
            }
        }
        temp = temp->next;
    }
    printf("No reservation found with provided code.\n");
}
/*Driver Code*/
int main()
{
    srand(time(NULL));
    login();
    int cust_choice, countinue;
  
    do
    {
        printf("\n========================================================\n");
        printf("\t\t\033[1;31mWELCOME TO BUS RESERVATION\033[0m \n");
        printf("==========================================================\n");
        printf("\t\t\033[1;31mMAIN MENU \033[0m \n");
        printf("\t\033[1;31m[1]\033[0;32m View Bus List \n");
        printf("\t\033[1;31m[2]\033[0;32m Book Bus Ticket \n");
        printf("\t\033[1;31m[3]\033[0;32m Cancle Ticket\n");
        printf("\t\033[1;31m[4]\033[0;32m Bus Seats Info\n");
        printf("\t\033[1;31m[5]\033[0;32m Reseravation Info\n");
        printf("\t\033[1;31m[6]\033[0;32m Exit\n");
        normal_clr();
        printf("========================================================\n");
        printf("Enter Your choice:");
        scanf("%d", &cust_choice);
        switch (cust_choice)
        {
        case 1: // view bus list.
            bus_list();
            break;
        case 2: // book bus ticket
            bus_list();
            book_bus_ticket();
            break;
        case 3: // cancle ticket
            cancel();
            break;
        case 4: // bus seats info
            seat_status();
            break;
        case 5: // reseravtion info
            reservation_info();
            break;
        case 6: // exit
            green();
            printf("Thankyou for using this Application..!");
            normal_clr();
            exit(0);
            break;
        default:
            printf("\033[1:31mPlease Enter the Valid Option.\033[0m");
            break;
        }
        green();
        printf("\nPress 1 or 0 to Countinue This Application\n");
        scanf("%d", &countinue);
        normal_clr();

    } while (countinue <= 1);
    return 0;
}
