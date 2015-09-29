
#include <libxml/tree.h>

#include <alerr.h>

int pt(char *fn, xmlDocPtr * pDoc);
int tv(xmlDocPtr doc, char *schema);

void errExit(int r)
{
  fputs(errLine, stderr);
  fputc('\n', stderr);
  exit(r);
}

int main(int argc, char **argv)
{
  if (argc != 3) {
    printf("usage: pv <xml file> <schema file>\n");
    exit(-1);
  }

  xmlDocPtr doc;
  int r = pt(argv[1], &doc);
  if (r) {
    errExit(r);
  }
  // printf("read okay\n");

  r = tv(doc, argv[2]);
  if (r) {
    // xmlSaveFormatFileEnc("debug.xml", doc, "UTF-8", 1);
    exit(r);                    // xml functions emit error messages
  }

  printf("validate okay\n");
}
