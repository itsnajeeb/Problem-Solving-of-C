#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
    return document[n - 1][m - 1][k - 1]; 
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
    return document[m - 1][k - 1]; 
}

char*** kth_paragraph(char**** document, int k) {
    return document[k - 1]; 
}

char* get_word(const char* word) 
{
    char* ans = NULL; 
    ans = (char*) strdup(word); 
    return ans; 
}

char** get_sentence(const char* sentence) 
{
    char** ans = NULL; 
    int count_word = 0;
    char *temp_sentence = (char*) strdup(sentence); 
    char *start = temp_sentence; 
    char *end = strchr(start, ' '); 
    while (end != NULL) {
        *end = '\0'; 
        char* temp_word = (char*) strdup(start); 
        ans = (char**) realloc(ans, sizeof(char**) * (count_word + 1)); 
        ans[count_word] = get_word(temp_word);       
        start = end + 1; 
        end = strchr(start, ' '); 
        count_word++; 
    }
    if (*start != '\0') {
        ans = (char**) realloc(ans, sizeof(char*) * (count_word + 1));
        char* temp_word = (char*) strdup(start);  
        ans[count_word] = get_word(temp_word);       
        count_word++;    
    }
    return ans; 
}

char*** get_paragraph(const char* paragraph) 
{
    char*** ans = NULL; 
    int count_sentence = 0; 
    char* temp_paragraph = (char*) strdup(paragraph); 
    char *start = temp_paragraph; 
    char *end = strchr(start, '.'); 
    while (end != NULL) {
        *end = '\0'; 
        char *temp_sentence = (char*) strdup(start); 
        ans = (char***) realloc(ans, sizeof(char**) * (count_sentence + 1)); 
        ans[count_sentence] = get_sentence(temp_sentence); 
        start = end + 1; 
        end = strchr(start, '.'); 
        count_sentence++; 
    }
    if (*start != '\0') {
        ans = (char***) realloc(ans, sizeof(char**) * (count_sentence + 1)); 
        char *temp_sentence = (char*) strdup(start); 
        ans[count_sentence] = get_sentence(temp_paragraph); 
        count_sentence++; 
    }
    return ans; 
}

char**** get_document(char* document) {
    char ****ans = NULL; 
    int count_paragraph = 0; 
    char *temp_document = (char*) strdup(document); 
    char *start = temp_document; 
    char *end = strchr(start, '\n'); 
    while (end != NULL) {
        *end = '\0'; 
        char *temp_paragraph = (char*) strdup(start); 
        ans = (char****) realloc(ans, sizeof(char***) * (count_paragraph + 1));
        ans[count_paragraph] = get_paragraph(temp_paragraph); 
        start = end + 1; 
        end = strchr(start, '\n'); 
        count_paragraph++; 
    }
    if (*start != '\0') {
        ans = (char****) realloc(ans, sizeof(char***) * (count_paragraph + 1));
        char *temp_paragraph = (char*) strdup(start); 
        ans[count_paragraph] = get_paragraph(temp_paragraph); 
        count_paragraph++; 
    }
    return ans; 
}   






char* get_input_text() {	
    int paragraph_count;
    scanf("%d", &paragraph_count);

    char p[MAX_PARAGRAPHS][MAX_CHARACTERS], doc[MAX_CHARACTERS];
    memset(doc, 0, sizeof(doc));
    getchar();
    for (int i = 0; i < paragraph_count; i++) {
        scanf("%[^\n]%*c", p[i]);
        strcat(doc, p[i]);
        if (i != paragraph_count - 1)
            strcat(doc, "\n");
    }

    char* returnDoc = (char*)malloc((strlen (doc)+1) * (sizeof(char)));
    strcpy(returnDoc, doc);
    return returnDoc;
}

void print_word(char* word) {
    printf("%s", word);
}

void print_sentence(char** sentence) {
    int word_count;
    scanf("%d", &word_count);
    for(int i = 0; i < word_count; i++){
        printf("%s", sentence[i]);
        if( i != word_count - 1)
            printf(" ");
    }
} 

void print_paragraph(char*** paragraph) {
    int sentence_count;
    scanf("%d", &sentence_count);
    for (int i = 0; i < sentence_count; i++) {
        print_sentence(*(paragraph + i));
        printf(".");
    }
}

int main() 
{
    char* text = get_input_text();
    char**** document = get_document(text);

    int q;
    scanf("%d", &q);

    while (q--) {
        int type;
        scanf("%d", &type);

        if (type == 3){
            int k, m, n;
            scanf("%d %d %d", &k, &m, &n);
            char* word = kth_word_in_mth_sentence_of_nth_paragraph(document, k, m, n);
            print_word(word);
        }

        else if (type == 2){
            int k, m;
            scanf("%d %d", &k, &m);
            char** sentence = kth_sentence_in_mth_paragraph(document, k, m);
            print_sentence(sentence);
        }

        else{
            int k;
            scanf("%d", &k);
            char*** paragraph = kth_paragraph(document, k);
            print_paragraph(paragraph);
        }
        printf("\n");
    }     
}