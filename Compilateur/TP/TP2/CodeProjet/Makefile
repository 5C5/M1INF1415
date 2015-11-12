SRCD = src
INCD = include
OBJD = obj
BIND = bin

EXEC = ppc

OBJFILES = ident.o tdi.o parser.o lexer.o main.o type.o symbole.o tds.o programme.o variable.o procedure.o fonction.o
OBJS = $(OBJFILES:%.o=$(OBJD)/%.o)

default: $(BIND)/$(EXEC)

$(BIND)/$(EXEC): $(OBJS)
	@g++ -o $@ $^ -ll

$(OBJD)/%.o: $(SRCD)/%.c 
	@g++ -o $@ -c $< -I$(INCD) -I$(SRCD)

$(SRCD)/parser.c: $(SRCD)/parser.y
	@bison -d -o $@ $<

$(SRCD)/lexer.c: $(SRCD)/lexer.l
	@flex -o $@ $<

clean:
	@rm -f $(OBJD)/*.o
	@rm -f $(SRCD)/parser.[hc]
	@rm -f $(SRCD)/lexer.[hc]

mrproper: clean
	@rm -f $(BIND)/$(EXEC)
