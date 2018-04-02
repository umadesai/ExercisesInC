/* Simple word counting program that reads a text file, splits lines into words,
and counts the frequency of each word.
*/
#include <glib.h>
#include <stdio.h>
#include <stdlib.h>


void process_file(GHashTable* ht, char* file_name) {
	FILE *f = fopen(file_name, "r");

	char item[50];
	while (fscanf(f, " %9999s", item) == 1) {
		char* dupl = g_strdup(item);
    char* value = g_hash_table_lookup(ht, dupl);
    if (value == NULL) {
      g_hash_table_insert(ht, dupl, "1");
    } else {
      int update = atoi(value) + 1;
      char* wrd = malloc(50);
      sprintf(wrd, "%d", update);
      g_hash_table_replace(ht, dupl, wrd);
    }
	}
}

void print_ht(gpointer key, gpointer value, gpointer user_data) {
	printf("%s : %s\n", key, value);
}

int main () {
  GHashTable* ht = g_hash_table_new(g_str_hash, g_str_equal);
	process_file(ht, "oliver_twist.txt");
  gpointer user_data = NULL;
	g_hash_table_foreach(ht, print_ht, user_data);
	return 0;
}
