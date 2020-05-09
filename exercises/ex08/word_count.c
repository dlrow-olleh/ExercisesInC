#include <stdio.h>
#include <stdlib.h>
#include <glib.h>
#include <glib/gstdio.h>
#include <glib/gprintf.h>


void step(GHashTable *a, gchar* b){
  if(g_hash_table_contains (a,b)){
    gint* val = (gint*) g_hash_table_lookup(a,b);
    *val += 1;
  } else {
    gint * val_new = g_new(gint,1);
    *val_new =1;
    g_hash_table_insert(a,b,val_new);
  }
}

GHashTable* split_words(gchar* filename){
  GHashTable* a = g_hash_table_new(g_str_a,g_str_equal);
  gchar **text = g_new(gchar*,1);
  gsize *length = g_new(gsize,1);
  GError **error = g_new(GError*,1)
  gboolean f = g_file_get_contents(filename,text,length,error);
  gchar **word = g_strsplit(*text," ",30000);
  for(guint i = 0; i<g_strv_length(word);i++)
  {
    increment(a,words[i]);
  }
  return a;
}

void print(){
  GHashTable* txt = split_words("Sherlock.txt");
  guint *len = g_new(guint,1);
  gchar** bs = (gchar**) g_hash_table_get_keys_as_arrays(txt,len);
  for (guint i=0; i<*len;i++){
    gint* val = (gint*) g_hash_table_lookup(txt,bs[i]);
    g_printf("%s %i \n",bs[i],*val);
  }
}

int main(int argc, char** argv) {
  print_words();
  return 0;
}
