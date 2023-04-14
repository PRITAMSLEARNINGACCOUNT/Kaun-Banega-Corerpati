#include <stdio.h>
#include <string.h>

char Question_lst[17][100];
char Answer_List[17][100];
char Answer_option_list[68][100];
int hello = 2;
int count = 0;
int money[2] = {1000, 2000,3000,5000,10000,20000,40000,80000,160000,320000};
int option = 0;
int show_option = 0;
int temp_money = 0;
int money1 = 0;

int cheeck(char *str, char lst[][100])
{
    int temp = show_option;
    for (int func1 = 0; func1 < 4; func1++)
    {
        if (strcmp(str, lst[temp]) == 0)
        {
            strcpy(Answer_List[count], str);
            count++;
            return 1;
        }
        temp = temp + 1;
    }
    return 0;
}

int main()
{
    printf("This Part Is For Setting Up The Game(Not For Users)\n");
    int n = 10;
    for (int i = 0; i < n; i++)
    {
        printf("Enter The %d Question\n", i + 1);
        fgets(Question_lst[i], 100, stdin);
        Question_lst[i][strcspn(Question_lst[i], "\n")] = '\0';
    }
    for (int ia = 0; ia < n; ia++)
    {
        printf("\n%s\n", Question_lst[ia]);
        printf("Enter The Options of the above question(maximum of 4 options)\n");
        for (int iaf = 0; iaf < 4; iaf++)
        {
            char lef[100];
            printf("Enter option no. %d\n", iaf + 1);
            fgets(lef, 100, stdin);
            lef[strcspn(lef, "\n")] = '\0';
            strcpy(Answer_option_list[temp_money], lef);
            temp_money++;
        }
    }
    for (int answer1 = 0; answer1 < n; answer1++)
    {
        printf("\nthe queston is %s\n", Question_lst[answer1]);
        printf("now these are the options of the above question\n");
        int temp2 = show_option;
        for (int show = 0; show < 4; show++)
        {
            printf("%s\n", Answer_option_list[temp2]);
            temp2++;
        }
        char string[100];
        printf("Now Enter the Correct answer of the above question from the above options\n");
        fgets(string, 100, stdin);
        string[strcspn(string, "\n")] = '\0';

        while (20 > 4)
        {
            if (cheeck(string, Answer_option_list) == 1)
            {
                break;
            }
            else
            {
                printf("your given answer is not matched in available options.\n");
                printf("Enter the answer of question no. %d\n", answer1 + 1);
                fgets(string, 100, stdin);
                string[strcspn(string, "\n")] = '\0';
                hello++;
                continue;
            }
        }
        show_option = show_option + 4;
    }
    printf("The Kaun Banega Corerpati Is Starting Now For Users\n");
    printf("The Final Amount Of This Game Will Be 7.5 crore Rupees and there are 17 different questions will be asked.\n");

    for (int user_questoin = 0; user_questoin < n; user_questoin++)
    {
        printf("\n");
        printf("So the question no. %d is\n", user_questoin + 1);
        printf("%s\n", Question_lst[user_questoin]);
        printf("So the options are.......\n");
        printf("%s, %s, %s, %s\n", Answer_option_list[option], Answer_option_list[option + 1], Answer_option_list[option + 2], Answer_option_list[option + 3]);
        char answer_store[100];
        fgets(answer_store, 100, stdin);
        answer_store[strcspn(answer_store, "\n")] = '\0';
        if (strcmp(answer_store, Answer_List[user_questoin]) == 0)
        {
            printf("you have given the correct answer, that's why you won Rs.%d\n", money[user_questoin]);
            int temp = money[user_questoin];
            money1 += temp;
        }
        else
        {
            printf("you have given the wrong answer or chosen the wrong option, that's why no money on this question\n");
            break;
        }
        option = option + 4;
    }
    printf("so the total amount of money you are taking to your home is %d\n", money1);

    return 0;
}
