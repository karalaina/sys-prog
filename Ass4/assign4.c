#include <stdio.h>
#include <string.h>

#define MAX_ARR  64
#define MAX_STR  32

typedef enum { COMEDY, DRAMA, HORROR, SCIFI 
} GenreType;

typedef struct {
  	char title[MAX_STR];
  	char director[MAX_STR];
  	int  year;
  	GenreType genre;
} MovieType;

void initMovie(char*, char*, int, GenreType, MovieType*);
void printMovies(MovieType*, int);
void readString(char*);
void readInt(int*);
void toLower(char*);
char* printGenre(GenreType);
GenreType getGenre(char*);

int main() {
	MovieType movies[MAX_ARR]; 	
	char title[MAX_STR];
	char dir[MAX_STR];
	int y;
	char genre[MAX_STR];
	GenreType g;
	int i;	
	int size = 0;

	while(1) {	//continuously asks user for movie information
		printf("Enter movie information: \n");
		printf("Title: ");
		readString(title);
		if (strcmp(title, "-1") == 0)
			break;	//breaks loop if -1 is entered for title
		printf("Director: ");
		readString(dir);
		y = 0;
		printf("Year: ");
		readInt(&y);
		if (y <= 0) {	//checks to make sure user entered a positive int value
			printf("Please enter an appropriate value\n");
			continue;
		}
		printf("Genre (comedy, drama, horror, scifi): ");
		readString(genre);
		g = getGenre(genre);
		if (g == -1) {	//checks to make sure user entered one of the given genres
			printf("Please enter a genre listed\n");
			continue;
		}
		
		initMovie(title, dir, y, g, &movies[i++]);
 		size++;
	}
	printMovies(movies, size);
		
  	return 0;
}
/*
    Function: 	printGenre
     Purpose: 	take GenreType value and return corresponding 
		string with genre name
          in: 	g
     Returns: 	string of genre corresponding to GenreType value given 
*/
char* printGenre(GenreType g) {
	switch(g) {
		case COMEDY: return "Comedy";
		case DRAMA: return "Drama";
		case HORROR: return "Horror";
		case SCIFI: return "Scifi";
	}
}
/*
    Function: 	toLower
     Purpose: 	take given string and make all uppercase characters lowercase
      in/out: 	str

*/
void toLower(char *str) {
	int i = 0;
	while (str[i] != '\0') {
		if (str[i] >= 65 && str[i] <= 90) { //if i is uppercase
			str[i] += 32; //make it lowercase
		}
		i++;
	}
}
/*
    Function: 	getGenre
     Purpose:	Takes given string and returns corresponding GenreType value
         in:	genre
    Returns: 	GenreType value corresponding to the string passed in
*/
GenreType getGenre(char *genre) {
	toLower(genre);
	if (strcmp(genre, "comedy") == 0) { 
		return COMEDY;
	} else if (strcmp(genre, "drama") == 0) {
		return DRAMA;
	} else if (strcmp(genre, "horror") == 0) {
		return HORROR;
	} else if (strcmp(genre, "scifi") == 0) {
		return SCIFI;	
	}else {
		return -1;
	}	
}  
/*
    Function:	initMovie
     Purpose:	creates a MovieType structure with data given
       	  in:	t (movie title)
	  in: 	d (director)
	  in:	y (year)
	  in:	g (genre)
      in/out:	m (movie structure)
*/
void initMovie(char *t, char *d, int y, GenreType g, MovieType *m) {
	strcpy(m->title, t);
	strcpy(m->director, d);
	m->year = y;
	m->genre = g;
}
/*
    Function:	printMovies
     Purpose: 	prints an array of MovieType structures 
          in:	arr
          in:	len
*/
void printMovies(MovieType *arr, int len) {
	printf("\n--MOVIES--\n");
	for (int i=0; i<len; i++) {
		printf("Title: %s\n  Director: %s\n  Year: %d\n  Genre: %s\n\n", 
		arr[i].title, arr[i].director, arr[i].year, 
		printGenre(arr[i].genre));
	} 	
} 


/*
    Function:  readString
    Purpose:   reads a string from standard input
        out:   string read in from the user
               (must be allocated in calling function)
*/
void readString(char *str) {
  	char tmpStr[MAX_STR];

  	fgets(tmpStr, sizeof(tmpStr), stdin);
  	tmpStr[strlen(tmpStr)-1] = '\0';
  	strcpy(str, tmpStr);
}

/*
    Function:  readInt
    Purpose:   reads an integer from standard input
        out:   integer read in from the user
               (must be allocated in calling function)
*/
void readInt(int *x) {
  	char str[MAX_STR];

  	readString(str);
  	sscanf(str, "%d", x);
}

