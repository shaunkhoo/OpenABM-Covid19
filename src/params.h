/*
 * params.h
 *
 *  Created on: 5 Mar 2020
 *      Author: hinchr
 */

#ifndef PARAMS_H_
#define PARAMS_H_

#include "constant.h"
#include "structure.h"

/************************************************************************/
/****************************** Structures  *****************************/
/************************************************************************/

typedef struct{
	long rng_seed; 					// number used to seed the GSL RNG
	char input_param_file[INPUT_CHAR_LEN];	// path to input parameter file
	char input_household_file[INPUT_CHAR_LEN]; //path to input household demographics file
	char output_file_dir[INPUT_CHAR_LEN];	// path to output directory
	int param_line_number;			// line number to be read from parameter file
	long param_id;					// id of the parameter set
	long n_total;  					// total number of people
	int days_of_interactions;		// the number of days of interactions to keep
	int end_time;				    // maximum end time
	int n_seed_infection;			// number of people seeded with the infections

	double mean_random_interactions[N_AGE_TYPES]; // mean number of random interactions each day
	double sd_random_interactions[N_AGE_TYPES];   // sd number of random interactions each day
	int random_interaction_distribution;          // distribution from which each person random interactions are drawn
	double mean_work_interactions[N_OCCUPATION_NETWORKS];// mean number of regular work interactions
	double daily_fraction_work;      			// fraction of daily work interactions without social-distancing
	double daily_fraction_work_used[N_OCCUPATION_NETWORKS];  // fraction of daily work interactions with social-distancing
	double child_network_adults;				// fraction of adults in the child network
	double elderly_network_adults;				// fraction of adults in the elderly network
	double work_network_rewire;					// rewire parameter on the Watts-Strogatz work networks

	double mean_infectious_period;  // mean period in days that people are infectious
	double sd_infectious_period;	// sd of period in days that people are infectious
	double infectious_rate;         // mean total number of people infected for a mean person

	double relative_susceptibility[N_AGE_GROUPS]; // relative susceptibility of an age group
	double adjusted_susceptibility[N_AGE_GROUPS]; // adjusted susceptibility of an age group (normalising for interactions)

	double relative_transmission[N_INTERACTION_TYPES]; 		// relative transmission rate by the type of interactions (e.g. household/workplace/random) w/o social distance
	double relative_transmission_used[N_INTERACTION_TYPES]; // relative transmission rate by the type of interactions (e.g. household/workplace/random)

	double mean_time_to_symptoms;   // mean time from infection to symptoms
	double sd_time_to_symptoms;		// sd time from infection to symptoms

	double hospitalised_fraction[N_AGE_GROUPS];   // fraction of symptomatic patients requiring hospitalisation
	double critical_fraction[N_AGE_GROUPS];  	  // fraction of hospitalised patients who require ICU treatment
	double fatality_fraction[N_AGE_GROUPS];  	  // fraction of ICU patients who die

	double mean_time_to_hospital;   // mean time from symptoms to hospital
	double mean_time_to_critical;   // mean time from hospitalised to critical care
	double sd_time_to_critical;   // sd time from hospitalised to critical care

	double mean_time_to_recover;	// mean time to recovery if hospitalisation is not required (days)
	double sd_time_to_recover;  	// sd time to recovery if hospitalisation is not required (days)
	double mean_time_to_death;		// mean time to death after hospital
	double sd_time_to_death;		// sd time to death after hospital

	double household_size[N_HOUSEHOLD_MAX];// ONS UK number of households with 1-6 person (in thousands)
	double population[N_AGE_GROUPS];		// ONS stratification of population (in millions)

	double fraction_asymptomatic[N_AGE_GROUPS]; // faction who are asymptomatic
	double asymptomatic_infectious_factor;  // relative infectiousness of asymptomatics

	double mild_fraction[N_AGE_GROUPS]; 	// faction who just have mild symptoms
	double mild_infectious_factor;  		// relative infectiousness of people with mild symptoms

	double mean_asymptomatic_to_recovery;   // mean time to recovery for asymptomatics
	double sd_asymptomatic_to_recovery;     // sd of time to recovery for asymptomatics

	double mean_time_hospitalised_recovery; // mean time to recover if hospitalised
	double sd_time_hospitalised_recovery;   // sd time to recover if hospitalised
	double mean_time_critical_survive;      // mean time to survive if critical
	double sd_time_critical_survive;        // sd time to survive if critical
	double location_death_icu[N_AGE_GROUPS];// whether death occurs in the ICU or outside

	int quarantined_daily_interactions; 	// number of interactions a quarantined person has
	int hospitalised_daily_interactions; 	// number of interactions a hopsitalised person has

	int quarantine_days;					// number of days of previous contacts to quarantine
	double self_quarantine_fraction;		// fraction of people who self-quarantine when show symptoms

	int trace_on_symptoms;   // contract trace on symptoms
	int trace_on_positive;   // contract trace on positive result
	int retrace_on_positive; // repeat contract tracing on a positive test if already tested on symptoms

	int quarantine_length_self;				// max length of quarantine if self-quarantine on symptoms
	int quarantine_length_traced_symptoms;	// max length of quarantine if contact-traced from a index case with only symptoms
	int quarantine_length_traced_positive;	// max length of quarantine if contact-traced from a index case with a positive test
	int quarantine_length_positive;			// max length of quarantine if receive positive test result
	double quarantine_dropout_self;			// daily dropout rate if self-quarantined
	double quarantine_dropout_traced_symptoms;	// daily dropout rate if contact-traced from a index case with only symptoms
	double quarantine_dropout_traced_positive;	// daily dropout rate if contact-traced rom a index case with a positive test
	double quarantine_dropout_positive;     	// daily dropout rate if receive positive test result

	double quarantine_compliance_traced_symptoms; // probability that someone complies with a amber quarantine message
	double quarantine_compliance_traced_positive; // probability that someone complies with a red quarantine message

	int quarantine_on_traced;				// immediately quarantine those who are contact traced
	int quarantine_smart_release_day;		// number of days until smart release on no contacts

	double traceable_interaction_fraction;  // the proportion of interactions which are traceable even if both users have app
	double manual_traceable_fraction_random; // the proportion of interactions on the random network that are manually traceable
	double manual_traceable_fraction_occupation; // the proportion of interactions on the occupation network that are manually traceable
	double manual_traceable_fraction_household; // the proportion of interactions on the household network that are manually traceable
	int manual_trace_delay; // how many days of a delay is there before manual tracing results come out
	int tracing_network_depth;				// the number of layers in the interaction network to recursively trace
	int allow_clinical_diagnosis;			// allow a hospital clinical diagnosis to trigger interventions

	int quarantine_household_on_symptoms;   	   // quarantine other household members when someone shows symptoms
	int quarantine_household_on_positive;   	   // quarantine other household members when someone tests positive
	int quarantine_household_on_traced_symptoms;   // quarantine other household members when someone is contact traced and index has symptoms
	int quarantine_household_on_traced_positive;   // quarantine other household members when someone is contact traced and index is positive
	int quarantine_household_contacts_on_positive; // quarantine the contacts of other household members when someone tests positive
	int quarantine_household_contacts_on_symptoms; // quarantine the contacts of other household members when someone gets symptoms

	int test_on_symptoms;					// carry out a test on those with symptoms
	int test_on_traced;						// carry out a test on those with positive test results
	int test_insensitive_period;			// number of days until a test is sensitive (delay test of recent contacts)
	int test_result_wait;					// number of days to wait for a test result
	int test_order_wait;					// minimum number of days to wait for a test to be taken
	
	double app_users_fraction[N_AGE_GROUPS];// Proportion of the population that use the app by age
	int app_turned_on;						// is the app turned on
	int app_turn_on_time;   				// time after which the app is usable
	double daily_non_cov_symptoms_rate; 				// Rate of seasonal flu

	double lockdown_occupation_multiplier[N_OCCUPATION_NETWORKS];   // during lockdown distancing this multiplier is applied to the fraction of work network connections made
	double lockdown_random_network_multiplier; 		// during lockdown distancing this multiplier is applied to the fraction of random network connections made
	double lockdown_house_interaction_multiplier;  	// during lockdown this multiplier is applied to the strengin of home connections
	int lockdown_time_on;							// lockdown turned on at this time
	int lockdown_time_off;							// lockdown turned off at this time
	int lockdown_on;								// is lockdown currently on

	int lockdown_elderly_time_on;					// lockdown elderly turned on at this time
	int lockdown_elderly_time_off;					// lockdown elderly turned off at this time
	int lockdown_elderly_on;						// is lockdown elderly currently on

	int testing_symptoms_time_on;							// testing symptoms turned on at this time
	int testing_symptoms_time_off;							// testing symptoms turned off at this time
		
	int interventions_on;           // should we use interventions
	int intervention_start_time;	// time at which interventions start

	int sys_write_individual; 		// Should an individual file be written to output?
	
	long N_REFERENCE_HOUSEHOLDS;		// Number of households in the household demographics file
	int **REFERENCE_HOUSEHOLDS;		// Array of reference households

	double ***risk_score;  			// risk score somebody who has been traced
	double **risk_score_household;  // risk score for household members of symptomatic person

} parameters;

/************************************************************************/
/******************************  Functions  *****************************/
/************************************************************************/
double get_model_param_daily_fraction_work_used(model *model, int idx);
int get_model_param_quarantine_days(model *model);
double get_model_param_self_quarantine_fraction(model *model);
int get_model_param_trace_on_symptoms(model *model);
int get_model_param_trace_on_positive(model *model);
int get_model_param_quarantine_on_traced(model *model);
double get_model_param_traceable_interaction_fraction(model *model);
double get_model_param_manual_traceable_fraction_random(model *model);
double get_model_param_manual_traceable_fraction_occupation(model *model);
double get_model_param_manual_traceable_fraction_household(model *model);
int get_model_param_manual_trace_delay(model *model);
int get_model_param_tracing_network_depth(model *model);
int get_model_param_allow_clinical_diagnosis(model *model);
int get_model_param_quarantine_household_on_symptoms(model *model);
int get_model_param_quarantine_household_on_positive(model *model);
int get_model_param_quarantine_household_on_traced_symptoms(model *model);
int get_model_param_quarantine_household_on_traced_positive(model *model);
int get_model_param_quarantine_household_contacts_on_positive(model *model);
int get_model_param_quarantine_household_contacts_on_symptoms(model *model);
int get_model_param_test_on_symptoms(model *model);
int get_model_param_test_on_traced(model *model);
int get_model_param_test_result_wait(model *model);
int get_model_param_test_order_wait(model *model);
double get_model_param_app_users_fraction(model *model);
int get_model_param_app_turned_on(model *model);
int get_model_param_lockdown_on(model *model);
double get_model_param_risk_score( model*, int, int, int );
double get_model_param_risk_score_household( model*, int, int );
double get_model_param_lockdown_house_interaction_multiplier(model *model);
double get_model_param_lockdown_random_network_multiplier(model *model);
double get_model_param_lockdown_occupation_multiplier(model *model, int index);

int set_model_param_quarantine_days(model *model, int value);
int set_model_param_self_quarantine_fraction(model *model, double value);
int set_model_param_trace_on_symptoms(model *model, int value);
int set_model_param_trace_on_positive(model *model, int value);
int set_model_param_quarantine_on_traced(model *model, int value);
int set_model_param_traceable_interaction_fraction(model *model, double value);
int set_model_param_manual_traceable_fraction_random(model *model, double value);
int set_model_param_manual_traceable_fraction_occupation(model *model, double value);
int set_model_param_manual_traceable_fraction_household(model *model, double value);
int set_model_param_manual_trace_delay(model *model, int value);
int set_model_param_tracing_network_depth(model *model, int value);
int set_model_param_allow_clinical_diagnosis(model *model, int value);
int set_model_param_quarantine_household_on_symptoms(model *model, int value);
int set_model_param_quarantine_household_on_positive(model *model, int value);
int set_model_param_quarantine_household_on_traced_symptoms(model *model, int value);
int set_model_param_quarantine_household_on_traced_positive(model *model, int value);
int set_model_param_quarantine_household_contacts_on_positive(model *model, int value);
int set_model_param_quarantine_household_contacts_on_symptoms(model *model, int value);
int set_model_param_test_on_symptoms(model *model, int value);
int set_model_param_test_on_traced(model *model, int value);
int set_model_param_test_result_wait(model *model, int value);
int set_model_param_test_order_wait(model *model, int value);
int set_model_param_app_users_fraction(model *model, double value);
int set_model_param_app_turned_on(model *model, int value);
int set_model_param_lockdown_on(model *model, int value);
int set_model_param_lockdown_house_interaction_multiplier(model *model, double value);
int set_model_param_lockdown_random_network_multiplier(model *model, double value);
int set_model_param_lockdown_occupation_multiplier(model *model, double value, int index);
int set_model_param_lockdown_elderly_on(model *model, int value);
int set_model_param_relative_transmission( model *model, double value, int type );

int set_model_param_risk_score( model*, int, int, int, double );
int set_model_param_risk_score_household( model*, int, int, double );

void update_work_intervention_state(model *model, int value);
void update_household_intervention_state(model *model, int value);
void check_params( parameters* );
void destroy_params( parameters* );

#endif /* PARAMS_H_ */
