
#ifndef FILTER_H
#define FILTER_H


#define SIZE 30
#define PI 3.141592653589793

//Structure: the most important part stores all the calculated data
struct filter{
    char name[SIZE];  // RC high-pass,RC low-pass,RL high-pass,RL low-pass
    float input_voltage; //V
    float output_voltage; //V
    float resistor;  // Ω
    double capacitor;  // F
    double inductance;  // H
    float frequency; // HZ
    float cut_off_frequency; // HZ
    float gain; // db
    float phase; // °
    int frequency_sweep_count;
    int time_sweep_count;
    float linear_time_data[1000][2];// time, output voltage
    float linear_frequency_data[1000][4]; //frequency ,output voltage,gain,phase shift
};


//main menu
void main_menu(struct filter*details);
void print_main_menu(void);
int  get_user_input(void);
void select_menu_item(int input,struct filter*details);
void go_back_to_main(struct filter*details);

//sub-menu
void menu_item_1(struct filter*details);
void menu_item_2(struct filter*details);
void menu_item_3(struct filter*details);
void menu_item_4(struct filter*details);
void menu_item_5(struct filter*details);//saving experimental data

//Resistance calculation
void Series_Resistance_Calculation(struct filter*details);
void Parallel_Resistance_Calculation(struct filter*details);

//RC circuit function
void RC_LP_Filter_Analysis(struct filter*details);
void RC_HP_Filter_Analysis(struct filter*details);

//RL circuit function
void RL_LP_Filter_Analysis(struct filter*details);
void RL_HP_Filter_Analysis(struct filter*details);

//Sweep function
void Frequency_output_voltage(struct filter*details);
void Time_output_voltage(struct filter*details);

//related parameter calculations.
void RC_LP_Filter_calculation(struct filter*details);
void RC_HP_Filter_calculation(struct filter*details);
void RL_LP_Filter_calculation(struct filter*details);
void RL_HP_Filter_calculation(struct filter*details);

//Print the analysed results
void print_analysis_data(struct filter*details);

//Input function.
void enter_the_value(struct filter*details,int mode);

//Print the sweep results in table form.
void frequency_sweep_table(struct filter*details);
void time_sweep_table(struct filter*details);

//Print the sweep results in image form.
void frequency_sweep_image(struct filter*details);
void time_sweep_image(struct filter*details);

//Sweep data storage.
void Data_storage_frequency(struct filter*details);
void Data_storage_time(struct filter*details,float time1);


#endif

