#include "codigo.h"
#include <string>

using namespace std;

int main(int argc, char* argv[])
{

  string archivo = argv[1];

  codigo l(archivo);
  l.Loop(archivo);

  return 0;
}
