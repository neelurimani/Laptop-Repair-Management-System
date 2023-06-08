#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct client {
    int id;
    char name[50];
    char email[50];
    char phone[15];
    char address[250];
    char laptop_brand[50];
    char laptop_model[50];
    int price;
}c;
struct laptop{
    int id;
    char brand[250];
    char model[250];
    char serial_no[250];
    char damaged_parts[250];
}l;
struct expert{
    int id;
    char name[250];
    int service_cost;
    char skill[250];
}e;
void add_client(){
    FILE *a;
    a=fopen("Client.txt","a");
    printf("\n\n\n\tEnter ID of Client:   ");
    scanf("%d",&c.id);
    printf("\n\tEnter Name of client:     ");
    scanf("%s",&c.name);
    printf("\n\tEnter Email-ID of client:     ");
    scanf("%s",c.email);
    printf("\n\tEnter Phone Number of Client:       ");
    scanf("%s",&c.phone);
    printf("\n\tEnter address of client:		");
    scanf("%s",&c.address);
    printf("\n\tEnter Laptop Brand:       ");
    scanf("%s",&c.laptop_brand);
    printf("\n\tEnter Model of Laptop:        ");
    scanf("%s",&c.laptop_model);
    printf("\n\tEnter the price to be paid by client:	");
    scanf("%d",&c.price);
    printf("\n\t\t\t\t\t********RECORD UPDATED********\n\n\n");
    fwrite(&c,sizeof(c),1,a);
    fclose(a);
}
void view_client(){
    FILE *b;
    b=fopen("Client.txt","r");
    printf("\nClient_ID\tName\t\t\tEmail\t\t\t\tPhone\t\tAddress\t\tLaptop_brand\tLaptop_Model\tPrice\n\n");
    while(fread(&c,sizeof(c),1,b)){
        printf("%d\t\t%s\t\t%s\t\t%s\t%s\t\t%s\t\t%s\t\t%d\n\n",c.id,c.name,c.email,c.phone,c.address,c.laptop_brand,c.laptop_model,c.price);
    }
    fclose(b);
}
void add_laptop(){
    FILE *c;
    c=fopen("laptop.txt","a");
    printf("\n");
    printf("\n\n\tEnter the ID of Laptop:     ");
    scanf("%d",&l.id);
    printf("\n\tEnter Laptop Brand:     ");
    scanf("%s",&l.brand);
    printf("\n\tEnter Model of Laptop:      ");
    scanf("%s",&l.model);
    printf("\n\tEnter serial number of laptop:      ");
    scanf("%s",&l.serial_no);
    printf("\n\tEnter damged parts of laptop:		");
    scanf("%s",&l.damaged_parts);
    printf("\n\t\t\t\t\t********RECORD UPDATED********\n\n\n");
    fwrite(&l,sizeof(l),1,c);
    fclose(c);
}
void view_laptop(){
    FILE *d;
    d=fopen("laptop.txt","r");
    printf("\nLaptop_ID\tLaptop_Brand\tLaptop_Model\tLaptop_Serial\t\tDamaged Parts\n\n");
    while(fread(&l,sizeof(l),1,d)){
        printf("%d\t\t%s\t\t%s\t\t%s\t\t%s\n\n\n",l.id,l.brand,l.model,l.serial_no,l.damaged_parts);
    }
    fclose(d);
}
void add_expert(){
    FILE *d;
    d=fopen("expert.txt","a");
    printf("\n\n\n\tEnter the ID of Expert:	");
    scanf("%d",&e.id);
    printf("\n\tEnter the Name of Expert:		");
    scanf("%s",&e.name);
    printf("\n\tEnter the Skill of Expert:		");
    scanf("%s",&e.skill);
    printf("\n\tEnter service cost of expert:	");
	scanf("%d",&e.service_cost);
    printf("\n\t\t\t\t\t********RECORD UPDATED********\n\n\n");
    fwrite(&e,sizeof(e),1,d);
    fclose(d);
}
void view_expert(){
    FILE *e1;
    e1=fopen("expert.txt","r");
    printf("\nExpert_ID\tName\t\tSkill\t\tService Cost\n\n\n");
    while(fread(&e,sizeof(e),1,e1)){
        printf("%d\t\t%s\t\t%s\t%d\n\n",e.id,e.name,e.skill,e.service_cost);
    }
}
int chec_lid(int a){
    FILE *ni;
    ni=fopen("laptop.txt","r");
    while(!feof(ni)){
        fread(&l,sizeof(l),1,ni);
        if(a==l.id){
            fclose(ni);
            return 1;
        }
    }
    fclose(ni);
    return 0;
}

int chec_client(int a){
    FILE *w1;
    w1=fopen("client.txt","r");
    while(!feof(w1)){
        fread(&c,sizeof(c),1,w1);
        if(a==c.id){
            fclose(w1);
            return 1;
        }
    }
    fclose(w1);
    return 0;
}
void update_client(){
    FILE *d1;
    FILE *d2;
    d1=fopen("client.txt","r");
    d2=fopen("record.txt","w");
    int avl;
    int r,s,ch;
    printf("\n\tEnter client ID which needs to be updated:		");
    scanf("%d",&r);
    avl=chec_client(r);
    if (avl==0){
        printf("\n\t\t\t*******CLIENT ID NOT FOUND*******\n\n\n");
    }
    else{
        while(fread(&c,sizeof(c),1,d1)){
            s=c.id;
            if(s!=r){
                fwrite(&c,sizeof(c),1,d2);
            }
            else{
                printf("\n\t\t\t1.Name");
                printf("\n\t\t\t2.Email");
                printf("\n\t\t\t3.Phone");
                printf("\n\t\t\t4.Laptop_brand");
                printf("\n\t\t\t5.Laptop_Model");
                printf("\n\t\t\t6.Price");
                printf("\n\t\t\t7.Address");
                printf("\n\t\t\t8.Exit");
                printf("\n\n\t\t\tEnter Your Choice:	");
                scanf("%d",&ch);
                switch(ch){
                    case(1):
                    printf("\n\t\t\tEnter Name:   ");
                    scanf("%s",&c.name);
                            printf("\n\t\t\t**********RECORD UPDATED**********\n\n\n");
                    break;
                    case(2):
                    printf("\n\t\t\tEnter Email ID:   ");
                    scanf("%s",&c.email);
                            printf("\n\t\t\t**********RECORD UPDATED**********\n\n\n");
                    break;
                    case(3):
                    printf("\n\t\t\tEnter Phone Number:   ");
                    scanf("%s",&c.phone);
                            printf("\n\t\t\t**********RECORD UPDATED**********\n\n\n");
                    break;
                    case(7):
                    	printf("\n\t\t\tEnter address of Client:	");
                    	scanf("%s",&c.address);
                    	break;
                    case(4):
                    printf("\n\t\t\tEnter Laptop Brand:   ");
                    scanf("%s",&c.laptop_brand);
                            printf("\n\t\t\t**********RECORD UPDATED**********\n\n\n");
                    break;
                    case(5):
                    printf("\n\t\t\tEnter Laptop Model:   ");
                    scanf("%s",&c.laptop_model);
                            printf("\n\t\t\t**********RECORD UPDATED**********\n\n\n");
                    break;
                    case(6):
                    printf("\n\t\t\tEnter new price needs to be paid by consumer:	");
                    scanf("%s",&c.price);
                    printf("\n\t\t\t**********RECORD UPDATED**********\n\n\n");
                    break;
                    case(8):
					exit(1);
                    break;
                    default:
                    printf("\n\t\t\t*******INVALID SELECTION*******");
                    break;
                }
                                                            fwrite(&c,sizeof(c),1,d2);
            }
        }
        fclose(d1);
        fclose(d2);
        d1=fopen("client.txt","w");
        d2=fopen("Record.txt","r");
        while(fread(&c,sizeof(c),1,d2)){
            fwrite(&c,sizeof(c),1,d1);
        }
        fclose(d1);
        fclose(d2);
    }
}
void delete_laptop(){
    FILE *fpo;
    FILE *fpt;
    int r,s;
    printf("\nEnter Laptop ID which you need to delete:     ");
    scanf("%d",&r);
    if(chec_lid(r)==0){
        printf("\n\t\t\t**********LAPTOP ID NOT FOUND**********");
    }
    else{
        fpo=fopen("Laptop.txt","r");
        fpt=fopen("Record.txt","w");
        while(fread(&l,sizeof(l),1,fpo)){
            s=l.id;
            if(s!=r){
                fwrite(&l,sizeof(l),1,fpt);
            }
        }
    fclose(fpo);
    fclose(fpt);
    fpo=fopen("Record.txt","r");
    fpt=fopen("Laptop.txt","w");
    while(fread(&l,sizeof(l),1,fpo)){
        fwrite(&l,sizeof(l),1,fpt);
    }
    printf("\n\t\t\t**********RECORD DELETED**********\n\n\n\n");
    fclose(fpo);
    fclose(fpt); 
    }
}
void delete_client(){
    FILE *fpo;
    FILE *fpt;
    int r,s;
    printf("\nEnter Client ID which you need to delete:     ");
    scanf("%d",&r);
    if(chec_client(r)==0){
        printf("Client ID is not available in the file\n");
    }
    else{
        fpo=fopen("Client.txt","r");
        fpt=fopen("Record.txt","w");
        while(fread(&c,sizeof(c),1,fpo)){
            s=c.id;
            if(s!=r){
                fwrite(&c,sizeof(c),1,fpt);
            }
        }
    fclose(fpo);
    fclose(fpt);
    fpo=fopen("Record.txt","r");
    fpt=fopen("Client.txt","w");
    while(fread(&c,sizeof(c),1,fpo)){
        fwrite(&c,sizeof(c),1,fpt);
    }
    printf("\n\t\t***************RECORD DELETED***************\n\n\n");
    fclose(fpo);
    fclose(fpt); 
    }
}
void update_laptop(){
    int avl;
    FILE *fpt;
    FILE *fpo;
    int s,r,ch;
    printf("Enter Laptop ID to update:	");
    scanf("%d",&r);
    avl=chec_lid(r);
    if(avl==0){
        printf("Laptop ID not found\n");
    }
    else{
        fpo=fopen("laptop.txt","r");
        fpt=fopen("tempfile.txt","w");
        while(fread(&l,sizeof(l),1,fpo)){
            s=l.id;
            if(s!=r){
                fwrite(&l,sizeof(l),1,fpt);
            }
            else{
                printf("\n\t1.BRAND");
                printf("\n\t2.MODEL");
                printf("\n\t3.SERIAL NO");
                printf("\n\t4.DAMAGED PARTS");
                printf("\n\t6.EXIT");
                printf("\nEnter your choice:    ");
                scanf("%d",&ch);
                switch(ch){
                    case(1):
                    printf("Enter Brand:    ");
                    scanf("%s",&l.brand);
                    break;
                    case(2):
                    printf("Enter Model:    ");
                    scanf("%s",&l.model);
                    break;
                    case(3):
                    printf("Enter Serial No:    ");
                    scanf("%s",&l.serial_no);
                    break;
                    case(4):
                    printf("Enter Damaged Parts:	");
					scanf("%s",l.damaged_parts);
					break;
					break;
                    default:
                    printf("Invalid Selection");
                    break;
                }
                fwrite(&l,sizeof(l),1,fpt);
            }
        }
        fclose(fpo);
        fclose(fpt);
        fpo=fopen("laptop.txt","w");
        fpt=fopen("tempfile.txt","r");
        while(fread(&l,sizeof(l),1,fpt)){
            fwrite(&l,sizeof(l),1,fpo);
        }
        fclose(fpo);
        fclose(fpt);
        printf("RECORD UPDATED\n");
    }
}
int main(){
    int option;
    do{
    printf("***********************************SELECT AN OPTION**************************************\n\n\n");
    printf("\t1.Add Details of Client\n");
    printf("\t2.View Details of Client\n");
    printf("\t3.Add Details of Laptop\n");
    printf("\t4.View Details of Laptop\n");
    printf("\t5.Update Details of Client\n");
    printf("\t6.Delete Details of Client\n");
    printf("\t7.Update Details of Laptop\n");
    printf("\t8.Delete Details of Laptop\n");
    printf("\t9.Viewing Expert Details\n");
    printf("\t10.Adding the details of an expert\n");
    printf("\t11.Exit\n\n\n");
    printf("***********************************SELECT AN OPTION**************************************\n");
    printf("\nPlease enter a option:      ");
    scanf("%d",&option);
    switch(option){
        case(1):
        add_client();
        break;
        case(2):
        view_client();
        break;
        case(3):
        add_laptop();
        break;
        case(4):
        view_laptop();
        break;
        case(5):
        update_client();
        break;
        case(6):
        delete_client();
        break;
        case(7):
        update_laptop();
        break;
        case(8):
        delete_laptop();
        break;
        case(9):
        view_expert();
        break;
        case(10):
        add_expert();
        break;
        case(11):
        exit(1);
        break;
        default:
        printf("Choose valid option");
    }}
    while(option!=11);
}
