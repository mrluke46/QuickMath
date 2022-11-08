#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<stdbool.h>
#include<unistd.h>
//#include<iostream.h>
#include<conio.h>
#define N 50.0
#define VERSION 1.23
#define BUILD 20220530
#define DEVELOPER "Mr.Snowman"

void header() {
    printf("This program is developed by %s | Version: %.3f | Build: %d", DEVELOPER, VERSION, BUILD);
}

bool start() {
    printf("\nWelcome to QuickMath version %.3f, Stable release. enter any number except 0 to start or else to exit: ", VERSION);
    bool dec;
    scanf("%d", &dec);
    if (dec == 1 ) {
        return true;
    } else {
        return false;
    }
    
}

int toAscii(char value) {
   return value;
}

float generateNumber() {
    srand(time(NULL)); // Set the random config.
    int value;
    value = rand() % 10; // Set the range of random number, 0 - 9.
        
    bool randbool = rand() & 1; // Random the boolean result.
    if (randbool == 1 ) {
        return value;
    } else {
        return value * -1;
    }
    return value;
}

int generateOperator() {
    srand(time(NULL)); // Set the random config.
    int value;
    value = rand() % 4; // Set the range of random number, 0 - 3.
    // (0) + = 43, (1) - = 45, (2) * = 42, (3) / = 47.
    int operator;
    if (value == 0) {
        operator = 43; 
    } else if (value == 1) {
        operator = 45;
    } else if (value == 2) {
        operator = 42;
    } else if (value == 3) {
        operator = 47;
    } 
    return operator;
}

float CAL(float a, float b, int operator) { // + = 43, - = 45, * = 42, / = 47.
    if (operator == 43) {
        //printf("+");
        return a + b;
    }
    else if (operator == 45) {
        //printf("-");
        return a - b;
    }
    else if (operator == 42) {
        //printf("*");
        return a * b;
    }
    else if (operator == 47) {
        //printf("/");
        return a / b;
    }
    return 0;
}

double accuracyCal(int corN) {
    return (((double)corN)/N) * 100;
}

const char* evaluation(double accuracy) {
    
    if (accuracy < 50) {
        return "F";
    } else if (accuracy <= 60 && accuracy >= 50) {
        return "D";
    } else if (accuracy <= 70 && accuracy > 60) {
        return "C";
    } else if (accuracy > 70 && accuracy < 80) {
        return "B";
    } else if (accuracy >= 80 && accuracy <= 85){
        return "A-";
    } else if (accuracy > 85 && accuracy <= 95){
        return "A";
    } else {
        return "A+";
    }
    
}

void result(double timeTaken, int corN) {
    //char *grade = evaluation(accuracyCal(corN));
    printf("\n\n************************ FINAL RESULTS ************************");
    printf("\n- You spent %f seconds to finish 50 math questions.", timeTaken);
    printf("\n- You got %d out of %d correct. Accuracy is %.2f%%.", corN, (int)N, accuracyCal(corN));
    printf("\n- With the accuracy of %.2f%%, you got '%s'!", accuracyCal(corN), evaluation(accuracyCal(corN)));
    printf("\n GOOD LUCK\n\t THANK YOU!");
    printf("\n********************** END OF THE REPORT **********************\n");
}


int main (void) {
    header();
    if (start() == false ) {
        printf("\n BYE BYE!");
        sleep(3);
        exit(0);
    }
    int corN = 0;
    float arrayA[(int)N];
    float arrayB[(int)N];
    float arrayResult[(int)N];
    int arrayOperator[(int)N];
    clock_t t;
    bool run = 1;
    //printf("\n%d\n", generateNumber());
    if (run == 1)
        printf("\n READY!");
        sleep(1);
        printf("\t SET!");
        sleep(1);
        printf("\t GO!");
        t = clock();
        printf("\nTimer starts!\n");
    while (run == 1) {
        //printf("State: running");
        for (int i = 1; i <= N; ++i) {
            float a = generateNumber();
            arrayA[i-1] = a;
            sleep(1);
            float b = generateNumber();
            arrayB[i-1] = b;
            int o = generateOperator();
            float calculation = CAL(a, b, o);
            arrayResult[i-1] = calculation;
            printf("\n------Q%d------", i);
            printf("\n%.1f %c %.1f = ?", a, o, b);
            float ans;
            printf("\nANS: ");
            scanf("%f", &ans);
            if (ans == calculation) {
                corN++;
            }
            printf("RESULT IS %.3f", calculation);
            printf("\n--------------\n");
            
        }
        run = 0;
    }
    if (run == 0) {
        t = clock() - t;
        double time_taken = (((double)t)/CLOCKS_PER_SEC) -50; // calculate the elapsed time, -50 because sleep each question for 1 sec.
        result(time_taken, corN);
        printf("\n Press any key to continue.");
        /*
        char end = getchar();
        printf(": ");
        putchar(end);
        if (end >= 1) {
            exit(0);
        }*/
        
        while(kbhit() == 0) {
            continue;
        } 
        printf("DONE!");
        sleep(1);
    }
    return 0;
}

/*
TO-DO:
- Add the time taken report in mins and seconds.
*/