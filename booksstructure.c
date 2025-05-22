
#include <stdio.h>
#include <stdlib.h>


struct book
{
    
    char author[30];
    char title[30];
    float book_price;
};


void input()
{
    FILE *file = fopen("books.txt", "a");
    struct book set;
    printf("Enter the author's name: ");
    scanf("%s", set.author);
    printf("Enter the title of the book: ");
    scanf("%s", set.title);
    printf("Enter the price of the book: ");
    scanf("%f", &set.book_price);

    fprintf(file, "%s %s %.2f\n", set.author, set.title, &set.book_price);
    fclose(file);
}
void display()
{
    FILE *file = fopen("books.txt", "r");
    struct book set;

    printf("\nBook Details:\n");
    while (fscanf(file, "%s %s %f", set.author, set.title, &set.book_price) != EOF)
    {
        printf("author: %s, Title: %s, Price: %.2f\n", set.author, set.title, set.book_price);
    }
    fclose(file);
}

int main()
{
    int choice;
    do
    {
        printf("\n1. Add Book Details\n2. View Book Details\n3. Exit\nChoice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            input();
            break;
        case 2:
            display();
            break;
        case 3:
            exit(0);
        default:
            printf("Invalid choice!\n");
        }
    } while (1);

    return 0;
}