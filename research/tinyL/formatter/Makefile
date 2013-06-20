TARGET	= formatter

# LINK (*.o)
LD	= gcc
LDFLAGS	= --strip-all

# COMPILE (*.c)
CC	= gcc
CCFLAGS	= -Wall -O2

# GENERATOR (*.lex and *.yac)
LEX	= flex
YAC	= yacc

OBJS	= y.tab.o main.o
DEFS	= defs.h
REXP	= rexp.lex
LEXC	= lex.yy.c
SYNS	= syns.yac
YACC	= y.tab.c
SRC	= src.txt
TMP	= tmp.txt

all: $(TARGET)

$(TARGET): $(OBJS)
	$(LD) $(LDFLAGS) -o $@ $(OBJS)

$(OBJS): $(DEFS)

$(LEXC): $(REXP) $(DEFS)
	$(LEX) $(REXP)

$(YACC): $(SYNS) $(LEXC) $(DEFS)
	$(YAC) $(SYNS)

%.o: %.c
	$(CC) $(CCFLAGS) -c $< -o $@

clean:
	-rm -f $(TARGET)* $(OBJS) $(LEXC) $(YACC) $(TMP) *\~

src: all
	./$(TARGET) < $(SRC) > $(TMP)
	more $(TMP)
