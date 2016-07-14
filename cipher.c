#include <stdio.h>
#include <string.h>
#include <conio.h>
#define TRUE   1
#define FALSE  0

//returns 1 if c occurs in buff > 1
//returns 0 otherwise
int
occurs ( char c, char*  buff ) {
     int occurence, i, len;
     i = 0;
     len = strlen ( buff );
     occurence = 0;
     while ( i < len ) {
          if ( buff[i] == c ) {
               occurence++;
               if ( occurence > 1 ) {
                    return TRUE;
               }
          }

          i++;
     }

     return FALSE;
}

int
isUnique ( const char*  str ) {
     char buffer[256], c;
     int len, i, ii;

     len

     = strlen ( str );

     //WARNING!
     strcpy ( buffer, str );
     i = 0;
     while ( c = str[i] ) {

          //returns FALSE if not found
          if ( occurs ( c, buffer ) == TRUE ) {
               return FALSE;
          }

          i++;
     }

     return TRUE;
}

//obviously
void
upcase ( char*  str ) {
     int i;
     int len;
     len = strlen ( str );

     for ( i = 0; i < len; i++ ) {
          str[i] = toupper ( str[i] );
     }
}

// function accepts an integer array, and a string
// returns an array indicating the pattern to follow
char*
genPattern ( int*  array, const char*  key ) {
     char tmp[256];
     char c;
     char*  place;
     int i;

     c     = 'A';
     place = NULL;

     strcpy ( tmp, key );
     upcase ( tmp );
     i = 0;
     while ( c != 'Z' ) {
          if ( place = strchr ( tmp, ( int ) c ) ) {

               //printf("%s",place);
               array[i] = place - tmp;
               i++;
          }

          c++;
     }
}

int
main ( void ) {
     char*  key;

     char buffer[1024];

     int k_len, pt_len, num_of_rows;

     int pattern[32];

     int i, ii, column, nxt, completion, ctr;

     char plaintext[64][64];
     char ciphertext[256];

     key = "DELAHOYZ";

     clrscr ();

     if ( !isUnique ( key ) ) {
          printf ( "\nWHAT: ERROR\nWHY: your key isnt unique.\nHOW: choose words that contain letters that are not repeated" );
          getch ();
          return ;
     }

     // feed me the patternz
     genPattern ( &pattern, key );

     //get the encryptee!?!
     printf ( "Enter plaintext:" );
     gets ( buffer );

     // get their lengths
     k_len = strlen ( key );
     pt_len = strlen ( buffer );

     // zeroes the memory before using
     memset ( ciphertext, 0, sizeof ( ciphertext ) );

     // get the number of rows
     num_of_rows = pt_len / k_len;

     // add 1 if division has remainder
     if ( ( pt_len % k_len ) > 0 ) {
          num_of_rows += 1;

     }

     // pag hati hatiin and mahabang string,and haba ay singhaba ng key
     // i arrange sila na parang naka matrix
     i = 0;

     while ( i < num_of_rows ) {
          memset ( &plaintext[i], 0, 256 );
          strncpy ( &plaintext[i], &buffer[i * k_len], k_len );

          //printf("\n%s",&plaintext[i]);
          i++;
     }

     // using a pattern, this code picks up letters downward, feeds it into  new buffer
     // then moves to another column, do this relative to key's length
     column = 0;
     ii = 0;
     completion = 0;
     ctr = 0;

     do
     {    // i holds the current row
          i = 0;

          // nxt holds the index of strings cut
          nxt = 0;

          // hmmm...
          column = pattern[ii];
          while ( i < num_of_rows ) {

               // if next row has zero in it. then do not concatenate to
               if ( plaintext[nxt][column] != 0 ) {
                    ciphertext[ctr] = plaintext[nxt][column];

                    // printf("%c",ciphertext[ctr]);
                    ctr++;
               }

               nxt++;
               i++;

          }

          completion++;
          ii++;
     }
     while ( completion < k_len );

     //dont forget the zero tail.
     ciphertext[ctr] = 0;

     //uppercase
     upcase ( ciphertext );

     //display!
     printf ( "ciphertext: %s", ciphertext );
     getch ();

     return 0;

}
