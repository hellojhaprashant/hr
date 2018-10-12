#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include<assert.h>
#define MAX_CHARACTERS 1005
#define MAX_PARAGRAPHS 5

char*** kth_paragraph(char**** document, int k);
char** kth_sentence_in_mth_paragraph(char**** document, int k, int m);

char* kth_word_in_mth_sentence_of_nth_paragraph(char**** document, int k, int m, int n) {
	char** sentence = kth_sentence_in_mth_paragraph(document, m, n);
	char* word = (char*)(sentence + (sizeof(char*)*k));

    	return word;
}

char** kth_sentence_in_mth_paragraph(char**** document, int k, int m) { 
        char*** para = kth_paragraph(document, m);
	char** sentence = (char**)(para + (sizeof(char**)*k));
        
	return sentence;
}

char*** kth_paragraph(char**** document, int k) {
	char*** para = (char***)(document + (sizeof(char***)*k));

	return para;
}

/**
[para][sentences][words]
iterate over each char
  if 
    '\0', end of text and current para
    '\n', end of current sentence
    '.', end of current word & sentence
    ' ', end of current word
*/
char**** get_document(char* text) {
    const int MAX_SENTENCES_PER_PARA = MAX_CHARACTERS;
    const int MAX_WORDS_PER_SENTENCE = MAX_CHARACTERS;
    const int MAX_CHAR_PER_WORD = 100;
    char ****document;
    char paras [MAX_PARAGRAPHS][MAX_SENTENCES_PER_PARA][MAX_WORDS_PER_SENTENCE] [MAX_CHAR_PER_WORD];
    int i = 0;
    
    while ('\0' != text[i]){
      printf("debug: char[%c]=\n", text[i]);
      i++;
    }
    
/**
    char**** paras1 = {
        {
            {"Learning", "C", "is", "fun"} //para 0, sentence 0
        }// end of para 0 
        ,
        {
            {"Learning", "pointers", "is", "more", "fun"}// para 1, sentence 0
            ,
            {"It", "is", "good", "to", "have", "pointers"}// para 1, sentence 1
        }// end of para 1
    };
    
*/
    return document;
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

/*
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
*/
}

