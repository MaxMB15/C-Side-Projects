#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#pragma GCC diagnostic ignored "-Wwrite-strings"

void subString (char *src, char *to, int start, int back);
void storeFileData(char **buffer, FILE *file);
char** str_split(char* a_str, const char a_delim);

int main(){
	char *bigNums[90] = {"4149592715896318693849709", "2534794902218749600993912", "3190523465079491056026174", "3074778338987907892876607", "6695387053906005671850966", "4175700148591818892491173", "8826446380739620928032424", "7637516797460242924439410", "6122521835292773858096408", "4663747783692557368786335", "5460753392244685703003541", "5287321411057070966032747", "9908603268620169551480290", "9053556600651377587680955", "8035786579000472062282739", "2800324771496092016260951", "2861381897178387641667422", "2295618289890599612462444", "3609320268872430341040994", "8911940383866081367599579", "8812361425215055441593411", "8510804340388781094218456", "3571920468043639648135907", "6552187093337802097595623", "3872565547753784575895955", "5008009114574162112380755", "6944215747377606768170585", "3559776541888469748844595", "9444409489526917192610563", "6817362279116187244859820", "1505791602140569839099258", "8320707535981754028228704", "4939561658480825767385744", "8874183362765776338088629", "2266669455927754127373714", "5543288059742315271232623", "9157913960948294491121560", "7173483501239335670241834", "2366479376597920488162020", "2644945616561317767103931", "8469841629009117413770055", "1665231495634042157546404", "5454579198827007431833606", "1496261788322202698694879", "2771547512418388981431611", "7598997421356279074235588", "3067291834095505258427133", "7891377811879799874199555", "3773501627008738685687678", "9135813709256569291123118", "9301516311437350820005616", "5416419980774293198192784", "4703410049312089307674576", "5947082012289884648775240", "5873983441400621779060350", "3566145369482468023013556", "4521515441389125104681738", "4203637421766819978132181", "3432193396181029673628820", "8012817379222283610791080", "6278959181740309024069977", "1910358927933141199499728", "1195009937353983320868035", "6513562820669022737281211", "8486997562249070710469908", "3016834820047227740241810", "2211751985519734617943454", "3545012129206758031685114", "8044677024992678303677533", "2584224731276816740922170", "6290555404215550019767453", "2857158598041802394177125", "7345260806128369149195619", "9372788288047132221461364", "7594966622106745890391532", "4989809903135247228357165", "5443672808897147042450417", "6408914424645781896682723", "9880331330494589543692899", "4698479497590845839991750", "7301841474179606554154621", "5419942579231882998716545", "1940093812060882385434572", "4465317039676819331607767", "1651779750166676400663545", "5143902608301281355973473", "2179806408731136565797395", "5198631961565789205768876", "3900390251192442109710216", "8528911472329547135176278"};
    FILE* fileRead = fopen("LastNineDig.txt", "r");
    int lastNineDigs[90];


	/*char buffer[10];
    int i;
    for(i = 0;i<90;i++){
    	subString(bigNums[i],buffer,25-9,25);
    	fprintf(fileRead, "%s\n", buffer);
    	printf("%s\n", buffer);
    }
	*/
    
    char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;
    while ((read = getline(&line, &len, fileRead)) != -1) {
    	lastNineDigs[i] = atoi(line);
        i++;
    }
    
    
    fclose(fileRead);
    
    FILE * fileOutput = fopen("PossibleMatch2.txt", "w");
    FILE * possComb = fopen("PossibleMatch.txt", "r");
    
    char **arr = NULL;
	i = 0;
	int b;
    /*while ((read = getline(&line, &len, possComb)) != -1) {
    	arr = str_split(line,' ');
    	if((lastNineDigs[atoi(arr[0])]+lastNineDigs[atoi(arr[1])]) % 1000000 == (lastNineDigs[atoi(arr[2])]+lastNineDigs[atoi(arr[3])]) % 1000000){
    		fprintf(fileOutput,"%s %s %s %s", arr[0],arr[1],arr[2],arr[3]);
    		printf("%s %s %s %s", arr[0],arr[1],arr[2],arr[3]);
    	}
    	i++;
    }*/
    //printf("%d\n",i);
    printf("%d %d %d %d\n", lastNineDigs[0],lastNineDigs[68],lastNineDigs[16],lastNineDigs[29]);


	/*if((lastDigs[a]+lastDigs[b]) % 10 == (lastDigs[c]+lastDigs[d]) % 10){
		printf("%d %d - %d %d\n", a,b,c,d);
		fprintf(fileOutput, "%d %d %d %d\n", a,b,c,d);
	}
	*/
	fclose(possComb);
    fclose(fileOutput);
	
    printf("FINISHED\n");
    return 0;
}
void subString (char *src, char *to, int start, int back){
	int size = back - start;
	memcpy(to, &src[start], size);
	to[size] = '\0';
}
void storeFileData(char **buffer, FILE *file){
	char *line = NULL;
    size_t len = 0;
    ssize_t read;
    int i = 0;
    while ((read = getline(&line, &len, file)) != -1) {
        printf("Retrieved line of length %zu:\n", read);
        printf("%s", line);
        buffer[i] = line;
        i++;
    }
    free(line);
    
}
//BY "hmjd": https://stackoverflow.com/questions/9210528/split-string-with-delimiters-in-c
char** str_split(char* a_str, const char a_delim)
{
    char** result    = 0;
    size_t count     = 0;
    char* tmp        = a_str;
    char* last_comma = 0;
    char delim[2];
    delim[0] = a_delim;
    delim[1] = 0;

    /* Count how many elements will be extracted. */
    while (*tmp)
    {
        if (a_delim == *tmp)
        {
            count++;
            last_comma = tmp;
        }
        tmp++;
    }

    /* Add space for trailing token. */
    count += last_comma < (a_str + strlen(a_str) - 1);

    /* Add space for terminating null string so caller
       knows where the list of returned strings ends. */
    count++;

    result = (char **)malloc(sizeof(char*) * count);

    if (result)
    {
        size_t idx  = 0;
        char* token = strtok(a_str, delim);

        while (token)
        {
            assert(idx < count);
            *(result + idx++) = strdup(token);
            token = strtok(0, delim);
        }
        assert(idx == count - 1);
        *(result + idx) = 0;
    }

    return result;
}



