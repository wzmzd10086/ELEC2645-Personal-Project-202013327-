#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#include<string.h>
#include "filter.h"

//=================================================================
//Main menu related functions
void main_menu(struct filter*details) {
    print_main_menu();
    int input = get_user_input();
    select_menu_item(input,details);
}

//Output the main menu options
void print_main_menu(void) {
    printf("\n----------- Main Menu -----------------\n");
    printf("1. Resistor\t\t\n");
    printf("2. RC Filter\t\n");
    printf("3. RL Filter\t\n");
    printf("4. Time-domain / frequency-domain scanning\t\n");
    printf("5. Save File\t\t\t\n");
    printf("6. Exit\t\t\t\t\n");
    printf("---------------------------------------\n");
}

//User inputs the option
int get_user_input(void) {
    int input;
    float temps;
    printf("\nSelect item: ");
    while((scanf("%f", &temps) != 1) || (temps != (int) temps)|| (temps < 1) || (temps > 6))
       {
        printf("\nError, input an integer between 1 and 6");
        while(getchar() != '\n');
       }
    input= (int) temps;
    return input;
}

//Use a switch statement to call the related function for each option.
void select_menu_item(int input,struct filter*details) {
    switch (input) {
        case 1: menu_item_1(details); break;
        case 2: menu_item_2(details); break;
        case 3: menu_item_3(details); break;
        case 4: menu_item_4(details); break;
        case 5: menu_item_5(details); break;
        case 6: printf("Exiting program...\n"); exit(0);
        default: printf("Invalid selection. Exiting...\n"); exit(1);
    }
}

//return to main menu function
void go_back_to_main(struct filter* details) {
    char input;
    do {
        printf("\nEnter 'b' or 'B' to go back to main menu: ");
        scanf(" %c", &input);
    } while (input != 'b' && input != 'B');
    main_menu(details);
}

//===============================================================================
//four sub-menus
void menu_item_1(struct filter*details) {
     int choice=0;
    do{  
       float temp=0.0;
       //output the sub menu 
       printf("\n--- Resistor Calculations ---\n");
       printf("1. Series\n");
       printf("2. Parallel\n");
       printf("3. Back to Main Menu\n");
       printf("4. Exit\n");
       printf("Select option:");
       while((scanf("%f", &temp) != 1) || (temp != (int) temp)|| (temp < 1) || (temp > 4))
          {
           printf("\nError, input an integer between 1 and 4");
           while(getchar() != '\n');
          }
       choice= (int) temp;
       switch(choice){
       case 1: Series_Resistance_Calculation(details); break;
       case 2: Parallel_Resistance_Calculation(details); break;
       case 3: go_back_to_main(details); break;
       case 4:  printf("Exiting program...\n"); exit(0);
       default: printf("Invalid selection. Exiting...\n"); exit(1);         
      }
   }while(choice<3);
}


void menu_item_2(struct filter*details){
    int choice;
    do{
        float temp;
        printf("\n--------- RC Menu ----------\n");
        printf("1. Low-pass Filter Analysis\n");
        printf("2. High-pass Filter Analysis\n");
        printf("3. Back to Main Menu\n");
        printf("4. Exit\n");
        printf("Select item: ");
        while((scanf("%f", &temp) != 1) || (temp != (int) temp)|| (temp < 1) || (temp > 4)){
            printf("\nError, input an integer between 1 and 4");
            while(getchar() != '\n');
        }
        choice= (int) temp;
        switch(choice){
           case 1: RC_LP_Filter_Analysis(details); break;
           case 2: RC_HP_Filter_Analysis(details); break;
           case 3: go_back_to_main(details); break;
           case 4:  printf("Exiting program...\n"); exit(0);
           default: printf("Invalid selection. Exiting...\n"); exit(1);     
        }    
    }while(choice<3);
}


void menu_item_3(struct filter*details){
    int choice;
    do{
        float temp;
        printf("\n--------- RL Menu ----------\n");
        printf("1. Low-pass Filter Analysis\n");
        printf("2. High-pass Filter Analysis\n");
        printf("3. Back to Main Menu\n");
        printf("4. Exit\n");
        printf("Select item: ");
        while((scanf("%f", &temp) != 1) || (temp != (int) temp)|| (temp < 1) || (temp > 4))
            {
             printf("\nError, input an integer between 1 and 4");
             while(getchar() != '\n');
            }
        choice= (int) temp;   
        switch(choice){
        case 1: RL_LP_Filter_Analysis(details); break;
        case 2: RL_HP_Filter_Analysis(details); break;
        case 3: go_back_to_main(details); break;
        case 4:  printf("Exiting program...\n"); exit(0);
        default: printf("Invalid selection. Exiting...\n"); exit(1);
        }
    }while(choice<3);
  
}

void menu_item_4(struct filter*details){
    int choice;
    do{
        float temp;
        printf("\n--------- scanning Menu ----------\n");
        printf("1.Frequency-domain Scanning\n");
        printf("2.Time-domain Scanning\n");
        printf("3.Back to Main Menu\n");
        printf("4.Exit\n");
        printf("Select item: ");
        while((scanf("%f", &temp) != 1) || (temp != (int) temp)|| (temp < 1) || (temp > 4))
            {
             printf("\nError, input an integer between 1 and 4");
             while(getchar() != '\n');
            }
        choice= (int) temp;   
        switch(choice){
        case 1:Frequency_output_voltage(details); break;
        case 2:Time_output_voltage(details); break;
        case 3: go_back_to_main(details); break;
        case 4:  printf("Exiting program...\n"); exit(0);
        default: printf("Invalid selection. Exiting...\n"); exit(1);
        }
    }while(choice<3);
  
}

//=================================================================================
//The fifth menu is a save file function.
void menu_item_5(struct filter*details){
      int i;
      int j;
      FILE *filePtr;
      filePtr = fopen("Experimental_data.txt","w");
      if(filePtr == NULL)
      {
        printf("\nError, cannot open the file\n");
        exit(1);
      }
      fprintf(filePtr,"\nParameter\t\t\t\tValue\n");
      fprintf(filePtr,"Filter Type:\t\t\t%s\n", details->name);
      fprintf(filePtr,"Input Voltage(Vin)\t\t%.4f V\n", details->input_voltage);
      fprintf(filePtr,"Output Voltage(Vout)\t%.4f V\n", details->output_voltage);
      fprintf(filePtr,"Resistance(R)\t\t\t%.4f Ω\n", details->resistor);
      if((strcmp(details->name,"RC-low-pass Filter")==0) || (strcmp(details->name,"RC-high-pass Filter")==0)){
        fprintf(filePtr,"Capacitance(C)\t\t\t%.12lf F\n", details->capacitor);
     }
     else{
        fprintf(filePtr,"Inductance(L)\t\t\t%.12lf H\n", details->inductance);
     }
     fprintf(filePtr,"Frequency(f)\t\t\t%.4f Hz\n", details->frequency);
     fprintf(filePtr,"Cutoff Frequency(fc)\t%.4f Hz\n", details->cut_off_frequency);
     fprintf(filePtr,"Gain(dB)\t\t\t\t%.4f dB\n", details->gain);
     fprintf(filePtr,"Phase Shift(°)\t\t\t%.4f °\n", details->phase);     
     fprintf(filePtr,"\n| %12s | %12s | %12s | %12s |\n", "Freq(Hz)", "Vout(V)", "Gain(dB)", "Phase(°)");
     for(i=0; i<details->frequency_sweep_count; i++){
        fprintf(filePtr,"| %12.4f | %12.4f | %12.4f | %12.4f |\n",
        details->linear_frequency_data[i][0],
        details->linear_frequency_data[i][1],
        details->linear_frequency_data[i][2],        
        details->linear_frequency_data[i][3]);
    }
    fprintf(filePtr,"\n| %12s | %12s |\n","Time(s)", "Vout(V)");
    for(j=0; j<details->time_sweep_count; j++){
        fprintf(filePtr,"| %12.4f | %12.4f |\n",
        details->linear_time_data[j][0],
        details->linear_time_data[j][1]); 
    }
     fclose(filePtr);
     printf("\nExperiment data saved successfully to Experiment_data.txt\n");    
     go_back_to_main(details);
}

//=================================================================================
//Resistance calculation related functions
void Series_Resistance_Calculation(struct filter*details){
    details->resistor = 0.0;
    float R1[SIZE];
    int count=0;
    float temp=0.0;
    int i;
    printf("\nEnter number of resistors in series (2-%d): ", SIZE);
    while(scanf("%f", &temp) != 1 || (temp != (int) temp) || temp < 2 || temp > SIZE) {
        printf("Error, enter integer between 2 and %d: ", SIZE);
        while(getchar()!='\n');
    }
    count = (int) temp;    
    for(i=0;i<count;i++){
        printf("\nEnter the %d series resistor value:",i+1);
        while(scanf("%f", &R1[i]) != 1|| R1[i] <= 0)
        {
           printf("\nError, Please enter a valid number.");
           while(getchar() != '\n');
        }
        details->resistor = details->resistor+R1[i];
    }
    printf("Total series resistance =%f\n",details->resistor);
}

void Parallel_Resistance_Calculation(struct filter*details){
    details->resistor = 0.0;
    float R1[SIZE];
    float resistance1=0.0;
    int i=0;
    int count=0;
    float temp=0.0;
    printf("\nEnter number of resistors in parallel (2-%d): ", SIZE);
    while(scanf("%f", &temp) != 1 || (temp != (int) temp) || temp < 2 || temp > SIZE) {
        printf("Error, enter integer between 2 and %d: ", SIZE);
        while(getchar()!='\n');
    }
    count = (int) temp;
    for(i=0;i<count;i++){
        printf("\nEnter the %d Parallel resistor value:",i+1);
        while(scanf("%f", &R1[i]) != 1|| R1[i] <= 0)
        {
           printf("\nError, Please enter a valid number.");
           while(getchar() != '\n');
        }
        resistance1 = resistance1+1.0/R1[i];
    }
    
    details->resistor = 1.0 / resistance1;
    printf("Total parallel resistance =%f\n",details->resistor);    
}

//==============================================================================
//Filter analysis function.
void RC_LP_Filter_Analysis(struct filter*details){
    strcpy(details->name, "RC-low-pass Filter");
    enter_the_value(details,1);
    RC_LP_Filter_calculation(details);
    print_analysis_data(details);
}

void RC_HP_Filter_Analysis(struct filter*details){
    strcpy(details->name, "RC-high-pass Filter");
    enter_the_value(details,1);
    RC_HP_Filter_calculation(details);
    print_analysis_data(details);
}

void RL_LP_Filter_Analysis(struct filter*details){
    strcpy(details->name, "RL-low-pass Filter");
    enter_the_value(details,1);
    RL_LP_Filter_calculation(details);
    print_analysis_data(details);
}

void RL_HP_Filter_Analysis(struct filter*details){
    strcpy(details->name, "RL-high-pass Filter");
    enter_the_value(details,1);
    RL_HP_Filter_calculation(details);
    print_analysis_data(details);
}

///================================================================================
///Frequency-domain analysis
void Frequency_output_voltage(struct filter*details){
    float H=0.0;
    float temp=0.0;
    int choice1;
    int choice;
    float step=0.0;
    printf("\nPlease choose whether this circuit is RL or RC(1.RL 2.RC):");
    while((scanf("%f", &temp) != 1) || (temp != (int) temp)|| (temp < 1) || (temp > 2))
       {
        printf("\nError, input an integer between 1 and 2");
        while(getchar() != '\n');
       }
    choice1=(int) temp;
    printf("\nPlease choose whether your filter is low-pass or high-pass (1. high-pass 2. low-pass):");
    while((scanf("%f", &temp) != 1) || (temp != (int) temp)|| (temp < 1) || (temp > 2))
       {
        printf("\nError, input an integer between 1 and 2");
        while(getchar() != '\n');
       }
    choice= (int) temp;
    details->frequency_sweep_count=0;
    details->time_sweep_count=0;
    details->cut_off_frequency=0.0;
    if(choice==1 && choice1==1){
        strcpy(details->name, "RL-high-pass Filter");
        enter_the_value(details,0);
        details->cut_off_frequency=details->resistor/(2 * PI * details->inductance); 
        step = details->cut_off_frequency/50;
        for(details->frequency=0;details->frequency<details->cut_off_frequency*15;details->frequency=details->frequency+step){
            RL_HP_Filter_calculation(details);
            Data_storage_frequency(details);
        }
    }
    else if(choice==2 && choice1==1){
        strcpy(details->name, "RL-low-pass Filter");
        enter_the_value(details,0);
        details->cut_off_frequency=details->resistor/(2 * PI * details->inductance); 
        step = details->cut_off_frequency/50;
        for(details->frequency=0;details->frequency<details->cut_off_frequency*15;details->frequency=details->frequency+step){
            RL_LP_Filter_calculation(details);
            Data_storage_frequency(details);
        }
    }
    else if(choice==1 && choice1==2){
        strcpy(details->name, "RC-high-pass Filter");
        enter_the_value(details,0);
        details->cut_off_frequency=1.0/(2*PI*details->resistor * details->capacitor); 
        step = details->cut_off_frequency/50;
        for(details->frequency=0;details->frequency<details->cut_off_frequency*15;details->frequency=details->frequency+step){
            RC_HP_Filter_calculation(details);
            Data_storage_frequency(details);
        }
    }
    else if(choice==2 && choice1==2){
        strcpy(details->name, "RC-low-pass Filter");
        enter_the_value(details,0);
        details->cut_off_frequency=1.0/(2*PI*details->resistor * details->capacitor); 
        step = details->cut_off_frequency/50;
        for(details->frequency=0;details->frequency<details->cut_off_frequency*15;details->frequency=details->frequency+step){
            RC_LP_Filter_calculation(details);
            Data_storage_frequency(details);
        }
    }
    if(details->frequency_sweep_count >= 1000){
        printf("Warning: The sampling frequency is beyond the allowed limit\n");
        exit(0);
    }
    int num;
    printf("\nSelect output format (1. Table 2. Graph):");
    while((scanf("%f", &temp) != 1) || (temp != (int) temp)|| (temp < 1) || (temp > 2))
       {
        printf("\nError, input an integer between 1 and 2");
        while(getchar() != '\n');
       }
    num = (int) temp;
    if(num==1){
        frequency_sweep_table(details);
    }
    else{
        frequency_sweep_image(details);
    }
}

//time-domain analysis functions
void Time_output_voltage(struct filter*details){
    float temp;
    int choice;
    int choice1;
    float step=0.0;
    float time1=0.0;
    float time_constant;
    printf("\nPlease note that time-domain scanning only works for DC input.");
    details->frequency=0;
    details->time_sweep_count = 0; 
    details->frequency_sweep_count = 0; 
    printf("\nPlease choose whether this circuit is RL or RC(1.RL 2.RC):");
    while((scanf("%f", &temp) != 1) || (temp != (int) temp)|| (temp < 1) || (temp > 2))
       {
        printf("\nError, input an integer between 1 and 2");
        while(getchar() != '\n');
       }
    choice1=(int) temp;
    printf("\nPlease choose whether your filter is low-pass or high-pass (1. high-pass 2. low-pass)");
    while((scanf("%f", &temp) != 1) || (temp != (int) temp)|| (temp < 1) || (temp > 2))
       {
        printf("\nError, input an integer between 1 and 2");
        while(getchar() != '\n');
       }    
    choice= (int) temp;
    if(choice1==1 && choice==1){
        strcpy(details->name, "RL-high-pass Filter");
        enter_the_value(details,0);
        time_constant = details->inductance / details->resistor;  
        step = time_constant / 50.0;
        for(time1=0;time1<5*time_constant;time1=time1+step){
            details->output_voltage = details->input_voltage*exp(-time1/time_constant);
            Data_storage_time(details,time1);
        }
    }
    else if(choice1==1 && choice==2){
        strcpy(details->name, "RL-low-pass Filter");
        enter_the_value(details,0);
        time_constant = details->inductance / details->resistor;  
        step = time_constant / 50.0;
        for(time1=0;time1<5*time_constant;time1=time1+step){
            details->output_voltage = details->input_voltage*(1-exp(-time1/time_constant));
            Data_storage_time(details,time1);
        }
    }
    else if(choice1==2 && choice==1){
        strcpy(details->name, "RC-high-pass Filter");
        enter_the_value(details,0);
        time_constant = details->capacitor * details->resistor;  
        step = time_constant / 50.0;
        for(time1=0;time1<5*time_constant;time1=time1+step){
            details->output_voltage = details->input_voltage*exp(-time1/time_constant);
            Data_storage_time(details,time1);
        }
    }
    else if(choice1==2 && choice==2){
        strcpy(details->name, "RC-low-pass Filter");
        enter_the_value(details,0);
        time_constant = details->capacitor * details->resistor;  
        step = time_constant / 50.0;
        for(time1=0;time1<5*time_constant;time1=time1+step){
            details->output_voltage = details->input_voltage*(1-exp(-time1/time_constant));
            Data_storage_time(details,time1);
        }
    }
    if(details->time_sweep_count >= 1000){
    printf("Warning: The sampling frequency is beyond the allowed limit\n");
    exit(0);
    }
    int num;
    printf("\nSelect output format (1. Table 2. Graph):");
    while((scanf("%f", &temp) != 1) || (temp != (int) temp)|| (temp < 1) || (temp > 2))
       {
        printf("\nError, input an integer between 1 and 2");
        while(getchar() != '\n');
       }
    num = (int) temp;
    if(num==1){
        time_sweep_table(details);
    }
    else{
        time_sweep_image(details);
    }
}
//===================================================================================================
//General output module
void print_analysis_data(struct filter*details){
    printf("\nParameter\t\t\tValue\n");
    printf("Filter Type\t\t\t%s\n", details->name);
    printf("Input Voltage(Vin)\t\t%.4f V\n", details->input_voltage);
    printf("Output Voltage(Vout)\t\t%.4f V\n", details->output_voltage);
    printf("Resistance(R)\t\t\t%.4f Ω\n", details->resistor);
    if((strcmp(details->name,"RC-low-pass Filter")==0) || (strcmp(details->name,"RC-high-pass Filter")==0)){
        printf("Capacitance(C)\t\t\t%.12lf F\n", details->capacitor);
    }
    else{
         printf("Inductance(L)\t\t\t%.12lf H\n", details->inductance);
    }
    printf("Frequency(f)\t\t\t%.4f Hz\n", details->frequency);
    printf("Cutoff Frequency(fc)\t\t%.4f Hz\n", details->cut_off_frequency);
    printf("Gain(dB)\t\t\t%.4f dB\n", details->gain);
    printf("Phase Shift(°)\t\t\t%.4f °\n", details->phase);   
} 
//============================================================================================
//Input module
void enter_the_value(struct filter*details,int mode){
    printf("\nplease enter the input voltage:");
    while(scanf("%f", &details->input_voltage) != 1|| details->input_voltage <= 0)
        {
           printf("\nError, Please enter a valid number.");
           while(getchar() != '\n');
        }
    if(mode==1){
         printf("\nplease enter the input frequency of the input voltage:");
         while(scanf("%f", &details->frequency) != 1|| details->frequency <= 0)
        {
           printf("\nError, Please enter a valid number.");
           while(getchar() != '\n');
        }
    }
    printf("\nplease enter the resistance value:");
    while(scanf("%f", &details->resistor) != 1|| details->resistor <= 0)
        {
           printf("\nError, Please enter a valid number.");
           while(getchar() != '\n');
        }
    if((strcmp(details->name,"RC-low-pass Filter")==0) || (strcmp(details->name,"RC-high-pass Filter")==0)){
        printf("\nplease enter the capacitor value:");
        while(scanf("%lf", &details->capacitor) != 1|| details->capacitor <= 0)
        {
           printf("\nError, Please enter a valid number.");
           while(getchar() != '\n');
        }    
    }
    else{
        printf("\nplease enter the inductance value:");
        while(scanf("%lf", &details->inductance) != 1|| details->inductance <= 0)
        {
           printf("\nError, Please enter a valid number.");
           while(getchar() != '\n');
        }           
    }
}


//===============================================================================
//Calculation module

void RC_LP_Filter_calculation(struct filter*details){
    float H=0.0;
    details->cut_off_frequency=1.0/(2 * PI * details->resistor * details->capacitor);
    H = 1.0/(sqrt(1.0 + pow(details->frequency/details->cut_off_frequency, 2)));
    details->output_voltage =  details->input_voltage * H;
    details->phase = -(atan(details->frequency / details->cut_off_frequency)) * 180 / PI;
    details-> gain = 20 * log10(H);
}


void RC_HP_Filter_calculation(struct filter*details){
    float H=0.0;
    details->cut_off_frequency=1.0/(2 * PI * details->resistor * details->capacitor);
    H = (details->frequency/details->cut_off_frequency)/(sqrt(1.0 + pow(details->frequency/details->cut_off_frequency, 2)));
    details->output_voltage =  details->input_voltage * H;
    details->phase = atan(details->cut_off_frequency / details->frequency) * 180 / PI;
    details-> gain = 20 * log10(H);
}

void RL_LP_Filter_calculation(struct filter*details){
    float H=0.0;
    details->cut_off_frequency=details->resistor/(2 * PI * details->inductance);
    H = 1.0/(sqrt(1.0 + pow(details->frequency/details->cut_off_frequency, 2)));
    details->output_voltage =  details->input_voltage * H;
    details->phase = -(atan(details->frequency / details->cut_off_frequency)) * 180 / PI;
    details-> gain = 20 * log10(H);
}

void RL_HP_Filter_calculation(struct filter*details){
    float H=0.0;
    details->cut_off_frequency=details->resistor/(2 * PI * details->inductance);
    H = (details->frequency/details->cut_off_frequency)/(sqrt(1.0 + pow(details->frequency/details->cut_off_frequency, 2)));
    details->output_voltage =  details->input_voltage * H;
    details->phase = 90- atan(details->cut_off_frequency / details->frequency) * 180 / PI;
    details-> gain = 20 * log10(H);
}

//================================================================================
//Sweep data storage module
void Data_storage_frequency(struct filter*details){
    details->linear_frequency_data[details->frequency_sweep_count][0]=details->frequency;
    details->linear_frequency_data[details->frequency_sweep_count][1]=details->output_voltage;
    details->linear_frequency_data[details->frequency_sweep_count][2]=details-> gain;
    details->linear_frequency_data[details->frequency_sweep_count][3]=details->phase;
    details->frequency_sweep_count++;
}

void Data_storage_time(struct filter*details,float time1){
    details->linear_time_data[details->time_sweep_count][0]=time1;
    details->linear_time_data[details->time_sweep_count][1]=details->output_voltage;
    details->time_sweep_count++;
}

//================================================================================
//Table output module
void frequency_sweep_table(struct filter*details){
    printf("\n| %12s | %12s | %12s | %12s |\n", "Freq(Hz)", "Vout(V)", "Gain(dB)", "Phase(°)");
    for(int i=0; i<details->frequency_sweep_count; i++){
        printf("| %12.4f | %12.4f | %12.4f | %12.4f |\n",
        details->linear_frequency_data[i][0],
        details->linear_frequency_data[i][1],
        details->linear_frequency_data[i][2],
        details->linear_frequency_data[i][3]);
    }
}

void time_sweep_table(struct filter*details){
    printf("\n| %12s | %12s |\n","Time(s)", "Vout(V)");
    for(int i=0; i<details->time_sweep_count; i++){
        printf("| %12.4f | %12.4f |\n",
        details->linear_time_data[i][0],
        details->linear_time_data[i][1]);
    }
}


//==============================================================================
//Image output module
void frequency_sweep_image(struct filter*details){
    float i=0.0;
    int number=0;
    int j=0;
    float f;
    float out=0.0;
    int count=0;
    float max=0.0;
    int type;
    float temp;
    printf("\nChoose the data type you need(1.vout 2.gain 3.phase):");
    while((scanf("%f", &temp) != 1) || (temp != (int) temp)|| (temp < 1) || (temp > 3)){
        printf("\nError, input an integer between 1 and 3");
        while(getchar() != '\n');
    }
    type= (int) temp;
    if(type==1 || type==3){
       for(int j=0;j<details->frequency_sweep_count;j++){ 
           if(fabs(details->linear_frequency_data[j][type]) > max){ 
               max = fabs(details->linear_frequency_data[j][type]); //“fabs,” cppreference.com. https://en.cppreference.com/w/c/numeric/math/fabs (accessed Dec. 02, 2025)
           }
        }
        for(i=1.0;i<details->frequency_sweep_count;i=i*sqrt(2)){
            number=(int) i;
            out=fabs(details->linear_frequency_data[number][type]);
            f=details->linear_frequency_data[number][0];
            printf(" %8.2fHz |",f);
            count= (out/max)*60;
            for(j=0;j<count;j++){
                printf("*");
            }    
        printf("\n");
        }
    printf("----------------------------------------------------------------------------");
    }
    else{
        float gain[1000];
        for(int j=0;j<details->frequency_sweep_count;j++){
            gain[j]=pow(10, details->linear_frequency_data[j][type] / 20.0);
            if(gain[j] > max){
                max = gain[j];
            }
        }
        for(i=1.0;i<details->frequency_sweep_count;i=i*sqrt(2)){
        number=(int) i;
        out=gain[number];
        f=details->linear_frequency_data[number][0];
        printf(" %8.2fHz |",f);
        count= (out/max)*60;
        for(j=0;j<count;j++){
            printf("*");
        }    
        printf("\n");
        }
     printf("--------------------------------------------------------------------------");
    }
}


void time_sweep_image(struct filter*details){
    int i=0;
    int j=0;
    float max=0.0;
    float step=0.0;
    float out=0.0;
    int number=0;
    float time1=0.0;
    int count=0;
    for(i=0;i<details->time_sweep_count;i++){
        if(details->linear_time_data[i][1]>max){
            max=details->linear_time_data[i][1];
        }
    }
    for(step=1.0;step<details->time_sweep_count;step=step*sqrt(2)){
        number=(int) step;
        out=details->linear_time_data[number][1];
        time1=details->linear_time_data[number][0];
        printf(" %8.7fs |",time1);
        count= (out/max)*60;
        for(j=0;j<count;j++){
            printf("*");
        }
        printf("\n");
    }
    printf("-------------------------------------------------------------------------");
}

//=========================================================================================

