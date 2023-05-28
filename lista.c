#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct CovidCases{
    char* state;
    float total_cases;
    float total_cases_MS;
    float deaths;
    float deaths_MS;
    char* url;
    float deaths_per_100k;
    float total_cases_per_100k;
    float deaths_by_total_cases;
    float recovered;
    float tests_per_100k;
    float vaccinated;
    float vaccinated_per_100k;
    float vaccinated_second;
    float vaccinated_second_per_100k;
    float vaccinated_single;
    float vaccinated_single_per_100k;
    float vaccinated_third;
    float vaccinated_third_per_100k;
    float date;

    struct no * prox;
    struct no * ant;
};

struct pais* criarNo(char* state, float total_cases, float total_cases_MS, float deaths, float deaths_MS, char* url, float deaths_per_100k, float total_cases_per_100k, float deaths_by_total_cases, float recovered, float tests_per_100k, float vaccinated, float vaccinated_per_100k, float vaccinated_second, float vaccinated_second_per_100k, float vaccinated_single, float vaccinated_single_per_100k, float vaccinated_third, float vaccinated_third_per_100k, float date)
{
    struct CovidCases* no = (struct CovidCases*)malloc(sizeof(struct CovidCases));

    no->state = (char*)malloc(strlen(state) + 1);
    strcpy(no->state, state);

    no->total_cases = total_cases;
    no->total_cases_MS = total_cases_MS;
    no->deaths = deaths;
    no->deaths_MS = deaths_MS;

    no->url = (char*)malloc(strlen(url) + 1);
    strcpy(no->url, url);

    no->deaths_per_100k = deaths_per_100k;
    no->total_cases_per_100k = total_cases_per_100k;
    no->deaths_by_total_cases = deaths_by_total_cases;

    no->recovered = recovered;
    no->tests_per_100k = tests_per_100k;

    no->vaccinated = vaccinated;
    no->vaccinated_per_100k = vaccinated_per_100k;
    no->vaccinated_second = vaccinated_second;
    no->vaccinated_second_per_100k = vaccinated_second_per_100k;
    no->vaccinated_single = vaccinated_single;
    no->vaccinated_single_per_100k = vaccinated_single_per_100k;
    no->vaccinated_third = vaccinated_third;
    no->vaccinated_third_per_100k = vaccinated_third_per_100k;

    no->date = date;

    no->prox = NULL;

    return no;
}

void adicionarNo(struct CovidCases** head) {
    
}

void buscaNo(struct CovidCases* head) {

}