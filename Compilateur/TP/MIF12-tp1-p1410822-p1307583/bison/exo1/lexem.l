%{
#include "exo1.h"
%}
%%
[.\n]+		return contenu;
[{]			return openbracket;
[}]			return closebracket;
%%
