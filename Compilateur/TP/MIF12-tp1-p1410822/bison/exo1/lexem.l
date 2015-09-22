%{
#include "exo1b.h"
%}
%%
"{"			{return openbracket;}
"}"			{return closebracket;}
[^{}]		{return contenu;}
%%
